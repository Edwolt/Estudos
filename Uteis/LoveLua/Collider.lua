local Vec = require'modules.Vec'

local M = {}
M.__index = M

local function new(_, pos, size)
    assert(pos ~= nil)
    assert(size ~= nil)

    local self = {pos = pos, size = size}
    return setmetatable(self, M)
end
setmetatable(M, {__call = new})

--- Checks is a collision happened
function M.collision(a, b)
    local a1, a2 = a.pos, a.pos + a.size
    local b1, b2 = b.pos, b.pos + b.size

    local on_x = a1.x < b2.x and a2.x > b1.x
    local on_y = a1.y < b2.y and a2.y > b1.y
    return on_x and on_y
end

function M:draw(color)
    love.graphics.push()
    love.graphics.translate(self.pos.x, self.pos.y)

    love.graphics.setColor(color)
    love.graphics.setLineWidth(0.01)
    love.graphics.rectangle('line', 0, 0, self.size.x, self.size.y)

    love.graphics.pop()
end

function M:randomPoint()
    local bx, by = self.pos:unpack()
    local ex, ey = (self.pos + self.size):unpack()
    return Vec(love.math.random(bx, ex), love.math.random(ey, by))
end

--- Check collision of all against all of list
--- list must be a list of Colliders
---
--- This function will iterate over the list checking if there are
--- collision between its elements
---
--- For every collision,
--- f will be executed with the indices of the collisors as parameters
---
--- If f returns break the iteration stops
--- If f returns continue, look at the implementation to see what happens
function M.checkCollisionsNtoN(list, f, ...)
    dbg.log.collisions('Self', '%d ** 2 = %d', #list)
    for i = 1, #list do
        for j = i + 1, #list do
            if list[i]:collision(list[j]) then
                local res = f(i, j, list[i], list[j], ...)
                if res == 'break' then
                    return
                elseif res == 'continue' then
                    break
                end
            end
        end
    end
end

--- Check collision of list1 against list2
--- list1 and list2 must be a list of Colliders
---
--- This function will iterate over the lists checking if there are
--- collisions between colliders of list1 and colliders of list2
---
--- For every collision,
--- f will be executed with the indices of the collisors as parameters
---
--- If f returns break the iteration stops
--- If f returns continue the iteration will stop checking collision with the
--- current item of the list1
function M.checkCollisionsNtoM(list1, list2, f, ...)
    dbg.log.collisions('Lists', '%d x %d = %d', #list1, #list2)
    for i = 1, #list1 do
        for j = 1, #list2 do
            if list1[i]:collision(list2[j]) then
                local res = f(i, j, ...)
                if res == 'break' then
                    return
                elseif res == 'continue' then
                    break
                end
            end
        end
    end
end

function M.checkCollisionsNear(object, object_pos, matrix, matrix_pos, f, ...)
    local pos = object_pos + matrix_pos
    local x, y = pos:unpack()
    x, y = math.floor(x), math.floor(y)
    local bx, by = math.max(1, x - 2), math.max(1, y - 2)
    local ex, ey = math.min(#matrix, x + 2), math.min(#matrix[1], y + 2)

    dbg.log.collisions('Near', '1 x (%d, %d) = %d', ex - bx, ey - by)
    for i = bx, ex do
        for j = by, ey do
            if matrix[i][j]:collision(object) then
                local res = f(i, j, ...)
                if res == 'break' then
                    return
                elseif res == 'continue' then
                    return
                end
            end
        end
    end
end

function M.getColliderList(list)
    local res = {}
    for _, obj in ipairs(list) do
        res[#res + 1] = obj:collider()
    end
    return res
end

function M.__tostring(col)
    return ('(x=%d, y=%d, sx=%d, sy=%d)'):format(
        col.pos.x, col.pos.y,
        col.size.x, col.size.y
    )
end

M.NULL_COLLIDER = M(Vec(0, 0), Vec(0, 0))

return M

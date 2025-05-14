local M = {}

--------------------------
-----[[ Functional ]]-----
--------------------------

--- Identity function
function M.idfn(it) return it end

--- Create a function that alway return this value
function M.constfn(val) return function(...) return val end end

--- Map table `t` with function `f`
function M.map(t, f)
    local res = {}
    for k, i in pairs(t) do res[k] = f(i) end
    return res
end

--- Map array `t` with function `f`
function M.imap(t, f)
    local res = {}
    for _, i in ipairs(t) do res[#res + 1] = f(i) end
    return res
end

--- Map table `t` with function `f`
--- `f` receive the pair key and value and return a new key and a new value
function M.tmap(t, f)
    local res = {}
    for k, i in ipairs(t) do
        local nk, ni = f(k, i)
        res[nk] = ni
    end
    return res
end

--- Filter table `t` with function `f`
function M.filter(t, f)
    local res = {}
    for k, i in pairs(t) do if f(i) then res[k] = i end end
    return res
end

--- Filter array `t` with function `f`
function M.ifilter(t, f)
    local res = {}
    for _, i in ipairs(t) do if f(i) then res[#res + 1] = i end end
    return res
end

--- Filter table `t` with function `f`
--- `f` receive the pair key and value
function M.tfilter(t, f)
    local res = {}
    for k, i in ipairs(t) do if f(k, i) then res[k] = i end end
    return res
end

--- Left fold over table `t` with function `f`
function M.ifold(t, val, f)
    local res = val
    for _, i in ipairs(t) do res = f(res, i) end
    return res
end

--- Function partial application
function M.curry(f, a) return function(...) return f(a, ...) end end

--- Apply a sequence of functions to a value in a chained way
function M.pipe(val, ...)
    return M.ifold({...}, val, function(acc, f) return f(acc) end)
end

---------------------
-----[[ Utils ]]-----
---------------------

--- Create a shallow copy of table `t`
function M.copy(t)
    if type(t) == 'table' then
        return M.map(t, M.fnid)
    else -- number, string, boolean, etc.
        return t
    end
end

--- Create a table where all itens in `t`
--- becomes key associated with value `val`
function M.arraytotable(t, val)
    val = (val ~= nil) and val or false
    return M.tmap(t, function(_, i) return i, val end)
end

--- Join array `t` into a string
--- If the table has key `sep`, use it as a separator of the itens
function M.join(t)
    if #t == 0 then return '' end

    local sep = t.sep or ''
    local l = #t
    local last = t[l]
    t[l] = nil

    local res = M.ifold(t, '', function(acc, i) return acc .. i .. sep end)
    res = res .. last

    t[l] = last
    return res
end

--- Transform a string into an array
function M.strtoarray(str)
    local t = {}
    str:gsub('.', function(c) t[#t + 1] = c end)
    return t
end

--- TODO documentation
function M.tableunzip(t)
    local res = {}
    for _, d in ipairs(t) do
        for k, i in pairs(d) do
            if res[k] == nil then res[k] = {} end
            res[k][#res[k] + 1] = i
        end
    end
    return res
end

return M

----- Watch -----
local Watch = {}
Watch.__index = Watch

local function new(_)
    local self = {time = 0}
    return setmetatable(self, T)
end
setmetatable(Watch, {__call = new})

function Watch:update(dt)
    self.time = self.time + dt
end

function Watch:reset()
    self.time = 0
end

function Watch:decrease(value)
    self.time = self.time - value
end

----- Interval Timer -----
local Timer = {}
Timer.__index = Timer

local function new(_, duration)
    assert(type(duration) == 'number')

    local self = {
        time = 0,
        duration = duration,
    }

    return setmetatable(self, Timer)
end
setmetatable(Timer, {__call = new})


function Timer:update(dt)
    self.time = self.time + dt
end

function Timer:clock(f, ...)
    while self.time > self.duration do
        self.time = self.time - self.duration
        f(...)
    end
end

----- Cool Down Timer -----
local CoolDown = {}
CoolDown.__index = CoolDown

local function new(_, duration)
    assert(type(duration) == 'number')

    local self = {
        time = 0,
        duration = duration,
        active = false,
    }

    return setmetatable(self, CoolDown)
end
setmetatable(CoolDown, {__call = new})

function CoolDown:update(dt)
    if self.active then
        self.time = self.time + dt
    end
end

function CoolDown:clock(f, ...)
    if not self.active then
        f(...)
        self.time = 0
        self.active = true
    elseif self.time > self.duration then
        self.active = false
    end
end

function CoolDown:canTrigger()
    return not self.active
end

----- Span Timer -----
local Span = {}
Span.__index = Span

local function new(_, duration)
    assert(type(duration) == 'number')

    local self = {
        time = 0,
        duration = duration,
        active = true,
    }

    return setmetatable(self, Span)
end
setmetatable(Span, {__call = new})

function Span:update(dt)
    if self.active then
        self.time = self.time + dt
    end
end

function Span:clock(f, ...)
    if self.time < self.duration then
        f(...)
    else
        self.active = false
    end
end

function Span:percentage()
    return self.time / self.duration
end

------
return {
    Watch = Watch,       -- Just Count the time
    Timer = Timer,       -- Interval Timer
    CoolDown = CoolDown, -- Cool Down Timer
    Span = Span,         -- Active for a Period
}

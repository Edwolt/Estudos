--- Get a hexadecimal number and return its color as a table
local function hex(val)
    return {love.math.colorFromBytes(
        bit.rshift(bit.band(val, 0xff0000), 16),
        bit.rshift(bit.band(val, 0x00ff00), 8),
        bit.band(val, 0x0000ff)
    )}
end

return {
    fromHex = hex,

    WHITE = hex(0xaaaaaa),
    BLACK = hex(0x000000),
    GRAY = hex(0x666666),

    RED = hex(0xff0000),
    GREEN = hex(0x00ff00),
    BLUE = hex(0x0000ff),
}

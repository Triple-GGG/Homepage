local function failure(chars)
    local n = #chars
    local f = {}
    local t = 0
    f[1] = 0
    for s = 1, n-1 do
        while t > 0 and chars[s+1] ~= chars[t+1] do
            t = f[t]
        end
        if chars[s+1] == chars[t+1] then
            t = t + 1
            f[s+1] = t;
        else
            f[s+1] = 0;
        end
    end
    return f
end

local s = { "a", "b", "a", "b", "a", "a" }
local f = failure(s)

for _, v in ipairs(f) do
    print(v)
end

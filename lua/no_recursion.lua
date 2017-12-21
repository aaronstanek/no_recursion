no_recursion_startup = function()
  local ou = {}
  ou.root = {}
  ou.depth = 1
  return ou
end

no_recursion_get_depth = function(inp)
  return inp.depth
end

no_recursion_active = function(inp)
  return inp.root
end

no_recursion_prev = function(inp)
  return inp.root["&"]
end

no_recursion_push = function(inp)
  local h = {}
  h["&"] = inp.root
  inp.root = h
  inp.depth = inp.depth+1
  return h
end

no_recursion_pop = function(inp)
  inp.root = inp.root["&"]
  inp.depth = inp.depth-1
end

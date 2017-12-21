function no_recursion_startup() {
  var ou = {};
  ou["root"] = {};
  ou["depth"] = 1;
  return ou;
}

function no_recursion_get_depth(inp) {
  return inp["depth"];
}

function no_recursion_active(inp) {
  return inp["root"];
}

function no_recursion_prev(inp) {
  return inp["root"]["&"];
}

function no_recursion_push(inp) {
  var h = {};
  h["&"] = inp["root"];
  inp["root"] = h;
  inp["depth"] += 1;
  return h;
}

function no_recursion_pop(inp) {
  inp["root"] = inp["root"]["&"];
  inp.depth -= 1;
}

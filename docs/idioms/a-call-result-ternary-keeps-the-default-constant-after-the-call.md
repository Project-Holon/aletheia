# A call-result ternary keeps the default constant after the call

summary: when a Thumb selector's default constant hoists above its predicate call into a callee-saved register, assign the selector with a ternary on that call result instead of initializing a local and conditionally replacing it.

Found in: `src/matched/ov/ov121_func_021DC03C.c`, `src/matched/ov/ov121_func_021DC064.c`.

Both functions obtain a table index from one call, then use another call to choose an additive constant. `add = 5; if (predicate(p)) add = 0;` and the corresponding zero/three selector emitted the default before the second call, kept it in a saved register, and differed in twelve concrete bytes despite matching the forty-byte extent.

`add = predicate(p) ? 0 : 5;` and `add = predicate(p) ? 3 : 0;` emit the default into r2 after the call, compare r0, and overwrite r2 conditionally. Both were EXACT with dsi/1.1p1 `-O4,p`. The table lookup remains `return add + table[index];`.

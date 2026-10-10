# symbol_map (ov010)

Round 9 (lane w9c): 7 parts to 2. Merged EXACT: old p01..p04 (func_0216630C is a K&R definition `u8 f(grid, id)` called with 4 arguments; func_021663F4 K&R with an unused fourth parameter) and old p05..p07 (func_021672B4 is void).

Boundary left (p01|p02): func_02159B10 is declared `u16` in p02 (callee's own return type, suppresses the zero extension at each call) and `u32` in p01, where the calls do zero extend. Both forms occur in the original object, so this looks like two source files. Also p02 has `struct Work` and a second `Work` typedef (renamed Work_p05 in the test merge), and d_02172BA4 as float scalar against u32[2].

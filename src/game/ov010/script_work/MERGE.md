# script_work (ov010)

Round 9 (lane w9c): 4 parts to 2. Old p02..p04 merged EXACT (func_02158FD0 is a K&R definition `int f(a0, a1, a2)` called with 2 or 3 arguments).

Boundary left (p01|p02): in the test merge the only open item is func_02158A34. Its caller func_02158A90 passes `int result` with no narrowing, but the definition `void f(int a, int b, u16 c, int d)` compiles EXACT only with a prototype in scope, and a prototype makes the caller narrow (lsls/lsrs, 6 bytes more). Tried: int c, u16 result, no prototype with K&R u16 (all DIFF, 42 to 96 bytes). Also func_02158F94 is called with 2 arguments and defined with 3 (K&R fixes it), func_02158BFC needs int parameters in the merged file.

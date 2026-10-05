# eors, eors, orrs, beq equality over two words is a u64 compare

Symptom: a two-word equality test compiles to `eors a,x; eors b,y; orrs; beq` and no source built from
`(w0 ^ x) | (w1 ^ y)` or `a != x || b != y` reproduces the load and register order.

Fix: the original compared 64-bit values. Write `u64 id = *(u64 *)(p + K); if (*(u64 *)(q) != id) { *(u64 *)(q) = id; ... }`.
mwcc lowers the compare to the xor/orr form with the original load schedule, and the u64 store to two word stores.
Closed ov125 func_021D7414 and func_021D74D8 (wave D4 lane 14). An earlier "u64 compare is worse" test used a different shape
(separate x,y halves mixed with the u64 test).

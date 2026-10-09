# iss_road_sys (arm9)

Two parts remain: iss_road_sys_p01.c (0x0202B1AC..0x0202B20B) and iss_road_sys_p02.c (0x0202B20C..).

Blocker (c99=DIFF): func_0202B1FC (end of p01) is a tail call `ldr r3, =func_0202B20C; bx r3` with a pool
word. When func_0202B20C is defined in the same file, the compiler emits a direct local branch instead and
the code shrinks, so func_0202B20C moves from 0x0202B20C to 0x0202B204. The original reaches it through a
pool word, so caller and callee were in different translation units. Likely a real TU boundary.

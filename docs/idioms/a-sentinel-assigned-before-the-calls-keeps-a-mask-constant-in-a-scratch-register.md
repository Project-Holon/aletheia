# A sentinel assigned before the calls keeps a mask constant in a scratch register

summary: when `movs rN, #9` (a "none" sentinel) sits before the first call of a classify chain, write the assignment there; written after the calls, the compiler hoists an earlier `& 2` mask into a callee-saved register and reuses it for a later `cls = 2`, shifting every register below.

Found in: src/matched/ov/ov021_func_021A5D04.c (0x021A5D04), src/matched/ov/ov021_func_021A60DC.c (0x021A60DC)

The original tests `r & 2` with `movs r1, #2; tst r0, r1`, then
`t = func_0219D724(...)` goes to r7, `movs r4, #9` comes next, and only then
`bl func_021AB0F0`. Each arm of the `if/else if` chain that follows
materialises its own `movs r4, #k`.

```c
t = func_0219D724(b, buf);
cls = 9;                 /* here, before the calls */
k = func_021AB0F0(t);
func_021AB0F8(t);
if (func_021AB158(k)) cls = 0; else if ... cls = 2; ...
```

Writing `cls = 9;` after `func_021AB0F8(t);` instead (the order the
calls-then-classify reading suggests) compiles 2 bytes short: the `2` of the
`r & 2` test is put in r7 and reused as `adds r4, r7, #0` for `cls = 2`, so
`t` moves to r4 and the sentinel lands after the two calls. Twenty bytes
differ. Moving only the assignment gives EXACT.

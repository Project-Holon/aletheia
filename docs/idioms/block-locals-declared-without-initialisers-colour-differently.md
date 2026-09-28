# Block locals declared without initialisers colour differently from initialised ones

summary: when a two-register swap inside a nested block survives every declaration order of `int x = ...;` locals, declare the block's locals bare and assign them in separate statements. Declaration order and assignment order then vary independently, and a set of orders that no initialised spelling reaches opens up.

Found in: src/matched/ov119_func_021DBE70.c (0x021DBE70)

The bound block after func_021E4DBC keeps `t + 5` in r1 and the 0x634 limit in
r3 (the pool offset for the limit is loaded into r3 first). The earlier source
wrote six initialised locals (`int t = ...; int cur = ...; int a = t + 5; ...`).
Ten declaration orders of that form, assignment reorders, inline reads,
`x = x;` self-assignments and a permuter run all left r1 and r3 swapped, which is
6 bytes out of 1088.

The fix keeps the statements in the same order but splits declaration from
initialisation:

```c
int end; int a; int t; int cur; int b; int lim;
t = func_021E4DBC(p);
cur = I(p, 0xF74);
a = t + 5;
b = t + 10;
lim = I(p, 0x634);
end = cur;
```

A sweep of the declaration orders in this form found 105 EXACT among the first
536. The rest were 6, 8 or 12 bytes out. When a sweep over initialised
declarations has stalled, repeat it on the bare-declaration form.

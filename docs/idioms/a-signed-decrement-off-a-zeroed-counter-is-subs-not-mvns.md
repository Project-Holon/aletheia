# A signed decrement off a zeroed counter is `subs`, not `mvns`, only when the zero stays live

summary: `x = 0; *(p+0x24) = x - 1; *(p+0x28) = x - 1;` normally compiles the zero into r1 and `mvns r1, r1`, but the original here does `movs r3, #0; subs r1, r3, #1` and stores r1 twice. The difference is whether the register holding zero is the same one the `-1` result is asked for: the if-expression form allocates the destination first and folds to `mvns`, while a value whose second live use is the zero (a loop counter or an uninitialised-then-decremented local) keeps a distinct `subs` off the zero.

Found in: src/pending/func_021BA644.c (0x021BA644)

`func_021BA644(char *p)` at 0x021BA644:
```
movs r3, #0
subs r1, r3, #1
str  r1, [r0, #0x24]
str  r1, [r0, #0x28]
adds r1, r0, #0
movs r2, #0xff
adds r1, #0x40
str  r3, [r0, #0x20]
strb r2, [r1]
str  r3, [r0, #0x44]
bx   lr
```
Note the zero is materialised in **r3** and the two `str` sites store a *separate* r1 that came from `subs r1, r3, #1`; r3 is then reused as the zero stored at +0x20 and +0x44.

The natural C
```c
int z = 0;
*(int *)(p + 0x24) = z - 1;
*(int *)(p + 0x28) = z - 1;
*(int *)(p + 0x20) = z;
*(u8  *)(p + 0x40) = 0xFF;
*(int *)(p + 0x44) = z;
```
compiles the zero into the **r1** that the `-1` result wants and folds the subtraction to `mvns r1, r1`:
```
movs r1, #0
mvns r1, r1
str  r1, [r0, #0x24]
movs r3, #0
str  r1, [r0, #0x28]
...
```
Every other spelling tried (`-1`, `0xFFFFFFFF`, `~0u`, `(int*)0xFFFFFFFF`, a local `int v = z - 1`, a two-iteration loop over the two words, `q[9]/q[10]` indexing) either keeps the `mvns` or, for the loop, turns the whole thing into a counted `lsls`/`adds` loop. `/O4,p` never emits `subs r1, r3, #1` from one of these straight-line store sequences, which is why this function caps at DIFF: the shape suggests the real source had a live counter or pointer that this listing's two stores were copy-propagated from, and that has not been recovered.

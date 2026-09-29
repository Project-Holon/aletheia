# A temporary in one inner arm keeps the inner if/else ahead of the outer else

summary: when a then-block ends in an inner `if (f) r = A(); else r = B();`
and the outer else returns, 1.1p1 sinks the inner if/else below the outer
else (the then-head gains a `b`) so its join falls into the code after the
outer if. Binding one arm's call to a temporary (`t = B(); r = t;`) keeps the
inner if/else in source order, with its join ending in `b rest` and the
else arm jumping back to the join's store, as in the original.

Found in: src/matched/ov/ov021_func_021B58B0.c (0x021B58B0)

The image (Thumb, dsi/1.1p1 -O4,p):

    bl   func_0200BAF4        ; then-head
    adds r6, r0, #0
    ldr  r0, [sp, #4]         ; inner test follows directly
    cmp  r0, #0
    beq  ELSE
    ...  bl func_02019ED4
    JOIN: str r0, [sp, #0x14]
    b    REST
    ELSE: ... bl func_0201A090
    b    JOIN
    OUTER_ELSE: ...           ; returns
    REST: ...

With `r2 = func_0201A090(rules, w, &mask);` in the else arm, the compiler
emits `bl func_0200BAF4; adds; b INNER`, then the outer else, then the inner
if/else whose join falls into REST: 56 bytes out at the same size.
`goto`-based spellings of the outer if (`if (x != 1) goto fail; ...
goto rest; fail: ...; rest:`) and an inlined helper returning from each arm
compile identically to the plain if/else and do not help. `tmp =
func_0201A090(rules, w, &mask); r2 = tmp;` gives the image's layout exactly.
The permuter found it (`temp(...)` mutation) in its first 31 compiles.

The same function's not-1 path needed `if (r1) *out = 3; else *out = 0;`,
not `*out = r1 ? 3 : 0;`: the ternary compiles branch-free (`movs r0, #3;
cmp; bne; movs r0, #0`) where the image branches to each constant.

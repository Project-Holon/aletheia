# An int-spelled object base hoists its field addresses; a struct pointer parameter keeps them inline

summary: when a function reads/writes many fields of its second parameter through `*(int *)(b + 0xNN)` with `b` an `int`, mwcc hoists the loop-invariant `b + 0xNN` sums into spilled or extra registers (extra stack, `b` itself spilled, str/adds order changed); declare `b` as a pointer to a struct with the fields at those offsets and the original's per-use `adds r0, #0xNN; ldr r0, [r0]` reappears.

Found in: src/matched/ov/ov096_func_02189C8C.c (0x02189C8C), src/matched/ov/ov096_func_02189B78.c (0x02189B78), src/matched/ov/ov096_func_02189AC0.c (0x02189AC0), src/matched/ov/ov096_func_02188BB0.c (0x02188BB0), src/matched/ov/ov096_func_02188C1C.c (0x02188C1C)

Symptom: same instruction count within a few bytes, but the compiled function pushes r4-r7 only and
subtracts a larger frame (`sub sp, #0x14` versus `#0x10`), keeps `b` in a stack slot, and computes
`b + 0xbc` / `b + 0xc0` once before the loop. The original recomputes each field address at every use
and keeps `b` in r5.

    typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b];
                     int fb0, fb4, fb8, fbc, fc0, fc4; } Obj;
    int f(int a, Obj *b) { ... b->fbc ... (int)b passed to callees ... return b->fc4; }

Only offsets the bytes show are named; pad arrays fill the gaps. Calls that pass `b` on take `(int)b`.
In 02189C8C the same change fixed the `str r5,[r6,#0x38]` versus `adds r4,#0x38` order and the r4/r5
roles that declaration reordering and an `int *p = b + 0x38` local could not.

Other spellings that did not help: `int *p` alias for the field, `u32 b`, declaration reorders.
Not a universal fix: ov096 0x02189548 keeps its r4/r5 swap with the struct pointer.

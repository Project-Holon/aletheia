# A pointer local set to NULL and then tested compiles to `movs rN, #0; beq`

summary: 1.1p1 does not fold `p = 0; if (p != 0 && f(p) == 1) {...}`: it emits `movs rN, #0` and branches on the flags of that movs (`beq` always taken), keeping the dead arm; likewise `p = 0; if (f(p) == 0) g(p);` passes a live zero register. A `movs r6, #0` directly followed by a conditional branch is this shape, not a flag-setting compare you are missing.

Found in: src/matched/ov/ov010_func_02161724.c (0x02161724)

The image has `bl func_0216DB04; movs r6, #0; beq skip; adds r0, r6, #0;
bl func_0216DA5C; cmp r0, #1; ...` and, in the next state, `movs r0, #0; movs r7, #0;
bl func_0216DA5C; ... adds r0, r7, #0; bl func_0216DAF8`. Both come from a second
object pointer that the source sets to 0 (a stub or a compiled-out lookup) and then
uses as if it were real:

    b = 0;
    if (b != 0 && func_0216DA5C(b) == 1) { w->busy |= 4; func_0216DB04(b); }

Constant-folding the test away (or deleting the block) loses the bytes; the
literal NULL local reproduces them exactly.

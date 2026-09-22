# A flag dispatch four bytes short is the front end tail-merging the arms

summary: `if (flag) r = f(&A, &C, x, y); else r = f(&B, &C, x, y);` keeps both
arms whole under `../2.0/sp2` and loses one `ldr rN,[pc]` under dsi/1.1p1; no
spelling of the C reaches it, so the four missing bytes are a compiler
question, not a source one.

Found in: src/matched/func_020621FC.c (0x020621FC), src/matched/func_0206216C.c (0x0206216C)

Both functions dispatch on a flag to the same callee with a different first
argument and the SAME second argument. The image emits each arm in full:

    0206222C  ldr r0, [pc, #0x30]      ; &g_02146B98
    02062230  ldr r1, [pc, #0x30]      ; &g_02146B9C, pool word 0x02062268
    02062234  bl  #0x206207c
    02062238  b   #0x2062248
    0206223C  ldr r0, [pc, #0x28]      ; &g_02146B94
    02062240  ldr r1, [pc, #0x20]      ; &g_02146B9C, the SAME pool word
    02062244  bl  #0x206207c

The two arms load one identical pool word from two different pc offsets and
are still not merged. dsi/1.1p1 `-O4,p` hoists the common `ldr r1,[pc]; bl`
suffix out of both arms, reducing each to a bare `ldr r0` plus a `b` to the
shared call, and lands exactly one instruction short.

What the wrong readings cost, all measured on 0x020621FC (original 116 bytes
including its 16-byte pool):

| C written under 1.1p1 | result |
| --- | --- |
| the natural if/else above | 104 bytes -- one `ldr` short |
| the whole tail duplicated in each arm (`{ r = f(...); if (r) return 0; return 1; }` twice) | 128 bytes -- 20 over |
| array-typed externs, `f(g_02146B98, g_02146B9C, ...)` | 108, same merge |
| the result forced through a `volatile` local | 116 bytes, but the instructions come back as a `str r0,[sp]` / `ldr r0,[sp]` pair at the join, 24 bytes out |

The same C under `../2.0/sp2 -O4,p -proc arm946e` is byte-exact.

So the recognition rule is a size rule, not a shape rule: when the prologue,
the arithmetic and the epilogue are all byte-identical and only the flag
dispatch is four bytes short, count the `ldr rN,[pc]` in each arm. If one arm
has fewer than the image's, the front end merged them and no respelling will
unmerge them. Change the compiler.

The inverse idiom, `a-shared-exit-block-is-written-out-in-each-arm.md`, tells
you to write shared statements in every arm and let the compiler cross-jump
them. This is the case where the compiler cross-jumps something the image did
not, which that lever cannot undo.

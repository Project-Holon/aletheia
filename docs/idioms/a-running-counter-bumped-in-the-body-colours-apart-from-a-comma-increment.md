# A running counter bumped in the loop body colours differently from the same bump in the for header

summary: `for (i = 0; i < n; i++) { f(src + k * 32, ...); k++; }` and `for (i = 0; i < n; i++, k++) f(src + k * 32, ...);` compile to the same instructions, but the comma form hands the inner index a lower callee-saved register than a loop-invariant pointer; when `i` and a hoisted base swap registers across every nest of a copy loop, move the second counter's increment into the body.

Found in: src/matched/ov195_func_0220685C.c (0x0220685C)

The function copies 32-byte characters from a source bitmap into a 16x16
canvas in four nested loops, with one running source index `k` that carries
across all four nests. The image keeps the source pointer in r4 and the inner
index `i` in r6:

    adds r1, r6, r7      ; i + j * 16
    lsls r0, r5, #5      ; k * 32
    adds r0, r4, r0      ; src + k * 32
    ...
    adds r6, r6, #1      ; i++
    adds r5, r5, #1      ; k++

Written with `k++` in the for header next to `i++`, every instruction is the
same but `src` and `i` trade r4 and r6 in all four nests (21 concrete
mismatches). No declaration order of the six locals, `long` or `const`
variants, block-scoped counters per nest or the permuter (seed 7304, 400
compiles) moved it. Writing `k++;` as a statement after the call, inside a
braced body, closes the function at once.

`src + k++ * 32` (post-increment in the argument) is worse, 32 mismatches.

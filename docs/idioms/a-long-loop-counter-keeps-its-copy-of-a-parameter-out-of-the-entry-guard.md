# A long loop counter keeps its copy of a parameter out of the entry guard

summary: when `for (i = n; i < K; ...)` compiles with an extra `adds r0, rN, #0` copy of the parameter and the entry guard tests that copy (`cmp r0, #K`) where the image tests the counter itself (`adds r7, r2, #0; ...; cmp r7, #K`), declare the counter `long`: the int-to-long assignment is no longer a plain copy, so 1.1p1 stops propagating `n` into the guard and drops the spare register.

Found in: src/matched/ov/ov031_func_021F0AA0.c (0x021F0AA0)

The function runs two counter pairs, `for (i = n, j = 0; i < 3; ...)` and,
in the else arm, `for (i = n + 2, j = 2; i > -1; ...)`. The image's first
arm is

    adds r7, r2, #0     ; i = n
    movs r5, #0         ; j = 0
    cmp  r7, #3         ; guard on i

With `int i` 1.1p1 copy-propagates `i = n` into the guard and gives n a
fresh register just for it:

    adds r0, r2, #0     ; copy of n for the guard
    adds r5, r2, #0     ; i = n
    movs r7, #0
    cmp  r0, #3

That is two bytes long and shifts everything after it. The else arm, where
`i = n + 2` is not a copy, is already right. `long i` removes the copy (17
bytes out, all a same-width i/j register swap). Moving `j++`/`j--` from the
for header into the loop body then closed the swap (see
`a-running-counter-bumped-in-the-body-colours-apart-from-a-comma-increment.md`).
Declaration order, a separate counter for the second loops, reusing `i` for
them, `n` as the counter with a saved copy, and a 300-compile permuter run
with `--types` did not remove the copy. The permuter never tries `long`.

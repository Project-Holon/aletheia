# A conditional branch onto an unconditional b is a cross-jumped tail copy

summary: when the image's conditional branch lands on a `b` whose own target
is the real destination (a hop jump threading would have removed), the source
wrote the shared tail out in that arm and the compiler cross-jumped the copy
into a `b` after threading had already run. Falling into one shared label
instead lets 1.1p1 thread the hop, and the branch target moves by one
instruction.

Found in: src/matched/func_020246C8.c (0x020246C8)

The image (Thumb, 1.1p1 -O4,p), inside the flag arm of a word validator:

    bl    sub_02024520
    cmp   r0, #1
    blt   0x0202470C      ; -> the hop below, not the fail block
    cmp   r0, #0xb
    blt   done
    b     bad             ; 0x0202470C
    b     bad             ; 0x0202470E, the flag == 0 arm
    ...
    bad:  ldr r0, =0x6A1 ; movs r4, #0 ; strh r0, [r5]

With the range test falling out of the arm into a single `bad:` label the
compiler emits the same two `b bad` but the `blt` goes straight to `bad`
(1 byte out). Writing the fail statements out in that arm,
`if (v >= 1 && v < 11) goto done; ok = 0; *p = 0x6A1; goto done;`, as the
flag == 0 arm already does, is EXACT: both copies are cross-jumped into
`b bad` after threading, so the `blt` keeps pointing at its own copy.

This is the diagnostic form of
docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md: read an
unthreaded hop as "this arm wrote the tail out". A permuter run (3000
compiles) and twenty control-flow shapes did not find it, because the
written-out copy must end in the same `goto` as its sibling.

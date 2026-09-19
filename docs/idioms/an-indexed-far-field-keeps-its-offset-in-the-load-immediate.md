# An indexed far field keeps the field offset in the load immediate

summary: `g[i].fNNN` with a stride of 4 compiles to `add r1, g, i<<2` plus a
load at `[r1, #NNN]`, but the algebraically identical `*(u32 *)(g + i * 4 + N)`
folds N into the base and indexes off that instead; spell the index against
the element type first, `*(u32 *)((u8 *)((u32 *)g + i) + N)`, to get the
original's form.

Found in: src/matched/func_02038570.c (0x02038570)

The original body of func_02038570, inside the loop:

    addne r1, r0, r4, lsl #2      ; r1 = g + i * 4
    ldrne r0, [r1, #0x1b4]        ; the field rides in the load immediate
    addne r0, r0, #1
    strne r0, [r1, #0x1b4]

The natural spelling, `*(u32 *)(g_021469D0 + 0x1b4 + i * 4) += 1;`, produces
instead

    addne r1, r0, #0x1b4          ; base = g + N
    ldrne r0, [r1, r4, lsl #2]    ; index scaled in the load

which is the same address but two different instructions, and costs 8 bytes of
residue because every register in the window shifts. Reassociating the source
so the scaled index lands on the pointer first -

    *(u32 *)((u8 *)((u32 *)g_021469D0 + i) + 0x1b4) += 1;

- reproduces the original exactly. The tell is an `addne rX, base, i, lsl #2`
followed by a load whose immediate is the field offset: that pair is one
member of a stride-4 element, so the field access must be written through an
already-scaled pointer, not through a byte offset added to the base.

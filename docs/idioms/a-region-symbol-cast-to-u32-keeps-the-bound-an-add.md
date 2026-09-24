# A region symbol cast to u32 keeps base + N an add and colours the bound first

summary: When the image pools a linker region base and derives a bound with
`add rX, rY, #N`, write the base as the extern region symbol cast to u32 in a
u32 local. A literal base colours base and bound the other way round, and the
symbol kept as a pointer folds base + N into a second relocated pool word.

Found in: src/matched/sub_02034D60.c (0x02034D60)

The image, after an overlay-header read, tests a window at the start of the
arm9_autoload1_main_twl region:

    ldr r1, [pc, #0x24]      ; .word 0x02FE0000
    add r0, r1, #0x4000
    cmp r2, r0
    bhi ...
    cmp r2, r1

Source that matches (dsi/1.1p1):

    extern const unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];
    u32 lo;
    ...
    lo = (u32)SDK_AUTOLOAD_MAIN_TWL_START;
    if (id <= lo + 0x4000 && id >= lo) return 2;

Wrong spellings measured:
- a literal base, as a `const u8 *` so the fold does not pick 0x02FE4000 as
  the pool word: every byte right except the pair, base r0 / bound r1
  (5 out, some thirty spellings over four waves);
- the symbol kept as a pointer (`lo = SYM; p <= lo + 0x4000`, `&lo[0x4000]`,
  `lo + off` through a long local): base + 0x4000 becomes a second pool word
  with its own relocation addend, 104 bytes, 10 out;
- a pointer difference against the symbol: 11 out.

The integer cast hides the symbol from the front end's address folding (the
add stays an add) while the value still arrives through a relocation, and in
that form the allocator colours the bound before the base, as the image does.
u32 and unsigned long are both exact.

Tell: a pooled region base (0x02FE0000 here) with an `add #N` bound, the
right instructions from a literal spelling but base and bound in swapped
registers. Related: src/matched/sub_02030534.c and src/matched/func_0200520C.c
name the same region symbol for a base-plus-offset split.

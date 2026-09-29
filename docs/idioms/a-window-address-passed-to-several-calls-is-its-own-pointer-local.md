# A window address passed to several calls is its own pointer local

summary: when an object's sub-block address `p + K` is passed to three or more calls (a text window drawn to, then flushed) and the diff is register priority, the stack-argument zeros rematerialised in the original (`movs r0,#0; str r0,[sp]` at each call) but CSE'd into a callee-saved register in yours, or K pooled once and the other offsets derived from it (`adds rN, rK, #d`), bind the address to a `u8 *win = p + K;` local where the block starts: at the top of the function, or at the top of the `if` block for a second window used only there.

Found in: `src/matched/ov/ov070_func_021BB260.c` (win = p + 0x754 first,
win2 = p + 0x76C at the top of the `if`, before the func_021B619C call),
`src/pending/ov/ov070_func_021BAB04.c` (win = p + 0x734; MATCH only on an
arm9 leaf).

Spelling:

    u8 *win2;
    u8 *win;

    win = p + 0x754;
    ...
    func_021BB6E0(p, win, *(int *)(p + 0x528), 0, 0, 0x3DC5);
    func_021BB724(win);
    if (*(int *)(p + 0x7EC) == 2) {
        win2 = p + 0x76C;
        ...

Tried: the address spelled inline at each call (021BB260: the zero is
CSE'd into r7 and the int parameter `val` spills to the stack, 182 B off;
021BAB04: 0x6C0/0x6CC pooled on their own instead of derived from 0x734);
`int p` against `u8 *p` without the locals; a struct-typed object; a static
inline draw helper for both halves; val as u8/s16/u16/u32; the permuter at
300 with --types (it got only to 34 B, through a signature change).

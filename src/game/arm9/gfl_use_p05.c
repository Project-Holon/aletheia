/*
 * file:     gfl_use_p05.c
 * unit:     yes
 * function: sub_02005430, func_02005438, func_02005440
 * address:  0x02005430
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02061C44  0x02061C44  arm
 *   func_020911A0  0x020911A0  arm
 *   g_020A9E80      0x020A9E80  data
 *   func_02005454   0x02005454  arm
 */
/* ARM, and attested by a branch to it from an overlay. */
extern void func_02061C44(void);
extern void func_020911A0(void);
extern void func_02005454(int v);
void sub_02005430(void);
void func_02005438(void);
void func_02005440(void);
extern int g_020A9E80;


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One eight byte tail call, the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes: a pool word and a
 * `bx`, no prologue, no argument set up.  sub_02005230 calls it as the first
 * half of its two step init.
 *
 * The range is one function wide because of its neighbours rather than
 * because of itself.  Immediately before it is the linker veneer at
 * 0x02005428, which is not compiled code at all and cannot be inside any
 * unit.  Immediately after it, sub_02005438 is the same eight byte shape
 * around CTRDG_DummyInit at 0x020911A0, and the only word in the image that
 * holds 0x020911A0 is that function's own pool word, so the `literal` class
 * discards its only witness and no cut can help.  See the near miss register
 * in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005430.c \
 *       --addr 0x02005430 --thumb
 */
void sub_02005430(void)
{
    func_02061C44();
}



/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * A one-instruction forwarder: `ldr r3, [pc, #0]; bx r3` with the pool word
 * holding the callee.  The word is even, so the callee is ARM - the Thumb
 * tail call of the tail-call idiom, crossing the interworking boundary.  It
 * is four bytes of code plus its own two-word literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005438.c \
 *       --func func_02005438 --addr 0x02005438 --cc 1.1p1 --thumb
 */
void func_02005438(void)
{
    func_020911A0();
}


void func_02005440(void)
{
    func_02005454(0);
    g_020A9E80 = 1;
}

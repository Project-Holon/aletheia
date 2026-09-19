/*
 * function: func_02052F58
 * address:  0x02052F58
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8148  0x020A8148  data
 *
 * Calls the routine held in the global function pointer at 0x020A8148 with
 * (a0, a1, 0) and returns (result & 0xffff) << 3.  The 8-byte frame is
 * push {lr} plus the AAPCS alignment word.
 *
 * Built by the 1.2 front end, on two measured tells at once: the image has a
 * register `blx r3` beside an ARMv4T return `ldm sp!, {lr}; bx lr`, a pair no
 * dsi build emits, and the frame is `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`.  Under 1.1p1 the 16-bit mask also folds into a shift pair
 * (`lsl r0,r0,#0x10; lsr r0,r0,#0xd`) where the image ANDs with a pooled
 * 0xffff; ../1.2/sp2 reproduces all of it.  Measured, same packet as
 * src/matched/func_020525A0.c (pinned for the frame tell).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F58.c \
 *       --func func_02052F58 --addr 0x02052F58 --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);

int func_02052F58(u32 a0, u32 a1)
{
    return (g_020A8148(a0, a1, 0) & 0xffff) << 3;
}

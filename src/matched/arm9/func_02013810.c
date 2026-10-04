/*
 * function: func_02013810
 * address:  0x02013810
 * packet:   pkt_02013810
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013284   0x02013284  thumb
 *   func_02013528   0x02013528  thumb
 *
 * btl_setup.c.  The three-slot builder on the eight-argument writer: the
 * same shape as func_020136E0 and func_02013734 (both EXACT), but the lead
 * call is func_02013528 rather than func_020134F4, so the object's mode is
 * stored by this function (1) instead of by the writer.
 *
 * The documented near miss in docs/notes/pkt_02013810.c.txt compiled 56
 * bytes against 84 because it gave func_02013528 six parameters and
 * func_02013284 seven, and passed the object's +0x28 sub-block as a bare
 * constant.  The arity is fixed by the matched members of both families:
 * func_02013528 takes eight (func_02013790, func_020137F0 et al) and
 * func_02013284 takes six (func_02013610, func_020136E0 et al).  With those
 * two prototypes and the shared halfword forwarded to all three calls, the
 * body is the ordinary family shape and matches first try.
 *
 * The incoming stack block is what `add r6, sp, #0x28` addresses (0x10 of
 * frame plus six pushed registers): a4 is the byte at +0x00, a5 the word at
 * +0x04, a6 the word at +0x08 and a7 the halfword at +0x0C, which is why a7
 * is re-loaded with `ldrh [r6, #0xc]` before each of the three calls rather
 * than kept in a register.
 *
 * EXACT*: all 82 code bytes reproduce (3 of 3 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x02013862 before func_02013864, which has a label.  Never a byte
 * difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013810.c \
 *       --func func_02013810 --addr 0x02013810 --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013528(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02013284(u8 *o, u32 a1, u32 n, u8 *dst, u32 v, u16 h);

void func_02013810(u8 *o, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u16 a7)
{
    func_02013528((u32)o, a1, 1, 2, a2, a3, a4, a7);
    ((struct Obj00155 *)o)->f0 = 1;
    func_02013284(o, a1, 1, o + 0x28, a5, a7);
    func_02013284(o, a1, 3, o + 0x30, a6, a7);
}

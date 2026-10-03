/*
 * function: func_02062594
 * address:  0x02062594
 * packet:   pkt_02062474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Ask the 'KNBA'-tagged accessor whether a packed id is live: the low
 * halfword and the high halfword of the argument are each scaled by 8 (the
 * record stride) and handed to func_0206207C along with the two words at
 * 0x02146BB0 and 0x02146BB4.  The answer is inverted - `moveq r0, #1;
 * movne r0, #0` - so the function is true exactly when the probe came back 0.
 *
 * The two extractions are deliberately spelled differently and that is what
 * the image has: the low half is `(id & 0xFFFFu) << 3`, which mwcc fuses into
 * `lsl r2, r0, #0x10; lsr r2, r2, #0xd`, while the high half is
 * `((id & 0xFFFF0000u) >> 16) << 3`, which it materialises as
 * `mov r1, #0x10000; rsb r1, r1, #0; and r1, r0, r1; lsr r3, r1, #0x10;
 * lsl r3, r3, #3`.  Declaring `u16 lo = (u16)id; u16 hi = (u16)(id >> 16);`
 * and multiplying those instead gives the right 60 bytes of code but
 *   a 16-byte-truncating load pair for hi, and comes out 8 bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   g_02146BB0     0x02146BB0  data
 *   g_02146BB4     0x02146BB4  data
 *   func_0206207C  0x0206207C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062594.c \
 *       --func func_02062594 --addr 0x02062594 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_02146BB0[];
extern u32 g_02146BB4[];
extern int func_0206207C(void *headp, void *freep, int a2, int a3);

int func_02062594(u32 id)
{
    u32 lo = (id & 0xFFFFu) << 3;
    u32 hi = ((id & 0xFFFF0000u) >> 16) << 3;

    return func_0206207C(g_02146BB0, g_02146BB4, lo, hi) == 0;
}

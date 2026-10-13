/*
 * function: func_0202F72C
 * address:  0x0202F72C
 * packet:   pkt_0202F72C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: twelve-byte tail forwarder (pool word and bx) to func_020212E4 with
 *   the second argument; witness for ov131 P_STA_SKILL_HandleTouchForget (bl at +0x13A),
 *   whose call supplies a pointer, a halfword and a second halfword.
 * symbols:
 *   func_020212E4  0x020212E4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020212E4(u16 v);

u32 func_0202F72C(void *a, u16 b, u16 c)
{
    return func_020212E4(b);
}

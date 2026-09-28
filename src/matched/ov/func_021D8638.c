/*
 * function: func_021D8638
 * address:  0x021D8638
 * packet:   pkt_021D8638
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  MATCH (tail-call ABS32 to 0x0202822C: no witness outside the range; the only reference image-wide is this pool word)
 *
 * symbols:
 *   func_0202822C  0x0202822C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0202822C(void *, int);

void func_021D8638(u8 *p)
{
    func_0202822C(*(void **)(p + 0xc4), 1);
}

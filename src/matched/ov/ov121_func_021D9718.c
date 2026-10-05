/*
 * function: func_021D9718
 * address:  0x021D9718
 * packet:   pkt_021D9718
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D98E0  0x021D98E0  thumb
 *   func_021D9860  0x021D9860  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021D98E0(void *);
extern void func_021D9860(void *);

void func_021D9718(u8 *p)
{
    func_021D98E0(p + 4);
    func_021D9860(p);
}

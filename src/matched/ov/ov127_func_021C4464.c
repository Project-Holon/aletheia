/*
 * function: func_021C4464
 * address:  0x021C4464
 * packet:   pkt_021C4464
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204A8D4(u32 i);

void func_021C4464(u8 *p, int i)
{
    u32 *tbl = (u32 *)(p + 0x14 + i * 20);
    func_0204A8D4((u32)((void *)*tbl));
    *tbl = (u32)-1;
}

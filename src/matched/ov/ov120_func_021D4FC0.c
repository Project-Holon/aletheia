/*
 * function: func_021D4FC0
 * address:  0x021D4FC0
 * packet:   pkt_021D4FC0
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D588C  0x021D588C  thumb
 *   func_020435F4  0x020435F4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021D588C(u8 *p);
extern void func_020435F4(int);

void func_021D4FC0(u8 *p)
{
    func_021D588C(p);
    func_020435F4(0x1f);
}

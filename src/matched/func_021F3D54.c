/*
 * function: func_021F3D54
 * address:  0x021F3D54
 * packet:   pkt_021F3D54
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020452E8(u32);
extern void func_02045808(u32);
extern void func_02082BCC(u8 *, u32, u32);

void func_021F3D54(u8 *p)
{
    func_020452E8(*(u32 *)(p + 0x14));
    func_02045808(*(u32 *)(p + 0x1c));
    func_02082BCC(p, 0, 0x24);
}


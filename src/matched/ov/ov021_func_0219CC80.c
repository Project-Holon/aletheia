/*
 * function: func_0219CC80
 * address:  0x0219CC80
 * packet:   pkt_ov021_0219CC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02046EFC  0x02046EFC  arm

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0(u32);
extern void func_02046EFC(u32);

void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 **)(o + 0x1c);
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    *(u32 *)c = i;
    func_020307B0(*(u32 *)(c + 0xc));
    p = *(u8 **)(c + 0x10);
    if (i < *(u16 *)(c + 6)) {
        for (; i < *(u16 *)(c + 6); i++, p += 0x14) {
            if (*(u32 *)(p + 0x10) != 0)
                func_02046EFC(*(u32 *)(p + 0x10));
        }
    }
    func_020307B0(*(u32 *)(c + 0x10));
    i = 0;
    p = *(u8 **)(c + 0x14);
    if (i < *(u16 *)(c + 8)) {
        for (; i < *(u16 *)(c + 8); i++, p += 0x28) {
            if (*(u32 *)p != 0 && *(u32 *)(p + 0x10) != 0)
                func_02046EFC(*(u32 *)(p + 0x10));
        }
    }
    func_020307B0(*(u32 *)(c + 0x14));
    func_020307B0((u32)c);
    *(u32 *)(o + 0x1c) = 0;
}

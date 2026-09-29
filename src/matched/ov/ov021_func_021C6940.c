/*
 * function: func_021C6940
 * address:  0x021C6940
 * packet:   pkt_ov021_021C6940
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02082C60  0x02082C60  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020470D0(u32 x);
extern void func_02046EFC(u32 x);
extern void func_02082C60(void *p, int v, int n);

void func_021C6940(u8 *p)
{
    int i;
    u8 f = p[0x29];

    p[0x29] = 0;
    if (f == 1) {
        if (*(u32 *)(p + 4) != 0)
            func_020470D0(*(u32 *)(p + 4));
        else if (*(u32 *)p != 0)
            func_020470D0(*(u32 *)p);
    }
    if (*(u32 *)(p + 4) != 0)
        func_02046EFC(*(u32 *)(p + 4));
    if (*(u32 *)p != 0)
        func_02046EFC(*(u32 *)p);
    if (p[0x28] != 0) {
        for (i = 0; i < p[0x28]; i++)
            func_02046EFC(*(u32 *)(p + 8 + i * 4));
    }
    func_02082C60(p, 0, 0x2c);
    p[0x29] = 1;
}

/*
 * function: ov208_func_021C4F30
 * address:  0x021C4F30
 * packet:   pkt_ov208_021C4F30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041EE4  0x02041EE4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02041EE4(u32 index, u32 a, u32 b);

void ov208_func_021C4F30(void *unused, u8 *p)
{
    switch (*(u32 *)(p + 0x6b8)) {
    case 0:
        func_02041EE4(2, 0, -0x40);
        break;
    case 4:
        if (*(u16 *)(p + 0x548) >= 2)
            func_02041EE4(2, 0, 0);
        else
            func_02041EE4(2, 0, -0x40);
        break;
    }
}

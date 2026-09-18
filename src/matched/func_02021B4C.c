/*
 * function: func_02021B4C
 * address:  0x02021B4C
 * packet:   pkt_02021944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void func_02021B6C(u8 *p, u32 idx, u32 arg);

void func_02021B4C(u8 *p)
{
    u8 i;

    for (i = 4; i < 0xE; i++) {
        func_02021B6C(p, i, 0x100);
    }
}

/*
 * function: func_02028CD4
 * address:  0x02028CD4
 * packet:   pkt_02028BDC
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

void func_02028CD4(u8 *p, u32 v)
{
    int i;

    *(u32 *)(p + 0x00) = v;
    *(u32 *)(p + 0x04) = 0;
    *(u32 *)(p + 0x1c) = 0;
    *(u32 *)(p + 0x08) = 0;
    *(u32 *)(p + 0x0c) = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u16 *)(p + 0x18) = 0;
    *(u16 *)(p + 0x1a) = 0;
    *(u32 *)(p + 0x20) = 0;
    *(u32 *)(p + 0x24) = 0;

    for (i = 0; i < 10; i++)
        *(u32 *)(p + 0x28 + i * 12) = 0;

    *(u8 *)(p + 0xa0) = 0;
    *(u8 *)(p + 0xa1) = 0;

    for (i = 0; i < 2; i++)
        *(u16 *)(p + 0xac + i * 2) = 0xffff;

    *(u32 *)(p + 0xb4) = 0;
}

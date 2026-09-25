/*
 * function: func_021B7438
 * address:  0x021B7438
 * packet:   pkt_021B7438
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u16 func_021B7438(char **p)
{
    char *q = *p;

    return *(u16 *)(*(char **)(q + 0x10) + (*(u16 *)(q + 0x16) + *(u16 *)(q + 0x14)) * 2);
}

/*
 * function: func_021E140C
 * address:  0x021E140C
 * packet:   pkt_021E140C
 * region:   ov137
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

void func_021E140C(char *p)
{
    char *q = p + 0xC88;

    *(u16 *)(q + 2) = 1;
    *(u16 *)q = 1;
}

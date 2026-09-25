/*
 * function: func_021E14CC
 * address:  0x021E14CC
 * packet:   pkt_021E14CC
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

void func_021E14CC(char *p, char *q)
{
    char *r = p + 0xC90 + *(int *)(q + 0xC) * 0x10;

    *(int *)r = 1;
    *(char **)(r + 0xC) = q;
}

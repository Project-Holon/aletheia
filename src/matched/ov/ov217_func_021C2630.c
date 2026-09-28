/*
 * function: func_021C2630
 * address:  0x021C2630
 * packet:   pkt_021C2630
 * region:   ov217
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

void func_021C2630(char *p, char *q)
{
    struct S { int a, b, c, d, e, f; };

    *(struct S *)(p + 8) = *(struct S *)q;
}

/*
 * function: func_021BA18C
 * address:  0x021BA18C
 * packet:   pkt_021BA18C
 * region:   ov133
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

int func_021BA18C(char *p)
{
    return *(u16 *)(p + 4) == *(u16 *)(p + 6);
}

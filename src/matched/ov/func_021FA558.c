/*
 * function: func_021FA558
 * address:  0x021FA558
 * packet:   pkt_021FA558
 * region:   ov132
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

void func_021FA558(char *p, int i, int v)
{
    char *q = p + i * 4;

    *(int *)(q + 0x1EC) = v;
    *(int *)(p + 0x200) = 1;
}

/*
 * function: func_021DD93C
 * address:  0x021DD93C
 * packet:   pkt_021DD93C
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

void func_021DD93C(char *p, int v)
{
    *(int *)(p + 0x118) = 0x1A;
    *(int *)(p + 0x11C) = v;
}

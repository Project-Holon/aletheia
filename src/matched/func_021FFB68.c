/*
 * function: func_021FFB68
 * address:  0x021FFB68
 * packet:   pkt_021FFB68
 * region:   ov186
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

void func_021FFB68(char *p, int v)
{
    *(int *)p = v;
    *(int *)(p + 4) = 0;
}

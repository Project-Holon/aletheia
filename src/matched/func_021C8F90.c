/*
 * function: func_021C8F90
 * address:  0x021C8F90
 * packet:   pkt_021C8F90
 * region:   ov212
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

int func_021C8F90(char *p, int v)
{
    *(int *)(p + 0x20) = v;
    return 0;
}

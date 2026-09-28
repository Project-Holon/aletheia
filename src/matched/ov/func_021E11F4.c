/*
 * function: func_021E11F4
 * address:  0x021E11F4
 * packet:   pkt_021E11F4
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

void func_021E11F4(char *p)
{
    char *q = p + 0xC74;

    *(int *)(q + 8) = 1;
    *(int *)q = 1;
}

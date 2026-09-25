/*
 * function: func_021FB1F4
 * address:  0x021FB1F4
 * packet:   pkt_021FB1F4
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

int func_021FB1F4(char *p, int i)
{
    if (i == -1)
        return *(u8 *)(p + 0x18);
    return 1 << i;
}

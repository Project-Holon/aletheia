/*
 * function: func_021C447C
 * address:  0x021C447C
 * packet:   pkt_021C447C
 * region:   ov127
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

int func_021C447C(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x14) == -1)
        return 0;
    return 1;
}

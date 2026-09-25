/*
 * function: func_021E161C
 * address:  0x021E161C
 * packet:   pkt_021E161C
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

int func_021E161C(char *p)
{
    int n = *(int *)(p + 8) + 1;

    *(int *)(p + 8) = n;
    if (n < 0x258)
        return 0;
    *(int *)(p + 8) = 0x258;
    return 1;
}

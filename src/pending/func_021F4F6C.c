/*
 * function: func_021F4F6C
 * address:  0x021F4F6C
 * packet:   pkt_021F4F6C
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  4 bytes differ; order of the two independent index computations.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u16 func_021F4F6C(char *p, int i, int j)
{
    char *q;
    int k;

    q = p + i * 6;
    k = j * 2;
    return *(u16 *)(q + k + 2);
}

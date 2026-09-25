/*
 * function: func_021E1768
 * address:  0x021E1768
 * packet:   pkt_021E1768
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  28 bytes differ; shared return-1 block / branch polarity not reproduced.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021E1768(char *p, int i)
{
    if (i != 0 && ((1 << i) & *(u16 *)(*(char **)(p + 0xDC) + 0x42)) == 0)
        return 0;
    return 1;
}

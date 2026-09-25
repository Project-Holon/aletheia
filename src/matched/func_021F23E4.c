/*
 * function: func_021F23E4
 * address:  0x021F23E4
 * packet:   pkt_021F23E4
 * region:   ov194
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

int func_021F23E4(char *p)
{
    return *(u16 *)(p + 0x1E) == *(u16 *)(p + 0x22);
}

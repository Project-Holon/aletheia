/*
 * function: func_0220D884
 * address:  0x0220D884
 * packet:   pkt_0220D884
 * region:   ov197
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

int func_0220D884(char **p)
{
    if (*(int *)(*p + 0x20) == 1) {
        *(u16 *)(*p + 0x16) = 0;
        *(u8 *)(*p + 0x18) = 0;
        return 1;
    }
    return 0;
}

/*
 * function: func_021C4980
 * address:  0x021C4980
 * packet:   pkt_021C4980
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

char *func_021C4980(char **p, int i)
{
    char *base = *p;
    char *e = base + i * 0x18;

    if (*(int *)e != 1)
        return 0;
    return e;
}

/*
 * function: func_021BF7AC
 * address:  0x021BF7AC
 * packet:   pkt_021BF7AC
 * region:   ov203
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

struct Q { char pad[6]; unsigned short flag : 1; };

int func_021BF7AC(char *p, int v)
{
    struct Q *q = *(struct Q **)(*(char **)(p + 0x1C) + 0x74);
    int flag = q->flag;

    if (flag == 1)
        v *= 2;
    return v;
}

/*
 * function: func_0217B3EC
 * address:  0x0217B3EC
 * packet:   pkt_ov019_0217B3EC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

int func_0217B3EC(char *base, char *p)
{
    char *q = base + 0x2830;
    if (*(char **)(q + 0x14) == p || *(char **)(q + 0x18) == p ||
        *(char **)(q + 0x1c) == p || *(char **)(q + 0x20) == p) {
        if (*(u16 *)(p + 0x6c) == 0) {
            *(u16 *)(p + 0x6c) = 1;
        }
        return 1;
    }
    if (*(u16 *)(p + 0x6c) == 0) {
        return 0;
    }
    *(u16 *)(p + 0x6c) -= 1;
    return 1;
}

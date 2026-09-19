/*
 * function: func_02014388
 * address:  0x02014388
 * packet:   pkt_02014314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0040 ABS32 sub_02146268_Sys       : 02146268 (data, from header) has no witness outside 02014388..020143CC
 * symbols:
 *   sub_02146268_Sys  0x02146268  data
 */

typedef unsigned int u32;

extern char sub_02146268_Sys[];

char *func_02014388(char *a0, u32 a1)
{
    int i;

    if (a1 == 0)
        return 0;
    if (a1 < 0x4000) {
        i = a1 >> 3;
        if (i >= 0x16c)
            return 0;
        return a0 + 0x27c + i;
    }
    i = (int)(a1 - 0x4000) / 8;
    if (i >= 8)
        return 0;
    return sub_02146268_Sys + i;
}

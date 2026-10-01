/*
 * function: func_02029E20
 * address:  0x02029E20
 * packet:   pkt_02029E20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020A75A8  0x020A75A8  data
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 key; u16 val; } Pair;
extern Pair d_020A75A8[];

u16 func_02029E20(u32 k)
{
    int i;
    for (i = 0; d_020A75A8[i].key != 0x69; i++) {
        if (k == d_020A75A8[i].key)
            return d_020A75A8[i].val;
    }
    return 0x45A;
}

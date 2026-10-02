/*
 * function: func_021EE674
 * address:  0x021EE674
 * packet:   pkt_ov093_021EE674
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 flag : 1;
    u32 n : 31;
    u32 w[4];
} Q;

void func_021EE674(Q *q)
{
    u32 i;

    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}

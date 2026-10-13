/*
 * function: BTL_REC_InitReader
 * address:  0x021EE644
 * packet:   pkt_ov093_021EE644
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
    u32 n : 31;
    u32 flag : 1;
    u32 w[4];
} Q;

void BTL_REC_InitReader(Q *q, u32 a, u32 n)
{
    u32 i;

    q->a = a;
    q->n = n;
    q->flag = 0;
    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}

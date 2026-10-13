/*
 * function: BTL_REC_IsChannelDone
 * address:  0x021EE894
 * packet:   pkt_ov093_021EE894
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q;

int BTL_REC_IsChannelDone(Q *q, int i)
{
    u32 p;

    if (q->flag == 0) {
        p = q->pos[i];
        if (p == q->n)
            return 1;
        return 0;
    }
    return 1;
}

/*
 * function: BTL_REC_ReadSkipFlag
 * address:  0x021EE688
 * packet:   pkt_ov093_021EE688
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stream-record head decoder (Q: buf, n:31+flag:1, pos[4]). Reads the byte
 * at stream i; if its kind field ((v >> 4) & 7) is 2, advances the stream
 * and returns bit 7. The int return type and the reuse of v for the bit
 * fix the order: kind cannot be forwarded past the redefinition of v, and
 * the u8 cast lands at the assignment, not at the return.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q;

int BTL_REC_ReadSkipFlag(Q *q, int i)
{
    int v;
    int kind;

    v = q->buf[q->pos[i]];
    kind = (v >> 4) & 7;
    v = (u8)((v >> 7) & 1);
    if (kind == 2) {
        q->pos[i]++;
        return v;
    }
    return 0;
}

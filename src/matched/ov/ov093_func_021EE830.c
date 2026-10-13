/*
 * function: BTL_REC_CountFlaggedRecords
 * address:  0x021EE830
 * packet:   pkt_ov093_021EE830
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the bit7-flagged records in a stream (Q: buf, n:31+flag:1).
 * The buffer is read through q->buf in the loop (the compiler hoists it),
 * the bound is a local, and the locals are declared count first and
 * pos/size last; these set the register colours. pos++ sits right after
 * the byte load.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q;

int BTL_REC_CountFlaggedRecords(Q *q)
{
    int count;
    u8 v;
    u8 n;
    int kind;
    u8 bit;
    u32 j;
    u8 len;
    u32 pos;
    u32 size;

    pos = 0;
    count = 0;
    size = q->n;
    if (size != 0) {
        do {
            v = q->buf[pos];
            pos++;
            n = v & 0xf;
            kind = (v >> 4) & 7;
            bit = (v >> 7) & 1;
            if (bit != 0)
                count++;
            if (pos >= size)
                break;
            if (kind != 1) {
                pos += n;
            } else {
                for (j = 0; j < n; j++) {
                    len = q->buf[pos] & 0x1f;
                    pos = pos + 1 + len * 4;
                    if (pos >= size)
                        break;
                }
            }
        } while (pos < size);
    }
    return count;
}

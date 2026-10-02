/*
 * function: func_021EE830
 * address:  0x021EE830
 * packet:   pkt_ov093_021EE830
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: DIFF, 30 bytes. Decoder that counts bit7-flagged records in a
 * stream (Q: buf, n:31+flag:1). Control flow and extraction order match
 * (low nibble, kind, bit7; kind==1 walks n length-prefixed items, else
 * skips n bytes); the whole body differs only in register colouring:
 * original keeps size r2, pos r1, buf r3, byte r4 (shared with bit), count
 * r5; ours size r4, pos r2, count r3, buf r5, byte r1. Declaration order
 * made no difference. Guard is 'size != 0', buf loaded before the do/while.
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

int func_021EE830(Q *q)
{
    u32 pos = 0;
    int count = 0;
    u32 size = q->n;
    u8 *buf;
    u8 v;
    u8 n;
    int kind;
    u8 bit;
    u32 j;
    u8 len;

    if (size != 0) {
        buf = q->buf;
        do {
            v = buf[pos];
            n = v & 0xf;
            kind = (v >> 4) & 7;
            bit = (v >> 7) & 1;
            pos++;
            if (bit != 0)
                count++;
            if (pos >= size)
                break;
            if (kind != 1) {
                pos += n;
            } else {
                for (j = 0; j < n; j++) {
                    len = buf[pos] & 0x1f;
                    pos = pos + 1 + len * 4;
                    if (pos >= size)
                        break;
                }
            }
        } while (pos < size);
    }
    return count;
}

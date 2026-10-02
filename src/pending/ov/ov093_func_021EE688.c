/*
 * function: func_021EE688
 * address:  0x021EE688
 * packet:   pkt_ov093_021EE688
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: DIFF, 11 bytes. Stream-record head decoder (Q: buf,
 * n:31+flag:1, pos[4]). Structure and branches match; only the schedule
 * differs: original extracts kind ((v>>4)&7, held in r1) before the bit7
 * chain with the byte in r5, ours extracts bit7 first with the byte in r1.
 * Tried declaration order, local vs inline loads, int/u32/s8 byte, ternary
 * return, reusing the parameter for kind, pointer-to-pos local.
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

u8 func_021EE688(Q *q, int i)
{
    u8 v;
    int kind;
    u8 bit;

    v = q->buf[q->pos[i]];
    kind = (v >> 4) & 7;
    bit = (v >> 7) & 1;
    if (kind == 2) {
        q->pos[i] = q->pos[i] + 1;
        return bit;
    }
    return 0;
}

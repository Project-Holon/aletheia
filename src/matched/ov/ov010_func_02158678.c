/*
 * function: INTRUDE_COMM_CountEventPeers
 * address:  0x02158678
 * packet:   pkt_ov010_02158678
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb
 */

typedef unsigned char u8;

typedef struct { u8 a : 5; u8 f : 1; u8 b : 2; } Fl;

extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_COMM_IsSessionActive(void *);

int INTRUDE_COMM_CountEventPeers(void *p)
{
    int n = 0;
    u8 i;
    u8 *q = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)p);
    if (q == 0)
        return n;
    if (INTRUDE_COMM_IsSessionActive(q + 0x1AC) == 0)
        return n;
    for (i = 0; i < 3; i++) {
        if (((Fl *)(q + 0xA6 + i * 0x1C))->f == 1)
            n++;
    }
    if (n == 0)
        n = 1;
    return n;
}

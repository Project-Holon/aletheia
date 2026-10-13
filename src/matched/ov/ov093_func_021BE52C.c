/*
 * function: BTL_SERVER_FLOW_PushMoveQueue
 * address: 0x021BE52C
 * packet: pkt_ov093_021BE52C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * evidence: Each byte store may alias p[0], so reread the index.
 */
typedef unsigned char u8;
void BTL_SERVER_FLOW_PushMoveQueue(u8 *p, int a, int b, int c)
{
    if (p[0] < 6) {
        (p + p[0])[1] = a;
        (p + p[0])[13] = b;
        (p + p[0])[7] = c;
        p[0]++;
    }
}

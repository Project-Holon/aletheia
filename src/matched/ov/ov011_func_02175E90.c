/*
 * function: INTRUDE_COMM_HasResultReward
 * address: 0x02175E90
 * packet: pkt_ov011_02175E90
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: DE4 source declares one argument; original E90 visibly sets r1, preserved here.
 * symbols:
 *   INTRUDE_COMM_HasResult 0x02175DA8 thumb ov011
 *   INTRUDE_COMM_GetResultCount 0x02175DE4 thumb ov011
 */
typedef unsigned char u8;
extern int INTRUDE_COMM_HasResult(u8 *);
extern int INTRUDE_COMM_GetResultCount(void *p, u8 *a1);
int INTRUDE_COMM_HasResultReward(void *p, u8 *q)
{
    if (INTRUDE_COMM_HasResult(q) == 0) return 0;
    if (INTRUDE_COMM_GetResultCount(p, q) > 0) return 1;
    return 0;
}

/*
 * function: Wf2dmapFriend_SetState
 * address: 0x021C6438
 * packet: pkt_ov128_021C6438
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Six code bytes followed by two zero alignment bytes.
 */
typedef unsigned char u8;
void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b)
{
    p[9] = a;
    p[10] = b;
}

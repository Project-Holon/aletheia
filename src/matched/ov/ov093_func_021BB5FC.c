/*
 * function: BTL_SERVER_SendSkipPacket
 * address: 0x021BB5FC
 * packet: pkt_ov093_021BB5FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * output: EE8D8 has no branch or forwarding call; it stores 2 through r1
 * at 021EE8EC on every path and returns p+4 at 021EE8EE..021EE8F0.
 * symbols:
 *   BTL_REC_InitPacket 0x021EE8B4 thumb ov093
 *   BTL_REC_MakeSkipPacket 0x021EE8D8 thumb ov093
 *   BTL_SERVER_SendCommandData 0x021BB724 thumb ov093
 */

typedef unsigned char u8;
extern void BTL_REC_InitPacket(u8 *, int);
typedef unsigned int   u32;
extern u8 *BTL_REC_MakeSkipPacket(u8 *p, u32 *out, int flag);
extern void BTL_SERVER_SendCommandData(u8 *, int, int, int);
int BTL_SERVER_SendSkipPacket(u8 *p, int b)
{
 int n;
 int r;
 BTL_REC_InitPacket(p + 0x68, 1);
 r = (int)BTL_REC_MakeSkipPacket(p + 0x68, (u32 *)(&n), b);
 BTL_SERVER_SendCommandData(p, 10, r, n);
 return 1;
}

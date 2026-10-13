/*
 * function: BTL_SERVER_SendActionPacket
 * address: 0x021BB628
 * packet: pkt_ov093_021BB628
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * interface: BTL_SERVER_BuildActionPacket's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &n in r3 and reads r0, so its extern preserves both.
 * symbols:
 *   BTL_SERVER_BuildActionPacket 0x021BB650 thumb ov093
 *   BTL_SERVER_SendCommandData 0x021BB724 thumb ov093
 */

typedef unsigned char u8;
extern int BTL_SERVER_BuildActionPacket(u8 *p, int a, int b, int c);
extern void BTL_SERVER_SendCommandData(u8 *, int, int, int);
int BTL_SERVER_SendActionPacket(u8 *p, int a, int b)
{
 int n;
 int r;
 r = BTL_SERVER_BuildActionPacket(p, a, b, (int)(&n));
 if (r != 0) {
  BTL_SERVER_SendCommandData(p, 10, r, n);
  return 1;
 }
 return 0;
}

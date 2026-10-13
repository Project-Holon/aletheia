/*
 * unit: yes
 * function: NET_WHPIPE_IsStateScanning, NET_WHPIPE_SendData, NET_WHPIPE_GetConnectBitmap, NET_WHPIPE_GetOwnAid
 * address: 0x02177C1C
 * packet: pkt_ov014_02177C1C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   DWCi_MOV_WH_SendData 0x02179368 thumb ov014
 *   func_02178E38 0x02178E38 thumb ov014
 *   WIH_GetOwnAid 0x021795A4 thumb ov014
 */

extern int func_02178E4C(void);
int NET_WHPIPE_IsStateScanning(void) { if (func_02178E4C() == 2) return 1; return 0; }
extern int DWCi_MOV_WH_SendData(int a, unsigned short b, int c);
typedef unsigned short u16;
extern u16 func_02178E38(void);
extern unsigned short WIH_GetOwnAid(void);
int NET_WHPIPE_SendData(int a, unsigned int b, int c) { return DWCi_MOV_WH_SendData(a, b, c); }
unsigned int NET_WHPIPE_GetConnectBitmap(void) { return func_02178E38(); }
int NET_WHPIPE_GetOwnAid(void) { return WIH_GetOwnAid(); }

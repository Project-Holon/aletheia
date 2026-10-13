/*
 * function: WIFICLUB_RunPeerAddrRoutine
 * address: 0x021C2850
 * packet: pkt_ov099_021C2850
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_GetMacAddress 0x02087C6C arm
 */
extern void OS_GetMacAddress(void *);
void WIFICLUB_RunPeerAddrRoutine(char *p) { OS_GetMacAddress(p + 0xe); }

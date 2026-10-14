/*
 * function: GDS_SOCKET_GetState
 * address: 0x021D85C0
 * packet: pkt_ov125_021D85C0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_GetStateUnlocked 0x021D7BCC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 */
extern void GDS_SOCKET_Lock(void);extern unsigned GDS_SOCKET_GetStateUnlocked(void);extern void GDS_SOCKET_Unlock(void);
unsigned GDS_SOCKET_GetState(void) {unsigned v;GDS_SOCKET_Lock();v=GDS_SOCKET_GetStateUnlocked();GDS_SOCKET_Unlock();return v;}

/*
 * function: BTL_NET_IsInitialSyncDone
 * address: 0x021D4230
 * packet: pkt_ov093_021D4230
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_PollSync 0x021D4B18 thumb ov093
 */
extern void *gBtlNet;
extern int BTL_NET_PollSync(int);
int BTL_NET_IsInitialSyncDone(void) { int r; if(gBtlNet) { r=1; if(BTL_NET_PollSync(1)==0) r=0; return r; } return 1; }

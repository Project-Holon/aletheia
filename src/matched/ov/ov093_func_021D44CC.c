/*
 * function: BTL_NET_IsPartyReceived
 * address: 0x021D44CC
 * packet: pkt_ov093_021D44CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_HasEntry 0x021D4330 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *gBtlNet;
extern u8 BTL_NET_HasEntry(int);
int BTL_NET_IsPartyReceived(void) { int i; for(i=0;i<4;i++) if(BTL_NET_HasEntry(i) && *(u32 *)(gBtlNet+i*4+0x3af4)==0) return 0; return 1; }

/*
 * function: BTL_SERVER_FLOW_CheckClientHasBackupPoke
 * address: 0x021C7F24
 * packet: pkt_ov093_021C7F24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_GetPartyOfPoke 0x021C7FCC thumb ov093
 *   BTL_SERVER_FLOW_GetFrontCountForRule 0x021C7F04 thumb ov093
 *   BTL_SLOT_CountLivingFrom 0x021B9BC4 thumb ov093
 */
typedef unsigned char u8;
extern char *BTL_SERVER_FLOW_GetPartyOfPoke(u8 *, int);
extern int BTL_SERVER_FLOW_GetFrontCountForRule(u8 *, int);
extern u8 BTL_SLOT_CountLivingFrom(u8 *, int);
int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i) { char *q = BTL_SERVER_FLOW_GetPartyOfPoke(p, i); if (BTL_SLOT_CountLivingFrom((u8 *)q, BTL_SERVER_FLOW_GetFrontCountForRule(p, i))) return 1; return 0; }

/*
 * function: BTL_MAIN_SyncSideParty
 * address: 0x021B8F5C
 * packet: pkt_ov093_021B8F5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SIDE_WriteBackParty 0x021B969C thumb ov093
 *   BTL_SIDE_GetParty 0x021B985C thumb ov093
 */
extern void BTL_SIDE_WriteBackParty(char *,char *,int,int);
extern int BTL_SIDE_GetParty(char *,int);
int BTL_MAIN_SyncSideParty(char *p,int k) { BTL_SIDE_WriteBackParty(p+0xc8,p,k,0); return BTL_SIDE_GetParty(p+0xc8,k); }

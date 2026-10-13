/*
 * function: BTL_MAIN_IsSecondTeamClient
 * address: 0x021B8FC0
 * packet: pkt_ov093_021B8FC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 */
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
unsigned char BTL_MAIN_IsSecondTeamClient(unsigned char *p,unsigned int k) { if(BTL_MAIN_IsMultiMode((unsigned char **)p)) return (unsigned char)((k&2)!=0); return 0; }

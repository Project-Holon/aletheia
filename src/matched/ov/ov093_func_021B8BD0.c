/*
 * function: BTL_MAIN_IsLocalSide
 * address: 0x021B8BD0
 * packet: pkt_ov093_021B8BD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetClientSide 0x021B8BC4 thumb ov093
 */
extern unsigned char BTL_MAIN_GetClientSide(int,unsigned int);
int BTL_MAIN_IsLocalSide(unsigned char *p,unsigned char k) { if(k==BTL_MAIN_GetClientSide((int)p,p[0x46c])) return 1; return 0; }

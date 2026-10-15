/*
 * function: BEACON_VIEW_ShowWindowText
 * address: 0x021F0B80
 * packet: pkt_ov032_021F0B80
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_DrawWindowText 0x021F201C thumb ov032
 */
extern void BEACON_VIEW_DrawWindowText(char *,char *,void *,unsigned short,unsigned char,unsigned char,unsigned short,unsigned);
void BEACON_VIEW_ShowWindowText(char *p,void *t,unsigned a) { BEACON_VIEW_DrawWindowText(p,p+0x17c,t,0,0,9,0x449,a); }

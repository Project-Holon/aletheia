/*
 * function: MUSICAL_MCSS_SetRenderVisible
 * address: 0x021F5374
 * packet: pkt_ov112_021F5374
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_ShowMCAnim 0x021F62EC thumb ov112
 *   MUSICAL_MCSS_HideMCAnim 0x021F62DC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_ShowMCAnim(char *p);
extern void MUSICAL_MCSS_HideMCAnim(char *p);
void MUSICAL_MCSS_SetRenderVisible(int *p,int b) { if(b==1)MUSICAL_MCSS_ShowMCAnim((char *)p[2]); else MUSICAL_MCSS_HideMCAnim((char *)p[2]); }

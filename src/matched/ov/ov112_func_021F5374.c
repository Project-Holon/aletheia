/*
 * function: MUSICAL_MCSS_SetRenderMode
 * address: 0x021F5374
 * packet: pkt_ov112_021F5374
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_NoOp9 0x021F62EC thumb ov112
 *   MUSICAL_MCSS_NoOp8 0x021F62DC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_NoOp9(char *p);
extern void MUSICAL_MCSS_NoOp8(char *p);
void MUSICAL_MCSS_SetRenderMode(int *p,int b) { if(b==1)MUSICAL_MCSS_NoOp9((char *)p[2]); else MUSICAL_MCSS_NoOp8((char *)p[2]); }

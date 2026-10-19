/*
 * function: MUSICAL_MCSS_IsRenderVisible
 * address: 0x021F5388
 * packet: pkt_ov112_021F5388
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_IsMCAnimHidden 0x021F62D0 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 MUSICAL_MCSS_IsMCAnimHidden(u8 *);
int MUSICAL_MCSS_IsRenderVisible(u8 **p) { return MUSICAL_MCSS_IsMCAnimHidden(p[2]) != 1; }

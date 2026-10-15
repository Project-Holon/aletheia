/*
 * function: MUSICAL_MCSS_GetRenderHandle
 * address: 0x021F5388
 * packet: pkt_ov112_021F5388
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetFieldG 0x021F62D0 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 MUSICAL_MCSS_GetFieldG(u8 *);
int MUSICAL_MCSS_GetRenderHandle(u8 **p) { return MUSICAL_MCSS_GetFieldG(p[2]) != 1; }

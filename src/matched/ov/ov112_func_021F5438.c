/*
 * function: MUSICAL_MCSS_SetRenderCellVramBase
 * address: 0x021F5438
 * packet: pkt_ov112_021F5438
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_SetCellVramBase 0x021F622C thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_SetCellVramBase(char *p, int b);
void MUSICAL_MCSS_SetRenderCellVramBase(void **p,int b) {MUSICAL_MCSS_SetCellVramBase(p[1],b); }

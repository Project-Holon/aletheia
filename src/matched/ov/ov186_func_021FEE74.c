/*
 * function: BR_SIDEBAR_StartSlide
 * address: 0x021FEE74
 * packet: pkt_ov186_021FEE74
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021FEE9A follow; no follower.
 * symbols:
 *   BR_SIDEBAR_IsSlotActive 0x021FF028 thumb ov186
 *   BR_SIDEBAR_SetSlotMode 0x021FF038 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BR_SIDEBAR_IsSlotActive(u32 *p); extern void BR_SIDEBAR_SetSlotMode(char *,u32);
void BR_SIDEBAR_StartSlide(char *p) { int i; for(i=0;i<12;i++) if(BR_SIDEBAR_IsSlotActive((u32 *)((u32)p+i*0x4c))) BR_SIDEBAR_SetSlotMode((char *)((u32)p+i*0x4c),3); }

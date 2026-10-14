/*
 * function: BR_SIDEBAR_ResetPositions
 * address: 0x021FEE9C
 * packet: pkt_ov186_021FEE9C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_SIDEBAR_IsSlotActive 0x021FF028 thumb ov186
 *   BR_SIDEBAR_ResetSlot 0x021FF074 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BR_SIDEBAR_IsSlotActive(u32 *p); extern void BR_SIDEBAR_ResetSlot(char *);
void BR_SIDEBAR_ResetPositions(char *p) { int i; for(i=0;i<12;i++) if(BR_SIDEBAR_IsSlotActive((u32 *)((u32)p+i*0x4c))) BR_SIDEBAR_ResetSlot((char *)((u32)p+i*0x4c)); }

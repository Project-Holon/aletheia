/*
 * function: BR_SIDEBAR_Update
 * address: 0x021FEE00
 * packet: pkt_ov186_021FEE00
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_SIDEBAR_IsSlotActive 0x021FF028 thumb ov186
 *   BR_SIDEBAR_UpdateSlot 0x021FF01C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BR_SIDEBAR_IsSlotActive(u32 *p); extern void BR_SIDEBAR_UpdateSlot(char *);
void BR_SIDEBAR_Update(char *p) { int i; for(i=0;i<12;i++) if(BR_SIDEBAR_IsSlotActive((u32 *)((u32)p+i*0x4c))) BR_SIDEBAR_UpdateSlot((char *)((u32)p+i*0x4c)); }

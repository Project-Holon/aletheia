/*
 * function: BR_SIDEBAR_Destroy
 * address: 0x021FEDC4
 * packet: pkt_ov186_021FEDC4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_SIDEBAR_IsSlotActive 0x021FF028 thumb ov186
 *   BR_SIDEBAR_DestroySlot 0x021FF004 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BR_SIDEBAR_IsSlotActive(u32 *p); extern void BR_SIDEBAR_DestroySlot(char *); extern void BR_RES_ReleaseSprite(char *,u32); extern void func_020307B0(void *);
void BR_SIDEBAR_Destroy(char *p,char *ctx) { int i; for(i=0;i<12;i++) if(BR_SIDEBAR_IsSlotActive((u32 *)((u32)p+i*0x4c))) BR_SIDEBAR_DestroySlot((char *)((u32)p+i*0x4c)); BR_RES_ReleaseSprite(ctx,4); BR_RES_ReleaseSprite(ctx,5); func_020307B0(p); }

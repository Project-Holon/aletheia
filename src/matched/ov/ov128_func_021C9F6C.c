/*
 * function: WF2DMAP_TOUCH_ClearAllScreens
 * address: 0x021C9F6C
 * packet: pkt_ov128_021C9F6C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_ClearScreenAt 0x021C9F30 thumb ov128
 *   WF2DMAP_TOUCH_SetBgScroll 0x021C9F8C thumb ov128
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void WF2DMAP_TOUCH_ClearScreenAt(char *p, u32 index);
extern void WF2DMAP_TOUCH_SetBgScroll(void *,char *);
void WF2DMAP_TOUCH_ClearAllScreens(char *p,void *q) { int i; for(i=0;i<8;i++)WF2DMAP_TOUCH_ClearScreenAt(p,i);WF2DMAP_TOUCH_SetBgScroll(q,p); }

/*
 * function: WF2DMAP_TOUCH_StartFriendEdit
 * address: 0x021C9238
 * packet: pkt_ov128_021C9238
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_CreateEditWidgets 0x021C9628 thumb ov128
 */
#include "../include/Obj23103.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_CreateEditWidgets(void *,void *,void *,void *);
void WF2DMAP_TOUCH_StartFriendEdit(char *p,void *b,void *c,void *d) { ((struct Obj23103 *)p)->f10=1; WF2DMAP_TOUCH_CreateEditWidgets(p,b,c,d); }

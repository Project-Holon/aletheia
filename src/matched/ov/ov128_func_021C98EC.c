/*
 * function: WF2DMAP_TOUCH_ReleaseEditWidgets
 * address: 0x021C98EC
 * packet: pkt_ov128_021C98EC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_TOUCH_ClearAllScreens 0x021C9F6C thumb ov128
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   WF2DMAP_TOUCH_ReleaseActor 0x021CA4C8 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_ClearAllScreens(char *p, void *q);
extern void func_021C6B38(u8 *);
extern void WF2DMAP_TOUCH_ReleaseActor(int *);
void WF2DMAP_TOUCH_ReleaseEditWidgets(char *p,u8 *q) {char *base;int i;i=0;base=p+20;for(;i<3;i++) WF2DMAP_TOUCH_ClearAllScreens(base+i*76,q);func_021C6B38(q);WF2DMAP_TOUCH_ReleaseActor((int *)p);}

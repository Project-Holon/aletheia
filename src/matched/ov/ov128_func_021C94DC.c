/*
 * function: WF2DMAP_TOUCH_GetMenuTouchInput
 * address: 0x021C94DC
 * packet: pkt_ov128_021C94DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gWf2dmapEditHitRects 0x021CA576 data a1
 *   WF2DMAP_TOUCH_SelectMenu 0x021C93C0 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int TOUCHPANEL_HitTrg(const void *);
extern const u8 gWf2dmapEditHitRects[];
extern int WF2DMAP_TOUCH_SelectMenu(char *p, void *q, void *r, int n);
int WF2DMAP_TOUCH_GetMenuTouchInput(void *p,void *q,void *r,int *flag) {
 int v=TOUCHPANEL_HitTrg(gWf2dmapEditHitRects);
 if(v==-1)return 2;
 *flag=1;
 if(v==0)return WF2DMAP_TOUCH_SelectMenu(p,q,r,3);
 if(v==1)return WF2DMAP_TOUCH_SelectMenu(p,q,r,2);
 if(v==2)return WF2DMAP_TOUCH_SelectMenu(p,q,r,0);
 return WF2DMAP_TOUCH_SelectMenu(p,q,r,1);
}

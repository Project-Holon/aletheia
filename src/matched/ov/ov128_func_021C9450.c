/*
 * function: WF2DMAP_TOUCH_GetMenuKeyInput
 * address: 0x021C9450
 * packet: pkt_ov128_021C9450
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   WF2DMAP_TOUCH_SelectMenu 0x021C93C0 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern void func_020355D8(u8 v);
extern int WF2DMAP_TOUCH_SelectMenu(char *p, void *q, void *r, int n);
int WF2DMAP_TOUCH_GetMenuKeyInput(void *p,int *q,void *r) {
 if(*q==1 && (KEY_GetTrg()&0xcf3)) {func_020355D8(0);*q=0;}
 if(KEY_GetTrg()&2)return WF2DMAP_TOUCH_SelectMenu(p,q,r,0);
 if(KEY_GetTrg()&1024)return WF2DMAP_TOUCH_SelectMenu(p,q,r,1);
 if(KEY_GetCont()&64)return WF2DMAP_TOUCH_SelectMenu(p,q,r,2);
 if(KEY_GetCont()&128)return WF2DMAP_TOUCH_SelectMenu(p,q,r,3);
 return 2;
}

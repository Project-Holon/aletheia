/*
 * function: func_021B96C8
 * address: 0x021B96C8
 * packet: pkt_ov181_021B96C8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021B9B10 0x021B9B10 thumb ov181
 *   func_021B9D20 0x021B9D20 thumb ov181
 *   func_021B9F1C 0x021B9F1C thumb ov181
 *   func_021B9DB0 0x021B9DB0 thumb ov181
 *   func_021B9B6C 0x021B9B6C thumb ov181
 *   func_021B99CC 0x021B99CC thumb ov181
 *   func_0207D534 0x0207D534 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 * volatile: hardware brightness registers 0x04000050 and 0x04001050
 */
typedef unsigned short u16;typedef unsigned int u32;
extern int GFL_USE_IsBgmFading(void),GFL_USE_IsBgmPlaying(void);extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B9B10(char *),func_021B9D20(char *),func_021B9F1C(char *),func_021B9DB0(char *),func_021B9B6C(char *),func_021B99CC(void);
extern void func_0207D534(volatile u16 *,int);extern void BG_SYS_SetMainVisiblePlanes(u32),BG_SYS_SetSubVisiblePlanes(u32),GF_OVERLAY_Unload(int);
extern char overlay_id[];
int func_021B96C8(char *p) {
if(GFL_USE_IsBgmFading()==1)return 2;
if(GFL_USE_IsBgmPlaying()==1)GFL_USE_CancelChangeAndStopBgm();
func_021B9B10(p);func_021B9D20(p);func_021B9F1C(p);func_021B9DB0(p);func_021B9B6C(p);func_021B99CC();
func_0207D534((volatile u16 *)0x0400006c,-16);func_0207D534((volatile u16 *)0x0400106c,-16);
*(volatile u16 *)0x04000050=0;*(volatile u16 *)0x04001050=0;
BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);GF_OVERLAY_Unload((int)overlay_id);return 5;
}

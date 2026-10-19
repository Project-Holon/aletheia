/*
 * function: POKETRADE_PROC_IncrementTimer
 * address: 0x021D8A50
 * packet: pkt_ov119_021D8A50
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(u32 a);
void POKETRADE_PROC_IncrementTimer(void *p) {
 int v;
 if(((struct Obj00001 *)p)->f1094!=0) {
 v=++((struct Obj00001 *)p)->f1094;
 if(v==2) {GFL_USE_FadeOutBgm(6); return;}
 if(v==8) {
 GFL_USE_SetBgmPaused((void *)1); GFL_USE_PushBgm();
 ++((struct Obj00001 *)p)->f11F8;
 GFL_USE_CancelChangeAndPlayBgm(0x3f3,0xffff); GFL_USE_FadeInBgmFull(1);
 ((struct Obj00001 *)p)->f1094=0;
 }
 }
}

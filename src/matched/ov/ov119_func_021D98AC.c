/*
 * function: POKETRADE_PROC_StepMain
 * address: 0x021D98AC
 * packet: pkt_ov119_021D98AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 is declared int here: original consumes r0 after
 * its 02035BBC forwarding call; the matched void spelling leaves r0 live.
 * Full matched ARM9 02035BBC returns int through 02035ADC, or -1.
 * wrap: the 10a0 toggle uses full-width unsigned subtraction to preserve
 * the original SUB for every 32-bit field pattern without a domain claim.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   POKETRADE_PROC_PlaceCursorIcon 0x021D9780 thumb ov119
 *   func_02040588 0x02040588 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E75F0 0x021E75F0 data a4
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021D9810 0x021D9810 thumb ov119
 */
#include "../include/Obj01727.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S;
extern u32 WIPE_SYS_EndCheck(void);
extern u8 func_020355C4(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern void POKETRADE_PROC_PlaceCursorIcon(char *,int,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void TOUCHBAR_Update(struct S *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021D9810(char *);
extern const char d_021E75F0[];
static inline int poll(void) {int v=KEY_GetTrg();if(v)func_020355D8(0);return v;}
void POKETRADE_PROC_StepMain(char *p)
{
 int done=0;
 if(((struct Obj01727 *)p)->f11F9==0 && WIPE_SYS_EndCheck()) {
  if(func_020355C4() && poll()) {func_020355D8(0);POKETRADE_PROC_PlaceCursorIcon(p,((struct Obj01727 *)p)->f10A0,0);return;}
  func_02040588(3,1);
  switch(TOUCHPANEL_HitTrg(d_021E75F0)) {
  case 0:
   if(((struct Obj01727 *)p)->f10A0!=0 || !func_020355C4()) {
    ((struct Obj01727 *)p)->f10A0=0;func_020355D8(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,((struct Obj01727 *)p)->f10A0,1);
   }
   break;
  case 1:
   if(((struct Obj01727 *)p)->f10A0!=1 || !func_020355C4()) {
    ((struct Obj01727 *)p)->f10A0=1;func_020355D8(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,((struct Obj01727 *)p)->f10A0,1);
   }
   break;
  case 2:done=1;break;
  }
  if(poll()==32 || poll()==16) {
   *(unsigned *)&((struct Obj01727 *)p)->f10A0=1u-*(unsigned *)&((struct Obj01727 *)p)->f10A0;GFL_USE_PlaySeDefaultVolume(0x548);func_020355D8(0);POKETRADE_PROC_PlaceCursorIcon(p,((struct Obj01727 *)p)->f10A0,1);
  }
  TOUCHBAR_Update(((struct Obj01727 *)p)->f9C0);
  if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj01727 *)p)->f9C0)==1)done=1;
  if(done) {WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj01727 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)func_021D9810);}
 }
}

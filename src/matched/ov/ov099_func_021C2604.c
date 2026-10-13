/*
 * function: func_021C2604
 * address: 0x021C2604
 * packet: pkt_ov099_021C2604
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021C2438 0x021C2438 thumb ov099
 *   d_021C3C0C 0x021C3C0C data a4
 */
#include "../include/Obj00825.h"
typedef unsigned char u8;
typedef int (*Handler)(char *,int);
extern const Handler d_021C3C0C[];
extern int GFL_NET_GetRunState(void);
extern int DWC_RAPCOMMON_HandleNetError(int,int);
extern unsigned int func_0200FB24(void);
extern int func_021C2438(char *);
typedef unsigned int   u32;
struct PrintSys;
extern void func_021BC0C4(char *);
extern void func_021BB0B4(char *);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void func_021C18C8(char *,int,int);
extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);
extern void WIPE_SYS_Start(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void CLACT_DrawSystem(void *);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);
extern void GF_FONT_SetTextColor(unsigned int,unsigned int,unsigned int);
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int func_021C2604(int task,int *state,int unused,char *p) {
 u8 r,g,b;
 Handler fn;
 if(GFL_NET_GetRunState()!=0) {
  switch(DWC_RAPCOMMON_HandleNetError(1,1)) {
   case 4:
    func_021BC0C4(p);func_021BB0B4(p);GFL_NET_SetAutoExit(0);GFL_NET_SetLoginOption(0);func_021C18C8(p,1,2);
    ((struct Obj00825 *)p)->f1E0=20;((struct Obj00825 *)p)->f1CC=0x39;return 0;
   case 2:
    WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);((struct Obj00825 *)p)->f1D0=1;return 1;
  }
 }
 if(func_0200FB24()==0) {
  fn=d_021C3C0C[((struct Obj00825 *)p)->f1CC];
  if(fn!=0) {
   *state=fn(p,*state);
   if(*state==2) {WIPE_SYS_Start(0,0,0,0,6,1,0x21);return 1;}
  }
 }
 if(((struct Obj00825 *)p)->f110!=0) CLACT_DrawSystem(((struct Obj00825 *)p)->f110);
 if(((struct Obj00825 *)p)->f1B8!=0) {
  GF_FONT_GetTextColor(&r,&g,&b);GF_FONT_SetTextColor(1,2,15);TCBL_Main(((struct Obj00825 *)p)->f1C0);GF_FONT_SetTextColor(r,g,b);PRINTSYS_QUE_Main(((struct Obj00825 *)p)->f1B8);
 }
 if(((struct Obj00825 *)p)->f1B4!=0) PRINTSYS_QUE_Main(((struct Obj00825 *)p)->f1B4);
 func_021C2438(p);return 0;
}

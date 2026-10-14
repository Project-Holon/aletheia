/*
 * function: func_021DC370
 * address: 0x021DC370
 * packet: pkt_ov119_021DC370
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);extern u32 KEY_GetTrg(void);extern int TOUCHPANEL_GetTrg(void);extern void func_020355D8(int);extern void POKETRADE_SAVE_CloseMessageWindowClear(void *);extern void POKETRADE_2D_SetupSubBlend(void *);extern void POKETRADE_PROC_SetStep(void *,int);extern void func_021DBE70(void);extern void POKETRADE_2D_UpdateVisibleColumns(int,void *,int);
static inline int poll_a(void) {int r=KEY_GetTrg();if(r)func_020355D8(0);return r;}
static inline int poll_b(void) {int r=TOUCHPANEL_GetTrg();if(r)func_020355D8(1);return r;}
void func_021DC370(char *p) {int hit=0;if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(poll_a()) {func_020355D8(0);hit=1;}if(poll_b()){hit=1;func_020355D8(1);}if(hit){POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_SetStep(p,(int)func_021DBE70);((struct Obj00001 *)p)->f1080=-1;POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828,p,1);}}}

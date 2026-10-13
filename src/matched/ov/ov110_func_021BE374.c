/*
 * function: PMS_INPUT_HandleSentenceMenu
 * address: 0x021BE374
 * packet: pkt_ov110_021BE374
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_CheckUiSwitch 0x021BD808 thumb ov110
 *   PMS_INPUT_HandleSentenceMenuButtons 0x021BDEF0 thumb ov110
 *   PMS_INPUT_HandleSentenceMenuTouch 0x021BE1B8 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern int PMS_INPUT_CheckUiSwitch(u8 *p, void *q);
extern int PMS_INPUT_HandleSentenceMenuButtons(u8 *,unsigned *);
extern int PMS_INPUT_HandleSentenceMenuTouch(u8 *,unsigned *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int PMS_INPUT_HandleSentenceMenu(u8 *p,unsigned *q) {
 if(*q<=2 && PMS_INPUT_CheckUiSwitch(p,q) && !((struct Obj00012 *)p)->f70) { GFL_USE_PlaySeDefaultVolume(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return PMS_INPUT_HandleSentenceMenuButtons(p,q); }
 else { return PMS_INPUT_HandleSentenceMenuTouch(p,q); }
}

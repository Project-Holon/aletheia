/*
 * function: BOX2_SEQ_DeleteSlotWindows
 * address: 0x021EA984
 * packet: pkt_ov170_021EA984
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb ov170
 */
#include "../include/Obj23960.h"
#include "../include/Obj23961.h"
#define WORK(p) (*(char **)((p)+0x2C))
struct WinMgr;
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
void BOX2_SEQ_DeleteSlotWindows(unsigned char *p) {
 switch(((struct Obj23961 *)(*(char * *)&((struct Obj23960 *)p)->f0))->f24) {
 case 0: BOX2_SEQ_SetSlotActors((char *)p,2,1); return;
 case 1: case 3: BOX2_UI_ToggleSlotPair(WORK(p),0); BOX2_SEQ_SetSlotActors((char *)p,1,1); return;
 case 2: case 4: case 5:
  BOX2_UI_ToggleSlotPair(WORK(p),0);
  if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(WORK(p)+0x74))==1) {
   BOX2_SEQ_SetSlotActors((char *)p,2,1); return;
  } else { BOX2_SEQ_SetSlotActors((char *)p,1,1); return; }
 }
}

/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteRecordWindow, WIFIBATTLEMATCH_VIEW_UpdateRecordWindow
 * address: 0x021E7710
 * packet: pkt_ov177_021E7710
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * volatile: 0x021E7718 writes hardware 0x04000050
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj 0x021E7CD0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordActor 0x021E7C14 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWin 0x021E7B44 thumb ov177
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   func_020307B0 0x020307B0 arm
 *   WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner 0x021E7AE0 thumb ov177
 */
#include "../include/Obj14374.h"
extern void WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj(void *);
typedef unsigned int   u32;
struct Obj;
extern void WIFIBATTLEMATCH_VIEW_DeleteRecordActor(char *p);
extern void WIFIBATTLEMATCH_VIEW_DeleteRecordWin(void *);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern int WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(unsigned char *p, void *mgr);
void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    switch (((struct Obj14374 *)p)->f98) {
    case 0: case 1: break;
    case 2: case 3: WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj(p); break;
    }
    WIFIBATTLEMATCH_VIEW_DeleteRecordActor(p);
    WIFIBATTLEMATCH_VIEW_DeleteRecordWin(p);
    PMS_DRAW_Delete(((struct Obj14374 *)p)->f7C);
    BG_SYS_FillScrollArea(2, 0, -256);
    BG_SYS_FillScrollArea(1, 0, -256);
    func_020307B0(p);
}
int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr)
{
    return WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(p, mgr);
}

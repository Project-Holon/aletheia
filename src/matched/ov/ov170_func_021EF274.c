/*
 * function: BOX2_UI_InitWindowFrames
 * address: 0x021EF274
 * packet: pkt_ov170_021EF274
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021EF30E.
 * symbols:
 *   BOX2_SEQ_AddTextFrame 0x021EB744 thumb ov170
 *   BOX2_UI_AddFadeFrame 0x021EF630 thumb ov170
 *   BOX2_SEQ_AddMsgFrame 0x021EB79C thumb ov170
 *   BOX2_SEQ_AddNameFrame 0x021EB7C8 thumb ov170
 *   BOX2_UI_SetFrameData 0x021EF31C thumb ov170
 *   BOX2_SEQ_PutNameFrame 0x021EB95C thumb ov170
 *   BOX2_UI_PutSlotFrames 0x021EF4C0 thumb ov170
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 */
#include "../include/Obj01558.h"
#include "../include/Obj24042.h"
typedef unsigned int u32;
struct WinMgr;
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BOX2_SEQ_AddTextFrame(char *);
extern void BOX2_UI_AddFadeFrame(char *);
extern void BOX2_SEQ_AddMsgFrame(unsigned char *p);
extern void BOX2_SEQ_AddNameFrame(char *);
extern void BOX2_UI_SetFrameData(struct WinMgr *mgr,int,int);
extern void BOX2_SEQ_PutNameFrame(char *);
extern void BOX2_UI_PutSlotFrames(struct WinMgr *mgr);
#define MGR(w) (*(struct WinMgr **)((w)+0x74))
void BOX2_UI_InitWindowFrames(char *p)
{
    char *w=*(char * *)&((struct Obj01558 *)p)->f2C;
    MGR(w)=BGWINFRM_Create(2,12,0x4c);
    BOX2_SEQ_AddTextFrame(w);
    BOX2_UI_AddFadeFrame(p);
    BOX2_SEQ_AddMsgFrame((unsigned char *)p);
    BOX2_SEQ_AddNameFrame(p);
    BGWINFRM_AddFrame(MGR(w),8,1,11,15);
    if(((struct Obj24042 *)(*(char * *)&((struct Obj01558 *)p)->f0))->f24==4) BOX2_UI_SetFrameData(MGR(w),8,8);
    else BOX2_UI_SetFrameData(MGR(w),8,9);
    BGWINFRM_AddFrame(MGR(w),7,1,11,15);
    BOX2_UI_SetFrameData(MGR(w),7,10);
    BOX2_SEQ_PutNameFrame(p);
    BGWINFRM_AddFrame(MGR(w),9,1,11,21);
    BOX2_UI_SetFrameData(MGR(w),9,11);
    BOX2_UI_PutSlotFrames(MGR(w));
}

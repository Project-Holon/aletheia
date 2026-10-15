/*
 * function: BOX2_SEQ_StateMoveClose
 * address: 0x021E432C
 * packet: pkt_ov170_021E432C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_UI_SlideBarOut 0x021EF3EC thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23899.h"
#include "../include/Obj23900.h"
typedef unsigned char u8;
typedef unsigned int u32;
#define W(p) (*(u8 **)((p) + 44))
struct WinMgr;
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *p, int a);
extern void BOX2_UI_SlideBarOut(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_SetWindow9(u8 *, int, int);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_ShowWindowB(char *p);
extern void BOX2_UI_ShowWindowA(char *p);
int BOX2_SEQ_StateMoveClose(u8 *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(W(p) + 0xa194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable((char *)W(p), 4, 0);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
        if (p[27] == 0) {
            BOX2_UI_OpenBar(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 2;
        } else {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            BOX2_UI_ToggleSlotPair((char *)W(p), 0);
            BOX2_UI_SlideBarOut(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 33);
    case 1:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, selection + 30);
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        BOX2_SEQ_SetWindow9(p, 14, 1);
        if (((struct Obj23899 *)(*(u8 * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            BOX2_UI_MoveCursor((char **)p, 5, selection);
            return 27;
        }
        BOX2_UI_ShowWindowB((char *)W(p));
        BOX2_UI_MoveCursor((char **)p, 14, selection);
        return 39;
    case 2:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index >= 30)
            index = 0;
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, index);
        BOX2_UI_ShowWindowA((char *)W(p));
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        BOX2_SEQ_SetWindow9(p, 14, 1);
        if (((struct Obj23900 *)(*(u8 * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            BOX2_UI_MoveCursor((char **)p, 13, index);
            return 35;
        }
        BOX2_UI_MoveCursor((char **)p, 3, index);
        return 17;
    }
    return 33;
}

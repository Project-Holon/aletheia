/*
 * function: BOX2_SEQ_StateCloseItem
 * address: 0x021E695C
 * packet: pkt_ov170_021E695C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Assign selection = 0 after the setter getter in case 1's else arm;
 *   a function-entry initializer hoists zero into the switch dispatch (256 B DIFF).
 * symbols:
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_SlideBarOut 0x021EF3EC thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23905.h"
#include "../include/Obj23906.h"
#include "../include/Obj23907.h"
#include "../include/Obj23908.h"
#include "../include/Obj23909.h"
#include "../include/Obj23910.h"
#include "../include/Obj23911.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void BOX2_MAIN_ResetBoxView(char *);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_SlideBarOut(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(u8 *);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_SetWindow9(u8 *, int, int);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void BOX2_UI_MoveCursor(char **, int, int);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_ShowWindowB(char *);
int BOX2_SEQ_StateCloseItem(u8 *p)
{
    u8 index;
    u8 selection;
    switch (((struct Obj23905 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194) {
    case 0:
        BOX2_MAIN_ResetBoxView((char *)p);
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 4, 0);
        if (p[30] == 0) {
            BOX2_UI_OpenBar(*(struct WinMgr * *)&((struct Obj23906 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        } else {
            BOX2_UI_ToggleSlotPair(*(char * *)&((struct Obj00000 *)p)->f2C, 0);
            BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            BOX2_UI_SlideBarOut(*(struct WinMgr * *)&((struct Obj23907 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((struct Obj23908 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 65);
    case 1:
        ((struct Obj23909 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194 = 0;
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        BOX2_SEQ_SetWindow9(p, 14, 1);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
        if (p[30] == 0) {
            index = func_020260E0(((struct Obj23910 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            BOX2_UI_MoveCursor((char **)p, 7, index);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, index);
            BOX2_UI_ShowWindowA(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 57;
        } else {
            index = func_020260E0(((struct Obj23911 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            BOX2_UI_MoveCursor((char **)p, 8, selection);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, selection + 30);
            BOX2_UI_ShowWindowB(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 70;
        }
    }
    return 65;
}

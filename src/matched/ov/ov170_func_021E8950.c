/*
 * function: BOX2_SEQ_StatePmVoiceConfirm
 * address: 0x021E8950
 * packet: pkt_ov170_021E8950
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return from BOX2_SEQ_ResetEntryB is used despite its legacy void declaration.
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ResetEntryB 0x021EA858 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23935.h"
#include "../include/Obj23936.h"
#include "../include/Obj23937.h"
#include "../include/Obj23938.h"
typedef unsigned char u8;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *, int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ResetEntryB(char *, int);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_SEQ_SetSlotActors(char *, int, int);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int BOX2_SEQ_StatePmVoiceConfirm(char *p)
{
    switch (S) {
    case 0:
        *(u8 *)(W + 0xA17A) = 0;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(W, 25);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_SetMiniIconVisible(p, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        S++;
        return BOX2_SEQ_ResetEntryB(p, 0x62);
    case 1:
        S = 0;
        BOX2_UI_ToggleSlotPair(W, 1);
        BOX2_UI_DeleteSlotObjects(p, 0, 0, 1);
        BOX2_SEQ_SetWindow9((unsigned char *)p, 14, 1);
        if (((struct Obj23935 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            BOX2_SEQ_SetSlotActors(p, 1, 0);
            BOX2_UI_ShowWindowA(W);
            BOX2_UI_MoveCursor((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23936 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 1) {
            BOX2_SEQ_SetSlotActors(p, 1, 0);
            BOX2_UI_MoveCursor((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23937 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            BOX2_SEQ_SetSlotActors(p, 0x81, 1);
            BOX2_UI_ShowWindowA(W);
            BOX2_UI_MoveCursor((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23938 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            BOX2_SEQ_SetSlotActors(p, 1, 0);
            BOX2_UI_ShowWindowA(W);
            BOX2_UI_MoveCursor((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x62;
}

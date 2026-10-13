/*
 * function: OPTION_MENU_StateMain
 * address:  0x021BB1C4
 * packet:   pkt_ov068_021BB1C4
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * OPTION_MENU_UpdateList receives a fifth (stack) argument, w + 0x104, that its own
 * body never reads.
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   OPTION_MENU_ReadInput  0x021BA03C  thumb  ov068
 *   OPTION_MENU_GetButtonChoice  0x021BA65C  thumb  ov068
 *   OPTION_MENU_UpdateList  0x021BA7C0  thumb  ov068
 *   OPTION_MENU_UpdateButtons  0x021BA448  thumb  ov068
 *   OPTION_MENU_HasButtonFocusChanged  0x021BA730  thumb  ov068
 *   OPTION_MENU_ClearListHighlight  0x021BA9C0  thumb  ov068
 *   OPTION_MENU_IsButtonFinished  0x021BA668  thumb  ov068
 *   OPTION_MENU_GetListSettings  0x021BA9E0  thumb  ov068
 *   OPTION_MENU_AreSettingsEqual  0x021BB0E4  thumb  ov068
 *   OPTION_MENU_SetRunnerCallback  0x021BB138  thumb  ov068
 *   OPTION_MENU_ResetButtons  0x021BA694  thumb  ov068
 *   OPTION_MENU_StateApply  0x021BB4D4  thumb  ov068
 *   OPTION_MENU_StateKeepSaved  0x021BB4A4  thumb  ov068
 *   OPTION_MENU_StateDiscardPrompt  0x021BB418  thumb  ov068
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   OPTION_MENU_GetTextWait  0x021BB0D0  thumb  ov068
 *   OPTION_MENU_PrintMessage  0x021BAF0C  thumb  ov068
 *   OPTION_MENU_PrintHelpMessage  0x021BAEC4  thumb  ov068
 *   OPTION_MENU_SetListButtonMode  0x021BA9FC  thumb  ov068
 *   OPTION_MENU_RedrawList  0x021BA9F0  thumb  ov068
 *   OPTION_MENU_IsMessageDone  0x021BAF38  thumb  ov068
 */
#include "../include/Obj09875.h"
#include "../include/Obj20654.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u8  b;
    u8  pad5[3];
    u32 c;
} Blk;

struct Big;
struct Ctx;
struct PrintSys;
struct Sub020071E4Ctrl;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void OPTION_MENU_ReadInput(int *p);
extern int  OPTION_MENU_GetButtonChoice(u8 *p, int *out);
extern void OPTION_MENU_UpdateList(u8 *p, void *a1, void *a2, void *a3, void *a4);
extern void OPTION_MENU_UpdateButtons(u8 *p, u8 *a, u8 *b);
extern int  OPTION_MENU_HasButtonFocusChanged(u8 *p);
extern void OPTION_MENU_ClearListHighlight(u8 *p, char *q);
extern u32  OPTION_MENU_IsButtonFinished(u8 *p);
extern void OPTION_MENU_GetListSettings(u8 *p, Blk *out);
extern int OPTION_MENU_AreSettingsEqual(const u8 *p, const u8 *q);
extern void OPTION_MENU_SetRunnerCallback(void *p, int v);
extern void OPTION_MENU_ResetButtons(u8 *p);
extern void OPTION_MENU_StateApply(void *a, u32 b, u8 *p);
extern void OPTION_MENU_StateKeepSaved(void *a, u32 b, u8 *p);
extern void OPTION_MENU_StateDiscardPrompt(void *a0, u32 *st, u8 *base);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern u32  OPTION_MENU_GetTextWait(Blk *b);
extern void OPTION_MENU_PrintMessage(void *p, u32 id, u32 value);
extern void OPTION_MENU_PrintHelpMessage(void *a, u32 b, u32 c);
extern void OPTION_MENU_SetListButtonMode(u8 *p, u8 v);
extern void OPTION_MENU_RedrawList(u8 *p, int v);
extern int  OPTION_MENU_IsMessageDone(u8 *p);

void OPTION_MENU_StateMain(void *a, u32 *st, u8 *w)
{
    Blk b50;
    Blk b44;
    Blk b38;
    Blk b2C;
    Blk b20;
    Blk b14;
    Blk b8;
    int k;
    int r;

    if (func_0201C6B4((const struct PrintSys *)(((struct Obj09875 *)w)->f258)) == 0)
        return;
    switch (*st) {
    case 0:
        OPTION_MENU_ReadInput((int *)(w + 0xE4));
        if (OPTION_MENU_GetButtonChoice(w + 0x104, 0) == 0)
            OPTION_MENU_UpdateList(w + 0x148, w + 0xE4, w + 0x1A0, w, w + 0x104);
        OPTION_MENU_UpdateButtons(w + 0x104, w + 0xE4, w + 0x148);
        if (OPTION_MENU_HasButtonFocusChanged(w + 0x104))
            OPTION_MENU_ClearListHighlight(w + 0x148, (char *)w);
        if (OPTION_MENU_GetButtonChoice(w + 0x104, &k)) {
            switch (k) {
            case 0:
                if (OPTION_MENU_IsButtonFinished(w + 0x104))
                    OPTION_MENU_SetRunnerCallback(a, (int)OPTION_MENU_StateApply);
                break;
            case 2:
                **(int * *)&((struct Obj09875 *)w)->f26C = 1;
                OPTION_MENU_GetListSettings(w + 0x148, &b50);
                if (OPTION_MENU_AreSettingsEqual(w + 0x248, (const u8 *)(&b50))) {
                    OPTION_MENU_SetRunnerCallback(a, (int)OPTION_MENU_StateKeepSaved);
                } else {
                    OPTION_MENU_ResetButtons(w + 0x104);
                    OPTION_MENU_SetRunnerCallback(a, (int)OPTION_MENU_StateDiscardPrompt);
                }
                break;
            case 1:
                if (OPTION_MENU_IsButtonFinished(w + 0x104)) {
                    OPTION_MENU_GetListSettings(w + 0x148, &b44);
                    if (OPTION_MENU_AreSettingsEqual(w + 0x248, (const u8 *)(&b44))) {
                        OPTION_MENU_SetRunnerCallback(a, (int)OPTION_MENU_StateKeepSaved);
                    } else {
                        OPTION_MENU_ResetButtons(w + 0x104);
                        OPTION_MENU_SetRunnerCallback(a, (int)OPTION_MENU_StateDiscardPrompt);
                    }
                }
                break;
            }
        }
        r = func_020071F0(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj20654 *)(*(u8 * *)&((struct Obj09875 *)w)->f26C))->f4))));
        OPTION_MENU_GetListSettings(w + 0x148, &b38);
        if (b38.b == 0 && r != 0)
            *st = 1;
        break;
    case 1:
        OPTION_MENU_GetListSettings(w + 0x148, &b2C);
        OPTION_MENU_PrintMessage(w + 0x1D8, 0x20, OPTION_MENU_GetTextWait(&b2C));
        OPTION_MENU_SetListButtonMode(w + 0x148, 1);
        *st = 5;
        break;
    case 2:
        OPTION_MENU_GetListSettings(w + 0x148, &b20);
        OPTION_MENU_PrintHelpMessage(w + 0x1D8, 0x16, OPTION_MENU_GetTextWait(&b20));
        OPTION_MENU_RedrawList(w + 0x148, 0);
        *st = 5;
        break;
    case 3:
        OPTION_MENU_GetListSettings(w + 0x148, &b14);
        OPTION_MENU_PrintHelpMessage(w + 0x1D8, 0x16, OPTION_MENU_GetTextWait(&b14));
        OPTION_MENU_RedrawList(w + 0x148, 0);
        *st = 5;
        break;
    case 4:
        OPTION_MENU_GetListSettings(w + 0x148, &b8);
        OPTION_MENU_PrintMessage(w + 0x1D8, 0x24, OPTION_MENU_GetTextWait(&b8));
        OPTION_MENU_RedrawList(w + 0x148, 1);
        *st = 5;
        break;
    case 5:
        if (OPTION_MENU_IsMessageDone(w + 0x1D8))
            *st = 0;
        break;
    }
}

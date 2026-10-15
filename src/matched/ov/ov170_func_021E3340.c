/*
 * function: BOX2_SEQ_StateSwapMenu
 * address:  0x021E3340
 * packet:   pkt_ov170_021E3340
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintMenuRow 0x021EBD1C thumb
 *   BOX2_SEQ_PrintYesNo 0x021EBD78 thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */
#include "../include/Obj00000.h"
#include "../include/Obj23893.h"

struct WinMgr;
extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *p);
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_Delete(char *p);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_PrintMenuRow(char *p, int row, int b);
extern void BOX2_SEQ_PrintYesNo(char *p, int b);
extern void BOX2_UI_ShowWindowA(char *w);
extern void BOX2_UI_ShowWindowB(char *w);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define MODE(p) (*(unsigned char *)(WORK(p) + 0xA173))
#define STATE(p) (*(int *)((p) + 0x28))

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

int BOX2_SEQ_StateSwapMenu(unsigned char *p)
{
    unsigned char sel;
    int arg;
    BOX2_MAIN_UpdateBoxSlots(p);
    p[0x18] = 0;
    p[0x17] = 0xFF;
    if (MODE(p) == 0) {
        sel = func_020260E0(OBJ(p));
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        BOX2_UI_SetCursorPos((char **)p, p[0x16]);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        sel = p[0x16];
    }
    *(int *)(WORK(p) + 0xA168) = sel;
    BOX2_SEQ_Delete((char *)p);
    if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
        if (STATE(p) == 0x20) {
            BOX2_UI_MoveCursor((char **)p, 4, sel);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, sel);
            STATE(p) = 0x15;
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((char *)p);
            arg = 2;
        }
    } else if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1) {
        if (STATE(p) == 0x15) {
            sel = func_020260E0(OBJ(p));
            if (sel > 0x20)
                sel = p[0x16];
            BOX2_UI_MoveCursor((char **)p, 6, sel);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, sel);
            STATE(p) = 0x20;
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((char *)p);
            arg = 2;
        }
    } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, sel);
        arg = 0;
    } else {
        BOX2_MAIN_ResetBoxView((char *)p);
        arg = 2;
    }
    if (((Nib *)(p + 0x1C))->lo == 0) {
        ((Nib *)(p + 0x1C))->hi = 1;
        arg = p[0x21];
    }
    BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, arg);
    switch (MODE(p)) {
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 2, 0x18);
        return 0x18;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 3, 0x18);
        return 0x18;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 4, 0x18);
        return 0x18;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintYesNo((char *)p, 0);
        return 0x18;
    }
    if (((struct Obj23893 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
        if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1)
            BOX2_UI_ShowWindowA(WORK(p));
        else
            BOX2_UI_ShowWindowB(WORK(p));
    }
    return STATE(p);
}

/*
 * function: IRCBATTLEMENU_Exit
 * address:  0x02197B5C
 * packet:   pkt_ov021_02197B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   IRCBATTLEMENU_FreeMenuGraphics  0x02196768  thumb  ov021
 *   IRC_BATTLE_ENTRY_SetMode  0x02155A8C  thumb  ov010
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   func_020307B0  0x020307B0  arm
 *   IRCBATTLEMENU_DeleteClact  0x021974A0  thumb  ov021
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   func_020403F4  0x020403F4  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19637.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 WIPE_SYS_EndCheck(void);
struct Obj;
extern void IRCBATTLEMENU_FreeMenuGraphics(u8 *p);
extern void IRC_BATTLE_ENTRY_SetMode(u8 *, u32);
struct Bank;
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec3;
struct S02031140;
struct TaskMenu;
struct TaskMenuState;
extern void TIME_ICON_Delete(u8 *p);
extern u32 func_020307B0(void *p);
extern void IRCBATTLEMENU_DeleteClact(struct Obj *o);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_020403F4(u32);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void GFL_HEAP_DeleteChecked(u32);

int IRCBATTLEMENU_Exit(u32 a, u32 b, u8 *c, u32 *d)
{
    if (!WIPE_SYS_EndCheck()) {
        return 0;
    }
    IRCBATTLEMENU_FreeMenuGraphics((u8 *)d);
    IRC_BATTLE_ENTRY_SetMode(c, d[2]);
    ((struct Obj19637 *)c)->f58 = d[3];
    if (d[0xBA] != 0) {
        TIME_ICON_Delete((u8 *)d[0xBA]);
        d[0xBA] = 0;
    }
    func_020307B0((void *)d[0xBB]);
    func_020307B0((void *)d[0xBC]);
    IRCBATTLEMENU_DeleteClact((struct Obj *)d);
    if (d[0xAD] != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)d[0xAD]);
    }
    APP_KEYCURSOR_Delete(d[0xAA]);
    TCBL_Destroy((struct S02031140 *)d[0xAE]);
    func_020403F4(7);
    PRINTSYS_QUE_Clear((struct PrintSys *)d[0xAF]);
    PRINTSYS_QUE_Delete((struct PrintSys *)d[0xAF]);
    if (d[0xAC] != 0) {
        BMP_WIN_Delete((struct Descriptor *)d[0xAC]);
    }
    if (d[0xB0] != 0) {
        APP_TASKMENU_CloseMenu((struct TaskMenu *)d[0xB0]);
        d[0xB0] = 0;
    }
    if (d[0xB8] != 0) {
        APP_TASKMENU_WIN_Delete((u8 *)d[0xB8]);
    }
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)d[0xB7]);
    func_02030EAC((struct Node *)d[0x9A]);
    CLACT_DeleteUnit((struct Bank *)d[0x9B]);
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_020315D4((struct S020315D4 *)a);
    GFL_HEAP_DeleteChecked(0x1f);
    return 1;
}

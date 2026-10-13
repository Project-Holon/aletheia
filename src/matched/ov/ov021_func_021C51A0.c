/*
 * function: SHORTCUT_MENU_Delete
 * address:  0x021C51A0
 * packet:   pkt_ov021_021C51A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   SHORTCUT_MENU_FreeList  0x021C5424  thumb  ov021
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00020.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern int SHORTCUT_MENU_FreeList(u32 a, u32 b);
struct Bank;
struct Obj;
struct PrintSys;
struct Rec;
extern void CLACT_DeleteActor(struct Obj *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);

void SHORTCUT_MENU_Delete(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    SHORTCUT_MENU_FreeList((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        CLACT_DeleteActor((struct Obj *)a[0x58 / 4 + i]);
    }
    PRINTSYS_QUE_Clear((struct PrintSys *)a[0x6c / 4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)a[0x6c / 4]);
    GF_FONT_Delete((void *)a[0x68 / 4]);
    MSGDATA_Delete((struct Rec *)a[0x64 / 4]);
    CLACT_ReleasePalette(((struct Obj00020 *)a)->f50);
    CLACT_ReleaseCharacter(((struct Obj00020 *)a)->f52);
    CLACT_ReleaseCellAnim(((struct Obj00020 *)a)->f54);
    CLACT_DeleteUnit((struct Bank *)a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((void *)((int)a));
}

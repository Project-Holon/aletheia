/*
 * function: SHORTCUT_MENU_Main
 * address:  0x021C5224
 * packet:   pkt_ov021_021C5224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHORTCUT_MENU_RunPrint 0x021C5334 thumb ov021
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   SHORTCUT_MENU_ScrollStep 0x021C59BC thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   SHORTCUT_MENU_UpdateInput 0x021C553C thumb ov021
 *   SHORTCUT_MENU_GetSelection 0x021C5768 thumb ov021
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
#include "../include/Obj01216.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern int SHORTCUT_MENU_RunPrint(u32 a);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
typedef unsigned char  u8;
struct Node;
extern void SHORTCUT_MENU_ScrollStep(void *a, u8 *p);
extern void func_02030EAC(struct Node *n);
extern void SHORTCUT_MENU_UpdateInput(char *p);
extern int SHORTCUT_MENU_GetSelection(char *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

void SHORTCUT_MENU_Main(char *p)
{
    int r;
    int i;

    if (SHORTCUT_MENU_RunPrint((u32)p) == 0) {
        return;
    }
    switch (((struct Obj01216 *)p)->f70) {
    case 0:
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        ((struct Obj01216 *)p)->f72 = 0;
        ((struct Obj01216 *)p)->f80 = 0;
        ((struct Obj01216 *)p)->f84 = func_020056A0((void *)SHORTCUT_MENU_ScrollStep, p, 0);
        ((struct Obj01216 *)p)->f70 = 2;
        break;
    case 2:
        if (((struct Obj01216 *)p)->f80 != 0) {
            func_02030EAC(((struct Obj01216 *)p)->f84);
            ((struct Obj01216 *)p)->f70 = 3;
        }
        break;
    case 3:
        SHORTCUT_MENU_UpdateInput(p);
        r = SHORTCUT_MENU_GetSelection(p);
        switch (r) {
        case -1:
            ((struct Obj01216 *)p)->f74 = 0;
            break;
        case -2:
            ((struct Obj01216 *)p)->f74 = 2;
            break;
        default:
            ((struct Obj01216 *)p)->f74 = 1;
            ((struct Obj01216 *)p)->f78 = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + 0x58 + i * 4), 0);
        }
        ((struct Obj01216 *)p)->f72 = 4;
        ((struct Obj01216 *)p)->f70 = 5;
        break;
    case 5:
        BG_SYS_ChangeScrollImmediate(1, 3, ((struct Obj01216 *)p)->f72 * 0xC0 / 4 - 0xC0);
        if ((((struct Obj01216 *)p)->f72)-- == 0) {
            ((struct Obj01216 *)p)->f70 = 0;
        }
        break;
    }
}

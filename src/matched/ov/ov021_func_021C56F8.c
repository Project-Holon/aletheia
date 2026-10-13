/*
 * function: SHORTCUT_MENU_FinishPrint
 * address:  0x021C56F8
 * packet:   pkt_ov021_021C56F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   SHORTCUT_MENU_UpdateCursorBg  0x021C577C  thumb  ov021
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj02094.h"

typedef unsigned char u8;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void SHORTCUT_MENU_UpdateCursorBg(int a, int b, int c);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

int SHORTCUT_MENU_FinishPrint(int *a)
{
    int r4 = a[3];
    int i;
    int r7;

    if (((struct Obj02094 *)a)->f14 != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)r4, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)a[4]))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)a[4]);
            ((struct Obj02094 *)a)->f14 = 0;
        }
    }
    r7 = 1;
    if (((struct Obj02094 *)a)->f14 != 0) {
        r7 = 0;
    }
    if (r7 != 0) {
        if (a[0x11] != 0) {
            SHORTCUT_MENU_UpdateCursorBg(a[1], 0, 0);
            a[0x11] = 0;
        }
        if (a[0x12] != 0) {
            for (i = 0; i < 3; i++) {
                CLACT_SetActorDrawEnable((struct Obj *)a[0xa + i], 1);
            }
            a[0x12] = 0;
        }
    }
    return r7;
}

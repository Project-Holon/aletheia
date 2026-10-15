/*
 * function: CTVT_TALK_Exit
 * address:  0x021B8FB8
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears down both 0x2c/0x7c buffers and the five 0x90 blocks, then clears the
 * display register.
 *
 * symbols:
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02505.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Obj;
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_020414EC(u32 i);

void CTVT_TALK_Exit(void *a0, char *a1)
{
    void *p;

    if (((struct Obj02505 *)a1)->f80 != 0)
        APP_TASKMENU_CloseMenu(((struct Obj02505 *)a1)->f80);

    p = ((struct Obj02505 *)a1)->f2C;
    BMP_WIN_ClearScreen(p);
    func_020409B4(BMP_WIN_GetBgLayer(p));

    p = ((struct Obj02505 *)a1)->f7C;
    BMP_WIN_ClearScreen(p);
    func_020409B4(BMP_WIN_GetBgLayer(p));

    BMP_WIN_Delete(((struct Obj02505 *)a1)->f2C);
    BMP_WIN_Delete(((struct Obj02505 *)a1)->f7C);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f98);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->fA0);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f9C);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f94);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f90);
    func_020414EC(6);
    func_020409B4(6);
    *(u16 *)0x04001050 = 0;
}

/*
 * function: GTSNEGO_MSG_DeleteAll
 * address:  0x021D883C
 * packet:   pkt_021D883C
 * region:   ov120
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tear-down: releases the handle at p+0x68, the pointer at p+0xC4, six
 * p+0x6C slots, then two ov120 callbacks and a six-argument SDK call.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder    0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen    0x020456F8  arm
 *   func_02041B6C    0x02041B6C  arm
 *   BMP_WIN_Delete    0x020452E8  arm
 *   APP_TASKMENU_WIN_Delete    0x02028148  thumb
 *   func_02049B40    0x02049B40  arm
 *   GTSNEGO_MSG_ClearRows    0x021D7D3C  thumb  ov120
 *   GTSNEGO_MSG_DeleteRows    0x021D7C1C  thumb  ov120
 */
#include "../include/Obj03260.h"
#include "../include/Obj08087.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void GTSNEGO_MSG_ClearRows(char *p);
extern void GTSNEGO_MSG_DeleteRows(char *p);

void GTSNEGO_MSG_DeleteAll(char *p)
{
    int i;

    if (((struct Obj03260 *)p)->f68 != 0) {
        BMP_MENUWORK_DrawWindowBorder(((struct Obj03260 *)p)->f68, 2);
        BMP_WIN_ClearScreen(((struct Obj03260 *)p)->f68);
        func_02041B6C(1);
        BMP_WIN_Delete(((struct Obj03260 *)p)->f68);
        ((struct Obj03260 *)p)->f68 = 0;
    }
    if (((struct Obj03260 *)p)->fC4 != 0) {
        APP_TASKMENU_WIN_Delete(((struct Obj03260 *)p)->fC4);
        ((struct Obj03260 *)p)->fC4 = 0;
    }
    for (i = 0; i < 6; i++) {
        char *q = p + i * 4;

        if (((struct Obj08087 *)q)->f6C != 0) {
            BMP_WIN_ClearScreen(((struct Obj08087 *)q)->f6C);
            BMP_WIN_Delete(((struct Obj08087 *)q)->f6C);
            ((struct Obj08087 *)q)->f6C = 0;
        }
    }
    GTSNEGO_MSG_ClearRows(p);
    GTSNEGO_MSG_DeleteRows(p);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct Obj03260 *)p)->fC8);
    func_02041B6C(5);
}

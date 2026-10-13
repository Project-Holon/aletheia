/*
 * function: func_021D883C
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
 *   func_0201F7A8    0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen    0x020456F8  arm
 *   func_02041B6C    0x02041B6C  arm
 *   func_020452E8    0x020452E8  arm
 *   APP_TASKMENU_WIN_Delete    0x02028148  thumb
 *   func_02049B40    0x02049B40  arm
 *   func_021D7D3C    0x021D7D3C  thumb  ov120
 *   func_021D7C1C    0x021D7C1C  thumb  ov120
 */
#include "../../../matched/include/Obj03260.h"
#include "../../../matched/include/Obj08087.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern u32 func_020452E8(struct Descriptor *d);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021D7D3C(char *p);
extern void func_021D7C1C(char *p);

void func_021D883C(char *p)
{
    int i;

    if (((struct Obj03260 *)p)->f68 != 0) {
        func_0201F7A8(((struct Obj03260 *)p)->f68, 2);
        BMP_WIN_ClearScreen(((struct Obj03260 *)p)->f68);
        func_02041B6C(1);
        func_020452E8(((struct Obj03260 *)p)->f68);
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
            func_020452E8(((struct Obj08087 *)q)->f6C);
            ((struct Obj08087 *)q)->f6C = 0;
        }
    }
    func_021D7D3C(p);
    func_021D7C1C(p);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct Obj03260 *)p)->fC8);
    func_02041B6C(5);
}

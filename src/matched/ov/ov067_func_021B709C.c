/*
 * function: YESNO_MENU_Delete
 * address:  0x021B709C
 * packet:   pkt_ov067_021B709C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   UI_SCENE_FreeActorGfx  0x021B6284  thumb  ov067
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj07677.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);

void YESNO_MENU_Delete(u8 *p)
{
    u8 i;
    u32 v;

    for (i = 0; i < 4; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)(p + i * 4 + 0xa0)));
    }
    UI_SCENE_FreeActorGfx((unsigned int *)(p + 0xb0));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj07677 *)p)->f88));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj07677 *)p)->f8C));
    v = ((struct Obj07677 *)p)->f84;
    BG_SYS_DeleteHalf(p[0x14], (u16)v, (u16)(v >> 16));
    func_020307B0(p);
}

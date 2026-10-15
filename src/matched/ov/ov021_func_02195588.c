/*
 * function: TALKMSGWIN_ReloadFrameGraphics
 * address:  0x02195588
 * packet:   pkt_ov021_02195588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 */
#include "../include/Obj04219.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BG_SYS_ClearSlot(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

void TALKMSGWIN_ReloadFrameGraphics(u8 *p)
{
    u32 r;
    u32 v;

    BG_SYS_ClearSlot(((struct Obj04219 *)p)->f10 & 0xFF);
    v = ((struct Obj04219 *)p)->f10;
    r = 0;
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = 4;
        break;
    }
    func_02049B40(5, 0, r, (u32)p[0x14] << 5, 0x20, ((struct Obj04219 *)p)->f0);
    ARC_UTIL_UploadBgCharFromArchive((void *)5, (void *)5, (void *)(((struct Obj04219 *)p)->f10), (void *)(((struct Obj04219 *)p)->fC), 0, 0, ((struct Obj04219 *)p)->f0);
}

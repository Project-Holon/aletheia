/*
 * function: FIELD_MSGBG_ReloadBg
 * address:  0x02193068
 * packet:   pkt_ov021_02193068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040DA8  0x02040DA8  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   FIELD_MSGBG_LoadWindowGraphicsAll  0x02192FA4  thumb  ov021
 *   TALKMSGWIN_ReloadFrameGraphics  0x02195588  thumb  ov021
 */
#include "../include/Obj04209.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void FIELD_MSGBG_LoadWindowGraphicsAll(int, int);
typedef unsigned char  u8;
extern void TALKMSGWIN_ReloadFrameGraphics(u8 *p);

void FIELD_MSGBG_ReloadBg(char *p)
{
    func_02040DA8(((struct Obj04209 *)p)->f2, 1, 0);
    BG_SYS_Init(((struct Obj04209 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj04209 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj04209 *)p)->f2 & 0xff);
    FIELD_MSGBG_LoadWindowGraphicsAll(((struct Obj04209 *)p)->f2, ((struct Obj04209 *)p)->f0);
    TALKMSGWIN_ReloadFrameGraphics((u8 *)(((struct Obj04209 *)p)->f15C));
}

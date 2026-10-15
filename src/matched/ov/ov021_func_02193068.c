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
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   FIELD_MSGBG_LoadWindowGraphicsAll  0x02192FA4  thumb  ov021
 *   TALKMSGWIN_ReloadFrameGraphics  0x02195588  thumb  ov021
 */
#include "../include/Obj04209.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);
extern void BG_SYS_PushTile(u32 index);
extern void FIELD_MSGBG_LoadWindowGraphicsAll(int, int);
typedef unsigned char  u8;
extern void TALKMSGWIN_ReloadFrameGraphics(u8 *p);

void FIELD_MSGBG_ReloadBg(char *p)
{
    BG_SYS_SetTileUnit(((struct Obj04209 *)p)->f2, 1, 0);
    BG_SYS_Init(((struct Obj04209 *)p)->f2, 0, 1, 0);
    BG_SYS_SetTileEntry(((struct Obj04209 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(((struct Obj04209 *)p)->f2 & 0xff);
    FIELD_MSGBG_LoadWindowGraphicsAll(((struct Obj04209 *)p)->f2, ((struct Obj04209 *)p)->f0);
    TALKMSGWIN_ReloadFrameGraphics((u8 *)(((struct Obj04209 *)p)->f15C));
}

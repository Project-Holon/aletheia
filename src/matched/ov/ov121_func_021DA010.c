/*
 * function: MYSTERY_UTIL_ResetMenuWindow
 * address: 0x021DA010
 * packet: pkt_ov121_021DA010
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj00236.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void TIME_ICON_Delete(u8 *);
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
void MYSTERY_UTIL_ResetMenuWindow(u8 *p) { ((struct Obj00236 *)p)->f2C=1; if(*(u8 * *)&((struct Obj00236 *)p)->f3C) { TIME_ICON_Delete(*(u8 * *)&((struct Obj00236 *)p)->f3C); *(u32 *)&((struct Obj00236 *)p)->f3C=0; BMP_WIN_MakeScreen(((struct Obj00236 *)p)->f10); BG_SYS_PushTile(BMP_WIN_GetBgLayer(((struct Obj00236 *)p)->f10)); } }

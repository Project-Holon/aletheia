/*
 * function: WIFILOGIN_MSG_RedrawWindow
 * address: 0x021D5C94
 * packet: pkt_ov115_021D5C94
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   WIFILOGIN_MSG_GetFrameIdA 0x021D5FA0 thumb ov115
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04467.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void TIME_ICON_Delete(u8 *);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 WIFILOGIN_MSG_GetFrameIdA(u32);
extern void func_02041B6C(u32);
void WIFILOGIN_MSG_RedrawWindow(u8 *p) { if(*(u8 * *)&((struct Obj04467 *)p)->f80) { TIME_ICON_Delete(*(u8 * *)&((struct Obj04467 *)p)->f80); *(u8 * *)&((struct Obj04467 *)p)->f80=0; } if(((struct Obj04467 *)p)->f2C) { BMP_MENUWORK_DrawWindowBorder(((struct Obj04467 *)p)->f2C,2); BMP_WIN_ClearScreen(((struct Obj04467 *)p)->f2C); func_02041B6C(WIFILOGIN_MSG_GetFrameIdA(((struct Obj04467 *)p)->f50)); } }

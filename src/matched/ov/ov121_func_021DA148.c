/*
 * function: func_021DA148
 * address: 0x021DA148
 * packet: pkt_ov121_021DA148
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06448.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
void func_021DA148(u8 *p) { BMP_MENULIST_Delete(((struct Obj06448 *)p)->f10,0,0); BMP_MENUWORK_Delete(((struct Obj06448 *)p)->f14); BMP_MENUWORK_DrawWindowBorder(((struct Obj06448 *)p)->f0,0); BMP_WIN_ClearScreen(((struct Obj06448 *)p)->f0); BMP_WIN_Delete(((struct Obj06448 *)p)->f0); func_020307B0(p); }

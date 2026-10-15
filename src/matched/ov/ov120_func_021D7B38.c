/*
 * function: GTSNEGO_MSG_DeleteWindow
 * address: 0x021D7B38
 * packet: pkt_ov120_021D7B38
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj06442.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void GTSNEGO_MSG_DeleteWindow(char *p) { if(((struct Obj06442 *)p)->f30) { BMP_MENUWORK_DrawWindowBorder(((struct Obj06442 *)p)->f30,2); BMP_WIN_ClearScreen(((struct Obj06442 *)p)->f30); func_02041B6C(1); BMP_WIN_Delete(((struct Obj06442 *)p)->f30); ((struct Obj06442 *)p)->f30=0; } }

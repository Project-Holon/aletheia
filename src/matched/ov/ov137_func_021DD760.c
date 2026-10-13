/*
 * function: func_021DD760
 * address: 0x021DD760
 * packet: pkt_ov137_021DD760
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj05425.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Descriptor;
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021DD760(u8 *p) {if(((struct Obj05425 *)p)->fE8!=0)BMP_MENU_DeleteYesNo(((struct Obj05425 *)p)->fE8);func_020452E8(((struct Obj05425 *)p)->fD0);func_020452E8(((struct Obj05425 *)p)->fDC);func_020452E8(((struct Obj05425 *)p)->fD8);func_020452E8(((struct Obj05425 *)p)->fD4);BMP_WIN_Exit();}

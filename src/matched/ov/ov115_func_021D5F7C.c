/*
 * function: func_021D5F7C
 * address: 0x021D5F7C
 * packet: pkt_ov115_021D5F7C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 */
#include "../include/Obj08045.h"
typedef unsigned char u8;typedef unsigned int u32;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32);extern u32 func_021D5FC4(u32);
void func_021D5F7C(u8 *p) { if(((struct Obj08045 *)p)->f30){BMP_MENUWORK_DrawWindowBorder(((struct Obj08045 *)p)->f30,2);BMP_WIN_ClearScreen(((struct Obj08045 *)p)->f30);func_02041B6C(func_021D5FC4(((struct Obj08045 *)p)->f50));} }

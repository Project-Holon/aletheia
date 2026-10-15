/*
 * function: func_021B9C74
 * address: 0x021B9C74
 * packet: pkt_ov218_021B9C74
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj26040.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
void func_021B9C74(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj26040 *)p)->f24,1);
}

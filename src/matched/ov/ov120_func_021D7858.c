/*
 * function: func_021D7858
 * address: 0x021D7858
 * packet: pkt_ov120_021D7858
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 */
#include "../include/Obj05351.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GF_FONT_SetTextColor(u32, u32, u32);
struct PrintSys;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void PMS_DRAW_Main(u8 *p);
void func_021D7858(u8 *p)
{
    GF_FONT_SetTextColor(1, 2, 15);
    TCBL_Main(((struct Obj05351 *)p)->fA0);
    PRINTSYS_QUE_Main(((struct Obj05351 *)p)->fA4);
    if (((struct Obj05351 *)p)->fC4) APP_TASKMENU_WIN_Update(((struct Obj05351 *)p)->fC4);
    if (((struct Obj05351 *)p)->fCC) PMS_DRAW_Main(((struct Obj05351 *)p)->fCC);
}

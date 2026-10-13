/*
 * function: P_STA_RIBBON_SnapCursorToScroll
 * address: 0x021D8EA8
 * packet: pkt_ov131_021D8EA8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   P_STA_RIBBON_SelectRow 0x021D8ED0 thumb ov131
 */
#include "../include/Obj00091.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void P_STA_RIBBON_SelectRow(u8 *,u8 *,u8);
void P_STA_RIBBON_SnapCursorToScroll(u8 *a,u8 *p)
{
    P_STA_RIBBON_SelectRow(a,p,(u8)(((((struct Obj00091 *)p)->f14+23)/24)%10));
}

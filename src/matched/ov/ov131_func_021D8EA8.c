/*
 * function: func_021D8EA8
 * address: 0x021D8EA8
 * packet: pkt_ov131_021D8EA8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D8ED0 0x021D8ED0 thumb ov131
 */
#include "../include/Obj00091.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D8ED0(u8 *,u8 *,u8);
void func_021D8EA8(u8 *a,u8 *p)
{
    func_021D8ED0(a,p,(u8)(((((struct Obj00091 *)p)->f14+23)/24)%10));
}

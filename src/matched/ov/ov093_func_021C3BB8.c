/*
 * function: BTL_SERVER_FLOW_ApplyWeatherChange
 * address: 0x021C3BB8
 * packet: pkt_ov093_021C3BB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcWeatherChanged 0x021C3BE0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021EF8A4(u32, u32);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ProcWeatherChanged(u8 *, u32);
void BTL_SERVER_FLOW_ApplyWeatherChange(u8 *p, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x3f, a, b);
    BTL_SERVER_FLOW_ProcWeatherChanged(p, a);
}

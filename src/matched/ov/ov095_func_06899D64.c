/*
 * function: BTLV_SCD_CloseInput
 * address: 0x06899D64
 * packet: pkt_ov095_06899D64
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_06899D80 0x06899D80 thumb ov095
 *   func_06899D90 0x06899D90 thumb ov095
 *   func_06899DA0 0x06899DA0 thumb ov095
 */
#include "../include/Obj21885.h"
typedef unsigned int u32;
extern void func_06899D80(u32, int, int);
extern u32 func_06899D90(int);
extern void func_06899DA0(u32);
void BTLV_SCD_CloseInput(u32 p)
{
    func_06899D80(((struct Obj21885 *)p)->fB0, 0, 0);
    func_06899DA0(func_06899D90(8));
}

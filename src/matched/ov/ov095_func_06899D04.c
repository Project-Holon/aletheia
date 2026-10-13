/*
 * function: BTLV_SCD_IsInputSlideDone
 * address: 0x06899D04
 * packet: pkt_ov095_06899D04
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_06899D1C 0x06899D1C thumb ov095
 */
#include "../include/Obj21884.h"
typedef unsigned int u32;
extern int func_06899D1C(u32);
int BTLV_SCD_IsInputSlideDone(u32 p)
{
    if (func_06899D1C(((struct Obj21884 *)p)->fB0) == 0) return 1;
    return 0;
}

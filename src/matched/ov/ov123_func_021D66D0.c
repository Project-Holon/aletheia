/*
 * function: func_021D66D0
 * address: 0x021D66D0
 * packet: pkt_ov123_021D66D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _f2d 0x0209BD38 arm
 *   _dmul 0x0209B2E8 arm
 *   _d2f 0x0209B64C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj13978.h"
typedef unsigned char u8;
void func_021D66D0(u8 *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (((struct Obj13978 *)p)->f455C > v) ((struct Obj13978 *)p)->f455C = v;
}

/*
 * function: func_021B61A4
 * address: 0x021B61A4
 * packet: pkt_ov098_021B61A4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B6308 0x021B6308 thumb ov098
 */
#include "../include/Obj10195.h"
extern int func_021B6308(unsigned p);
int func_021B61A4(int a, int b, int c, unsigned p)
{
    *(int *)(((struct Obj10195 *)p)->f4 + 0x1c) = func_021B6308((unsigned int)(((struct Obj10195 *)p)->f0));
    if (*(int *)(((struct Obj10195 *)p)->f4 + 0x1c) != 0) return 1;
    return 0;
}

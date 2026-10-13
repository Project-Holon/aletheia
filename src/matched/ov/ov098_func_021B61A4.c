/*
 * function: PDC_ProcMain
 * address: 0x021B61A4
 * packet: pkt_ov098_021B61A4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PDC_MAIN_Update 0x021B6308 thumb ov098
 */
#include "../include/Obj10195.h"
extern int PDC_MAIN_Update(unsigned p);
int PDC_ProcMain(int a, int b, int c, unsigned p)
{
    *(int *)(((struct Obj10195 *)p)->f4 + 0x1c) = PDC_MAIN_Update((unsigned int)(((struct Obj10195 *)p)->f0));
    if (*(int *)(((struct Obj10195 *)p)->f4 + 0x1c) != 0) return 1;
    return 0;
}

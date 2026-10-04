/*
 * function: func_021DF434
 * address: 0x021DF434
 * packet: pkt_ov137_021DF434
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0478 0x021E0478 thumb ov137
 *   func_021E01B0 0x021E01B0 thumb ov137
 *   func_021E1988 0x021E1988 thumb ov137
 */
#include "../include/Obj06541.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_021E0478(u8 *p, u32 i);
extern void func_021E01B0(u8 *p, int message, void *value);
extern void func_021E1988(unsigned int n);
int func_021DF434(u8 *p)
{
    int i;
    ((struct Obj06541 *)p)->fC += 1;
    if (((struct Obj06541 *)p)->fC < 120) return 0;
    ((struct Obj06541 *)p)->fC = 0;
    for (i = 0; i < ((struct Obj06541 *)p)->f30; i++) func_021E0478(p, i);
    func_021E01B0(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int **)(p + 40))[3])));
    func_021E1988(1302);
    ((struct Obj06541 *)p)->f0 = 37;
    return 0;
}

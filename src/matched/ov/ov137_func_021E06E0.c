/*
 * function: func_021E06E0
 * address: 0x021E06E0
 * packet: pkt_ov137_021E06E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   d_021E1E60 0x021E1E60 data a4
 *   d_021E1E70 0x021E1E70 data a4
 *   d_021E212C 0x021E212C data a4
 */
#include "../include/Obj10628.h"
#include "../include/Obj14236.h"
extern int G3D_UTIL_AddUnit(void *,const void *);
extern const char d_021E1E60[],d_021E1E70[],d_021E212C[];
void func_021E06E0(char *p)
{
    int i;
    char *q=p+0x1a0;
    ((struct Obj14236 *)q)->f938=G3D_UTIL_AddUnit(((struct Obj10628 *)p)->fAF4,d_021E1E60);
    ((struct Obj14236 *)q)->f93C=G3D_UTIL_AddUnit(((struct Obj10628 *)p)->fAF4,d_021E1E70);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=G3D_UTIL_AddUnit(((struct Obj10628 *)p)->fAF4,d_021E212C+i*16);
}

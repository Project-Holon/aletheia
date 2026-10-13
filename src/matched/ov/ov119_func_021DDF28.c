/*
 * function: func_021DDF28
 * address: 0x021DDF28
 * packet: pkt_ov119_021DDF28
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76E4 0x021E76E4 data a4
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021E1410 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDED4 0x021DDED4 thumb ov119
 */
#include "../include/Obj22741.h"
typedef struct { int a,b; } Pair;
extern const Pair d_021E76E4;
typedef unsigned int   u32;
extern int func_021E12AC(char *p);
extern void func_021E1410(void *p, int *ids, int count);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D8E84(void *,int);
extern void func_021DDED4(unsigned char *p);
void func_021DDF28(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E76E4;
        func_021E1410(p,(int *)(&t),2);
        BG_SYS_SetMainVisiblePlanes(31);
        TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22741 *)p)->f9C0),1,0);
        func_021D8E84(p,(int)func_021DDED4);
    }
}

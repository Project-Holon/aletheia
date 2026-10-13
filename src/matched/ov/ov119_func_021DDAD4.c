/*
 * function: func_021DDAD4
 * address: 0x021DDAD4
 * packet: pkt_ov119_021DDAD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76F4 0x021E76F4 data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDA50 0x021DDA50 thumb ov119
 */
#include "../include/Obj22740.h"
typedef struct { int a,b; } Pair;
extern const Pair d_021E76F4;
extern void func_021E1410(void *p, int *ids, int count);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D8E84(void *,int);
extern void func_021DDA50(void *);
void func_021DDAD4(char *p)
{
    Pair t=d_021E76F4;
    func_021E1410(p,(int *)(&t),2);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22740 *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DDA50);
}

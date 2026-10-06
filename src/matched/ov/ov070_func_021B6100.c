/*
 * unit: yes
 * function: func_021B6100, func_021B6120
 * address: 0x021B6100
 * packet: pkt_ov070_021B6100
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02036270 0x02036270 arm
 *   func_021B6138 0x021B6138 thumb ov070
 */
#include "../include/Obj00002.h"
#include "../include/Obj20659.h"
extern int func_02036270(int a0, int a1);
extern void func_021B6138(char *p);
void func_021B6100(char *p, int k)
{
    *(int *)&((struct Obj00002 *)p)->f4F8 = k;
    func_02036270(((struct Obj00002 *)p)->f86C, ((struct Obj00002 *)p)->f870);
}
void func_021B6120(char *p)
{
    ((struct Obj20659 *)p)->f818 = 0xFFFF;
    func_021B6138(p);
}

/*
 * function: func_021FCE0C,func_021FCE50
 * unit: yes
 * address: 0x021FCE0C
 * packet: pkt_ov186_021FCE0C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead plus tail-call stub at 021FCE50.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D68 0x02200D68 data a4
 *   func_021FCE60 0x021FCE60 thumb ov186
 */
#include "../include/Obj00048.h"
#include "../include/Obj08332.h"
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02200D68[];
extern void func_021FCE60(char *,int);
int func_021FCE0C(char *p,unsigned field)
{
    switch(field) {
    case 0:return ((struct Obj08332 *)p)->f40;
    case 1:return ((struct Obj08332 *)p)->f42;
    case 2:return ((struct Obj08332 *)p)->f4C;
    case 3:return ((struct Obj08332 *)p)->f4;
    default:func_02034714(d_02200D68,0,d_02200D68);return 0;
    }
}
void func_021FCE50(char *p)
{
    func_021FCE60(p,((struct Obj00048 *)p)->f42);
}

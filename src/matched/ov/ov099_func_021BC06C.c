/*
 * function: func_021BC06C
 * address: 0x021BC06C
 * packet: pkt_ov099_021BC06C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201A570 0x0201A570 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 */
#include "../include/Obj04412.h"
extern void func_0201A570(void *);
extern int func_021BA8BC(void *);
void func_021BC06C(char *p)
{
    func_0201A570(((struct Obj04412 *)p)->f1344);
    *(int *)&((struct Obj04412 *)p)->f1344 = 0;
    *(int *)&((struct Obj04412 *)p)->f19C = func_021BA8BC(((struct Obj04412 *)p)->f19C);
}

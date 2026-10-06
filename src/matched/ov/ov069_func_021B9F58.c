/*
 * unit: yes
 * function: func_021B9F58, func_021B9F68, func_021B9F6C
 * address: 0x021B9F58
 * packet: pkt_ov069_021B9F58
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 * symbols:
 *   func_02025D14 0x02025D14 thumb
 */
#include "../include/Obj01132.h"
typedef unsigned int   u32;
extern u32 func_02025D14(void *a0);
int func_021B9F58(char *p)
{
    return func_02025D14(((struct Obj01132 *)p)->f14C);
}
void func_021B9F68(void) {}
void func_021B9F6C(void) {}

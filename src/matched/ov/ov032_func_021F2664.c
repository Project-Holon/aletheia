/*
 * function: func_021F2664
 * address: 0x021F2664
 * packet: pkt_ov032_021F2664
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021D50 0x02021D50 thumb
 */
#include "../include/Obj13067.h"
struct S02021D50;
extern void func_02021D50(struct S02021D50 *);
void func_021F2664(int a, char *p)
{
    if (*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC)
        func_02021D50(*(struct S02021D50 * *)&((struct Obj13067 *)p)->fAC);
}

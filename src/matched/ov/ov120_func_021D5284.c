/*
 * function: func_021D5284
 * address: 0x021D5284
 * packet: pkt_ov120_021D5284
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6E1C 0x021D6E1C thumb ov120
 *   func_021D6FF8 0x021D6FF8 thumb ov120
 *   func_021D822C 0x021D822C thumb ov120
 */
#include "../include/Obj04487.h"
typedef unsigned char u8;
extern int func_021D6E1C(void *unused, int *p);
extern void func_021D6FF8(u8 *p, int state);
extern void func_021D822C(char *p, void *q, int index);
int func_021D5284(u8 *p)
{
    int result = func_021D6E1C(((struct Obj04487 *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct Obj04487 *)p)->f164 != 8)
            (((struct Obj04487 *)p)->f164)++;
        break;
    case 2:
        func_021D6FF8(((struct Obj04487 *)p)->f3C, 2);
        func_021D822C(((struct Obj04487 *)p)->f40, ((struct Obj04487 *)p)->f2C, ((struct Obj04487 *)p)->f158 + 2);
        break;
    }
    return result;
}

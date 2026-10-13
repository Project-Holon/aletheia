/*
 * function: func_021D52D4
 * address: 0x021D52D4
 * packet: pkt_ov120_021D52D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D51D4 0x021D51D4 thumb ov120
 */
#include "../include/Obj06434.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void func_02028148(u8 *p);
extern void func_02041B6C(u32 bit);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D51D4(u8 *p);
void func_021D52D4(u8 *p)
{
    if (APP_TASKMENU_WIN_IsFinish(((struct Obj06434 *)p)->f34)) {
        func_02028148(((struct Obj06434 *)p)->f34);
        *(int *)&((struct Obj06434 *)p)->f34 = 0;
        ((struct Obj06434 *)p)->f148 = -1;
        func_021D69F4(((struct Obj06434 *)p)->f3C, 0, 9);
        func_02041B6C(5);
        func_021D4244((int *)p, (int)func_021D51D4, 0x6ba);
    }
}

/*
 * function: func_021D4930
 * address: 0x021D4930
 * packet: pkt_ov120_021D4930
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_02039338 0x02039338 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4864 0x021D4864 thumb ov120
 *   func_021D48F0 0x021D48F0 thumb ov120
 */
#include "../include/Obj05342.h"
typedef unsigned char u8;
extern int func_021D7AF4(char *p);
typedef unsigned short u16;
extern u16 func_02039338(void);
extern int func_02039ACC(void);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4864(u8 *p);
extern void func_021D48F0(int *a);
void func_021D4930(u8 *a)
{
    if (func_021D7AF4((char *)(((struct Obj05342 *)a)->f40)) != 0) {
        if (((struct Obj05342 *)a)->f14 > 0) {
            ((struct Obj05342 *)a)->f14 = ((struct Obj05342 *)a)->f14 - 1;
            return;
        }
        if (func_02039338() != 0) {
            if (func_02039ACC() != 0) {
                ((struct Obj05342 *)a)->f14 = 0xb4;
                func_021D4244((int *)a, (int)((void (*)(int))func_021D4864), 0x33f);
                return;
            }
        } else {
            ((struct Obj05342 *)a)->f14 = 0xb4;
            func_021D4244((int *)a, (int)func_021D48F0, 0x344);
        }
    }
}

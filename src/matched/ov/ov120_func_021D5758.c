/*
 * function: func_021D5758
 * address: 0x021D5758
 * packet: pkt_ov120_021D5758
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 */
#include "../include/Obj05345.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_021D7AF4(char *p);
extern void func_021D79F4(u8 *p, u16 n);
extern u32 func_021D6988(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *p, u32 v);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D5AD4(u8 *p);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
void func_021D5758(u8 *p)
{
    if (func_021D7AF4(((struct Obj05345 *)p)->f40)) {
        if (--((struct Obj05345 *)p)->f14 <= 0) {
            func_021D79F4(((struct Obj05345 *)p)->f40, 0x20);
            TOUCHBAR_SetAllButtonsVisible((u8 *)func_021D6988(((struct Obj05345 *)p)->f3C), 1);
            func_021D4244((int *)p, (int)func_021D5AD4, 0x7c7);
            if (func_020355C4() == 0)
                func_021D69F4(((struct Obj05345 *)p)->f3C, 0, ((struct Obj05345 *)p)->f15C);
        }
    }
}

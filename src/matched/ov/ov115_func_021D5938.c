/*
 * function: WIFILOGIN_DISP_SetupScreen
 * address: 0x021D5938
 * packet: pkt_ov115_021D5938
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj22601.h"
typedef unsigned char u8;
extern void func_0207D63C(void *, int, int, int, int);
void WIFILOGIN_DISP_SetupScreen(u8 *p) {
    switch (((struct Obj22601 *)p)->f8) {
    case 1:
        func_0207D63C((void *)0x04000050, 4, 3, 6, 16);
        func_0207D63C((void *)0x04001050, 8, 21, 6, 16);
        break;
    case 0:
        func_0207D63C((void *)0x04000050, 1, 8, 8, 16);
        break;
    }
}

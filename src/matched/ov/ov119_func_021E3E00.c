/*
 * function: func_021E3E00
 * address: 0x021E3E00
 * packet: pkt_ov119_021E3E00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E3DBC 0x021E3DBC thumb ov119
 *   func_021E3D88 0x021E3D88 thumb ov119
 */
#include "../include/Obj10378.h"
extern void func_021E3DBC(char *, void *, char *);
extern void func_021E3D88(char *, int, char *);
int func_021E3E00(char *p, int i)
{
    while (i < ((struct Obj10378 *)p)->f630 + 1) {
        if (i == ((struct Obj10378 *)p)->f630) {
            func_021E3DBC(p, ((struct Obj10378 *)p)->f838, p + 0x2E0);
            return 1;
        }
        func_021E3D88(p, i, p + 0x10 + i * 30);
        break;
    }
    return 0;
}

/*
 * function: func_021DD1D4
 * address: 0x021DD1D4
 * packet: pkt_ov183_021DD1D4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x021DD226
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj00050.h"
#include "../include/Obj06598.h"
#include "../include/Obj10731.h"
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
void func_021DD1D4(char *p, char *q)
{
    int i;
    char *slot;
    if (((struct Obj00050 *)p)->fE4) {
        for (i = 0; i < 2; i++) {
            slot = p + i * 4;
            if (((struct Obj10731 *)slot)->f28) {
                func_021FC734(((struct Obj10731 *)slot)->f28);
                *(int *)&((struct Obj10731 *)slot)->f28 = 0;
            }
        }
        func_020409B4(4);
        func_021FBDA4(((struct Obj06598 *)q)->f10, 30);
        if (((struct Obj00050 *)p)->f18) {
            func_021FD15C(((struct Obj00050 *)p)->f18, ((struct Obj06598 *)q)->f10);
            *(int *)&((struct Obj00050 *)p)->f18 = 0;
        }
        ((struct Obj00050 *)p)->fE4 = 0;
    }
}

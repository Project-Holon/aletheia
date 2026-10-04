/*
 * function: func_021DEB74
 * address: 0x021DEB74
 * packet: pkt_ov137_021DEB74
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj02496.h"
#include "../include/Obj23746.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DCBC4(void *, int, void *, int);
int func_021DEB74(u8 *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (((struct Obj02496 *)p)->f14 == 0) {
        buf[1] = 0; buf[0] = 0;
        if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
        return 0;
    }
    i = 1;
    mask = ((struct Obj23746 *)(*(u8 * *)&((struct Obj02496 *)p)->fDC))->f42;
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= ((struct Obj02496 *)p)->f14) {
                buf[1] = i; buf[0] = ((struct Obj02496 *)p)->f14;
                if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
                break;
            }
            count++;
        }
    }
    if (((struct Obj02496 *)p)->f14 >= ((struct Obj02496 *)p)->f30) ((struct Obj02496 *)p)->f0 = 7;
    return 0;
}

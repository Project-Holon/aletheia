/*
 * function: func_021DDDE8
 * address: 0x021DDDE8
 * packet: pkt_ov183_021DDDE8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE12C 0x021DE12C thumb ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj06603.h"
#include "../include/Obj10733.h"
#include "../include/Obj10734.h"
typedef unsigned char  u8;
extern void func_021DE12C(char *p);
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
void func_021DDDE8(char *p, char *q)
{
    int i;
    char *slot;
    func_021DE12C(p + 8);
    for (i = 0; i < 16; i++) {
        slot = p + i * 4;
        if (((struct Obj10734 *)slot)->f34) {
            func_021FC734(((struct Obj10734 *)slot)->f34);
            *(int *)&((struct Obj10734 *)slot)->f34 = 0;
        }
    }
    func_021FBDA4(((struct Obj06603 *)q)->f8, 10);
    if (((struct Obj10733 *)p)->f1C) {
        func_021FD15C(((struct Obj10733 *)p)->f1C, ((struct Obj06603 *)q)->f8);
        *(int *)&((struct Obj10733 *)p)->f1C = 0;
    }
}

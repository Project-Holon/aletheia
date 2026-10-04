/*
 * function: func_021DE780
 * address: 0x021DE780
 * packet: pkt_ov183_021DE780
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj08312.h"
#include "../include/Obj10742.h"
#include "../include/Obj10743.h"
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
void func_021DE780(char *p, char *q)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10743 *)slot)->f1C != 0) {
            func_021FC734(((struct Obj10743 *)slot)->f1C);
            ((struct Obj10743 *)slot)->f1C = 0;
        }
    }
    func_021FBDA4(((struct Obj08312 *)q)->f8, 17);
    if (((struct Obj10742 *)p)->f8 != 0) {
        func_021FD15C(((struct Obj10742 *)p)->f8, ((struct Obj08312 *)q)->f8);
        ((struct Obj10742 *)p)->f8 = 0;
    }
}

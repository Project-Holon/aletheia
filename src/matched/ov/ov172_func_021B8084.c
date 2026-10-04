/*
 * function: func_021B8084
 * address:  0x021B8084
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Chooses the +8 state from the +0x174 code and latches +0x178.
 *
 * symbols:
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03853.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0203A5E4(u32 key);
extern int func_0203CEAC(int a);

void func_021B8084(void *a, char *q)
{
    if (((struct Obj03853 *)q)->f4 <= 1) {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 0xc;
            func_0203A5E4(0x2000);
        } else {
            func_0203CEAC(0);
            ((struct Obj03853 *)q)->f8 = 0xb;
        }
    } else {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 9;
        } else {
            ((struct Obj03853 *)q)->f8 = 8;
        }
    }
    ((struct Obj03853 *)q)->f178 = 1;
}

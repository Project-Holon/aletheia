/*
 * function: func_021BE040
 * address: 0x021BE040
 * packet: pkt_ov217_021BE040
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE4DC 0x021BE4DC thumb ov217
 *   func_021BEF30 0x021BEF30 thumb ov217
 *   func_021BE4E0 0x021BE4E0 thumb ov217
 *   func_021BEFC0 0x021BEFC0 thumb ov217
 *   func_021BE448 0x021BE448 thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj06712.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BE4DC(void *);
extern void func_021BEF30(char *);
extern void func_021BE4E0(void *);
extern void func_021BEFC0(u8 *, u32);
extern void func_021BE448(void *);
void func_021BE040(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BEF30((char *)p);
        func_021BE4E0(p);
        break;
    case 1:
        if (((struct Obj06712 *)p)->f28 % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            func_021BEFC0(p, index);
        }
        if (p[764] <= p[765]) func_021BE448(p);
        break;
    }
}

/*
 * function: func_021DFFE0
 * address:  0x021DFFE0
 * packet:   pkt_ov119_021DFFE0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021DFD7C  0x021DFD7C  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E0008  0x021E0008  thumb  ov119
 */
#include "../include/Obj22753.h"

extern void func_021DFD7C(void *);
extern void func_021D8E84(void *, int);
extern void func_021E0008(char *p);

void func_021DFFE0(char *p)
{
    if (((struct Obj22753 *)p)->fF2C >= 0x10e) {
        func_021DFD7C(p);
        func_021D8E84(p, (int)func_021E0008);
    }
}

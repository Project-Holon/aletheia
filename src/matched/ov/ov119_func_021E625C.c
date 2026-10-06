/*
 * function: func_021E625C
 * address: 0x021E625C
 * packet: pkt_ov119_021E625C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 */
#include "../include/Obj13925.h"
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);

void func_021E625C(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            func_0204B3B4((struct Obj *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct Obj13925 *)q)->f10) {
        func_021B6284((unsigned int *)q);
        ((struct Obj13925 *)q)->f10 = 0;
    }
}

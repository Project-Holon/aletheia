/*
 * function: func_021E3BB0
 * address: 0x021E3BB0
 * packet: pkt_ov119_021E3BB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */
#include "../include/Obj10377.h"
extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
void func_021E3BB0(char *p)
{
    int i;
    int j;
    int component;
    int shift;
    char *q;
    for (i = 0; i < 16; i++) {
        q = p + i * 2;
        ((struct Obj10377 *)q)->f1154 = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (((struct Obj10377 *)q)->f1134 >> shift) & 31;
            if (component)
                component--;
            ((struct Obj10377 *)q)->f1154 |= (unsigned short)((component & 31) << shift);
        }
    }
    func_0207FA0C();
    func_0207FA40(p + 0x1154, 0x2000, 32);
    func_0207FADC();
}

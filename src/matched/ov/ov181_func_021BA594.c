/*
 * function: func_021BA594
 * address: 0x021BA594
 * packet: pkt_ov181_021BA594
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021BA4AC 0x021BA4AC thumb ov181
 */
#include "../include/Obj01071.h"
#include "../include/Obj08305.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_021BA4AC(char *, unsigned char *, void *, int);
void func_021BA594(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (((struct Obj01071 *)q)->f4 < 0x100) {
        s = func_02045770(((struct Obj08305 *)p)->f2BC);
        y = ((struct Obj01071 *)q)->f4;
        ((struct Obj08305 *)p)->f2CF |= 1;
    } else {
        s = func_02045770(((struct Obj08305 *)p)->f2C4);
        y = ((struct Obj01071 *)q)->f4 - 0x100;
        ((struct Obj08305 *)p)->f2CF |= 2;
    }
    func_021BA4AC(p, q, s, y);
}

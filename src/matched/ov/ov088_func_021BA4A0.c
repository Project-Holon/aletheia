/*
 * function: func_021BA4A0
 * address:  0x021BA4A0
 * packet:   pkt_ov088_021BA4A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EB04  0x0202EB04  thumb
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_021BB858  0x021BB858  thumb  ov088
 */
#include "../include/Obj01228.h"

struct CodeIn;
extern void func_0202EB04(struct CodeIn *p);
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern int func_021BB840(char *p, int y);
extern void func_021BB810(void *, int, int, int);
extern void func_021BB858(char *p, int d);

int func_021BA4A0(char *p)
{
    if (((struct Obj01228 *)p)->f134 == 3) {
        ((struct Obj01228 *)p)->f134 = 0;
        ((struct Obj01228 *)p)->f138 = 0;
        func_0202EB04((struct CodeIn *)(((struct Obj01228 *)p)->f11C));
        func_021BB810(p, *(unsigned char *)(p + ((struct Obj01228 *)p)->f128 + 0x120),
                      func_021BB840(p, ((struct Obj01228 *)p)->f12F), 2);
        return 5;
    }
    ((struct Obj01228 *)p)->f130 += ((struct Obj01228 *)p)->f138;
    if (((struct Obj01228 *)p)->f130 < 0)
        ((struct Obj01228 *)p)->f130 += 0x200;
    else if (((struct Obj01228 *)p)->f130 >= 0x200)
        ((struct Obj01228 *)p)->f130 -= 0x200;
    func_02041EE4(1, 3, ((struct Obj01228 *)p)->f130);
    func_02041EE4(2, 3, ((struct Obj01228 *)p)->f130);
    func_021BB858(p, -((struct Obj01228 *)p)->f138);
    ((struct Obj01228 *)p)->f134 = ((struct Obj01228 *)p)->f134 + 1;
    return 6;
}

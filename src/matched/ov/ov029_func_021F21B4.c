/*
 * function: func_021F21B4
 * address:  0x021F21B4
 * packet:   pkt_ov029_021F21B4
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F1060  0x021F1060  thumb  ov029
 *   func_021F0300  0x021F0300  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef unsigned char  u8;
extern int func_021F1060(u8 *p);
extern void func_021F0300(u8 *p);
extern void func_021EFEF8(char *p, void (*f)(void), int line);
extern void func_021F2180(char *p);

void func_021F21B4(char *p)
{
    void (*f)(int);

    if (func_021F1060((u8 *)p) == 0) {
        f = *(void (**)(int))(p + 0x1fc);
        if (f)
            f(*(int *)&((struct Obj00042 *)p)->f200);
        *(int *)&((struct Obj00042 *)p)->f1FC = 0;
        *(int *)&((struct Obj00042 *)p)->f200 = 0;
        return;
    }
    func_021F0300((u8 *)p);
    func_021EFEF8(p, (void *)func_021F2180, 0xF92);
}

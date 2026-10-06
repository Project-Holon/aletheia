/*
 * function: func_021F29D8
 * address:  0x021F29D8
 * packet:   pkt_ov029_021F29D8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = func_021F2EEC" tails are cross-jumped.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_020061E4  0x020061E4  thumb
 *   func_021F3098  0x021F3098  thumb  ov029
 *   func_021F3118  0x021F3118  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F2EEC  0x021F2EEC  thumb  ov029
 *   func_021F2CD4  0x021F2CD4  thumb  ov029
 */
#include "../include/Obj00042.h"

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
extern int func_021F05B4(unsigned char *p);
extern void func_020061E4(unsigned int id);
extern void func_021F3098(u8 *p);
extern void func_021F3118(void *p);
extern void func_021EFEF8(char *p, void (*f)(void), int a);
extern int func_021F2EEC(char *p, int k);
extern void func_021F2CD4(void);

int func_021F29D8(char *p, int a)
{
    int r = 0;
    void *b;

    func_02012138((const struct Ctx *)*(int *)&((struct Obj00042 *)p)->f1C);
    b = func_0201210C(((struct Obj00042 *)p)->f1C);
    if (a == 0 || b == 0)
        return 0;

    switch (((struct Obj00042 *)p)->f214) {
    case 1:
    case 6:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x54E);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
            func_021F3098((u8 *)p);
            func_021EFEF8(p, (void (*)(void))func_021F3118, 0x1238);
        }
        break;
    case 5:
        func_020061E4(0x54E);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 12:
    case 13:
        func_020061E4(0x628);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 7:
    case 11:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x628);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
        }
        break;
    }

    if (r != 0) {
        ((struct Obj00042 *)p)->f218 = ((struct Obj00042 *)p)->f214;
        func_021EFEF8(p, func_021F2CD4, 0x1256);
    }
    ((struct Obj00042 *)p)->f214 = 0;
    return r;
}

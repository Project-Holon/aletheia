/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov035_021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFEC0 0x021EFEC0 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F0678    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_021EFF78 0x021EFF78 thumb ov035
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_021EFF3C 0x021EFF3C thumb ov035
 */
#include "../include/Obj02409.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021F0678[];
struct Ctx;
extern u32 func_02012138(const struct Ctx *);
extern void func_021EFF78(char *p, int a1);
extern int func_0202EB44(void);
extern u32 func_0201214C(const struct Ctx *);
extern void func_021EFF3C(char *p, int a1);

void *func_021EFEC0(int a0, int a1, int a2)
{
    char *p = (char *)func_02030734(a2, 0x50, 1, d_021F0678, 0x12D);
    ((struct Obj02409 *)p)->f4 = a1;
    ((struct Obj02409 *)p)->f8 = func_02012138((const struct Ctx *)a1);
    *(int *)&((struct Obj02409 *)p)->fC = a0;
    ((struct Obj02409 *)p)->f0 = a2;
    func_021EFF78(p, a2);
    if (func_0202EB44() == 0)
        ((struct Obj02409 *)p)->f48 = 2;
    else if (func_0201214C((const struct Ctx *)a1) == 1)
        ((struct Obj02409 *)p)->f48 = 1;
    else
        ((struct Obj02409 *)p)->f48 = 0;
    func_021EFF3C(p, 1);
    return p;
}

/*
 * function: func_021DDA50
 * address:  0x021DDA50
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8980  0x021D8980  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DD09C  0x021DD09C  thumb  ov119
 *   func_021DEBD4  0x021DEBD4  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E12F8  0x021E12F8  thumb  ov119
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202208C  0x0202208C  thumb
 */
#include "../include/Obj00001.h"

typedef unsigned short u16;

extern void func_021D8980(char *p);
extern void func_021D8E84(void *p, int v);
extern void func_021DD09C(char *p);
extern void func_021DEBD4(void *p);
extern void func_021E1098(char *p);
extern void func_021E12F8(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

void func_021DDA50(void *p)
{
    int v;

    if (func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C)) == 0)
        return;
    v = func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)&((struct Obj00001 *)p)->f64C = 0;
    switch (v) {
    case 0:
        func_0202208C((void *)3, 0, 0, 0, 6, 1, ((struct Obj00001 *)p)->f5F4);
        func_021D8E84(p, 0x021DE519);
        return;
    case 1:
        func_021D8980(p);
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p, 0x021DEA25);
        return;
    }
}

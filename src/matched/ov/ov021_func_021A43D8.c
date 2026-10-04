/*
 * function: func_021A43D8
 * address:  0x021A43D8
 * packet:   pkt_ov021_021A43D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A428C  0x021A428C  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 */
#include "../include/Obj00656.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern void *func_02188C80(void *p);
extern int func_0202E83C(void *a0);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_021A428C(u8 *o, int unused, int c, int flag, int kind);
extern void func_02164208(int, u32 *, int);

void func_021A43D8(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        ((struct Obj00656 *)p)->f18 = 0x546;
        ((struct Obj00656 *)p)->f1A = 0;
        return;
    }
    a = func_021A3960(((struct Obj00656 *)p)->fC);
    r = func_0202E83C(func_02188C80((void *)(((struct Obj00656 *)p)->f10)));
    func_0216D88C(a, (struct VecFx32 *)buf);
    if (func_021A428C(p, k, (int)buf, 0, r) == 0) {
        func_02164208(dir, buf, 0x10000);
        func_021A428C(p, k, (int)buf, 1, r);
    }
}

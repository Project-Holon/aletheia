/*
 * function: func_021737A4
 * address:  0x021737A4
 * packet:   pkt_ov012_021737A4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02034714  0x02034714  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   func_020123C4  0x020123C4  thumb
 *   func_02173840  0x02173840  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217B840  0x0217B840  thumb  ov019
 *   func_0217B75C  0x0217B75C  thumb  ov019
 *   func_0217B264  0x0217B264  thumb  ov019
 */
#include "../include/Obj00610.h"
#include "../include/Obj19233.h"
#include "../include/Obj19234.h"

typedef unsigned char u8;

extern unsigned int func_02026454(void *obj);
extern unsigned int func_02026474(void *obj);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Ctx;
extern void *func_02188C80(void *p);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_020123C4(void *v);
extern int func_02173840(u8 *p);
extern int func_02174268(u8 *p);
extern int func_0217B840(char *base, int r1);
extern void func_0217B75C(char *p);
extern void func_0217B264(u8 *w, void *sys, void *q);

void func_021737A4(void *a, int b)
{
    u8 *r4;
    u8 s;

    if (func_02026454(a) != 3) {
        return;
    }
    r4 = (u8 *)func_02026474(a);
    if (r4 == 0) {
        func_02034714((void *)0x02175610, 0, (void *)0x02175610);
    }
    if (func_0201212C(func_02188C80((void *)b)) == 1) {
        return;
    }
    if (func_020123C4((void *)((struct Obj19233 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->fC) == 1) {
        return;
    }
    if (func_02173840(r4) != 1) {
        return;
    }
    s = r4[0x2830];
    if (s >= 4 && s <= 0x17) {
        if (func_02174268(r4) != 0) {
            return;
        }
        func_0217B840((char *)r4, b);
        return;
    }
    if (s != 0 && s != 1) {
        return;
    }
    if (func_02174268(r4) != 0) {
        return;
    }
    func_0217B75C((char *)r4);
    func_0217B840((char *)r4, b);
    func_0217B264(r4, (void *)(((struct Obj19234 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->f8), (void *)b);
}

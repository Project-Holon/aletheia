/*
 * function: func_021BCA14
 * address:  0x021BCA14
 * packet:   pkt_ov099_021BCA14
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020200CC  0x020200CC  thumb
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *
 * Twin of func_021BC958 (+0x22 byte, +0x134e halfword, +0x238 out slot).
 */
#include "../include/Obj01916.h"
#include "../include/Obj22030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef signed int     s32;
struct Obj;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern s32 func_020200CC(struct Obj *o);
extern void func_021BA8EC(char *p);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *p);

int func_021BCA14(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01916 *)p)->f1B8;
    if (((struct Obj01916 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01916 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj01916 *)p)->f1AC);
            ((struct Obj01916 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj01916 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01916 *)p)->f134E = r;
        ((struct Obj22030 *)(*(char * *)&((struct Obj01916 *)p)->f248))->f22 = r;
    }
    ((struct Obj01916 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01916 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01916 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj01916 *)p)->fBC), 0, (u16 *)(p + 0x238));
    func_0201F868((void *)(((struct Obj01916 *)p)->fB8));
    return v;
}

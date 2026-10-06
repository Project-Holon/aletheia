/*
 * function: func_02189614
 * address:  0x02189614
 * packet:   pkt_ov021_02189614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012B38  0x02012B38  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0218DC74  0x0218DC74  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02012844  0x02012844  thumb
 *   func_021939C0  0x021939C0  thumb  ov021
 *   func_02193ABC  0x02193ABC  thumb  ov021
 *   func_02012964  0x02012964  thumb
 *   func_02193AFC  0x02193AFC  thumb  ov021
 *
 */
#include "../include/Obj00571.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub02014444Obj;
extern void *func_02012B38(const struct BigObj *p);
extern int func_02013DD0(int v);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u8 *func_020127C4(void *p);
extern u8 *func_020127D0(u8 *o, u32 idx);
extern int func_0218DC74(u32 a, u32 b, u32 c);
extern void *func_0218DC70(u8 *p);
extern u32 func_02012844(const struct BigObj *p);
extern void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
extern void func_02193ABC(char *p, int a, int b);
extern u32 func_02012964(const struct BigObj *p);
extern void func_02193AFC(u8 *p, u32 v);

void func_02189614(void *p, char *q, u16 id)
{
    void *t;
    int k;
    void *m;
    void *a;

    t = func_02012B38(p);
    if (func_02013DD0(((struct Obj00571 *)q)->fD0) != 0) {
        k = func_0201444C(t);
        if (k == 0)
            m = func_020127C4(((struct Obj00571 *)q)->f8);
        else
            m = func_020127D0(((struct Obj00571 *)q)->f8, 0);
        func_0218DC74((u32)(((struct Obj00571 *)q)->f48), (u32)m, k);
        a = func_0218DC70(((struct Obj00571 *)q)->f48);
        func_021939C0(a, (void *)func_02012844(p), k, ((struct Obj00571 *)q)->f0);
        func_02193ABC(a, *(int *)&((struct Obj00571 *)q)->f10, ((struct Obj00571 *)q)->f0);
        func_02193AFC(a, func_02012964(((struct Obj00571 *)q)->f8));
    }
}

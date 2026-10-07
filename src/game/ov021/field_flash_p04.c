/*
 * file:     field_flash_p04.c
 * unit:     yes
 * function: func_021C71D4, func_021C7220, func_021C7260
 * address:  0x021C71D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021C7418  0x021C7418  thumb  ov021
 *   func_021C748C  0x021C748C  thumb  ov021
 */
#include "../../matched/include/Obj05086.h"
#include "../../matched/include/Obj05087.h"
#include "../../matched/include/Obj05088.h"

struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021C6C70(u32 heap, u32 n, void *cb);
extern u32 func_021C6CCC(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *a);
extern void func_021C7418(void);
extern void func_021C748C(void);
void *func_021C71D4(u32 a, u32 b, u32 c);
void *func_021C7220(u32 a, u16 b, int c, u32 d);
void *func_021C7260(u32 a, u16 b, int c);


/*
 * Addresses are Black-image addresses.
 */
void *func_021C71D4(u32 a, u32 b, u32 c)
{
    u32 heap = func_02188C84((u8 *)a);
    void *x = func_02188CB4((void *)a);
    void *r = func_021C6C70(heap, 0x10, (void *)func_021C7418);
    u8 *e = (u8 *)func_021C6CCC(r);
    void *t;

    ((struct Obj05086 *)e)->f0 = a;
    t = func_021A3074((void *)x);
    ((struct Obj05086 *)e)->f4 = t;
    ((struct Obj05086 *)e)->f8 = 0;
    ((struct Obj05086 *)e)->fA = b;
    e[12] = c;
    ((struct Obj05086 *)e)->fE = func_0216D5F8(t);
    return r;
}


void *func_021C7220(u32 a, u16 b, int c, u32 d)
{
    void *o;
    u8 *p;

    o = func_021C6C70(func_02188C84((u8 *)a), 0x10, (void *)func_021C7418);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05087 *)p)->f0 = a;
    ((struct Obj05087 *)p)->f4 = d;
    ((struct Obj05087 *)p)->f8 = 0;
    ((struct Obj05087 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05087 *)p)->fE = func_0216D5F8((void *)d);
    return o;
}


void *func_021C7260(u32 a, u16 b, int c)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;
    void *t;

    h = func_02188C84((u8 *)a);
    q = func_02188CB4((void *)a);
    o = func_021C6C70(h, 0x10, (void *)func_021C748C);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05088 *)p)->f0 = a;
    t = func_021A3074((void *)q);
    ((struct Obj05088 *)p)->f4 = t;
    ((struct Obj05088 *)p)->f8 = 0;
    ((struct Obj05088 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05088 *)p)->fE = func_0216D5F8(t);
    return o;
}

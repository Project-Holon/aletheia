/*
 * function: func_021B7128
 * address:  0x021B7128
 * packet:   pkt_ov070_021B7128
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   func_020213E0  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021B7688  0x021B7688  thumb  ov070
 *   func_021B795C  0x021B795C  thumb  ov070
 *   func_021B832C  0x021B832C  thumb  ov070
 *   func_021BADB8  0x021BADB8  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B6EF8  0x021B6EF8  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x51C - 0x014];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x844 - 0x6AC];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    unsigned int f84C;
} Obj;

extern int func_021B61B8(Obj *o);
extern u16 *func_021B616C(Obj *o, int k);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern u32 func_020213E0(u16 v);
extern unsigned int func_0202136C(u16 v);
extern void func_021B6100(Obj *o, void *fn);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern void func_021B61F4(Obj *o, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021BB3F4(Obj *o, int v);
extern void func_021BB580(Obj *o, int v);
extern void func_021B7688(struct Obj *o);
extern void func_021B795C(struct Obj *o);
extern void func_021B832C(Obj *o);
extern void func_021BADB8(Obj *o, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021B6EF8(u8 *p);

void func_021B7128(Obj *o)
{
    u16 *p;
    int s;

    p = func_021B616C(o, func_021B61B8(o));
    o->f84C = 0;
    if (p != 0)
        o->f84C = *p;
    s = o->f010;
    if (s == 2) {
        if (func_02020FE4(o->f84C, 3, o->f544) == 0 && func_020213E0(o->f84C) == 1) {
            if (func_0202136C(o->f84C) != 0)
                o->f844 = 0x12;
            else
                o->f844 = 3;
            func_021B6100(o, 0);
            return;
        }
        func_02045CAC(o->f51C, 0x2F, o->f524);
        func_021B61F4(o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB3F4(o, 0);
        func_021BB580(o, 0);
        func_021B6100(o, (void *)func_021B7688);
    } else if (s == 5) {
        o->f844 = 1;
        func_021B6100(o, 0);
    } else if (s == 4) {
        func_021B6100(o, (void *)func_021B795C);
    } else {
        func_021B832C(o);
        func_021BADB8(o, o->f84C);
        func_021BADAC(o);
        func_0204B92C(o->f6A8, 0);
        func_021B6100(o, (void *)func_021B6EF8);
    }
}

/*
 * function: func_021B795C
 * address:  0x021B795C
 * packet:   pkt_ov070_021B795C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   func_02020FE4  0x02020FE4  thumb
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7C88  0x021B7C88  thumb  ov070
 *   func_021BB08C  0x021BB08C  thumb  ov070
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_021B7B08  0x021B7B08  thumb  ov070
 *   func_021B7D9C  0x021B7D9C  thumb  ov070
 *   func_021B7A7C  0x021B7A7C  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x7F4 - 0x6AC];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

typedef unsigned int   u32;
struct WordSet;
extern void func_0204B92C(struct Obj *p, u32 v);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
extern void func_021BB3F4(Obj *o, int v);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern void func_021B61F4(Obj *o, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021BB580(Obj *o, int v);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B7C88();
extern void func_021BB08C(Obj *o);
extern int func_021B61B8(Obj *o);
extern u16 *func_021B616C(Obj *o, int k);
extern void func_021B7B08(struct Obj *o);
extern void func_021B7D9C(Obj *o, int v);
extern void func_021B7A7C();

void func_021B795C(Obj *o)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C(o->f6A8, 0);
    a = func_02020FE4(o->f84C, 0, o->f544);
    b = func_02020FE4(o->f84C, 3, o->f544);
    if (a == 0 || b != 0) {
        func_021BB3F4(o, 0);
        func_02045CAC(o->f51C, 0x4D, o->f524);
        func_021B61F4(o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB580(o, 0);
        func_021B6100(o, (void *)func_021B7C88);
        return;
    }
    o->f7F4 = 1;
    func_021BB08C(o);
    func_021BB3F4(o, 0);
    if (func_021B616C(o, func_021B61B8(o))[1] == 1) {
        func_021B6100(o, (void *)func_021B7B08);
        return;
    }
    func_021B7D9C(o, 2);
    func_02045CAC(o->f51C, 0x4E, o->f524);
    func_021B61F4(o, 0, o->f84C);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100(o, (void *)func_021B7A7C);
}

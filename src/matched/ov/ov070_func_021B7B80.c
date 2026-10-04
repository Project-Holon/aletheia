/*
 * function: func_021B7B80
 * address:  0x021B7B80
 * packet:   pkt_ov070_021B7B80
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BB1AC  0x021BB1AC  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BAFC4  0x021BAFC4  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7C88  0x021B7C88  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B7CD0  0x021B7CD0  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    void *f000;
    unsigned char pad004[0x51C - 0x004];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x77C - 0x546];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern int func_021BADF0(int p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
struct WordSet;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BB1AC(Obj *o);
extern int func_021B619C(int a, int b, unsigned int id);
extern void func_021B7D20(struct Obj *o, int x);
extern void *func_02012F08(int *p);
extern void func_0200C278(unsigned int a, unsigned int b);
extern void func_020061E4(unsigned int id);
extern void func_021BAFC4(Obj *o);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern void func_021B6204(Obj *o, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021B6100(char *p, int k);
extern void func_021B7C88();
extern u8 func_020355C4(void);
extern void func_021B80C4(Obj *o, int v);
extern void func_021B7CD0(struct Obj *o);

void func_021B7B80(Obj *o)
{
    int r;
    int v;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC(o);
    switch (r) {
    case 0:
        v = func_021B619C(o->f84C, o->f7F4, o->f544);
        func_021B7D20(o, o->f7F4);
        func_0200C278((unsigned int)func_02012F08(o->f000), v);
        func_020061E4(0x655);
        func_021BAFC4(o);
        func_02045CAC(o->f51C, 0x50, o->f524);
        func_021B6204(o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, v, 7, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        break;
    case 1:
        func_021B80C4(o, func_020355C4() == 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        break;
    }
}

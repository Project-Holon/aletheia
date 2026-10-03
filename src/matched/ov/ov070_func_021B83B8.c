/*
 * function: func_021B83B8
 * address:  0x021B83B8
 * packet:   pkt_ov070_021B83B8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of func_021B7250's key handling.
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B8CE4  0x021B8CE4  thumb  ov070
 *   func_021B8F90  0x021B8F90  thumb  ov070
 *   func_021B8080  0x021B8080  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8EA8  0x021B8EA8  thumb  ov070
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_021B81B8  0x021B81B8  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B7250  0x021B7250  thumb  ov070
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_021B8B7C  0x021B8B7C  thumb  ov070
 *   func_021B8134  0x021B8134  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B6288  0x021B6288  thumb  ov070
 *   func_021B80BC  0x021B80BC  thumb  ov070
 *   d_021BB984     0x021BB984  data  a4
 */

typedef unsigned int u32;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x4F8 - 0x14];
    void (*f4F8)(Obj *o);
    unsigned char pad4FC[0x80C - 0x4FC];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    unsigned char pad81C[0x844 - 0x81C];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
};

typedef struct TabTbl {
    int v[5];
} TabTbl;

extern const TabTbl d_021BB984;

extern int func_021B61C8(Obj *o);
typedef unsigned char  u8;
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B8CE4(Obj *o, int u, int a, void *fn);
extern void func_021B8F90(void *o);
extern void func_021B8080(Obj *o);
extern void func_021B6138(Obj *o);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B8EA8(int p);
extern int func_021B811C(Obj *o);
extern void func_021B81B8(Obj *o);
extern void func_021B8C1C(Obj *o, int a, void *fn);
extern void func_020355D8(u8 v);
extern void func_021B7250(Obj *o);
extern int func_021B61B8(Obj *o);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B9850(Obj *o);
extern void func_021B8B7C(int p);
extern int func_021B8134(struct Obj *o, int k);
extern void func_020061E4(unsigned int se);
extern void func_021B6288(struct Obj *o, int a, int b);
extern void func_021B80BC(void *p);

void func_021B83B8(u32 idx, int flag, Obj *o)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = func_021B61C8(o);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (o->f80C != t.v[idx]) {
            tab = t.v[idx];
            func_021B80C4(o, 0);
        }
    } else if (idx == 5) {
        func_021B80C4(o, 0);
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_021B8CE4(o, v, 0, (void *)func_021B8F90);
        return;
    } else if (idx == 6) {
        func_021B80C4(o, 0);
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_021B8CE4(o, v, 1, (void *)func_021B8F90);
        return;
    } else if (idx == 7) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8(o) > 1) {
            func_021B8080(o);
            func_021B80C4(o, 0);
            o->f818 = 0xFFFF;
            func_021B6138(o);
            func_021B6100(o, (void *)func_021B8EA8);
        }
    } else if (idx == 8) {
        if (func_021B811C(o) == 1) {
            func_021B81B8(o);
            func_021B80C4(o, 0);
            o->f818 = 0xFFFF;
            func_021B6138(o);
        }
    } else if (idx == 9) {
        if (o->f010 != 2) {
            o->f844 = 0;
            o->f84C = 0;
            func_021B8C1C(o, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        o->f844 = 1;
        o->f84C = 0;
        func_021B8C1C(o, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (o->f4F8 != func_021B7250)
            return;
        saved = o->f810;
        cur = func_021B61B8(o);
        if (func_021B61C8(o) == 0)
            return;
        if (o->f810 != idx - 11) {
            o->f810 = idx - 11;
            if (count <= func_021B61B8(o)) {
                o->f810 = saved;
                return;
            }
        }
        func_021B624C(o, cur, func_021B61B8(o));
        func_021B80C4(o, 0);
        o->f818 = 0xFFFF;
        func_021B6138(o);
        func_021B9850(o);
        func_021B6100(o, (void *)func_021B8B7C);
        return;
    } else if (idx >= 17) {
        if (func_021B811C(o) == 1 && func_021B8134(o, idx - 17) == 1) {
            func_021B80C4(o, 0);
            func_021B6138(o);
        }
    }
    if (tab != -1) {
        v = o->f80C;
        o->f80C = tab;
        func_020061E4(0x7D9);
        func_021B6288(o, v, o->f80C);
        func_021B80BC(o);
        func_021B80C4(o, 0);
        o->f818 = 0xFFFF;
        func_021B6138(o);
    }
}

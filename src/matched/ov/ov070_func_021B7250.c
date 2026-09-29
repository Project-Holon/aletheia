/*
 * function: func_021B7250
 * address:  0x021B7250
 * packet:   pkt_ov070_021B7250
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02051C88  0x02051C88  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_021B8134  0x021B8134  thumb  ov070
 *   func_021B81B8  0x021B81B8  thumb  ov070
 *   func_021B8080  0x021B8080  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8EA8  0x021B8EA8  thumb  ov070
 *   func_021B8B7C  0x021B8B7C  thumb  ov070
 *   func_02082BCC  0x02082BCC  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB5DC  0x021BB5DC  thumb  ov070
 *   func_021B8B0C  0x021B8B0C  thumb  ov070
 *   func_021B6554  0x021B6554  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_021B8CE4  0x021B8CE4  thumb  ov070
 *   func_021B8F90  0x021B8F90  thumb  ov070
 */

typedef struct Obj Obj;

struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x18 - 0x14];
    void *f018;
    unsigned char pad01C[0x20 - 0x1C];
    unsigned char f020[0x4D8];
    void (*f4F8)(Obj *o);
    unsigned char pad4FC[0x50C - 0x4FC];
    void *f50C;
    unsigned char pad510[0x694 - 0x510];
    void *f694;
    unsigned char pad698[0x6A4 - 0x698];
    void *f6A4;
    unsigned char pad6A8[0x80C - 0x6A8];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    int f81C;
    unsigned char pad820[0x844 - 0x820];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
    void *f850;
    unsigned char pad854[0x85C - 0x854];
    int f85C;
};

extern int func_0201C6B4(void *p);
extern int func_02035C38(void);
extern void func_02051C88(void *p);
extern void func_0202EA40(void *p);
extern unsigned int func_021B63F8(Obj *o);
extern void func_021B6138(Obj *o);
extern int func_020355C4(void);
extern unsigned int func_020362DC(void);
extern int func_021B61C8(Obj *o);
extern void func_020061E4(unsigned int se);
extern void func_021B9850(Obj *o);
extern void func_021B80C4(Obj *o, int v);
extern void func_020355D8(int v);
extern void func_021B8C1C(Obj *o, int a, void *fn);
extern int func_021B811C(Obj *o);
extern int func_021B8134(Obj *o, int k);
extern void func_021B81B8(Obj *o);
extern void func_021B8080(Obj *o);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B8EA8();
extern void func_021B8B7C();
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(void *a, void *buf, int idx, int dir);
extern void func_0204B878(void *p, int v);
extern void func_021BB5DC(Obj *o, int mode);
extern void func_021B8B0C(Obj *o);
extern int func_021B6554(Obj *o);
extern void func_021BA6A4(Obj *o);
extern unsigned int func_0203633C(void);
extern void func_021B8CE4(Obj *o, int u, int a, void *fn);
extern void func_021B8F90();

void func_021B7250(Obj *o)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(o->f50C) == 0)
        return;
    if (func_02035C38() == 0)
        o->f85C = 0;
    func_02051C88(o->f694);
    func_0202EA40(o->f850);
    if (o->f4F8 != func_021B7250)
        return;
    if (func_021B63F8(o) != 0) {
        o->f818 = 0xFFFF;
        func_021B6138(o);
        return;
    }
    if (o->f85C == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (func_021B61C8(o) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                func_021B9850(o);
                func_021B80C4(o, 1);
                return;
            }
        } else {
            func_021B80C4(o, 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        o->f844 = 1;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C(o, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (o->f010 == 2)
            return;
        o->f844 = 0;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C(o, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (func_021B811C(o) != 1)
            return;
        if (o->f80C == 4) {
            func_021B8134(o, o->f810);
            func_021B6138(o);
        } else {
            func_021B81B8(o);
        }
        if (func_020355C4() != 1)
            return;
        func_021B9850(o);
        func_021B80C4(o, 1);
        return;
    }
    if ((func_020362DC() & 8) && o->f80C != 2 && o->f80C != 3 && func_021B61C8(o) > 1) {
        func_021B8080(o);
        func_021B80C4(o, 1);
        o->f818 = 0xFFFF;
        func_021B6138(o);
        func_021B6100(o, (void *)func_021B8EA8);
        return;
    }
    if (func_020362DC() & 1) {
        if (func_021B61C8(o) > 0) {
            func_021B6100(o, (void *)func_021B8B7C);
            return;
        }
    } else if (func_020362DC() & 4) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8(o) > 1) {
            func_02082BCC(o->f020, 0, 0x4D8);
            func_02007CC8(o->f018, o->f020, o->f80C, 1);
            func_0204B878(o->f6A4, 2);
            func_021BB5DC(o, 0);
            o->f81C = 1;
            func_021B8B0C(o);
        }
        return;
    } else if (func_021B6554(o) != 0) {
        func_021BA6A4(o);
        func_020061E4(0x548);
        func_021B6138(o);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_020355D8(0);
        func_021B8CE4(o, v, 1, (void *)func_021B8F90);
        return;
    }
    if (func_0203633C() & 0x20) {
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_020355D8(0);
        func_021B8CE4(o, v, 0, (void *)func_021B8F90);
    }
}

/*
 * file:     zukan_detail_graphic_p08.c
 * unit:     yes
 * function: func_021BEE70, func_021BEF9C, func_021BEFA0, func_021BF088, func_021BF1D0, func_021BF280
 * address:  0x021BEE70
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021BF4FC 0x021BF4FC thumb ov208
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BF4C4 0x021BF4C4 thumb ov208
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 *   func_021BF620 0x021BF620 thumb ov208
 */
#include "../../matched/include/Obj00442.h"
#include "../../matched/include/Obj00442.h"

struct Ov208Cur;
struct Obj;
struct Ov208Scene;
struct Ov208Heap;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct S_021BEE70 {
    u8 pad0[0x14];
    u32 f14;
    u32 f18;
};

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S_021BEFA0 {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

extern int func_021BC3B4(int *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_021BDBA0(int p);
extern int func_021BC3A4(int *p);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_0204B3F4(struct Obj *p);
extern void ov208_func_021BF280(void *first, char *q, void *third, int next);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void func_020355D8(u8 v);
extern void func_021BDC48(int p, u32 on);
extern u32 func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
extern void func_021BF63C(void *,char *,void *);
extern void func_021BA7C8(void *);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BF4C4(int unused, char *q, int c, int *tbl);
extern void func_021BA814(void *);
extern void func_021BA64C(char *p, int mode);
extern void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx);
void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key);
void func_021BEF9C(void *p);
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj);
int func_021BF088(void *first,char *p,int key);
void func_021BF1D0(void *first,char *q,void *third);
void func_021BF280(void *first,char *q,void *third,int next);





void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 15:
        break;
    case 10: case 11: case 12: case 13: case 14: case 16: case 17: case 18:
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f14 = 2;
        return;
    case 7: case 8: case 9:
        st->f14 = 1;
        return;
    case 3:
        func_021BDBA0(sc);
        return;
    case 4:
        func_021BDBA0(sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x11, func_021BDC2C((char *)sc));
        func_021BDBA0(sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}




void func_021BEF9C(void *p)
{
}




/*
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = func_021BC3B4(obj);
    res = 0;
    if (st->cur == 6 && func_02035D20(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (func_0204B3F4((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        func_0204B878((struct Obj *)e->h1c, e->f26);
        func_020061E4(0x54a);
        func_020355D8(1);
        func_021BDC48(sc, 0);
    }
    return res;
}


int func_021BF088(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)func_021BC3B4((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=func_0203633C();
        press=func_020362DC();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        func_021BF280(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        func_0204B878(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        func_020061E4(0x54a);
        func_020355D8(0);
        func_021BDC48((int)scene, 0);
    }
    return changed;
}


/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void func_021BF1D0(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    func_021BF4FC(first,(u8 *)q,(int)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {func_021BF63C(first,q,third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    func_021BF4C4((int)first,q,(int)third,(int *)p.arr);
}


void func_021BF280(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            func_021BF4FC(first,(u8 *)q,(int)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        func_021BF63C(first,q,third);((struct Obj00442 *)q)->f98=next;
        func_021BF620(first,(int *)q,third);
    }
}

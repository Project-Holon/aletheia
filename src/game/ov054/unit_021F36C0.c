/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3704, func_021F373C, func_021F37B4, func_021F3874, func_021F38B0, func_021F38E4, func_021F3918
 * address:  0x021F36C0
 * region:   ov054
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
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_0202B914  0x0202B914  thumb
 *   d_021F39A0     0x021F39A0  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021C4DA8 0x021C4DA8 thumb ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0202B93C  0x0202B93C  thumb
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021F393C  0x021F393C  thumb  ov054
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021F394C 0x021F394C data a4
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 */
#include "../../matched/include/Obj20572.h"
#include "../../matched/include/Obj03165.h"

struct Obj;
struct O;
struct Big;
struct Ctx;
struct Rec94;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int w[2];
} O;

typedef struct { int v[2]; } Pair;

typedef signed int     s32;

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void func_021BE310(unsigned a, void *b, int c);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_0202B914(struct Obj *o, u32 v);
extern int *func_021897BC(char *,int);
extern void func_021897A0(unsigned char *,int);
extern int func_021C4DA8(void *a);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048AE8(void *, void *);
extern void func_02048B30(void *, void *);
extern void func_0202B93C(int, void *, void *);
extern int func_021C4DE4(int, int);
extern int func_021F393C(char *, int);
extern void *func_02188C80(void *p);
extern unsigned int func_02012134(unsigned int *p);
extern unsigned int func_0202B57C(void *obj);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021C4D14(int a, int b, int c, int d, int e);
extern void func_021C4DC0(int, int, int, int);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021C4E20(void *);
extern int func_021C4E08(void *,int);
extern unsigned func_02005728(unsigned);
void func_021F36C0(unsigned a);
void func_021F3704(char *a);
void func_021F373C(int a);
void func_021F37B4(O *o, u32 q);
void func_021F3874(char *p);
void func_021F38B0(char *p,int a);
void func_021F38E4(char *p,int a);
void func_021F3918(char *p, int i);
extern char d_021F39A0[];
extern Pair d_021F394C;




void func_021F36C0(unsigned a)
{
    unsigned r5;
    int *p;

    r5 = func_02188C84((u8 *)a);
    func_021BE310(func_02188D2C((int *)a), d_021F39A0, 0);
    p = func_02189764((unsigned char *)a, 0, r5, 0x28);
    func_021F37B4((O *)((struct O *)p), a);
    func_021F38E4((char *)p, a);
    func_0202B914((struct Obj *)p[1], 0x7f);
}



void func_021F3704(char *a) { int i=0; char *p=(char *)func_021897BC(a,0); func_0202B914((struct Obj *)(((struct Obj20572 *)p)->f4),0); func_021F38B0(p,(int)a); for(;i<2;i++) func_021C4DA8((void *)(*(void **)(p+8+4*i))); func_021897A0((unsigned char *)a,0); }




void func_021F373C(int a)
{
    int i;
    char *p;
    void *cam;
    int v[3];
    int w[3];

    p = (char *)(void *)func_021897BC((char *)a, 0);
    cam = (void *)func_0218EC2C(func_02188C58((void *)a));
    func_02048AE8(cam, v);
    func_02048B30(cam, w);
    func_0202B93C(*(int *)(p + 4), v, w);
    for (i = 0; i < 2; i++) {
        int *e = (int *)(p + i * 4);
        if (e[4] > 0) {
            e[4]--;
            if (e[4] <= 0)
                func_021F393C(p, i);
        } else if (func_021C4DE4(e[2], 0x1000)) {
            func_021F3918(p, i);
        }
    }
}




void func_021F37B4(O *o, u32 q)
{
    int i;
    int t8;
    int s0;
    int a;
    int *p;
    int r;

    a = func_02188C84((u8 *)q);
    t8 = func_02188D2C((int *)q);
    o->h0 = a;
    o->f4 = func_0202B57C((void *)func_02012134((unsigned int *)func_02188C80((void *)q)));
    p = func_02048F60(0x7f, 1, a);
    i = 0;
    s0 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    func_021C4DC0(s0, 0x7f, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    p = func_02048F60(0x7f, 2, a);
    r = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 1), 9, p[0] << 12, p[1]);
    func_021C4DC0(r, 0x7f, 4, 10);
    o->fc = r;
    func_020307B0(p);
    for (i = 0; i < 2; i++)
        o->w[i] = 0;
    func_021F3874((char *)o);
}


void func_021F3874(char *p) { Pair t=d_021F394C; int i; for(i=0;i<2;i++){ int *q=func_02048F60(0x7f,t.v[i],((struct Obj03165 *)p)->f0); ((int *)(p+0x18))[i]=q[0]; ((int *)(p+0x20))[i]=q[1]; func_020307B0(q); } }


void func_021F38B0(char *p,int a) { int *q=func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),11); int i; for(i=0;i<2;i++) { int offset=4*i; int v=func_021C4E20(*(void **)(p+8+offset)); *(int *)((char *)q+offset)=v>>12; } }


void func_021F38E4(char *p,int a) { int *q=func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),11); int i; for(i=0;i<2;i++) func_021C4E08(*(void **)(p+8+4*i),(int)((unsigned)q[i]<<12)); }


void func_021F3918(char *p, int i)
{
    ((int *)(p + 0x10))[i] = ((int *)(p + 0x18))[i] +
        func_02005728(((int *)(p + 0x20))[i] - ((int *)(p + 0x18))[i] + 1);
}

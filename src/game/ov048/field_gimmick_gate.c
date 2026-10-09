/*
 * file:     field_gimmick_gate.c
 * unit:     yes
 * function: func_021F36C0, func_021F374C, func_021F376C, func_021F3790, func_021F37A4, func_021F37C4, func_021F37FC, func_021F3818, func_021F3830, func_021F3870, func_021F3880, func_021F38EC, func_021F3908, func_021F392C, func_021F39A8, func_021F39BC, func_021F39E4, func_021F3A50, func_021F3A70, func_021F3A98, func_021F3AB4, func_021F3AD4, func_021F3B64, func_021F3BC0, func_021F3C14, func_021F3C2C, func_021F3CB0
 * address:  0x021F36C0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_021F3D78  0x021F3D78  thumb  ov048
 *   d_021F4E94     0x021F4E94  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F474C 0x021F474C thumb ov048
 *   func_021F4784 0x021F4784 thumb ov048
 *   func_021BE580 0x021BE580 thumb ov021
 *   d_021F50C0 0x021F50C0 data a4
 *   func_021F47B0 0x021F47B0 thumb ov048
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3B8 0x0200C3B8 thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02014314  0x02014314  thumb
 *   func_021F47BC 0x021F47BC thumb ov048
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F4698  0x021F4698  thumb  ov048
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02012EC0 0x02012EC0 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C3B0 0x0200C3B0 thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02049030  0x02049030  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_021F4C10  0x021F4C10  thumb  ov048
 *   d_021F5224     0x021F5224  data  ov048  a1
 *   func_020307B0 0x020307B0 arm
 *   func_021BE700 0x021BE700 thumb ov021
 *   d_021F50D2 0x021F50D2 data a2
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_020142E8 0x020142E8 thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_0200ECD0  0x0200ECD0  thumb
 *   func_0200ECF0  0x0200ECF0  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02012F68  0x02012F68  thumb
 *   func_0200EC14  0x0200EC14  thumb
 *   func_0200EC2C  0x0200EC2C  thumb
 *   func_021F4DE4  0x021F4DE4  thumb  ov048
 *   func_021F4DF4  0x021F4DF4  thumb  ov048
 *   func_021F4E3C  0x021F4E3C  thumb  ov048
 */
#include "../../matched/include/Obj05133.h"
#include "../../matched/include/G_T.h"
#include "../../matched/include/Obj09833.h"
#include "../../matched/include/Obj00377.h"
#include "../../matched/include/Obj09834.h"
#include "../../matched/include/Obj20528.h"
#include "../../matched/include/Obj20529.h"
#include "../../matched/include/Obj20530.h"
#include "../../matched/include/Obj20531.h"
#include "../../matched/include/Obj20532.h"
#include "../../matched/include/Obj03645.h"
#include "../../matched/include/Obj03646.h"
#include "../../matched/include/Obj03647.h"

struct Big;
struct Ctx;
struct Sub02008700Obj;
struct Obj_021F36C0;
struct Rec94;
struct Blk34;
struct BigObj;
struct M;
struct Mtx33;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct U16Vec;
struct Src0200EC2C;
struct Dst0200EC2C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct { u32 w[15]; } Copy60;

typedef struct Obj_021F36C0 {
    u16 f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
} Obj_021F36C0;

typedef struct Cfg {
    u16 a;
    u8 b;
    u8 c;
    u8 d;
    int w;
} Cfg;

typedef struct Rec {
    u32 a;
    u32 b;
    u32 pad[29];
} Rec;

typedef struct Obj_021F392C {
    u16 f00;
    u32 f04;
    u32 pad08[5];
    Rec *f1c;
} Obj_021F392C;

typedef struct Ent {
    int pad[2];
    int x;
    int y;
    int z;
    int mode;
} Ent;

typedef struct St {
    void *p0;
    void *p1;
    int a;
    int b;
    u16 c;
    u8 pad[10];
} St;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void func_021BE760(int a, void *b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern void func_021F3D78(void *p);
extern int *func_021897BC(char *,int);
extern void func_021F474C(unsigned char *p);
extern void func_021F4784(unsigned char *p, int c);
extern void func_021BE580(void *);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021F47B0(void *);
extern void *func_0200C0F0(void *p);
extern void func_0200C3B8(struct Blk34 *p, u16 v);
extern unsigned int func_0201296C(const struct BigObj *p);
extern void func_02014314(char *a0, int a1);
extern void func_021F47BC(struct M *p, int v);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void *func_021BE4C4(int a, int b, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021F4698(unsigned char *p);
extern void func_021897A0(unsigned char *p, int id);
extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *p);
extern u16 func_0200C3B0(struct Blk34 *p);
extern u16 func_02188C9C(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 id);
extern u32 func_020111E8(void);
extern int func_021F4C10(int a, int b, int c);
extern u32 func_020307B0(void *p);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_020520FC(int a, int b, int c, struct Mtx33 *d);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 func_0200725C(void *s, u32 id, u32 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern int func_0200ECD0(char *o, int idx);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02012F68(void **h);
extern int func_0200EC14(char *p);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern int func_021F4DE4(int a, int b, int c);
extern int func_021F4DF4(int *p, int v);
extern int func_021F4E3C(int *p);
void func_021F36C0(int a);
void func_021F374C(char *a);
void func_021F376C(char *a);
u8 func_021F3790(char *p);
u8 *func_021F37A4(u32 a);
void func_021F37C4(u8 *p);
void func_021F37FC(int *p);
void func_021F3818(int *p);
void func_021F3830(int *p);
void func_021F3870(int *p);
Obj_021F36C0 *func_021F3880(int a);
void func_021F38EC(int *p);
void func_021F3908(int *p);
void func_021F392C(Obj_021F392C *o);
void func_021F39A8(void **p);
void func_021F39BC(int *p);
void func_021F39E4(int *p);
void func_021F3A50(char *p,int a,int b);
int func_021F3A70(u8 *p);
int func_021F3A98(void *p);
int func_021F3AB4(void *p);
void func_021F3AD4(const u16 *p, u32 *out, int *cnt);
void func_021F3B64(u16 *p, u32 *out, int *cnt);
void func_021F3BC0(u8 *p);
void func_021F3C14(char *p);
u8 *func_021F3C2C(u8 *o);
int *func_021F3CB0(int *p);
extern u8 d_021F4E94[];
extern struct T d_021F50C0;
extern const char d_021F5224[];
extern const u16 d_021F50D2[];









void func_021F36C0(int a)
{
    int r6;
    int r4;
    int *p;
    int v;

    r6 = func_02188D2C((int *)a);
    v = func_020083E4((short unsigned int *)func_0200873C(func_02012EBC(func_020120F4(func_02188C80((void *)a)))));
    if (v != 0) {
        if (v == 1) {
            r4 = 0;
        }
    } else {
        r4 = 1;
    }
    func_021BE760(r6, d_021F4E94 + r4 * 16, 1);
    p = (int *)(struct Obj *)func_021F3880(a);
    func_021F392C((Obj_021F392C *)((struct Obj_021F36C0 *)p));
    func_021F3BC0((u8 *)p);
    func_021F37FC(p);
    if (p[4] == 0) {
        func_021F3908(p);
    } else {
        func_021F3818(p);
        func_021F3830(p);
    }
    func_021F3D78(p);
    func_021F3870(p);
    func_021F39E4(p);
    func_021F39BC(p);
}








void func_021F374C(char *a) { u8 *p; p=(u8 *)func_021897BC(a,0); func_021F37C4(p); if(((struct Obj05133 *)p)->f14)func_021F474C(((struct Obj05133 *)p)->f14); func_021F38EC((int *)p); }








void func_021F376C(char *a) { int *p; p=func_021897BC(a,0); func_021F4784((void *)p[5],(*(int *)&d_021F50C0)); func_021BE580((void *)func_02188D2C((int *)((u32)a))); }








u8 func_021F3790(char *p) { return (u8)(*(int **)((char *)func_021897BC(p,0)+0x1c))[5]; }








u8 *func_021F37A4(u32 a) { u32 p; p=(u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))); return (u8 *)func_0200B3A4((struct Rec94 *)p,func_0200B3AC((struct Rec94 *)p)); }








void func_021F37C4(u8 *p) { u8 *q; q=func_021F37A4(((struct Obj05133 *)p)->f4); ((struct Obj09833 *)q)->f0=((struct Obj05133 *)p)->f10; ((struct Obj09833 *)q)->f4=func_021F47B0(((struct Obj05133 *)p)->f14)>>12; ((struct Obj09833 *)q)->f8=((struct Obj05133 *)p)->f64; *(Copy60 *)(q+0xc)=*(Copy60 *)(p+0x28); }







void func_021F37FC(int *p) { char *q; q=(char *)func_021F37A4(p[1]); p[4]=((struct Obj09834 *)q)->f0; p[6]=((struct Obj09834 *)q)->f4; ((struct Obj00377 *)p)->f64=((struct Obj09834 *)q)->f8; }







void func_021F3818(int *p) { func_0200C3B8(func_0200C0F0(func_02012EBC(((struct Obj00377 *)p)->f8)), ((struct Obj00377 *)p)->f64); }








void func_021F3830(int *p)
{
    int r6;
    int i;
    u8 *q;

    r6 = (int)func_0201296C((const struct BigObj *)p[2]);
    q = func_021F37A4(p[1]) + 0xc;
    for (i = 0; i < q[0]; i++) {
        if (*(int *)(q + i * 4 + 4) == 8) {
            func_02014314((char *)r6, (u16)(*(int *)(q + i * 4 + 0x20)));
        }
    }
}






void func_021F3870(int *p) { func_021F47BC((void *)p[5], p[6] << 12); }







Obj_021F36C0 *func_021F3880(int a)
{
    u16 r5;
    int r7;
    Obj_021F36C0 *o;
    int v;
    Cfg c;

    r5 = func_02188C84((u8 *)a);
    r7 = func_02188D2C((int *)a);
    o = func_02189764((unsigned char *)a, 0, r5, 0x68);
    func_02082BCC(o, 0, 0x68);
    o->f00 = r5;
    o->f04 = a;
    v = (int)func_02188C80((void *)a);
    o->f0C = v;
    o->f08 = (int)func_020120F4((const struct Ctx *)v);
    o->f10 = 0;
    c.a = r5;
    c.b = 7;
    c.c = 8;
    c.d = 3;
    c.w = (int)func_021BE4C4(r7, 1, 0);
    o->f14 = (int)func_021F4698((unsigned char *)(&c));
    return o;
}






void func_021F38EC(int *p) { if(p) {func_021F39A8((void **)p);func_021F3C14((char *)p);func_021897A0((unsigned char *)p[1],0);} }






void func_021F3908(int *p) { if(p[4]==0) { ((struct Obj00377 *)p)->f64=func_0200C3B0(func_0200C0E8(func_02012EC0((void *)p[2]))); p[4]=1; } }






void func_021F392C(Obj_021F392C *o)
{
    u32 i;
    u32 n;
    u32 r5;
    Rec buf;

    if (o->f1c == 0) {
        r5 = func_02188C9C((u8 *)o->f04);
        i = 0;
        o->f1c = func_02030734(o->f00, 0x7c, 0, d_021F5224, 0x387);
        n = func_02049030(0xae);
        for (; i < n; i++) {
            func_021F4C10((int)(&buf), 0xae, i);
            if (buf.a == r5) {
                if (buf.b == 0 || buf.b == func_020111E8()) {
                    *o->f1c = buf;
                    return;
                }
            }
        }
    }
}





void func_021F39A8(void **p) { if (p[7]) { func_020307B0(p[7]); p[7] = 0; } }





void func_021F39BC(int *p) { func_021BE700((void *)func_02188D2C((int *)p[1]),1,0,d_021F50D2[((int *)p[7])[0x1d]],1); }






void func_021F39E4(int *p)
{
    int *r3;
    Ent *e;
    int r4;

    r4 = 0;
    r3 = (int *)func_021BE480((char *)func_02188D2C((int *)p[1]), 1, 0);
    e = (Ent *)p[7];
    r3[0] = e->x << 12;
    r3[1] = e->y << 12;
    r3[2] = e->z << 12;
    switch (e->mode) {
    case 1:
        r4 = 0;
        break;
    case 3:
        r4 = 90;
        break;
    case 0:
        r4 = 180;
        break;
    case 2:
        r4 = 270;
        break;
    default:
        r4 = 0;
        break;
    }
    func_020520FC(0, (u16)(r4 * 0xb6), 0, (struct Mtx33 *)(r3 + 6));
}





void func_021F3A50(char *p,int a,int b) { char *q; int i; q=p+0x28; i=((struct Obj20528 *)p)->f28; if(i<7) { *(int *)(q+i*4+4)=a; *(int *)(q+i*4+0x20)=b; ((struct Obj20529 *)q)->f0=i+1; } }






int func_021F3A70(u8 *p)
{
    if (func_021F3A98(p) == 1 || func_021F3AB4(p) == 1) {
        if (((struct Obj20530 *)p)->f64 != 0) {
            return 1;
        }
    }
    return 0;
}





int func_021F3A98(void *p) {return func_020142E8((void *)func_0201296C((const struct BigObj *)(((struct Obj20531 *)p)->f8)),0x960)==1;}





int func_021F3AB4(void *p)
{
    return func_020142E8((void *)func_0201296C((const struct BigObj *)(((struct Obj20532 *)p)->f8)), 0x97b) == 1;
}





void func_021F3AD4(const u16 *p, u32 *out, int *cnt)
{
    int i;
    void *s;
    void *t;
    St st;

    i = 0;
    *cnt = 0;
    s = func_02012EBC((struct Big *)(((int *)p)[2]));
    if (func_0200725C(s, 8, p[0]) - 1 <= 1) {
        t = func_020073D8(s, 8, i);
        if (func_0200ECB4(t) != 0) {
            *cnt = func_0200ECD0(t, i);
            for (; i < *cnt; i++) {
                st.p0 = func_020457B0(0x40, p[0]);
                st.p1 = func_020457B0(0x40, p[0]);
                func_0200ECF0(t, 0, (void *)i, &st);
                out[i] = st.c;
                func_02045808(st.p0);
                func_02045808(st.p1);
            }
        }
    }
    func_020072A4(s, 8);
}





void func_021F3B64(u16 *p, u32 *out, int *cnt)
{
    void *s;
    int i;
    St st;

    s = func_02012F68((void **)(((int *)p)[2]));
    *cnt = func_0200EC14(s);
    for (i = 0; i < *cnt; i++) {
        st.p0 = func_020457B0(0x40, p[0]);
        st.p1 = func_020457B0(0x40, p[0]);
        func_0200EC2C(s, i, (struct Dst0200EC2C *)&st);
        out[i] = st.c;
        func_02045808(st.p0);
        func_02045808(st.p1);
    }
}




void func_021F3BC0(u8 *p)
{
    int n;
    int i;

    if (*(u8 * *)&((struct Obj00377 *)p)->f20 == 0) {
        n = func_02049030(0xa6);
        ((struct Obj00377 *)p)->f20 = func_02030734(((struct Obj00377 *)p)->f0, n * 0x24, 0, d_021F5224, 0x4cb);
        for (i = 0; i < n; i++) {
            func_021F4DE4((int)(*(u8 * *)&((struct Obj00377 *)p)->f20 + i * 0x24), 0xa6, i);
        }
        p[0x24] = n;
    }
}



void func_021F3C14(char *p) { if (((struct Obj03645 *)p)->f20) { func_020307B0(((struct Obj03645 *)p)->f20); ((struct Obj03645 *)p)->f20=0; p[0x24]=0; } }



u8 *func_021F3C2C(u8 *o)
{
    int a;
    void *b;
    int i;
    int off;
    int c;
    int d;

    a = func_02188C9C((u8 *)(((struct Obj03646 *)o)->f4));
    b = (void *)func_0201296C((const struct BigObj *)(((struct Obj03646 *)o)->f8));
    if (*(u8 * *)&((struct Obj03646 *)o)->f20 == 0) {
        return 0;
    }
    for (i = 0; i < ((struct Obj03646 *)o)->f24; i++) {
        off = i * 0x24;
        c = (int)func_020142E8(b, (u16)*(u32 *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off + 4));
        d = func_021F4DF4((int *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off), a);
        if (func_021F4E3C((int *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off)) && c && d) {
            return *(u8 * *)&((struct Obj03646 *)o)->f20 + off;
        }
    }
    return 0;
}



int *func_021F3CB0(int *p)
{
    int a = func_02188C9C((u8 *)p[1]);
    int b = func_0201296C((const struct BigObj *)p[2]);
    int i;

    if (p[8] == 0)
        return 0;
    for (i = 0; i < ((struct Obj03647 *)p)->f24; i++) {
        int off = i * 0x24;
        int t = func_020142E8((void *)b, (u16)((int *)(p[8] + off))[1]);
        int r = func_021F4DF4((int *)(p[8] + off), a);

        if (t != 0 && r != 0 && ((int *)(p[8] + off))[4] == 2)
            return (int *)(p[8] + off);
    }
    return 0;
}

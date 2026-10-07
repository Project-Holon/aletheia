/*
 * file:     plist_battle_p02.c
 * unit:     yes
 * function: func_021B9C64, func_021B9CB0, func_021B9CF4, func_021B9D58, func_021B9DC0, func_021B9E20, func_021B9E3C, func_021B9E44, func_021B9EB0, func_021B9EC0, func_021B9F34, func_021B9F44, func_021BA004, func_021BA0A8, func_021BA288, func_021BA318, func_021BA3A4, func_021BA454, func_021BA4E4, func_021BA4F8, func_021BA5B4, func_021BA5E0, func_021BA60C
 * address:  0x021B9C64
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_021BA65C  0x021BA65C  thumb ov091
 *   func_021BB97C  0x021BB97C  thumb ov091
 *   func_021BB9AC  0x021BB9AC  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021BB9CC  0x021BB9CC  thumb ov091
 *   func_021BB99C  0x021BB99C  thumb ov091
 *   func_021BC6C0  0x021BC6C0  thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E40  0x02017E40  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021BB464  0x021BB464  thumb ov091
 *   func_021BB9EC  0x021BB9EC  thumb ov091
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021BA688  0x021BA688  thumb  ov091
 *   func_021B90F8  0x021B90F8  thumb  ov091
 *   func_0201A59C  0x0201A59C  thumb
 *   func_0201808C 0x0201808C thumb
 *   func_02018238 0x02018238 thumb
 *   func_020181F4 0x020181F4 thumb
 *   func_020182A0 0x020182A0 thumb
 *   func_0201B7A0 0x0201B7A0 thumb
 */
#include "../../matched/include/Obj09926.h"
#include "../../matched/include/Obj13242.h"
#include "../../matched/include/Obj06211.h"
#include "../../matched/include/Obj02771.h"
#include "../../matched/include/Obj09927.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj13244.h"
#include "../../matched/include/Obj13245.h"
#include "../../matched/include/Obj13246.h"
#include "../../matched/include/Obj20864.h"
#include "../../matched/include/Obj20865.h"
#include "../../matched/include/Obj20866.h"
#include "../../matched/include/Obj20869.h"

#define S (*(u8 **)(p+0x280))
struct MsgBank;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct Sub02008F80Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021B7B98(u8 *);
extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9804(u8 *p, int a1);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BC6C0(char *p);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(u8 *,void *);
extern int func_021BDC5C(u8 *,void *);
extern void func_021BDC3C(u32 p, void *m);
extern void func_021BDCA0(u32 p, void *m);
extern void *func_0201AB28(void *p, u32 idx);
extern void  func_02017E40(void *obj, u32 key, u32 v);
extern u16  func_021BB464(int unused, u16 *q);
extern void func_021BB9EC(int a, int b, int c, int d, unsigned char e);
extern int   func_02009020(void *obj, int v);
extern void *func_02008F08(int a0);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern u32 func_020307B0(void *p);
extern u32 func_021BA688(u8 *p, u16 id);
extern void func_021B90F8(u8 *a);
extern int func_0201A59C(void *a0, void *a1, void *a2);
extern u32 func_0201808C(void *,u32);
extern u32 func_02018238(void *,u16);
extern void func_020181F4(void *,u16,u32);
extern void func_020182A0(void *,u16,u32);
extern void func_0201B7A0(void *, int, int, int);
void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
void func_021B9DC0(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
void func_021B9E20(u8 *p);
void func_021B9E3C(u8 *p);
void func_021B9E44(u8 *p);
void func_021B9EB0(u8 *p);
void func_021B9EC0(u8 *p, u32 state);
void func_021B9F34(u8 *p);
void func_021B9F44(u8 *p, u32 state);
void func_021BA004(u8 *p);
void func_021BA098(u8 *p);
void func_021BA0A8(u8 *p,int action);
void func_021BA288(u8 *p);
void func_021BA318(u8 *p);
void func_021BA394(u8 *p);
void func_021BA3A4(u8 *p, u32 state);
void func_021BA444(u8 *p);
void func_021BA454(u8 *a, int k);
void func_021BA4E4(u8 *p);
void func_021BA4F8(u8 *a);
u32 func_021BA5B4(u8 *p, void *q);
void func_021BA5E0(u8 *p, void *q, u32 slot);
void func_021BA60C(u8 *p, void *q);


void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09926 *)p)->f134), idx);
    func_0201C724((void *)(((struct Obj09926 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, (u32)text,
                  ((struct Obj09926 *)p)->f13C, color);
    func_02045808(text);
}


void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj13242 *)p)->f134), idx);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, text, (void *)(((struct Obj13242 *)p)->f13C), color);
    func_02045808(text);
}


void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj06211 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj06211 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C724((void *)(((struct Obj06211 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), x, y, (u32)buf,
                  ((struct Obj06211 *)p)->f138, color);
    func_02045808(text);
    func_02045808(buf);
}


void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj02771 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj02771 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C724((void *)(((struct Obj02771 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), x, y, (u32)buf,
                  ((struct Obj02771 *)p)->f13C, color);
    func_02045808(text);
    func_02045808(buf);
}


void func_021B9DC0(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color)
{
    void *buf = func_020457B0(16, ((struct Obj09927 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09927 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, buf, (void *)(((struct Obj09927 *)p)->f13C), color);
    func_02045808(text);
    func_02045808(buf);
}

void func_021B9E20(u8 *p) { func_021BB7A4(p,(u32 *)(*(u32 *)&((struct Obj00009 *)p)->f150)); p[12]=2; func_021B7B98(p); }

void func_021B9E3C(u8 *p) { p[12]=19; }


#define W(o) (*(u32 *)(p + (o)))


void func_021B9E44(u8 *p)
{
    if (func_021BA65C(p, *(u16 *)(W(0x280) + 0x44))) {
        func_021BB7A4(p, (u32 *)W(0x150));
        p[0xc] = 2;
        func_021B7B98(p);
        return;
    }
    func_021BB7A4(p, (u32 *)W(0x150));
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB9AC((int)p, W(0x150), 0, *(u16 *)(W(0x280) + 0x44));
    func_021B9788(p, 0xb3, 1, (int)func_021B9E3C);
    func_021BB98C(p, W(0x150));
}


void func_021B9EB0(u8 *p)
{
    func_021B9804(p, (int)func_021B9EC0);
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021B9EC0(u8 *p, u32 state)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        u32 *q = (u32 *)W(0x280);
        if (q[0x34 / 4] == 5 || q[0x34 / 4] == 8) {
            q[0x40 / 4] = 5;
        } else {
            q[0x40 / 4] = 4;
        }
        func_021B9788(p, 0x27, 1, (int)func_021B9E3C);
        return;
    }
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x23, 0, (int)func_021B9F34);
    func_021BB98C(p, W(0x150));
}


void func_021B9F34(u8 *p)
{
    func_021B9804(p, (int)func_021B9F44);
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021B9F44(u8 *p, u32 state)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        *(u32 *)(W(0x280) + 0x40) = 10;
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
        if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
            func_021B9788(p, 0x26, 1, (int)func_021BC6C0);
        } else {
            func_021B9788(p, 0x26, 1, (int)func_021B9E3C);
        }
        func_021BB98C(p, W(0x150));
        return;
    }
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x20, 0, (int)func_021B9EB0);
    func_021BB98C(p, W(0x150));
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021BA004(u8 *p)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
        func_021B9788(p, 0x29, 1, (int)func_021BC6C0);
    } else {
        func_021B9788(p, 0x29, 1, (int)func_021B9E3C);
        func_021BA60C(p, (void *)W(0x38));
        *(u32 *)(W(0x280) + 0x40) = 10;
    }
    func_021BB98C(p, W(0x150));
    func_021BA5E0(p, (void *)W(0x38), *(u8 *)(W(0x280) + 0x48));
}


void func_021BA098(u8 *p)
{
    func_021B9804(p, (int)func_021BA0A8);
}

#undef W
#define W(k) (*(u32 *)(p+(k)))

void func_021BA0A8(u8 *p,int action)
{
    u32 old;
    int a,b;
    if (action == 0xe) {
        old = func_02017E1C((void *)W(0x38),6,0);
        if (func_021BA65C(p,old) == 0x3e7) {
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E20);
            } else {
                p[0xc] = 0x13;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E3C);
            }
        } else if (func_0202136C(*(u16 *)(S+0x44)) == 1) {
            *(u32 *)(S+0x3c) = W(0x2c);
            p[0xc] = 0x13;
            *(int *)(S+0x40) = 6;
        } else {
            func_021BB7A4(p,(u32 *)W(0x150));
            func_021BA624(p,(void *)W(0x38),*(u16 *)(S+0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BC24C(p,(void *)W(0x38),(u16)(*(u16 *)(S+0x44)));
            func_021BC288((int)p,(int)((void *)W(0x38)),*(u16 *)(S+0x44));
            a = func_021BDBF8(p,(void *)W(0x38));
            b = func_021BDC5C(p,(void *)W(0x38));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
            func_021BB9AC((int)p,(u32)W(0x150),(u32)2,(u16)(*(u16 *)(S+0x44)));
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E20);
                }
            } else {
                *(int *)(S+0x40) = 0xa;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E3C);
                }
            }
            func_021BB98C(p,W(0x150));
        }
    } else {
        if (*(int *)(S+0x34) == 0xa) {
            *(int *)(S+0x34) = 0;
            func_021BB7A4(p,(u32 *)W(0x150));
            p[0xc] = 2;
            func_021B7B98(p);
        } else p[0xc] = 0x13;
    }
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021BA288(u8 *p)
{
    void *o1;
    void *o2;
    u32 b, c, d, e;

    o1 = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
    func_02017E1C(o1, 0xa0, 0);
    b = func_02017E1C(o1, 0xa1, 0);
    o2 = func_0201AB28((void *)*(u32 *)W(0x280), ((u32 *)W(0x280))[0x3c / 4]);
    c = func_02017E1C((void *)W(0x38), 0xa0, 0);
    d = func_02017E1C((void *)W(0x38), 0xa1, 0);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    e = c + b / 5;
    if (e > d) {
        func_02017E40(o2, 0xa0, d);
    } else {
        func_02017E40(o2, 0xa0, e);
    }
    W(0x120) = (u32)func_021BA318;
    p[0xc] = 10;
    W(0x24) = 1;
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021BA318(u8 *p)
{
    u16 r;
    u16 t;

    r = func_021BB464((int)p, (u16 *)((u32 *)(p + 0x160))[((u32 *)W(0x280))[0x3c / 4]]);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    t = ((struct Obj13244 *)p)->f11C;
    if (t) {
        func_021BB9EC((int)p, (u32)W(0x150), (u32)1, (u16)(r - t), 3);
        func_021B9788(p, 0x2c, 1, (int)func_021B9E20);
    }
    func_021BB98C(p, W(0x150));
}


void func_021BA394(u8 *p)
{
    func_021B9804(p, (int)func_021BA3A4);
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021BA3A4(u8 *p, u32 state)
{
    int r;
    void *buf;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        r = func_02009020((void *)((u32 *)W(0x280))[2], 0);
        if (r >= 0) {
            buf = func_02008F08(((struct Obj13245 *)p)->f0);
            func_02017E1C((void *)W(0x38), 0xa7, (u32)buf);
            func_0200903C((void *)((u32 *)W(0x280))[2], 0, r, buf);
            func_020307B0(buf);
            func_02017E40((void *)W(0x38), 6, 0);
            func_021BB2C0(p, (u8 *)(((u32 *)(p + 0x160))[W(0x2c)]));
            func_021B9788(p, 0x1a, 1, (int)func_021B9E20);
        } else {
            func_021B9788(p, 0x1e, 1, (int)func_021B9E20);
        }
        return;
    }
    func_021B9788(p, 0x1b, 0, (int)func_021BA444);
}


void func_021BA444(u8 *p)
{
    func_021B9804(p, (int)func_021BA454);
}


void func_021BA454(u8 *a, int k)
{
    func_021BB7A4(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
    if (k == 0xe) {
        int v = func_02017E1C((void *)*(int *)&((struct Obj00009 *)a)->f38, 6, 0);

        if (func_021BA65C(a, v) == 0x3e7) {
            func_021B9788(a, 0x3f, 1, (int)func_021B9E20);
            return;
        }
        func_021BA688(a, v);
        func_02017E40((void *)(*(int *)&((struct Obj00009 *)a)->f38), 6, 0);
        func_021BB2C0(a, (u8 *)(*(int *)(a + ((struct Obj00009 *)a)->f2C * 4 + 0x160)));
        func_021B9788(a, 0x1f, 1, (int)func_021B9E20);
    } else {
        func_021BB7A4(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
        a[0xc] = 2;
        func_021B7B98(a);
    }
}

void func_021BA4E4(u8 *p) { func_021BB7A4(p, (u32 *)(((struct Obj13246 *)p)->f150)); p[12]=14; }


void func_021BA4F8(u8 *a)
{
    u8 i;
    u8 j;
    u8 *rules;
    int st;

    if (((struct Obj00009 *)a)->f250 != 0)
        return;
    st = a[0xc];
    if (st == 0x13)
        return;
    if (st == 0x15)
        return;
    if (st == 0)
        return;
    if (st == 1)
        return;
    if (st == 6)
        func_021B90F8(a);
    ((struct Obj00009 *)a)->f250 = 1;
    if (((struct Obj00009 *)a)->f278 == 1)
        a[0xc] = 0x11;
    else
        a[0xc] = 0x14;
    ((struct Obj20864 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f3C = 6;
    ((struct Obj20865 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f40 = 0;
    if (((struct Obj00009 *)a)->f118 != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    rules = *(u8 * *)&((struct Obj20866 *)(*(u8 * *)&((struct Obj00009 *)a)->f280))->f14;
    if (func_0201A59C(rules, (void *)(**(int * *)&((struct Obj00009 *)a)->f280), *(u8 * *)&((struct Obj00009 *)a)->f280 + 0x49) != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    for (j = 0; j < rules[2]; j++)
        (*(u8 **)(a + 0x280))[0x49 + j] = j + 1;
}

u32 func_021BA5B4(u8 *p, void *q) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) return func_0201808C(q,*(u16 *)(s+0x46)); else return func_02018238(q,*(u16 *)(s+0x46)); }

/*
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned char u8; typedef unsigned short u16;
 * extern void func_020182A8(void *,u16,u8);
 * void func_020182A0(void *p,u16 move,u8 slot) { func_020182A8(p,move,slot); }
 * Extent ends with two bytes alignment padding.
 *
 * 2026-10-05 (D8 lane 15): 020182A0 now filed EXACT as src/matched/arm9/func_020182A0.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void func_021BA5E0(u8 *p, void *q, u32 slot) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) func_020181F4(q,*(u16 *)(s+0x46),slot); else func_020182A0(q,*(u16 *)(s+0x46),slot); }

void func_021BA60C(u8 *p, void *q) { func_0201B7A0(q,7,((struct Obj20869 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f30,((struct Obj00009 *)p)->f0); }

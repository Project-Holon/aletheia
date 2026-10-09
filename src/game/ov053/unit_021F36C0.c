/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3734, func_021F3778, func_021F3828, func_021F3978, func_021F39BC, func_021F39D0, func_021F3A04, func_021F3A38, func_021F3A5C, func_021F3A6C, func_021F3A7C, func_021F3AA0, func_021F3B10, func_021F3B20, func_021F3B30
 * address:  0x021F36C0
 * region:   ov053
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
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_0202B914  0x0202B914  thumb
 *   d_021F3D60     0x021F3D60  data  a4
 *   func_021897BC  0x021897BC  thumb
 *   func_02005F24  0x02005F24  thumb
 *   func_021C4DA8  0x021C4DA8  thumb  ov021
 *   func_021897A0  0x021897A0  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECB4  0x0218ECB4  thumb  ov021
 *   func_0202B93C  0x0202B93C  thumb
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021F3B40  0x021F3B40  thumb  ov053
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4D7C  0x021C4D7C  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021F3CF0     0x021F3CF0  data  a4
 *   func_02048F74 0x02048F74 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fleq  0x0209BC0C  arm
 *   _fls   0x0209BC74  arm
 *   _fsub  0x0209CB8C  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02082A7C 0x02082A7C arm
 */
#include "../../matched/include/Obj13115.h"
#include "../../matched/include/Obj09845.h"
#include "../../matched/include/Obj13117.h"
#include "../../matched/include/Obj03650.h"

struct Obj;
struct O;
struct Obj00020;
struct Big;
struct Ctx;
struct Rec94;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int w[5];
    char pad30[0x34];
    int f64;
    char f68[1];
} O;

typedef struct { int v[5]; } T5;

typedef signed int     s32;

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_0202B914(struct Obj *o, u32 v);
extern void *func_021897BC(int, int);
extern void func_02005F24(u32 a0, u32 a1);
extern int func_021C4DA8(void *a);
extern void func_021897A0(int, int);
extern void *func_02188C58(void *p);
extern void func_0218ECE4(int, int *);
extern void func_0218ECB4(int, int *);
extern void func_0202B93C(int a, void *b, void *c);
extern int func_021C4DE4(int, int);
extern void func_021BE580(int);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021F3B40(struct Obj *o, int h, u8 *a2);
extern void *func_02188C80(void *p);
extern unsigned int func_02012134(unsigned int *p);
extern unsigned int func_0202B57C(void *obj);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021C4D14(int a, int b, int c, int d, int e);
extern int func_021C4D7C(int, int);
extern void func_021C4DC0(int, int, int, int);
extern u32 func_020307B0(void *p);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern unsigned func_021C4E20(void *);
extern int func_021C4E08(void *, int);
extern unsigned func_02005728(unsigned);
extern void func_02082A7C(int, void *, unsigned int);
void func_021F36C0(u32 a);
void func_021F3734(int a);
void func_021F3778(int a);
void func_021F3828(O *o, u32 q);
void func_021F3978(char *a);
void func_021F39BC(char *a);
void func_021F39D0(char *a, int b);
void func_021F3A04(char *a, int b);
void func_021F3A38(char *a, int i);
int func_021F3A5C(char *p, int i);
void func_021F3A6C(int *p);
void func_021F3A7C(char *p, int a);
int func_021F3AA0(char *a, int b);
void func_021F3B10(char *p, int target);
void func_021F3B20(char *p, int target);
void func_021F3B30(void *p);
extern char d_021F3D60[];
extern T5 d_021F3CF0;





void func_021F36C0(u32 a)
{
    u32 r6;
    u32 r5;
    u8 *e;
    int *p;

    r6 = func_02188C84((u8 *)a);
    r5 = func_02188D2C((int *)a);
    func_021BE760(r5, d_021F3D60, 0);
    func_021BE700((void *)r5, 0, 4, 0, 1);
    e = func_021BE674((char *)r5, 0, 4, 0);
    func_021BE6B0(e, 0);
    func_021BE6B8(e, 1);
    p = func_02189764((unsigned char *)a, 0, r6, 0xf8);
    func_021F3828((O *)((struct O *)p), a);
    func_021F3A04((char *)p, a);
    func_0202B914((struct Obj *)p[1], 0x7f);
}





void func_021F3734(int a)
{
    int i;
    char *p = (char *)func_021897BC(a, 0);
    func_0202B914((struct Obj *)(((struct Obj13115 *)p)->f4), 0);
    func_02005F24(((struct Obj13115 *)p)->f58, 0);
    func_021F39D0(p, a);
    for (i = 0; i < 5; i++)
        func_021C4DA8((void *)(*(int *)(p + i * 4 + 8)));
    func_021897A0(a, 0);
}





void func_021F3778(int a)
{
    int i;
    int h;
    int *p;
    int v1[3];
    int v2[3];

    i = 0;
    p = func_021897BC((int)((char *)a), 0);
    h = (int)func_02188C58((void *)a);
    func_0218ECE4(h, v1);
    func_0218ECB4(h, v2);
    func_0202B93C(p[1], v1, v2);
    for (i = 0; i < 5; i++) {
        int *q = p + i;
        if (q[7] > 0) {
            if (--q[7] <= 0) {
                func_021F3A5C((char *)p, i);
                switch (i) {
                case 0:
                    p[8] = 1;
                    break;
                case 2:
                    p[10] = 1;
                    break;
                }
            }
        } else if (func_021C4DE4(q[2], 0x1000)) {
            func_021F3A38((char *)p, i);
        }
    }
    func_021F3A7C((char *)p, a);
    func_021F3A6C(p);
    func_021BE580(func_02188D2C((int *)a));
    func_021F3B40((struct Obj *)(p + 0x1a), h, (u8 *)func_02188CB4((struct Obj00020 *)a));
}





void func_021F3828(O *o, u32 q)
{
    int i;
    int a;
    int t8;
    int s0;
    int s1;
    int *p;
    int r;

    a = func_02188C84((u8 *)q);
    t8 = func_02188D2C((int *)q);
    i = 0;
    o->h0 = a;
    o->f64 = 0;
    o->f4 = func_0202B57C((void *)func_02012134((unsigned int *)func_02188C80((void *)q)));
    p = func_02048F60(0x94, 1, a);
    s0 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    func_021C4DC0(s0, 0x94, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480((char *)t8, 0, 1));
    func_021C4DC0(r, 0x94, 5, 10);
    o->fc = r;
    p = func_02048F60(0x94, 6, a);
    s1 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 2), 9, p[0] << 12, p[1]);
    func_021C4DC0(s1, 0x94, 8, 10);
    o->f10 = s1;
    func_020307B0(p);
    r = func_021C4D7C(q, func_021BE480((char *)t8, 0, 3));
    func_021C4DC0(r, 0x94, 10, 10);
    o->f14 = r;
    p = func_02048F60(0x94, 12, a);
    r = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 4), 7, p[0] << 12, p[1]);
    func_021C4DC0(r, 0x94, 11, 10);
    o->f18 = r;
    func_020307B0(p);
    for (i = 0; i < 5; i++)
        o->w[i] = 0;
    func_021F3978((char *)o);
    func_021F39BC((char *)o);
    func_021F3B30(o->f68);
}




void func_021F3978(char *a)
{
    T5 t = d_021F3CF0;
    int i;

    for (i = 0; i < 5; i++) {
        int *p = func_02048F60(0x94, t.v[i], ((struct Obj09845 *)a)->f0);
        ((int *)(a + 0x30))[i] = p[0];
        ((int *)(a + 0x44))[i] = p[1];
        func_020307B0(p);
    }
}




void func_021F39BC(char *a)
{
    func_02048F74(a + 0x58, 0x94, 0, 0, (u32 *)12);
}




void func_021F39D0(char *a, int b)
{
    int i;
    int *p = (int *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)b))), 1);
    for (i = 0; i < 5; i++)
        p[i] = (int)func_021C4E20(((void **)(a + 8))[i]) >> 12;
}




void func_021F3A04(char *a, int b)
{
    int i;
    int *p = (int *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)b))), 1);
    for (i = 0; i < 5; i++)
        func_021C4E08(((void **)(a + 8))[i], (int)((unsigned)p[i] << 12));
}


/*
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 */
void func_021F3A38(char *a, int i)
{
    ((int *)(a + 0x1c))[i] = ((int *)(a + 0x30))[i] +
        func_02005728(((int *)(a + 0x44))[i] - ((int *)(a + 0x30))[i] + 1);
}


int func_021F3A5C(char *p, int i) { return func_021C4E08(*(void **)(p+8+4*i),0); }


void func_021F3A6C(int *p) { func_02005F24(((struct Obj13117 *)p)->f58, ((struct Obj13117 *)p)->f64); }


void func_021F3A7C(char *p, int a) { int v=func_021F3AA0(p,a); if (((struct Obj03650 *)p)->f64<v) func_021F3B10(p,v); else if(v<((struct Obj03650 *)p)->f64) func_021F3B20(p,v); }



int func_021F3AA0(char *a, int b)
{
    int v[3];
    float x;
    float r;

    func_0218ECE4((int)func_02188C58((void *)b), v);
    x = v[1] / 4096.0f;
    if (x <= *(float *)(a + 0x5c))
        return 0;
    if (*(float *)(a + 0x60) < x)
        return 0x7f;
    r = *(float *)(a + 0x60) - *(float *)(a + 0x5c);
    return (int)(127.0f * (x - *(float *)(a + 0x5c)) / r);
}



void func_021F3B10(char *p, int target) { ((struct Obj03650 *)p)->f64 += 16; if (target < ((struct Obj03650 *)p)->f64) ((struct Obj03650 *)p)->f64=target; }



void func_021F3B20(char *p, int target) { ((struct Obj03650 *)p)->f64 -= 16; if (((struct Obj03650 *)p)->f64 < target) ((struct Obj03650 *)p)->f64=target; }


void func_021F3B30(void *p) { func_02082A7C(0,p,0x90); }

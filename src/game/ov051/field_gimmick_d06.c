/*
 * file:     field_gimmick_d06.c
 * unit:     yes
 * function: func_021F36C0, func_021F36E0, func_021F36EC, func_021F36F8, func_021F3718, func_021F3724, func_021F3730, func_021F3868, func_021F38A0, func_021F38A4, func_021F3958, func_021F39F8, func_021F3AB4, func_021F3B44, func_021F3B88, func_021F3BC4, func_021F3C84, func_021F3C98, func_021F3CCC, func_021F3D04, func_021F3D38, func_021F3D6C
 * address:  0x021F36C0
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3DB4 0x021F3DB4 data a4
 *   d_021F3DFC 0x021F3DFC data a4
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3D94  0x021F3D94  thumb  ov051
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_0216D588  0x0216D588  thumb
 *   d_021F40A0     0x021F40A0  data  ov051  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb
 *   func_0216DDC0  0x0216DDC0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082C60  0x02082C60  arm
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D3CC  0x0216D3CC  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb
 *   func_0216D480  0x0216D480  thumb
 *   func_021C909C  0x021C909C  thumb
 *   func_021C90AC  0x021C90AC  thumb
 *   func_021C90D0  0x021C90D0  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_021C9064  0x021C9064  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D854  0x0216D854  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_02164240  0x02164240  thumb
 *   func_02163994  0x02163994  thumb
 *   func_02164280  0x02164280  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB3F8  0x021AB3F8  thumb
 *   func_021C9258 0x021C9258 thumb ov021
 *   func_021C928C 0x021C928C thumb ov021
 *   func_0216CE6C 0x0216CE6C thumb ov010
 */
#include "../../matched/include/Obj20552.h"
#include "../../matched/include/Obj20553.h"
#include "../../matched/include/Obj20555.h"
#include "../../matched/include/Obj20556.h"
#include "../../matched/include/Obj09844.h"
#include "../../matched/include/Obj06158.h"
#include "../../matched/include/Obj01876.h"
#include "../../matched/include/Obj07660.h"

struct Big;
struct Ctx;
struct Rec94;
struct VecFx32;
struct Desc;
struct Obj;
struct Actor;
typedef struct { int id; int n; int *ptr; } Entry;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 x,y,z; } V;

extern unsigned short func_02188C84(unsigned char *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern unsigned int func_02188CD0(u8 *p);
extern unsigned short func_02188C9C(u8 *p);
extern int func_021F3D94(int a);
extern s32 *func_0200B3A4(struct Rec94 *p, unsigned int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ABE30(int, int *, int);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(void *it, int *cur, int *v);
extern int func_0216D588(int a);
extern u32 func_020307B0(void *p);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *b);
extern void func_02164208(int a, int *b, int c);
extern int func_0216DDC0(void *a, int b, int c, int d);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082C60(void *a, int b, int c);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(void *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
extern void func_020061E4(u32 a);
extern int func_0216D454(void *a);
extern void func_0216D480(void *a);
extern void func_021C909C(int a);
extern void func_021C90AC(int a);
extern int func_021C90D0(int a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *b);
extern int func_021C9064(int a, int *b, int c);
extern int func_02188C98(int a);
extern int func_0216D83C(int a);
extern int func_0216D854(int a);
extern int func_0216D86C(int a);
extern void func_02164240(int a, short *b, short *c, int d);
extern int func_02163994(int a, int b, int c, int d, int e);
extern void func_02164280(int a, int b, int *c);
extern int func_0216D8AC(int a);
extern int func_021AB0D4(int a, int *b);
extern int func_021AB0F0(int a);
extern int func_021AB3F8(int a);
extern unsigned func_021C9258(unsigned, int *);
extern void func_021C928C(unsigned);
extern void *func_0216CE6C(void *, int, int, unsigned short, unsigned, unsigned, unsigned, unsigned);
const Entry *func_021F36C0(int id);
int func_021F36E0(int a);
int func_021F36EC(int a);
const Entry *func_021F36F8(int id);
int func_021F3718(int a);
int func_021F3724(int a);
void func_021F3730(unsigned char *a);
void func_021F3868(u8 *p);
void func_021F38A0(void);
int func_021F38A4(int a, int b);
int func_021F3958(int a, int id, int arg);
int func_021F39F8(int a, int *s, int *t);
int func_021F3AB4(int a, int *s, int *t);
void func_021F3B44(int *a, int *out, int x, int y);
void func_021F3B88(int *a, u32 *out, int c);
int func_021F3BC4(int *a, int *bp, int c, unsigned short d, unsigned int *out);
int func_021F3C84(int *a, int *b, int c);
int func_021F3C98(int *a, int *b);
void func_021F3CCC(int *a, unsigned *b, int x, int y, int z);
void func_021F3D04(int a, int b);
void *func_021F3D38(int a, int x, int y);
void *func_021F3D6C(int a);
extern const Entry d_021F3DB4[];
extern const Entry d_021F3DFC[];
extern char d_021F40A0[];


const Entry *func_021F36C0(int id) { unsigned int i; const Entry *p=d_021F3DB4; for(i=0;i<3;i++,p++) if(p->id==id) return p; return d_021F3DB4; }


/*
 * Two accessors over the result of func_021F36C0.
 */
int func_021F36E0(int a)
{
    return ((struct Obj20552 *)((char *)func_021F36C0(a)))->f8;
}


int func_021F36EC(int a)
{
    return ((struct Obj20553 *)((char *)func_021F36C0(a)))->f4;
}



const Entry *func_021F36F8(int id) { unsigned int i; const Entry *p=d_021F3DFC; for(i=0;i<3;i++,p++) if(p->id==id) return p; return d_021F3DFC; }

/*
 * Two accessors over the result of func_021F36F8.
 */
int func_021F3718(int a)
{
    return ((struct Obj20555 *)((char *)func_021F36F8(a)))->f8;
}

int func_021F3724(int a)
{
    return ((struct Obj20556 *)((char *)func_021F36F8(a)))->f4;
}








/*
 * note:     the flag test reads p[0] as unsigned char (ldrb); a plain char
 *           test gives ldrsb with a zero register hoisted above the branch.
 */
void func_021F3730(unsigned char *a)
{
    int n;
    int v;
    int cur;
    int r4;
    unsigned h;
    int sp8;
    int r5;
    char *p;
    int *q;
    unsigned int i;
    unsigned int cnt;
    int *e;
    void *it;

    r4 = func_02188C84(a);
    h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    sp8 = func_02188CD0((u8 *)a);
    r5 = func_02188C9C((u8 *)a);
    p = (char *)func_0200B3A4((struct Rec94 *)h, func_021F3D94(r5));
    q = func_02030734(r4, 0xa4, 1, d_021F40A0, 0xca);
    *(int * *)&((struct Obj09844 *)p)->f4 = q;
    q[1] = (int)p;
    q[2] = (int)a;
    q[0] = r5;
    n = 0xb;
    func_021ABE30(sp8, &n, 1);
    if (((struct Obj09844 *)p)->f0 == 0) {
        cnt = func_021F36EC(q[0]);
        e = (int *)func_021F36E0(q[0]);
        i = 0;
        if (i < cnt)
            for (; i < cnt; i++) {
                func_021F3B44(q, q + 3 + i * 2, e[0], e[2]);
                e += 3;
            }
    } else {
        i = 0;
        v = 0;
        it = func_02188C7C((void *)a);
        while (func_0216DD1C(it, &cur, &v)) {
            if (func_0216D588(cur) == 0xfd) {
                func_021F3B88(q, (u32 *)(q + 3 + i * 2), cur);
                i++;
                if (i >= 12)
                    break;
            }
        }
    }
    cnt = func_021F3724(q[0]);
    e = (int *)func_021F3718(q[0]);
    i = 0;
    if (i < cnt)
        for (; i < cnt; i++) {
            func_021F3CCC(q, (unsigned int *)(q + 0x1b + i), e[0], e[1], e[2]);
            e += 3;
        }
    *p = 1;
}






void func_021F3868(u8 *p)
{
    unsigned h;
    func_02188C84(p);
    h=(unsigned int)func_02012EC4(func_020120F4(func_02188C80(p)));
    func_02188CD0(p);
    func_020307B0(*(void **)((char *)func_0200B3A4((struct Rec94 *)h, func_021F3D94(func_02188C9C(p)))+4));
}







/*
 * note: extent follower at 0x021F38A0 is an empty return stub; no existing same-region source or shard was found.
 */
void func_021F38A0(void)
{
}







int func_021F38A4(int a, int b)
{
    int v[3];
    int res;
    int x;
    int y;
    int h;
    unsigned int i;
    int *p;
    unsigned int n;
    int *r4;

    res = 0;
    r4 = func_021F3D6C(a);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    func_02164208(b, v, 1 << 16);
    x = (short)(((v[0] >> 4) / 4096));
    y = (short)(((v[2] >> 4) / 4096));
    n = func_021F3724(*r4);
    p = (int *)func_021F3718(*r4);
    i = 0;
    if (i < n)
        for (; i < n; i++) {
            if (p[0] == x && p[2] == y)
                func_021F3D04(a, i);
            p += 3;
        }
    h = func_0216DDC0(func_02188C7C((void *)a), x, y, 0);
    if (h != 0 && func_0216D588(h) == 0xfd)
        res = func_021F3958(a, h, b);
    return res;
}







int func_021F3958(int a, int id, int arg)
{
    int sp3;
    int sp8;
    int sp1;
    unsigned short i;
    int v;
    char *r5;
    char *r7;
    unsigned short *r6;

    r5 = func_021F3D6C(a);
    sp8 = (int)func_02188C80((void *)a);
    for (i = 0; i < 12; i++) {
        v = *(int *)(r5 + 12 + i * 8);
        if (v == id)
            break;
    }
    if (i >= 12)
        i = 0;
    r7 = r5 + 12 + i * 8;
    if (func_021F3C98((int *)r5, (int *)r7) == 1)
        return 0;
    sp3 = func_021F3C84((int *)r5, (int *)r7, arg);
    if (sp3 == 0)
        sp1 = (int)func_020122C0((void *)sp8, 0, func_021F3AB4, 0x10);
    else
        sp1 = (int)func_020122C0((void *)sp8, 0, func_021F39F8, 0x10);
    r6 = func_020124E8((struct Obj *)sp1);
    func_02082C60(r6, 0, 0x10);
    r6[0] = arg;
    *(char * *)&((struct Obj06158 *)r6)->fC = r5;
    r6[1] = i;
    *(char * *)&((struct Obj06158 *)r6)->f8 = r7;
    ((struct Obj06158 *)r6)->f4 = sp3;
    return sp1;
}







int func_021F39F8(int a, int *s, int *t)
{
    void *r6;

    r6 = func_021A3074(func_02188CB4(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (func_0216D3CC(r6) == 1) {
            func_0216D410(r6, func_02197E7C(((struct Obj01876 *)t)->f0, 0x1c));
            func_020061E4(0x6ce);
            *s = *s + 1;
        }
        break;
    case 1:
        if (func_0216D3CC(*(void **)t[2]) == 1) {
            if (t[1] > 0) {
                int v = 8;
                if (t[1] <= 1)
                    v = 0x10;
                else if (t[1] <= 2)
                    v = 0x10;
                else if (t[1] <= 4)
                    v = 0xc;
                func_0216D410(*(void **)t[2], func_02197E7C(((struct Obj01876 *)t)->f0, v));
                t[1] = t[1] - 1;
            } else {
                func_020061E4(0x6a3);
                *s = *s + 1;
            }
        }
        break;
    case 2:
        if (func_0216D454(r6) == 1) {
            func_0216D480(*(void **)t[2]);
            func_0216D480(r6);
            func_021C909C(((int *)t[2])[1]);
            return 1;
        }
        break;
    }
    return 0;
}






int func_021F3AB4(int a, int *s, int *t)
{
    void *r6;

    r6 = func_021A3074(func_02188CB4(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (func_0216D3CC(r6) == 1) {
            func_0216D410(r6, func_02197E7C(((struct Obj07660 *)t)->f0, 0x1c));
            func_020061E4(0x55a);
            *s = *s + 1;
        }
    case 1:
        func_021C90AC(((int *)t[2])[1]);
        *s = *s + 1;
        break;
    case 2:
        if (func_021C90D0(((int *)t[2])[1]) == 0)
            break;
        *s = *s + 1;
    case 3:
        if (func_0216D454(r6) == 1) {
            func_0216D480(r6);
            return 1;
        }
        break;
    }
    return 0;
}






void func_021F3B44(int *a, int *out, int x, int y)
{
    int buf[3];

    out[0] = (int)func_021F3D38(a[2], x, y);
    func_0216D88C((const struct Actor *)out[0], (struct VecFx32 *)buf);
    out[1] = func_021C9064(func_02188CD0((u8 *)a[2]), buf, out[0]);
    if (func_021F3C98(a, out) == 1)
        func_021C909C(out[1]);
}




/*
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * note: func_021C9064's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
void func_021F3B88(int *a, u32 *out, int c)
{
    V v;
    out[0]=c;
    func_0216D88C((const struct Actor *)c,(struct VecFx32 *)&v);
    out[1]=func_021C9064(func_02188CD0((u8 *)a[2]), (int *)&v, out[0]);
    if(func_021F3C98(a,(int *)out)==1) func_021C909C(out[1]);
}





/*
 * q[3] is padding (four bytes of frame the original carries above q[1]);
 * m[1] keeps the mask in memory (a plain int folds); d as u16 puts the
 * parameter spill first.
 */
int func_021F3BC4(int *a, int *bp, int c, unsigned short d, unsigned int *out)
{
    int r7 = *bp;
    unsigned short i = 0;
    int q[3];
    short pt[2];
    int m[1];
    int found = 0;
    int sp0c;
    int sp8;
    int r;

    sp0c = func_02188C98(a[2]);
    pt[1] = func_0216D83C(r7);
    sp8 = func_0216D854(r7);
    pt[0] = func_0216D86C(r7);
    m[0] = 1;
    do {
        func_02164240(c, &pt[1], &pt[0], 1);
        r = func_02163994(r7, pt[1], sp8, pt[0], c) & ~m[0];
        if (r != 0) {
            if (r & 2) {
                func_02164280(pt[1], pt[0], &q[0]);
                q[1] = func_0216D8AC(r7);
                r = func_021AB0D4(sp0c, q);
                if (r != -1) {
                    if (func_021AB3F8(func_021AB0F0(r)) == 1)
                        found = 1;
                }
            }
            break;
        }
        i = i + 1;
    } while (i < d);
    if (found == 0)
        i = 0;
    *out = i;
    return found;
}




int func_021F3C84(int *a, int *b, int c) { unsigned int out; func_021F3BC4(a,b,c,32,&out); return out; }




int func_021F3C98(int *a, int *b)
{
    unsigned short i = 0;
    unsigned out;
    do {
        if (func_021F3BC4(a, b, i, 1, &out) == 1)
            return 1;
        i++;
    } while (i < 4);
    return 0;
}




/*
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 */
void func_021F3CCC(int *a, unsigned *b, int x, int y, int z)
{
    int v[3];
    func_02164280((short)x, (short)z, v);
    v[1] = (int)(((unsigned)y << 16) + 0x8000u);
    *b = func_021C9258(func_02188CD0((u8 *)a[2]), v);
}




void func_021F3D04(int a, int b)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    char *p = *(char **)((char *)func_0200B3A4((struct Rec94 *)h, func_021F3D94(func_02188C9C((u8 *)a))) + 4);
    func_021C928C(((unsigned *)(p + 0x6c))[b]);
}




void *func_021F3D38(int a, int x, int y)
{
    void *p = func_02188C7C((u8 *)a);
    int n = func_02188C9C((u8 *)a);
    return func_0216CE6C(p, (short)x, (short)y, 0, 0xfd, 0, 0, n);
}




void *func_021F3D6C(int a)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    return *(void **)((char *)func_0200B3A4((struct Rec94 *)h, func_021F3D94(func_02188C9C((u8 *)a))) + 4);
}

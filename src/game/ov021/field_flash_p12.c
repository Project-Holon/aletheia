/*
 * file:     field_flash_p12.c
 * unit:     yes
 * function: func_021C7FB4, func_021C7FBC, func_021C7FC0, func_021C7FF0, func_021C8000, func_021C800C, func_021C8018, func_021C8054, func_021C8078, func_021C812C, func_021C8170, func_021C81B4, func_021C81F8, func_021C8268, func_021C82C4, func_021C85CC, func_021C8608, func_021C8660, func_021C868C, func_021C86E8, func_021C8738
 * address:  0x021C7FB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021C7DAC  0x021C7DAC  thumb  ov021
 *   func_021C7E50  0x021C7E50  thumb  ov021
 *   func_021C7DE0  0x021C7DE0  thumb
 *   func_021C7DFC  0x021C7DFC  thumb  ov021
 *   func_021C7E30  0x021C7E30  thumb  ov021
 *   d_021DE520  0x021DE520  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047504  0x02047504  arm
 *   func_02047738  0x02047738  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02046AFC  0x02046AFC  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0204755C  0x0204755C  arm
 *   func_0206E394  0x0206E394  arm
 *   func_0206E4FC  0x0206E4FC  arm
 *   func_0206E484  0x0206E484  arm
 *   func_0206E574  0x0206E574  arm
 *   func_0206E40C  0x0206E40C  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_021C30B8  0x021C30B8  thumb  ov021
 *   d_021DAAE0     0x021DAAE0  data  a2
 *   d_021DAAE2     0x021DAAE2  data  a2
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218F848  0x0218F848  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_021BEA30  0x021BEA30  thumb  ov021
 *   func_021854CC  0x021854CC  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02043658  0x02043658  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   d_021DE534     0x021DE534  data  a4
 *   d_00000024     0x00000024  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_021C87E0  0x021C87E0  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 */
#include "../../matched/include/Obj18331.h"
#include "../../matched/include/Obj18332.h"
#include "../../matched/include/Obj09214.h"
#include "../../matched/include/Obj03616.h"
#include "../../matched/include/Obj07575.h"
#include "../../matched/include/Obj06090.h"

struct Rec;
struct Tagged;
struct Arg;
struct Ctx;
struct Stream;
struct Desc;
struct Obj;
struct Sub0200852CObj;
struct t;
struct TaskCtx;
struct Evt;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M_021C7FC0;

typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M_021C8018;

typedef struct { u32 f0; u32 f4; } N;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } V;

typedef struct { int m[9]; } M_021C8078;

typedef struct { int m[12]; } M43;

typedef struct { V pos, tgt, up; } Cam;

typedef struct { V t; V s; M_021C8078 r; } SRT;

typedef struct { int f0; void *f4; } Q;

typedef struct { int f0; void *f4; } Obj;

typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

typedef struct Param {
    u32 pad0[3];
    VecFx32 pos;
    u32 f18;
    u32 f1c;
    u32 f20;
    u16 h24;
    u16 h26;
    u32 f28;
    u16 h2c;
    u16 pad2e;
    Buf24 buf;
} Param;

typedef struct TaskCtx {
    void *w0;
    u32 f04;
    u32 f08;
    u8 f0c[0x28 - 0x0c];
    u32 f28;
    u32 f2c;
} Ctx;

typedef struct { u32 f0; u32 f4; u32 f8; u8 pad[0x1a8]; u32 f1B4; } P;

typedef struct {
    int f0;
    short f4;
    short f6;
    int f8;
} S;

extern u32 func_020307B0(void *p);
extern M_021C7FC0 *func_021C7DAC(u32 heap);
extern void func_021C7E50(u8 *p, u16 v);
extern void func_021C7DE0(void *p);
extern void func_021C7DFC(u32 v);
extern void func_021C7E30(u32 v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02046DB8(u32 a0, u32 a1);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02046EFC(struct Tagged *p);
extern void func_02047504(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02046AFC(u8 *dst);
extern void func_0207CA00(V *, V *, V *);
extern void func_0207CCA4(V *, V *);
extern u32 *func_0206AAD4(void);
extern void func_02082B60(M43 *, M_021C8078 *);
extern Q *func_0204755C(void *);
extern void func_0206E394(void *, int, int);
extern void func_0206E4FC(void *, int, int);
extern void func_0206E484(void *, int, int);
extern void func_0206E574(void *, int, int);
extern void func_0206E40C(void *, int, int);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02189A00(unsigned char *p);
extern u16 func_02011330(struct Stream *s);
extern void *func_0215A5F4(void *p);
extern int func_021C1CB0(int a, char *b, int c);
extern void func_0215897C(void *vm, void *task);
extern unsigned int func_02159B10(void *a, void *b);
extern int func_021C1D68(int a, int b, int c);
extern int func_021C30B8(void *a, unsigned char *b, unsigned int c);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02014204(struct t *p, int id);
extern void *func_02188C58(void *p);
extern u32 func_02188C5C(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021BB260(u32 a, u32 b);
extern void func_0218EC54(u8 *p);
extern void func_0218F818(u8 *a);
extern void func_0218F848(u8 *a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(u8 *a, VecFx32 *out);
extern void func_0218F900(u8 *a, void *p, int n);
extern int func_0218FE50(u8 *a);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 *func_0216D9E4(void *c);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0218F878(u8 *a);
extern u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021854CC(void *p, u32 u, u16 u2, void *src, u16 h);
extern u32 func_02188D20(u8 *p);
extern int func_021BC5BC(u8 *a);
extern u32 func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 planes);
extern void func_02188DB0(u8 *a);
extern void func_0216D5E0(int a0, int a1);
extern void func_021BC578(void *p, int v);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern void func_0218EC30(u32 a, u32 b);
extern void func_0218F05C(unsigned char *a);
extern void *func_020124E4(struct Obj *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(int a);
extern void func_021F36C0(char *p);
extern void func_020061E4(u32 id);
extern int func_021C87E0(char *p);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
void func_021C7FB4(u32 a);
void *func_021C7FBC(void **p);
void func_021C7FC0(M_021C7FC0 **pp, u32 flags, u32 heap);
void func_021C7FF0(void *msg);
void func_021C8000(u8 *p);
void func_021C800C(u8 *p);
N *func_021C8018(u32 heap);
int func_021C8054(void *a);
void func_021C8078(Obj *p, int b, int c);
int func_021C812C(int a, int b);
int func_021C8170(int a, int b);
int func_021C81B4(int a, int b);
int func_021C81F8(int a, int b);
int func_021C8268(void *a, int b, int c);
int func_021C82C4(u32 a, int *st, Ctx *c);
int func_021C85CC(void *task, int *state);
char *func_021C8608(void);
void func_021C8660(P *p);
int func_021C868C(int a, char *b);
void func_021C86E8(S *p, int b, int c);
int func_021C8738(char *p, int k);
extern char d_021DE520[];
extern unsigned short d_021DAAE0[];
extern unsigned short d_021DAAE2[];
extern char d_021DE534;
extern char d_00000024[];


/*
 * Tail-call thunk: forwards to func_021C800C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7FB4(u32 a)
{
    func_021C800C((u8 *)a);
}


/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the first word of its argument.
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
void *func_021C7FBC(void **p)
{
    return *p;
}

void func_021C7FC0(M_021C7FC0 **pp, u32 flags, u32 heap)
{
    if (flags & 3) {
        *pp = func_021C7DAC(heap);
        if (flags & 2)
            func_021C7E50((u8 *)(*pp), 2);
        else
            func_021C7E50((u8 *)(*pp), 0);
    } else {
        *pp = 0;
    }
}


/*
 * TwlDWC libdwcgsgp gpipeer.o: frees the buffer the message owns and clears
 * the message's pointer (gsifree is func_021C7DE0 here).
 */
void func_021C7FF0(void *msg)
{
    func_021C7DE0(*(void **)msg);
    *(u32 *)msg = 0;
}


/*
 * Tail-call thunk: forwards the object's first word to func_021C7DFC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C8000(u8 *p)
{
    func_021C7DFC(((struct Obj18331 *)p)->f0);
}


/*
 * Tail-call thunk: forwards the object's first word to func_021C7E30.
 *
 * Addresses are Black-image addresses.
 */
void func_021C800C(u8 *p)
{
    func_021C7E30(((struct Obj18332 *)p)->f0);
}

N *func_021C8018(u32 heap)
{
    N *n = func_02030734(heap, 8, 1, d_021DE520, 0x24);
    n->f0 = (u32)func_02046DB8(0x4a, 0);
    n->f4 = (u32)func_0204767C((u32)func_02047400((void *)n->f0, 0, 0), 0, 0);
    return n;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8054(void *a)
{
func_02047504((struct Rec *)func_02047788((int *)(((struct Obj09214 *)((u8 *)(a)))->f4)));
func_02047738((struct Rec *)(((struct Obj09214 *)((u8 *)(a)))->f4));
func_02046EFC((struct Tagged *)(((struct Obj09214 *)((u8 *)(a)))->f0));
return func_020307B0(a);
}


void func_021C8078(Obj *p, int b, int c)
{
    SRT srt;
    Cam cam;
    V v;
    int y;
    void *q;

    if (b == 0) {
        return;
    }
    func_02046AFC((u8 *)(&cam));
    srt.t = cam.pos;
    func_0207CA00(&cam.up, &cam.pos, &v);
    func_0207CCA4(&v, &v);
    y = v.y;
    if (y <= 0) {
        y = -y;
    }
    srt.s.x = b;
    srt.s.y = (int)(((long long)b * y + 0x800) >> 12);
    srt.s.z = 0x4000;
    func_02082B60((M43 *)func_0206AAD4(), &srt.r);
    q = func_0204755C((void *)func_02047788(p->f4))->f4;
    func_0206E394(q, 0, 0);
    func_0206E4FC(q, 0, 0);
    func_0206E484(q, 0, 2);
    func_0206E574(q, 0, c);
    func_0206E40C(q, 0, 0);
    func_02047A60(p->f4, (struct Arg *)(&srt));
}


int func_021C812C(int a, int b)
{
    void *r7;
    int r4, v;
    void *r5;
    void *r6;

    r5 = func_0215A5DC((void *)b);
    r7 = func_02189A00(func_0201210C(r5));
    r4 = func_02011330((struct Stream *)a);
    r6 = func_0215A5F4((void *)b);
    v = func_021C1CB0((int)r5, r7, (unsigned char)r4);
    if (v) {
        func_0215897C(r6, (void *)v);
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C8170(int a, int b)
{
    void *r7;
    int r5, v;
    void *r6;
    void *r4;

    r6 = func_0215A5DC((void *)b);
    r7 = func_02189A00(func_0201210C(r6));
    r5 = func_02159B10((void *)a, (void *)b);
    r4 = func_0215A5F4((void *)b);
    v = func_021C1D68((int)r6, (int)r7, (unsigned char)r5);
    if (v) {
        func_0215897C(r4, (void *)v);
    }
    return 1;
}


int func_021C81B4(int a, int b)
{
    void *r7;
    int r5, v;
    void *r6;
    void *r4;

    r6 = func_0215A5DC((void *)b);
    r7 = func_02189A00(func_0201210C(r6));
    r5 = (int)func_02159B10((void *)a, (void *)b);
    r4 = func_0215A5F4((void *)b);
    v = func_021C30B8(r6, r7, r5);
    if (v) {
        func_0215897C(r4, (void *)v);
    }
    return 1;
}


int func_021C81F8(int a, int b)
{
    void *sp4;
    void *sp0;
    int v, found, i;
    void *r5;
    unsigned short r4;

    sp4 = func_0215A5DC((void *)b);
    sp0 = func_02189A00(func_0201210C(sp4));
    v = (int)func_02159B10((void *)a, (void *)b);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (v == d_021DAAE0[i * 2]) {
            found = 1;
            r4 = d_021DAAE2[i * 2];
            break;
        }
    }
    if (found) {
        r5 = func_0215A5F4((void *)b);
        v = func_021C1CB0((int)sp4, sp0, (unsigned char)r4);
        if (v) {
            func_0215897C(r5, (void *)v);
        }
    }
    return 1;
}


int func_021C8268(void *a, int b, int c)
{
    int r7;
    int *r4;
    int v;

    r7 = (int)func_020122C0(a, 0, func_021C82C4, 0x30);
    r4 = func_020124E8((struct Obj *)r7);
    func_02082BCC(r4, 0, 0x30);
    r4[0] = (int)a;
    r4[2] = c;
    if (func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4((const struct Ctx *)a))) == 0) {
        r4[10] = 11;
        v = 12;
    } else {
        r4[10] = 18;
        v = 19;
    }
    r4[11] = v;
    func_02014204((struct t *)(r4 + 3), (unsigned short)c);
    return r7;
}


int func_021C82C4(u32 a, int *st, Ctx *c)
{
    void *sys;
    u32 h;
    void *y;
    u32 x;
    u32 v;
    void *o;
    void *t;
    Param p1;
    Param p2;
    VecFx32 v1;
    VecFx32 v2;
    Buf24 buf;

    sys = func_0201210C(c->w0);
    h = (u32)func_02188C58(sys);
    y = func_02189A00(sys);
    x = func_02188C5C(sys);
    switch (*st) {
    case 0:
        func_0218F1AC((u8 *)h, 0);
        c->f04 = func_0218EC5C((u8 *)h);
        func_0218F0A8((u8 *)h);
        (*st)++;
        break;
    case 1:
        if (c->f04 != 0 && func_0218F0E8((u8 *)h) != 0)
            break;
        func_021BB260(x, 0);
        func_0218EC54((u8 *)h);
        func_0218F818((u8 *)h);
        func_021A3038(func_02188CB4(sys), &v1);
        p1.h24 = 0x25d8;
        p1.h26 = 0;
        p1.f28 = 0xed000;
        p1.f18 = 0;
        p1.f1c = 0x4000;
        p1.f20 = 0;
        p1.pos = v1;
        p1.h2c = 0xe38;
        p1.buf.w[0] = 1;
        p1.buf.w[1] = 1;
        p1.buf.w[2] = 0;
        p1.buf.w[3] = 1;
        p1.buf.w[4] = 1;
        p1.buf.w[5] = 1;
        func_0218F900((u8 *)h, &p1, 10);
        (*st)++;
    case 2:
        if (func_0218FE50((u8 *)h) != 0)
            break;
        func_0216D9A0(func_02188C7C(sys));
        v = (u32)func_021C1CB0((u32)c->w0, y, (u8)c->f28);
        if (v != 0)
            func_02012374((struct Evt *)a, (struct Evt **)v);
        (*st)++;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(sys));
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        func_0218F878((u8 *)h);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BEA30((u32)c->w0, (u32)sys, 0, 0));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, (struct Evt **)func_021854CC(c->w0, (u32)sys, c->f08, c->f0c, 1));
        (*st)++;
        break;
    case 5:
        func_021BC5BC((u8 *)func_02188D20(sys));
        c->f04 = func_0218EC5C((u8 *)h);
        func_0218F0A8((u8 *)h);
        (*st)++;
        break;
    case 6:
        if (c->f04 != 0 && func_0218F0E8((u8 *)h) != 0)
            break;
        func_021BB260(x, 0);
        func_0218EC54((u8 *)h);
        func_0218F848((u8 *)h);
        func_0218F1AC((u8 *)h, 0);
        func_021A3038(func_02188CB4(sys), &v2);
        p2.h24 = 0x25d8;
        p2.h26 = 0;
        p2.f28 = 0xed000;
        p2.f18 = 0;
        p2.f1c = 0x4000;
        p2.f20 = 0;
        p2.pos = v2;
        p2.h2c = 0xe38;
        p2.buf.w[0] = 1;
        p2.buf.w[1] = 1;
        p2.buf.w[2] = 0;
        p2.buf.w[3] = 1;
        p2.buf.w[4] = 1;
        p2.buf.w[5] = 1;
        func_0218F900((u8 *)h, &p2, 1);
        (*st)++;
    case 7:
        if (func_0218FE50((u8 *)h) != 0)
            break;
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        t = (void *)func_02043658();
        func_02188DA0();
        func_02043534((u32)t);
        func_02188DB0(sys);
        (*st)++;
        break;
    case 8:
        func_0216D9A0(func_02188C7C(sys));
        v = (u32)func_021C1CB0((u32)c->w0, y, (u8)c->f2c);
        if (v != 0) {
            func_02012374((struct Evt *)a, (struct Evt **)v);
        } else {
            o = func_021A3074(func_02188CB4(sys));
            func_0216DAC8(o, 0);
            func_0216D5E0((u32)o, (u32)1);
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0(c->w0, (void *)a, func_021C85CC, 0));
        }
        (*st)++;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(sys));
        func_021BC578((void *)func_02188D20(sys), c->f08);
        buf.w[0] = 1;
        buf.w[1] = 1;
        buf.w[2] = 0;
        buf.w[3] = 1;
        buf.w[4] = 1;
        buf.w[5] = 1;
        func_0218F9C4((u8 *)h, (u8 *)(&buf), 10);
        (*st)++;
    case 10:
        if (func_0218FE50((u8 *)h) != 0)
            break;
        if (c->f04 != 0)
            func_0218EC30(h, c->f04);
        func_0218F05C((unsigned char *)h);
        func_021BB260(x, 1);
        func_0218F878((u8 *)h);
        func_0218F1AC((u8 *)h, 1);
        return 1;
    }
    return 0;
}

int func_021C85CC(void *task, int *state)
{
    func_0201210C(func_020124E4(task));
    switch (*state) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}


char *func_021C8608(void)
{
    char *p = func_02030734(5, 0x1b8, 1, &d_021DE534, 0x31);

    ((struct Obj03616 *)p)->f0 = 0;
    ((struct Obj03616 *)p)->f4 = 0;
    ((struct Obj03616 *)p)->f8 = 0;
    p[0x1b0] = 0;
    p[0x1b1] = 0;
    p[0x1b2] = 0;
    p[0x1b3] = 0;
    ((struct Obj03616 *)p)->f1B4 = 0;
    func_02034AC4((int)d_00000024);
    func_021F36C0(p);
    func_02034A5C((int)d_00000024);
    return p;
}

void func_021C8660(P *p)
{
    if (p != 0 && p->f1B4 == 0 && p->f0 != 0) {
        func_020061E4(0x6dd);
        p->f8++;
        p->f0 = 0;
    }
}


int func_021C868C(int a, char *b)
{
    int r4;
    int flag;
    int v;

    if (b == 0) {
        return 0;
    }
    if (((struct Obj07575 *)b)->f1B4 != 0) {
        return 0;
    }
    ((struct Obj07575 *)b)->f4 = ((struct Obj07575 *)b)->f4 + 1;
    v = func_021C87E0(b);
    switch (v) {
    case 1:
        ((struct Obj07575 *)b)->f0 = 1;
        flag = 0;
        break;
    case 2:
        r4 = (int)func_02158768(a, 1, 0, 0x8015);
        flag = 1;
        break;
    default:
        flag = 0;
        break;
    }
    if (flag == 0) {
        r4 = 0;
    }
    return r4;
}


/*
 * The sum is built in two statements (`r = f4 % 1350; r += b * 30;`) so
 * the multiply lands after the _s32_div_f call; one expression, or a
 * separate `t = b * 30` local, hoists it above the call into r4.
 * Addresses are Black-image addresses.
 */
void func_021C86E8(S *p, int b, int c)
{
    int r;

    r = p->f4 % 1350;
    r += b * 30;
    if (r >= 1350) {
        if (c) {
            p->f4 = (p->f8 + 1) * 1350 - 1;
        } else {
            p->f4 = (p->f8 + 1) * 1350;
            p->f8++;
        }
    } else {
        p->f4 += b * 30;
    }
}


int func_021C8738(char *p, int k)
{
    int r;
    int i;

    switch (k) {
    case 0:
        r = ((struct Obj06090 *)p)->f1B0;
        break;
    case 1:
        r = ((struct Obj06090 *)p)->f1B1;
        break;
    case 2:
        r = ((struct Obj06090 *)p)->f1B2;
        break;
    case 3:
        r = ((struct Obj06090 *)p)->f1B3;
        break;
    case 4:
        r = ((struct Obj06090 *)p)->f6;
        break;
    case 5:
        r = 0;
        for (i = 0; i < 15; i++) {
            if (*(int *)(p + i * 0x1c + 0x24) != 0) {
                r++;
            }
        }
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

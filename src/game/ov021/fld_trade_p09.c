/*
 * file:     fld_trade_p09.c
 * unit:     yes
 * function: func_021CD48C, func_021CD5A4, func_021CD60C
 * address:  0x021CD48C
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
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02008494  0x02008494  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_021CF164  0x021CF164  thumb  ov021
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 *   d_021DE5E8     0x021DE5E8  data   ov021  a1
 *   func_021CE760  0x021CE760  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Fx;
struct Obj2;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u8 f30[0x51B - 0x30];
    u8 f51B;
    u8 f51C;
    u8 f51D;
    u8 f51E;
    u8 f51F;
    u8 f520;
    u8 pad521[0x528 - 0x521];
    u16 f528;
    u8 pad52A[0x554 - 0x52A];
    u8 f554[0x572 - 0x554];
    signed char f572;
    u8 pad573;
    u16 f574;
    u8 pad576[0x580 - 0x576];
} Work;

typedef struct {
    u8 pad[0x26];
    u16 f26;
} Disp;

typedef struct {
    u8 pad[0x18];
    Disp *(*f18)(u32 a);
} Sys;

typedef struct {
    u8 pad000[0x488];
    void *f488;
    void *f48c;
    void *f490;
} Obj;

extern u32 func_02188C54(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int a, const char *file, u16 line);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_021904B0(u32 a, u32 b);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02008494(void *src, void *dst);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_0203D7BC(u8 a0);
extern void func_021CF164(u32 a);
extern void *func_0203D798(void);
extern u32 func_0203D650(void);
extern u32 func_021CE760(u8 *p);
extern void func_021CE81C(u32 *p);
extern int func_021909BC(void *a);
extern void func_02045808(struct U16Vec *vec);
extern int func_02190E40(u32 a);
extern u32 func_021904C8(struct Rec *a0);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_0203CD98(void);
extern void func_021CF17C(void);
extern u32 func_020307B0(void *p);
Work *func_021CD48C(u32 a0, u32 a1, u32 a2, u32 a3, u32 heap, u32 a5, u32 a6, void *a7);
u32 func_021CD5A4(u32 *p);
void func_021CD60C(Obj *p, void *a, void *b, void *c);
extern u8 d_021DE5E8[];


Work *func_021CD48C(u32 a0, u32 a1, u32 a2, u32 a3, u32 heap, u32 a5, u32 a6, void *a7)
{
    u32 t;
    Work *w;
    Sys *s;

    t = func_02188C54((u8 *)a1);
    w = func_02030734(heap, 0x580, 1, (const char *)d_021DE5E8, 0x179);
    w->f4 = (u32)func_0201EC64(heap);
    w->f8 = func_021904B0(t, 0x1e);
    w->f14 = (u32)func_02190F64((struct Fx *)t, w->f8);
    w->f18 = (u32)func_020457B0(0x64, heap);
    w->f1C = (u32)func_02045EC0((struct MsgBank *)w->f8, 7);
    w->f20 = (u32)func_020457B0(0x40, heap);
    if (a6 == 1) {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 3);
    } else {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 2);
    }
    w->f28 = (u32)func_020457B0(0x20, heap);
    w->f51C = a2;
    w->f51D = a3;
    w->f0 = a1;
    w->f51F = a5;
    w->f520 = a6;
    w->f528 = heap;
    w->f572 = -1;
    w->f574 = 0xffff;
    func_02008494((void *)a0, w->f30);
    if (a7 != 0) {
        func_02082D44(a7, w->f554, 6);
    }
    func_0203D7BC(0);
    func_021CF164((u32)w);
    if (a6 == 1) {
        w->f51B = 1;
    }
    s = func_0203D798();
    s->f18(func_0203D650())->f26 = 0x3a0b;
    return w;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021CD5A4(u32 *p)
{
    u32 r;

    r = func_021CE760((u8 *)p);
    func_021CE81C(p);
    if (p[0x4c]) {
        func_021909BC((void *)p[0x4c]);
        p[0x4c] = 0;
    }
    func_02045808((struct U16Vec *)p[10]);
    func_02045808((struct U16Vec *)p[9]);
    func_02045808((struct U16Vec *)p[8]);
    func_02045808((struct U16Vec *)p[7]);
    func_02045808((struct U16Vec *)p[6]);
    func_02190E40(p[5]);
    func_021904C8((struct Rec *)p[2]);
    func_0201ED04((struct WordSet *)p[1]);
    if (func_0203CD98() == 1) {
        func_021CF17C();
    }
    func_020307B0(p);
    return r;
}


void func_021CD60C(Obj *p, void *a, void *b, void *c)
{
    p->f488 = a;
    p->f48c = b;
    p->f490 = c;
}

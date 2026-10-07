/*
 * file:     eventdata_system_p34.c
 * unit:     yes
 * function: func_021641E8, func_021641F8, func_02164208, func_02164240, func_02164280, func_02164294, func_021642A4, func_021642B4, func_021642D4, func_021642F8, func_02164304, func_0216435C, func_02164380, func_021643AC, func_021643E8, func_02164454, func_0216445C, func_02164464, func_0216446C, func_02164474, func_0216447C, func_02164480, func_021644C4
 * address:  0x021641E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171480 0x02171480 data a4
 *   d_02171470 0x02171470 data a4
 *   d_021714B0     0x021714B0  data  a4
 *   d_02171458     0x02171458  data  a2
 *   d_02171460     0x02171460  data
 *   d_021714C0     0x021714C0  data  a4
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0201441C  0x0201441C  thumb
 *   func_0216D67C  0x0216D67C  thumb
 *   func_0216D4D4  0x0216D4D4  thumb
 *   func_0219E2C0  0x0219E2C0  thumb
 *   func_0216D684  0x0216D684  thumb
 *   func_0216D69C 0x0216D69C thumb ov010
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0215E428 0x0215E428 thumb ov010
 *   func_0215E3A0 0x0215E3A0 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_0201433C 0x0201433C thumb
 *   func_0215E33C 0x0215E33C thumb ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02013F6C  0x02013F6C  thumb
 *   func_02014464  0x02014464  thumb
 *   func_0215E364  0x0215E364  thumb ov010
 *   func_02164728  0x02164728  thumb ov010
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0215E34C  0x0215E34C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02028748  0x02028748  thumb
 *   func_02012B28  0x02012B28  thumb
 *   d_021714DC     0x021714DC  data
 */
#include "../../matched/include/Obj09310.h"
#include "../../matched/include/Obj05896.h"
#include "../../matched/include/Obj05897.h"

struct Big;
struct BigObj;
struct Sub02008828Obj;
struct Sub02014444Obj;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct Obj;
typedef signed short s16_02164240;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;

typedef short s16_02164304;

typedef struct {
    u16 a;
    u8 b;
    u8 c;
    s16_02164304 d;
    u16 e;
} Msg;

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

typedef int (*Handler)(void *sys, void *b, void *save);

extern u32 *func_0216D548(u32 *p, u32 v);
extern u8 func_0201441C(int i);
extern void *func_0216D67C(void *a0);
extern int func_0216D4D4(int a, int b);
extern void func_0219E2C0(int a, Msg *m);
extern void func_0216D684(int a, int b);
extern void *func_0216D69C(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *);
extern u16 func_02188C9C(u8 *p);
extern void func_0215E428(int a0, int a1);
extern void func_0215E3A0(void *);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0201433C(char *, int);
extern int func_0215E33C(int a0);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_02013F6C(u32 id);
extern void func_02014464(struct Sub02014444Obj *o, u8 v);
extern void  func_0215E364(void *a);
extern void  func_02164728(void *a);
extern u32 func_02013FFC(u32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);
extern int func_0215E34C(int a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02028748(struct Obj *obj, int n, int mask);
extern u32 func_02012B28(const struct Rec44 *p);
int func_021641E8(int a);
int func_021641F8(int a);
void func_02164208(int dir, int *p, int amt);
void func_02164240(int dir, s16_02164240 *x, s16_02164240 *z, s16_02164240 amt);
void func_02164280(int x, int y, int *p);
void func_02164294(int x, int y, int z, int *out);
u16 func_021642A4(int i);
u16 func_021642B4(int x0, int y0, int x1, int y1);
u8 func_021642D4(int i, int v);
void func_021642F8(void *a0);
void func_02164304(int a, u8 *p);
void func_0216435C(void *a, const u16 *b);
int func_02164380(void *a, u16 *b);
void func_021643AC(void *a, void *b);
void func_021643E8(void *a, void *b);
int func_02164454(int a, int b);
int func_0216445C(int a, int b);
int func_02164464(int a, int b);
int func_0216446C(int a, int b);
void func_02164474(int a, int b);
void func_0216447C(int sys, u16 id);
void func_02164480(Flags *f, void *a, void *b);
int func_021644C4(int i, void *a, void *b);
extern const int d_02171480[];
extern const int d_02171470[];
extern u32 d_021714B0[];
extern u16 d_02171458[];
extern u8 d_02171460[];
extern Quad d_021714C0[];
extern Handler d_021714DC[];

/*
 * contract: ROM table at 0x02171480 holds {0,0,-1,1}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641E8(int a) { return (short)*(const int *)((unsigned)d_02171480+((unsigned)a<<2)); }

/*
 * contract: ROM table at 0x02171470 holds {-1,1,0,0}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
int func_021641F8(int a) { return (short)*(const int *)((unsigned)d_02171470+((unsigned)a<<2)); }

void func_02164208(int dir, int *p, int amt)
{
    switch (dir) {
    case 0:
        p[2] -= amt;
        break;
    case 1:
        p[2] += amt;
        break;
    case 2:
        p[0] -= amt;
        break;
    case 3:
        p[0] += amt;
        break;
    }
}


/*
 * Unlabelled leaf (no lr save, prints as .word data): step one of two
 * halfword coordinates by amt in the direction dir (0 z-, 1 z+, 2 x-, 3 x+).
 * Halfword sibling of the word version func_02164208.  Filed as the sole
 * blocker of ov021 func_021A40A8.
 */
void func_02164240(int dir, s16_02164240 *x, s16_02164240 *z, s16_02164240 amt)
{
    switch (dir) {
    case 0:
        z[0] -= amt;
        break;
    case 1:
        z[0] += amt;
        break;
    case 2:
        x[0] -= amt;
        break;
    case 3:
        x[0] += amt;
        break;
    }
}

void func_02164280(int x, int y, int *p)
{
    p[0] = (x << 16) + 0x8000;
    p[2] = (y << 16) + 0x8000;
}


/*
 * Unlabelled leaf, blocker of ov021 func_0218B4B0: widens three integers to 16.16 fixed point.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02164294(int x, int y, int z, int *out)
{
    out[0] = x << 16;
    out[1] = y << 16;
    out[2] = z << 16;
}


/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219A7DC and func_0219A8C0: returns
 * the low halfword of word i of a table.
 */
u16 func_021642A4(int i)
{
    return d_021714B0[i];
}


/*
 * Unlabelled leaf (word run in the listing), blocker of func_0219B13C and
 * func_0219BA6C (ov021).  Direction code 0..3 from a point pair.
 */
u16 func_021642B4(int x0, int y0, int x1, int y1)
{
    int r;

    if (x0 > x1) {
        return 2;
    }
    if (x0 < x1) {
        return 3;
    }
    r = 1;
    if (y0 > y1) {
        r = 0;
    }
    return r;
}


/*
 * Unlabelled leaf, blocker of ov021 func_0219FFD4: three chained table lookups.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 func_021642D4(int i, int v)
{
    u32 s = (u16)(v + d_02171458[i]);

    return d_021714C0[d_02171460[s >> 12]].b;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D548, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021642F8.c \
 *       --func func_021642F8 --addr 0x021642F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021642F8(void *a0)
{

    func_0216D548(a0, 8192);
}


void func_02164304(int a, u8 *p)
{
    Msg m;
    u16 *q;

    m.a = ((struct Obj09310 *)p)->f1C;
    m.b = 1;
    q = (u16 *)(p + 0x1c);
    m.c = func_0201441C(((struct Obj09310 *)p)->fC);
    m.e = q[1];
    m.d = ((s16_02164304 *)q)[2];
    if (func_0216D4D4((int)func_0216D67C((void *)a), 0x10) != 0) {
        func_0219E2C0(a, &m);
        return;
    }
    func_0216D684(a, 0xc);
    func_0216435C((void *)a, (const u16 *)(&m));
}

void func_0216435C(void *a, const u16 *b) { u16 *p=func_0216D69C(a); p[2]=b[0]; p[3]=b[1]; p[4]=b[2]; p[5]=b[3]; ((struct Obj05896 *)p)->f0=0xEFEFEFEF; }

/*
 * contract: setter func_0216435C writes the four payload halfwords
 * at +4,+6,+8,+10 before publishing 0xEFEFEFEF at +0;
 * this reader loads those halfwords only after the sentinel comparison.
 */
int func_02164380(void *a, u16 *b) { u16 *p=func_0216D69C(a); if (((struct Obj05897 *)p)->f0==0xEFEFEFEF) { b[0]=p[2]; b[1]=p[3]; b[2]=p[4]; b[3]=p[5]; return 1; } return 0; }

/*
 * interface: func_02188C9C reads the u16 field at +0xD8;
 * func_0215E428 forwards its second argument to func_0200D45C,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy ov010_func_021643E8 declaration uses a pointer for this ID.
 */
void func_021643AC(void *a, void *b) { void *p=func_0200D418(func_02012EBC(a)); func_0215E428((int)p,func_02188C9C(b)); func_0215E3A0(a); func_0201433C((char *)func_0201296C(a),0x964); func_0215E33C((int)b); }


/*
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * Addresses are Black-image addresses.
 */
void func_021643E8(void *a, void *b)
{
    void *w = func_02012B38(a);
    void *c;
    if ((func_02013F6C((u32)b) & 3) == 0) {
        func_02014464(w, 0);
    }
    func_0215E428((int)func_0200D418(func_02012EBC(a)), (int)b);
    func_0215E364(a);
    c = (void *)func_0201296C(a);
    func_0201433C(c, 0x964);
    func_02164728(c);
    if (func_02013FFC((u32)b) == 0) {
        func_02008988(func_02008854(func_02012EBC(a)), 0);
    }
}


/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 1 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164454(int a, int b)
{
    return func_0215E34C(a);
}


/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 3 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216445C(int a, int b)
{
    return func_0215E34C(a);
}


/*
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 2 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_02164464(int a, int b)
{
    return func_0215E34C(a);
}


/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */
int func_0216446C(int a, int b)
{
    return func_0215E34C(a);
}


/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_02183DE4.
 */
void func_02164474(int a, int b)
{
    func_0215E364((void *)a);
}


/*
 * Empty function after the veneer run; the only Thumb code at this address
 * in any overlay window, called from ov021 func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_0216447C(int sys, u16 id)
{
}


void func_02164480(Flags *f, void *a, void *b)
{
    void *save;
    int i;

    save = func_020127A4(func_020120F4(a));
    MI_CpuFill8(f, 0, sizeof(Flags));
    for (i = 0; i < 10; i++)
        func_02028748((struct Obj *)f, i, func_021644C4(i, a, b));
    f->f04 = func_02012B28(save);
}


/*
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 */
int func_021644C4(int i, void *a, void *b)
{
    void *sys;
    void *save;
    Handler fn;

    sys = func_020120F4(a);
    save = func_020127A4(sys);
    fn = d_021714DC[i];
    if (fn == 0)
        return 1;
    return fn(sys, b, save);
}

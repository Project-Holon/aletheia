/*
 * file:     unit_020746C4.c
 * unit:     yes
 * function: func_020746C4, func_020746D0, func_020746DC, func_020746E8, func_02074758, func_02074770, func_0207482C, func_02074894, func_020748E0, func_020749B4, func_020749C4, func_020749F8, func_02074A34, DWCi_IsShutdownMatch, func_02074A6C, func_02074A98, func_02074AC4, func_02074AE8, func_02074BEC, func_02074C70, func_02074CD0, func_02074E10, func_02074E9C, func_02074F3C, func_02074FA8, func_02075014, func_02075080, func_020750EC, func_020751F4, func_0207524C, func_02075274, func_020752A4, func_020752D4, func_020752F4, func_0207533C, func_02075404, func_020754C4
 * address:  0x020746C4
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020610E0  0x020610E0  arm
 *   func_02061118  0x02061118  arm
 *   func_0206062C  0x0206062C  arm
 *   func_020605B4  0x020605B4  arm
 *   func_02061158  0x02061158  arm
 *   func_02061184  0x02061184  arm
 *   func_020611D4  0x020611D4  arm
 *   func_02060468  0x02060468  arm
 *   func_02061124  0x02061124  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 *   func_02074518  0x02074518  arm
 *   func_02074324  0x02074324  arm
 *   func_0207466C  0x0207466C  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074450  0x02074450  arm
 *   func_0208A2BC  0x0208A2BC  arm
 *   func_0207457C  0x0207457C  arm
 *   func_020745A4  0x020745A4  arm
 *   DC_StoreRange  0x020862D4  arm
 *   func_020742FC  0x020742FC  arm
 *   func_02074694  0x02074694  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_0214EA54     0x0214EA54  data  a4
 *   d_0214EA54_hdr 0x0214EA54  data  a4
 *   func_020896AC    0x020896AC  arm
 *   func_020896CC    0x020896CC  arm
 *   func_0208A38C    0x0208A38C  arm
 *   func_0208A638  0x0208A638  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *   func_0208A46C  0x0208A46C  arm
 *   func_0208A48C  0x0208A48C  arm
 *   func_020744B4  0x020744B4  arm
 *   func_02072DB0  0x02072DB0  arm
 *   func_02072DD0  0x02072DD0  arm
 *   func_02072DE8  0x02072DE8  arm
 */
#include "../../matched/include/Obj07066.h"
#include "../../matched/include/Obj08948.h"
#include "../../matched/include/Obj11687.h"

struct Table_020746C4;
struct Obj_020746C4;
struct DList;
struct H;
struct NNSiFndHeapHead;
struct Global;
struct SNDBankData;
struct SNDWaveArc;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Arc { u8 pad_00[0x88]; u32 f88; u32 f8c; u32 f90; };

struct Node {
    u8  pad00[8];
    u32 f08;
    u32 f0c;   /* callback */
    u32 f10;
    u32 f14;
};

struct Obj_020746C4 { u32 f00; u8 list[4]; };

typedef unsigned short u16;

typedef signed   int   s32;

typedef struct S {
    u32  f00;        /* 0x00 -- owner/key word */
    char pad_04[8];
    u16  f0c;        /* 0x0c -- slot count */
} S;

struct Obj_02074894  { u32 f00; u8 list[8]; u16 f0c; };

struct Table_020746C4 {
    void *heap;
    char list[0x1c];
};

typedef int BOOL;

struct Entry { u8 kind; u8 b1; u16 h2; u32 f4; };

struct Table_02074A6C { u32 count; struct Entry entries[1]; };

typedef struct { u32 f0; u16 slot[4]; } Grp;

union Hdr {
    unsigned w;
    struct { unsigned v : 24; unsigned flag : 1; unsigned rest : 7; } b;
};

struct ArcHdr {
    u32 pad[0xe];
    u32 count;                  /* +0x38 entries in the offset table   */
    u32 off[1];                 /* +0x3c the table, count words        */
};

typedef struct {
    u32 pad00[2];
    u32 f08;
    u32 pad0c[(0x38 - 0x0c) / 4];
    u32 f38;
    u32 f3c[1];
} Bank;

typedef struct { u32 a; u32 b; } Iter;

typedef struct { u8 kind; u8 p1; u16 h2; u16 h4; u16 h6; u32 w8; } Rec;

typedef struct {
    u8  count;
    u8  pad01;
    u16 h2;
    void *data;
} Ent;

extern void *func_020610E0(void *mem, u32 size, u32 opt);
extern void  func_02061118(void *p);
extern void *func_0206062C(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_02061158(void *p, int flags);
extern unsigned int func_02061124(char *p, int n, int v);
extern void func_020604AC(u32, u32);
extern int func_02061184(struct H *h, u32 a1);
extern int func_020611D4(struct NNSiFndHeapHead *heap, u32 tagName);
extern void func_02060468(int p0, int p1);
extern u32 func_02089D40(void);
extern void func_02089B38(u32 a0);
extern void func_02089CD4(u32 tag);
extern void *func_02074518(int index);
extern void *func_02074324(int index);
extern u32  func_0207466C(u32 a);
extern void *func_02074388(int index);
extern void *func_020743EC(int index);
extern void *func_02074450(int index);
extern void  func_0208A2BC(u32 bank, u32 i, u32 waveArc);
extern u32   func_0207457C(u32 a);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void  DC_StoreRange(void *addr, u32 size);
extern struct Global *func_020742FC(void);
extern void func_02074694(u32, u32);
extern void  MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern struct Global *func_020742E4(struct Global *val);
extern void func_020896AC(const void *start, const void *end);
extern void func_020896CC(const void *start, const void *end);
extern void func_0208A38C(struct SNDBankData *bank);
extern void func_020896EC(const void *start, const void *end);
extern void func_0208A424(struct SNDWaveArc *waveArc);
extern u32 func_0208A674(u32, u32);
extern void func_0208A640(u32, u32, u32);
extern void *func_0208A638(char *p);
extern void func_0208A46C(Iter *it, u32 a, u32 b, u32 c);
extern u32  func_0208A48C(u32 seq, Rec *r, Iter *it);
extern void *func_020744B4(int index);
extern void  func_02072DB0(int idx, int v);
extern void func_02072DD0(u32 idx, u32 val);
extern u32   func_02072DE8(int idx, u32 a, void *src);
void func_020746C4(void *payload, u32 size, struct Arc *c);
void func_020746D0(void *payload, u32 size, struct Arc *c);
void func_020746DC(void *payload, u32 size, struct Arc *c);
u32 func_020746E8(u32 off, u32 size);
void func_02074758(void **a0);
void func_02074770(struct Obj_020746C4 *o);
u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
s32 func_02074894(S *p);
void func_020748E0(struct Obj_02074894 *o, s32 k);
void func_020749B4(void *node);
int func_020749C4(struct Table_020746C4 *t, void *heap);
int func_020749F8(struct Table_020746C4 *t);
void func_02074A34(void);
BOOL DWCi_IsShutdownMatch(void);
u32 func_02074A6C(u32 a, u32 b);
u32 func_02074A98(u32 a, u32 b);
u32 func_02074AC4(u32 a, u32 b, u32 c);
u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);
u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out);
u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out);
u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out);
void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out);
u32 func_02074F3C(u32 a, u32 b, u32 c);
u32 func_02074FA8(u32 a, u32 b, u32 c);
u32 func_02075014(u32 a, u32 b, u32 c);
u32 func_02075080(u32 a, u32 b, u32 c);
u32 func_020750EC(u32 idx, u32 *heap, int flag);
void func_020751F4(u32 a, u32 b, u32 c);
void func_0207524C(u8 *p, u32 len, u32 b, u32 c);
void func_02075274(u8 *p, u32 len, u32 b, u32 c);
void func_020752A4(int a, int b, int c, int d);
void func_020752D4(int a, int b, int c, int d);
void func_020752F4(u32 a, u32 n, u32 x, u32 y);
u32 func_0207533C(Bank *o, u32 i, u32 h, u32 *heap);
u32 func_02075404(u32 o, u32 seq, u32 want, u32 h, u32 *heap);
u32 func_020754C4(u32 a);
extern struct ArcHdr d_0214EA54;
extern struct ArcHdr d_0214EA54_hdr;














/*
 * Release callback func_02074048 registers with func_0207482C for the
 * allocation it stores at Arc +0x90: the request drain (func_02074770 /
 * func_020748E0) invokes it as cb(node + 0x20, f08, f10, f14) with f10 the
 * Arc object, and it forgets the pointer.  One of three 12-byte unlabelled
 * leaves disasm.py prints as .word data after pool_020746C0.
 */
void func_020746C4(void *payload, u32 size, struct Arc *c)
{
    c->f90 = 0;
}














/*
 * Release callback func_02074048 registers with func_0207482C for the
 * allocation it stores at Arc +0x88: the request drain (func_02074770 /
 * func_020748E0) invokes it as cb(node + 0x20, f08, f10, f14) with f10 the
 * Arc object, and it forgets the pointer.  One of three 12-byte unlabelled
 * leaves disasm.py prints as .word data after pool_020746C0.
 */
void func_020746D0(void *payload, u32 size, struct Arc *c)
{
    c->f88 = 0;
}














/*
 * Release callback func_02074048 registers with func_0207482C for the
 * allocation it stores at Arc +0x8c: the request drain (func_02074770 /
 * func_020748E0) invokes it as cb(node + 0x20, f08, f10, f14) with f10 the
 * Arc object, and it forgets the pointer.  One of three 12-byte unlabelled
 * leaves disasm.py prints as .word data after pool_020746C0.
 */
void func_020746DC(void *payload, u32 size, struct Arc *c)
{
    c->f8c = 0;
}














/*
 * Carves one sub-allocation out of an (offset, size) window: round the offset
 * up to four, refuse the window if the rounded offset already ran past its end
 * or if fewer than 0x10 bytes remain, then allocate through func_020610E0 with
 * a 0x10-byte header reserved and register the block with func_020749C4. A
 * failed registration frees the block again and answers 0; success answers the
 * aligned offset.
 *
 * PINNED ../2.0/sp2, the pin five cluster siblings carry (func_020737C0,
 * func_02073AD0, func_02073B3C, func_02073CA0, func_02074894).
 * docs/notes/pkt_020746E8.c.txt recorded this body as 116 bytes against 112
 * with 77 concrete bytes out under dsi/1.1p1, which pools the constant 0 into
 * a callee-saved register and shifts every subsequent register by one
 * (docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md).
 * Under the pin the note's own C is size-exact at 112 bytes with only 8 bytes
 * out, and no register substitution at all -- one swapped instruction pair at
 * +0008.
 *
 * The last 8 bytes came from tools/permuter.py (hill, 200 compiles): the
 * mutation `temp(tmp = off + size)` closes it. Written out, that is simply
 * computing the window end BEFORE the rounded start, which is the order the
 * original source declared them in; writing `aligned` first makes mwcc emit
 * the `bic` before the `add`.
 *
 * The note's third finding, that func_020610E0 has no branch witness outside
 * this range, no longer caps the file: the 2026-09-21 sole-ref/code widening
 * attests it at its own function start.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020746E8.c \
 *       --func func_020746E8 --addr 0x020746E8 --cc ../2.0/sp2 --arm
 */
u32 func_020746E8(u32 off, u32 size)
{
    u32 end;
    u32 aligned;
    u32 rest;
    void *p;

    end     = off + size;
    aligned = (off + 3) & ~3u;

    if (aligned > end) return 0;
    rest = end - aligned;
    if (rest < 0x10) return 0;

    p = func_020610E0((void *)(aligned + 0x10), rest - 0x10, 0);
    if (p == 0) return 0;
    if (func_020749C4((struct Table_020746C4 *)aligned, p) != 0) return aligned;

    func_02061118(p);
    return 0;
}













void func_02074758(void **a0)
{
    func_02074770((struct Obj_020746C4 *)a0);
    func_02061118(*a0);
}












void func_02074770(struct Obj_020746C4 *o)
{
    void *a;
    u32 any;
    struct Node *n;

    any = 0;
    a = func_0206062C((struct DList *)o->list, 0);
    while (a != 0) {
        n = (struct Node *)func_0206062C(a, 0);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)func_0206062C(a, n);
        }
        func_020605B4((volatile struct DList *)o->list, a);
        a = func_0206062C((struct DList *)o->list, 0);
    }

    func_02061158((void *)o->f00, 3);
    if (any != 0) func_02074A34();
    func_020749F8((struct Table_020746C4 *)o);
}











u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e) {
    u32 t;
    u32 r = func_02061124((char *)(*a), ((b + 0x1f) & ~0x1fu) + 0x20, 0x20);
    if (r == 0) return 0;
    t = (u32)func_0206062C((struct DList *)(a + 1), 0);
    ((struct Obj07066 *)r)->f8 = b;
    ((struct Obj07066 *)r)->fC = c;
    ((struct Obj07066 *)r)->f10 = d;
    ((struct Obj07066 *)r)->f14 = e;
    func_020604AC(t, r);
    return r + 0x20;
}










/*
 * The close path for one handle: func_02061184 decides whether the key is
 * still live (0 when not), func_020749F8 reports drain progress (the caller
 * gets remaining count - 1 when it advanced), and only when the drain is
 * complete does func_020611D4 unlink the key, after which the call still
 * answers -1.
 *
 * PINNED ../2.0/sp2, the same pin three cluster siblings carry
 * (func_02073AD0, func_02073B3C, func_02073CA0). docs/notes/func_02074894.c.txt
 * recorded this exact C as a 30-byte DIFF (76 vs 80) under dsi/1.1p1 and listed
 * six rejected respellings of the tail. The residue was never in the C: 1.1p1
 * shares the constant 0 between func_020611D4's second argument and the `-1`
 * return, parking it in a callee-saved register (`mov r4,#0` ... `sub r0,r4,#1`)
 * and widening the prologue by a push slot, where the image rematerialises
 * `mov r1,#0` and `mvn r0,#0`. That is the repeated-small-constant tell of
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md.
 * Under the pin the note's own C is 76 bytes, 0 concrete mismatches.
 *
 * All three call sites resolve by `label`, so nothing further was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074894.c \
 *       --func func_02074894 --addr 0x02074894 --cc ../2.0/sp2 --arm
 */
s32 func_02074894(S *p)
{
    if (func_02061184((struct H *)p->f00, p->f0c) == 0) {
        return -1;
    }
    if (func_020749F8((struct Table_020746C4 *)p) != 0) {
        return p->f0c - 1;
    }
    func_020611D4((void *)p->f00, 0);
    return -1;
}










/*
 * Bounded sibling of func_02074770: drains request lists while the key k is
 * below the live count at +0x0C (k == 0 forwards to func_02074770), then
 * func_020611D4(f00, k), func_02074A34 once if any callback ran,
 * func_02061184(f00, f0c) and func_020749F8((struct Table_020746C4 *)o).
 *
 * Two levers closed the 19-byte floor of docs/notes/pkt_02074894.c.txt:
 *  1. The null cursor of each outer iteration's SECOND func_0206062C is the
 *     node cursor n itself (n = 0 at entry and 0 again whenever the inner walk
 *     ends), not a literal 0.  That is the image's `mov r1, r8` with r8 = n,
 *     and it is what lets one zero serve n, any and the head cursor.
 *  2. Declaration order a, any, n (a in r6, any in r7), per
 *     docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 */
void func_020748E0(struct Obj_02074894 *o, s32 k)
{
    void *a;
    u32 any;
    struct Node *n;

    n   = 0;
    any = 0;
    if (k == 0) { func_02074770((struct Obj_020746C4 *)o); return; }

    while (k < o->f0c) {
        a = func_0206062C((struct DList *)o->list, 0);
        n = (struct Node *)func_0206062C((struct DList *)a, n);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)
                    ((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)func_0206062C((struct DList *)a, n);
        }
        func_020605B4((volatile struct DList *)o->list, a);
    }

    func_020611D4((struct NNSiFndHeapHead *)o->f00, k);
    if (any != 0) func_02074A34();
    func_02061184((struct H *)o->f00, o->f0c);
    func_020749F8((struct Table_020746C4 *)o);
}









/*
 * A whole translation unit, matched as one byte range.
 */
void func_020749B4(void *node)
{
    func_02060468((int)node, 0);
}









int func_020749C4(struct Table_020746C4 *t, void *heap)
{
    func_02060468((int)(&t->list), 0xc);
    t->heap = heap;
    if (func_020749F8((struct Table_020746C4 *)t)) {
        return 1;
    }
    return 0;
}









int func_020749F8(struct Table_020746C4 *t)
{
    void *node = (void *)func_02061124(t->heap, 0x14, 4);
    if (!node) {
        return 0;
    }
    func_020749B4(node);
    func_020604AC((u32)(&t->list), (u32)node);
    return 1;
}









void func_02074A34(void)
{
    void *p = (void *)func_02089D40();
    func_02089B38(1);
    func_02089CD4((u32)p);
}









BOOL DWCi_IsShutdownMatch(void)
{
    return func_02074AE8() == 0;
}








/*
 * One-line wrapper: call the byte-stream reader over a 0xff mask and invert
 * the result.
 *
 * PER-FILE PIN (../2.0/sp2), and the byte evidence for it: this is the
 * "kept constants" tell of docs/FRONTEND-PINS.md, measured on 2026-09-19.
 * The image materialises the fourth and fifth arguments at the call and
 * rebuilds the boolean from immediates:
 *
 *   push {r3, lr} / mov r2, r1 / mov ip, #0 / mov r1, #0xff / mov r3, #1 /
 *   str ip, [sp] / bl ... / cmp r0, #0 / moveq r0, #1 / movne r0, #0
 *
 * `dsi/1.1p1 -O4,p -proc arm946e` instead keeps the same two constants live
 * in callee-saved r4/r5 across the call (push {r3, r4, r5, lr} / mov r5, #1 /
 * mov r4, #0 / ... / movne r5, r4 / mov r0, r5): 48 bytes, 35 differing.
 * `../2.0/sp2 -O4,p -proc arm946e` gives the image's 44 bytes byte for byte,
 * so the bytes themselves name the front end.  The pin needs a row in
 * docs/FRONTEND-PINS.md; that file is outside this lane's write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074A6C.c \
 *       --func func_02074A6C --addr 0x02074A6C --arm --cc ../2.0/sp2
 */
u32 func_02074A6C(u32 a, u32 b)
{
    return func_02074BEC(a, 0xff, b, 1, 0) == 0;
}








/*
 * Sibling of func_02074A6C: the identical wrapper over the other byte-stream
 * reader in the same unit.
 *
 * PER-FILE PIN (../2.0/sp2), same byte evidence and same tell as
 * func_02074A6C (docs/FRONTEND-PINS.md, "kept constants"): the image
 * materialises 0xff / 1 / 0 at the call and the boolean from immediates
 * (44 bytes), `dsi/1.1p1` keeps 1 and 0 live in callee-saved r4/r5 and needs
 * 48 bytes (35 differing), `../2.0/sp2` reproduces the image exactly.
 * Needs a row in docs/FRONTEND-PINS.md; that file is outside this lane's
 * write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074A98.c \
 *       --func func_02074A98 --addr 0x02074A98 --arm --cc ../2.0/sp2
 */
u32 func_02074A98(u32 a, u32 b)
{
    return func_02074E10(a, 0xff, b, 1, 0) == 0;
}








/*
 * Three-argument sibling of src/matched/func_02074A6C.c / func_02074A98.c:
 * forward a, b, c to the byte-stream reader with d=1, out=0, and invert the
 * result.  Same "kept constants" tell and the same ../2.0/sp2 pin as both of
 * those; docs/FRONTEND-PINS.md's closing paragraph names this very address as
 * the unmeasured 36-byte member of the family.  Measured here: the image is
 * `push {r3, lr} / mov ip, #0 / mov r3, #1 / str ip, [sp] / bl ... /
 * cmp r0, #0 / moveq r0, #1 / movne r0, #0`, 36 bytes; 1.1p1 -O4,p keeps the
 * two constants live in callee-saved r4/r5 across the call and emits
 * `push {r3, r4, r5, lr}` for 40 bytes.  Under the pin: 36 bytes, 0 mismatches.
 */
u32 func_02074AC4(u32 a, u32 b, u32 c)
{
    return func_02074BEC(a, b, c, 1, 0) == 0;
}








/*
 * Event-list walker: look the list up by index, then run each 8-byte entry
 * {u8 kind; u8 b1; u16; u32 f4} through one of four handlers chosen by a dense
 * 4-way switch, returning the first non-zero handler result.  A null list is 1.
 *
 * Three levers, all measured:
 *  - SOURCE ORDER OF THE ARMS IS 0, 3, 1, 2, read straight off the branch
 *    table at 0x02074B34..0x02074B40 (case 0 -> 0x02074B44, case 1 ->
 *    0x02074B8C, case 2 -> 0x02074BB0, case 3 -> 0x02074B68); the emitted arms
 *    run in source order, so the second body in the file is case 3.  The
 *    handlers are 0 -> BEC, 3 -> C70, 1 -> CD0, 2 -> E10.
 *  - The arms return the HANDLER'S OWN RESULT (`r = f(..); if (r) return r;`),
 *    not a literal 1: the image pops straight out of each arm with no `mov r0`.
 *    Writing `return 1` costs 16 bytes and a shared `mov r0, r4` tail.
 *  - The empty-count exit must share the function's LAST epilogue, so the loop
 *    is `if (i < t->count) { do { .. } while (i < t->count); }` with `i = 0`
 *    assigned FIRST.  A `while` head hoists `add r8, r6, #4` above the compare
 *    (12 bytes out) and `t->count != 0` / `> 0` both fold the guard to `beq`
 *    where the image has `bls` (1 byte out); only the `i < t->count` spelling,
 *    with i provably zero, keeps the unsigned form.
 *  - Declaration order `u32 i;` before `struct Entry *e;` is what puts the
 *    counter in r7 and the cursor in r8; reversed, they swap.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The fifth
 * argument is a literal 0 at all four call sites and the image materialises it
 * FOUR separate times, `mov fp, r7` / `mov sl, r7` / `mov r4, r7` / `mov r5, r7`
 * at 0x02074B2C..0x02074B38 off the counter's own zero, one dedicated register
 * per arm, which is what forces the ten-register `push {r3, r4, r5, r6, r7, r8,
 * sb, sl, fp, lr}` (`f8 4f 2d e9`).  1.1p1 -O4,p CSEs all four into a single
 * `mov r5, #0` and shares the `1` of the fourth argument into r4 as well,
 * dropping sl and fp entirely for an eight-register `push {r3, r4, r5, r6, r7,
 * r8, sb, lr}` and 256 bytes against the original's 260.  Under the pin the
 * same C is 260 bytes, 0 mismatches.
 */
int func_02074AE8(u32 index, u32 arg)
{
    struct Table_02074A6C *t;
    u32 i;
    struct Entry *e;
    u32 r;

    t = func_02074518(index);
    if (t == 0) {
        return 1;
    }
    i = 0;
    if (i < t->count) {
        e = t->entries;
        do {
        switch (e->kind) {
        case 0:
            r = func_02074BEC(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 3:
            r = func_02074C70(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 1:
            r = func_02074CD0(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            r = func_02074E10(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        }
            i++;
            e++;
        } while (i < t->count);
    }
    return 0;
}








u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u8 *p = func_02074324(a);
    u32 r;

    if (p == 0) return 2;
    r = func_02074CD0(((struct Obj08948 *)p)->f4, b, c, d, 0);
    if (r != 0) return r;
    if (b & 1) {
        r = func_02074F3C(((struct Obj08948 *)p)->f0, c, d);
        if (r == 0) return 6;
    } else {
        r = func_0207466C(((struct Obj08948 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}







u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out) {
    void *p = func_02074388(a);
    u32 r;
    if (p == 0) return 3;
    if (b & 8) {
        r = func_02074FA8(((struct Obj11687 *)p)->f0, c, d);
        if (r == 0) return 7;
    } else {
        r = func_0207466C(((struct Obj11687 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}








/*
 * The third kind dispatcher: look up the group (error 4), load or look up its
 * bank (flag bit 2; error 8), then for each of the group's four halfword slots
 * that is not 0xffff resolve the entry (error 5), load its wave through
 * func_02074E10 (its own error code is returned as is), bind the sequence's
 * banks through func_02075404 when header bit 24 and flag bit 4 are both set
 * (error 9), and finally assign the loaded wave archive to the bank slot.
 *
 * THE LAST LEVER (wave 12, from 2 bytes out): func_0208A2BC takes THREE
 * arguments, not two.  Its own prologue saves r0, r1 AND r2 (`mov r4, r2` at
 * 0x0208A2C8), which is the SDK's SND_AssignWaveArc(bank, index, waveArc)
 * shape.  The image's `ldrne r2, [sp, #4]` at 0x02074DD0 was never a
 * scratch register choice: it loads `sub` straight into the third argument
 * register for the call, and the `cmpne r2, #0` guard reads it from there.
 * Every other lever (the union header, one-argument func_02074450, the
 * func_02074E10 result returned as is, the int counter, the ../2.0/sp2 pin)
 * is documented in docs/notes/pkt_02074CD0.c.txt.
 *
 * With the three-argument callee the body is byte-exact under the project
 * default dsi/1.1p1 AND under ../2.0/sp2 / ../2.0/sp2p2 (all three checked),
 * so no front-end pin is recorded: the two-argument prototype was what made
 * 1.1p1 look wrong in the earlier notes.
 */
u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out)
{
    Grp *g;
    union Hdr *o;
    u32 bank;
    int i;
    u32 want;
    u32 sub;
    u32 r;

    g = func_020743EC(a);
    if (g == 0) return 4;

    if (flags & 2) {
        bank = func_02075014(g->f0, c, d);
        if (bank == 0) return 8;
    } else {
        bank = func_0207466C(g->f0);
    }

    want = flags & 4;
    for (i = 0; i < 4; i++) {
        if (g->slot[i] != 0xffff) {
            o = func_02074450(g->slot[i]);
            if (o == 0) return 5;
            r = func_02074E10(g->slot[i], flags, c, d, &sub);
            if (r != 0) return r;
            if ((o->w >> 24) & 1 && want != 0) {
                if (func_02075404(sub, bank, (u32)i, o->b.v, (u32 *)c) == 0) return 9;
            }
            if (bank != 0 && sub != 0) {
                func_0208A2BC(bank, (u32)i, sub);
            }
        }
    }
    if (out != 0) *out = bank;
    return 0;
}






/*
 * The 0x02074BEC/0x02074C70 sibling for the third handler slot: resolve the
 * object (func_02074450), read its 32-bit header word, and dispatch on the
 * caller's flag bits.  With flag bit 2 set the 24-bit low field of the header
 * is handed to one of two loaders chosen by header bit 24, and a zero result
 * is the error code 9; without it the field goes to the plain lookup
 * func_0207466C and no error check applies (the image's `bl 0x207466c` at
 * 0x02074E84 lands at 0x02074E88, PAST the `cmp r0,#0` / `mov r0,#9`).
 *
 * TWO LEVERS, both required and both previously measured against the wrong
 * front end in docs/notes/pkt_02074CD0.c.txt / docs/notes/pkt_0207533C.c.txt:
 *
 *  - THE HEADER IS READ THROUGH TWO VIEWS OF ONE WORD, so it must be a UNION.
 *    The value is a 24-bit BITFIELD (`o->b.v`): that and only that emits the
 *    image's `lsl r0,r0,#8` / `lsr r0,r0,#8` pair straddling the branch at
 *    0x02074E44/0x02074E54, per
 *    docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md; spelling it
 *    `(w << 8) >> 8` folds to `bic r0, r0, #0xff000000`.  The FLAG is a plain
 *    word read `(o->w >> 24) & 1`, which is the image's `lsr r1,r0,#0x18` /
 *    `tst r1,#1` at 0x02074E3C; taking it from the same bitfield view as a
 *    1-bit member gives `lsl r1,r0,#7` / `lsrs r1,r1,#0x1f` instead (the two
 *    bytes that were still out before the union).  The union is what lets the
 *    two views share the single `ldr r0,[r0]` at 0x02074E34; two separate
 *    pointers cost the whole function, as the note records.
 *
 *  - PIN ../2.0/sp2, the "kept constants" tell of docs/FRONTEND-PINS.md, the
 *    same pin the rest of this cluster carries (func_02074A6C, func_02074A98,
 *    func_02074AC4, func_02074AE8).  The image computes the SECOND and THIRD
 *    call arguments separately inside EACH arm -- `mov r2, r4` / `lsr r0,r0,#8`
 *    at 0x02074E50/0x02074E54 and again at 0x02074E60/0x02074E64 -- and only
 *    the first argument's `mov r1, r5` is hoisted above the branch.  1.1p1
 *    -O4,p hoists all three and cross-jumps the two arms onto one call
 *    sequence, giving 132 bytes against the original's 140 with 67 concrete
 *    bytes out; no source spelling of the two arms moves it, which is what
 *    docs/notes/pkt_02074CD0.c.txt spent its pass measuring.  Under the pin
 *    the SAME C is 140 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02074E10.c \
 *       --func func_02074E10 --addr 0x02074E10 --arm --cc ../2.0/sp2
 */
u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    union Hdr *o;
    u32 r;

    o = func_02074450(a);
    if (o == 0) return 5;
    if (b & 4) {
        if ((o->w >> 24) & 1) r = func_020750EC(o->b.v, (u32 *)c, d);
        else                  r = func_02075080(o->b.v, c, d);
        if (r == 0) return 9;
    } else {
        r = func_0207466C(o->b.v);
    }
    if (out != 0) *out = r;
    return 0;
}






/*
 * The generic "load this resource whole" worker, funnelled into by the four
 * sibling loaders func_02074F3C / func_02074FA8 / func_02075014 / func_02075080,
 * each of which passes its own teardown callback as the second argument.
 * Five steps, each answering 0 on failure: size the entry (func_0207457C),
 * refuse a null output cell, allocate size+0x20 through func_0207482C with the
 * callback / cookie / heap triple, read the whole entry into it, and flush the
 * range with DC_StoreRange before returning the buffer.
 *
 * The read's success test is `!= len`, not `== 0`: the image compares the
 * SIZE against the call result (`cmp r5, r0` at 0x02074F14) rather than the
 * result against zero, which is
 * docs/idioms/cmp-operand-order-names-the-temporary.md -- the size was
 * assigned to a named local first, the read result was not.
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, "kept constants").
 * The image materialises the four early exits' zero FRESH at each
 * (`moveq r0, #0` at 0x02074EC0, 0x02074ED4, 0x02074EF8 and `movne r0, #0` at
 * 0x02074F1C) alongside the separate `mov r3, #0` at 0x02074F0C for the read's
 * fourth argument; 1.1p1 -O4,p CSEs the five into one hoisted register.  Under
 * the pin this C is 160 bytes, 0 mismatches, first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02074E9C.c \
 *       --func func_02074E9C --addr 0x02074E9C --arm --cc ../2.0/sp2
 */
void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u32 len;
    void *p;

    len = func_0207457C(a);
    if (len == 0) return 0;
    if (out == 0) return 0;
    p = (void *)func_0207482C(out, len + 0x20, b, c, d);
    if (p == 0) return 0;
    if (func_020745A4(a, p, len, 0) != len) return 0;
    DC_StoreRange(p, len);
    return p;
}




u32 func_02074F3C(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_0207524C, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}





u32 func_02074FA8(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_0207524C, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}




/*
 *           own, so the ABS32 site has no outside witness; 0x02075274 in turn
 *           cannot be filed because SND_InvalidateBankData (0x020896CC) and
 *           SND_DestroyBank (0x0208A38C) each have their only caller inside it
 */
u32 func_02075014(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_02075274, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}




u32 func_02075080(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_020752A4, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}




u32 func_020750EC(u32 idx, u32 *heap, int flag)
{
    u32 r;
    u32 n;
    u32 total;
    u32 cookie;
    struct ArcHdr *p;
    u32 sz;

    r = func_0207466C(idx);
    if (r == 0) {
        if (func_020745A4(idx, &d_0214EA54, 0x3c, 0) != 0x3c)
            return 0;
        sz = d_0214EA54_hdr.count * 4;
        total = sz * 2;
        if (heap == 0)
            return 0;
        if (flag != 0)
            cookie = (u32)func_020742FC();
        else
            cookie = 0;
        p = (struct ArcHdr *)func_0207482C(heap, total + 0x5c, (u32)func_020752D4, cookie, idx);
        if (p == 0)
            return 0;
        n = func_020745A4(idx, p, sz + 0x3c, 0);
        if (n != sz + 0x3c)
            return 0;
        MI_CpuCopy8(p->off, &p->off[p->count], sz);
        MI_CpuFill8(p->off, 0, sz);
        DC_StoreRange(p, total + 0x3c);
        if (flag != 0)
            func_02074694(idx, (u32)p);
        r = (u32)p;
    }
    return r;
}




void func_020751F4(u32 a, u32 b, u32 c) {
    u32 t, s;
    if (b == 0) return;
    s = func_02087988();
    t = (u32)func_020742E4((struct Global *)b);
    if (func_0207466C(c) == a) func_02074694(c, 0);
    func_020742E4((struct Global *)t);
    func_0208799C(s);
}






/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * Reads a bank header, then invalidates the range [p, p + len) of sequence
 * data; the length survives in r4 across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0207524C.c \
 *       --func func_0207524C --addr 0x0207524C --cc 1.1p1 --arm
 */
void func_0207524C(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4((u32)p, b, c);
    func_020896AC(p, p + len);
}






/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * The bank flavour: same range invalidate plus the bank teardown.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075274.c \
 *       --func func_02075274 --addr 0x02075274 --cc 1.1p1 --arm
 */
void func_02075274(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4((u32)p, b, c);
    func_020896CC(p, p + len);
    func_0208A38C((struct SNDBankData *)p);
}






/*
 * Kept as its own file rather than folded with func_020752D4, its immediate
 *  * neighbour: the two are the only callers of 0x0208A424 anywhere in the image,
 *  * so any range holding both has no witness left for that site and caps at
 *  * MATCH. Split, each file is the other's witness.
 */
void func_020752A4(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_020896EC((const void *)a, (const void *)(a + b));
    func_0208A424((struct SNDWaveArc *)a);
}





/*
 * See src/matched/func_020752A4.c: the pair is deliberately not one unit.
 */
void func_020752D4(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_0208A424((struct SNDWaveArc *)a);
}



void func_020752F4(u32 a, u32 n, u32 x, u32 y) {
    if (func_0208A674(x, y) == a) func_0208A640(x, y, 0);
    func_020896EC((const void *)a, (const void *)(a + n));
}


/*
 * Bank-entry loader.  Skip the work if the entry is already resident
 * (func_0208A674), otherwise take the entry's byte range from the object's
 * offset table and stream it in: allocate range+0x20 through func_0207482C
 * with func_020752F4 as the teardown callback, read it with func_020745A4,
 * flush it with DC_StoreRange and publish it with func_0208A640.  Returns 1
 * for "resident on exit" (already-resident and success both), 0 for failure.
 *
 * THE OFFSET TABLE.  `ldr r1,[r8,#0x38]` / `add r1,r1,r7` /
 * `add r1,r8,r1,lsl #2` / `ldr r4,[r1,#0x3c]` / `ldrlo r0,[r1,#0x40]` at
 * 0x02075368..0x02075380 fixes it: a u32 array based at +0x3c of the object,
 * indexed by the object's own base index at +0x38 plus the caller's entry
 * index.  The entry's end is the NEXT slot, except for the last entry
 * (`cmp r7, r0` against count-1) where it is the object's total size at +0x08;
 * the `ldrlo`/`ldrhs` pair is the unsigned compare, so both index and count
 * are u32.
 *
 * THE DEAD POINTER IS LOAD-BEARING.  `e` is assigned the table-entry address
 * and then never read: both reads are spelled as fresh
 * `(&o->f3c[o->f38 + i])[0]` / `[1]` expressions.  Dropping the assignment, or
 * reading through `e` instead of recomputing, both move the whole frame down
 * one callee-saved register (r8/r7/r6/r5 becomes r7/r6/r5/r4) and add an
 * instruction: 204 bytes against the original's 200, 134-143 concrete bytes
 * out.  The assignment is an extra definition point for the address value,
 * which is what makes the allocator number it before the four parameters --
 * the mechanism docs/notes/permuter.md describes for the `temp` mutation.
 * Likewise `n = func_0208A638(o); n = n - 1;` must be TWO statements; folded
 * into one the subtract is scheduled after the compare.  Both levers were
 * found by tools/permuter.py (`--mode hill --budget 800 --jobs 8 --types`,
 * closing at compile 573 with `split-assign(n) ; temp(tmp=e[0]) ; expand(e x2)`
 * from a body that was already size-exact) and then re-verified by hand: every
 * hand-tidied spelling that removes either one goes back to DIFF.
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, "kept constants").
 * The image materialises the four failure exits' zero fresh at each
 * (`moveq r0,#0` at 0x02075390, 0x020753B4, `movne r0,#0` at 0x020753D4).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0207533C.c \
 *       --func func_0207533C --addr 0x0207533C --arm --cc ../2.0/sp2
 */
u32 func_0207533C(Bank *o, u32 i, u32 h, u32 *heap)
{
  u32 n;
  u32 off;
  u32 end;
  u32 len;
  u32 *e;
  void *p;
  u32 tmp;
  if (func_0208A674((u32)o, i) != 0)
    return 1;
  n = (u32)func_0208A638((char *)o);
  n = n - 1;
  e = &o->f3c[o->f38 + i];
  tmp = (&o->f3c[o->f38 + i])[0];
  if (i < n)
    end = (&o->f3c[o->f38 + i])[1];
  else
    end = o->f08;
  off = tmp;
  len = end - off;
  if (heap == 0)
    return 0;
  p = (void *)func_0207482C(heap, len + 0x20, (u32) func_020752F4, (u32) o, i);
  if (p == 0)
    return 0;
  if (func_020745A4(h, p, len, off) != len)
    return 0;
  DC_StoreRange(p, len);
  func_0208A640((u32)o, i, (u32)p);
  return 1;
}


/*
 * "Load every bank this sequence needs for one group": open an iterator over
 * the sequence (func_0208A46C), copy it to a working cursor, then step it
 * (func_0208A48C) and, for every record of kind 1 whose group id matches the
 * caller's, pull the bank in with func_0207533C.  Any failed load answers 0;
 * a run to exhaustion answers 1.  The null-sequence guard answers 0 and is
 * emitted AFTER the iterator open, which is why it shares the mid-function
 * epilogue rather than the entry.
 *
 * THE FRAME IS THE EVIDENCE FOR BOTH STRUCT SIZES, and it took two levers:
 *
 *  - DECLARATION ORDER IS STACK ORDER, reversed
 *    (docs/idioms/local-declaration-order-is-stack-order.md).  The image puts
 *    the freshly-opened iterator at sp+0, the working cursor at sp+8 and the
 *    record at sp+0x10; declaring them in that order lays them out backwards
 *    (record at sp+0) and costs 17 bytes.  Declared `Rec r; Iter it; Iter it0;`
 *    the offsets line up.
 *
 *  - THE RECORD IS 12 BYTES, NOT 8.  With an 8-byte Rec every offset is right
 *    but the frame is `push {r4..sl, lr}` / `sub sp, #0x18`; the image is
 *    `push {r3, r4..sl, lr}` / `sub sp, #0x1c`, i.e. eight bytes more of
 *    locals.  Only the first four bytes of the tail are ever read
 *    (`ldrb [sp,#0x10]`, `ldrh [sp,#0x12]`, `ldrheq [sp,#0x14]`), so the
 *    +6..+11 members are sized by the frame alone and their split is not
 *    constrained: `u16 h6; u32 w8;`, `u16 h6; u16 h8;` and a bare `u32 w8;`
 *    all give the same 192 bytes, 0 mismatches.  Recorded as the three-member
 *    form; a later caller of func_0208A48C can settle the split.
 *
 * PIN ../2.0/sp2, the cluster pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075404.c \
 *       --func func_02075404 --addr 0x02075404 --arm --cc ../2.0/sp2
 */
u32 func_02075404(u32 o, u32 seq, u32 want, u32 h, u32 *heap)
{
    Rec r;
    Iter it;
    Iter it0;

    func_0208A46C(&it0, seq, want, h);
    it = it0;
    if (seq == 0) return 0;
    if (func_0208A48C(seq, &r, &it) != 0) {
        do {
            if (r.kind == 1 && want == r.h4) {
                if (func_0207533C((Bank *)o, r.h2, h, heap) == 0) return 0;
            }
        } while (func_0208A48C(seq, &r, &it) != 0);
    }
    return 1;
}



/*
 * Walk the 32 slots of the current archive (func_020742FC is called for its
 * side effect only): for every slot record func_020744B4 hands back, apply
 * its count byte and +2 halfword (func_02072DB0 / func_02072DD0), and when
 * both the record's +4 payload and the argument are non-null, register the
 * payload count times with func_02072DE8, failing out on the first refusal.
 *
 * Levers (permuter hill found the first, the second is a prototype read):
 *   - declaration order i, e, j (register r6 / r7 / r8);
 *   - the slot index is `int` in the CALLEE PROTOTYPES as well as the loop
 *     (func_02072DE8's first parameter above all).  With the callee declared
 *     u32 the implicit conversion reshuffles r4-r7 (14 bytes out); the loop
 *     compare is `blt`, so the index itself is signed.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020754C4.c \
 *       --func func_020754C4 --addr 0x020754C4 --arm --cc ../2.0/sp2
 *   EXACT, 156 bytes, 5 of 5 relocation sites resolved (sp2p2 the same,
 *   dsi/1.1p1 152 bytes DIFF).
 */
u32 func_020754C4(u32 a)
{
    int i;
    Ent *e;
    int j;

    func_020742FC();
    for (i = 0; i < 32; i++) {
        e = func_020744B4(i);
        if (e == 0)
            continue;
        func_02072DB0(i, e->count);
        func_02072DD0(i, e->h2);
        if (e->data != 0 && a != 0) {
            for (j = 0; j < e->count; j++) {
                if (func_02072DE8(i, a, e->data) == 0)
                    return 0;
            }
        }
    }
    return 1;
}

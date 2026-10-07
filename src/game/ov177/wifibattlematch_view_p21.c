/*
 * file:     wifibattlematch_view_p21.c
 * unit:     yes
 * function: func_021E8420, func_021E84F8, func_021E8568, func_021E8628, func_021E867C
 * address:  0x021E8420
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021E8DD4     0x021E8DD4  data
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 */
#include "../../matched/include/Obj10713.h"
#include "../../matched/include/Obj01960.h"
#include "../../matched/include/Obj00842.h"

struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Descriptor;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct Tcbl;
struct U16Vec;
struct Rec3;
struct S02031140;
struct Ctx;
struct Blk;
typedef struct { short x, y; } Pos;

typedef struct {
    char pad0[0x30];
    void *obj[14];
    char pad68[0xb0 - 0x68];
    unsigned count;
    short base[14];
} Work;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    char           pad0[4];
    int            f4;
    char           pad1[4];
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad2[3];
    int            f28;
    int            f2c;
} S;

typedef unsigned char  u8;

typedef signed int     s32;

extern u32 func_020407E8(u32 layer);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_0209C2B0(int, int);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02082BCC(void *, int, int);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(unsigned char *p);
extern int func_02028604(int p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020307B0(void *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
int func_021E8420(Work *p);
int func_021E84F8(char *p, void *q);
S *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap);
void func_021E8628(char *p);
void func_021E867C(char *p);
extern unsigned char d_021E8DD4[];

int func_021E8420(Work *p)
{
    int done;
    int shift;
    Pos pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = func_0209C2B0(p->count << 8, 20);
    for (i = 0; i < 14; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->base[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], (const struct Vec2 *)(&pos[0]), 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0x100;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}

int func_021E84F8(char *p, void *q)
{
 int result=1;
 unsigned i;
 for(i=0;(int)i<6;i++) {
 if(*(void **)(p+i*4+0x68)!=0) {
 unsigned char *e=(unsigned char *)p+i*8;
 if(e[0x84]!=0) {
 if(func_0201C6C4(q,func_02045770(((struct Obj10713 *)e)->f80))==0) {
 func_02045334(*(void **)((unsigned)p+(int)i*8+0x80));*(unsigned char *)((unsigned)p+(int)i*8+0x84)=0;
 }
 }
 result &= e[0x84]==0;
 }
 }
 return result;
}


/*
 * note 2026-10-02: only prologue scheduling (orig spills r2,r3 before ldr r5 heap, mine
 *   after) and tail ldr r3/str order differ (10 lines). Tried u8 param, local copies,
 *   decl order, init-at-decl, heap types.
 *
 * note 2026-10-05: re-checked the listing: c and d are spilled (str r2,[sp,#0xc]; str r3,[sp,#0x10]) BEFORE
 * the heap load (ldr r5,[sp,#0x30]); ours spills r3 then r2 after the heap load, and loads r3 for the last call
 * above the w->fc store (orig after). Both are scheduler order only, 20 bytes. No source form tried this
 * round changed it (arguments are used in place, no stand-in casts). Still DIFF.
 *
 * note 2026-10-05 (wD9 lane15): 20 -> 8 bytes. `unsigned short c` (docs/idioms/a-narrow-spilled-parameter-keeps-
 *   its-reload-below-a-store.md) fixes the tail: the reload of c now stays below the w->fc store. Left: the
 *   prologue, original `str r2; str r3; ldr r5,[sp,#0x30]; adds r6`, ours `ldr r5; adds r6; str r2; str r3`.
 *   Tried: a struct-by-value (c, d) pair (pushes r0-r3, worse), K&R definition (same 20), d as u16/u8/s16/s8
 *   (10, d's store then drifts below adds r6), a and b as u16 (no change), heap u8/u16 (186, original loads it
 *   as a word), the callee third parameter u16 as in other matched callers (worse). c as u8 is 33 (the original
 *   truncates c at the call).
 *
 * note 2026-10-05 (wD9r lane17, pengy draft): still 8 bytes, prologue only. Hypothesis: c and d are address-taken
 *   so their stores block the heap load. `*&c`/`*&d` at the call: folded, 8. `*(int *)&c` with int c: 38 (homes
 *   r0-r3 in the caller area, push {r0-r3}), so the original does not take their address. Also tried: a local
 *   copy of heap (8), local copies of c and d at the top (8), heap as unsigned int (145).
 * note 2026-10-05 (wD9r lane31): still 8 bytes, prologue only. New tries: c and d as one 64-bit parameter
 *   (20), e/f/heap as a struct passed by value on the stack (8), c and d copied into an `int lc[2]` array local
 *   (8, scalarised), a or b as u8 (113/119), e as u16/u8 (8), f as u16 (158), c as short/signed char (8),
 *   d unsigned int (8), callee 4th parameter u8 with plain c (8; with d u16: 10/12), a..d all u16 (10),
 *   c,d,e u16 (10). With c and d both u16 the c store goes to the front (str r2 matches) but d's store and the
 *   heap load drift down (str r2; adds r6; str r3; movs; adds r7; ldr r5). Left DIFF.
 * note 2026-10-05 (wD9r lane39): still 8 bytes, prologue only. New tries: d as void * / u16 * with the callee
 *   third parameter a pointer (8), an extra unused 8th stack parameter (8), void * return type (8), const heap
 *   (145, heap is reloaded from the stack at each use). Left DIFF.
 * note 2026-10-05 (wD9r lane58): still 8 bytes, prologue only. New tries: the allocation and clear in a
 *   static inline Alloc(heap) helper (8, the inlined copy of heap is propagated), the last call in a static
 *   inline Frame(w, d, c) helper (27). Checked for a matched twin (callers of func_0201F73C and func_020450F0
 *   in src/matched): none has this shape. Left DIFF.
 * note 2026-10-05 (wD9r lane68): EXACT. Fix: heap is a u16 parameter (it is stored with strh to f1e) with the
 *   house callee prototypes (func_02030734 u32 heap, u16 tag; func_020457B0 u32, u32; func_0203101C u32 heap,
 *   u16 tag, so heap goes to both), and d is a u16 parameter passed to the u16 third parameter of
 *   func_0201F73C. The u16 heap keeps the word ldr and moves it below the c home store (8 -> 6), and the u16 d
 *   moves its home store to the front (6 -> 0). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 */
S *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap)
{
    S *w;
    int h;

    w = func_02030734(heap, 0x40, 0, (const char *)d_021E8DD4, 0x5e);
    func_02082BCC(w, 0, 0x40);
    w->f1c = 0xf;
    w->f4 = f;
    w->f28 = func_0201C440((void *)heap);
    w->f2c = 3;
    w->f1e = heap;
    w->f18 = (int)func_020457B0(0x300, heap);
    w->f14 = func_020450F0((unsigned char)a, 1, 0x13, 0x1e, 4, (unsigned char)b, 1);
    w->f20 = w->f14;
    w->f24 = 0;
    func_02043B5C(func_02045770((struct Descriptor *)w->f14), (unsigned char)w->f1c);
    h = w->f14;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    w->fc = (int)func_0203101C(heap, heap, 1, 0x20);
    func_0201F73C((void *)w->f14, 0, d, (unsigned char)c);
    return w;
}

void func_021E8628(char *p)
{
    if (((struct Obj01960 *)p)->f8 != 0) {
        func_0201CE48(((struct Obj01960 *)p)->f8);
        ((struct Obj01960 *)p)->f8 = 0;
    }
    if (*(unsigned char * *)&((struct Obj01960 *)p)->f10 != 0) {
        func_0202F038(*(unsigned char * *)&((struct Obj01960 *)p)->f10);
        ((struct Obj01960 *)p)->f10 = 0;
    }
    if (((struct Obj01960 *)p)->f34 != 0)
        func_02028604(((struct Obj01960 *)p)->f34);
    func_02031140(((struct Obj01960 *)p)->fC);
    func_0201F7A8(((struct Obj01960 *)p)->f14, 0);
    func_020452E8(((struct Obj01960 *)p)->f14);
    func_02045808(((struct Obj01960 *)p)->f18);
    func_0201C4C0(((struct Obj01960 *)p)->f28);
    func_020307B0(p);
}

void func_021E867C(char *p)
{
 void *q;
 func_0201C4E4(((struct Obj00842 *)p)->f28);
 switch(((struct Obj00842 *)p)->f2C) {
 case 2:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 break;
 case 0:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 ((struct Obj00842 *)p)->f30=((struct Obj00842 *)p)->f24==0;
 break;
 case 1:
 if(((struct Obj00842 *)p)->f8!=0) {
 if(((struct Obj00842 *)p)->f34!=0)func_020286C4(((struct Obj00842 *)p)->f34,((struct Obj00842 *)p)->f8,((struct Obj00842 *)p)->f14);
 if(func_02028484((struct Blk *)(p+0x38),((struct Obj00842 *)p)->f8)!=0)((struct Obj00842 *)p)->f30=1;
 }
 break;
 case 3:break;
 }
 func_020310C4(((struct Obj00842 *)p)->fC);
}

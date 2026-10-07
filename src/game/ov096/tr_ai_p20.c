/*
 * file:     tr_ai_p20.c
 * unit:     yes
 * function: func_0218A308, func_0218A310, func_0218A324, func_0218A378, func_0218A384, func_0218A390, func_0218A3F4, func_0218A41C, func_0218A458, func_0218A494
 * address:  0x0218A308
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021C7E14 0x021C7E14 thumb ov093
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02030734 0x02030734 arm
 *   D_0218A7C0 0x0218A7C0 data a4
 *   D_0218A7A0 0x0218A7A0 data
 *   func_02049250  0x02049250  arm
 */
#include "../../matched/include/Obj13672.h"
#include "../../matched/include/G_Slot.h"
#include "../../matched/include/Obj04408.h"

struct S2;
struct QL;
struct QG;
struct Rec;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } Slot;

extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D67A8(struct QL *p);
extern void func_0201BD28(int, int);
extern void func_0201BEB8(int, int);
extern u8 func_021D5440(u8 *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u16 func_021C7E14(u8 *, u8, u8, u32, int, int);
extern int func_02020F20(int, int, u16);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
u8 *func_0218A308(void *p, u32 i);
void func_0218A310(unsigned int a);
void func_0218A324(u8 *p);
void func_0218A378(int a, int b, int c);
void func_0218A384(int a, int b, int c);
u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d);
int func_0218A3F4(int a, int b, int c);
void func_0218A41C(unsigned int a);
void func_0218A458(void);
void *func_0218A494(u8 *a);
extern struct Slot *D_0218A7C0;
extern const char D_0218A7A0[];

/*
 * Resolved by the matched func_021B9C00 in ov093 (thumb); cross-overlay target.
 */
u8 *func_0218A308(void *p, u32 i) { return func_021B9C00(p, i); }

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void func_0218A310(unsigned int a) { int i; for(i=0;i<4;i++) *(int *)(a + (unsigned)i*4+4)=*(int *)(a + (unsigned)i*4+0x14); }


void func_0218A324(u8 *p)
{
    u8 *s;
    int i;
    u16 h;
    s = func_0218A2FC(p, p[0x95]);
    for (i = 0; i < 4; i++) {
        h = *(u16 *)(p + p[0x95] * 8 + i * 2 + 0x4c);
        if (h == func_021D67A8((struct QL *)s))
            return;
        if (h == 0) {
            *(u16 *)(p + p[0x95] * 8 + 0x4c + i * 2) =func_021D67A8((struct QL *)s);
            return;
        }
    }
}

void func_0218A378(int a, int b, int c) { func_0201BD28(b, c); }

void func_0218A384(int a, int b, int c) { func_0201BEB8(b, c); }

/*
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes, size 98 vs 100). Image order in the loop call: str r7,[sp,#4]; ldr r0,[sp,#8]; ldr r1,[sp,#0x10]; adds r0,#0xb4; ldr r0,[r0]; ldr r2. Ours loads a first, then the field, then x. Also tried const-qualified first parameter (callee and function) and a split pointer/xx copy; the compiler folds them back.
 * note: 2026-10-04 Residue: store order only. Original stores the stack arg d ([sp,#4]) before reloading spilled a ([sp,#8]) for the first call argument; ours loads a first. Tried: struct field, ptr casts, local hoist, u32/int d, u16 callee return, while loop, temp for the 54C0 result.
 * note: 2026-10-05 (wD4 lane20): tried the first argument and the 54C0 result as separate locals before the call (c = f(b,i); q = *(a+0xB4); g(q,x,y,c,1,d)) and a u32 first parameter; same 10 bytes (ldr r0,[sp,#8] still ahead of str r7,[sp,#4]).
 * 2026-10-05 (wD5 lane20): no new variant closed it. Reading: original emits the stack argument store (str r7,[sp,#4]) before the spilled-a reload and the field address chain; ours starts the chain first. Same 10 bytes as before; the sibling func_02188D5C shows the same tie-break in its loop call, so a common cause (IR order of stack-argument stores versus argument 0) is likely.
 * 2026-10-05 (wD6 lane15): EXACT*. func_021C7E14 takes u8 a, u8 b (as in matched func_02189D48)
 *   and x, y are u8 locals; that fixes the stack-argument store order in the loop call.
 */
u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d)
{
    u32 best = 0;
    u8 x = func_021D5440(b);
    u8 y = func_021D5440(c);
    int i;
    for (i = 0; i < (int)func_021D5448((struct QG *)b); i++) {
        u32 r = func_021C7E14(*(u8 **)(a + 0xB4), x, y, (u32)func_021D54C0(b, (u8)i), 1, d);
        if (r > best)
            best = r;
    }
    return best;
}


/*
 * The apparent register-scheduling residue was a missing third argument:
 *   the image keeps `b` (r1) live and loads the halfword into r2, which is
 *   only possible if the callee takes (field, b, h).  func_02020F20 is
 *   declared with the extra `int` argument and the call passes `b`.
 *   EXACT* because the follower at 0x0218A41A is an unlabelled `movs r0,r0`
 *   pad.
 */
int func_0218A3F4(int a, int b, int c) {
    u16 h;
    int p;
    int q;
    h = ((struct Obj13672 *)a)->fA0;
    p = func_02020F20(((struct Obj13672 *)a)->fA8, b, h);
    q = func_02021014((struct Rec *)p, c);
    func_020307B0((void *)p);
    return q;
}

void func_0218A41C(unsigned int a) { int i; if(D_0218A7C0==0) { D_0218A7C0=func_02030734(a,24,1,D_0218A7A0,3999); for(i=0;i<4;i++) D_0218A7C0->id[i]=255; } }

void func_0218A458(void) { int i; int zero; if(D_0218A7C0!=0) { zero=0; for(i=0;i<4;i++) { if(D_0218A7C0->obj[i]!=0) { func_020307B0(D_0218A7C0->obj[i]); D_0218A7C0->obj[i]=(void *)zero; } } func_020307B0(D_0218A7C0); D_0218A7C0=0; } }


void *func_0218A494(u8 *a)
{
    int i;
    u32 x;

    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == a[0x45]) {
            D_0218A7C0->ref[i]++;
            return D_0218A7C0->obj[i];
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == 0xff)
            break;
    }
    if (a[0x45] == 2)
        x = (u16)((((struct Obj04408 *)a)->fA0 & 0x7fff) | 0x8000);
    else
        x = ((struct Obj04408 *)a)->fA0;
    D_0218A7C0->id[i] = a[0x45];
    D_0218A7C0->ref[i]++;
    D_0218A7C0->obj[i] = func_02049250(((struct Obj04408 *)a)->fA4, a[0x45], (u16)x);
    return D_0218A7C0->obj[i];
}

/*
 * file:     unit_021D5EA8_p01.c
 * unit:     yes
 * function: func_021D5EA8, func_021D5EFC, func_021D5F08, func_021D5F14, func_021D5F38, func_021D5F90, func_021D5FA4, func_021D5FB8
 * address:  0x021D5EA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D53DC  0x021D53DC  thumb  ov093
 *   func_021D53C8  0x021D53C8  thumb  ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 */
#include "../../matched/include/Obj07797.h"

struct UtilWork;
typedef signed char s8;

typedef unsigned char u8;

typedef unsigned short u16;

struct S { u8 pad[0x142]; u8 f; };

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

struct Unk021D5FA4 { u8 pad[0xE]; u16 fE; u16 f10; };

int func_021D53DC(signed char *p);
void func_021D53C8(unsigned char *p);
extern int func_021D5BDC(struct UtilWork *, unsigned int);
void func_021D5EA8(u8 *p, int i, u8 n);
int func_021D5EFC(char *p);
void func_021D5F08(char *p);
u8 func_021D5F14(struct UtilWork *p);
int func_021D5F38(struct S *p, int n);
void func_021D5F90(u8 *p, u16 n);
void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
void func_021D5FB8(u8 *p);

void func_021D5EA8(u8 *p, int i, u8 n)
{
    u8 *q;
    switch (i) {
    case 1: q = p + 0xfc; break;
    case 2: q = p + 0xfd; break;
    case 3: q = p + 0xfe; break;
    case 4: q = p + 0xff; break;
    case 5: q = p + 0x100; break;
    case 6: q = p + 0x101; break;
    case 7: q = p + 0x102; break;
    default: return;
    }
    if (n <= 12) q[0] = n;
}


/*
 * note: unblocked when src/matched/func_021D53DC.c was filed EXACT; the
 * relocation now attests as `matched` (ov093) with no C change.
 */
int func_021D5EFC(char *p)
{
    return func_021D53DC((signed char *)(p + 0xfc));
}


/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */
void func_021D5F08(char *p)
{
    func_021D53C8((unsigned char *)(p + 0xfc));
}

u8 func_021D5F14(struct UtilWork *p)
{
    u8 n;
    n = *((u8 *)p + 0x142);
    if (func_021D5BDC(p, 9)) {
        n += 2;
        if (n > 4) n = 4;
    }
    return n;
}


/*
 * Lever: the clamp at the bottom stores the field in each arm
 * (`if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;`). A local `v` assigned in the arms
 * and stored once, or a ternary, keeps k out of r4 (no push {r3,r4}; 8 bytes short).
 * `n * 0xffffffff` keeps the mvns/muls (a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md).
 */
int func_021D5F38(struct S *p, int n)
{
    int k;

    if (n > 0) {
        if (p->f < 4) {
            p->f = p->f + (u8)n;
            if (p->f > 4) p->f = 4;
            return 1;
        }
    } else {
        k = n * 0xffffffff;
        if (p->f != 0) {
            if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;
            return 1;
        }
    }
    return 0;
}

/*
 * extent: final two bytes are zero alignment padding.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
void func_021D5F90(u8 *p, u16 n)
{
    if (((struct Obj07797 *)p)->f10 > n) {
        ((struct Obj07797 *)p)->f10 = ((struct Obj07797 *)p)->f10 - n;
        return;
    }
    ((struct Obj07797 *)p)->f10 = 0;
}

void func_021D5FA4(struct Unk021D5FA4 *p, u16 n)
{
    p->f10 += n;
    if (p->f10 > p->fE) p->f10 = p->fE;
}


/*
 * store constant 0x0 at #0x10
 */
void func_021D5FB8(u8 *p)
{
    *(u16 *)&p[0x10] = 0x0;
}

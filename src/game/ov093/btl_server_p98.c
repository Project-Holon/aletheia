/*
 * file:     btl_server_p98.c
 * unit:     yes
 * function: func_021C8810, func_021C8828, func_021C8838, func_021C8860
 * address:  0x021C8810
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
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj18339.h"
#include "../../matched/include/Obj21124.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Packed021C8810 { u16 low : 8; u16 high : 8; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct S {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

extern void func_02082BCC(void *, int, u32);
void func_021C8810(u8 *p);
/* 021C8828 u8 of the low halfword, != 0 */ u32 func_021C8828(u8 *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, u32 val);

void func_021C8810(u8 *p)
{
    func_02082BCC(p, 0, 0x24);
    ((struct Packed021C8810 *)(p + 2))->low = 0;
}


/* 021C8828  u8 of the low halfword, != 0 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrh r0, [r0, #2]; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; beq loc_021C8834; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C8828(u8 *p)
{
    return ((u8)((struct Obj18339 *)p)->f2 != 0);
}


/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */
void func_021C8838(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    ((struct Obj21124 *)p)->f0 = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}


/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Appends `val` to the record at p: the count in bits 8..14
 * of the +2 halfword (max 7 entries) is incremented and `val` stored at
 * p + 4 + idx*4.  The 7-bit unsigned bitfield is what makes the count
 * unsigned (`bhs`, not `bge`) and produces the lsl/lsr extraction pair.
 */
void func_021C8860(struct S *p, u32 val)
{
    unsigned int idx = p->n;

    if (idx >= 8)
        return;
    p->n = idx + 1;
    p->arr[idx] = val;
}

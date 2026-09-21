/*
 * function: func_02073AD0
 * address:  0x02073AD0
 * packet:   pkt_02073AD0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Pushes the base value v to +0x44 and re-emits every one of the +0x50 active
 * slots: each slot byte at +0x54+i indexes the 8-byte records of g_0214E934,
 * whose second word is added to the base, converted by func_0208A24C, and
 * handed to func_02089638 as (1 << k, low byte, arithmetic high half).
 *
 * PINNED ../2.0/sp2 on the store/load schedule tell, the same pin its only
 * caller func_02075858 (pkt_02075698) already carries and for the same
 * front-end reason. Under dsi/1.1p1 -O4,p this body is 108 bytes with every
 * instruction and every register correct but 11 bytes out, entirely in the
 * three-instruction window at +0008: the image stores `str r1,[r7,#0x44]`
 * before loading the loop bound `ldr r0,[r7,#0x50]`, and 1.1p1 hoists the
 * load above the store at every spelling tried (a `volatile` store through
 * &s->f44, a `volatile` f50 field, the bound bound to a named local, the
 * guard written as an explicit early return). Under the pin the same C is
 * 108 bytes, 0 concrete mismatches: BYTE-CORRECT.
 *
 * Two shape levers were needed and are worth keeping: the `f50 <= 0` guard
 * must NOT be written as a separate early return (that emits a second
 * `cmp r0,#0`; the bare `for` gives the single predicated `pople`), and
 * `u32 k` must be declared BEFORE `s32 i` or the two swap r5/r6
 * (declaration-order-decides-which-register-a-local-gets).
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. The PC24
 * at +003C to func_0208A24C is unattested: 0x0208A24C has exactly one branch
 * reference anywhere in the image and it is this call, so no cut frees it and
 * only a `matched` entry at 0x0208A24C would close this row.
 *
 * symbols:
 *   g_0214E934     0x0214E934  data
 *   func_0208A24C  0x0208A24C  arm
 *   func_02089638  0x02089638  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073AD0.c \
 *       --func func_02073AD0 --addr 0x02073AD0 --cc ../2.0/sp2 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct Ent { u32 a; u32 b; };
extern struct Ent g_0214E934[];

extern s32  func_0208A24C(s32 x);
extern void func_02089638(u32 mask, u32 lo, s32 hi);

struct Slot {
    u8  pad_00[0x44];
    s32 f44;          /* 0x44 */
    u8  pad_48[0x08];
    s32 f50;          /* 0x50 */
    u8  f54[4];       /* 0x54 */
};

void func_02073AD0(struct Slot *s, s32 v)
{
    u32 k;
    s32 i;

    s->f44 = v;
    for (i = 0; i < s->f50; i++) {
        s32 r;
        k = s->f54[i];
        r = func_0208A24C(s->f44 + (s32)g_0214E934[k].b);
        func_02089638((u32)(1 << k), (u32)r & 0xff, r >> 8);
    }
}

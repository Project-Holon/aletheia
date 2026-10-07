/*
 * file:     unit_0200E44C_p01.c
 * unit:     yes
 * function: func_0200E44C, func_0200E458, func_0200E460, func_0200E47C, func_0200E488, func_0200E49C, func_0200E4B0, func_0200E4CC, func_0200E4F8, func_0200E518, func_0200E588, func_0200E590, func_0200E5A0, func_0200E5CC, func_0200E5E4, func_0200E5F8, func_0200E608, func_0200E684, func_0200E6B4, func_0200E6E8, func_0200E6FC, func_0200E714
 * address:  0x0200E44C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216736C    0x0216736C  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   data_020A721C  0x020A721C  data
 *   func_020072CC  0x020072CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012E4C  0x02012E4C  thumb
 *   func_02012E7C  0x02012E7C  thumb
 *   OS_WaitIrq     0x0208459C  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203F1FC 0x0203F1FC  thumb, not otherwise called in arm9_main
 *   func_02024344  0x02024344  thumb
 *   func_020242D8  0x020242D8  thumb
 *   sub_020071CC  0x020071CC  thumb
 */
#include "../../matched/include/Obj11237.h"
#include "../../matched/include/Obj15607.h"
#include "../../matched/include/Obj15608.h"

struct Big;
struct Sub02007324Ctrl;
struct Sub020071CCCtrl;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Tally {
    u16 add16[30];      /* 0x000 */
    u8 add8[150];       /* 0x03C */
    u8 pad[10];         /* 0x0D2 */
    u32 total32[30];    /* 0x0DC */
    u16 total16[150];   /* 0x154 */
} Tally;

struct Rec0200E6FC {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

struct Rec0200E714 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

extern u8 func_0216736C(u32 id);
extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_020072CC(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02012E4C(u8 *p, u32 id);
extern int func_02012E7C(char *p, int a1);
extern void OS_WaitIrq(int clear, u32 mask);
extern void func_0200734C(struct Sub02007324Ctrl *ctrl, u32 id);
extern u32 func_020307B0(void *p);
extern void func_02024344(void *obj);
extern void func_020242D8(void *slot, u32 idx);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
int func_0200E44C(int p0, int p1);
u16 func_0200E458(const u16 *p, int i);
void func_0200E460(char *p, int idx, int v);
u32 func_0200E47C(u8 *p, int i);
u32 func_0200E488(u32 a0, u32 a1);
u32 func_0200E49C(u8 *p, u32 a, u32 count);
u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
void func_0200E4CC(u8 *a0, u32 a1, u32 a2, int a3);
int func_0200E4F8(int a0, int a1, int a2);
void func_0200E518(Tally *t);
u32 func_0200E588(void);
void func_0200E590(void *p);
int func_0200E5A0(void *a0);
int func_0200E5CC(void *p);
u16 func_0200E5E4(void *p);
char *func_0200E5F8(char *p, u32 idx);
void func_0200E608(void *sys, void *dst, u32 heap);
void sub_0200E684(void *obj);
u32 sub_0200E6B0(void);
void sub_0200E6B4(void *obj);
void *sub_0200E6E8(u32 a);
void *sub_0200E6F0(u32 a);
extern const char data_020A721C[];




int func_0200E44C(int p0, int p1){ return *(unsigned char *)(((p0 + p1) + ((0xa << 6) << 0))); }





/*
 * Unlabelled Thumb leaf in the ARM9 module: halfword array index.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0200E458(const u16 *p, int i)
{
    return p[i];
}




void func_0200E460(char *p, int idx, int v)
{
    unsigned short *q = (unsigned short *)(p + idx * 2);
    *q = *q + (unsigned short)v;
    if (*q > 0x270f)
        *q = 0x270f;
}





/*
 * Unlabelled Thumb leaf in the ARM9 module: word array at +0xDC, index i.
 * Filed by wave D4 lane 12 (blocked ov217 func_021BFC60).
 *
 * Addresses are Black-image addresses.
 */
u32 func_0200E47C(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0xdc);
}





/*
 * note:     wave 16: promoted.  0x0216736C is the unlabelled ov010 leaf matched
 *           in src/matched/func_0216736C.c (ov010/pkt_02167358); it attests as
 *           `matched, overlay` under the ov010 hint.  The source shape that
 *           works: a1-1 must be a named local computed before the call;
 *           writing `f(a0) + (a1 - 1)` gives `adds r0, r1, r0` instead of
 *           `adds r0, r0, r1`.
 */
u32 func_0200E488(u32 a0, u32 a1)
{
    u32 n = a1 - 1;
    u32 v = func_0216736C((u8)a0);

    return v + n;
}





/*
 * Returns 1 when func_0200E4B0's result is 0x63 or more, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E49C.c \
 *       --func func_0200E49C --addr 0x0200E49C --thumb --cc 1.1p1
 */
u32 func_0200E49C(u8 *p, u32 a, u32 count)
{
    return func_0200E4B0(p, a, count) >= 0x63 ? 1 : 0;
}





u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2)
{
    if (a2 == 0)
        return 0;
    return *(a0 + func_0200E488(a1, a2) + 0x3c);
}





/*
 * Two tells on the source, both four bytes each.  The base has to be taken as
 * a pointer (`p = a0 + 0x3c` then `p[off]`) rather than as one subscript
 * `a0[off + 0x3c]`: the original adds the 0x3c to the object pointer and then
 * indexes off against that, not the other way round.  And the guard is
 * written `a3 + v`, not `v + a3`: the add is commutative but this front end
 * keeps the source order in the encoding, and `v + a3` emits `adds r1, r2,
 * r4` where the original has `adds r1, r4, r2`.  The fourth parameter is
 * signed (the guard is `ble`, not `bls`).
 */
void func_0200E4CC(u8 *a0, u32 a1, u32 a2, int a3)
{
    u8 *p;
    u32 off;
    u8 v;

    if (a2 == 0)
        return;
    off = func_0200E488(a1, a2);
    p = a0 + 0x3c;
    v = p[off];
    if (a3 + v > 0x63) {
        p[off] = 0x63;
        return;
    }
    p[off] = v + (u8)a3;
}




int func_0200E4F8(int a0, int a1, int a2){ int t0; if ((unsigned int)(a2) == (unsigned int)(0)) {  return 0; } else { t0 = func_0200E488((int)(a1 + 0), (int)(a2 + 0)); return *(unsigned short *)(((char *)(((a0 + 0) + (t0 << 1))) + ((int)((0x55 << 2)) << 0))); } }





/*
 * Folds two arrays of pending increments into their saturating totals and
 * clears the increments: 30 u16 into u32 totals capped at 999999, then 150
 * u8 into u16 totals capped at 9999.  Seeded in layout/function_starts.txt
 * from its only caller, the bl at ov010 0x02169056 (w6_fix18).
 */
void func_0200E518(Tally *t)
{
    int i;

    for (i = 0; i < 30; i++) {
        t->total32[i] += t->add16[i];
        if (t->total32[i] > 999999) {
            t->total32[i] = 999999;
        }
        t->add16[i] = 0;
    }
    for (i = 0; i < 150; i++) {
        t->total16[i] += t->add8[i];
        if (t->total16[i] > 9999) {
            t->total16[i] = 9999;
        }
        t->add8[i] = 0;
    }
}





/*
 * Unlabelled arm9 leaf returning the constant 0x5C8 (a structure size); filed
 * as the relocation witness for ov021 callers 021D096C, 021D0BE4, 021D10A8
 * (wave A1).
 */
u32 func_0200E588(void)
{
    return 0x5C8;
}





/*
 * Clears the 0x5C8-byte save block (func_0200E588 returns its size):
 * a tail call to MI_CpuFill8(p, 0, 0x5C8).
 */
void func_0200E590(void *p)
{
    MI_CpuFill8(p, 0, 0x5C8);
}





/*
 * The two tests share one exit, so they have to be one conjunction with the
 * `return 0` written after it; as two separate `if (...) return 0;` statements
 * the compiler emits two copies of the `movs r0, #0; pop` pair and lands 28
 * bytes wrong.  EXACT*: the listing extent runs to the next label at
 * 0x0200E688, over three unlabelled followers.
 */
int func_0200E5A0(void *a0)
{
    if (((struct Obj11237 *)a0)->f5C6 == func_0203F1FC(a0, 0x5c6) &&
        ((struct Obj11237 *)a0)->f5C2 == 0xd68)
        return 1;
    return 0;
}





/*
 * Unlabelled arm9 leaf: true when bit 15 of the halfword at +0x5C4 is clear.
 * Filed as the relocation witness for ov021 func_021D09D0 (wave A1).
 */
int func_0200E5CC(void *p)
{
    if (((struct Obj15607 *)p)->f5C4 & 0x8000) {
        return 0;
    }
    return 1;
}





/*
 * Unlabelled arm9 leaf: the low seven bits of the halfword at +0x5C4. Filed
 * as the relocation witness for ov021 func_021D0C58 (wave A1).
 */
u16 func_0200E5E4(void *p)
{
    return ((struct Obj15608 *)p)->f5C4 & 0x7F;
}





/*
 * Unlabelled arm9 leaf: element idx of a five-entry array of 0x120 byte
 * records, the base itself when idx is out of range. Filed as the relocation
 * witness for ov021 func_021D0B58 (wave A1).
 */
char *func_0200E5F8(char *p, u32 idx)
{
    if (idx < 5) {
        p += idx * 0x120;
    }
    return p;
}





/*
 * Unlabelled arm9 function: loads save block 5 into a 0x1000 byte heap buffer,
 * copies its first 0x5C8 bytes to dst, then starts a save of block 5 and spins
 * on OS_WaitIrq until it reports done. Filed as the relocation witness for
 * ov021 func_021D0C58 (wave A1).
 */
void func_0200E608(void *sys, void *dst, u32 heap)
{
    u32 sv = (u32)func_02012EBC(sys);
    void *buf = func_02030734(heap, 0x1000, 0, data_020A721C, 0x99);

    func_020072CC(sv, 5, heap, buf, 0x1000);
    func_02082D44(dst, buf, 0x5C8);
    func_02012E4C(sys, 5);
    for (;;) {
        if (func_02012E7C(sys, 5) == 2) {
            break;
        }
        OS_WaitIrq(1, 1);
    }
    func_0200734C((struct Sub02007324Ctrl *)sv, 5);
    func_020307B0(buf);
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: sub_0200E684 toggles one flag half of a caller object's field pair
 * addressed by the constant id 0x5c6: it looks the field up through
 * func_0203F1FC, and if the stored halfword at +0x5c6 already equals the
 * looked-up value, rewrites the paired halfword at +0x5c2 with the constant
 * 0x7da and refreshes +0x5c6 with a second lookup.  sub_0200E6B0 is an
 * unlabelled getter returning the constant 0x28, sitting in what disasm.py
 * printed as trailing data after sub_0200E684 because it carries no
 * register-saving prologue; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E684.c \
 *       --addr 0x0200E684 --thumb
 */
void sub_0200E684(void *obj)
{
    u32 id = 0x5c6;
    if (*(u16 *)((u8 *)obj + id) == func_0203F1FC(obj, id)) {
        *(u16 *)((u8 *)obj + (id - 4)) = 0x7da;
        *(u16 *)((u8 *)obj + id) = func_0203F1FC(obj, id);
    }
}





u32 sub_0200E6B0(void)
{
    return 0x28;
}




/*
 * Promoted from src/pending/sub_0200E6B4.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/sub_020242A4.c's func_02024344, and
 * src/matched/unit_020242D8.c's func_020242D8), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E6B4.c \
 *       --func sub_0200E6B4 --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */
void sub_0200E6B4(void *obj)
{
    func_02024344(obj);
    func_020242D8((u8 *)obj + 8, 0);
    func_020242D8((u8 *)obj + 0x10, 1);
    func_020242D8((u8 *)obj + 0x18, 2);
    obj = (u8 *)obj + 0x20;
    func_020242D8(obj, 3);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a two-hop tail-call chain. sub_0200E6E8 is a pure forwarder to
 * sub_0200E6F0, which itself tail calls sub_020071CC with a fixed id of
 * 0x3e; both pass their argument through unchanged. Neither carries a
 * register-saving prologue, so disasm.py's sweep does not label
 * sub_0200E6F0 and it prints as data between the two literal pools; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md and
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E6E8.c \
 *       --addr 0x0200E6E8 --thumb
 */
void *sub_0200E6E8(u32 a)
{
    return sub_0200E6F0(a);
}




void *sub_0200E6F0(u32 a)
{
    return sub_020071CC((struct Sub020071CCCtrl *)a, 0x3e);
}




/*
 * One 8-byte record copied out: four u16 fields, so the copy unrolls to four
 * ldrh/strh pairs rather than an ldm/stm.  It has to be written as a struct
 * assignment: the same copy spelled field by field, or through a `u16 *`
 * temporary, picks the other register for the scaled index (r1 instead of
 * r3) and lands six bytes wrong.  EXACT*: the listing extent runs 192 bytes
 * because the follower at 0x0200E714 saves nothing and carries no label.
 */
void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst)
{
    *dst = src[idx];
}


/*
 * Unlabelled Thumb leaf that follows func_0200E6FC: copy one 8-byte record to dst[idx].
 */
void func_0200E714(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src)
{
    dst[idx] = *src;
}

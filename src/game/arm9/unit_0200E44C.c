/*
 * file:     unit_0200E44C.c
 * unit:     yes
 * function: func_0200E44C, func_0200E458, func_0200E460, func_0200E47C, func_0200E488, func_0200E49C, func_0200E4B0, func_0200E4CC, func_0200E4F8, func_0200E518, func_0200E588, func_0200E590, func_0200E5A0, func_0200E5CC, func_0200E5E4, func_0200E5F8, func_0200E608, func_0200E684, func_0200E6B4, func_0200E6E8, func_0200E6FC, func_0200E714, sub_0200E730, sub_0200E734, sub_0200E740, sub_0200E74C,, func_0200E7BC, func_0200E874, func_0200E878, func_0200E884, func_0200E89C, func_0200E8B0, func_0200E8B8, func_0200E8CC, func_0200E8D0, func_0200E8D8, func_0200E8E0, func_0200E8F8, func_0200E904, func_0200E918, func_0200E938, func_0200E958, func_0200E978, sub_0200E994, sub_0200E9DC, func_0200E9E0, func_0200E9F4, func_0200EA00, func_0200EA04, func_0200EA08, func_0200EA0C, func_0200EA14, func_0200EA1C, func_0200EA2C, func_0200EA3C, func_0200EBD0, func_0200EC14, func_0200EC2C, func_0200EC98, func_0200ECB4, func_0200ECD0, func_0200ECF0, func_0200ED14, func_0200ED38, func_0200ED3C, func_0200ED48, func_0200ED54, func_0200EDC4, func_0200EDEC
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
 *   func_0203F1FC 0x0203F1FC  thumb, not otherwise called in arm9_main
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
 *   func_02024344  0x02024344  thumb
 *   func_020242D8  0x020242D8  thumb
 *   sub_020071CC  0x020071CC  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02045F5C   0x02045F5C  arm
 *   func_0201F41C   0x0201F41C  thumb
 *   g_020A7370      0x020A7370  data
 *   func_02082A90 0x02082A90  arm
 *   func_02087C6C 0x02087C6C  arm
 *   _u32_div_f    0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_0200E918  0x0200E918  thumb
 *   func_0200E938  0x0200E938  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02017D70  0x02017D70  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045994  0x02045994  arm
 *   sub_0200EC14   0x0200EC14  thumb
 */
#include "../../matched/include/Obj11237.h"
#include "../../matched/include/Obj15607.h"
#include "../../matched/include/Obj15608.h"
#include "../../matched/include/Obj17086.h"
#include "../../matched/include/Obj08961.h"
#include "../../matched/include/Obj17088.h"
#include "../../matched/include/Obj17089.h"
#include "../../matched/include/Obj17090.h"
#include "../../matched/include/Obj15609.h"

struct Big;
struct Sub02007324Ctrl;
struct Sub020071CCCtrl;
struct MsgData;
struct Sav;
struct U16Vec;
struct Rec;
struct Date;
struct Strbuf;
struct Src0200EC2C;
struct Dst0200EC2C;
struct Out0200EC98;
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

struct RFC {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

typedef struct {
    u8 flag : 1;
    u8 level : 7;
} Flags;

struct Bits0200E7BC {
    u8 flag : 1;
    u8 level : 7;
};

struct Rec0200E7BC {
    u32 f00;
    u16 name[11];
    struct Bits0200E7BC bits;
    u8  f1b;
    u32 f1c;
};

typedef signed int     s32;

struct Entry {
    u16 species;
    u8  level;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u16 name[11];
    u16 ot[8];
    u16 f32[4];
};

struct Rec {
    struct Entry e[6];
    u16 year;
    u8  month;
    u8  day;
};

struct Date {
    u32 year;
    u32 month;
    u32 day;
};

struct Obj {
    u8  pad[0x1554];
    u32 unk1554;
    u32 unk1558;
};

struct Bits {
    u8 a : 6;
    u8 b : 2;
};

struct Src0200EC2C {
    u16 f00;
    u8  f02;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u8  f0C[0x16];
    u8  f22[0x10];
    u16 f32[4];
};

struct Dst0200EC2C {
    void *p00;
    void *p04;
    u32   f08;
    u32   f0C;
    u16   f10;
    u8    f12;
    u8    f13a : 6;
    u8    f13b : 2;
    u16   f14[4];
};

struct Out0200EC98 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct L0200ED54 {
    u32 arr[32];
    u32 count;
    u8 pad_84[0x617C];
    unsigned int f6200;
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
extern u32  func_02017E1C(void *mon, u32 id, u32 buf);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void  func_02082A90(void *dest, const void *src, u32 size);
extern void  func_02087C6C(void *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern void func_0200E938(u8 *obj, u32 id, void *dest);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_0200E904(void *p);
extern void func_0200DFCC(void *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0201AA18(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017D30(struct Sav *p);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u16   func_02045A98(void);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern int sub_0200EC14(char *o);
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
void func_0200E6FC(struct RFC *src, int idx, struct RFC *dst);
void func_0200E714(struct RFC *dst, int idx, struct RFC *src);
u32 sub_0200E730(void);
void sub_0200E734(void *dest);
u32 sub_0200E740(const void *obj, u32 idx);
u32 sub_0200E74C(const void *obj, u32 idx);
u32 sub_0200E76C(const void *obj, u32 idx);
u8 sub_0200E780(const void *obj, u32 idx);
u32 sub_0200E788(const void *unused, u32 a, u32 b);
u32 sub_0200E7A4(const void *obj, u32 idx);
void *sub_0200E7AC(void *obj, u32 idx);
u32 sub_0200E7B4(const void *obj, u32 idx);
void func_0200E7BC(struct Rec0200E7BC *o, int idx, void *mon);
int sub_0200E874(void);
void sub_0200E878(void *dst);
void sub_0200E884(void *sys, void *src);
void sub_0200E89C(void *sys, void *dest);
u32 sub_0200E8B0(void);
void sub_0200E8B8(void *dest);
void sub_0200E8CC(void);
void *sub_0200E8D0(void *obj);
u32 sub_0200E8D8(const void *obj);
void sub_0200E8E0(void *obj, u32 value);
u32 sub_0200E8E8(void);
void sub_0200E8EC(void *dest);
void *sub_0200E8F8(void *sys);
void sub_0200E904(void *obj);
u8 sub_0200E918(const u8 *base, u32 idx);
void sub_0200E920(u8 *base, u32 idx, int delta);
void sub_0200E938(u8 *obj, u32 id, void *dest);
void sub_0200E958(u8 *obj, u32 id, const void *src);
void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value);
u32 sub_0200E994(void *base, void *key);
unsigned int sub_0200E9DC(void);
void func_0200E9E0(void *a0);
void *func_0200E9F4(void *p);
int func_0200EA00(int p);
int func_0200EA04(int p);
int func_0200EA08(int p);
u32 func_0200EA0C(void);
u32 func_0200EA14(void);
void func_0200EA1C(void *p);
void func_0200EA2C(void *block);
void func_0200EA3C(struct Rec *rec, void *party, struct Date *date, u32 heap);
void func_0200EBD0(struct Obj *obj, void *a1, void *date, u32 heap);
int func_0200EC14(char *p);
void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
void sub_0200EC98(const u8 *o, struct Out0200EC98 *out);
u32 sub_0200ECB4(char *o);
u32 sub_0200ECC4(char *o, u32 n);
int sub_0200ECD0(char *o, int idx);
void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
void func_0200ED14(u8 *o, int idx, void *out);
u32 func_0200ED38(void);
void func_0200ED3C(void *block);
void *func_0200ED48(void *p);
void func_0200ED54(struct L0200ED54 *l, u32 val);
int sub_0200EDC4(struct L0200ED54 *l, u32 val);
int sub_0200EDEC(char *obj, int i);
void sub_0200EE14(char *obj, int i);
extern const char data_020A721C[];
extern void *g_020A7370;










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
void func_0200E6FC(struct RFC *src, int idx, struct RFC *dst)
{
    *dst = src[idx];
}








/*
 * Unlabelled Thumb leaf that follows func_0200E6FC: copy one 8-byte record to dst[idx].
 */
void func_0200E714(struct RFC *dst, int idx, struct RFC *src)
{
    dst[idx] = *src;
}







/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0200E76C, sub_0200E780, sub_0200E788, sub_0200E7A4,
 *           sub_0200E7AC, sub_0200E7B4
 *
 * alias: ten accessors on an array of 0x20-byte records, indexed by idx into
 * base + idx*0x20. sub_0200E730/sub_0200E734 are the constant-getter and
 * fill-user pair seen elsewhere in this packet: sub_0200E730 returns 0x40,
 * and sub_0200E734 zero-fills that many bytes at the given pointer.
 *
 * The byte at record offset +0x1a packs two fields, read by the next pair:
 * bit 0 is a plain flag (sub_0200E740), and bits [7:1] are a level clamped
 * into [0x41, 0x64] (sub_0200E74C, which adds 5 to the raw value once it is
 * at least 0x41 and clamps the low end up to 0x41 otherwise). The two
 * fields are declared as one bitfield struct so the compiler's lsls
 * #0x18 / lsrs #0x19 extraction for the 7-bit field is generated directly
 * instead of re-derived as a mask; see
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * sub_0200E76C/sub_0200E780 are a validity check and raw getter on the byte
 * at +0x1b (0xff means "unset"). sub_0200E788 ignores its first argument
 * (r0) and looks at the second and third (r1, r2): it returns 0x23c when
 * r1 == 1, 0x222 when r2 == 0x15, and 0x224 otherwise, apparently a cost
 * table keyed by two flags. sub_0200E7A4/sub_0200E7AC/sub_0200E7B4 are a
 * plain word getter at +0, a pointer-to-field getter at +4, and a plain
 * word getter at +0x1c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E730.c \
 *       --addr 0x0200E730 --thumb
 */
u32 sub_0200E730(void)
{
    return 0x40;
}







void sub_0200E734(void *dest)
{
    MI_CpuFill8(dest, 0, 0x40);
}







u32 sub_0200E740(const void *obj, u32 idx)
{
    return ((const Flags *)((const u8 *)obj + idx * 0x20 + 0x1a))->flag;
}







u32 sub_0200E74C(const void *obj, u32 idx)
{
    u32 level = ((const Flags *)((const u8 *)obj + idx * 0x20 + 0x1a))->level;
    if (level < 0x41) {
        level = 0x41;
    } else {
        level = (u8)(level + 5);
    }
    if (level > 0x64) {
        level = 0x64;
    }
    return level;
}







u32 sub_0200E76C(const void *obj, u32 idx)
{
    return *((const u8 *)obj + idx * 0x20 + 0x1b) != 0xff;
}







u8 sub_0200E780(const void *obj, u32 idx)
{
    return *((const u8 *)obj + idx * 0x20 + 0x1b);
}







u32 sub_0200E788(const void *unused, u32 a, u32 b)
{
    if (a == 1) {
        return 0x23c;
    }
    if (b == 0x15) {
        return 0x222;
    }
    return 0x224;
}







u32 sub_0200E7A4(const void *obj, u32 idx)
{
    return *(const u32 *)((const u8 *)obj + idx * 0x20);
}







void *sub_0200E7AC(void *obj, u32 idx)
{
    return (u8 *)obj + idx * 0x20 + 4;
}







u32 sub_0200E7B4(const void *obj, u32 idx)
{
    return *(const u32 *)((const u8 *)obj + idx * 0x20 + 0x1c);
}









/*
 * Fill slot idx of the 0x20-byte-stride record array that unit_0200E730's
 * ten accessors read (level in bits 1..7 of +0x1a, a "set" flag in bit 0,
 * the +0x1b byte or 0xff, words at +0 and +0x1c, an 11-u16 name at +4)
 * from a Pokemon via func_02017E1C: fields 0x9e, 0x71/0xa, 0, 7, then the
 * nickname (0x74) when field 0x75 says there is one, else the species name
 * (field 5) read out of the message bank at g_020A7370 into a stack buffer
 * and copied in.
 *
 * Two facts closed the 133-135-byte "pointer permutation" of the earlier
 * notes: the notes' struct had a stray pad byte before +0x1a (every field
 * from the bitfield on was one byte off), and every field is written as
 * o[idx].field rather than through a hoisted record pointer.  Written that
 * way mwcc keeps o and idx*32 in r5/r7 across all nine calls and CSEs
 * o + idx*32 into r4 for most, but not all, of the uses -- the image's
 * `adds r1, r5, r7` before the +0x1c store is exactly that.
 *
 * EXACT* because the listing extent runs over the unlabelled followers at
 * 0x0200E874/0x0200E878 (unit_0200E874.c); compiled bytes match exactly.
 */
void func_0200E7BC(struct Rec0200E7BC *o, int idx, void *mon)
{
    o[idx].bits.level = func_02017E1C(mon, 0x9e, 0);
    if (func_02017E1C(mon, 0x71, 0) != 0)
        o[idx].f1b = func_02017E1C(mon, 0xa, 0);
    else
        o[idx].f1b = 0xff;
    o[idx].f00 = func_02017E1C(mon, 0, 0);
    o[idx].f1c = func_02017E1C(mon, 7, 0);
    if (func_02017E1C(mon, 0x75, 0) != 0) {
        func_02017E1C(mon, 0x74, (u32)o[idx].name);
    } else {
        u16 buf[12];

        func_02045F5C(g_020A7370, func_02017E1C(mon, 5, 0), buf, 0xb);
        func_0201F41C(buf, o[idx].name, 0xb);
    }
    o[idx].bits.flag = 1;
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * The twelve bytes after func_0200E7BC: two unlabelled leaves that save
 * nothing at all, so their bytes print as part of the same `.word` run as
 * the pool word in front of them (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The first is a size
 * getter returning 0x10, the second is a tail call to the SDK's
 * MI_CpuFill8 (arm: the pool word is even, so `bx r3` switches to ARM) that
 * clears 0x10 bytes from whatever pointer it is handed.
 */
int sub_0200E874(void)
{
    return 0x10;
}







void sub_0200E878(void *dst)
{
    MI_CpuFill8(dst, 0, 0x10);
}








/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0200E8CC, sub_0200E8D0, sub_0200E8D8, sub_0200E8E0,
 *           sub_0200E8E8, sub_0200E8EC, sub_0200E8F8, sub_0200E904
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  sub_0200E884 and sub_0200E89C
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from sub_020071CC(id 0x40); sub_0200E8B0 hands back the constant 0x6204,
 * which sub_0200E8B8 uses as the zero-fill size for the whole object;
 * sub_0200E8CC is an empty hook; sub_0200E8D0 hands out the address 0x6000
 * bytes into the object; sub_0200E8D8/sub_0200E8E0 are a plain word
 * getter/setter on the field at +0x6200; sub_0200E8E8 returns the constant
 * 0x5c, which sub_0200E8EC's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * sub_0200E8E8, but the tail call inlines it); sub_0200E8F8 tail calls
 * sub_020071CC(sys, 0x41); sub_0200E904 zero-fills a separate 0x5a-byte
 * scratch object and hands it to func_02087C6C.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (sub_0200E884.c, sub_0200E89C.c, sub_0200E8B0.c, sub_0200E904.c) and
 * unit_0200E8B8.c: the five are contiguous in the image with no gap and no
 * intervening matched/sdk address, and the whole 0x0200E884..0x0200E918
 * range still reproduces EXACT as a single translation unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E884.c \
 *       --addr 0x0200E884 --thumb
 */
void sub_0200E884(void *sys, void *src)
{
    void *obj = sub_020071CC(src, 0x40);
    func_02082A90(sys, obj, 0x10);
}








void sub_0200E89C(void *sys, void *dest)
{
    void *obj = sub_020071CC(sys, 0x40);
    func_02082A90(obj, dest, 0x10);
}








u32 sub_0200E8B0(void)
{
    return 0x6204;
}








void sub_0200E8B8(void *dest)
{
    MI_CpuFill8(dest, 0, sub_0200E8B0());
}








void sub_0200E8CC(void)
{
}








void *sub_0200E8D0(void *obj)
{
    return (u8 *)obj + 0x6000;
}








u32 sub_0200E8D8(const void *obj)
{
    return *(const u32 *)&((struct L0200ED54 *)obj)->f6200;
}








void sub_0200E8E0(void *obj, u32 value)
{
    ((struct Obj17086 *)obj)->f6200 = value;
}








u32 sub_0200E8E8(void)
{
    return 0x5c;
}








void sub_0200E8EC(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}








void *sub_0200E8F8(void *sys)
{
    return sub_020071CC(sys, 0x41);
}








void sub_0200E904(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    func_02087C6C(obj);
}








/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a byte array at offset 6 of some base object, indexed by the second
 * parameter.  sub_0200E918 is the plain getter; sub_0200E920 adds a signed
 * delta to one element and clamps the result to 0..255 before storing it
 * back.  sub_0200E918 has no register-saving prologue (two instructions, no
 * push), so disasm.py's sweep never labelled it; it sits in the listing as a
 * .word between two functions.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E918.c \
 *       --addr 0x0200E918 --thumb
 */
u8 sub_0200E918(const u8 *base, u32 idx)
{
    return (base + idx)[6];
}








void sub_0200E920(u8 *base, u32 idx, int delta)
{
    u8 *p = base + 6;
    int v = p[idx] + delta;

    if (v > 0xff) {
        v = 0xff;
    } else if (v < 0) {
        v = 0;
    }
    p[idx] = (u8)v;
}








/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three accessors on an array of 6-byte records that starts 0xa bytes
 * into the object, indexed by "id mod 10".  sub_0200E938 reads a record out,
 * sub_0200E958 stores one in, and sub_0200E978 writes a single byte field at
 * +0x10 past an extra caller-given offset from the same slot.  Each divides
 * by 10 for the remainder only; the
 * quotient the helper also returns is never used, per
 * docs/idioms/div-and-mod-are-two-calls.md and
 * docs/idioms/runtime-helper-reloc.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E938.c \
 *       --addr 0x0200E938 --thumb
 */
void sub_0200E938(u8 *obj, u32 id, void *dest)
{
    u32 idx = id % 10;

    MI_CpuCopy8(obj + 0xa + idx * 8, dest, 6);
}








void sub_0200E958(u8 *obj, u32 id, const void *src)
{
    u32 idx = id % 10;

    MI_CpuCopy8(src, obj + 0xa + idx * 8, 6);
}








void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value)
{
    u32 idx = id % 10;
    u8 *p = obj + idx * 8;

    p += extra;
    p[0x10] = value;
}







/*
 * Linear search over up to 10 stored 6-byte keys: func_0200E918(base, 0)
 * gives the stored count (capped at 10), func_0200E938 copies the i'th key
 * into a stack buffer, and func_0203EFC8 (DWC's own key comparator)
 * compares it against the caller's key. Returns 1 on the first match, 0
 * if none of the stored keys match.
 *
 * EXACT* because the 70 compiled bytes fall six short of the disasm.py
 * extent: sub_0200E9DC, a four-byte constant getter with no
 * register-saving prologue, hides in the two trailing pad bytes plus this
 * function's own alignment filler (see "the two missing labels" in
 * docs/MATCHING.md); it is matched separately.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E994.c \
 *       --func sub_0200E994 --addr 0x0200E994 --cc 1.1p1
 */
u32 sub_0200E994(void *base, void *key)
{
    int i;
    int count = func_0200E918(base, 0);
    u8 buf[6];

    if (count > 10) {
        count = 10;
    }

    for (i = 0; i < count; i++) {
        func_0200E938(base, i, buf);
        if (func_0203EFC8(key, buf, 6) == 0) {
            return 1;
        }
    }
    return 0;
}




/*
 * A four-byte constant getter with no register-saving prologue; it was
 * hiding as the unlabelled follower behind sub_0200E994's EXACT* extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Its own
 * follower, sub_0200E9E0, already carries a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E9DC.c \
 *       --func sub_0200E9DC --addr 0x0200E9DC --cc 1.1p1
 */
unsigned int sub_0200E9DC(void)
{
    return 0x9c;
}






void func_0200E9E0(void *a0)
{
    func_0200E904(a0);
    func_0200DFCC((u8 *)a0 + 0x5a);
}






/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *func_0200E9F4(void *p)
{
    return func_020071CC(p, 0x3c);
}





/*
 * Unlabelled leaf accessor matched to give overlay call sites a matched
 * witness.  Addresses are Black-image addresses.
 */
int func_0200EA00(int p)
{
    return p + 0x5a;
}





int func_0200EA04(int p)
{
    return p + 0x5a;
}





int func_0200EA08(int p)
{
    return p;
}



u32 func_0200EA0C(void)
{
    return 0x155C;
}



/*
 * Save-table size callback: returns 0x16C, the size of the block that
 * func_0200EA2C clears.  Pointer word 0x0200EA15 at 0x0209DD44.
 */
u32 func_0200EA14(void)
{
    return 0x16C;
}



void func_0200EA1C(void *p)
{
    MI_CpuFill8(p, 0, 0x155C);
}




/*
 * Save-table init callback: clears the 0x16C-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200EA38).  Pointer word
 * 0x0200EA2D at 0x0209DD48.
 */
void func_0200EA2C(void *block)
{
    MI_CpuFill8(block, 0, 0x16C);
}




/*
 * Snapshot of a party into a 0x16c-byte ring record (func_0200EBD0's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of func_02017E1C is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from func_02045A98 in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct Entry is the one func_0200EC2C (EXACT*) reads back.
 *
 * Levers: the loop counter i is initialised AFTER the memset and before
 * n (both zeroes are then scheduled across the call with i first, which is
 * what puts i at sp+0x14 and n at sp+0x10); the species store goes through
 * rec->e[n] and every later field through the named entry pointer.
 *
 * EXACT* only because the 402 compiled bytes stop two short of the listing
 * extent at a "movs r0, r0" alignment filler; no byte differs.
 */
void func_0200EA3C(struct Rec *rec, void *party, struct Date *date, u32 heap)
{
    int count = func_0201AA18(party);
    void *buf = func_020457B0(11, heap);
    int i;
    int n;

    MI_CpuFill8(rec, 0, 0x168);
    i = 0;
    n = 0;
    for (; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 saved = func_02017D30(mon);
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            struct Entry *e = &rec->e[n];
            rec->e[n].species = func_02017E1C(mon, 5, 0);
            e->level = func_02017E1C(mon, 0x9e, 0);
            e->f03a = func_02017E1C(mon, 0x6f, 0);
            e->f03b = func_02017E1C(mon, 0x6e, 0);
            e->f04 = func_02017E1C(mon, 0, 0);
            e->f08 = func_02017E1C(mon, 7, 0);
            e->f32[0] = func_02017E1C(mon, 0x36, 0);
            e->f32[1] = func_02017E1C(mon, 0x37, 0);
            e->f32[2] = func_02017E1C(mon, 0x38, 0);
            e->f32[3] = func_02017E1C(mon, 0x39, 0);
            if (buf != 0) {
                func_02017E1C(mon, 0x73, (u32)buf);
                func_02045A38(buf, e->name, 11);
                func_02017E1C(mon, 0x8d, (u32)buf);
                func_02045A38(buf, e->ot, 8);
            } else {
                e->name[0] = func_02045A98();
                e->ot[0] = func_02045A98();
            }
            n++;
        }
        func_02017D70(mon, saved);
    }
    rec->year = date->year;
    rec->month = date->month;
    rec->day = date->day;
    if (buf != 0) {
        func_02045808(buf);
    }
}




/*
 * Ring-buffer record dispatcher: while the saturating counter at +0x1558 is
 * below 9999, hand the 0x16c-byte record at slot +0x1554 to func_0200EA3C,
 * then advance the slot (wrapping at 15) and the counter.
 *
 * The residue that stood for four passes (r6 vs r1, push one register
 * narrower) was the parameter list: func_0200EA3C takes FOUR arguments
 * (its prologue homes r0..r3), and this function forwards its own r1..r3 to
 * it untouched.  With a1..a3 live in r1..r3 across the prologue the index
 * temporary cannot take r1 and lands in r6.  The only caller
 * (ov205 0x021B9B62) passes (obj, func_02012934 result, &stack date record
 * from func_02088864, 4).  The slot index is read inline in the call's
 * argument, not through a named local.
 *
 * Current listing extent is 68 bytes; compiled bytes match exactly.
 */
void func_0200EBD0(struct Obj *obj, void *a1, void *date, u32 heap)
{
    if (obj->unk1558 < 9999) {
        u32 idx;
        func_0200EA3C((struct Rec *)((u8 *)obj + obj->unk1554 * 0x16c), a1, date, heap);
        idx = obj->unk1554 + 1;
        obj->unk1554 = idx;
        if (idx >= 15) {
            obj->unk1554 = 0;
        }
        obj->unk1558 += 1;
    }
}



/*
 * An unlabelled leaf: it saves nothing, so disasm.py's lr-saving prologue
 * sweep never fired and the bytes print as a run of `.word` in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing in
 * the image branches to it either, so no `function_starts.txt` seed exists.
 * First zero halfword of six 0x3c-byte records.
 *
 * It is not an anonymous hole, though: sub_0200ECD0 (src/matched/
 * unit_0200EC98.c) tail-calls it through a pool word, which is why that file
 * could not resolve its one relocation until this entry existed -- the
 * `matched` class is the only witness 0x0200EC14 can ever have, since no
 * branch anywhere in the image names it and its address appears in exactly
 * one pool.
 */
int func_0200EC14(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(u16 *)(p + i * 0x3c) == 0)
            break;
    }
    return i;
}



/*
 * One record of a 0x3c-byte table copied into a destination object.
 *
 * This closes the 76-byte residue that docs/notes/pkt_0200EA3C.c.txt
 * section 2 recorded.  Three spellings had to hold at once:
 *
 *  1. the byte at source +3 is a `u8 :6 / u8 :2` bitfield PAIR, not a plain
 *     u8.  The source side is what produces the `lsls #26 / lsrs #26` pair
 *     the note could not reach; reading it as a plain u8 and shifting gives
 *     `ands` instead and compiles 104 bytes.
 *  2. the destination byte at +0x13 is the same bitfield pair.  That is what
 *     turns the insert into `movs r1, #0x3f; ands r1, r3` rather than a
 *     single immediate mask.  Both sides are needed: either one alone is
 *     still wrong.
 *  3. the source pointer must be `const`.  Without it, the store to
 *     dst->f13a may alias s->f03a, so mwcc reloads `ldrb [r4, #3]` a second
 *     time for the `:2` field, two bytes over at 110.  The original loads it
 *     once into r2 and keeps it live across the first insert.  See
 *     docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *
 * EXACT* : the inferred extent ran to 0x0200ECF0 because the accessor at
 * 0x0200EC98 saves no lr and so carries no label.  0x0200EC98 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200EC2C.c \
 *       --func func_0200EC2C --addr 0x0200EC2C --cc 1.1p1 --thumb
 */
void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst)
{
    const struct Src0200EC2C *s = base + idx;
    int i;

    dst->f10 = s->f00;
    dst->f12 = s->f02;
    dst->f08 = s->f04;
    dst->f0C = s->f08;
    dst->f13a = s->f03a;
    dst->f13b = s->f03b;

    func_02045994(dst->p00, (const u16 *)s->f0C, 0xb);
    func_02045994(dst->p04, (const u16 *)s->f22, 8);

    for (i = 0; i < 4; i++)
        dst->f14[i] = s->f32[i];
}



/*
 * An unlabelled leaf accessor (it saves no lr, so disasm.py gives it no
 * label, see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It unpacks the three fields at +0x168..+0x16b of the object into a
 * four-word output record and zeroes the fourth word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EC98.c \
 *       --func sub_0200EC98 --addr 0x0200EC98 --cc 1.1p1 --thumb
 */
void sub_0200EC98(const u8 *o, struct Out0200EC98 *out)
{
    out->a = *(const u16 *)&((struct Obj08961 *)o)->f168;
    out->b = o[0x16a];
    out->c = o[0x16b];
    out->d = 0;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * func_0200EBD0 and func_0200EC2C work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * sub_0200EC98 (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * sub_0200ECD0 is a tail call through a pool word to
 * src/matched/func_0200EC14.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
u32 sub_0200ECB4(char *o)
{
    u32 v = ((struct Obj17088 *)o)->f1558;

    if (v >= 0xf)
        v = 0xf;
    return v;
}



u32 sub_0200ECC4(char *o, u32 n)
{
    return ((struct Obj17089 *)o)->f1558 - n;
}



int sub_0200ECD0(char *o, int idx)
{
    int n = ((struct Obj17090 *)o)->f1554 - 1 - idx;

    if (n < 0)
        n += 0xf;
    return sub_0200EC14(o + n * 0x16c);
}



void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3)
{
    int v = ((struct Obj15609 *)a0)->f1554 - 1 - (int)a1;

    if (v < 0)
        v += 0xf;
    func_0200EC2C((const struct Src0200EC2C *)((u8 *)a0 + v * 0x16c), (int)a2, a3);
}



/*
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of func_0200ECF0): the header of ring entry `count - 1 - idx`, a tail call
 * to sub_0200EC98 through a pool word. Same shape as sub_0200ECD0 in
 * unit_0200ECB4.c. Its only caller is ov171 func_021DCCC8.
 */
void func_0200ED14(u8 *o, int idx, void *out)
{
    int n = *(int *)(o + 0x1554) - 1 - idx;

    if (n < 0)
        n += 0xf;
    sub_0200EC98(o + n * 0x16c, out);
}



/*
 * Save-table size callback: returns 0xFC, the size of the block that
 * func_0200ED3C clears.  Pointer word 0x0200ED39 at 0x0209DD5C.
 */
u32 func_0200ED38(void)
{
    return 0xFC;
}



/*
 * Save-table init callback: clears the 0xFC-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200ED44).  Pointer word
 * 0x0200ED3D at 0x0209DD60.
 */
void func_0200ED3C(void *block)
{
    MI_CpuFill8(block, 0, 0xFC);
}



void *func_0200ED48(void *p)
{
    return func_020071CC(p, 0x44);
}



/*
 * Insert `val` into a 32-entry u32 list unless it is already there: the
 * table is the object's first 0x80 bytes and the count lives at +0x80.
 * When the value is found at index i, everything above it shifts up one
 * slot (the memmove) and the value is rewritten into the last live slot
 * (`p[-1]` on a pointer to one past the end), so the list keeps its
 * length; when it is not found and there is room it goes at the end, and
 * when the list is full the whole table shifts up one slot and the value
 * lands in slot 31.
 *
 * Two shapes the bytes pinned down, both from
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md and the
 * signed/unsigned split:
 *
 *  - the copy is MI_CpuCopy8(src, dst, size) -- the SDK's argument order,
 *    which is why the source passes the higher index first: the shift is
 *    downward, arr[i+1] is copied onto arr[i];
 *  - the trailing store is NOT `l->arr[l->count - 1]` (which subtracts one
 *    from the count and then scales) but `p[-1]` on a pointer computed as
 *    `l->arr + l->count`: the original scales the count by four first and
 *    subtracts the element size afterwards, four instructions against
 *    three and the whole tail shifts;
 *  - the walk is unsigned (`bls`/`blo`) while the element count `n` that
 *    gates the shift is signed (`ble`).
 *
 * EXACT* rather than EXACT: the follower at 0x0200EDC4 saves registers but
 * not lr, so disasm.py did not label it (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md) and the inferred extent
 * runs to 0x0200EE48. The bytes all match; see
 * src/matched/unit_0200EDC4.c for that follower, which this project can
 * reproduce but has not been able to seed in layout/function_starts.txt.
 */
void func_0200ED54(struct L0200ED54 *l, u32 val)
{
    u32 i;
    int n;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] != val)
            continue;
        n = (int)l->count - 1 - (int)i;
        if (n <= 0)
            return;
        MI_CpuCopy8(&l->arr[i + 1], &l->arr[i], (u32)n * 4);
        {
            u32 *p = l->arr + l->count;
            p[-1] = val;
        }
        return;
    }

    if (l->count < 32) {
        l->arr[l->count] = val;
        l->count++;
        return;
    }

    MI_CpuCopy8(&l->arr[1], &l->arr[0], 0x7c);
    l->arr[31] = val;
    l->count = 32;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow func_0200ED54 (src/matched/
 * func_0200ED54.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * func_0200ED54 inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
int sub_0200EDC4(struct L0200ED54 *l, u32 val)
{
    u32 i;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] == val)
            return 1;
    }
    return 0;
}


int sub_0200EDEC(char *obj, int i)
{
    u32 *bits = (u32 *)(obj + 0x84);

    return (bits[i / 32] >> (i % 32)) & 1;
}


void sub_0200EE14(char *obj, int i)
{
    if (i >= 256)
        return;
    ((u32 *)(obj + 0x84))[i / 32] |= (u32)(1 << (i % 32));
}

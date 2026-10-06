/*
 * file:     pokeparty_p05.c
 * unit:     yes
 * function: func_0201A4D4, func_0201A570, func_0201A59C, func_0201A5FC, func_0201A858, func_0201A918, func_0201A920, func_0201A948, func_0201A954, func_0201A98C, func_0201A9C8, func_0201AA14, func_0201AA18, func_0201AA1C, func_0201AA50, func_0201AA88, func_0201AAD4, func_0201AB08, func_0201AB18, func_0201AB28, func_0201AB34, func_0201AB48, func_0201AB8C, func_0201AC2C, func_0201AC44, func_0201AC80, func_0201ACC4, func_0201ACDC, func_0201AD0C, func_0201AD18, func_0201AD40, func_0201AD58, func_0201AD88, func_0201ADA4, func_0201ADD0, func_0201ADE4, func_0201AE14, func_0201AE1C, func_0201AF6C, func_0201AF80, func_0201AFD4, func_0201B038, func_0201B100, func_0201B170, func_0201B220, func_0201B25C, func_0201B268, func_0201B280, func_0201B28C, func_0201B2B0, func_0201B718, func_0201B764, func_0201B774, func_0201B7A0
 * address:  0x0201A4D4
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
 *   func_02030734 0x02030734  arm
 *   func_020457B0 0x020457B0  arm
 *   func_02045808 0x02045808  arm
 *   func_02045B38 0x02045B38  arm
 *   func_02045EC0 0x02045EC0  arm
 *   tbl_0209E444  0x0209E444  data
 *   func_02045C04   0x02045C04  arm
 *   func_020307B0   0x020307B0  arm
 *   g_0209E424      0x0209E424  data
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0201A26C   0x0201A26C  thumb
 *   func_02019DA4   0x02019DA4  thumb
 *   sub_0201A920_File  0x020A7304  data
 *   sub_0201AB8C_File  0x020A7304  data
 *   sub_020071CC  0x020071CC  thumb
 *   g_0214652C  0x0214652C  data
 *   sub_0201ADE4_File  0x020A7310  data
 *   func_0204A39C  0x0204A39C  arm
 *   _ull_mul       0x0209C054  arm
 *   sub_0201AA18   0x0201AA18  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02020FE4   0x02020FE4  thumb
 *   sub_0201AC44    0x0201AC44  thumb
 *   func_02011410   0x02011410  thumb
 *   _s32_div_f      0x0209C0A4  arm
 *   s_shinka_check_c 0x020A7330 data  a1
 *   g_020A7320      0x020A7320  data  a2
 *   g_020A7322      0x020A7322  data  a2
 *   g_020A7324      0x020A7324  data  a2
 *   g_020A732A      0x020A732A  data  a2
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02048F4C  0x02048F4C  arm
 *   g_0209E45C     0x0209E45C  data
 *   func_0201B850  0x0201B850  thumb
 */
#include "../../matched/include/Obj06868.h"
#include "../../matched/include/Obj11261.h"
#include "../../matched/include/Obj15718.h"
#include "../../matched/include/Obj15719.h"
#include "../../matched/include/Obj17207.h"
#include "../../matched/include/Obj17208.h"

struct MsgBank;
struct U16Vec;
struct Rec;
struct Reg;
struct Sav;
struct Sub020071CCCtrl;
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int           s32;

struct PartyMon {
    u32 w[0x37];
};

struct Party_0201A4D4 {
    s32 capacity;
    s32 count;
    struct PartyMon mon[6];
    u8  unk530;
};

typedef u32 (*Predicate)(void *entry);

struct Party_0201AB28 {
    u32 unk00;
    u32 count;
    struct PartyMon mon[6];
};

struct Rec534 {
    u32 unk000[0x14D];
};

struct Personal_0201AE1C {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u16 ev0 : 2;
    u16 ev1 : 2;
    u16 ev2 : 2;
    u16 ev3 : 2;
    u16 ev4 : 2;
    u16 ev5 : 2;
    u16 unk0A_12 : 1;
    u16 unk0A_13 : 3;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u16 unk1E;
    u8  unk20;
    u8  unk21_0 : 6;
    u8  unk21_6 : 1;
    u8  unk21_7 : 1;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

struct Personal_0201AFD4 {
    u8  unk00[0x1C];
    u16 unk1C;
    u8  unk1E[2];
    u8  unk20;
    u8  unk21[0x1B];
};

typedef unsigned long long u64;

typedef int            s32_0201B100;

typedef int            s32_0201B220;

typedef signed int     s32_0201B2B0;

struct EvoRow_0201B2B0 {
    u16 method;
    u16 param;
    u16 target;
};

typedef int            s32_0201B70C;

struct EvoRow_0201B70C {
    u16 method;
    u16 param;
    u16 species;
};

struct EvoTable {
    struct EvoRow_0201B70C rows[7];
    u16 unk2A;
};

typedef signed char s8;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32 func_0201AA18(void *a1);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201A26C(void *a0, u32 a1);
extern int func_02019DA4(void *a0, void *a1);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02017528(struct Sav *p);
void sub_0201A948(struct Party_0201A4D4 *p);
void sub_0201A954(struct Party_0201A4D4 *p, s32 capacity);
u32 sub_0201AA14(void *p);
u32 sub_0201AA18(void *p);
u32 sub_0201AA1C(void *p);
u32 sub_0201AA50(void *p);
u32 sub_0201AA88(void *p);
u32 sub_0201AAD4(void *p);
u32 sub_0201AB08(void *p);
u32 sub_0201AB18(void *p);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02049578(struct ArcFile *handle, u32 x);
extern void *func_0204960C(void *handle, void *x);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void  func_02048F4C(void *c, u32 id, u32 arg);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void  func_02017E40(void *mon, u32 id, u32 v);
extern u32   func_0203F0A8(void);
void *sub_0201AB28(void *p, u32 idx);
u32 sub_0201AB34(void *p, u32 idx);
u32 sub_0201AE1C(const struct Personal_0201AE1C *p, u32 field);
extern u32   func_02017E88(void *mon, u32 id, u32 v);
extern void *func_020185F0(void *a);
extern u32   func_02020FE4(u32 id, u32 sel, u16 heap);
extern u32 sub_0201AC44(struct Rec *p, u32 target);
extern u32   func_02011410(u32 tz);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_0201B850(void *mon, const s8 *tbl, int a2, u32 a3);
u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3);
void func_0201A570(void *a0);
int func_0201A59C(void *a0, void *a1, void *a2);
int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4);
int func_0201A858(u8 *a);
int func_0201A918(void);
struct Party_0201A4D4 *sub_0201A920(u32 heap);
u32 sub_0201AC80(void *p);
int sub_0201ACC4(void *p, u32 pos);
void sub_0201ACDC(void *p, u32 pos, u32 mode);
void *sub_0201AD0C(void *sys);
u32 sub_0201AD18(void *p);
u32 sub_0201AD40(void *p);
u32 sub_0201AD58(void *p, Predicate pred);
void sub_0201AD88(u32 heap);
void sub_0201ADA4(u32 a, int b, void *c);
void sub_0201ADD0(u32 a, int b, void *c);
void *sub_0201ADE4(u32 a, int b, u32 c);
void sub_0201AE14(void *p);
u32 sub_0201AE1C(const struct Personal_0201AE1C *p, u32 field);
u16 *sub_0201AF80(u32 heap, u16 *countOut);
u32 sub_0201AFD4(u32 species, s32 form);
void sub_0201B038(void *party);
void sub_0201B100(void *party, s32_0201B100 amount);
void sub_0201B170(void *party);
u32 sub_0201B220(void *party);
u32 sub_0201B25C(void *a);
u32 sub_0201B268(void *mon);
u32 sub_0201B280(void *a);
u32 sub_0201B28C(void *mon);
u32 sub_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
void *sub_0201B70C(u32 heap);
u32 sub_0201B718(void *a, u32 id, u32 row, u32 field);
void sub_0201B764(u32 id, void *dest);
u32 sub_0201B774(void *mon, u32 move);
void func_0201B7A0(void *a0, int a1, int a2, int a3);
extern u8 tbl_0209E444[];
extern const u8 g_0209E424[6];
extern const char sub_0201A920_File[];
extern const char sub_0201AB8C_File[];
extern void *g_0214652C;
extern const char sub_0201ADE4_File[];
extern u8 s_shinka_check_c[];
extern const u16 g_020A7320[1];
extern const u16 g_020A7322[1];
extern const u16 g_020A7324[3];
extern const u16 g_020A732A[3];
extern const s8 g_0209E45C[];





/*
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */
u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3)
{
    u8 *v7;
    u32 v10;
    int i;
    u32 f;

    v7 = (u8 *)func_02030734(a2, 0x38, 1, (const char *)0x020A72F0, 0x312);
    ((struct Obj06868 *)v7)->f0 = (u32)func_02045B38(0, 2, 0xa5, a2);
    v10 = (u32)func_020457B0(0x40, a2);
    f = ((struct Obj15718 *)a0)->fAB;
    if (f == 2)
        ((struct Obj06868 *)v7)->f34 = a3;
    else
        ((struct Obj06868 *)v7)->f34 = f;
    for (i = 0; i < 6; i++) {
        int off = i * 4;
        u8 *q = v7 + off;

        ((struct Obj11261 *)q)->f4 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06868 *)v7)->f0), i);
        ((struct Obj11261 *)q)->f1C =
            ((u32 (*)(u8 *, u32, u8 *, u32, u32))
                 (*(u32 *)(tbl_0209E444 + off)))(a0, a1, v7, v10, a2);
    }
    func_02045808((struct U16Vec *)v10);
    return v7;
}





/*
 * EXACT* note: the 42 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A59A before the next labelled function at 0x0201A59C.
 *
 * Six records of 0x20 bytes, each with a pair of ARM calls at +4 and +0x1C,
 * then the object's first word through the ARM at 0x02045C04 and the object
 * itself through 0x020307B0.  The loop index is a signed int, so the bound
 * test is `blt` and no truncation appears.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A570.c \
 *       --func func_0201A570 --addr 0x0201A570 --cc 1.1p1 --thumb
 */
void func_0201A570(void *a0)
{
    int i;

    for (i = 0; i < 6; i++) {
        func_02045808((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 4)));
        func_02045808((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 0x1C)));
    }
    func_02045C04((struct Rec *)(((struct Obj15719 *)a0)->f0));
    func_020307B0(a0);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201A59C.c \
 *       --func func_0201A59C --addr 0x0201A59C --cc 1.1p1 --thumb
 */
int func_0201A59C(void *a0, void *a1, void *a2)
{
    char buf[6];

    buf[0] = g_0209E424[0];
    buf[1] = g_0209E424[1];
    buf[2] = g_0209E424[2];
    buf[3] = g_0209E424[3];
    buf[4] = g_0209E424[4];
    buf[5] = g_0209E424[5];

    if (func_0201A858((u8 *)buf) != 0) {
        do {
            if (func_0201A5FC(a0, a1, (u8 *)buf, a2, 0) == 1) {
                return 1;
            }
        } while (func_0201A858((u8 *)buf) != 0);
    }

    return 0;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A5FC.c  *       --func func_0201A5FC --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4)
{
    u8 count = 0;
    u32 arr5c[6] = {0};
    u32 arr44[6] = {0};
    u32 arr2c[6] = {0};
    u8 i;
    int flag;
    u32 acc;
    void *p;
    u32 v18;
    u32 v14;
    u32 v10;
    u8 n;
    u8 j;
    u32 v6;
    u32 k1;
    u8 k;
    u32 k2;
    u32 r;
    int found;

    acc = 0;
    v10 = (u32)(int)func_0200AE54(a0, (int)6);

    if (a3 != 0)
        *a3 = 0;
    if (a4 != 0)
        *a4 = 0;

    for (i = 0; i < 6; i++) {
        if (a2[i] == 0)
            continue;
        n = (u8)(a2[i] - 1);
        if ((int)n >= (int)func_0201AA18(a1))
            continue;
        p = func_0201AB28(a1, n);
        v18 = func_02017E1C(p, 5, 0);
        v6 = func_02017E1C(p, 6, 0);
        v14 = (u32)func_0201A26C(a0, func_02017E1C(p, 0x9e, 0));
        r = func_02019DA4(a0, p);
        if (r != 0) {
            if (a4 != 0)
                *a4 |= r;
            continue;
        }
        flag = 1;
        for (j = 0; j < count; j++) {
            if ((int)func_0200AE54(a0, (int)7) == 0 && v18 == arr5c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 8;
                break;
            }
            if ((int)func_0200AE54(a0, (int)8) == 0 && v6 != 0 && v6 == arr2c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 0x10;
                break;
            }
        }
        if (flag == 0)
            continue;
        if (v10 != 0 && (u32)(acc + v14) > v10) {
            if (a4 != 0)
                *a4 |= 0x100;
            continue;
        }
        if (a3 != 0)
            a3[count] = (char)(n + 1);
        arr5c[count] = v18;
        arr44[count] = func_02017E1C(p, 0x6f, 0);
        arr2c[count] = v6;
        acc = (u16)(acc + (u16)v14);
        count = (u8)(count + 1);
        if ((int)count < (int)func_0200AE54(a0, (int)3))
            continue;
        if (a4 != 0 && count < 6 && a2[count] != 0)
            *a4 |= 1;
        break;
    }

    if ((int)count >= (int)func_0200AE54(a0, (int)2)) {
        k1 = (u32)(int)func_0200AE54(a0, (int)0xb);
        found = 1;
        if (k1 != 0) {
            k2 = (u32)(int)func_0200AE54(a0, (int)0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (k1 == arr5c[k] && k2 == arr44[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (a4 != 0)
            *a4 |= 0x80;
    } else {
        if (a4 != 0)
            *a4 |= 1;
    }
    return 0;
}





/*
 * A base-7 odometer with a distinctness test: six nested counters (a[0]
 * outermost) over 0..6, and the innermost body returns 1 as soon as all six
 * values differ.  The entry `a[5]++` is the source's own first statement, not
 * a loop increment.
 *
 * The fifteen `!=` tests are one conjunction: every `cmp` in the listing
 * branches to the same increment block (0x0201A8B8) on equality, which is the
 * "guard chain sharing one exit block" spelling, not a chain of ifs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A858.c \
 *       --func func_0201A858 --addr 0x0201A858 --cc 1.1p1 --thumb
 */
int func_0201A858(u8 *a)
{
    a[5]++;
    while (a[0] <= 6) {
        while (a[1] <= 6) {
            while (a[2] <= 6) {
                while (a[3] <= 6) {
                    while (a[4] <= 6) {
                        while (a[5] <= 6) {
                            if (a[0] != a[1] && a[0] != a[2] &&
                                a[0] != a[3] && a[0] != a[4] &&
                                a[0] != a[5] && a[1] != a[2] &&
                                a[1] != a[3] && a[1] != a[4] &&
                                a[1] != a[5] && a[2] != a[3] &&
                                a[2] != a[4] && a[2] != a[5] &&
                                a[3] != a[4] && a[3] != a[5] &&
                                a[4] != a[5]) {
                                return 1;
                            }
                            a[5]++;
                        }
                        a[5] = 1;
                        a[4]++;
                    }
                    a[4] = 1;
                    a[3]++;
                }
                a[3] = 1;
                a[2]++;
            }
            a[2] = 1;
            a[1]++;
        }
        a[1] = 1;
        a[0]++;
    }
    return 0;
}




/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
int func_0201A918(void)
{
    return 0x534;
}





/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
struct Party_0201A4D4 *sub_0201A920(u32 heap)
{
    struct Party_0201A4D4 *p = (struct Party_0201A4D4 *)func_02030734(heap, sizeof(struct Party_0201A4D4), 0,
                                                   sub_0201A920_File, 65);

    sub_0201A948(p);
    return p;
}





/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
void sub_0201A948(struct Party_0201A4D4 *p)
{
    sub_0201A954(p, 6);
}

/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
void sub_0201A954(struct Party_0201A4D4 *p, s32 capacity)
{
    s32 i;

    MIi_CpuClearFast(0, p, sizeof(struct Party_0201A4D4));
    p->capacity = capacity;
    p->count = 0;
    p->unk530 = 0;
    for (i = 0; i < 6; i++) {
        func_02017528((struct Sav *)(&p->mon[i]));
    }
}

/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
u32 sub_0201A98C(struct Party_0201A4D4 *p, const struct PartyMon *src)
{
    if (p->count >= p->capacity) {
        return 0;
    }
    p->mon[p->count] = *src;
    sub_0201ACDC(p, p->count, 1);
    p->count = p->count + 1;
    return 1;
}

/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
u32 sub_0201A9C8(struct Party_0201A4D4 *p, s32 idx)
{
    s32 i;

    for (i = idx; i < p->count - 1; i++) {
        p->mon[i] = p->mon[i + 1];
    }
    func_02017528((struct Sav *)(&p->mon[i]));
    p->count = p->count - 1;
    return 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from sub_0201AA1C (0x0201AA1C, still open)
 * and sub_0201AA18 is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */
u32 sub_0201AA14(void *p)
{
    return ((struct Obj17207 *)p)->f0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from sub_0201AA1C (0x0201AA1C, still open)
 * and sub_0201AA18 is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */
u32 sub_0201AA18(void *p)
{
    return ((struct Obj17208 *)p)->f4;
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AA1C(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0x4C, 0) != 1) {
            n++;
        }
    }
    return n;
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AA50(void *p)
{
    u32 n = 0;
    s32 count;
    s32 i;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        sub_0201AB28(p, i);
        if (sub_0201AD18(sub_0201AB28(p, i)) != 0) {
            n++;
        }
    }
    return n;
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AA88(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);
        u32 a = func_02017E1C(entry, 0x4C, 0);
        u32 b = func_02017E1C(entry, 3, 0);

        if (a == 1 && b == 0) {
            n++;
        }
    }
    return n;
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AAD4(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 3, 0) == 1) {
            n++;
        }
    }
    return n;
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AB08(void *p)
{
    return sub_0201AD58(p, sub_0201AD18);
}


/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AB18(void *p)
{
    return sub_0201AD58(p, sub_0201AD40);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201AB28 is the index calculator this whole neighbourhood shares: an
 * entry of an array of 0xDC-byte records starting eight bytes into the
 * object.  sub_0201AB34 looks the entry up and, if it is non-null (in
 * practice it always is; the check reads as a defensive null guard rather
 * than a reachable branch), tail-hands it to sub_0201AD18 (0x0201AC2C..,
 * still open at the time of writing but pinned as an extern here since a
 * `label` witness for it exists outside this range).
 *
 * Immediately in front of sub_0201AB28, at 0x0201AB08..0x0201AB28, are two
 * back to back linker long-branch veneers (`ldr r1,[pc,#4]; ldr r3,[pc,#8];
 * bx r3` plus two pool words each) that this file does not claim; see
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for the general shape, though here both are Thumb-encoded stubs rather
 * than the ARM long-branch form.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB28.c \
 *       --addr 0x0201AB28 --thumb
 */
void *sub_0201AB28(void *p, u32 idx)
{
    return (u8 *)p + 8 + idx * 0xDC;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201AB28 is the index calculator this whole neighbourhood shares: an
 * entry of an array of 0xDC-byte records starting eight bytes into the
 * object.  sub_0201AB34 looks the entry up and, if it is non-null (in
 * practice it always is; the check reads as a defensive null guard rather
 * than a reachable branch), tail-hands it to sub_0201AD18 (0x0201AC2C..,
 * still open at the time of writing but pinned as an extern here since a
 * `label` witness for it exists outside this range).
 *
 * Immediately in front of sub_0201AB28, at 0x0201AB08..0x0201AB28, are two
 * back to back linker long-branch veneers (`ldr r1,[pc,#4]; ldr r3,[pc,#8];
 * bx r3` plus two pool words each) that this file does not claim; see
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for the general shape, though here both are Thumb-encoded stubs rather
 * than the ARM long-branch form.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB28.c \
 *       --addr 0x0201AB28 --thumb
 */
u32 sub_0201AB34(void *p, u32 idx)
{
    void *entry = sub_0201AB28(p, idx);

    if (entry != 0) {
        return sub_0201AD18(entry);
    }
    return 0;
}



/*
 * pokeparty.c: the store-at-index and swap-two-indices operations on the
 * party container, an array of 0xDC byte records eight bytes into the object
 * with a running count at +0x04.  The file name is the image's own: the debug
 * allocator call in sub_0201AB8C passes 0x020A7304, which spells
 * "pokeparty.c", and its neighbours in the string area are
 * "poke_regulation.c" and "poke_personal.c".
 *
 * Both functions copy a whole record with a plain struct assignment, which
 * this front end inlines as a counted `ldm`/`stm` loop of 27 eight-byte steps
 * plus a trailing word rather than as a call
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).  The record is
 * declared as an array of `u32` and not of `u8` for exactly that reason: a
 * one-aligned declaration gives a byte loop of 0xDC iterations, the same
 * shape with completely different bytes.
 *
 * sub_0201AB48 reads field 0xA9 (the "slot is occupied" derived id, see
 * src/pending/sub_02018E34.c) out of the destination slot before the copy and
 * out of the source after it, and adds the difference to the count, so the
 * count stays right whether the write fills an empty slot or overwrites a
 * full one.
 *
 * Two spellings in sub_0201AB48 are load bearing and neither is obvious.  The
 * destination of the copy is written as byte arithmetic,
 * `(u8 *)p + idx * sizeof(rec) + 8`, while the getter's argument is the
 * ordinary `&p->mon[idx]`: written the same way twice the compiler common
 * subexpression eliminates them and keeps the finished address in a
 * callee-saved register across both calls, which is four bytes short.  What
 * the original keeps alive across the calls is the *product*, and only two
 * differently associated address expressions produce that.  And the second
 * getter's result is not bound to a local: `a - func_02017E1C(...)` puts the
 * `subs` at the call, where the original has it, while a named `b` sinks it
 * past the copy loop (the mirror of
 * docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * sub_0201AB8C swaps two slots through a heap-allocated temporary of exactly
 * one record, then swaps the two slots' 0x1B-keyed side values through
 * sub_0201ACC4 / sub_0201ACDC (src/matched/unit_0201AC2C.c).  It returns 0
 * unconditionally.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB48.c \
 *       --addr 0x0201AB48 --thumb
 */
void sub_0201AB48(struct Party_0201AB28 *p, u32 idx, const struct PartyMon *src)
{
    u32 a = func_02017E1C(&p->mon[idx], 0xA9, 0);
    u32 d = a - func_02017E1C((void *)src, 0xA9, 0);

    *(struct PartyMon *)((u8 *)p + idx * sizeof(struct PartyMon) + 8) = *src;
    p->count += d;
}

/*
 * pokeparty.c: the store-at-index and swap-two-indices operations on the
 * party container, an array of 0xDC byte records eight bytes into the object
 * with a running count at +0x04.  The file name is the image's own: the debug
 * allocator call in sub_0201AB8C passes 0x020A7304, which spells
 * "pokeparty.c", and its neighbours in the string area are
 * "poke_regulation.c" and "poke_personal.c".
 *
 * Both functions copy a whole record with a plain struct assignment, which
 * this front end inlines as a counted `ldm`/`stm` loop of 27 eight-byte steps
 * plus a trailing word rather than as a call
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).  The record is
 * declared as an array of `u32` and not of `u8` for exactly that reason: a
 * one-aligned declaration gives a byte loop of 0xDC iterations, the same
 * shape with completely different bytes.
 *
 * sub_0201AB48 reads field 0xA9 (the "slot is occupied" derived id, see
 * src/pending/sub_02018E34.c) out of the destination slot before the copy and
 * out of the source after it, and adds the difference to the count, so the
 * count stays right whether the write fills an empty slot or overwrites a
 * full one.
 *
 * Two spellings in sub_0201AB48 are load bearing and neither is obvious.  The
 * destination of the copy is written as byte arithmetic,
 * `(u8 *)p + idx * sizeof(rec) + 8`, while the getter's argument is the
 * ordinary `&p->mon[idx]`: written the same way twice the compiler common
 * subexpression eliminates them and keeps the finished address in a
 * callee-saved register across both calls, which is four bytes short.  What
 * the original keeps alive across the calls is the *product*, and only two
 * differently associated address expressions produce that.  And the second
 * getter's result is not bound to a local: `a - func_02017E1C(...)` puts the
 * `subs` at the call, where the original has it, while a named `b` sinks it
 * past the copy loop (the mirror of
 * docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * sub_0201AB8C swaps two slots through a heap-allocated temporary of exactly
 * one record, then swaps the two slots' 0x1B-keyed side values through
 * sub_0201ACC4 / sub_0201ACDC (src/matched/unit_0201AC2C.c).  It returns 0
 * unconditionally.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB48.c \
 *       --addr 0x0201AB48 --thumb
 */
u32 sub_0201AB8C(struct Party_0201AB28 *p, u32 i, u32 j, u32 heap)
{
    u32 a;
    u32 b;
    struct PartyMon *tmp = (struct PartyMon *)func_02030734(heap, sizeof(struct PartyMon), 0,
                                                           sub_0201AB8C_File, 382);

    *tmp = p->mon[i];
    p->mon[i] = p->mon[j];
    p->mon[j] = *tmp;
    func_020307B0(tmp);
    a = sub_0201ACC4(p, i);
    b = sub_0201ACC4(p, j);
    sub_0201ACDC(p, i, b);
    sub_0201ACDC(p, j, a);
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
void sub_0201AC2C(const struct Rec534 *src, struct Rec534 *dst)
{
    *dst = *src;
}

struct Rec {
    u32 unk00;
    s32 unk04;
    u8  unk08[1];
};




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
u32 sub_0201AC44(struct Rec *p, u32 target)
{
    s32 i;

    for (i = 0; i < p->unk04; i++) {
        void *entry = &p->unk08[i * 0xDC];

        if (func_02017E1C(entry, 5, 0) == target) {
            break;
        }
    }
    if (i == p->unk04) {
        return 0;
    }
    return 1;
}

extern u32   sub_0201AA18(void *p);




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
u32 sub_0201AC80(void *p)
{
    s32 n = sub_0201AA18(p);
    s32 i, count = 0;

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0xA0, 0)) {
            if (!func_02017E1C(entry, 0x4C, 0)) {
                count++;
            }
        }
    }
    return count;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
int sub_0201ACC4(void *p, u32 pos)
{
    u8 b = ((u8 *)p)[0x530];

    if (b & (1u << pos)) {
        return 1;
    }
    return 0;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
void sub_0201ACDC(void *p, u32 pos, u32 mode)
{
    if (mode == 1) {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] | (1u << pos);
    } else {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] & (0xFFu - (1u << pos));
    }
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
void *sub_0201AD0C(void *sys)
{
    return sub_020071CC(sys, 0x1A);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
u32 sub_0201AD18(void *p)
{
    u32 a = func_02017E1C(p, 0x4C, 0);
    u32 b = func_02017E1C(p, 0xA0, 0);

    if (a != 1 && b != 0) {
        return 1;
    }
    return 0;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
u32 sub_0201AD40(void *p)
{
    u32 r = 0;

    if (func_02017E1C(p, 0x4C, 0) != 1) {
        r = 1;
    }
    return r;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
u32 sub_0201AD58(void *p, Predicate pred)
{
    s32 i;
    s32 n = sub_0201AA18(p);

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (pred(entry)) {
            return i;
        }
    }
    return n;
}




/*
 * The lazy constructor for the static handle at 0x0214652C that
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c thread every
 * call through: allocates a 0x10 byte object out of the heap named by the
 * parameter the first time it is asked and does nothing afterwards.
 *
 * The `adds r1, r0, #0` that moves the parameter out of r0 sits in front of
 * the guard's own load rather than inside the `if`, which is what the
 * parameter being live across the test costs; it is not an argument set-up
 * for a call that happens later.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AD88.c \
 *       --addr 0x0201AD88 --thumb
 */
void sub_0201AD88(u32 heap)
{
    if (g_0214652C == 0) {
        g_0214652C = func_020490F4(0x10, heap);
    }
}




/*
 * A three-parameter wrapper: calls sub_0201AFD4(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring sub_0201ADD0/sub_0201ADE4
 * (src/matched/unit_0201ADD0.c) because both of those call sub_0201AFD4 as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */
void sub_0201ADA4(u32 a, int b, void *c)
{
    u32 r = sub_0201AFD4(a, b);

    r = func_02049578(g_0214652C, r);
    func_0204960C(g_0214652C, (void *)r);
    func_020495F4(g_0214652C, 0x3C, c);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201ADD0 is a second, smaller wrapper around sub_0201AFD4 (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * sub_0201ADE4 constructs an object from the debug allocator,
 * func_02030734(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to sub_0201ADA4 (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */
void sub_0201ADD0(u32 a, int b, void *c)
{
    u32 r = sub_0201AFD4(a, b);

    func_02048F4C(c, 0x12, r);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201ADD0 is a second, smaller wrapper around sub_0201AFD4 (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * sub_0201ADE4 constructs an object from the debug allocator,
 * func_02030734(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to sub_0201ADA4 (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */
void *sub_0201ADE4(u32 a, int b, u32 c)
{
    void *obj = func_02030734(c, 0x3C, 0, sub_0201ADE4_File, 0x76);

    sub_0201ADA4(a, b, obj);
    return obj;
}




/*
 * poke_personal.c's record destructor: four bytes of code and one pool word,
 * a tail call with no argument set-up at all
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  It abuts
 * src/matched/unit_0201ADD0.c on the left, whose sub_0201ADE4 carries the
 * "poke_personal.c" file string.
 *
 * This file used to hold the whole middle of poke_personal.c
 * (0x0201AE14..0x0201AFD4: this destructor, the 44 field getter, the
 * placeholder-ability predicate and the form-table loader).  It was cut into
 * three so that the 44 field getter, which the whole poke_* region reads the
 * personal record through, gets a manifest entry of its own instead of being
 * an interior function with no attestable address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The other two
 * pieces are src/matched/sub_0201AE1C.c and src/matched/unit_0201AF6C.c; the
 * C in all three is unchanged, only the file boundaries moved, and no
 * relocation crosses a new boundary.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AE14.c \
 *       --addr 0x0201AE14 --thumb
 */
void sub_0201AE14(void *p)
{
    func_020307B0(p);
}




/*
 * poke_personal.c's 44 field getter over the 0x3C byte personal record, cut
 * out of src/matched/unit_0201AE14.c so that it has a manifest entry of its
 * own.  The bytes and the C are unchanged; only the file boundary moved.
 *
 * Why it is its own file: the manifest records one entry per unit at the
 * unit's start address, so while this function sat in the middle of
 * unit_0201AE14.c the address 0x0201AE1C had no entry, was not an address the
 * `matched` evidence class could attest, and read as still open to every
 * consumer that asked the manifest what the record layer covers
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  It has high
 * fan-in: it is the field selector the whole poke_* region reads the personal
 * record through, so it is exactly the address that wants an entry.
 *
 * Splitting costs nothing here: sub_0201AE14 (the record destructor, four
 * bytes of code and a pool word) keeps the start address and therefore keeps
 * its entry, sub_0201AF6C and sub_0201AF80 move into
 * src/matched/unit_0201AF6C.c which starts at the address of the first of
 * them, and this function holds no relocation at all, so no cut can take a
 * witness away from anybody.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * The 44 case ids are an interface rather than content: they are the field
 * selector the whole region uses, and src/matched/sub_02018A7C.c reads the
 * same record through ids of its own.  The field offsets are structure and
 * will not move; the ids will not either unless a field is added, which is
 * exactly the kind of thing a version diff does, so the map below is the thing
 * to check against IRAO rather than any single number.  No constant in this
 * function is a content id.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP, from the jump table
 * ---------------------------------------------------------------------------
 * The table at 0x0201AE2E is 44 signed halfwords and every one of them names a
 * real body, so the source has case labels 0 through 43 with no gaps
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  The bodies
 * are emitted in the source's order, which here is also the numeric order,
 * even though the offsets they read are not monotonic: id 9 reads +0x22 and id
 * 36 reads +0x09, both out of sequence.
 *
 *    0.. 5  +0x00..+0x05  the six base stats
 *    6, 7   +0x06, +0x07  the two types
 *    8      +0x08
 *    9      +0x22
 *   10..15  +0x0A bits 0..11, six 2 bit fields: the six effort yields
 *   16      +0x0A bit 12, one bit
 *   17..19  +0x0C, +0x0E, +0x10  three held item ids
 *   20..29  +0x12..+0x1B  ten bytes
 *   30, 31  +0x1C, +0x1E  the form table base and its companion; +0x1C is the
 *                         same field src/matched/unit_0201AFD4.c reads
 *   32      +0x20         the form count, also read by unit_0201AFD4.c
 *   33      +0x21 bits 0..5
 *   34, 35  +0x21 bit 6, bit 7
 *   36      +0x09
 *   37, 38  +0x24, +0x26
 *   39..43  +0x28..+0x38  five words
 *
 * Two shapes in there are readings of the declaration rather than of the code.
 * The 2 bit and 1 bit extractions at +0x0A are `lsls`/`lsrs` pairs whose width
 * is neither 8, 16 nor 32, so they are bitfields and nothing else
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * container has to be `u16` for the load to be a `ldrh`, and `u8` at +0x21 for
 * it to be a `ldrb`.  And the two bytes at +0x20 and +0x21 each cost an
 * `adds r0, #0x20` first, which is only the byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); the halfword at +0x22
 * needs none, because `ldrh` reaches 62.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0201AE1C.c \
 *       --addr 0x0201AE1C --thumb
 */
u32 sub_0201AE1C(const struct Personal_0201AE1C *p, u32 field)
{
    switch (field) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:  return p->unk04;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:  return p->unk07;
    case 8:  return p->unk08;
    case 9:  return p->unk22;
    case 10: return p->ev0;
    case 11: return p->ev1;
    case 12: return p->ev2;
    case 13: return p->ev3;
    case 14: return p->ev4;
    case 15: return p->ev5;
    case 16: return p->unk0A_12;
    case 17: return p->unk0C;
    case 18: return p->unk0E;
    case 19: return p->unk10;
    case 20: return p->unk12;
    case 21: return p->unk13;
    case 22: return p->unk14;
    case 23: return p->unk15;
    case 24: return p->unk16;
    case 25: return p->unk17;
    case 26: return p->unk18;
    case 27: return p->unk19;
    case 28: return p->unk1A;
    case 29: return p->unk1B;
    case 30: return p->unk1C;
    case 31: return p->unk1E;
    case 32: return p->unk20;
    case 33: return p->unk21_0;
    case 34: return p->unk21_6;
    case 35: return p->unk21_7;
    case 36: return p->unk09;
    case 37: return p->unk24;
    case 38: return p->unk26;
    case 39: return p->unk28;
    case 40: return p->unk2C;
    case 41: return p->unk30;
    case 42: return p->unk34;
    case 43: return p->unk38;
    }
    return 0;
}


/*
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/sub_0201AE1C.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * sub_0201AF80 was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  sub_0201AF80's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          sub_0201AF80's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF sub_0201AF6C's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * sub_0201AF6C is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201AF80 narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */
u32 sub_0201AF6C(u32 v)
{
    if (v == 0 || v - 0xFE <= 1) {
        return 1;
    }
    return 0;
}




/*
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/sub_0201AE1C.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * sub_0201AF80 was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  sub_0201AF80's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          sub_0201AF80's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF sub_0201AF6C's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * sub_0201AF6C is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201AF80 narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */
u16 *sub_0201AF80(u32 heap, u16 *countOut)
{
    u32 len;
    u16 *tab;
    u16 count;
    u16 n;
    u16 i;

    count = 0;
    tab = func_0204A39C(g_0214652C, 0x29C, 0, heap, &len);
    n = (u16)(len >> 1);
    if (countOut != 0) {
        for (i = 0; i < n; i++) {
            if (tab[i] != 999) {
                count++;
            }
        }
        *countOut = count;
    }
    return tab;
}




/*
 * The species-to-form resolver the three wrappers in
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c open with: it
 * reads the 0x3C byte personal record for the species out of the archive
 * handle at 0x0214652C and, when the record has a form table and the
 * requested form is inside it, answers with the form's own species-like id.
 *
 * VERSION SENSITIVITY: the guard rejects exactly the two ids 650 and 651,
 * which are the egg and bad-egg entries src/pending/sub_02018E34.c's field
 * map already names, and it spells them as a 16 bit range test.  They are
 * content ids rather than structure offsets, so they are the first thing to
 * re-read for a Pokemon White build; nothing else in this function is
 * version dependent.
 *
 * The test is written `(u16)(species + 0xFD76) > 1`, not `species - 650`:
 * 0x28A does not fit an 8 bit immediate either way, and only the positive
 * unsigned 16 bit spelling of the complement keeps the constant in the pool
 * where the original has it
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md).
 *
 * The three tests in the tail are one disjunction guarding `return species`,
 * not the conjunction guarding the computed answer that the semantics
 * suggest: written the other way round every byte is still right but the two
 * exit blocks are emitted in the opposite order, because the block the source
 * writes inside the `if` is the one that comes first
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md and
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The record's halfword at +0x1C is reached with a plain `ldrh [r0, #0x1c]`
 * while its byte at +0x20 costs an `add r0, sp, #0x20` first, which is only
 * the byte immediate's reach of 31 and not a second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AFD4.c \
 *       --addr 0x0201AFD4 --thumb
 */
u32 sub_0201AFD4(u32 species, s32 form)
{
    struct Personal_0201AFD4 rec;

    if ((u16)(species + 0xFD76) <= 1) {
        return 0;
    }
    func_0204960C(g_0214652C, (void *)func_02049578(g_0214652C, species));
    func_020495F4(g_0214652C, 0x3C, &rec);
    if (rec.unk1C == 0 || rec.unk20 <= form || form == 0) {
        return species;
    }
    return (u16)(rec.unk1C + form - 1);
}



/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/sub_0201B038.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 */
void sub_0201B038(void *party)
{
    u32 mask;
    u32 r;
    u32 slot;
    void *mon;
    u32 v;
    u32 w;
    u32 n;

    n = sub_0201AA18(party);
    r = (u16)((u64)func_0203F0A8() * 0x10000 >> 32);
    mask = sub_0201B220(party);
    if (r == 0x4000 || r == 0x8000 || r == 0xC000) {
        do {
            slot = func_0203F0A8();
            if (n != 0) {
                slot = (u32)(((u64)slot * n) >> 32);
            }
            mon = sub_0201AB28(party, slot);
        } while (func_02017E1C(mon, 5, 0) == 0
                 || func_02017E1C(mon, 0x4C, 0) != 0);
        if ((mask & (1 << slot)) != 0) {
            return;
        }
        do {
            v = (u8)((u64)func_0203F0A8() * 0x100 >> 32);
        } while ((v & 7) == 0);
        if ((v & 0xF0) != 0) {
            v = v & 7;
        }
        w = v; w |= (u8)(v << 4);
        func_02017E40(mon, 0x97, (u8)((u8)(w & 0xF3) + 1));
    }
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The two writers of the packed byte field id 0x97 that
 * src/matched/unit_0201B220.c reads: sub_0201B100 counts its low nibble down
 * across the whole party, and sub_0201B170 spreads it to the neighbouring
 * slots one time in three.
 *
 * sub_0201B100 walks every occupied slot, clears the low nibble outright when
 * the amount to subtract is larger than it or larger than 4, subtracts it
 * otherwise, and forces 0x10 when the whole byte comes out zero so that the
 * high nibble stays distinguishable from "never set".  sub_0201B170 copies a
 * slot's byte into the slot before and the slot after it whenever theirs has
 * no high nibble, and advances the index an extra step when it wrote forwards
 * so that a value cannot propagate down the party in one pass.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  What is content shaped:
 *
 *   4      sub_0201B100's threshold: an amount above it always clears the
 *          nibble instead of subtracting, so it is a rule about the field's
 *          range rather than about its layout.
 *   0x10   the value written when the subtraction leaves zero, i.e. the low
 *          nibble empty and the high nibble at one.
 *   3      sub_0201B170's odds, one call in three.
 *   0xF, 0xF0   the two nibble masks, the field's own layout.
 *   0x97, 5   party record ids in src/matched/sub_02018DB4.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B170's odds are a 64 bit multiply and not a modulo:
 * `(u64)rand() * 3 >> 32` puts the answer in the `_ull_mul` call's **r1**, and
 * the `movs r1, #0` in front of the call is the draw's high half rather than a
 * second argument.  See
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.
 *
 * It has no `last` variable.  The original loads the count once, tests it,
 * decrements it and spills the result, which reads like `last = n - 1` written
 * after an `if (n > 0)` guard; it is not.  It is `if (i < n - 1)` inside the
 * loop, with `n - 1` hoisted into the loop preheader by the compiler, which is
 * why the decrement lands after the loop's own entry guard rather than before
 * it.  Writing the guard and the local out by hand costs six bytes.
 *
 * sub_0201B100's two arms are not spelled the same way.  The masking arm is a
 * compound assignment, `v &= 0xF0`, and the subtracting arm carries an explicit
 * `(u8)` cast; written with the cast on both, the two truncations cross-jump
 * into one block that both arms branch to and the function is four bytes
 * short.  That is
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md
 * seen on a local rather than on a field: the compound form is the one that
 * does not materialise a fresh truncation.
 *
 * Both loop counters are signed, and in sub_0201B100 the amount and the
 * extracted nibble are signed too: the comparisons are `blt` and `ble`, not
 * `blo` and `bls`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */
void sub_0201B100(void *party, s32_0201B100 amount)
{
    s32_0201B100 n;
    void *mon;
    s32_0201B100 i;
    u8 v;
    s32_0201B100 low;

    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        low = v & 0xF;
        if (low == 0) {
            continue;
        }
        if (low < amount || amount > 4) {
            v &= 0xF0;
        } else {
            v = (u8)(v - (u8)amount);
        }
        if (v == 0) {
            v = 0x10;
        }
        func_02017E40(mon, 0x97, v);
    }
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The two writers of the packed byte field id 0x97 that
 * src/matched/unit_0201B220.c reads: sub_0201B100 counts its low nibble down
 * across the whole party, and sub_0201B170 spreads it to the neighbouring
 * slots one time in three.
 *
 * sub_0201B100 walks every occupied slot, clears the low nibble outright when
 * the amount to subtract is larger than it or larger than 4, subtracts it
 * otherwise, and forces 0x10 when the whole byte comes out zero so that the
 * high nibble stays distinguishable from "never set".  sub_0201B170 copies a
 * slot's byte into the slot before and the slot after it whenever theirs has
 * no high nibble, and advances the index an extra step when it wrote forwards
 * so that a value cannot propagate down the party in one pass.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  What is content shaped:
 *
 *   4      sub_0201B100's threshold: an amount above it always clears the
 *          nibble instead of subtracting, so it is a rule about the field's
 *          range rather than about its layout.
 *   0x10   the value written when the subtraction leaves zero, i.e. the low
 *          nibble empty and the high nibble at one.
 *   3      sub_0201B170's odds, one call in three.
 *   0xF, 0xF0   the two nibble masks, the field's own layout.
 *   0x97, 5   party record ids in src/matched/sub_02018DB4.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B170's odds are a 64 bit multiply and not a modulo:
 * `(u64)rand() * 3 >> 32` puts the answer in the `_ull_mul` call's **r1**, and
 * the `movs r1, #0` in front of the call is the draw's high half rather than a
 * second argument.  See
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.
 *
 * It has no `last` variable.  The original loads the count once, tests it,
 * decrements it and spills the result, which reads like `last = n - 1` written
 * after an `if (n > 0)` guard; it is not.  It is `if (i < n - 1)` inside the
 * loop, with `n - 1` hoisted into the loop preheader by the compiler, which is
 * why the decrement lands after the loop's own entry guard rather than before
 * it.  Writing the guard and the local out by hand costs six bytes.
 *
 * sub_0201B100's two arms are not spelled the same way.  The masking arm is a
 * compound assignment, `v &= 0xF0`, and the subtracting arm carries an explicit
 * `(u8)` cast; written with the cast on both, the two truncations cross-jump
 * into one block that both arms branch to and the function is four bytes
 * short.  That is
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md
 * seen on a local rather than on a field: the compound form is the one that
 * does not materialise a fresh truncation.
 *
 * Both loop counters are signed, and in sub_0201B100 the amount and the
 * extracted nibble are signed too: the comparisons are `blt` and `ble`, not
 * `blo` and `bls`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */
void sub_0201B170(void *party)
{
    s32_0201B100 i;
    void *mon;
    void *other;
    u8 v;
    s32_0201B100 n;

    n = sub_0201AA18(party);
    if ((u32)((u64)func_0203F0A8() * 3 >> 32) != 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        if ((v & 0xF) == 0) {
            continue;
        }
        if (i != 0) {
            other = sub_0201AB28(party, i - 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
            }
        }
        if (i < n - 1) {
            other = sub_0201AB28(party, i + 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
                i++;
            }
        }
    }
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B220(void *party)
{
    s32_0201B220 i;
    u32 mask;
    s32_0201B220 n;

    mask = 0;
    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(sub_0201AB28(party, i), 0x97, 0) != 0) {
            mask |= (u8)(1 << i);
        }
    }
    return mask;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B25C(void *a)
{
    return sub_0201B268(func_020185F0(a));
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B268(void *mon)
{
    u32 r;

    r = 0;
    if ((func_02017E88(mon, 0x97, 0) & 0xF) != 0) {
        r = 1;
    }
    return r;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B280(void *a)
{
    return sub_0201B28C(func_020185F0(a));
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B28C(void *mon)
{
    u32 r;
    u8 v;

    r = 0;
    v = (u8)func_02017E88(mon, 0x97, 0);
    if ((v & 0xF) == 0 && (v & 0xF0) != 0) {
        r = 1;
    }
    return r;
}



/*
 * note:     wave 18 (2026-09-24): EXACT* (the listing extent includes the
 *           12-byte unlabelled follower at 0x0201B70C, src/matched/
 *           unit_0201B70C.c).  Closed by the heap id's width: the seventh
 *           parameter is a u16 and func_02020FE4 takes its third argument
 *           as a u16.  With both u32 the gate's `ldr r2, [sp, #0x68]` is
 *           hoisted above the pidHigh store (12 bytes out); u16 on the
 *           parameter alone breaks the size, u16 on both keeps the load
 *           behind the store as in the image.  func_02020FE4 masks the id to
 *           fifteen bits and ORs in 0x8000 (a temporary-heap id), and
 *           src/matched/unit_02007CB0.c already declares that parameter u16.
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, sub_0201B764) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/sub_0201B2B0.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B2B0.c \
 *       --func sub_0201B2B0 --addr 0x0201B2B0 --cc 1.1p1 --thumb
 */
u32 sub_0201B2B0(void *party, void *mon, u32 context, u32 param,
                 u8 timezone, u32 *methodOut, u16 heap)
{
    u32 dummy;
    u32 a3c;
    u32 a38;
    u32 a34;
    u32 pid;
    struct EvoRow_0201B2B0 *table;
    u16 species;
    u16 held;
    u16 friendship;
    u16 pidHigh;
    u8  level;
    u8  beauty;
    int i;
    u16 result;
    u8  holdEffect;
    struct EvoRow_0201B2B0 *row;
    u32 j;

    result = 0;
    if (func_02017E1C(mon, 0x4C, 0) != 0) {
        return result;
    }
    species = func_02017E1C(mon, 5, 0);
    held = func_02017E1C(mon, 6, 0);
    pid = func_02017E1C(mon, 0, 0);
    beauty = func_02017E1C(mon, 0x14, 0);
    pidHigh = (pid & 0xFFFF0000) >> 16;
    holdEffect = func_02020FE4(held, 1, heap);
    if (species != 0x40 && holdEffect == 0x40 && context != 3) {
        return result;
    }
    if (methodOut == 0) {
        methodOut = &dummy;
    }
    i = 0;
    table = func_02030734(heap, 0x2A, 0, (const char *)s_shinka_check_c, 0x6A);
    sub_0201B764(species, table);

    switch (context) {
    case 0:
        level = func_02017E1C(mon, 0x9E, i);
        friendship = func_02017E1C(mon, 9, i);
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 1:
                if (friendship >= 220) {
                    result = row->target;
                }
                break;
            case 2:
                if (func_02011410(timezone) == 0 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 3:
                if (func_02011410(timezone) == 1 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 4:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 9:
                if (row->param <= level) {
                    a34 = func_02017E1C(mon, 0xA2, 0);
                    if (a34 > func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 10:
                if (row->param <= level) {
                    a38 = func_02017E1C(mon, 0xA2, 0);
                    if (a38 == func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 11:
                if (row->param <= level) {
                    a3c = func_02017E1C(mon, 0xA2, 0);
                    if (a3c < func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 12:
                if (row->param <= level && pidHigh % 10 < 5) {
                    result = row->target;
                }
                break;
            case 13:
                if (row->param <= level && pidHigh % 10 >= 5) {
                    result = row->target;
                }
                break;
            case 14:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 15:
                *methodOut = 15;
                break;
            case 16:
                if (row->param <= beauty) {
                    result = row->target;
                }
                break;
            case 19:
                if (func_02011410(timezone) == 0 && held == row->param) {
                    result = row->target;
                }
                break;
            case 20:
                if (func_02011410(timezone) == 1 && held == row->param) {
                    result = row->target;
                }
                break;
            case 21:
                if (sub_0201B774(mon, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 22:
                if (party != 0 && sub_0201AC44(party, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 23:
                if (func_02017E1C(mon, 0x6E, 0) == 0 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 24:
                if (func_02017E1C(mon, 0x6E, 0) == 1 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 25:
                for (j = 0; j < 3; j++) {
                    if (param == g_020A7324[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 26:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7322[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 27:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7320[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 28:
                for (j = 0; j < 3; j++) {
                    if (param == g_020A732A[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 5:
                result = row->target;
                break;
            case 6:
                if (held == row->param) {
                    result = row->target;
                }
                break;
            case 7:
                if (func_02020FE4((u16)func_02017E1C((void *)param, 6, 0), 1, heap) != 0x40) {
                    if ((func_02017E1C(mon, 0xAB, 0) == 588
                         && func_02017E1C((void *)param, 0xAB, 0) == 616)
                     || (func_02017E1C((void *)param, 0xAB, 0) == 588
                         && func_02017E1C(mon, 0xAB, 0) == 616)) {
                        result = row->target;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            if (row->method == 8 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x11 && func_02017E1C(mon, 0x6E, 0) == 0 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x12 && func_02017E1C(mon, 0x6E, 0) == 1 && param == row->param) {
                result = row->target;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    }
    func_020307B0(table);
    return result;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
void *sub_0201B70C(u32 heap)
{
    return func_020490F4(0x13, heap);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
u32 sub_0201B718(void *a, u32 id, u32 row, u32 field)
{
    struct EvoTable t;

    func_0204932C(a, id, &t);
    switch (field) {
    case 0:
        return t.rows[row].method;
    case 1:
        return t.rows[row].param;
    case 2:
        return t.rows[row].species;
    }
    return 0;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
void sub_0201B764(u32 id, void *dest)
{
    func_02048F4C(dest, 0x13, id);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
u32 sub_0201B774(void *mon, u32 move)
{
    u32 found;
    s32_0201B70C i;

    found = 0;
    for (i = 0x36; i < 0x3A; i++) {
        if (move == func_02017E1C(mon, i, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}



/*
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * A three-byte-stride table entry is handed to func_0201B850 along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201B7A0.c \
 *       --func func_0201B7A0 --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */
void func_0201B7A0(void *a0, int a1, int a2, int a3)
{
    func_0201B850(a0, &g_0209E45C[a1 * 3], a2, a3);
}

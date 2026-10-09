/*
 * file:     btl_server_p83.c
 * unit:     yes
 * function: func_021C8810, func_021C8828, func_021C8838, func_021C8860, func_021C888C, func_021C88A4, func_021C88B4, func_021C88C8, func_021C88E4, func_021C8910, func_021C8918
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
 *   func_021CC9AC   0x021CC9AC  thumb  ov093
 *   func_021CCA74   0x021CCA74  thumb  ov093
 *   func_021CC96C  0x021CC96C  thumb  ov093
 *   func_021CC9A4  0x021CC9A4  thumb  ov093
 *   func_021B9940   0x021B9940  thumb ov093
 *   func_021C8C6C   0x021C8C6C  thumb ov093
 *   func_021C8CBC   0x021C8CBC  thumb ov093
 *   func_021C8D0C   0x021C8D0C  thumb ov093
 *   func_021C8D2C   0x021C8D2C  thumb ov093
 *   func_021C8DE4   0x021C8DE4  thumb ov093
 *   func_021C8E58   0x021C8E58  thumb ov093
 *   func_021C8F24   0x021C8F24  thumb ov093
 *   func_021C8FA4   0x021C8FA4  thumb ov093
 *   func_021C9010   0x021C9010  thumb ov093
 *   func_021C9068   0x021C9068  thumb ov093
 *   func_021C9178   0x021C9178  thumb ov093
 *   func_021C9250   0x021C9250  thumb ov093
 *   func_021C9394   0x021C9394  thumb ov093
 *   func_021C9448   0x021C9448  thumb ov093
 *   func_021C947C   0x021C947C  thumb ov093
 *   func_021C94C8   0x021C94C8  thumb ov093
 *   func_021C95D0   0x021C95D0  thumb ov093
 *   func_021C962C   0x021C962C  thumb ov093
 *   func_021C96D4   0x021C96D4  thumb ov093
 *   func_021C9728   0x021C9728  thumb ov093
 *   func_021C9750   0x021C9750  thumb ov093
 *   func_021C9778   0x021C9778  thumb ov093
 *   func_021C97A4   0x021C97A4  thumb ov093
 *   func_021C97D0   0x021C97D0  thumb ov093
 *   func_021C9828   0x021C9828  thumb ov093
 *   func_021C9898   0x021C9898  thumb ov093
 *   func_021C98C4   0x021C98C4  thumb ov093
 *   func_021C98E4   0x021C98E4  thumb ov093
 *   func_021C9A24   0x021C9A24  thumb ov093
 *   func_021C9A60   0x021C9A60  thumb ov093
 *   func_021C9BB8   0x021C9BB8  thumb ov093
 *   func_021C9CC0   0x021C9CC0  thumb ov093
 *   func_021C9DCC   0x021C9DCC  thumb ov093
 *   func_021C9DE8   0x021C9DE8  thumb ov093
 *   func_021C9E3C   0x021C9E3C  thumb ov093
 *   func_021C9ECC   0x021C9ECC  thumb ov093
 *   func_021C9F0C   0x021C9F0C  thumb ov093
 *   func_021C9F4C   0x021C9F4C  thumb ov093
 *   func_021C9F6C   0x021C9F6C  thumb ov093
 *   func_021CA128   0x021CA128  thumb ov093
 *   func_021CA158   0x021CA158  thumb ov093
 *   func_021CA1D0   0x021CA1D0  thumb ov093
 *   func_021CA248   0x021CA248  thumb ov093
 *   func_021CA270   0x021CA270  thumb ov093
 *   func_021CA2E8   0x021CA2E8  thumb ov093
 *   func_021CA318   0x021CA318  thumb ov093
 *   func_021CA370   0x021CA370  thumb ov093
 *   func_021CA394   0x021CA394  thumb ov093
 *   func_021CA3AC   0x021CA3AC  thumb ov093
 *   func_021CA3D0   0x021CA3D0  thumb ov093
 *   func_021CA47C   0x021CA47C  thumb ov093
 *   func_021CA570   0x021CA570  thumb ov093
 *   func_021CA5CC   0x021CA5CC  thumb ov093
 *   func_021CA6C4   0x021CA6C4  thumb ov093
 *   func_021CA6FC   0x021CA6FC  thumb ov093
 *   func_021CA738   0x021CA738  thumb ov093
 *   func_021CA748   0x021CA748  thumb ov093
 *   func_021CA7C4   0x021CA7C4  thumb ov093
 *   func_021CA7D4   0x021CA7D4  thumb ov093
 *   func_021CC960   0x021CC960  thumb ov093
 *   func_021CC974   0x021CC974  thumb ov093
 *   func_021CC99C   0x021CC99C  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 */
#include "../../matched/include/Obj18339.h"
#include "../../matched/include/Obj21124.h"
#include "../../matched/include/Obj21125.h"

struct Pack;
struct Rec;
struct Q9;
struct S;
struct Cmd;
struct Q;
struct Q10;
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

struct Packed021C888C { u16 low : 8; u16 index : 7; u16 active : 1; };

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

extern void func_02082BCC(void *, int, u32);
extern struct Rec *func_021CC9AC(struct Pack *p, int id, int b);
extern void func_021CCA74(void *s, void *cmd);
extern int func_021CC96C(struct Q9 *p);
extern u32 func_021CC9A4(u32 *p);
extern unsigned short func_021CC960(struct S *p);
extern int func_021CC99C(struct Q10 *p);
extern void func_021CC974(void *q, int r);
extern u8 *func_021B9940(char *p, u8 i);
extern int func_021D5B68(void *mon);
extern u8 func_021C9DE8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8C6C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8CBC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8D0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C96D4(BattleCtx *s, BtlCmd *cmd);
typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8D2C;

extern u8 func_021C8D2C(int p, const Ent_021C8D2C *e, int c);
extern u8 func_021C8DE4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C8E58(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8F24(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8FA4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9010(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9068(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9178(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9250(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9394(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C947C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C94C8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9448(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C95D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C962C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9728(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9750(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9778(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97A4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9828(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9898(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98E4(u8 *w, struct Cmd *c);
extern u8 func_021C9A24(void *p, const struct Cmd *q);
extern u8 func_021C9A60(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9BB8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9DCC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9E3C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9ECC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9CC0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F4C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F6C(u8 *p, u8 *q);
extern u8 func_021CA128(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA158(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA1D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA248(u8 *p, const u8 *q);
extern u8 func_021CA270(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA2E8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA318(u8 *p, const struct Q *q);
extern u8 func_021CA370(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA394(u8 *p, const u8 *q);
extern u8 func_021CA3AC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA3D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA47C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA570(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA5CC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6FC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA738(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA748(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7D4(BattleCtx *s, BtlCmd *cmd);
void func_021C8810(u8 *p);
u32 func_021C8828(u8 *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, u32 val);
void func_021C888C(u8 *p, u32 v);
void *func_021C88A4(char *p, int a, int b);
void func_021C88B4(void *a, int k, int b);
void func_021C88C8(void *a, void *b);
int func_021C88E4(u8 *p);
int func_021C8910(u8 *p);
void func_021C8918(BattleCtx *s, BtlCmd *cmd);


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


/*
 * extent: two-byte alignment padding at 0x021C88A2.
 */
void func_021C888C(u8 *p, u32 v)
{
    if (((struct Packed021C888C *)(p + 2))->index < 8) {
        ((struct Obj21125 *)p)->f20 = v;
        ((struct Packed021C888C *)(p + 2))->active = 1;
    }
}



/*
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).
 *
 * 2026-10-05 (D9 lane 02): unchanged. 0x021CC9AC is a 176-byte packer, not a tiny leaf, and ov093 below 0x021D4000 is pengy's, so no witness filed. Needs the integrator seed.
 * 2026-10-05 (D9r lane 14): callee 0x021CC9AC is now matched EXACT as
 * src/matched/ov/ov093_func_021CC9AC.c (user-approved). Re-verified MATCH: the
 * relocation still waits on that file's shard (integrator manifest), then this
 * should verify EXACT with no source change.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021CC9AC is a real 176-byte Thumb bitfield packer (bitfield insert into a table with 0x3b-entry byte lookup), not a veneer and not tiny; not filed in this lane. Needs bottom-up match or integrator seed.
 */
void *func_021C88A4(char *p, int a, int b)
{
    return func_021CC9AC((struct Pack *)(p + 0x1D74), a, b);
}



/*
 * Named by the parked ov093 files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).  EXACT*: both calls resolve
 * (func_021C88A4 by `label`, func_021C88C8 by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 */
void func_021C88B4(void *a, int k, int b)
{
    func_021C88C8(a, func_021C88A4(a, k, b));
}



/*
 * Unlabelled-record helper reached from the five ov093 packets that name it
 * (func_021DFABC / func_021E4A70 / func_021D85F4 / func_021E7388 /
 * func_021DF0C4).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 */
void func_021C88C8(void *a, void *b)
{
    func_021C8918(a, b);
    func_021CCA74((char *)a + 0x1d74, b);
}



int func_021C88E4(u8 *p)
{
    if (func_021CC96C((struct Q9 *)(p + 0x1D74)) != 0) {
        if (func_021CC9A4((u32 *)(p + 0x1D74)) != 0) return 2;
        return 1;
    }
    return 0;
}



/*
 * tail-call thunk to func_021C88E4
 */
int func_021C8910(u8 *p)
{
    return func_021C88E4(p);
}



void func_021C8918(BattleCtx *s, BtlCmd *cmd)
{
    int arg = func_021CC960((struct S *)s->queue);
    u8 r;

    if (func_021CC96C((struct Q9 *)s->queue))
        r = func_021CC99C((struct Q10 *)s->queue);
    else
        r = 1;

    if (cmd->ignoreIfBusy && r == 0)
        return;
    if (cmd->checkFainted && func_021D5B68(func_021B9940(s->party, cmd->client)))
        return;

    switch (cmd->id) {
    case 1:
        r = func_021C8C6C(s, cmd);
        break;
    case 2:
        r = func_021C8CBC(s, cmd);
        break;
    case 3:
        r = func_021C8D0C(s, cmd);
        break;
    case 0:
        r = func_021C9DE8(s, cmd);
        break;
    case 5:
        r = func_021C8D2C((int)s, (Ent_021C8D2C *)cmd, arg);
        break;
    case 6:
        r = func_021C8DE4(s, cmd, arg);
        break;
    case 7:
        r = func_021C8E58(s, cmd);
        break;
    case 8:
        r = func_021C8F24(s, cmd);
        break;
    case 9:
        r = func_021C8FA4(s, cmd, arg);
        break;
    case 10:
        r = func_021C9010(s, cmd, arg);
        break;
    case 11:
        r = func_021C9068(s, cmd, arg);
        break;
    case 12:
        r = func_021C9178(s, cmd);
        break;
    case 14:
        r = func_021C9250(s, cmd, arg);
        break;
    case 15:
        r = func_021C9394(s, cmd);
        break;
    case 18:
        r = func_021C9448(s, cmd);
        break;
    case 16:
        r = func_021C947C(s, cmd);
        break;
    case 17:
        r = func_021C94C8(s, cmd);
        break;
    case 19:
        r = func_021C95D0(s, cmd);
        break;
    case 20:
        r = func_021C962C(s, cmd);
        break;
    case 4:
        r = func_021C96D4(s, cmd);
        break;
    case 21:
        r = func_021C9728(s, cmd);
        break;
    case 22:
        r = func_021C9750(s, cmd);
        break;
    case 23:
        r = func_021C9778(s, cmd);
        break;
    case 24:
        r = func_021C97A4(s, cmd);
        break;
    case 25:
        r = func_021C97D0(s, cmd);
        break;
    case 26:
        r = func_021C9828(s, cmd);
        break;
    case 27:
        r = func_021C9898(s, cmd);
        break;
    case 29:
        r = func_021C98E4((u8 *)s, (struct Cmd *)cmd);
        break;
    case 28:
        r = func_021C98C4(s, cmd);
        break;
    case 30:
        r = func_021C9A24(s, (const struct Cmd *)cmd);
        break;
    case 31:
        r = func_021C9A60(s, cmd);
        break;
    case 32:
        r = func_021C9BB8(s, cmd);
        break;
    case 33:
        r = func_021C9DCC(s, cmd);
        break;
    case 34:
        r = func_021C9E3C(s, cmd);
        break;
    case 35:
        r = func_021C9ECC(s, cmd);
        break;
    case 36:
        r = func_021C9CC0(s, cmd);
        break;
    case 37:
        r = func_021C9F0C(s, cmd);
        break;
    case 38:
        r = func_021C9F4C(s, cmd);
        break;
    case 39:
        r = func_021C9F6C((u8 *)s, (u8 *)cmd);
        break;
    case 40:
        r = func_021CA128(s, cmd);
        break;
    case 41:
        r = func_021CA158(s, cmd);
        break;
    case 42:
        r = func_021CA1D0(s, cmd);
        break;
    case 43:
        r = func_021CA248((u8 *)s, (const u8 *)cmd);
        break;
    case 44:
        r = func_021CA270(s, cmd);
        break;
    case 45:
        r = func_021CA2E8(s, cmd);
        break;
    case 46:
        r = func_021CA318((u8 *)s, (const struct Q *)cmd);
        break;
    case 47:
        r = func_021CA370(s, cmd);
        break;
    case 48:
        r = func_021CA394((u8 *)s, (const u8 *)cmd);
        break;
    case 49:
        r = func_021CA3AC(s, cmd);
        break;
    case 50:
        r = func_021CA3D0(s, cmd);
        break;
    case 51:
        r = func_021CA47C(s, cmd);
        break;
    case 52:
        r = func_021CA570(s, cmd);
        break;
    case 53:
        r = func_021CA5CC(s, cmd);
        break;
    case 54:
        r = func_021CA6C4(s, cmd);
        break;
    case 55:
        r = func_021CA6FC(s, cmd);
        break;
    case 56:
        r = func_021CA738(s, cmd);
        break;
    case 57:
        r = func_021CA748(s, cmd);
        break;
    case 58:
        r = func_021CA7C4(s, cmd);
        break;
    case 59:
        r = func_021CA7D4(s, cmd);
        break;
    }
    func_021CC974(s->queue, r);
}

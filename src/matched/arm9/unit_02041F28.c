/*
 * unit:     yes
 * function: BG_SYS_SetScrollX, BG_SYS_SetScrollY, BG_SYS_SetAffine
 * address:  0x02041F28
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44      0x02146A44  data
 *   func_02043228   0x02043228  arm
 *   func_02043264   0x02043264  arm
 *   func_020432E4   0x020432E4  arm
 *
 * Three consecutive "bring one video slot up" entry points, 68 bytes each
 * and no padding between them, differing only in the helper they call:
 * each hands the slot record (base +8, stride 0x2c) to its helper and then
 * sets that slot's own bit in the halfword at +4 of the same context.
 *
 * Each helper is the three-argument set/add/sub family matched as
 * src/matched/BG_SYS_SetAffineField.c and its siblings, so `op` and `value` pass
 * straight through in r1/r2 and the call site prepares only r0.  That is
 * what pins the register the context value lands in: written as a
 * one-argument call every instruction of the body is still right but the
 * context load comes out in r1, four bytes per function; with the two
 * pass-through parameters declared, r1/r2 are live across the address
 * computation and the scratch goes to r3.  See
 * docs/idioms/arguments-left-in-place-keep-the-low-registers-out-of-the-scratch-pool.md.
 *
 * The bit set is the u16 truncation idiom, not a mask: `1 << which` is
 * materialised and then narrowed with the lsl #0x10 / lsr #16 pair the
 * `orr` takes as a shifted operand, which only a `u16` lvalue produces.
 * The context pointer is re-read from its own slot after the call, because
 * the callee may store it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02041F28.c \
 *       --addr 0x02041F28 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8 pad_00[0x2c];
};

struct Ctx {
    u8    pad_00[4];
    u16   unk_04;
    u8    pad_06[2];
    struct Slot slots[8];
};

extern struct Ctx *g_02146A44;

struct Obj;
extern void func_02043228(struct Obj *p, u32 op, u16 value);
struct Obj;
extern void func_02043264(struct Obj *p, u32 op, u32 value);
extern void func_020432E4(struct Obj *p, u32 op, u32 value);

void BG_SYS_SetScrollX(u32 which, u32 op, u16 value)
{
    func_02043228((struct Obj *)(&g_02146A44->slots[which]), op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

void BG_SYS_SetScrollY(u32 which, u32 op, u32 value)
{
    func_02043264((struct Obj *)(&g_02146A44->slots[which]), op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

void BG_SYS_SetAffine(u32 which, u32 op, u16 value)
{
    func_020432E4((struct Obj *)(&g_02146A44->slots[which]), op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

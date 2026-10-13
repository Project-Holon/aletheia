/*
 * file:     unit_02069D14.c
 * unit:     yes
 * function: func_02069D14, func_02069D68, func_02069E20, func_02069E88, func_02069F08, func_02069F7C, func_02069FD0, func_02069FE4, func_02069FF8, func_0206A00C
 * address:  0x02069D14
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A8234     0x020A8234  data
 *   g_020A8238     0x020A8238  data
 *   g_020A823C     0x020A823C  data
 *   func_02082A7C  0x02082A7C  arm
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 */
#include "../../matched/include/Obj16534.h"
#include "../../matched/include/Obj16535.h"
#include "../../matched/include/Obj01198.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8  pad00[4];
    u32 f04;
    u8  pad08[4];
    u32 f0c;
    u8  pad10[4];
    u32 f14;
    u8  pad18[4];
    u32 f1c;
} S;

typedef struct Node_02069D14_02069D14 {
    u8 unk00[0x10];
    struct Node_02069D14_02069D14 *next;
    u8 unk14[4];
    u8 pri18;
} Node_02069D14_02069D14;

typedef signed int s32;

typedef unsigned short u16;

typedef struct Node_02069E20 {
    u8 unk00[0x10];
    struct Node_02069E20 *next;
    u8 unk14[5];
    u8 cnt19;
    u16 tab1A[1];
} Node_02069E20;

typedef struct Node_02069E88 { u8 unk00[8]; u8 *tag08; u8 unk0C[4]; struct Node_02069E88 *next; } Node_02069E88;

typedef struct {
    u32 flags00;
    u32 pad04;
    Node_02069E88 *l08;
    u32 pad0C;
    Node_02069E88 *l10;
    u32 pad14;
    Node_02069E88 *l18;
    u8  pad1C[0x20];
    u32 m3C;
    u32 pad40;
    u32 m44;
    u32 pad48;
    u32 m4C;
} Owner_02069E88;

typedef struct Node_02069D14_02069E88 {
    u8 unk00[0x10];
    struct Node_02069D14_02069E88 *next;
} Node_02069D14_02069E88;

typedef struct {
    u32 flags00;
    u32 pad04;
    Node_02069D14_02069E88 *l08;
    u32 pad0C;
    Node_02069D14_02069E88 *l10;
    u32 pad14;
    Node_02069D14_02069E88 *l18;
} Owner_02069D14;

struct Up {
    u32 pad00[2];
    u32 f08;
    u16 f0c;
    u16 pad0e;
    u16 f10;
    u16 pad12;
    u32 f14;
    u32 f18;
    u16 f1c;
    u16 pad1e;
    u16 f20;
    u16 pad22;
    u32 f24;
    u32 f28;
};

extern void func_02082A7C(u32 val, void *dst, u32 len);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);
void func_02069D14(S *p, u32 b);
void func_02069D68(Node_02069D14_02069D14 **head, Node_02069D14_02069D14 *item);
void func_02069E20(u32 *mask, Node_02069E20 *n);
void func_02069E88(Owner_02069E88 *o, Node_02069E88 *item);
u32 func_02069F08(Node_02069D14_02069E88 **head, Node_02069D14_02069E88 *target);
void func_02069F7C(Owner_02069D14 *o, Node_02069D14_02069E88 *item);
int func_02069FD0(int p);
int func_02069FE4(int p);
void func_02069FF8(char *p, int a, int b);
void func_0206A00C(struct Up *u, u32 wrap);
extern u32 g_020A8234;
extern u32 g_020A8238;
extern u32 g_020A823C;




/*
 * cap:      literal - 0x020A823C (data) has no witness outside 0x02069D14..0x02069D68;
 *           the second pool word of the same word-run (0x020A8238 / 0x020A8234)
 *           resolves as data_table, this one occurs only inside the compared range.
 *           All 17 instructions and the two other pool words are byte-identical.
 */
void func_02069D14(S *p, u32 b)
{
    func_02082A7C(0, p, 0x54);
    p->f0c = g_020A823C;
    p->f14 = g_020A8238;
    p->f1c = g_020A8234;
    p->f04 = b;
}




/*
 * Priority-ordered insert into the singly-linked list rooted at *head. The
 * list links through +0x10 and orders on the unsigned byte at +0x18, highest
 * first; `item` may itself already be a chain, so before splicing it in the
 * code walks to its own tail and attaches the displaced remainder there.
 *
 * Three shape notes:
 *  - The one-element case (*head has no next) is written out separately from
 *    the general search; that is what produces the `bne`/`beq` pair on one
 *    `cmp r2,#0` at +0x18 and +0x60, where the second branch re-uses the
 *    flags the first one set.
 *  - The search loop is TOP-TESTED (`while (nx != 0)` with the priority test
 *    inside). Rotating it into `while (nx->pri18 >= ...)` with a NULL check at
 *    the bottom compiles to 188 bytes, four too many.
 *  - The insert guard is `nx->pri18 >= item->pri18`; the reverse polarity is
 *    a single wrong byte at +0x70 (`bhs` for `blo`), the only difference
 *    between the two spellings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02069D68.c \
 *       --func func_02069D68 --addr 0x02069D68 --cc 1.1p1 --arm
 */
void func_02069D68(Node_02069D14_02069D14 **head, Node_02069D14_02069D14 *item)
{
    Node_02069D14_02069D14 *cur;
    Node_02069D14_02069D14 *nx;
    Node_02069D14_02069D14 *tail;

    cur = *head;
    if (cur == 0) { *head = item; return; }
    nx = cur->next;
    if (nx == 0) {
        if (cur->pri18 > item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            tail->next = cur;
            *head = item;
            return;
        }
        cur->next = item;
        return;
    }
    while (nx != 0) {
        if (nx->pri18 >= item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            cur->next = item;
            tail->next = nx;
            return;
        }
        cur = nx;
        nx = nx->next;
    }
    cur->next = item;
}



/*
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The original keeps `tst r2,#0x100` / `beq` over a five-instruction guard
 * body at 0x02069E60..0x02069E74; dsi/1.1p1 -O4,p always predicates a guard
 * block of five instructions or fewer (docs/idioms/an-arm-guard-block-of-
 * five-instructions-or-fewer-is-predicated.md) and emits asrne/andne/ldrne/
 * orrne/strne for 100 bytes against the original's 104. No C spelling under
 * the pinned front end can restore the branch; ../2.0/sp2 keeps it, giving
 * 104 bytes and 0 mismatches. Evidence and the ruled-out spellings are in
 * docs/notes/func_02069E20.c.txt.
 *
 * Walk the linked list from `n`, and for each entry set bit i of `mask`
 * for every tab1A[i] (i < cnt19) whose 0x100 flag is set.
 */
void func_02069E20(u32 *mask, Node_02069E20 *n)
{
    s32 i;

    if (n == 0) return;
    do {
        for (i = 0; i < (s32)n->cnt19; i++) {
            if (n->tab1A[i] & 0x100) {
                mask[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        n = n->next;
    } while (n != 0);
}



/*
 * 2026-09-21: unblocked. 128 bytes, zero mismatches, and now 6 of 6
 * relocation sites resolved: the three calls to 0x02069E20 take the
 * `matched` class from src/matched/func_02069E20.c, filed EXACT under the
 * per-file pin `compiler: ../2.0/sp2` (the "kept branches" tell, see
 * docs/FRONTEND-PINS.md and docs/notes/func_02069E20.c.txt). This file
 * itself stays on the pinned default 1.1p1; only its callee is pinned.
 *
 * Dispatches on the tag byte at *(item->tag08): 0x4D, 0x4A and 0x56 each
 * pair one mask-collect call with one priority insert, into the owner's
 * (+0x3C,+0x08), (+0x44,+0x10) and (+0x4C,+0x18) slots respectively. The
 * case ORDER in the source is 0x4D, 0x4A, 0x56 (the emitted compare chain
 * tests 0x4A first because the compiler reorders the tests, not the arms).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02069E88.c \
 *       --func func_02069E88 --addr 0x02069E88 --cc 1.1p1 --arm
 */
void func_02069E88(Owner_02069E88 *o, Node_02069E88 *item)
{
    u8 *tag;

    if (item == 0) return;
    tag = item->tag08;
    if (tag == 0) return;
    switch (*tag) {
    case 0x4d:
        func_02069E20(&o->m3C, (Node_02069E20 *)item);
        func_02069D68((Node_02069D14_02069D14 * *)(&o->l08), (Node_02069D14_02069D14 *)item);
        break;
    case 0x4a:
        func_02069E20(&o->m44, (Node_02069E20 *)item);
        func_02069D68((Node_02069D14_02069D14 * *)(&o->l10), (Node_02069D14_02069D14 *)item);
        break;
    case 0x56:
        func_02069E20(&o->m4C, (Node_02069E20 *)item);
        func_02069D68((Node_02069D14_02069D14 * *)(&o->l18), (Node_02069D14_02069D14 *)item);
        break;
    }
}




/*
 * The list-removal pair, folded into one translation unit so that
 * func_02069F7C's three calls to func_02069F08 are `local` relocations
 * attested by the unit's own layout rather than by a separate manifest
 * entry.
 *
 * func_02069F08  unlinks `target` from the list rooted at *head (next at
 *                +0x10), returning 1 on success and clearing the removed
 *                node's own next pointer.
 * func_02069F7C  tries all three of the owner's lists (+0x08, +0x10, +0x18)
 *                in turn and sets bit 4 of the owner's word at +0x00 if any
 *                of them claimed the node.
 *
 * Two shape notes from the derivation:
 *  - In func_02069F08, `q` must be DECLARED BEFORE `p`; with the natural
 *    order the trailing cursor takes r0 instead of r2 and eleven bytes go
 *    wrong across the search loop. The inner unlink is `p->next = q->next`,
 *    not `p->next = target->next`, so the load comes off the cursor.
 *  - In func_02069F7C the three guards must NEST (each failure falling into
 *    the next attempt) so the three success paths share one tail; three
 *    separate early returns duplicate the flag store.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02069F08.c \
 *       --addr 0x02069F08 --arm
 */
u32 func_02069F08(Node_02069D14_02069E88 **head, Node_02069D14_02069E88 *target)
{
    Node_02069D14_02069E88 *q;
    Node_02069D14_02069E88 *p;

    p = *head;
    if (p == 0) return 0;
    if (p == target) {
        *head = p->next;
        target->next = 0;
        return 1;
    }
    for (q = p->next; q != 0; q = q->next) {
        if (q == target) {
            p->next = q->next;
            q->next = 0;
            return 1;
        }
        p = q;
    }
    return 0;
}




void func_02069F7C(Owner_02069D14 *o, Node_02069D14_02069E88 *item)
{
    if (!func_02069F08((Node_02069D14_02069E88 * *)(&o->l08), (Node_02069D14_02069E88 *)item)) {
        if (!func_02069F08((Node_02069D14_02069E88 * *)(&o->l10), (Node_02069D14_02069E88 *)item)) {
            if (!func_02069F08((Node_02069D14_02069E88 * *)(&o->l18), (Node_02069D14_02069E88 *)item)) {
                return;
            }
        }
    }
    o->flags00 |= 0x10;
}




int func_02069FD0(int p)
{
    return p ? (((struct Obj16534 *)p)->fC << 3) : 0;
}




int func_02069FE4(int p)
{
    return p ? (((struct Obj16535 *)p)->f1C << 3) : 0;
}




void func_02069FF8(char *p, int a, int b)
{
    if (a) *(int *)&((struct Obj01198 *)p)->f8 = a;
    if (b) *(int *)&((struct Obj01198 *)p)->f18 = b;
}




/*
 * The ATTACH half of the upload descriptor whose DETACH half is
 * src/matched/func_0206A0C4.c: push this descriptor's texture slot and its
 * palette slot into texture VRAM and mark each uploaded.  `wrap` asks for the
 * GX_BeginLoadTex / GX_EndLoadTex bracket to be opened and closed here; a
 * caller uploading several descriptors in a row passes 0 and brackets the run
 * itself.  The SDK names are the ones docs/families/cluster_020637F4.h already
 * fixed for 0x0207F7A0 / 0x0207F7FC / 0x0207F9B4.
 *
 * THE PALETTE SLOT IS UPLOADED TWICE, and that is not a transcription error:
 * 0x0206A07C and 0x0206A0A0 are two GX_LoadTex calls from two different source
 * pointers (+0x24 and +0x28) to two different VRAM offsets, the second being
 * the first remapped into the second palette bank at half the size.  The
 * remap, read off 0x0206A080..0x0206A098 with the pool word 0x0001FFFF at
 * 0x0206A0C0, is
 *
 *     ((off & 0x1FFFF) >> 1) + 0x20000 + ((off & 0x40000) >> 2)
 *
 * with the length halved: the low 17 bits of the offset are scaled to 4-bit
 * palettes, bit 18 (the bank select) is moved down two places, and 0x20000 is
 * the second bank's base.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. +0x08 AND +0x18 ARE `u32` FIELDS, NOT `u16`.  The image loads each with
 *      a full-word `ldr` and then narrows with the UNEQUAL shift pair
 *      `lsl #0x10` / `lsr #0xd`, which is
 *      docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md:
 *      a 16-bit truncation folded with the `<< 3` that scales it.  Declaring
 *      them `u16` gives `ldrh` and a separate `lsl #3` and is 125 concrete
 *      bytes out; the cast `(u32)(u16)f << 3` on a u32 field does not fold
 *      either and comes out 4 bytes long.  Only the shift pair written out as
 *      `(u->f08 << 16) >> 13` reproduces the image.
 *
 *   2. `hi` (the `<< 16` result) MUST SURVIVE as its own value.  The image
 *      keeps it in r4 across both calls and re-derives the remap's operand
 *      from it with `and r0, r0, r4, lsr #13` rather than from the already
 *      computed offset.  Writing the remap in terms of `off` instead of
 *      `hi >> 13` is 8 bytes out even with everything else right.
 *
 *   3. +0x28 IS READ INTO A NAMED LOCAL BEFORE THE FIRST CALL.  The image has
 *      `ldr r5, [sb, #0x28]` at 0x0206A078, one instruction ahead of the first
 *      GX_LoadTex, because the value has to be live across it; reading
 *      `u->f28` at the second call site instead leaves the function one
 *      callee-saved register short, so it pushes six registers where the image
 *      pushes eight and 51 concrete bytes differ.  This is
 *      docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md
 *      read in the other direction: here the extra register is what the image
 *      spends, so the local is required rather than forbidden.
 *
 *   4. THE TWO BLOCKS DO NOT SHARE A SIZE LOCAL.  `m` (the texture length) and
 *      `n` (the palette length) are separate locals even though the second
 *      assignment would kill the first; reusing one costs a register colour
 *      and is 6 bytes out.
 *
 * CLOSED BY THE PERMUTER, and worth recording as a clean case of it.  With all
 * four of the above right the residue was 5 concrete bytes and purely a
 * colouring tie -- `--explain` printed a three-way rotation (r6->r7, r7->r5,
 * r5->r6) with every instruction and relocation already correct.  Hand
 * respelling could not move it: five permutations of the declaration list all
 * gave the same 5 bytes, because these locals are coloured in first-definition
 * order rather than declaration order.  `--mode hill --budget 800 --jobs 8
 * --types` exhausted 253 singles at the same point; `--mode anneal --budget
 * 2000 --jobs 8 --types` reached EXACT and named its mutations as
 * `decl-order(d2<->n) ; block(if1,2) ; selfassign(n)`.  Only the FIRST of the
 * three is real: applied on its own to the readable source -- declaring `d2`
 * before `n` so `d2` takes r5 and `n` takes r6 -- it is byte-exact, and the
 * permuter's `if (1) { }` wrapper and its `n = n;` dead self-assignment are
 * search artefacts that this file does not carry.  Re-verified with match.py
 * one after the transfer.
 *
 * Both callers agree with the two-argument signature (0x02047080 and
 * 0x02047238, via src/matched/G3D_SYSTEM_TransVramTexture.c), and the sibling's callers
 * agree with the three-argument one (src/matched/G3D_SYSTEM_FreeVramTexture.c calls
 * func_0206A0C4(r, &x, &y)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A00C.c \
 *       --func func_0206A00C --addr 0x0206A00C --arm --cc 1.1p1
 *   -> EXACT, compiled 184 = original 184, 4 of 4 sites resolved
 */
void func_0206A00C(struct Up *u, u32 wrap)
{
    u32 m;
    u32 d2;
    u32 hi;
    u32 off;
    u32 n;

    if (wrap != 0) {
        GX_BeginLoadTex();
    }
    m = u->f0c << 3;
    if (m != 0) {
        GX_LoadTex((u8 *)u + u->f14, (u->f08 << 16) >> 13, m);
        u->f10 = (u16)(u->f10 | 1);
    }
    n = u->f1c << 3;
    if (n != 0) {
        hi = u->f18 << 16;
        off = hi >> 13;
        d2 = u->f28;
        GX_LoadTex((u8 *)u + u->f24, off, n);
        GX_LoadTex((u8 *)u + d2,
                   (((hi >> 13) & 0x1FFFF) >> 1) + 0x20000
                       + ((off & 0x40000) >> 2),
                   n >> 1);
        u->f20 = (u16)(u->f20 | 1);
    }
    if (wrap != 0) {
        GX_EndLoadTex();
    }
}

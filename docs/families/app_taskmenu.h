/*
 * docs/families/app_taskmenu.h -- shared declarations for the app_taskmenu.c
 * family (0x02027778..0x02028590 in the ARM9 image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived either from a file in src/matched that is EXACT (or EXACT*),
 * with the matched function that evidences each field named in the comment
 * beside it, or -- marked explicitly as such -- from src/pending/
 * func_02027778.c, which is DIFF, not EXACT, and is used only for the
 * struct-shape hints it gives (allocation size, field order at construction
 * time); nothing in this file should be taken to assert that the pending
 * function's own body is correct.  Where the matched sources disagree on the
 * spelling of a field or a parameter type (they were written by different
 * lanes against different partial views of the same object), the spelling
 * recorded here is the one the byte evidence actually constrains, and the
 * disagreement is noted.
 *
 * NOTE ON EXTENT AND CONTENTS.  The span holds at least two distinct
 * layouts:
 *   - struct TaskMenu (0x38 bytes): the menu object itself, constructed by
 *     func_02027778 (pending/DIFF) and torn down by func_02027858 (matched/
 *     EXACT*).  Field offsets are cross-checked against func_02027858,
 *     func_02027A08, func_02027A24, func_02027CFC, func_02027E3C and
 *     sub_020279E8 (func_020279E8), all matched/EXACT.
 *   - struct Anim (0x20 bytes): a per-entry animation/sub-object record,
 *     evidenced by func_02028178 (matched/EXACT*) and the small accessor
 *     cluster in packet pkt_02027FEC (func_0202846C, func_0202843C,
 *     func_02028454, func_02028230).
 * A few functions in the grep window are NOT part of this family and are
 * excluded here:
 *   - unit_02027710.c (func_02027710..func_02027774) is a different TU
 *     ("beacon_status" per its own comment) at 0x02027710, below the span
 *     start; included by the grep only because its packet name overlaps.
 *   - func_020285A4 is explicitly commented "TU: app_keycursor.c" and
 *     constructs an unrelated struct KeyCursor; func_02028590 merely calls
 *     it. Both are left out of the TaskMenu/Anim layouts below, though
 *     func_02028590's extern is listed since it sits inside the address
 *     span.
 */

#ifndef APP_TASKMENU_H
#define APP_TASKMENU_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * struct TaskMenuTmpl: the template the caller passes to func_02027778,
 * and which is copied byte-for-byte into TaskMenu (at +0x20, see below).
 * Evidenced ONLY by src/pending/func_02027778.c (DIFF, not EXACT) --
 * layout recorded here as a shape hint, not as confirmed-by-bytes.
 * ------------------------------------------------------------------ */
struct TaskMenuTmpl {
    u32         heapId;   /* +0x00  pending func_02027778: (u16)tmpl->heapId
                           *        passed to func_02030734 twice */
    u8          count;    /* +0x04  pending func_02027778: *p where
                           *        p = (u8*)m + 0x24, i.e. tmpl+4; also the
                           *        `count` matched code reads at TaskMenu
                           *        +0x24 (see below) */
    u8          pad05[3]; /* +0x05  no matched function touches these */
    const void *unk08;    /* +0x08  pending func_02027778: source of the
                           *        MIi_CpuCopy16 into buf2, count*12 bytes */
    u32         unk0c;    /* +0x0c  pending func_02027778: copied, otherwise
                           *        untouched in the constructor */
    u8          pad10[2]; /* +0x10  no matched function touches these */
    u8          unk12;    /* +0x12  pending func_02027778: defaulted to 13
                           *        when the caller passes 0; per-row height
                           *        divisor consumed as TaskMenu+0x32 (see
                           *        func_02027E3C, func_02028178) */
    u8          unk13;    /* +0x13  pending func_02027778: defaulted to 3
                           *        when the caller passes 0; consumed as
                           *        TaskMenu+0x33 */
};

/* ------------------------------------------------------------------ *
 * struct TaskMenu: 0x38 bytes, evidenced as that size by the literal 0x38
 * passed to func_02030734 in src/pending/func_02027778.c (DIFF; size hint
 * only).  Field offsets below are the ones the MATCHED accessor/teardown
 * functions actually dereference; the pending constructor's own field
 * names ("unk00", "unk01", ...) are folded in here under the spellings the
 * matched call sites constrain, per the task's "disagreement" rule.
 * ------------------------------------------------------------------ */
struct TaskMenu {
    u8   index;       /* +0x00  func_02027974 (p->f00, used as table[]
                       *        index); func_02027A08 (tm->type, used the
                       *        same way: `tm->table[tm->type]`); func_02027E3C
                       *        (m[0], read and written as the current
                       *        cursor/selection); func_02027CFC (loop
                       *        compares `i == sel` then writes *p = sel).
                       *        Matched sources spell it both `f00`/`type`
                       *        and, via func_02027CFC's `*p = sel`, as a
                       *        plain selection index -- recorded here as
                       *        `index`, the spelling all call sites agree
                       *        with functionally. */
    u8   entryPhase;  /* +0x01  func_02027974: p->f01, incremented every
                       *        call (`p->f01 = p->f01 + 1`) and divided by
                       *        a step to pick a 0/1 mode bit; read-modify-
                       *        write byte, so u8 */
    u16  colorPhase;  /* +0x02  func_02027974: &p->f02 passed to
                       *        func_02027B60 as `u16 *phase`, the running
                       *        color-cycle phase */
    u16  color;       /* +0x04  func_02027974: &p->f04 passed to
                       *        func_02027B60 as `u16 *out`, the computed
                       *        RGB555 color */
    u8   pad06[0x08 - 0x06]; /* +0x06  no matched function touches these
                       *        two bytes (func_02027974's Obj typedef pads
                       *        0x06..0x0c as one block; nothing in this
                       *        family reads +0x06/+0x07 specifically) */
    u32  obj;         /* +0x08  func_02027858: `func_02045730(m->cells[0])`
                       *        reads through cells[] not this field
                       *        directly, but pending func_02027778 leaves
                       *        +0x08 as `unk08` set to 1 at the very end of
                       *        construction (`m->unk08 = 1`); no matched
                       *        function dereferences +0x08 on TaskMenu
                       *        itself, so this is a pending-only field,
                       *        kept for shape, not confirmed live/flag
                       *        semantics */
    u32  state;       /* +0x0c  func_0202784C: `*(int*)(t0+20)... ` -- NOTE:
                       *        func_0202784C actually writes offset +0x14,
                       *        not +0x0c (source literal is `+ 20` = 0x14);
                       *        see `phase` below. +0x0c itself is set to 0
                       *        by pending func_02027778 (`m->unk0c = 0`)
                       *        and otherwise not dereferenced by any
                       *        matched TaskMenu function; kept as a gap. */
    u32  pad10;       /* +0x10  pending func_02027778 zeroes it
                       *        (`m->unk10 = 0`); no matched function reads
                       *        it back on TaskMenu */
    u32  phase;       /* +0x14  func_0202784C (matched/EXACT): writes the
                       *        literal 2 to `t0 + 20` where t0 is the
                       *        return of func_02027778, i.e. TaskMenu+0x14;
                       *        pending func_02027778 initializes the same
                       *        offset to 1 (`m->unk14 = 1U`).  A state/
                       *        phase word: constructed as 1, advanced to 2
                       *        by func_0202784C. */
    void **table;     /* +0x18  func_02027A08 (matched/EXACT): `tm->table`,
                       *        indexed by `index` to fetch a function
                       *        pointer: `fn = tm->table[index]`.
                       *        func_02027858 spells the same offset
                       *        `cells` (`void **cells`) and indexes it by
                       *        the per-cell loop counter; func_02027E3C
                       *        reads it as `*(u32**)(m+0x18)` indexed by
                       *        m[0] (== index) to get an item pointer
                       *        passed to func_02027B30.  All three treat
                       *        +0x18 as an array of per-entry handles/fn
                       *        pointers, one slot per menu row; recorded
                       *        here as `table` since func_02027A08 is the
                       *        only one to dereference an element as a
                       *        callable target. */
    void *rows;       /* +0x1c  func_02027A24 (matched/EXACT*): `o->rows`,
                       *        an array of struct Row (0xc bytes each,
                       *        stride confirmed by `o->rows[i].f08` /
                       *        `rows[i].f00` addressing); func_02027858
                       *        spells the same offset `unk_1c` (opaque
                       *        pointer, only passed to the deallocator);
                       *        func_02027FD8 spells a same-shaped struct's
                       *        +0x08 as `child` -- different packet
                       *        (pkt_02027A04) and only 8 bytes into its own
                       *        struct, so NOT necessarily the same offset
                       *        as this one; not folded in. */
    u8   pad20[0x24 - 0x20]; /* +0x20  covered by struct TaskMenuTmpl's
                       *        leading bytes per the pending constructor
                       *        (`m->tmpl = *tmpl` at TaskMenu+0x20); no
                       *        matched TaskMenu function dereferences
                       *        +0x20..+0x23 directly */
    u8   count;       /* +0x24  func_02027858 (matched/EXACT*): `m->count`,
                       *        an 8-bit loop bound (`lsls #24`/`lsrs #24`
                       *        pair after increment); func_02027A24:
                       *        `o->count`, same role; sub_020279E8/
                       *        func_020279E8 (matched/EXACT): `m->count`
                       *        compared against `16 / m->height`;
                       *        func_02027CFC: `*(u8*)(p + 0x24)` as the
                       *        loop bound; func_02027E3C: `m[0x24]`, same.
                       *        This is also TaskMenuTmpl.count (tmpl+4),
                       *        per the pending constructor's
                       *        `p = (u8*)m + 0x24`. */
    u8   pad25[0x2c - 0x25]; /* +0x25  no matched function in this family
                       *        touches these seven bytes */
    u32  inset;       /* +0x2c  func_02027A24: `o->inset`, a flag selecting
                       *        between a plain origin (x0,y0) and an inset
                       *        one; func_02027E3C: `*(int*)(m+0x2C)`, same
                       *        role, same test (`== 0`) */
    u8   x0;          /* +0x30  func_02027A24: `o->x0`; func_02027E3C:
                       *        `m[0x30]` */
    u8   y0;          /* +0x31  func_02027A24: `o->y0`; func_02027E3C:
                       *        `m[0x31]` */
    u8   dx;          /* +0x32  func_02027A24: `o->dx`, per-row x step, also
                       *        TaskMenuTmpl.unk12's destination per the
                       *        pending constructor's copy-then-default;
                       *        func_02027E3C: `m[0x32]`, used identically
                       *        as the row-height divisor / inset amount */
    u8   dy;          /* +0x33  func_02027A24: `o->dy`, per-row y step /
                       *        TaskMenuTmpl.unk13's destination;
                       *        func_02027E3C: `m[0x33]` */
    void *glyph;      /* +0x34  func_02027A24: `o->glyph`, dereferenced as
                       *        `struct Glyph { u16 f00; u16 f02; }`;
                       *        func_02027E3C, func_02027CFC, func_02027974,
                       *        func_02028218/func_0202843C-style callers
                       *        (different struct, see Anim below) spell
                       *        the same TaskMenu offset `ctx`/`arg1` --
                       *        this is also `arg1`, the opaque context the
                       *        constructor stores and every per-row
                       *        callback receives as its second argument
                       *        (func_02027B30's `s`/`sub`/`ctx` parameter).
                       *        Disagreement note: func_02027A24 dereferences
                       *        it as a small glyph-metrics struct while
                       *        func_02027778/func_02027E3C/func_02027CFC
                       *        treat it as an opaque `void *` handed
                       *        through to func_02027B30 -- both are
                       *        consistent with the SAME pointer value being
                       *        read two ways by different callees; kept as
                       *        `void *glyph` here since func_02027A24 is
                       *        the only matched site to dereference it. */
};
/* sizeof(struct TaskMenu) == 0x38, per src/pending/func_02027778.c's
 * allocation size (DIFF; size hint only, not EXACT-confirmed). */

/* ------------------------------------------------------------------ *
 * struct TaskMenuOwner: the shared "owner" object TaskMenu's teardown
 * releases queued items through.  Evidenced only by func_02027858
 * (matched/EXACT*), which never constructs one, only reads +0x14 off it.
 * ------------------------------------------------------------------ */
struct TaskMenuOwner {
    u8    pad_00[0x14]; /* +0x00  no matched function in this family
                         *        touches these bytes */
    void *queue;        /* +0x14  func_02027858: `m->unk_34->unk_14`,
                         *        passed to func_0201C6C4 and func_0201C4E4
                         *        as the drain queue */
};

/* ------------------------------------------------------------------ *
 * struct Anim: 0x20 bytes, the per-entry animation/sub-object step record.
 * Evidenced by func_02028178 (matched/EXACT*, the per-frame step) plus the
 * accessor cluster in packet pkt_02027FEC.
 * ------------------------------------------------------------------ */
struct Anim {
    u32  obj;         /* +0x00  func_02028178: `*(u32*)p`, passed to
                       *        func_02045770/func_02045334/func_02045374/
                       *        func_02045730 as a cell/surface handle */
    u32  unk04;       /* +0x04  no matched function in this family
                       *        dereferences +0x04; kept for shape only
                       *        (func_02028178's own comment block does not
                       *        mention it) */
    u32  unk08;       /* +0x08  func_02028178: `*(u32*)(p+8)` tested as a
                       *        "run the frame-advance arm" flag */
    u32  teardownFlag;/* +0x0c  func_02028178: `*(u32*)(p+0xc)`, tested,
                       *        and cleared to 0 once the sub-object at +0
                       *        finishes; func_0202846C (matched/EXACT):
                       *        `return *(u32*)(p + 0xc)`, a bare getter for
                       *        this same field (same packet, pkt_02027FEC) */
    u16  frame;       /* +0x10  func_02028178: `*(u16*)(p+0x10)`, the frame
                       *        counter, incremented and tested against a
                       *        divisor; func_02028230 (matched/EXACT):
                       *        `*(u16*)(p + 0x10)` compared to `0x10 /
                       *        *(u16*)(p + 0x12)` */
    u16  div;         /* +0x12  func_02028178: `*(u16*)(p+0x12)`, the
                       *        divisor for the frame-parity/threshold test
                       *        (`4 / div` and, in func_02028230, `0x10 /
                       *        div`); same field, two different numerators
                       *        in the two matched call sites */
    u8   unk14[4];    /* +0x14  func_02028178: `p+0x14`/`p+0x16` passed as
                       *        two separate `u8*` outs to func_02027BF4
                       *        (unmatched callee, no witness -- see
                       *        func_02028178's blocker note); treated as
                       *        raw bytes here rather than split fields
                       *        since no matched function assigns a single-
                       *        field type to +0x14/+0x16 individually */
    void *ctx;        /* +0x18  func_02028178: `*(u32*)(p+0x18)`, passed to
                       *        func_02027B30 as its second argument and to
                       *        func_0201C6C4 as `*(u32*)(ctx+0x14)`;
                       *        func_0202843C, func_02028454 (both matched/
                       *        EXACT, same packet): `*(u32*)(*(u32*)(p +
                       *        0x18))` narrowed to a byte via a u16 read --
                       *        i.e. `ctx` points at a struct whose own
                       *        +0x00 is a u16 consumed by func_02041B6C;
                       *        func_02028218 (matched/EXACT*, different
                       *        packet pkt_02028178 but the same shape)
                       *        spells this same relative offset `field_18`
                       *        on its own 4-word-plus-halfword `struct
                       *        Obj`, consistent with Anim.ctx. */
    u16  unk1c;       /* +0x1c  func_02028178: `*(u16*)(p+0x1c)`, passed
                       *        through to func_02027BF4 unexamined */
    u16  unk1e;       /* +0x1e  func_02028178: `*(u16*)(p+0x1e)`, passed
                       *        through to func_02027BF4 unexamined */
};
/* sizeof(struct Anim) == 0x20, per func_02028178's own field layout (all
 * offsets it touches fit in 0x00..0x1f) -- NOT independently confirmed by
 * an allocation-size literal the way TaskMenu's 0x38 is. */

/* ------------------------------------------------------------------ *
 * struct Blk: the flags word tested by func_02028484's dispatch and by
 * func_020284F4/func_02028528/func_0202855C, all matched/EXACT.  Kept
 * separate from Anim/TaskMenu: func_02028484's own comment identifies it
 * as "one handle attached to a state block", a different object.
 * ------------------------------------------------------------------ */
typedef struct Blk {
    u8  first;   /* +0x00  func_02028484: `blk->first`, a latch bit toggled
                 *        by the state-0 arm */
    u8  pad[3];  /* +0x01  no matched function touches these */
    u32 flags;   /* +0x04  func_02028484: `blk->flags`, passed whole to
                 *        func_020284F4/func_02028528/func_0202855C, and
                 *        bit-tested locally (`1 << 10`) */
} Blk;

/* ------------------------------------------------------------------ *
 * Prototypes, exactly as the matched sources in this family spell them.
 * Where two matched call sites disagree on a parameter's width or
 * signedness, the spelling used is the one the dereferencing site (not
 * the pass-through site) constrains.
 * ------------------------------------------------------------------ */

/* Constructor (pending/DIFF -- shape hint, not confirmed by bytes). */
extern struct TaskMenu *func_02027778(const struct TaskMenuTmpl *tmpl,
                                      void *arg1);

/* func_0202784C (matched/EXACT): calls func_02027778() with no visible
 * arguments in the compiled body (arguments a0..a3 are unused) and writes
 * TaskMenu+0x14 = 2 on the result. */
extern struct TaskMenu *func_0202784C(int a0, int a1, int a2, int a3);

/* func_02027858 (matched/EXACT*): full teardown. */
extern void func_02027858(struct TaskMenu *m);

/* func_02027A08 (matched/EXACT): dispatch through TaskMenu.table[index]. */
extern u32 func_02027A08(struct TaskMenu *tm, u32 arg);

/* func_02027A24 (matched/EXACT*): builds the o->count BG layers. */
extern void func_02027A24(struct TaskMenu *o, void *cfg);

/* func_02027974 (matched/EXACT): per-frame color-cycle step; note this
 * matched source's own local struct spells the object `Obj`, offsets
 * folded into struct TaskMenu above. */
extern void func_02027974(struct TaskMenu *p);

/* func_02027E3C (matched/EXACT): touch handler / cursor mover. Matched
 * source takes `u8 *m` (byte-offset addressing throughout); the pointer is
 * a struct TaskMenu*. */
extern void func_02027E3C(u8 *m);

/* func_02027CFC (matched/EXACT): select entry `sel`, repaint all rows. */
extern void func_02027CFC(u8 *p, int sel);

/* sub_020279E8 / func_020279E8 (matched/EXACT): "needs more than one page"
 * predicate. Matched source's own local struct duplicates count@+1,
 * height@+0x14 -- NOTE this disagrees with the consolidated TaskMenu
 * layout above (count is at +0x24 there, not +1); func_020279E8's struct
 * is a narrower/local view and its own field names ("pad00/count/pad02/
 * height") are not folded into struct TaskMenu since the two do not agree
 * on where `count` lives.  Recorded here as its own prototype only. */
extern u32 func_020279E8(struct TaskMenu *m);

/* func_02027B30 (matched/EXACT, packet pkt_02027A24): per-row repaint
 * primitive; called with (item, ctx, self) from func_02027974,
 * func_02027E3C, func_02027CFC, func_02028178, func_020282AC-adjacent
 * code. Parameter names vary by call site (a0/s/mode vs item/sub/self vs
 * obj/ctx/flag); recorded as (item, ctx, flag) since that spelling matches
 * the plurality of matched call sites. */
extern void func_02027B30(u32 item, void *ctx, u32 flag);

/* func_02027B60 (matched/EXACT): color-phase step + palette write. */
extern void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot);

/* func_02027A04 (matched/EXACT): trivial byte load, used as an accessor
 * somewhere in the family; too small to pin to a specific struct offset. */
extern u8 func_02027A04(const u8 *p);

/* func_02027FD8 (matched/EXACT): frees a two-pointer TaskMenuState-shaped
 * object; NOT confirmed to be struct TaskMenu itself (only 8 bytes into
 * its own struct are referenced, and the packet, pkt_02027A04, is shared
 * with the unrelated byte-accessor func_02027A04, not with TaskMenu's own
 * pkt_02027778/pkt_02027A24/pkt_02027FEC packets). */
struct TaskMenuState {
    u8    pad[8];
    void *child; /* +0x08  func_02027FD8: freed alongside the struct
                  *        itself */
};
extern void func_02027FD8(struct TaskMenuState *s);

/* Anim family, packet pkt_02027FEC. */
extern u32   func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                           u32 a6, u32 a7, u32 a8); /* matched/EXACT*:
                           allocates+configures, tears down p[0] on the
                           three-call quartet */
extern u32   func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
                           /* matched/EXACT: thin wrapper over
                              func_0202800C(a0,a1,a2,a3,a4,3,0,0,a5) */
extern u32  *func_02028084(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                           u32 a6, u32 a7, u32 a8); /* unmatched callee,
                           prototype constrained by func_0202800C and
                           func_0202804C's identical call shape */
extern u32  *func_0202804C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                           u32 a6, u32 a7, u16 a8); /* matched/EXACT*:
                           sibling of func_0202800C, same teardown minus
                           func_02045334 */
extern void  func_02028148(u8 *p); /* matched/EXACT: releases *(u32*)p then
                                       frees p via func_02028164 */
extern void  func_02028164(u8 *p); /* matched/EXACT: releases *(u32*)p,
                                       frees p */
extern void  func_0202815C(void);  /* matched/EXACT: 8-byte tail-call thunk
                                       to func_02028164 */
extern void  func_02028178(struct Anim *p); /* matched/EXACT*: per-frame
                                       step, see struct Anim above; matched
                                       source's own parameter is `u8 *p` */
extern u32   func_02028230(struct Anim *p); /* matched/EXACT: threshold
                                       test on frame/div, matched source's
                                       own parameter is `u8 *p` */
extern u32   func_0202846C(struct Anim *p); /* matched/EXACT: bare getter
                                       for teardownFlag (+0x0c) */
extern void  func_0202843C(struct Anim *p); /* matched/EXACT: releases
                                       *(u32*)p then notifies via ctx
                                       (+0x18) */
extern void  func_02028454(struct Anim *p); /* matched/EXACT: identical
                                       body to func_0202843C, different
                                       release call (func_02045374 vs
                                       func_020456F8) */
extern void  func_02028470(u8 *p, u32 v); /* matched/EXACT: zeroes an
                                       8-byte block then sets +4 = v; too
                                       small a footprint to confirm as
                                       struct Anim's own first 8 bytes,
                                       kept as a bare `u8 *` */
extern void  func_020282A4(u8 *p); /* matched/EXACT: clears field_08 (u32)
                                       and field_10 (u16) of an unnamed
                                       struct with the local shape `{ u32
                                       pad_00[2]; u32 field_08; u32 pad_0c;
                                       u16 field_10; u16 pad_12; }`; offsets
                                       do not line up with struct Anim
                                       (Anim+0x08/+0x10 are u32/u16 too, so
                                       this MAY be the same struct, but no
                                       matched function ties the two
                                       together -- left unfolded, flagged
                                       as a possible-but-unconfirmed alias
                                       of struct Anim) */
/* func_020282AC (matched/EXACT, packet pkt_0202824C): local struct T's
 * f1c/f1e line up with struct Anim's unk1c/unk1e by offset, but this is a
 * different packet and no shared call site confirms it is the same
 * struct; kept as its own local struct T, not folded into Anim. */
struct T {
    u32 f00;
    u8  pad04[0x18];
    u16 f1c;
    u16 f1e;
};
extern void  func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
extern u32   func_0202824C(void **p); /* matched/EXACT*: touch hit test
                                       against a window descriptor `p[0]`;
                                       unrelated struct (window, not
                                       Anim/TaskMenu) */

/* func_02028218 (matched/EXACT*, packet pkt_02028178): six-instruction
 * leaf clearing field_14 (u16) and tail-calling func_02027B30 with
 * field_00/field_18. Matched source's own struct: */
struct Obj18 {
    u32 field_00;
    u32 pad_04[4];
    u16 field_14;
    u16 pad_16;
    u32 field_18;
};
extern void func_02028218(struct Obj18 *obj, u32 a);

/* func_0202822E (matched/EXACT): bare `bx lr`, empty function, same
 * packet as func_02028218 (pkt_02028178). */
extern void func_0202822E(void);

/* func_02027BF4: unmatched callee referenced from func_02028178; no
 * witness elsewhere in the image (see func_02028178's blocker note).
 * Prototype below is inferred purely from func_02028178's call site. */
extern void func_02027BF4(void *a, void *b, u32 c, u32 d, u32 e, u32 f);

/* func_02028484 (matched/EXACT): per-frame service step for one handle
 * attached to a Blk. */
extern s32 func_02028484(Blk *blk, void *h);
extern u32 func_020284F4(u32 flags); /* matched/EXACT */
extern u32 func_02028528(u32 flags); /* matched/EXACT */
extern u32 func_0202855C(u32 flags); /* matched/EXACT */

/* func_02028590 (matched/EXACT): inside the address span, but calls into
 * the UNRELATED app_keycursor.c TU (func_020285A4); listed for
 * completeness of the span, not folded into TaskMenu/Anim. */
extern void func_02028590(u32 a0, u32 a1, u32 a2, u32 a3);
extern char g_0209FD10[]; /* func_02028590: literal data pointer forwarded
                             as func_020285A4's `pixels` argument */

/* ------------------------------------------------------------------ *
 * External callees, prototypes as constrained by the matched call sites
 * above. Many are shared with other families (the 0x0204xxxx cell/surface
 * API, the heap allocator, notification dispatch); only the constraints
 * this family's matched sources impose are recorded.
 * ------------------------------------------------------------------ */
extern u32   _u32_div_f(u32 a, u32 b);          /* func_02027974, func_020279E8 */
extern s32   _s32_div_f(s32 a, s32 b);          /* func_02028178, func_02028230 (inferred from `/` on signed s16 operands; the div helper itself is not dereferenced by any matched source here, only called) */
extern void  func_02045798(void *p, u32 n);     /* func_02027B30, func_020282AC */
extern void  func_02045374(void *p);            /* func_02027B30, func_0202800C, func_0202804C, func_02028454 */
extern void  func_02045730(void *p);            /* func_02027B30, func_0202800C, func_0202804C, func_02027858 */
extern void  func_02041B6C(void *p);            /* func_02027B30, func_0202800C, func_0202804C, func_02027858, func_0202843C, func_02028454 */
extern void  func_020456F8(void *cell);         /* func_02027858, func_02028148, func_0202843C */
extern void  func_020452E8(void *cell);         /* func_02027858, func_02028164 */
extern u32   func_02045770(u32 cell);           /* func_02027A24, func_02028178, func_02027858 */
extern void  func_02045334(u32 cell);           /* func_02027A24, func_0202800C, func_02028178 */
extern u32   func_0201C6C4(void *q, void *item);/* func_02027858, func_02028178 */
extern void  func_0201C4E4(void *q);            /* func_02027858 */
extern void  func_020307B0(void *p);            /* func_02027858, func_02028164, func_02027FD8 */
extern u32   func_02030DA8(void *owner, const u8 *tag, void *p, u32 a3); /* shared heap-record API, see docs/families/time_icon.h */
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line); /* func_02027778 (pending); shared
                           allocator, see docs/families/time_icon.h */
extern void  MIi_CpuCopy16(const void *src, void *dst, u32 size); /* func_02027778 (pending) */
extern int   func_02035C08(const void *key);    /* func_02027E3C */
extern void  func_020355D8(int v);              /* func_02027E3C, func_02027CD8 */
extern void  func_020061E4(u32 id);              /* func_02027E3C, func_02028484 */
extern int   func_020355C4(void *p);             /* func_02027CFC, func_02027778 (pending, spelled func_020355c4) */
extern u32   func_02035D20(u32 *x, u32 *y);      /* func_0202824C */
extern u32   func_02045738(void *w);             /* func_0202824C */
extern u32   func_02045758(void *w);             /* func_0202824C */
extern u32   func_02045760(void *w);             /* func_0202824C */
extern u32   func_0201CE30(void *h);             /* func_02028484 */
extern void  func_0201CE38(void *h);             /* func_02028484 */
extern void  func_0201CE5C(void *h, u32 v);      /* func_02028484 */
extern u32   func_020362DC(void);                /* func_020284F4 */
extern u32   func_02035C60(void);                /* func_020284F4 */
extern u32   func_0203630C(void);                /* func_02028528, func_0202855C */
extern u32   func_02035C38(void);                /* func_02028528, func_0202855C */
extern void  func_02082BCC(void *p, u32 v, u32 size); /* func_02028470 */
extern s32   sub_02061CA4(void *p, u32 a, u32 b, s32 size); /* func_02027B60 */

/* ------------------------------------------------------------------ *
 * Pinned data objects.
 * ------------------------------------------------------------------ */
extern s16   tbl_020A1B38[];   /* func_02027B60: palette ramp table */
extern char  sFile_020A74E0[]; /* func_02027778 (pending): __FILE__ anchor,
                                   likely the family's own "app_taskmenu.c"
                                   string; not independently confirmed
                                   EXACT since the constructor is DIFF */

/* ------------------------------------------------------------------ *
 * WAVE 12 (2026-09-23): the family's four open functions are closed.
 * func_02027778 (the constructor) is now EXACT in src/matched, so the
 * "pending/DIFF, shape hint only" caveats above on struct TaskMenuTmpl and
 * struct TaskMenu's construction-time fields are now byte-proven.  Facts
 * proven, each by an EXACT file:
 *
 *   func_02027778  the template parameter is NOT const (a const pointer
 *                  lets mwcc hoist the +0x12 default's load above the
 *                  three zero stores); the template's count is read as
 *                  m->tmpl.count.
 *   func_02027F60  func_020275E4()'s result is the FIRST argument of both
 *                  0x02049xxx loaders:
 *                    func_02049DB4(h, 0x20, 0, &r->f04, heap)
 *                    func_02049B40(h, 0x1f, sel, a1 << 5, 0x40, heap)
 *                  and the heap id is a plain fifth (stack) u16 parameter.
 *   func_02027BF4  third parameter is u16:
 *                    void func_02027BF4(u16 *phase, u16 *out, u16 mode,
 *                                       u32 slot, u16 c0, u16 c1);
 *                  (the extern above, inferred from func_02028178's call
 *                  site, is superseded by this).
 *   func_02027D44  the per-frame input step: up/down play sound 0x548,
 *                  confirm plays 0x551/0x54C, cancel 0x551; in the cancel
 *                  arm the cursor store precedes m->f0C = 1 in the source.
 * ------------------------------------------------------------------ */

#endif /* APP_TASKMENU_H */

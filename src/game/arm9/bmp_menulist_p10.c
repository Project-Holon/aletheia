/*
 * file:     bmp_menulist_p10.c
 * unit:     yes
 * function: func_02020F84, func_02020FB4, func_02020FE4, func_02021014, func_020210C8, func_02021288, func_020212B0, func_020212E4, func_0202130C, func_02021350, func_0202136C, func_0202138C, func_020213AC
 * address:  0x02020F84
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
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02020F34  0x02020F34  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   g_0209EAA0     0x0209EAA0  data
 *   g_0209E8EC     0x0209E8EC  data
 */
struct MsgBank;
struct Rec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed char    s8;

/* The sub-record at +0x10 of the header, seventeen bytes of packed fields. */
struct Sub {
    u8 b00_0 : 1;
    u8 b00_1 : 1;
    u8 b00_2 : 1;
    u8 b00_3 : 1;
    u8 b00_4 : 1;
    u8 b00_5 : 1;
    u8 b00_6 : 1;
    u8 b00_7 : 1;

    u8 b01_0 : 1;
    u8 b01_1 : 1;
    u8 b01_2 : 1;
    u8 b01_3 : 1;
    u8 b01_4 : 4;

    u8 b02_0 : 4;
    u8 b02_4 : 4;

    u8 b03_0 : 4;
    u8 b03_4 : 4;

    u8 b04_0 : 4;
    u8 b04_4 : 2;
    u8 b04_6 : 1;
    u8 b04_7 : 1;

    u8 b05_0 : 1;
    u8 b05_1 : 1;
    u8 b05_2 : 1;
    u8 b05_3 : 1;
    u8 b05_4 : 1;
    u8 b05_5 : 1;
    u8 b05_6 : 1;
    u8 b05_7 : 1;

    u8 b06_0 : 1;
    u8 b06_1 : 1;
    u8 b06_2 : 1;
    u8 b06_3 : 1;
    u8 b06_4 : 1;

    s8 f07;
    s8 f08;
    s8 f09;
    s8 f0A;
    s8 f0B;
    s8 f0C;
    u8 f0D;
    u8 f0E;
    s8 f0F;
    s8 f10;
    s8 f11;
};

/* The record header. */
struct Rec {
    u16 f00;
    u8  f02;
    u8  f03;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u16 b08_0  : 5;
    u16 b08_5  : 1;
    u16 b08_6  : 1;
    u16 b08_7  : 4;
    u16 b08_11 : 5;
    u8  f0A;
    u8  f0B;
    u8  f0C;
    u8  f0D;
    u8  f0E;
    u8  f0F;
    u8  f10;
};

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02020F34(u32 item, u32 which, u32 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
int func_020210C8(struct Sub *q, u32 sel);
void func_02020F84(void *dst, u32 entry, u32 heap);
void func_02020FB4(void *dst, u32 entry, u32 heap);
u32 func_02020FE4(void *a, u32 sel, u32 id);
u32 func_02021014(struct Rec *p, u32 sel);
u16 func_020212B0(u16 id);
u32 func_020212E4(u16 v);
u32 func_0202130C(u32 id);
u8 func_02021350(u16 id);
u32 func_0202136C(u16 v);
u8 func_0202138C(u16 v);
u16 func_020213AC(u32 i);
extern const u16 g_0209EAA0[];
extern const u16 g_0209E8EC[];



/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020F84.c  *       --func func_02020F84 --addr 0x02020F84 --cc 1.1p1 --thumb
 */
void func_02020F84(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x36, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}



/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FB4.c  *       --func func_02020FB4 --addr 0x02020FB4 --cc 1.1p1 --thumb
 */
void func_02020FB4(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x35, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}



/*
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FE4.c \
 *       --func func_02020FE4 --addr 0x02020FE4 --cc 1.1p1 --thumb
 */
u32 func_02020FE4(void *a, u32 sel, u32 id)
{
    void *rec;
    u32   v;

    rec = func_02020F34((u32)a, 0, (u16)((id & 0x7FFF) | 0x8000));
    v = func_02021014(rec, sel);
    func_020307B0(rec);
    return v;
}



/*
 * A whole translation unit range, matched as one byte range.
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by func_02021014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to func_020210C8 on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because func_02021014's call to
 * func_020210C8 is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - func_02021014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: func_020210C8 takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring func_020210C8 as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  func_020210C8's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of func_02021014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of func_020210C8 are the signedness evidence
 * for the six plain fields at +7..+0xC and the three at +0xF..+0x11: there is
 * no immediate-offset `ldrsb`, so a signed byte load has to materialise its
 * offset in a register (docs/idioms/ldrsh-register-offset-is-signedness.md).
 * +0xD and +0xE load with a plain `ldrb` and are unsigned, which is why the
 * declared return type has to be signed for the rest to sign-extend.
 *
 * Addresses are Black-image addresses.  The bitfield block's contents are
 * content data, not code shape: if Pokemon White sizes this record
 * differently, the field list here is the thing to re-derive, not the dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02021014.c \
 *       --addr 0x02021014 --thumb
 */
u32 func_02021014(struct Rec *p, u32 sel)
{
    switch (sel) {
    case 0:
        return p->f00 * 10;
    case 1:
        return p->f02;
    case 2:
        return p->f03;
    case 3:
        return p->b08_5;
    case 4:
        return p->b08_6;
    case 5:
        return p->b08_7;
    case 6:
        return p->f0A;
    case 7:
        return p->f0B;
    case 8:
        return p->f04;
    case 9:
        return p->f05;
    case 10:
        return p->f06;
    case 11:
        return p->f07;
    case 12:
        return p->b08_0;
    case 13:
        return p->b08_11;
    case 14:
        return p->f0C;
    case 15:
        return p->f0D;
    case 16:
        return p->f0E;
    case 17:
        return p->f0F;
    }

    switch (p->f0C) {
    case 0:
        return p->f10;
    case 1:
        return func_020210C8((struct Sub *)&p->f10, sel);
    }
    return 0;
}

/*
 * A whole translation unit range, matched as one byte range.
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by func_02021014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to func_020210C8 on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because func_02021014's call to
 * func_020210C8 is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - func_02021014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: func_020210C8 takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring func_020210C8 as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  func_020210C8's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of func_02021014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of func_020210C8 are the signedness evidence
 * for the six plain fields at +7..+0xC and the three at +0xF..+0x11: there is
 * no immediate-offset `ldrsb`, so a signed byte load has to materialise its
 * offset in a register (docs/idioms/ldrsh-register-offset-is-signedness.md).
 * +0xD and +0xE load with a plain `ldrb` and are unsigned, which is why the
 * declared return type has to be signed for the rest to sign-extend.
 *
 * Addresses are Black-image addresses.  The bitfield block's contents are
 * content data, not code shape: if Pokemon White sizes this record
 * differently, the field list here is the thing to re-derive, not the dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02021014.c \
 *       --addr 0x02021014 --thumb
 */
int func_020210C8(struct Sub *q, u32 sel)
{
    switch (sel) {
    case 0x12:
        return q->b00_0;
    case 0x13:
        return q->b00_1;
    case 0x14:
        return q->b00_2;
    case 0x15:
        return q->b00_3;
    case 0x16:
        return q->b00_4;
    case 0x17:
        return q->b00_5;
    case 0x18:
        return q->b00_6;
    case 0x19:
        return q->b00_7;
    case 0x1A:
        return q->b01_0;
    case 0x1B:
        return q->b01_1;
    case 0x1C:
        return q->b01_2;
    case 0x1D:
        return q->b01_3;
    case 0x1E:
        return q->b01_4;
    case 0x1F:
        return q->b02_0;
    case 0x20:
        return q->b02_4;
    case 0x21:
        return q->b03_0;
    case 0x22:
        return q->b03_4;
    case 0x23:
        return q->b04_0;
    case 0x24:
        return q->b04_4;
    case 0x25:
        return q->b04_6;
    case 0x26:
        return q->b04_7;
    case 0x27:
        return q->b05_0;
    case 0x28:
        return q->b05_1;
    case 0x29:
        return q->b05_2;
    case 0x2A:
        return q->b05_3;
    case 0x2B:
        return q->b05_4;
    case 0x2C:
        return q->b05_5;
    case 0x2D:
        return q->b05_6;
    case 0x2E:
        return q->b05_7;
    case 0x2F:
        return q->b06_0;
    case 0x30:
        return q->b06_1;
    case 0x31:
        return q->b06_2;
    case 0x32:
        return q->b06_3;
    case 0x33:
        return q->b06_4;
    case 0x34:
        return q->f07;
    case 0x35:
        return q->f08;
    case 0x36:
        return q->f09;
    case 0x37:
        return q->f0A;
    case 0x38:
        return q->f0B;
    case 0x39:
        return q->f0C;
    case 0x3A:
        return q->f0D;
    case 0x3B:
        return q->f0E;
    case 0x3C:
        return q->f0F;
    case 0x3D:
        return q->f10;
    case 0x3E:
        return q->f11;
    }
    return 0;
}


/*
 * The membership test for the two id windows this file's tables are indexed
 * by: 0x148..0x1A9 and 0x26A..0x26C.  Written as one disjunction so that both
 * true arms share the single `movs r0, #1` exit and both false arms the single
 * `movs r0, #0` (docs/idioms/disjunction-must-be-one-expression-to-share-its-
 * exit.md); as two separate `if` statements each window grows its own return.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021288.c \
 *       --func func_02021288 --addr 0x02021288 --cc 1.1p1 --thumb
 */
u32 func_02021288(u32 id)
{
    if ((id >= 0x148 && id <= 0x1A9) || (id >= 0x26A && id <= 0x26C)) {
        return 1;
    }
    return 0;
}



/*
 * Halfword lookup keyed by one of the two id windows func_02021288 accepts:
 * 0x148..0x1A9 maps to entries 0..0x61 of the table at 0x0209EAA0 and
 * 0x26A..0x26C continues at 0x62..0x64, which is why the second window's
 * subtrahend is 0x208 rather than its own start.  Ids outside both windows
 * answer 0.
 *
 * The two subtrahends are one constant: the compiler keeps 0x26A in r0 for the
 * window test and derives 0x208 from it with `subs r0, #0x62` rather than
 * spending a second pool word.
 *
 * The id parameter is `u16` and the subtraction is written back into it, not
 * into a fresh local.  That is what puts the index in r4, the parameter's own
 * callee-saved home, and leaves r0 free for the table base: with a separate
 * `u16 i` local the narrowed index is a dead temporary, lands in r0, and the
 * last three instructions come out in the other order, five bytes wrong.  A
 * `u32` parameter with an explicit `(u16)` cast is the same five bytes wrong,
 * so the `u16` parameter type is real evidence and not a spelling choice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212B0.c \
 *       --func func_020212B0 --addr 0x020212B0 --cc 1.1p1 --thumb
 */
u16 func_020212B0(u16 id)
{
    if (func_02021288(id) == 0) {
        return 0;
    }
    if (id >= 0x26A) {
        id -= 0x208;
    } else {
        id -= 0x148;
    }
    return g_0209EAA0[id];
}



/*
 * Linear search of the six-entry tail of the same halfword table
 * func_020212B0 indexes, entries 0x5C..0x61.  The 0xB8 byte offset is kept out
 * of the `ldrh` encoding because it is past the halfword load's +62 reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md), so the address comes
 * out as base, plus the scaled index, plus a separate `adds r1, #0xb8`.
 *
 * The counter is a `u8`: the increment is `adds`/`lsls #0x18`/`lsrs #0x18`
 * through a scratch register, which a `u32` counter does not produce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212E4.c \
 *       --func func_020212E4 --addr 0x020212E4 --cc 1.1p1 --thumb
 */
u32 func_020212E4(u16 v)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209EAA0[0x5C + i]) {
            return 1;
        }
    }
    return 0;
}



/*
 * Maps an id in one of func_02021288's two accepted windows onto a byte-wide
 * slot number, in three ranges with three different subtrahends: 0x26A.. off
 * 0x20E, 0x1A4..0x269 off 0x145, and the rest off 0x148.  Ids the window test
 * rejects answer 0xFF.
 *
 * Only two pool words: 0x26A is loaded once and 0x1A4 derived from it with
 * `subs r0, #0xc6`, the same constant-sharing func_020212B0 does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202130C.c \
 *       --func func_0202130C --addr 0x0202130C --cc 1.1p1 --thumb
 */
u32 func_0202130C(u32 id)
{
    if (func_02021288(id) == 0) {
        return 0xFF;
    }
    if (id >= 0x26A) {
        return (u8)(id - 0x20E);
    }
    if (id >= 0x1A4) {
        return (u8)(id - 0x145);
    }
    return (u8)(id - 0x148);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021350.c  *       --func func_02021350 --addr 0x02021350 --cc 1.1p1 --thumb
 */
u8 func_02021350(u16 id)
{
    if (id >= 0x1A4 && id <= 0x1A9) {
        return (u8)(id - 0x1A4);
    }
    return 0xFF;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202136C.c  *       --func func_0202136C --addr 0x0202136C --cc 1.1p1 --thumb
 */
u32 func_0202136C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return 1;
        }
    }
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202138C.c  *       --func func_0202138C --addr 0x0202138C --cc 1.1p1 --thumb
 */
u8 func_0202138C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return (u8)i;
        }
    }
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213AC.c  *       --func func_020213AC --addr 0x020213AC --cc 1.1p1 --thumb
 */
u16 func_020213AC(u32 i)
{
    if (i >= 0xC) {
        return 0;
    }
    return g_0209E8EC[i];
}

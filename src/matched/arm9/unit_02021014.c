/*
 * A whole translation unit range, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02021014
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_Get_1014, FILE_UTIL_GetMonProp
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by FILE_UTIL_Get_1014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to FILE_UTIL_GetMonProp on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because FILE_UTIL_Get_1014's call to
 * FILE_UTIL_GetMonProp is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - FILE_UTIL_Get_1014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: FILE_UTIL_GetMonProp takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring FILE_UTIL_GetMonProp as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  FILE_UTIL_GetMonProp's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of FILE_UTIL_Get_1014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of FILE_UTIL_GetMonProp are the signedness evidence
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

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

int FILE_UTIL_GetMonProp(struct Sub *q, u32 sel);

u32 FILE_UTIL_Get_1014(struct Rec *p, u32 sel)
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
        return FILE_UTIL_GetMonProp((struct Sub *)&p->f10, sel);
    }
    return 0;
}

int FILE_UTIL_GetMonProp(struct Sub *q, u32 sel)
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

/*
 * function: func_02018E34
 * address:  0x02018E34
 * region:   arm9
 * packet:   pkt_02018DB4
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 1236 bytes, one function, a 176 case jump table.  The read accessor over
 * the encrypted block area of the 0xDC byte record, and the larger half of
 * poke_tool.c's get/set dispatcher quartet.  func_02018DB4
 * (src/matched/sub_02018DB4.c) owns ids 0x9D to 0xA8 and forwards everything
 * else here; the writer twin is func_02019388 (src/matched/sub_02019388.c).
 *
 * Of the eighteen relocation sites, three are calls to 0x0209C074 (_ll_shl,
 * the compiler's own 64 bit shift helper) and one is to func_02019BBC; a scan
 * of every Thumb BL and BLX in the image finds those four sites and no
 * others, all four inside this one function, so neither the `label` nor
 * `matched` class alone ever had an outside witness for both.  func_02019BBC
 * resolves via the `matched` class (src/matched/unit_02019B58.c, an EXACT
 * entry proved over a range this file does not touch); 0x0209C074 resolves
 * via the `runtime` class, layout/runtime_arm9.txt's curated identification
 * of the MSL/runtime.a routines mwccarm links in, which carries the same
 * evidentiary standing as an SDK symbol without needing a label or an
 * outside call.  See docs/AGENT-BRIEF.md's attestation section.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP
 * ---------------------------------------------------------------------------
 * func_02019C38(p, p->unk00, n) returns the n-th of four 0x20 byte substructs
 * inside the 0x80 byte block area at +0x08, permuted by the seed word; so the
 * four pointers a, b, c, d below are the substructs and every id is one field
 * of one of them.  Ids not listed fall to `default` and read back 0.
 *
 *   id         where                       what the code does
 *   0x00       record +0x00 u32            the seed word
 *   0x01/02/03 record +0x04 bits 0/1/2     the three lock flags
 *   0x04       record +0x06 u16            the block-area checksum
 *   0x05       A +0x00 u16                 species; 650 when flag bit 2 is set
 *   0x06       A +0x02 u16                 held item; 0 when above 626
 *   0x07       A +0x04 u32
 *   0x08       A +0x08 u32                 experience
 *   0x09       A +0x0C u8
 *   0x0A       A +0x0D u8                  ability (see 0xAE below)
 *   0x0B       A +0x0E u8
 *   0x0C       A +0x0F u8
 *   0x0D..0x12 A +0x10..0x15 u8 x6         the six the setter caps at 510 total
 *   0x13..0x18 A +0x16..0x1B u8 x6
 *   0x19..0x35 A +0x1C u32                 29 flag bits, bit (id - 0x19)
 *   0x36..0x39 B +0x00 u16[4]
 *   0x3A..0x3D B +0x08 u8[4]
 *   0x3E..0x41 B +0x0C u8[4]
 *   0x42..0x45 derived                     func_0201C158(B move[i], B +0x0C[i])
 *                                          when the move is non zero, else 0
 *   0x46..0x4B B +0x10 bits 0..29          six 5 bit fields
 *   0x4C       B +0x10 bit 30              1 when flag bit 2 is set
 *   0x4D..0x6C B +0x14 u32                 32 flag bits, bit (id - 0x4D)
 *   0x6D       B +0x18 bit 0
 *   0x6E       derived, and it WRITES      func_02017F50(species, form, seed),
 *                                          stored into B +0x18 bits 1..2, then
 *                                          the block-area checksum is recomputed
 *   0x6F       B +0x18 bits 3..7           form
 *   0x70       B +0x19 u8
 *   0x71       B +0x1A bit 0
 *   0x72       B +0x1C u32
 *   0x73       C +0x00                     copied out through the third
 *                                          argument, or the id 651 string from
 *                                          the bank at 0x020A7370 when flag
 *                                          bit 2 is set
 *   0x74       C +0x00                     the same, length 11
 *   0x75       B +0x10 bit 31
 *   0x76       C +0x16 u8
 *   0x77       C +0x17 u8
 *   0x78..0x8C C +0x18 u64                 21 flag bits, bit (id - 0x78)
 *   0x8D/0x8E  D +0x00                     copied out, length 8 for 0x8E
 *   0x8F..0x94 D +0x10..0x15 u8 x6
 *   0x95       D +0x16 u16
 *   0x96       D +0x18 u16
 *   0x97       D +0x1A u8
 *   0x98       D +0x1B u8
 *   0x99       D +0x1C bits 0..6
 *   0x9A       D +0x1C bit 7
 *   0x9B       D +0x1D u8
 *   0x9C       D +0x1E u16
 *   0x9E       derived                     func_0201850C(species, form, exp)
 *   0x9D, 0x9F..0xA8                       gaps here; the party area, owned by
 *                                          func_02018DB4
 *   0xA9       derived                     species != 0
 *   0xAA       derived                     flag bit 2, else B +0x10 bit 30
 *   0xAB       derived                     species, or 650 when it is an egg
 *                                          or flag bit 2 is set
 *   0xAC       derived                     B +0x10 bits 0..29 repacked
 *   0xAD       derived                     0 for species 29 or 32 with
 *                                          B +0x10 bit 31 clear, else 1
 *   0xAE/0xAF  derived                     func_02019BBC(item) for species 493
 *                                          with A +0x0D == 121, otherwise
 *                                          func_02019C90(species, form,
 *                                          id - 0xA8)
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Six numeric constants in this function are content ids rather than structure
 * offsets, and they are the only things here that could differ between the two
 * paired versions: 650 (ids 0x05 and 0xAB), 651 (the string id for ids 0x73
 * and 0x74), 626 (the item ceiling for id 0x06), 493 and 121 (the species and
 * ability that select the item-derived type at ids 0xAE and 0xAF) and 29 and
 * 32 (the two species id 0xAD special cases).  There is no
 * version-exclusive-species table and no version flag anywhere in this
 * function; Black and White share their species, item and ability numbering,
 * so all six are expected to be identical in IRAO, but they are the addresses
 * to re-read first if a White build diverges here.  The message bank pointer
 * at 0x020A7370 is a global, so its address will differ between builds and
 * must be re-derived rather than copied.
 *
 * ---------------------------------------------------------------------------
 * WHAT PINNED THE SOURCE
 * ---------------------------------------------------------------------------
 * The 176 entry halfword table is read as
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md: the entries
 * that point at the default body are the ids with no case label, and the
 * addresses the other entries point at, sorted, are the source order of the
 * arms.  That order is not the numeric order and reconstructing it is most of
 * the work: the switch opens with `default`, then 0x00 to 0x04, then 0xA9,
 * 0xAA, 0xAB and 0x9E, and only then 0x05 onwards, with 0x75 sitting between
 * 0x4C and the 0x4D group.  Writing the arms in numeric order instead is a
 * whole-function diff with the size still exactly right.
 *
 * Three further details each cost bytes:
 *
 *   * `u32 r = 0;` has to be declared before the four substruct calls and
 *     `u32 ok = 1;` after them.  The original's `movs r4, #0` sits in front of
 *     the first call and its `str r2, [sp, #8]` just after it, and the two
 *     stack slots are assigned in that declaration order, which is
 *     docs/idioms/local-declaration-order-is-stack-order.md.
 *   * `default:` has to be the first arm written, not a statement after the
 *     switch.  Written after the switch its block lands at the end and all 176
 *     displacements move.
 *   * ids 0x4C and 0xAA are the same two-line test and both have to be written
 *     `r = p->b2; if (r == 0) { r = b->iv6; }`, so that the flag bit lands
 *     directly in the result register.  Written as
 *     `if (p->b2 != 0) { r = 1; } else { r = b->iv6; }` the compiler computes
 *     the bit into a scratch register and 0x4C loses the two byte `b` to the
 *     shared exit that id 0x42's `beq` needs to reach, which turns that `beq`
 *     into a `bne` plus a long `b` and shifts everything after it by two.
 *
 * The three 64 bit flag-bit tests are one shape: `((u64)ok << n) & field`,
 * with the field zero extended, compared against zero in 64 bits.  The u64 is
 * what calls 0x0209C074 (_ll_shl).
 *
 * Verified with
 *   python tools/match.py one --src src/pending/sub_02018E34.c \
 *       --func func_02018E34 --addr 0x02018E34 --cc 1.1p1
 *
 * symbols:
 *   _ll_shl        0x0209C074  arm
 *   gMsgBank       0x020A7370  data
 *   func_02019BBC  0x02019BBC  thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct Mon {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
};

struct BlockA {
    u16 species;
    u16 item;
    u32 otId;
    u32 exp;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
    u8  unk10[6];
    u8  unk16[6];
    u32 unk1C;
};

struct BlockB {
    u16 moves[4];
    u8  pp[4];
    u8  ppUp[4];
    u32 iv0 : 5;
    u32 iv1 : 5;
    u32 iv2 : 5;
    u32 iv3 : 5;
    u32 iv4 : 5;
    u32 iv5 : 5;
    u32 iv6 : 1;
    u32 iv7 : 1;
    u32 unk14;
    u8  f0 : 1;
    u8  f1 : 2;
    u8  f2 : 5;
    u8  unk19;
    u16 g0 : 1;
    u16 g1 : 15;
    u32 unk1C;
};

struct BlockC {
    u16 unk00[11];
    u8  unk16;
    u8  unk17;
    u64 unk18;
};

struct BlockD {
    u16 unk00[8];
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u16 unk16;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u8  h0 : 7;
    u8  h1 : 1;
    u8  unk1D;
    u16 unk1E;
};

extern void *func_02019C38(struct Mon *p, u32 pid, u32 n);
extern u16  func_02019A9C(const void *p, u32 size);
struct MsgBank;
struct MsgData;
struct Strbuf;
extern u32 func_0201850C(u16 species, u16 form, u32 exp);
extern u8   func_02017F50(u32 species, u16 form, u32 pid);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern u32 func_02019BBC(u32 item);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);

extern void *gMsgBank;

u32 func_02018E34(struct Mon *p, u32 id, u32 v)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38(p, p->unk00, 0);
    struct BlockB *b = (struct BlockB *)func_02019C38(p, p->unk00, 1);
    struct BlockC *c = (struct BlockC *)func_02019C38(p, p->unk00, 2);
    struct BlockD *d = (struct BlockD *)func_02019C38(p, p->unk00, 3);
    u32 ok = 1;

    switch (id) {
    default:
        r = 0;
        break;
    case 0x00: r = p->unk00; break;
    case 0x01: r = p->b0; break;
    case 0x02: r = p->b1; break;
    case 0x03: r = p->b2; break;
    case 0x04: r = p->unk06; break;
    case 0xA9:
        if (a->species == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0xAA:
        r = p->b2;
        if (r == 0) {
            r = b->iv6;
        }
        break;
    case 0xAB:
        r = a->species;
        if (r != 0) {
            if (b->iv6 != 0 || p->b2 != 0) {
                r = 650;
            }
        }
        break;
    case 0x9E:
        r = func_0201850C(a->species, b->f2, a->exp);
        break;
    case 0x05:
        if (p->b2 != 0) {
            r = 650;
        } else {
            r = a->species;
        }
        break;
    case 0x06:
        r = a->item;
        if (r > 626) {
            r = 0;
        }
        break;
    case 0x07: r = a->otId; break;
    case 0x08: r = a->exp; break;
    case 0x09: r = a->unk0C; break;
    case 0x0A: r = a->unk0D; break;
    case 0x0B: r = a->unk0E; break;
    case 0x0C: r = a->unk0F; break;
    case 0x0D: r = a->unk10[0]; break;
    case 0x0E: r = a->unk10[1]; break;
    case 0x0F: r = a->unk10[2]; break;
    case 0x10: r = a->unk10[3]; break;
    case 0x11: r = a->unk10[4]; break;
    case 0x12: r = a->unk10[5]; break;
    case 0x13: r = a->unk16[0]; break;
    case 0x14: r = a->unk16[1]; break;
    case 0x15: r = a->unk16[2]; break;
    case 0x16: r = a->unk16[3]; break;
    case 0x17: r = a->unk16[4]; break;
    case 0x18: r = a->unk16[5]; break;
    case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
    case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A:
    case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30:
    case 0x31: case 0x32: case 0x33: case 0x34: case 0x35:
        id -= 0x19;
        if ((((u64)ok << id) & a->unk1C) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x36: case 0x37: case 0x38: case 0x39:
        id -= 0x36;
        r = b->moves[id];
        break;
    case 0x3A: case 0x3B: case 0x3C: case 0x3D:
        id -= 0x3A;
        r = b->pp[id];
        break;
    case 0x3E: case 0x3F: case 0x40: case 0x41:
        id -= 0x3E;
        r = b->ppUp[id];
        break;
    case 0x42: case 0x43: case 0x44: case 0x45:
        id -= 0x42;
        if (b->moves[id] != 0) {
            r = func_0201C158(b->moves[id], b->ppUp[id]);
        }
        break;
    case 0x46: r = b->iv0; break;
    case 0x47: r = b->iv1; break;
    case 0x48: r = b->iv2; break;
    case 0x49: r = b->iv3; break;
    case 0x4A: r = b->iv4; break;
    case 0x4B: r = b->iv5; break;
    case 0x4C:
        r = p->b2;
        if (r == 0) {
            r = b->iv6;
        }
        break;
    case 0x75: r = b->iv7; break;
    case 0x4D: case 0x4E: case 0x4F: case 0x50: case 0x51: case 0x52:
    case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
    case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E:
    case 0x5F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C:
        id -= 0x4D;
        if ((((u64)ok << id) & b->unk14) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x6D: r = b->f0; break;
    case 0x6E:
        r = func_02017F50(a->species, b->f2, p->unk00);
        b->f1 = (u8)r;
        p->unk06 = func_02019A9C(p->unk08, 0x80);
        break;
    case 0x6F: r = b->f2; break;
    case 0x70: r = b->unk19; break;
    case 0x71: r = b->g0; break;
    case 0x72: r = b->unk1C; break;
    case 0x73:
        if (p->b2 != 0) {
            func_02045CAC(gMsgBank, 651, (void *)v);
        } else {
            func_02045924((void *)v, c->unk00);
        }
        break;
    case 0x74:
        if (p->b2 != 0) {
            func_02045F5C(gMsgBank, 651, (void *)v, 11);
        } else {
            func_0201F41C(c->unk00, (void *)v, 11);
        }
        break;
    case 0x76: r = c->unk16; break;
    case 0x77: r = c->unk17; break;
    case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D:
    case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82: case 0x83:
    case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89:
    case 0x8A: case 0x8B: case 0x8C:
        id -= 0x78;
        if ((((u64)ok << id) & c->unk18) == 0) {
            ok = 0;
        }
        r = ok;
        break;
    case 0x8D:
        func_02045924((void *)v, d->unk00);
        break;
    case 0x8E:
        func_0201F41C(d->unk00, (void *)v, 8);
        break;
    case 0x8F: r = d->unk10; break;
    case 0x90: r = d->unk11; break;
    case 0x91: r = d->unk12; break;
    case 0x92: r = d->unk13; break;
    case 0x93: r = d->unk14; break;
    case 0x94: r = d->unk15; break;
    case 0x95: r = d->unk16; break;
    case 0x96: r = d->unk18; break;
    case 0x97: r = d->unk1A; break;
    case 0x98: r = d->unk1B; break;
    case 0x99: r = d->h0; break;
    case 0x9A: r = d->h1; break;
    case 0x9B: r = d->unk1D; break;
    case 0x9C: r = d->unk1E; break;
    case 0xAC:
        r = b->iv0 | (b->iv1 << 5) | (b->iv2 << 10) | (b->iv3 << 15)
            | (b->iv4 << 20) | (b->iv5 << 25);
        break;
    case 0xAD:
        if ((a->species == 29 || a->species == 32) && b->iv7 == 0) {
            r = 0;
        } else {
            r = 1;
        }
        break;
    case 0xAE:
    case 0xAF:
        if (a->species == 493 && a->unk0D == 121) {
            r = func_02019BBC(a->item);
        } else {
            id -= 0xA8;
            r = func_02019C90(a->species, b->f2, id);
        }
        break;
    }
    return r;
}

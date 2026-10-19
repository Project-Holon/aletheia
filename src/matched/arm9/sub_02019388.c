/*
 * function: POKE_TOOL_SetBoxValueRaw
 * address:  0x02019388
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 1736 bytes, one function, 178 case jump table.
 *
 * The write accessor over the encrypted block area of the 0xDC byte record,
 * and the largest of poke_tool.c's get/set dispatcher quartet.  POKE_TOOL_SetPartyValueRaw
 * (src/matched/POKE_TOOL_SetPartyValueRaw.c) owns the party-area ids 0x9D to 0xA8 and
 * forwards everything else here; the reader twin is POKE_TOOL_GetBoxValueRaw
 * (src/pending/POKE_TOOL_GetBoxValueRaw.c), whose header carries the full field map.  The
 * two dispatchers agree field for field, so only what is specific to writing
 * is repeated below.
 *
 * What held it open, and what closed it: two of the thirteen relocation sites
 * call POKE_TOOL_HasNickname, both from inside this function, and a scan of every
 * Thumb BL and BLX in the image finds no third site.  The `label` class
 * therefore has no witness and no cut helps, because the range cannot be made
 * smaller than the one function that holds both calls.  The `matched` class
 * carries both: 0x02019ABC is src/matched/unit_02019ABC.c, an EXACT entry
 * proved against the original bytes over a range this file does not touch.
 *
 * ---------------------------------------------------------------------------
 * WHAT THE WRITER ADDS OVER THE READER
 * ---------------------------------------------------------------------------
 * Two ids exist here that the reader does not have, 0xB0 and 0xB1, and they
 * sit in the source between 0x74 and 0x76.  They are 0x73 and 0x74 without the
 * trailing recomputation, so the pairs read: 0x73 copies 11 halfwords into
 * substruct C and then sets C's "renamed" bit from POKE_TOOL_HasNickname, 0xB0 copies
 * the same 11 halfwords and leaves the bit alone; 0x74 and 0xB1 are the same
 * pair through the other copier.
 *
 * Nine ids the reader answers are absent here and fall to `default`, which
 * writes nothing: 0x42 to 0x45 (derived from a move and its use count), 0x75,
 * 0x9D to 0xAB (the party area plus the derived species, egg and level
 * queries) and 0xAD to 0xAF (the derived nickname and type queries).
 *
 * Ids 0x0D to 0x12, the six bytes at A +0x10, are the only arms with real
 * logic: each sums all six, clamps the increment so that the total cannot pass
 * 510, and then clamps the single value to 255.  The comparison is signed
 * (`ble`) while the values are unsigned bytes, so the clamp has to be written
 * through an explicit signed cast or the compiler emits `bls` and the arm is
 * a byte short.
 *
 * Id 0x06 refuses any value above 626 by branching into the `default` body,
 * which is why the writer's `default` is the last arm and the reader's is the
 * first: here it is a shared do-nothing exit that two arms jump to.
 *
 * ---------------------------------------------------------------------------
 * THE TWO THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **One u64 mask serves all three flag-bit groups, and its complement is
 * written `mask ^ -1`, not `~mask`.**  Ids 0x19..0x35, 0x4D..0x6C and
 * 0x78..0x8C are all `mask = 1 << n; if (v) field |= mask; else field &=
 * complement;`, with `mask` a single function-scope `u64`.  The 64 bit type is
 * what makes the two u32 fields behave the way the original does: the shift
 * stays a plain `lsls` because only the low half is ever used, while the
 * complement is emitted as the low half of a 64 bit NOT, which mwccarm builds
 * as `movs r1, #3` / `subs r1, r1, #4` / `eors` rather than as `mvns`.
 * Spelling it `~mask` gives `mvns` and 904 wrong bytes; spelling it
 * `mask ^ 0xFFFFFFFF` gives the right size but 346 wrong bytes, because the
 * constant then fits one word and the 21 bit group at C +0x18 loses its
 * second `eors`.  Declaring `mask` u32, or one mask per group, also sinks the
 * shift into both arms of the test and costs a further eight bytes.
 * Getting this wrong is also what decides the register allocation: with three
 * separate 32 bit masks the record pointer loses r7 to the id and is reloaded
 * from the frame before each of the four substruct calls.
 *
 * **Id 0xAC writes the six 5 bit fields in the order 0, 1, 2, 4, 5, 3, and the
 * value it takes them from is permuted.**  The masks the original ANDs in are,
 * in order, 0xFFFFFC1F, 0xFFFF83FF, 0xFE0FFFFF, 0xC1FFFFFF and one derived
 * from the last by `asrs #0xa`, which is 0xFFF07FFF: that is bits 5, 10, 20,
 * 25 and 15, in that order.  Matching them against the shift amounts gives
 * field[4] = (v >> 15) & 0x1F, field[5] = (v >> 20) & 0x1F and
 * field[3] = (v >> 25) & 0x1F, so the packed argument orders the last three
 * fields differently from the structure.  The reader's 0xAC is a plain
 * identity repack of the same word, so the asymmetry is real and is in the
 * game, not in this reconstruction; writing 0xAC as an identity here is 89
 * wrong bytes and four bytes long, because the derived mask becomes a fifth
 * pool word.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Only one content id appears here, 626, the item ceiling at id 0x06, and it
 * is the same constant the reader uses.  There is no version-exclusive-species
 * table, no version flag and no message bank in this function; everything else
 * is a structure offset or a field width.  Black and White share their item
 * numbering, so 626 is expected to be identical in IRAO, but it is the one
 * number to re-read.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_SetBoxValueRaw.c \
 *       --func POKE_TOOL_SetBoxValueRaw --addr 0x02019388 --cc 1.1p1
 *
 * symbols:
 *   STRBUF_ToChars  0x02045A38  arm
 *   POKE_TOOL_CalcGender  0x02017F50  thumb
 *   POKE_TOOL_HasNickname  0x02019ABC  thumb
 *   POKE_TOOL_GetBoxSubstruct  0x02019C38  thumb
 *   WORDSET_CopyString  0x0201F41C  thumb
 */
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed int         s32;
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

extern void *POKE_TOOL_GetBoxSubstruct(struct Mon *p, u32 pid, u32 n);
extern u8   POKE_TOOL_CalcGender(u32 species, u16 form, u32 pid);
extern u32  POKE_TOOL_HasNickname(struct Mon *p);
extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *src, u16 *dest, u32 n);

void POKE_TOOL_SetBoxValueRaw(struct Mon *p, u32 id, u32 v)
{
    struct BlockA *a = (struct BlockA *)POKE_TOOL_GetBoxSubstruct(p, p->unk00, 0);
    struct BlockB *b = (struct BlockB *)POKE_TOOL_GetBoxSubstruct(p, p->unk00, 1);
    struct BlockC *c = (struct BlockC *)POKE_TOOL_GetBoxSubstruct(p, p->unk00, 2);
    struct BlockD *d = (struct BlockD *)POKE_TOOL_GetBoxSubstruct(p, p->unk00, 3);
    u32 sum;
    u64 mask;

    switch (id) {
    case 0x00: p->unk00 = v; break;
    case 0x01: p->b0 = (u16)v; break;
    case 0x02: p->b1 = (u16)v; break;
    case 0x03: p->b2 = (u16)v; break;
    case 0x04: p->unk06 = (u16)v; break;
    case 0x05: a->species = (u16)v; break;
    case 0x06:
        if (v > 626) {
            break;
        }
        a->item = (u16)v;
        break;
    case 0x07: a->otId = v; break;
    case 0x08: a->exp = v; break;
    case 0x09: a->unk0C = (u8)v; break;
    case 0x0A: a->unk0D = (u8)v; break;
    case 0x0B: a->unk0E = (u8)v; break;
    case 0x0C: a->unk0F = (u8)v; break;
    case 0x0D:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[0]) > (s32)(510 - sum)) {
            v = a->unk10[0] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[0] = (u8)v;
        break;
    case 0x0E:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[1]) > (s32)(510 - sum)) {
            v = a->unk10[1] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[1] = (u8)v;
        break;
    case 0x0F:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[2]) > (s32)(510 - sum)) {
            v = a->unk10[2] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[2] = (u8)v;
        break;
    case 0x10:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[3]) > (s32)(510 - sum)) {
            v = a->unk10[3] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[3] = (u8)v;
        break;
    case 0x11:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[4]) > (s32)(510 - sum)) {
            v = a->unk10[4] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[4] = (u8)v;
        break;
    case 0x12:
        sum = a->unk10[0] + a->unk10[1] + a->unk10[2] + a->unk10[3]
            + a->unk10[4] + a->unk10[5];
        if ((s32)(v - a->unk10[5]) > (s32)(510 - sum)) {
            v = a->unk10[5] + (510 - sum);
        }
        if (v > 255) {
            v = 255;
        }
        a->unk10[5] = (u8)v;
        break;
    case 0x13: a->unk16[0] = (u8)v; break;
    case 0x14: a->unk16[1] = (u8)v; break;
    case 0x15: a->unk16[2] = (u8)v; break;
    case 0x16: a->unk16[3] = (u8)v; break;
    case 0x17: a->unk16[4] = (u8)v; break;
    case 0x18: a->unk16[5] = (u8)v; break;
    case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
    case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A:
    case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30:
    case 0x31: case 0x32: case 0x33: case 0x34: case 0x35:
        id -= 0x19;
        mask = 1 << id;
        if (v != 0) {
            a->unk1C |= mask;
        } else {
            a->unk1C &= (mask ^ -1);
        }
        break;
    case 0x36: case 0x37: case 0x38: case 0x39:
        id -= 0x36;
        b->moves[id] = (u16)v;
        break;
    case 0x3A: case 0x3B: case 0x3C: case 0x3D:
        id -= 0x3A;
        b->pp[id] = (u8)v;
        break;
    case 0x3E: case 0x3F: case 0x40: case 0x41:
        id -= 0x3E;
        b->ppUp[id] = (u8)v;
        break;
    case 0x46: b->iv0 = v; break;
    case 0x47: b->iv1 = v; break;
    case 0x48: b->iv2 = v; break;
    case 0x49: b->iv3 = v; break;
    case 0x4A: b->iv4 = v; break;
    case 0x4B: b->iv5 = v; break;
    case 0x4C: b->iv6 = v; break;
    case 0x4D: case 0x4E: case 0x4F: case 0x50: case 0x51: case 0x52:
    case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
    case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E:
    case 0x5F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C:
        id -= 0x4D;
        mask = 1 << id;
        if (v != 0) {
            b->unk14 |= mask;
        } else {
            b->unk14 &= (mask ^ -1);
        }
        break;
    case 0x6D: b->f0 = (u8)v; break;
    case 0x6E:
        b->f1 = POKE_TOOL_CalcGender(a->species, b->f2, p->unk00);
        break;
    case 0x6F: b->f2 = (u8)v; break;
    case 0x70: b->unk19 = (u8)v; break;
    case 0x71: b->g0 = (u16)v; break;
    case 0x72: b->unk1C = v; break;
    case 0x73:
        STRBUF_ToChars((struct U16Vec *)v, c->unk00, 11);
        b->iv7 = POKE_TOOL_HasNickname(p);
        break;
    case 0x74:
        WORDSET_CopyString((const void *)v, c->unk00, 11);
        b->iv7 = POKE_TOOL_HasNickname(p);
        break;
    case 0xB0:
        STRBUF_ToChars((struct U16Vec *)v, c->unk00, 11);
        break;
    case 0xB1:
        WORDSET_CopyString((const void *)v, c->unk00, 11);
        break;
    case 0x76: c->unk16 = (u8)v; break;
    case 0x77: c->unk17 = (u8)v; break;
    case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D:
    case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82: case 0x83:
    case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89:
    case 0x8A: case 0x8B: case 0x8C:
        id -= 0x78;
        mask = 1 << id;
        if (v != 0) {
            c->unk18 |= mask;
        } else {
            c->unk18 &= (mask ^ -1);
        }
        break;
    case 0x8D:
        STRBUF_ToChars((struct U16Vec *)v, d->unk00, 8);
        break;
    case 0x8E:
        WORDSET_CopyString((const void *)v, d->unk00, 8);
        break;
    case 0x8F: d->unk10 = (u8)v; break;
    case 0x90: d->unk11 = (u8)v; break;
    case 0x91: d->unk12 = (u8)v; break;
    case 0x92: d->unk13 = (u8)v; break;
    case 0x93: d->unk14 = (u8)v; break;
    case 0x94: d->unk15 = (u8)v; break;
    case 0x95: d->unk16 = (u16)v; break;
    case 0x96: d->unk18 = (u16)v; break;
    case 0x97: d->unk1A = (u8)v; break;
    case 0x98: d->unk1B = (u8)v; break;
    case 0x99: d->h0 = (u8)v; break;
    case 0x9A: d->h1 = (u8)v; break;
    case 0x9B: d->unk1D = (u8)v; break;
    case 0x9C: d->unk1E = (u16)v; break;
    case 0xAC:
        b->iv0 = (u8)(v & 0x1F);
        b->iv1 = (u8)((v >> 5) & 0x1F);
        b->iv2 = (u8)((v >> 10) & 0x1F);
        b->iv4 = (u8)((v >> 15) & 0x1F);
        b->iv5 = (u8)((v >> 20) & 0x1F);
        b->iv3 = (u8)((v >> 25) & 0x1F);
        break;
    default:
        break;
    }
}

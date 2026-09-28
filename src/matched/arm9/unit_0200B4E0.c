/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B4E0
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B4E0, func_0200B570, func_0200B5A4
 *
 * 236 bytes, 0x0200B4E0..0x0200B5CC, 3 functions, all three of which carry a
 * label in the generated listing.
 *
 * alias: inside "battle_rec.c"; see src/matched/unit_0200B394.c for how the
 * name at 0x020A71C4 is attested and src/matched/unit_0200B448.c for the
 * 0x18A4-byte record these work on.
 *
 * func_0200B4E0 loads a saved battle record and classifies the result into
 * the caller's status word: 0 when the block is absent, 3 when the load
 * failed, 0 again when the record's own check rejects it, 2 when the second
 * check does, and 1 when it is good.  Every arm writes the status and returns
 * 1, and the last arm shares its `movs r0, #1` between the store and the
 * return, which is the compiler reusing one constant and not two statements.
 *
 * The address of the checksummed sub-record is a named local, not
 * `&b->unkC4` written out at each of the three uses: with the local the base
 * is formed once as `adds r0, #0xc4` and the field offset 0x17DC is the
 * register operand, and written inline the compiler folds 0xC4 + 0x17DC into
 * one pool word of 0x18A0 and then subtracts 0xC4 back off it, which is two
 * instructions more.
 *
 * This range stops at 0x0200B5CC and src/matched/unit_0200B5CC.c starts
 * there, because func_0200B888 and func_0200B8AC are each called exactly
 * twice in the image, once from func_0200B4E0 and once from func_0200B5CC;
 * one range holding both pairs has no witness left for either and caps at
 * MATCH with every byte right.  Cut between them, each file is the other's
 * witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md. *
 * symbols:
 *   gObj_0214616C  0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RecC4 {
    u8  unk0000[0x17DC];
    u16 unk17DC;
    u8  unk17DE[2];
};

struct BattleRec {
    u8  unk00[0x80];
    u8  unk80[0x44];
    struct RecC4 unkC4;
};

extern u32  func_020072CC(void *save, u32 id, u32 heap, void *buf, u32 size);
extern void func_020072A4(void *save, u32 id);
extern void func_0200B900(void *a, u32 b, u32 c);
extern u32  func_0200725C(void *save, u32 id, u32 heap);
extern struct BattleRec *func_020073D8(void *save, u32 id, u32 c);
extern u32  func_0200B888(void *a, void *b);
extern u32  func_0200B8AC(void *a, void *b);
extern void func_0200B448(struct BattleRec *p);
extern void func_0200B400(u32 heap);
extern struct BattleRec *func_0200B3DC(u32 heap);
extern struct BattleRec *gObj_0214616C;

u32 func_0200B4E0(void *a, struct BattleRec *b, u32 heap, u32 *d, u32 id)
{
    struct RecC4 *r;
    u16 v;

    *d = func_020072CC(a, id, heap, b, 0x2000);
    func_020072A4(a, id);
    if (*d == 0) {
        *d = 0;
        return 1;
    }
    if (*d != 1) {
        *d = 3;
        return 1;
    }
    r = &b->unkC4;
    v = r->unk17DC;
    func_0200B900(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (func_0200B888(a, b) == 1) {
        *d = 0;
        return 1;
    }
    if (func_0200B8AC(a, b) == 0) {
        *d = 2;
        return 1;
    }
    *d = 1;
    return 1;
}

u32 func_0200B570(void *a, u32 heap, u32 *dp, u32 id)
{
    if (gObj_0214616C != 0) {
        func_0200B448(gObj_0214616C);
    } else {
        func_0200B400(heap);
    }
    return func_0200B4E0(a, gObj_0214616C, heap, dp, id);
}

struct BattleRec *func_0200B5A4(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p = func_0200B3DC(heap);

    func_0200B4E0(a, p, heap, dp, id);
    return p;
}


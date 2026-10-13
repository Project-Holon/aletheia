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
 * function: BATTLE_REC_LoadToWork, BATTLE_REC_Load, BATTLE_REC_LoadAlloc
 *
 * 236 bytes, 0x0200B4E0..0x0200B5CC, 3 functions, all three of which carry a
 * label in the generated listing.
 *
 * alias: inside "battle_rec.c"; see src/matched/unit_0200B394.c for how the
 * name at 0x020A71C4 is attested and src/matched/unit_0200B448.c for the
 * 0x18A4-byte record these work on.
 *
 * BATTLE_REC_LoadToWork loads a saved battle record and classifies the result into
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
 * there, because BATTLE_REC_IsMagicBroken and BATTLE_REC_IsValid are each called exactly
 * twice in the image, once from BATTLE_REC_LoadToWork and once from BATTLE_REC_CheckSaved;
 * one range holding both pairs has no witness left for either and caps at
 * MATCH with every byte right.  Cut between them, each file is the other's
 * witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md. *
 * symbols:
 *   pBattleRec  0x0214616C  data
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   BATTLE_REC_Create  0x0200B3DC  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   BATTLE_REC_Clear  0x0200B448  thumb
 *   BATTLE_REC_IsMagicBroken  0x0200B888  thumb
 *   BATTLE_REC_IsValid  0x0200B8AC  thumb
 *   BATTLE_REC_Decode  0x0200B900  thumb
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
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

extern u32  SAVE_CONTROL_LoadExtraSaveWithBuffer(void *save, u32 id, u32 heap, void *buf, u32 size);
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void BATTLE_REC_Decode(void *a, u32 b, u32 c);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 BATTLE_REC_IsMagicBroken(void *a, struct BattleRec *b);
extern u32 BATTLE_REC_IsValid(void *a, struct BattleRec *b);
extern void BATTLE_REC_Clear(struct BattleRec *p);
extern void BATTLE_REC_AllocWork(u32 heap);
extern void *BATTLE_REC_Create(u32 heap);
extern struct BattleRec *pBattleRec;

u32 BATTLE_REC_LoadToWork(void *a, struct BattleRec *b, u32 heap, u32 *d, u32 id)
{
    struct RecC4 *r;
    u16 v;

    *d = SAVE_CONTROL_LoadExtraSaveWithBuffer(a, id, heap, b, 0x2000);
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
    BATTLE_REC_Decode(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(a, b) == 1) {
        *d = 0;
        return 1;
    }
    if (BATTLE_REC_IsValid(a, b) == 0) {
        *d = 2;
        return 1;
    }
    *d = 1;
    return 1;
}

u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id)
{
    if (pBattleRec != 0) {
        BATTLE_REC_Clear(pBattleRec);
    } else {
        BATTLE_REC_AllocWork(heap);
    }
    return BATTLE_REC_LoadToWork(a, pBattleRec, heap, dp, id);
}

struct BattleRec *BATTLE_REC_LoadAlloc(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p = BATTLE_REC_Create(heap);

    BATTLE_REC_LoadToWork(a, p, heap, dp, id);
    return p;
}


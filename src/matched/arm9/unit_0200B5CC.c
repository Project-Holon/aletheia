/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B5CC
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_CheckSaved
 *
 * 176 bytes, 0x0200B5CC..0x0200B67C, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  The same classification BATTLE_REC_LoadToWork does,
 * over a record the save system already holds rather than one just read, and
 * with a `func_020072A4` release on every path instead of only on entry.  See
 * src/matched/unit_0200B4E0.c for why the two are separate files. *
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

struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct Ctrl *ctrl, u32 id, u8 heap, void *buf, u32 size);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void BATTLE_REC_Decode(void *a, u32 b, u32 c);
extern u32  SAVE_CONTROL_LoadExtraSave(void *save, u32 id, u32 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 BATTLE_REC_IsMagicBroken(void *a, struct BattleRec *b);
extern u32 BATTLE_REC_IsValid(void *a, struct BattleRec *b);
extern void BATTLE_REC_Clear(struct BattleRec *p);
extern void BATTLE_REC_AllocWork(u32 heap);
extern void *BATTLE_REC_Create(u32 heap);
extern struct BattleRec *pBattleRec;

u32 BATTLE_REC_CheckSaved(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p;
    struct RecC4 *r;
    u16 v;

    *dp = SAVE_CONTROL_LoadExtraSave(a, id, heap);
    p = func_020073D8(a, id, 0);
    if (*dp == 0) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (*dp != 1) {
        *dp = 3;
        func_020072A4(a, id);
        return 0;
    }
    r = &p->unkC4;
    v = r->unk17DC;
    BATTLE_REC_Decode(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(a, p) == 1) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (BATTLE_REC_IsValid(a, p) == 0) {
        *dp = 2;
        func_020072A4(a, id);
        return 0;
    }
    *dp = 1;
    func_020072A4(a, id);
    return 1;
}

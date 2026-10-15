/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B348
 * packet:   pkt_0200ADB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_COMPETITION_Init, BATTLE_COMPETITION_GetFromSave, GIMMICK_WORK_GetSize, GIMMICK_WORK_Init
 *
 * symbols:
 *   func_0200B3DC_File  0x020A71C4  data
 *   BATTLE_REC_Clear  0x0200B448  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   GIMMICK_WORK_Reset  0x0200B37C  thumb
 *
 * 52 bytes, 0x0200B348..0x0200B37C, 4 functions, none of which carries a
 * label in the generated listing.
 *
 * GIMMICK_WORK_GetSize returns 0x94 and GIMMICK_WORK_Init clears 0x94 bytes and then
 * writes -1 into the first word, which is the "a block file opens with a
 * function returning its own size, and the constructor clears exactly that"
 * shape this range keeps producing.  The -1 is free: the compiler already
 * has 0x94 in a register for the fill and reaches -1 with `subs r4, #0x95`.
 *
 * This unit starts at 0x0200B348 rather than at the end of
 * src/matched/unit_0200ADB8.c because of a near miss between them:
 * REGULATION_BuildParty, 162 bytes, which walks a list and pushes four fields of each
 * entry into the record through REGULATION_Party_SetValue.  Every instruction is
 * reproduced and the size is right; what differs is that the original keeps
 * the constant 0 alive in r7 for the whole loop (it gets there as a copy of
 * the loop counter's initial value) and therefore rematerialises `(u8)i`
 * before each of the four calls, where this source has one register less in
 * play, common-subexpression-eliminates `(u8)i` into r5 and rematerialises
 * the 0 instead.  The two are the same eighteen instructions per iteration in
 * a different order with every register renumbered.
 *
 * This unit stops at 0x0200B37C because of a near miss there; see
 * src/matched/unit_0200B394.c for what it is.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void  MIi_CpuCopy32(void *dest, const void *src, u32 size);
struct BattleRec;
struct Struct_0200B37C;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BATTLE_REC_Clear(struct BattleRec *p);
extern const char func_0200B3DC_File[];

struct Rec2FC {
    u8 unk000[0x2FC];
};

struct Rec94 {
    s32 unk00;
    s32 unk04[32];
    u8  unk84[0x10];
};

void GIMMICK_WORK_Reset(struct Struct_0200B37C *p);

void BATTLE_COMPETITION_Init(struct Rec2FC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec2FC));
}

void *BATTLE_COMPETITION_GetFromSave(void *sys)
{
    return func_020071CC(sys, 0x2F);
}

u32 GIMMICK_WORK_GetSize(void)
{
    return sizeof(struct Rec94);
}

void GIMMICK_WORK_Init(struct Rec94 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec94));
    p->unk00 = -1;
}

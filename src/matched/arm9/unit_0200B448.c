/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B448
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_Clear, BATTLE_REC_IsDataExist, BATTLE_REC_ClearWork, BATTLE_REC_DecodeWork,
 *           BATTLE_REC_EncodeWork
 *
 * 152 bytes, 0x0200B448..0x0200B4E0, 5 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: this continues "battle_rec.c"; BATTLE_REC_Clear is the buffer clear the
 * constructor BATTLE_REC_Create calls, and the object is the 0x18A4-byte record
 * at 0x0214616C that src/matched/unit_0200B400.c allocates and
 * src/matched/unit_0200B938.c publishes.
 *
 * Two things are worth recording.
 *
 *  - BATTLE_REC_DecodeWork and BATTLE_REC_EncodeWork are the same four instructions of
 *    checksum arithmetic as BATTLE_REC_SetData, but as **tail calls**, and that
 *    changes the callee's arity.  A tail call needs r3 for the branch target,
 *    so the fourth argument BATTLE_REC_SetData passes cannot be passed here: the
 *    `ldrh r3` that loads the halfword is overwritten by the `ldr r3, [pc]`
 *    that loads BATTLE_REC_Decode's address.  The callee is therefore declared
 *    with three parameters in this file and with four in
 *    src/matched/unit_0200B900.c, and both are right, because nothing in
 *    BATTLE_REC_Decode reads its arguments.  A four-argument call here compiles
 *    to `push {r3, lr}` / `bl` / `pop` and is eight bytes longer.
 *  - the length 0x17DC is reached as `subs r1, #0xc4` off the 0x18A0 the
 *    halfword load already needed, and 0x18A0 itself is a pool word rather
 *    than a `movs`, so the file spends one pool word where BATTLE_REC_SetData
 *    spends none for the same value.  That is a consequence of the tail call
 *    having no register to spare, not of the source.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GF_STANDARD_Checksum   0x0203F2FC  arm
 *   pBattleRec   0x0214616C  data
 *   BATTLE_REC_Decode  0x0200B900  thumb
 *   BATTLE_REC_Encode  0x0200B908  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern u32 GF_STANDARD_Checksum(const u8 *p, u32 len);
extern void BATTLE_REC_Decode(void *a, u32 b, u32 c);
extern void BATTLE_REC_Encode(void *a, u32 b, u32 c);

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

extern struct BattleRec *pBattleRec;

void BATTLE_REC_Clear(struct BattleRec *p)
{
    MIi_CpuClear32(0, p, sizeof(struct BattleRec));
}

u32 BATTLE_REC_IsDataExist(void)
{
    if (GF_STANDARD_Checksum((const u8 *)(&pBattleRec->unkC4), sizeof(pBattleRec->unkC4))
        != 0) {
        return 1;
    }
    return 0;
}

void BATTLE_REC_ClearWork(void)
{
    BATTLE_REC_Clear(pBattleRec);
}

void BATTLE_REC_DecodeWork(void)
{
    u16 v = pBattleRec->unkC4.unk17DC;

    BATTLE_REC_Decode(&pBattleRec->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}

void BATTLE_REC_EncodeWork(void)
{
    u16 v = pBattleRec->unkC4.unk17DC;

    BATTLE_REC_Encode(&pBattleRec->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}

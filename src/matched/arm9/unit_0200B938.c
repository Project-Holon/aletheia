/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B938
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_SetData
 *
 * 84 bytes, 0x0200B938..0x0200B98C, one function, which carries a label in
 * the generated listing.
 *
 * The publisher of the battle record: three copies into the single object at
 * 0x0214616C and then a checksum word handed to BATTLE_REC_Decode.  The object is
 * 0x18A4 bytes, which is what BATTLE_REC_GetWorkSize in src/matched/unit_0200B400.c
 * returns, so the record is pinned from both ends: 0x80 + 0x44 + 0x17E0 is
 * exactly 0x18A4.
 *
 * The word handed over is `v + ((v ^ 0xFFFF) << 16)`, spelled with `+` and
 * not with `|`: the two halves cannot overlap and this compiler emits `adds`
 * for the one and `orrs` for the other.  The length 0x17DC is rematerialised
 * as `subs r1, r6, #4` off the 0x17E0 that is still live from the second
 * copy, which is the compiler reusing a value rather than a second constant
 * in the source.
 *
 * The range stops at 0x0200B98C because of a near miss there; see
 * src/matched/unit_0200BA38.c. *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   pBattleRec  0x0214616C  data
 *   BATTLE_REC_Decode  0x0200B900  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   BattleRecModeTable  0x0209DDCC  data
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   BATTLE_BOX_GetMon  0x0200BBEC  thumb
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;
typedef signed int     s32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Mon;
struct MsgBank;
struct MsgData;
struct Party;
struct PartyMon;
struct Rec;
struct Sav;
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);

extern void  BATTLE_REC_Decode(void *a, u32 b, u32 c);
extern void *func_020271CC(void *a, u32 id);
extern void POKE_TOOL_ClearBoxParam(struct Sav *p);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32   POKEPARTY_GetCount(void *list);
extern void *POKEPARTY_GetMember(void *list, u32 i);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern u32   POKE_TOOL_GetBoxValue(void *e, u32 a, u32 b);
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void *BATTLE_BOX_GetMon(void *a, u32 b, u32 c);

extern const u16 BattleRecModeTable[];

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

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u8  unk28[2];
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u64 unk38;
};

struct Ent88 {
    u32 unk00[0x22];
};

struct Grp330 {
    struct Ent88 ent[6];
};

struct Rec35C {
    struct Grp330 unk000;
    u8 unk330[0x14];
    u8 unk344[0x18];
};

void BATTLE_REC_SetData(const void *a, const void *b, const void *c)
{
    u16 v;

    MI_CpuCopy8(b, pBattleRec->unk80, sizeof(pBattleRec->unk80));
    MI_CpuCopy8(c, &pBattleRec->unkC4, sizeof(pBattleRec->unkC4));
    MI_CpuCopy8(a, pBattleRec->unk00, sizeof(pBattleRec->unk00));
    v = pBattleRec->unkC4.unk17DC;
    BATTLE_REC_Decode(&pBattleRec->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}


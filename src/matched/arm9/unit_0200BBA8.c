/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BBA8
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_BOX_HasMon
 *
 * 30 bytes, 0x0200BBA8..0x0200BBC8, one function, which carries a label in
 * the generated listing.
 *
 * Whether entry zero of the record is present.  The result is a local
 * initialised to 0 and set to 1 inside the `if`, not a `return 1` /
 * `return 0` pair: there is one epilogue and the arm is a single `movs`.
 *
 * BATTLE_BOX_GetMon, which it calls, is the first function of
 * src/matched/unit_0200BBC8.c; the other caller of that address is
 * func_0200BAF4 at 0x0200BB1E, and that call is what attests it here.
 *
 * func_0200BAF4 itself is a near miss.  Its 100 bytes reproduce in size and
 * in every instruction, and fifteen bytes differ, all of them register
 * numbers: the original keeps the id parameter in r5 and the loop counter in
 * r4, where this source coalesces the two into r4 because the counter is born
 * after the id dies.  Twenty shapes were tried, five declaration orders for
 * the three locals crossed with two statement orders, plus four forms that
 * give the counter a live range reaching back past the id's last use; the
 * best is fifteen and the ranking is flat between fifteen and twenty-eight. *
 * symbols:
 *   BATTLE_REC_Decode  0x0200B900  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   pBattleRec  0x0214616C  data
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
 *   (none)
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

u32 BATTLE_BOX_HasMon(void *a)
{
    u32 r = 0;

    if (POKE_TOOL_GetBoxValue(BATTLE_BOX_GetMon(a, 0, 0), 0xA9, 0) != 0) {
        r = 1;
    }
    return r;
}

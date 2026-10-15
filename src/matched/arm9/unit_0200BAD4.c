/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BAD4
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_BOX_SetMon
 *
 * 30 bytes, 0x0200BAD4..0x0200BAF4, one function, which carries no label in
 * the generated listing.
 *
 * One 0x88-byte entry assigned into a two-dimensional array: the outer stride
 * is 0x330 and the inner 0x88, and the copy is an inline counted `ldm`/`stm`
 * loop of 17 iterations, which is 0x88 divided by eight.  The eight-byte step
 * is what says the entry is word aligned; declared as a byte array the same
 * assignment becomes a `ldrb`/`strb` loop of 0x88 iterations.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * It is a range of its own because the function on either side of it is a
 * near miss: BATTLE_BOX_GetFromSave before it, which has no witness for 0x020271CC,
 * and func_0200BAF4 after it, which is fifteen bytes of register numbering.
 * Its only caller, BATTLE_BOX_StoreParty, is therefore outside this range and is what
 * attests it. *
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
extern u32   func_02017E88(void *e, u32 a, u32 b);
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

void BATTLE_BOX_SetMon(struct Grp330 *p, u32 g, u32 i, const struct Ent88 *src)
{
    p[g].ent[i] = *src;
}


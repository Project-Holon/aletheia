/*
 * file:     btl_client_p02.c
 * unit:     yes
 * function: func_021D3A20, func_021D3A40, func_021D3A7C, func_021D3A98, func_021D3AB4, func_021D3AD0, func_021D3AEC, func_021D3B08, func_021D3B28, func_021D3B5C, func_021D3B74, func_021D3B88, func_021D3B9C, func_021D3BB0, func_021D3BC0, func_021D3BE0, func_021D3C0C, func_021D3C2C, func_021D3C44, func_021D3C70, func_021D3C90, func_021D3CA8, func_021D3CC8, func_021D3CFC, func_021D3D1C, func_021D3D2C, func_021D3D50, func_021D3D70, func_021D3D7C, func_021D3D90, func_021D3D9C, func_021D3DC4, func_021D3E70, func_021D3EC8, func_021D3F04, func_021D3F48, func_021D3F4C, func_021D3F54, func_021D3F60, func_021D3F64, func_021D3F88, func_021D3F98, func_021D3FA8, func_021D3FAC, func_021D3FC4, func_021D3FD0, func_021D3FDC
 * address:  0x021D3A20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_ConsumeHeldItem 0x021D6730 thumb ov093
 *   BTL_POKEPARAM_RecordMoveUse 0x021D6744 thumb ov093
 *   BTL_POKEPARAM_SetContFlag 0x021D5FE4 thumb ov093
 *   BTL_POKEPARAM_ClearContFlag 0x021D6008 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_POKEPARAM_ClearTurnFlag 0x021D6440 thumb ov093
 *   BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 *   BTL_POKEPARAM_ResetEffectsOnSwitchOut   0x021D64F0  thumb
 *   BTL_FIELD_RegisterSlot 0x021EF9F4 thumb ov093
 *   BTL_FIELD_AddSlotHolder 0x021EFAD8 thumb ov093
 *   BTL_FIELD_RemoveHolderFromSlots 0x021EFB34 thumb ov093
 *   BTL_FIELD_RemoveSlot 0x021EFA94 thumb ov093
 *   func_021D69A0 0x021D69A0 thumb ov093
 *   BTL_POKEPARAM_PassEffects 0x021D65C8 thumb ov093
 *   BTL_POKEPARAM_SetSubstituteHp 0x021D6D5C thumb ov093
 *   BTL_POKEPARAM_ClearSubstitute   0x021D6D70  thumb
 *   BTL_CLIENT_AddPoints 0x021CD9F4 thumb ov093
 *   BTL_MAIN_AddClientPoints 0x021B9B10 thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 *   BTL_POKEPARAM_ClearConsumedItem   0x021D6738  thumb
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 *   BTL_POKEPARAM_AddHitRecord 0x021D6848 thumb ov093
 *   BTL_POKEPARAM_AdvanceTurn 0x021D6408 thumb ov093
 *   BTL_EVENT_ClearClientReservedChoice 0x021D6E88 thumb ov093
 *   BTL_FIELD_TickSlots   0x021EFC78  thumb
 *   BTL_POKEPARAM_SetWeight 0x021D67D8 thumb ov093
 *   BTL_FIELD_GetCountdownByte 0x021EF9A8 thumb ov093
 *   BTL_MAIN_GetTrainerItem 0x021B9F84 thumb ov093
 *   gAiSlotLimitTable  0x021EFF74  data  a1
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   gAiMoveStageCheckPairs  0x021EFF94  data  ov093  a1
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 *   gAiMoveSickCheckPairs 0x021EFFA0 data a1
 *   BTLV_CORE_SetCounterDisplay 0x021EAE74 thumb ov093
 *   BTLV_CORE_PollCounterInput 0x021EAE64 thumb ov093
 *   BTLV_CORE_StartFadeIn 0x021EAE04 thumb ov093
 *   BTLV_CORE_SetCounterValueMode 0x021EAECC thumb ov093
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   func_021F8B10 0x021F8B10 thumb ov094
 *   BTL_MAIN_SetKeepBgm 0x021B92A0 thumb ov093
 *   BTLV_CORE_PollFadeInDone 0x021EAE14 thumb ov093
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   gBtlNetSourceName 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   sub_02030734   0x02030734  arm
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   gBtlNetSourceName   0x021F3A98  data
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_02082D44 0x02082D44 arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   BTL_POKEPARAM_ClearSickConts  0x021D63B8  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_POKEPARAM_ClearHitHistory  0x021D67F4  thumb  ov093
 *   func_021D6DC4  0x021D6DC4  thumb  ov093
 *   gBtlPokeparamFileName     0x021F3AA4  data  a1
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   func_020181F4  0x020181F4  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   BTLV_CORE_PackBytes  0x021E8CE0  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject 0x021EF948 thumb ov093
 *   BTL_CALC_ApplyStatStage  0x021D78E4  thumb  ov093
 *   gSemiInvulnerableContFlags  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 *   func_021D3D84  0x021D3D84  thumb
 *   BTL_POKEPARAM_ReplaceMove  0x021D5734  thumb
 *   BTL_POKEPARAM_SetStat  0x021D5970  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   BTL_POKEPARAM_SetItem  0x021D5B44  thumb
 *   func_021D5D14  0x021D5D14  thumb
 */
#include "../../matched/include/Obj13430.h"

struct QK;
struct QJ;
struct BtlNet;
struct BtlPokeParam;
struct Arr;
struct UtilSlots;
struct Q1;
struct Unk021D62A8;
struct Link;
struct Entry;
struct U16Vec;
struct Sav;
#include "btl_net_types.h"

typedef struct { u32 v; } Slot;

struct Rec { u16 a, b; u8 c, d, e; };

struct HalfRec { u16 a, b, c, d; };

typedef struct {
    u8 a;
    u8 b;
} Pair_021D3E70;

typedef struct { u8 a,b; } Pair_021D3EC8;

struct Q {
    u8 state, mode;
    u8 flag0:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, rest:2;
    u8 unk3;
    u16 delay, current, target, maximum, tick;
};

typedef struct {
    int w[8];
} S32;

struct BtlNetRec {
    u8 pad00[0xbb8];
    u16 fBB8;
    u16 fBBA;
};

struct BtlNetSync {
    struct {
        u8 val;
        u8 ok;
    } e[4];
    u8 n;
    u8 mx;
    u8 pad[2];
};

struct BtlNet {
    void *link;                 /* 0x00 */
    u16 heap;                   /* 0x04 */
    u8 id;                      /* 0x06 */
    u8 f07;                     /* 0x07 */
    u16 mask;                   /* 0x08 */
    u8 f0a, count, f0c, f0d, f0e, f0f, f10;
    u8 states[4];               /* 0x11 */
    u8 pad15[3];
    S32 f18;                    /* 0x18 */
    struct BtlNetRec rec0;      /* 0x38 */
    struct BtlNetRec peer[4];   /* 0xbf4 */
    void *tblA[4];              /* 0x3ae4 */
    void *tblB[4];
    void *tblC[4];
    void *f3b14;
    void *f3b18;
    union {
        u32 f3b1c;
        u16 buf[2];
    } u;                        /* 0x3b1c */
    struct BtlNetSync sync;     /* 0x3b20 */
};

typedef union {
    u32 w;
    struct {
        u32 type : 8;
        u32 size : 24;
    } h;
} Hdr_021D3A20;

typedef struct {
    u8 pad00[0x14];
    void *f14;
} In;

typedef struct {
    u8 pad00[0x28];
    u8 f28[0x40];
    u32 f68;
} Out;

typedef struct {
    u32 type : 8;
    u32 size : 24;
} Hdr_021D4CB8;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ConsumeHeldItem(struct QK *p, u16 v);
extern void BTL_POKEPARAM_RecordMoveUse(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
extern void BTL_POKEPARAM_SetContFlag(u8 *, u32);
extern void BTL_POKEPARAM_ClearContFlag(u8 *, u32);
extern void BTL_POKEPARAM_SetTurnFlag(struct BtlPokeParam *, u32);
extern void BTL_POKEPARAM_ClearTurnFlag(u8 *, u32);
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern void BTL_POKEPARAM_ResetEffectsOnSwitchOut(void *p);
extern int BTL_FIELD_RegisterSlot(void *, u32, Slot, int);
extern int BTL_FIELD_AddSlotHolder(char *a, u32 b, u32 c);
extern void BTL_FIELD_RemoveHolderFromSlots(struct BtlNet *, u8);
extern int BTL_FIELD_RemoveSlot(void *, int);
extern void func_021D69A0(u8 *, int, u8);
extern void BTL_POKEPARAM_PassEffects(struct BtlPokeParam *, struct BtlPokeParam *);
extern void BTL_POKEPARAM_SetSubstituteHp(u8 *, u16);
extern void BTL_POKEPARAM_ClearSubstitute(unsigned char *p);
extern void BTL_CLIENT_AddPoints(u8 *p, u8 n);
extern void BTL_MAIN_AddClientPoints(u8 *, u8, int);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern void BTL_SLOT_UpdateIllusion(char *, struct Arr *, int);
extern void BTL_POKEPARAM_ClearConsumedItem(u8 *p);
extern void BTL_POKEPARAM_CureSickBySource(struct UtilSlots *p, int v);
extern void BTL_POKEPARAM_AddHitRecord(u8 *p, struct Rec *r);
extern void BTL_POKEPARAM_AdvanceTurn(u8 *);
extern void BTL_EVENT_ClearClientReservedChoice(u8 *);
extern void BTL_POKEPARAM_SetWeight(u8 *p, u32 n);
extern u8 BTL_FIELD_GetCountdownByte(u32 *);
extern u16 BTL_MAIN_GetTrainerItem(char *p, int i, unsigned int j);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 func_021D805C(void *p, u32 n);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern u8 BTL_POKEPARAM_GetCritStage(struct BtlPokeParam *p);
extern void BTLV_CORE_SetCounterDisplay(char *p, u32 a, u32 b);
extern int BTLV_CORE_PollCounterInput(void *);
extern void BTLV_CORE_StartFadeIn(u32 *p);
extern void BTLV_CORE_SetCounterValueMode(u8 *p, int v, int w);
extern void GFL_USE_FadeOutBgm(u32);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_SetMasterVolume(u8);
extern int func_021F8B10(void);
extern void BTL_MAIN_SetKeepBgm(u8 *p);
extern int BTLV_CORE_PollFadeInDone(u32 *p);
extern int POKE_REGULATION_GetDataSize(void);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32 WAZA_TOOL_GetMaxPP(u32, u32);
extern u8 POKE_TOOL_GetGender(void *h);
int func_021D3A20(u32 *a, int *b, u32 *c);
int func_021D3A40(u32 *a, int *b, const u32 *c);
int func_021D3A7C(u32 *a, int *b, u32 *c);
int func_021D3A98(u32 *a, int *b, u32 *c);
int func_021D3AB4(u32 *a, int *b, u32 *c);
int func_021D3AD0(u32 *a, int *b, u32 *c);
int func_021D3AEC(u32 *a, int *b, u32 *c);
int func_021D3B08(u32 *a, int *b, u32 *c);
int func_021D3B28(u32 *a, int *b, const u32 *c);
int func_021D3B5C(u8 *p, int b, u32 *q);
int func_021D3B74(u32 *a, int *b, u32 *c);
int func_021D3B88(u32 *a, int *b, u32 *c);
int func_021D3B9C(char *p, int unused, unsigned int *a);
int func_021D3BB0(char *p, int unused, unsigned int *a);
int func_021D3BC0(char *p, int unused, unsigned int *a);
int func_021D3BE0(char *p, int unused, unsigned int *a);
int func_021D3C0C(char *p, int unused, unsigned int *a);
int func_021D3C2C(u8 *p, int b, u32 *q);
int func_021D3C44(u8 *p, int unused, unsigned int *a);
int func_021D3C70(char *p, int unused, unsigned int *a);
int func_021D3C90(u8 *p, int b, u32 *q);
int func_021D3CA8(char *p, int unused, unsigned int *a);
int func_021D3CC8(char *p, int unused, const unsigned int *a);
int func_021D3CFC(char *p, int unused, unsigned int *a);
int func_021D3D1C(u8 *p);
int func_021D3D2C(char *p, int unused, unsigned int *a);
int func_021D3D50(char *p, int unused, unsigned int *a);
u8 func_021D3D70(u8 *p);
u32 func_021D3D7C(u8 *p);
u8 func_021D3D84(u8 *p);
u8 func_021D3D90(u8 *p);
void func_021D3D9C(u8 *p);
u32 func_021D3DC4(u8 *a, void *b, void *c);
int func_021D3E70(void *s, void *m);
int func_021D3EC8(void *s,struct Unk021D62A8 *m);
void func_021D3F04(struct BtlNetEntry *p);
void func_021D3F48(u8 *p, u32 v);
int func_021D3F4C(struct BtlNetEntry *p);
void func_021D3F54(u8 *p);
u8 func_021D3F60(u8 *p);
void func_021D3F64(struct BtlNetEntry *p, u16 v);
void func_021D3F88(struct BtlNetEntry *p);
int func_021D3F98(u8 *p);
u16 func_021D3FA8(u8 *p);
int func_021D3FAC(struct BtlNetEntry *p);
void func_021D3FC4(struct BtlNetEntry *p);
void func_021D3FD0(unsigned char *p);
void func_021D3FDC(u8 *p, struct Q *q);
void BTL_POKEPARAM_ReplaceMove(struct BtlPokeParam *p, u8 i, u16 a, u8 b, u32 c);
void BTL_POKEPARAM_SetStat(u8 *p, int k, u16 v);
int func_021D59B4(u8 *p, int k);
void BTL_POKEPARAM_SetItem(struct BtlPokeParam *p, u16 v);
int func_021D5D14(s8 *p, int i, int sign);
extern u8 gAiSlotLimitTable[];
extern Pair_021D3E70 gAiMoveStageCheckPairs[];
extern Pair_021D3EC8 gAiMoveSickCheckPairs[];
extern struct BtlNet *gBtlNet;
extern const char gBtlNetSourceName[];
extern const char gBtlPokeparamFileName[];
extern const u32 gSemiInvulnerableContFlags[4];

































int func_021D3A20(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ConsumeHeldItem((struct QK *)x, c[1]);
    return 1;
}
































int func_021D3A40(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_RecordMoveUse(x, c[1], c[2], c[3], c[4], c[5]);
    return 1;
}
































int func_021D3A7C(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetContFlag(x, c[1]);
    return 1;
}
































int func_021D3A98(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ClearContFlag(x, c[1]);
    return 1;
}
































int func_021D3AB4(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetTurnFlag((struct BtlPokeParam *)x, c[1]);
    return 1;
}
































int func_021D3AD0(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ClearTurnFlag(x, c[1]);
    return 1;
}
































int func_021D3AEC(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetAbility((struct QJ *)x, c[1]);
    return 1;
}
































int func_021D3B08(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetItem((struct BtlPokeParam *)x, c[1]);
    return 1;
}
































int func_021D3B28(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ReplaceMove((struct BtlPokeParam *)x, c[1], c[4], c[2], c[3]);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl BTL_SIDE_GetPokeByIdThunk; bl BTL_POKEPARAM_ResetEffectsOnSwitchOut; movs r0, #1; pop {r3, pc}.
 */
int func_021D3B5C(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ResetEffectsOnSwitchOut(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3B74(u32 *a, int *b, u32 *c)
{
    Slot s;
    s.v = c[1];
    BTL_FIELD_RegisterSlot((void *)a[13], c[0], s, 0);
    return 1;
}
































int func_021D3B88(u32 *a, int *b, u32 *c)
{
    BTL_FIELD_AddSlotHolder((char *)a[13], c[0], (u8)c[1]);
    return 1;
}
































/*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3B9C(char *p, int unused, unsigned int *a)
{
    BTL_FIELD_RemoveHolderFromSlots(*(struct BtlNet * *)&((struct BtlNetCtx *)p)->f34, a[0]);
    return 1;
}
































/*
 * extent: compiled 14 bytes followed by 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BB0(char *p, int unused, unsigned int *a)
{
    BTL_FIELD_RemoveSlot(((struct BtlNetCtx *)p)->f34, a[0]);
    return 1;
}
































/*
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BC0(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D69A0(obj, a[1], a[2]);
    return 1;
}
































int func_021D3BE0(char *p, int unused, unsigned int *a)
{
    u8 *first = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    u8 *second = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[1]);
    BTL_POKEPARAM_PassEffects((struct BtlPokeParam *)second, (struct BtlPokeParam *)first);
    return 1;
}
































int func_021D3C0C(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    BTL_POKEPARAM_SetSubstituteHp(obj, a[1]);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl BTL_SIDE_GetPokeByIdThunk; bl BTL_POKEPARAM_ClearSubstitute; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C2C(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ClearSubstitute(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3C44(u8 *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    u8 value = a[1];
    if (index == p[0x1a6]) BTL_CLIENT_AddPoints(p, value);
    else BTL_MAIN_AddClientPoints(*(u8 * *)&((struct BtlNetCtx *)p)->f00, index, value);
    return 1;
}
































int func_021D3C70(char *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    struct Arr *obj = (struct Arr *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct BtlNetCtx *)p)->f04, index);
    BTL_SLOT_UpdateIllusion(*(char * *)&((struct BtlNetCtx *)p)->f00, obj, index);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl BTL_SIDE_GetPokeByIdThunk; bl BTL_POKEPARAM_ClearConsumedItem; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C90(u8 *p, int b, u32 *q)
{
    BTL_POKEPARAM_ClearConsumedItem(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3CA8(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    BTL_POKEPARAM_CureSickBySource((struct UtilSlots *)obj, (u8)a[1]);
    return 1;
}
































/*
 * lever: const source pointer restores the five-load acquisition order.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * Record byte 7 is uninitialized padding, preserved as in the listing.
 */
int func_021D3CC8(char *p, int unused, const unsigned int *a)
{
    struct Rec r;
    u8 *obj;
    u16 x, y;
    u8 z, w, v;
    obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    x = a[4]; y = a[5]; z = a[3]; w = a[2]; v = a[1];
    r.a = x; r.b = y; r.c = z; r.d = v; r.e = w;
    BTL_POKEPARAM_AddHitRecord(obj, (struct Rec *)((struct HalfRec *)&r));
    return 1;
}
































int func_021D3CFC(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    BTL_POKEPARAM_AdvanceTurn(obj);
    BTL_EVENT_ClearClientReservedChoice(obj);
    return 1;
}

































/* 021D3D1C  3-arg call on field 0x34, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0x34]; movs r1, #0; movs r2, #0; bl BTL_FIELD_TickSlots; movs r0, #1; pop {r3, pc}.
 */
int func_021D3D1C(u8 *p)
{
    BTL_FIELD_TickSlots(((struct BtlNetCtx *)p)->f34, 0, 0);
    return 1;
}
































int func_021D3D2C(char *p, int unused, unsigned int *a)
{
    int index = a[1];
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    BTL_POKEPARAM_SetStat(obj, index, a[2]);
    return 1;
}
































int func_021D3D50(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    BTL_POKEPARAM_SetWeight(obj, (u16)a[1]);
    return 1;
}

































/*
 * ldrb at #0x1a6 (pool constant)
 */
u8 func_021D3D70(u8 *p)
{
    return ((struct BtlNetCtx *)p)->f1a6;
}
































/*
 * Claimed follower 021D3D84 is included; target byte accessor has a verified shard.
 */
u32 func_021D3D7C(u8 *p) { return ((struct BtlNetCtx *)p)->f118; }
































u8 func_021D3D84(u8 *p) { return BTL_FIELD_GetCountdownByte(*(u32 * *)&((struct BtlNetCtx *)p)->f34); }

































/*
 * ldrb at #0x1ab (pool constant)
 */
u8 func_021D3D90(u8 *p)
{
    return ((struct BtlNetCtx *)p)->f1ab;
}
































/*
 * Byte narrowing before call proves u8 third argument despite wide callee definition.
 */
void func_021D3D9C(u8 *p) {
    u32 i;
    for(i=0;i<4;i++) *(u16 *)(p+i*2+0xe8)=BTL_MAIN_GetTrainerItem(*(char * *)&((struct BtlNetCtx *)p)->f00,p[0x1a6],(u8)i);
}

































u32 func_021D3DC4(u8 *a, void *b, void *c)
{
    u32 i;
    u32 r;
    u32 v;
    u32 lim;
    u32 off;
    u8 *t;

    lim = BTL_SLOT_GetCount(c);
    if (BTL_POKEPARAM_HasSick(b, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (gAiSlotLimitTable[i] < lim)
            break;
        off = i * 2;
        if (*(u16 *)(a + off + 0xe8) != 0) {
            r = 0;
            if (func_021D805C((void *)(u32)*(u16 *)(a + off + 0xe8), 0x29) != 0) {
                r = func_021D59B4(b, 0xd);
                if (r > BTL_CALC_DivideMaxHp(b, 4))
                    continue;
                r = 1;
            } else {
                if (func_021D3E70((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
                else if (func_021D3EC8((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
            }
            if (r != 0) {
                t = a + 0xe8;
                v = *(u16 *)(t + off);
                *(u16 *)(t + off) = 0;
                return v;
            }
        }
    }
    return 0;
}

































int func_021D3E70(void *s, void *m)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (func_021D805C(s, gAiMoveStageCheckPairs[i].a) != 0 && func_021D5D14(m, gAiMoveStageCheckPairs[i].b, 1) != 0)
            return 1;
    }
    if (func_021D805C(s, 0x24) != 0 && BTL_POKEPARAM_GetCritStage(m) == 0)
        return 1;
    return 0;
}
































int func_021D3EC8(void *s,struct Unk021D62A8 *m) { u32 i; for(i=0;i<7;i++) if(func_021D805C(s,gAiMoveSickCheckPairs[i].a) && BTL_POKEPARAM_HasSick(m,gAiMoveSickCheckPairs[i].b)) return 1; return 0; }

































void func_021D3F04(struct BtlNetEntry *p)
{
    p->b1 = 0;
    p->f3 = 0;
    p->b0 = 0;
    p->f1 = 0;
    p->h6 = 0;
    p->f2 = 0;
    p->h8 = 0;
    p->f0 = 0;
    p->h10 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->h12 = 0;
    p->h4 = 0;
}

































/*
 * strh v at #0xa
 */
void func_021D3F48(u8 *p, u32 v)
{
    *(u16 *)&p[0xa] = v;
}
































int func_021D3F4C(struct BtlNetEntry *p)
{
    return p->f2;
}
































/*
 * Extent follower 021D3F60 is already filed separately.
 */
void func_021D3F54(u8 *p) { p[2] |= 8; }
































/*
 * extent: Parent approved only the bounded four-byte accessor. Unapproved
 * followers 021D3F64 and 021D3F88, matched 021D3F98 and code 021D3FA8 follow;
 * no follower is included in this source.
 */
u8 func_021D3F60(u8 *p)
{
    return p[1];
}
































/*
 * note 2026-10-05: object is the same 14-byte record as func_021D3F04 (bit flags in byte 2).
 *   Sets h8 = v, bit0 = 1, h12 = 0, clears bits 1 and 2. Source order h12 = 0 before h8 = v:
 *   the scheduler hoists the strh, and r1 (v) stays live so the zero takes r2.
 */
void func_021D3F64(struct BtlNetEntry *p, u16 v)
{
    p->f0 = 1;
    p->h12 = 0;
    p->h8 = v;
    p->f1 = 0;
    p->f2 = 0;
}
































/*
 * Extent follower 021D3F98 is already filed separately; bitfield clear produces bics.
 */
void func_021D3F88(struct BtlNetEntry *p) { p->b0=0; p->f0=0; }
































int func_021D3F98(u8 *p)
{
    if (((struct Obj13430 *)p)->fC == ((struct Obj13430 *)p)->f8) return 1;
    return 0;
}

































/*
 * ldrh at #0x8
 */
u16 func_021D3FA8(u8 *p)
{
    return *(u16 *)&p[0x8];
}
































/*
 * extent: Twenty-two code bytes plus two zero padding bytes at 021D3FC2;
 * the approved separate 021D3FC4 leaf and existing 021D3FD0 follow.
 */
int func_021D3FAC(struct BtlNetEntry *p)
{
    if (p->f1) return 0;
    p->f4 = 1;
    return 1;
}
































/*
 * match-note: Clearing the unsigned-char bitfield emits bics #0x10;
 * raw p[2] &= ~0x10 emits ands #0xef and was four bytes out.
 * extent: Ten bytes of code, two zero padding bytes at 021D3FCE, then
 * existing matched func_021D3FD0 at 021D3FD0; no follower included.
 */
void func_021D3FC4(struct BtlNetEntry *p)
{
    p->f4 = 0;
}
































void func_021D3FD0(unsigned char *p)
{
    p[2] |= 0x20;
}
































/*
 * note 2026-10-05: now verifies EXACT (func_021F8B10 resolves).
 * match-note: A goto to the bottom epilogue reproduces the entry guards;
 * input is called before adjusted=0, preserving the original scheduling.
 */
void func_021D3FDC(u8 *p, struct Q *q)
{
    int changed, adjusted, input;
    if (p[0x1a7] != 2 || q->flag4 || q->flag5 || !q->maximum) goto done;
    changed = 0;
    if (q->flag3) {
        q->flag3 = 0;
        if (!q->flag0) {
            if (q->current < q->maximum && q->state == 0) {
                ++q->current;
                if (!q->delay) q->target = q->current;
                changed = 1;
            }
        } else {
            if (q->tick < q->target) {
                ++q->tick;
                if (q->tick == q->target) {
                    q->current = q->target;
                    if (*(void **)(p+0x54)) BTLV_CORE_SetCounterDisplay(*(void **)(p+0x54),q->current,q->target);
                }
            }
            return;
        }
    }
    if (!q->current || !*(void **)(p+0x54)) return;
    switch (q->state) {
    case 0:
        input = BTLV_CORE_PollCounterInput(*(void **)(p+0x54));
        adjusted = 0;
        switch (input) {
        case 2:
            q->mode = 1;
            BTLV_CORE_StartFadeIn(*(void **)(p+0x54));
            q->flag1 = 1;
            q->state = 1;
            BTLV_CORE_SetCounterValueMode(*(void **)(p+0x54),q->current,1);
            GFL_USE_FadeOutBgm(30);
            GFL_USE_SetPlayersAudible(0,62);
            PM_VOICE_SetMasterVolume(0);
            func_021F8B10();
            BTL_MAIN_SetKeepBgm((u8 *)(*(u32 *)p));
            break;
        case 0:
            if (q->target > 1) { --q->target; adjusted = 1; }
            q->delay = 45;
            break;
        case 1:
            if (q->target < q->maximum) { ++q->target; adjusted = 1; }
            q->delay = 45;
            break;
        }
        if (adjusted || changed) BTLV_CORE_SetCounterDisplay(*(void **)(p+0x54),q->current,q->target);
        if (q->delay) {
            --q->delay;
            if (!q->delay) {
                q->mode = 2;
                BTLV_CORE_StartFadeIn(*(void **)(p+0x54));
                q->flag1 = 1;
                q->state = 1;
                GFL_USE_FadeOutBgm(30);
                GFL_USE_SetPlayersAudible(0,62);
                PM_VOICE_SetMasterVolume(0);
                func_021F8B10();
            }
        }
        break;
    case 1:
        if (BTLV_CORE_PollFadeInDone(*(void **)(p+0x54))) { q->flag2 = 1; q->state = 2; }
        break;
    case 2:
        break;
    }
done:
    return;
}

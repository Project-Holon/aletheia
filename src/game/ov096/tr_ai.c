/*
 * file:     tr_ai.c
 * unit:     yes
 * function: func_02187F00, func_02187FB0, func_02188080, func_021880BC, func_02188134, func_02188140, func_0218814C, func_02188284, func_021885BC, func_0218871C, func_0218872C, func_0218873C, func_0218874C, func_0218875C, func_0218878C, func_021887B4, func_021887C4, func_021887D4, func_021887E4, func_021887F4, func_0218883C, func_0218884C, func_0218885C, func_0218889C, func_021888AC, func_021888BC, func_02188904, func_02188914, func_02188924, func_02188980, func_02188990, func_021889A0, func_021889E8, func_021889F8, func_02188A08, func_02188A54, func_02188A64, func_02188A74, func_02188A84, func_02188A94, func_02188AA4, func_02188AB4, func_02188AD8, func_02188AE8, func_02188AF8, func_02188B1C, func_02188B64, func_02188BB0, func_02188C1C, func_02188C88, func_02188CA0, func_02188D48, func_02188D5C, func_02188E00, func_02188E24, func_02188E90, func_02188F14, func_02188F2C, func_02188F58, func_02188FAC, func_02188FBC, func_02188FCC, func_0218905C, func_0218906C, func_0218907C, func_0218908C, func_021890C0, func_021890D0, func_021890E0, func_021890F0, func_02189100, func_02189150, func_02189160, func_02189170, func_021891D4, func_021891E4, func_021891F4, func_021892D8, func_021892E8, func_021892F8,func_021893AC,func_021893B4,func_021893CC,func_021893D4, func_021893DC, func_02189400, func_02189434, func_0218945C, func_0218948C, func_021894D4, func_021894F8, func_02189500, func_02189524, func_02189548, func_02189590, func_021895AC, func_021895C4, func_02189620, func_02189630, func_02189640, func_02189668, func_02189694, func_021896E0, func_02189718, func_02189758, func_0218979C, func_021897CC, func_02189800, func_0218989C, func_02189978, func_021899C4, func_021899DC, func_02189A2C, func_02189A44, func_02189A6C, func_02189A9C, func_02189AC0, func_02189B78, func_02189BFC, func_02189C8C, func_02189CEC, func_02189D48, func_02189E70, func_02189E80, func_02189E90, func_02189ED0, func_02189EF8, func_02189F34, func_02189F58, func_02189F68, func_02189F78, func_02189F88, func_02189F98, func_02189FC0, func_0218A034, func_0218A074, func_0218A084, func_0218A094, func_0218A0A4, func_0218A0F4, func_0218A160, func_0218A220, func_0218A2FC, func_0218A308, func_0218A310, func_0218A324, func_0218A378, func_0218A384, func_0218A390, func_0218A3F4, func_0218A41C, func_0218A458, func_0218A494
 * address:  0x02187F00
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02020F14 0x02020F14 thumb
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   WAZA_TOOL_IsCacheCreated 0x0201C408 thumb
 *   WAZA_TOOL_CreateCache 0x0201C328 thumb
 *   D_0218A7A0 0x0218A7A0 data
 *   D_0218A574 0x0218A574 data
 *   func_02011324 0x02011324 thumb
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_Delete 0x02011264 thumb
 *   WAZA_TOOL_DeleteCache 0x0201C3C0 thumb
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   func_020870D0 0x020870D0 arm
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_MAIN_IsPosInTable 0x021B9A6C thumb ov093
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_MAIN_IsOpposingPos 0x021B8CE8 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   func_0218A528 0x0218A528 thumb ov096
 *   VM_Start 0x0201127C thumb
 *   func_02011290 0x02011290 thumb
 *   VM_Control 0x02011298 thumb
 *   VM_GetU32  0x0201134C  thumb
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_GetSideEffectEntry  0x021C82D0  thumb  ov093
 *   VM_Jump  0x020113B0  thumb
 *   BTL_SERVER_FLOW_GetTurnCount 0x021C8138 thumb ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTLV_CORE_GetHighByte  0x021E8CFC  thumb  ov093
 *   BTLV_CORE_GetLowByte  0x021E8D04  thumb  ov093
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_CalcPredictedMoveDamage 0x021C7E14 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_SERVER_FLOW_CalcMoveTypeEffectiveness  0x021C7DAC  thumb  ov093
 *   BTL_FIELD_GetCountdownValue 0x021EF884 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   BTL_POKEPARAM_GetMoveStreak 0x021D679C thumb ov093
 *   d_0218A580     0x0218A580  data   ov096  a4
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   func_021D5478  0x021D5478  thumb  ov093
 *   BTL_SERVER_FLOW_CountFasterPokes  0x021C81D0  thumb  ov093
 *   BTL_POKEPARAM_GetTurnCount  0x021D5BA4  thumb  ov093
 *   d_0218A58C     0x0218A58C  data   ov096  a4
 *   BTL_SLOT_FindPoke 0x021B9C98 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTL_SERVER_FLOW_CheckFieldEffectActive  0x021C82F4  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   func_021F8AFC 0x021F8AFC thumb ov094
 *   func_02019C90 0x02019C90 thumb
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   D_0218A7C0 0x0218A7C0 data a4
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb  arm9
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb  arm9
 */
#include "../../matched/include/Obj00067.h"
#include "../../matched/include/Obj13649.h"
#include "../../matched/include/Obj02152.h"
#include "../../matched/include/Obj21916.h"
#include "../../matched/include/Obj21917.h"
#include "../../matched/include/Obj21918.h"
#include "../../matched/include/Obj21919.h"
#include "../../matched/include/Obj07919.h"
#include "../../matched/include/Obj21920.h"
#include "../../matched/include/Obj21921.h"
#include "../../matched/include/Obj21922.h"
#include "../../matched/include/Obj21923.h"
#include "../../matched/include/Obj21924.h"
#include "../../matched/include/Obj21925.h"
#include "../../matched/include/Obj21926.h"
#include "../../matched/include/Obj21927.h"
#include "../../matched/include/Obj21928.h"
#include "../../matched/include/Obj21929.h"
#include "../../matched/include/Obj21930.h"
#include "../../matched/include/Obj21931.h"
#include "../../matched/include/Obj21932.h"
#include "../../matched/include/Obj21933.h"
#include "../../matched/include/Obj21934.h"
#include "../../matched/include/Obj21935.h"
#include "../../matched/include/Obj21936.h"
#include "../../matched/include/Obj21937.h"
#include "../../matched/include/Obj21938.h"
#include "../../matched/include/Obj21939.h"
#include "../../matched/include/Obj21940.h"
#include "../../matched/include/Obj21941.h"
#include "../../matched/include/Obj21942.h"
#include "../../matched/include/Obj21943.h"
#include "../../matched/include/Obj21944.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj13651.h"
#include "../../matched/include/Obj10175.h"
#include "../../matched/include/Obj10176.h"
#include "../../matched/include/Obj10177.h"
#include "../../matched/include/Obj13654.h"
#include "../../matched/include/Obj06341.h"
#include "../../matched/include/Obj10179.h"
#include "../../matched/include/Obj13655.h"
#include "../../matched/include/Obj21945.h"
#include "../../matched/include/Obj06342.h"
#include "../../matched/include/Obj21946.h"
#include "../../matched/include/Obj21947.h"
#include "../../matched/include/Obj10180.h"
#include "../../matched/include/Obj13656.h"
#include "../../matched/include/Obj21948.h"
#include "../../matched/include/Obj21949.h"
#include "../../matched/include/Obj21950.h"
#include "../../matched/include/Obj21951.h"
#include "../../matched/include/Obj21952.h"
#include "../../matched/include/Obj21953.h"
#include "../../matched/include/Obj21954.h"
#include "../../matched/include/Obj21955.h"
#include "../../matched/include/Obj21956.h"
#include "../../matched/include/Obj06343.h"
#include "../../matched/include/Obj21957.h"
#include "../../matched/include/Obj21958.h"
#include "../../matched/include/Obj21959.h"
#include "../../matched/include/Obj21960.h"
#include "../../matched/include/Obj13658.h"
#include "../../matched/include/Obj13659.h"
#include "../../matched/include/Obj13660.h"
#include "../../matched/include/Obj13661.h"
#include "../../matched/include/Obj13663.h"
#include "../../matched/include/Obj07923.h"
#include "../../matched/include/Obj07924.h"
#include "../../matched/include/Obj21964.h"
#include "../../matched/include/Obj10184.h"
#include "../../matched/include/Obj21966.h"
#include "../../matched/include/Obj21967.h"
#include "../../matched/include/Obj21968.h"
#include "../../matched/include/Obj10185.h"
#include "../../matched/include/Obj13664.h"
#include "../../matched/include/Obj13665.h"
#include "../../matched/include/Obj21969.h"
#include "../../matched/include/Obj21970.h"
#include "../../matched/include/Obj21971.h"
#include "../../matched/include/Obj10186.h"
#include "../../matched/include/Obj07925.h"
#include "../../matched/include/Obj07926.h"
#include "../../matched/include/Obj10187.h"
#include "../../matched/include/Obj07927.h"
#include "../../matched/include/Obj21972.h"
#include "../../matched/include/Obj10188.h"
#include "../../matched/include/Obj10189.h"
#include "../../matched/include/Obj10190.h"
#include "../../matched/include/Obj13666.h"
#include "../../matched/include/Obj06344.h"
#include "../../matched/include/Obj10192.h"
#include "../../matched/include/Obj21973.h"
#include "../../matched/include/Obj21974.h"
#include "../../matched/include/Obj21975.h"
#include "../../matched/include/Obj21976.h"
#include "../../matched/include/Obj21977.h"
#include "../../matched/include/Obj13667.h"
#include "../../matched/include/Obj21978.h"
#include "../../matched/include/Obj13668.h"
#include "../../matched/include/Obj21979.h"
#include "../../matched/include/Obj21980.h"
#include "../../matched/include/Obj21981.h"
#include "../../matched/include/Obj21982.h"
#include "../../matched/include/Obj21983.h"
#include "../../matched/include/Obj13669.h"
#include "../../matched/include/Obj13671.h"
#include "../../matched/include/Obj21984.h"
#include "../../matched/include/Obj21985.h"
#include "../../matched/include/Obj21986.h"
#include "../../matched/include/Obj00067.h"
#include "../../matched/include/Obj13672.h"
#include "../../matched/include/G_Slot.h"
#include "../../matched/include/Obj04408.h"

struct ScriptVm;
struct ScriptVmParams;
struct QG;
struct UtilWork;
struct Cursor;
struct Rat;
struct Unk021D62A8;
struct Cur;
struct Q7;
struct QL;
struct Q1;
struct QI;
struct QK;
struct Work;
struct QF;
struct S2;
struct Rec;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_02187F00;

typedef unsigned long long u64;

typedef short s16;

typedef signed char s8;

typedef int s32_02188134;

typedef enum { COUNT_ONE = 1 } Count;

typedef struct { u8 state, index; unsigned short move; int scores[4]; u8 p14[0x28]; u32 mask, all; u8 flags, entry, slot, target; u8 p48[0x4c]; u8 side, opp; u8 p96[0x1a]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; u8 pc8[8]; u64 tick; } Obj;

typedef struct {
    u8 state, index;
    u16 move;
    int scores[4];
    u8 p14[0x10];
    short h24[6];
    signed char s30[6];
    u8 p36[6];
    u32 mask, all;
    u8 flags, entry, slot, target;
    u8 p48[0x4c];
    u8 side, opp;
    u8 p96[2];
    int mode;
    u8 p9c[0x14];
    int fb0, fb4, fb8;
    u8 *fbc, *fc0;
    int fc4;
    u8 pc8[8];
    u64 tick;
} Obj_02188284;

typedef struct { u8 state, index; u16 move; int scores[4]; u8 p14[0x28]; u32 mask, all; u8 flags, entry, slot, target; u8 p48[0x4c]; u8 side, opp; u8 p96[2]; int mode; u8 p9c[0x10]; void *script; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; u8 pc8[8]; u64 tick; } Obj_021885BC;

typedef int s32;

typedef enum { Z0 } E;

typedef struct Slot_02187F00 { u32 a : 3; u32 rest : 29; } Slot_02187F00;

typedef struct {
    u8 pad00[0xbc];
    u8 *fbc;
    u8 padC0[4];
    int fc4;
} Conn_02188284;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xbc - 0x3c];
    u8 *fbc;
    u8 *fc0;
    int fc4;
} Conn_02188CA0;

typedef signed int     s32_02188CA0;

typedef int s32_02188E00;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xb0 - 0x3c];
    int fb0;
    u8 padB4[4];
    char *fb8;
    u8 padBC[8];
    int fc4;
} Conn_02188E90;

typedef struct Obj_02188E90 Obj_02188E90;

typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; } Obj_021891F4;

typedef struct Obj_021892D8 Obj_021892D8;

typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; } Obj_021892F8;

typedef struct {
    u8 pad00[0x38];
    int f38;
    u8 pad3C[0x98 - 0x3c];
    int f98;
    int f9c;
    u8 padA0[0xc4 - 0xa0];
    int fc4;
} Conn_021892F8;

typedef struct { int a, b, c; } Tri;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4; char *fb8; u8 *fbc, *fc0; int fc4; } Obj_02189AC0;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; } Obj_02189B78;

typedef struct { int v[7]; } Seven;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x88]; int fc4; } Obj_02189C8C;

typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } Slot_02188E90;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u16 heap);
extern void *func_02020F14(u16 heap);
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);
extern u32 WAZA_TOOL_IsCacheCreated(void);
extern void WAZA_TOOL_CreateCache(s32_02187F00 n, u32 heap);
extern void *func_02011324(struct ScriptVm *vm);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u32 func_0203F0A8(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
extern void VM_Delete(void *);
extern void WAZA_TOOL_DeleteCache(void);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u64 func_020870D0(void);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int BTL_MAIN_IsPosInTable(int, u32);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern int BTL_MAIN_IsOpposingPos(int, int, int);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern void func_0218A528(u8 *);
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern int VM_Control(struct ScriptVm *vm);
extern u32 VM_GetU32(struct Cursor *p);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern Slot_02187F00 BTL_POKEPARAM_GetSickContRaw(void *, int);
extern int BTLV_CORE_IsSlotKind1Index15(Slot_02187F00);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_GetSideEffectEntry(int unused, unsigned int v, int k);
extern void VM_Jump(struct Cur *c, u32 v);
extern unsigned short BTL_SERVER_FLOW_GetTurnCount(struct Q7 *);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern u8 BTLV_CORE_GetHighByte(s32_02188CA0 v);
extern int BTLV_CORE_GetLowByte(int x);
extern u16 WAZA_TOOL_GetPower(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern u16 BTL_SERVER_FLOW_CalcPredictedMoveDamage(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *, u8 *, int);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern int BTL_SERVER_FLOW_CalcMoveTypeEffectiveness(u8 *p, int a, int b, int c);
extern int BTL_FIELD_GetCountdownValue(void);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern u16 BTL_POKEPARAM_GetMoveStreak(u8 *p);
extern int BTL_FIELD_GetStaticSlotObject(int);
extern u8 BTL_POKEPARAM_GetMovePPLost(u8 *p, u8 i);
extern u8 func_021D5478(struct Work *p);
extern u16 BTL_SERVER_FLOW_CountFasterPokes(u8 *p, u8 *a, u32 y);
extern unsigned short BTL_POKEPARAM_GetTurnCount(int *p);
extern int BTL_SLOT_FindPoke(u8 *p, u32 v);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_SERVER_FLOW_CheckFieldEffectActive(int, int, int);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);
extern int func_021F8AFC(int);
extern u32 func_02019C90(u16, u16, u32);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int WAZA_TOOL_GetParam(int, int);
extern int WAZA_TOOL_GetFlag(int, int);
extern int func_02020F20(int, int, u16);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
void *func_02187F00(void **a, u32 b, u32 c, u32 d, u16 heap);
int func_02187FB0(u8 *a);
void func_02188080(void *a);
void func_021880BC(int a, u8 *b, int c);
u8 func_02188134(u8 *p);
u8 func_02188140(u8 *p);
int func_0218814C(int a, Obj *b);
int func_02188284(int a, Obj_02188284 *b);
void func_021885BC(int a, Obj_021885BC *b);
int func_0218871C(struct Cursor *p, int q);
int func_0218872C(struct Cursor *a, u8 *b);
int func_0218873C(struct Cursor *a, u8 *b);
int func_0218874C(struct Cursor *a, u8 *b);
int func_0218875C(struct Cursor *a, int unused, int c);
int func_0218878C(struct Cursor *a, u8 *b);
int func_021887B4(struct Cursor *a, int b);
int func_021887C4(struct Cursor *a, int b);
int func_021887D4(struct Cursor *a, int b);
int func_021887E4(struct Cursor *a, int b);
int func_021887F4(struct Cursor *a, int b, int c);
int func_0218883C(struct Cursor *a, int b);
int func_0218884C(struct Cursor *a, int b);
int func_0218885C(struct Cursor *a, int b, int c);
int func_0218889C(struct Cursor *a, int b);
int func_021888AC(struct Cursor *a, int b);
int func_021888BC(struct Cursor *a, int b, int c);
int func_02188904(struct Cursor *a, int b);
int func_02188914(struct Cursor *a, int b);
int func_02188924(struct Cursor *a, int b, int c);
int func_02188980(struct Cursor *a, int b);
int func_02188990(struct Cursor *a, int b);
int func_021889A0(struct Cursor *a, int b, int c);
int func_021889E8(struct Cursor *a, int b);
int func_021889F8(struct Cursor *a, int b);
int func_02188A08(struct Cursor *a, int b, int c);
int func_02188A54(int a, int b);
int func_02188A64(int a, int b);
int func_02188A74(int a, int b);
int func_02188A84(int a, int b);
int func_02188A94(int a, int b);
int func_02188AA4(int a, int b);
int func_02188AB4(struct Cursor *a, unsigned char *b, int c);
int func_02188AD8(void *a, unsigned char *b);
int func_02188AE8(void *a, unsigned char *b);
int func_02188AF8(struct Cursor *a, unsigned char *b, int c);
int func_02188B1C(struct Cursor *a, int b);
int func_02188B64(struct Cursor *a, int b);
int func_02188BB0(struct Cursor *a, Conn_02188284 *b);
int func_02188C1C(struct Cursor *a, Conn_02188284 *b);
int func_02188C88(int a, unsigned char *b);
int func_02188CA0(struct Cursor *a, Conn_02188CA0 *b);
int func_02188D48(int a, unsigned char *b);
u32 func_02188D5C(struct Cursor *a, u8 *p);
int func_02188E00(struct Cursor *a, int b);
int func_02188E24(struct Cursor *a, u8 *b);
int func_02188E90(struct Cursor *a, Conn_02188E90 *b);
int func_02188F08(int a, Conn_02188E90 *b);
int func_02188F14(int a, unsigned char *b);
int func_02188F2C(struct Cursor *a,unsigned char *b);
int func_02188F50(int a, unsigned char *b);
int func_02188F58(struct Cursor *a, int b);
int func_02188FAC(struct Cursor *a, unsigned char *b);
int func_02188FBC(struct Cursor *a, unsigned char *b);
void func_02188FCC(struct Cursor *a, int b, int c);
int func_0218905C(int a, unsigned char *b);
int func_0218906C(void *a, unsigned char *b);
int func_0218907C(u8 * a, int b);
void func_0218908C(u8 *a, int b, int c);
int func_021890C0(struct Cursor *a, int b);
int func_021890D0(struct Cursor *a, int b);
int func_021890E0(struct Cursor *a, int b);
int func_021890F0(struct Cursor *a, int b);
int func_02189100(struct Cursor *a, int b, int c);
int func_02189150(struct Cursor *a, int b);
int func_02189160(struct Cursor *a, int b);
int func_02189170(struct Cursor *a, int b, int c);
int func_021891D4(int a, Obj_02188E90 * b);
int func_021891E4(int a, Obj_02188E90 * b);
int func_021891F4(struct Cursor *a, Obj_021891F4 *b, int c);
int func_021892D8(int a, Obj_021892D8 * b);
int func_021892E8(int a, Obj_02188E90 * b);
int func_021892F8(struct Cursor *a, Obj_021892F8 *b, int c);
int func_021893AC(int a, Obj_021892F8 *b);
int func_021893B4(int a, Obj_021892F8 *b);
int func_021893CC(int a, Obj_021892F8 *b);
int func_021893D4(int a, Obj_021892F8 *b);
int func_021893DC(struct Cursor *a, int b);
int func_02189400(struct Cursor *a, int b);
int func_02189434(struct Cursor *a, int b);
int func_0218945C(struct Cursor *a, int b);
int func_0218948C(struct Cursor *a, Conn_021892F8 *b);
int func_021894B4(int a, Conn_021892F8 *b);
int func_021894C4(int a, Conn_021892F8 *b);
int func_021894D4(struct Cursor *a, int b);
int func_021894F8(int a, Conn_021892F8 *b);
int func_02189500(int a, int b);
int func_02189524(int a, int b);
u32 func_02189548(struct Cursor *x, u8 *p);
int func_02189590(struct Cursor *a, u8 *b);
int func_021895AC(u8 *a, u8 *b);
int func_021895C4(struct Cursor *a, int b);
int func_02189620(u8 *a, u8 *b);
int func_02189630(u8 *a, u8 *b);
int func_02189640(struct Cursor *a, int b, int c);
int func_02189668(struct Cursor *a, int b);
int func_02189694(struct Cursor *a, int b);
int func_021896E0(struct Cursor *a, int b);
int func_02189718(struct Cursor *a, int b);
int func_02189758(struct Cursor *a, int b);
int func_0218979C(struct Cursor *a, int b);
int func_021897CC(struct Cursor *a, int b);
int func_02189800(struct Cursor *a, int b);
int func_0218989C(struct Cursor *a, int b);
int func_02189978(struct Cursor *a, int b);
int func_021899C4(u8 *a, u8 *b);
int func_021899DC(struct Cursor *a, int b);
int func_02189A2C(u8 *a, u8 *b);
int func_02189A44(int a, int b);
int func_02189A6C(struct Cursor *a, int b);
int func_02189A9C(struct Cursor *a, int b);
int func_02189AC0(struct Cursor *a, Obj_02189AC0 *b);
int func_02189B78(struct Cursor *a, Obj_02189B78 *b);
int func_02189BFC(struct Cursor *a, int b);
int func_02189C8C(struct Cursor *a, Obj_02189C8C *b);
int func_02189CEC(struct Cursor *a, int b);
int func_02189D30(int a, int b);
int func_02189D38(int a, int b);
int func_02189D40(int a, int b);
u32 func_02189D48(struct Cursor *a, u8 *p);
int func_02189E70(struct Cursor *a, u8 *b);
int func_02189E80(struct Cursor *a, u8 *b);
int func_02189E90(struct Cursor *a, u8 *b, int c);
int func_02189ED0(struct Cursor *a, u8 *b);
int func_02189EF8(struct Cursor *a, u8 *b);
int func_02189F34(struct Cursor *a, u8 *b);
int func_02189F58(u8 *a, u8 *b);
int func_02189F68(unsigned char *a, unsigned char *b);
int func_02189F78(unsigned char *a, unsigned char *b);
int func_02189F88(unsigned char *a, unsigned char *b);
int func_02189F98(unsigned char *a, unsigned char *b, int c);
int func_02189FC0(struct Cursor *a, u8 *b);
int func_0218A034(struct Cursor *a, u8 *b);
int func_0218A074(struct Cursor *a, unsigned char *b);
int func_0218A084(struct Cursor *a, unsigned char *b);
int func_0218A094(struct Cursor *a, unsigned char *b);
int func_0218A0A4(struct Cursor *a, u8 *b, int c);
int func_0218A0F4(u8 *a, int op, int x, int y, int z);
u8 func_0218A160(u8 *p, int k);
int func_0218A220(u8 *p, int k, u8 slot);
u8 *func_0218A2FC(u8 *p, u8 i);
u8 *func_0218A308(void *p, u32 i);
void func_0218A310(unsigned int a);
void func_0218A324(u8 *p);
int func_0218A378(void *a, int b, int c);
int func_0218A384(void *a, int b, int c);
u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d);
int func_0218A3F4(int a, int b, int c);
void func_0218A41C(unsigned int a);
void func_0218A458(void);
void *func_0218A494(u8 *a);
extern const char D_0218A7A0[];
extern u8 D_0218A574[];
extern const Tri d_0218A580;
extern const Seven d_0218A58C;
extern Slot_02188E90 *D_0218A7C0;




void *func_02187F00(void **a, u32 b, u32 c, u32 d, u16 heap)
{
    u8 *p;
    void *v;
    p = func_02030734(heap, 0xD8, 1, D_0218A7A0, 0x1D9);
    *(u16 *)(p + 0xA0) = heap;
    *(u32 *)(p + 0xC4) = 1;
    *(u32 *)(p + 0x40) = d;
    *(void **)(p + 0xA4) = func_020490F4(0xAB, heap);
    *(void **)(p + 0xA8) = func_02020F14(heap);
    *(void ***)(p + 0xB0) = a;
    *(u32 *)(p + 0xB4) = b;
    *(u32 *)(p + 0xB8) = c;
    *(u32 *)(p + 0x98) = BTL_MAIN_GetRule(a);
    *(void **)(p + 0x9C) = BTL_MAIN_GetCompetitor((void ***)a);
    v = VM_Create(heap, (const struct ScriptVmParams *)D_0218A574);
    VM_Init(v, p);
    if (WAZA_TOOL_IsCacheCreated() == 0)
        WAZA_TOOL_CreateCache(0x30, heap);
    func_0218A41C(*(u16 *)(p + 0xA0));
    return v;
}




/*
 * lever: unsigned count/u64 draw reproduce the guarded high multiply;
 *   the callee result is returned through the final flag clear, keeping r0 live.
 */
int func_02187FB0(u8 *a)
{
    u8 *p;
    u32 n;
    int candidates[3];
    u64 r;
    int result;
    p = func_02011324((struct ScriptVm *)a);
    if (((struct Obj00067 *)p)->f98 == 0) {
        p[0x95] = p[0x94] ^ 1;
        return func_0218814C((int)a, (Obj *)p);
    }
    if (((struct Obj00067 *)p)->f98 == 1 || ((struct Obj00067 *)p)->f98 == 2) {
        return func_02188284((int)a, (Obj_02188284 *)p);
    }
    n = 0;
    for (p[0x95] = 0; p[0x95] < 6; p[0x95]++) {
        if (p[0x95] != p[0x94] && (p[0x95] & 1) != (p[0x94] & 1)) {
            if (BTL_POKEPARAM_IsFainted(func_0218A2FC(p, p[0x95])) != 1)
                candidates[n++] = p[0x95];
        }
    }
    r = func_0203F0A8();
    if (n != 0)
        r = (r * n) >> 32;
    p[0x95] = candidates[r];
    result = func_0218814C((int)a, (Obj *)p);
    if (result == 0)
        p[0x47] = 0;
    return result;
}




/*
 * note: Extent ends with two-byte zero alignment padding.
 */
void func_02188080(void *a)
{
    u8 *p;
    p = func_02011324(a);
    ARC_TOOL_DeleteHandle(((struct Obj13649 *)p)->fA4);
    ARC_TOOL_DeleteHandle(((struct Obj13649 *)p)->fA8);
    func_020307B0(p);
    VM_Delete(a);
    if (WAZA_TOOL_IsCacheCreated() == 1) WAZA_TOOL_DeleteCache();
    func_0218A458();
}





void func_021880BC(int a, u8 *b, int c)
{
    u8 *p;
    int i;
    int z;

    p = func_02011324((struct ScriptVm *)a);
    p[0] = 0;
    ((struct Obj02152 *)p)->f2 = 0;
    p[1] = 0;
    ((struct Obj02152 *)p)->f38 = 0;
    p[0x44] = 0;
    p[0x45] = 0;
    p[0x94] = c;
    ((struct Obj02152 *)p)->f3C = ((struct Obj02152 *)p)->f40;
    ((struct Obj02152 *)p)->fC8 = 4;
    z = 0;
    for (i = 0; i < 4; i++) {
        if (b[i] == 0)
            *(int *)(p + 0x14 + i * 4) = z;
        else
            *(int *)(p + 0x14 + i * 4) = 100;
        p[0x48 + i] = 100 - (u32)(((u64)func_0203F0A8() * 0x10) >> 32);
    }
    ((struct Obj02152 *)p)->fCC = (u32)(((u64)func_0203F0A8() * 0x100) >> 32);
}





u8 func_02188134(u8 *p) { return ((u8 *)func_02011324((struct ScriptVm *)p))[0x46]; }





u8 func_02188140(u8 *p) { return ((u8 *)func_02011324((struct ScriptVm *)p))[0x47]; }




inline static u32 draw_below(u32 n)
{
    u32 r = func_0203F0A8();
    u64 random = r;
    if (n != 0)
        r = (random * n) >> 32;
    return r;
}




/*
 * Lever: guarded named field pointers retain the 0x18 frame; entry/mask
 * declaration order fixes r7/r6; u64 draw puts its high-word zero before
 * the count guard. All 9 relocation sites resolve.
 */
int func_0218814C(int a, Obj *b)
{
    int scores[4];
    u8 ids[4];
    long i;
    int v;
    Count n;

    u32 mask;
    int next;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    b->fbc = func_0218A2FC((u8 *)b, b->side);
    b->fc0 = func_0218A2FC((u8 *)b, b->opp);
    if (!(b->flags & 16)) {
        func_0218A310((unsigned int)((u8 *)b));
        func_0218A324((u8 *)b);
    }
    if ((mask = b->mask) != 0) {
    flagsPtr = &b->flags;
    maskPtr = &b->mask;
    entryPtr = &b->entry;
    do {
        if (mask & 1) {
            if (!(b->flags & 16)) b->state = 0;
            *flagsPtr &= ~16;
            b->tick = func_020870D0();
            func_021885BC((int)a, (Obj_021885BC *)b);
            if (b->flags & 16) return 1;
        }
        next = *entryPtr + 1;
        mask = *maskPtr >> 1;
        *entryPtr = next;
        *maskPtr = mask;
        b->index = 0;
    } while ((mask = *maskPtr) != 0);
    }
    if (b->flags & 2) {
        b->slot = 4;
    } else {
        n = COUNT_ONE;
        scores[0] = b->scores[0];
        ids[0] = 0;
        for (i = 1; i < 4; i++) {
            if (i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc)) {
                v = b->scores[i];
                if (scores[0] == v) {
                    scores[n] = v;
                    ids[n] = i;
                    n++;
                }
                if (scores[0] < v) {
                    scores[0] = v;
                    n = COUNT_ONE;
                    ids[0] = i;
                }
            }
        }
        b->slot = ids[draw_below(n)];
    }
    b->target = b->opp;
    return 0;
}















/*
 * note (2026-10-05, wD5 lane16): EXACT. The draw helper holds the random value in a u32 and
 *   widens a copy to u64 before the test (`u32 r = f(); u64 random = r; if (n) r = (random * n) >> 32;`).
 *   That makes the hi zero before the n test and keeps the result in r0, as at both original sites.
 */
int func_02188284(int a, Obj_02188284 *b)
{
    int limit;
    int scores[4];
    u8 ids[4];
    u8 ids2[6];
    u32 mask;
    int next;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    Count n;
    int i;
    int v;
    u8 j;
    int h;

    limit = (b->mode == 1) ? 4 : 6;
    if (!(b->flags & 16))
        b->opp = 0;
    while (b->opp < limit) {
        b->fbc = func_0218A2FC((u8 *)b, b->side);
        b->fc0 = func_0218A2FC((u8 *)b, b->opp);
        if (!(b->flags & 16)) {
            if (b->fc0 == 0) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            if (b->opp == b->side || BTL_POKEPARAM_IsFainted(b->fc0) == 1) {
                b->s30[b->opp] = -1;
                b->h24[b->opp] = -1;
                goto next;
            }
            func_0218A310((unsigned int)((u8 *)b));
            func_0218A324((u8 *)b);
            b->entry = 0;
            mask = b->all;
            b->index = 0;
            b->mask = mask;
        }
        if ((mask = b->mask) != 0) {
            flagsPtr = &b->flags;
            maskPtr = &b->mask;
            entryPtr = &b->entry;
            do {
                if (mask & 1) {
                    if (!(b->flags & 16)) b->state = 0;
                    *flagsPtr &= ~16;
                    b->tick = func_020870D0();
                    func_021885BC(a, (Obj_021885BC *)((u8 *)b));
                    if (b->flags & 16) return 1;
                }
                next = *entryPtr + 1;
                mask = *maskPtr >> 1;
                *entryPtr = next;
                *maskPtr = mask;
                b->index = 0;
            } while ((mask = *maskPtr) != 0);
        }
        if (b->flags & 2) {
            b->slot = 4;
            goto next;
        }
        n = COUNT_ONE;
        scores[0] = b->scores[0];
        ids[0] = 0;
        for (i = 1; i < 4; i++) {
            if (i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc)) {
                v = b->scores[i];
                if (scores[0] == v) {
                    scores[n] = v;
                    ids[n] = i;
                    n++;
                }
                if (scores[0] < v) {
                    scores[0] = v;
                    n = COUNT_ONE;
                    ids[0] = i;
                }
            }
        }
        b->s30[b->opp] = ids[draw_below(n)];
        b->h24[b->opp] = scores[0];
        if (BTL_MAIN_IsOpposingPos(b->fb0, BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->side), BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->opp)) == 0) {
            if (b->h24[b->opp] < 100)
                b->h24[b->opp] = -1;
        }
    next:
        b->opp = b->opp + 1;
    }
    h = b->h24[0];
    n = COUNT_ONE;
    ids2[0] = 0;
    for (j = 1; j < limit; j++) {
        v = b->h24[j];
        if (h == v) {
            ids2[n] = j;
            n++;
        }
        if (h < v) {
            h = v;
            ids2[0] = j;
            n = COUNT_ONE;
        }
    }
    b->target = ids2[draw_below(n)];
    b->slot = b->s30[b->target];
    if (func_0218A378((Obj_02188284 *)b, BTL_POKEPARAM_GetMoveId(b->fbc, b->slot), 27) == 1 && !(b->target & 1))
        b->target = b->side;
    v = BTL_POKEPARAM_GetMoveId(b->fbc, b->slot);
    if (b->mode == 2 && BTL_MAIN_IsPosInTable(b->side, b->target) == 0 && func_0218A384((Obj_02188284 *)b, v, 11) == 0)
        b->target = (b->target & 1) + 2;
    return 0;
}








/*
 * Lever: case 2 falls into default; an empty case 2 break adds four bytes.
 * Caller-visible return overrides tail-forwarders; 0201127C keeps visible r1.
 */
void func_021885BC(int a, Obj_021885BC *b)
{
    while (b->state != 2 && !(b->flags & 16)) {
        switch (b->state) {
        case 0:
            if (BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)b->fbc, b->index) == 0) {
                b->move = 0;
            } else {
                b->move = BTL_POKEPARAM_GetMoveId(b->fbc, b->index);
                b->script = func_0218A494((u8 *)b);
                VM_Start((struct ScriptVm *)a, b->script);
            }
            b->state++;
        case 1:
            if (b->mode == 2 && b->move != 0 && BTL_MAIN_IsPosInTable(b->side, b->opp) == 0 && func_0218A384((Obj_02188284 *)b, b->move, 11) == 0) {
                b->move = 0;
                func_02011290((struct ScriptVm *)a);
                func_0218A528((u8 *)b);
                b->script = 0;
            }
            if (b->move != 0) {
                VM_Control((struct ScriptVm *)a);
                if (b->flags & 1) {
                    b->flags &= ~16;
                    func_0218A528((u8 *)b);
                    b->script = 0;
                } else if (func_020870D0() - b->tick > 500) {
                    b->flags |= 16;
                    break;
                }
            } else {
                b->scores[b->index] = 0;
                b->flags |= 1;
            }
            if (b->flags & 1) {
                b->index++;
                if (b->index < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc) && !(b->flags & 8))
                    b->state = 0;
                else
                    b->state++;
                b->flags &= ~1;
            }
            break;
        case 2:
        default:
            b->state = 2;
            break;
        }
    }
}








int func_0218871C(struct Cursor *p, int q)
{
    func_0218875C(p, q, 0);
    return ((struct Obj21916 *)q)->fC4;
}








int func_0218872C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 1);
    return ((struct Obj21917 *)b)->fC4;
}








int func_0218873C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 2);
    return ((struct Obj21918 *)b)->fC4;
}








int func_0218874C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 3);
    return ((struct Obj21919 *)b)->fC4;
}









/*
 * Two levers closed this: (1) the third argument's zero is an enum-typed
 *   value (`typedef enum { Z0 } E; z = Z0;`) so mwcc does not fold
 *   `(v >> 24) | (z << 8)`; the operand order must put the shift second so
 *   its register is the accumulator (`lsls r2` + `orrs r2,r4`).  (2) the
 *   twice-called helper is 0x0201134C, not the 0x02011324 the old name
 *   implied.
 */
int func_0218875C(struct Cursor *a, int unused, int c) {
    u8 *p;
    u32 v;
    int r;
    E z;
    p = (u8 *)VM_GetU32(a);
    r = (int)VM_GetU32(a);
    v = func_0203F0A8();
    z = Z0;
    return func_0218A0F4((u8 *)a, c, ((v >> 24) | (z << 8)), (int)p, r);
}








int func_0218878C(struct Cursor *a, u8 *b)
{
    u32 value;
    value = VM_GetU32(a);
    *(u32 *)((u32)b + 4 + b[1] * 4) += value;
    if (*(int *)((u32)b + 4 + b[1] * 4) < 0)
        *(int *)((u32)b + 4 + b[1] * 4) = 0;
    return ((struct Obj07919 *)b)->fC4;
}








int func_021887B4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 0);
    return ((struct Obj21920 *)((unsigned int)b))->fC4;
}








int func_021887C4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 1);
    return ((struct Obj21921 *)((unsigned int)b))->fC4;
}








int func_021887D4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 2);
    return ((struct Obj21922 *)((unsigned int)b))->fC4;
}







int func_021887E4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 3);
    return ((struct Obj21923 *)((unsigned int)b))->fC4;
}








int func_021887F4(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t1);
    r = BTL_POKEPARAM_GetHpRatioFixed((struct Rat *)func_0218A2FC((u8 *)b, s));
    return func_0218A0F4((u8 *)a, c, r >> 12, t2, t3);
}







int func_0218883C(struct Cursor *a, int b)
{
    func_0218885C(a, b, 3);
    return ((struct Obj21924 *)((unsigned int)b))->fC4;
}







int func_0218884C(struct Cursor *a, int b)
{
    func_0218885C(a, b, 2);
    return ((struct Obj21925 *)((unsigned int)b))->fC4;
}








int func_0218885C(struct Cursor *a, int b, int c)
{
    int t1;
    int t3;
    int r;
    u8 s;

    t1 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t1);
    r = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, s));
    return func_0218A0F4((u8 *)a, c, r, 0, t3);
}







int func_0218889C(struct Cursor *a, int b)
{
    func_021888BC(a, b, 2);
    return ((struct Obj21926 *)((unsigned int)b))->fC4;
}







int func_021888AC(struct Cursor *a, int b)
{
    func_021888BC(a, b, 3);
    return ((struct Obj21927 *)((unsigned int)b))->fC4;
}








int func_021888BC(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t1);
    r = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, s), t2);
    return func_0218A0F4((u8 *)a, c, r, 1, t3);
}







int func_02188904(struct Cursor *a, int b)
{
    func_02188924(a, b, 2);
    return ((struct Obj21928 *)b)->fC4;
}







int func_02188914(struct Cursor *a, int b)
{
    func_02188924(a, b, 3);
    return ((struct Obj21929 *)b)->fC4;
}








int func_02188924(struct Cursor *a, int b, int c)
{
    int t1;
    int t3;
    u8 *r;
    u8 k;
    int x;
    Slot_02187F00 s;

    t1 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    k = func_0218A160((u8 *)b, t1);
    r = func_0218A2FC((u8 *)b, k);
    x = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)r, 5) != 0) {
        s = BTL_POKEPARAM_GetSickContRaw(r, 5);
        if (BTLV_CORE_IsSlotKind1Index15(s) != 0)
            x = 1;
    }
    return func_0218A0F4((u8 *)a, c, x, 1, t3);
}







int func_02188980(struct Cursor *a, int b)
{
    func_021889A0(a, b, 2);
    return ((struct Obj21930 *)b)->fC4;
}







int func_02188990(struct Cursor *a, int b)
{
    func_021889A0(a, b, 3);
    return ((struct Obj21931 *)b)->fC4;
}








int func_021889A0(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t1);
    r = BTL_POKEPARAM_TestContFlag((struct UtilWork *)func_0218A2FC((u8 *)b, s), t2);
    return func_0218A0F4((u8 *)a, c, r, 1, t3);
}







int func_021889E8(struct Cursor *a, int b)
{
    func_02188A08(a, b, 2);
    return ((struct Obj21932 *)b)->fC4;
}







int func_021889F8(struct Cursor *a, int b)
{
    func_02188A08(a, b, 3);
    return ((struct Obj21933 *)b)->fC4;
}








int func_02188A08(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    r = func_0218A160((u8 *)b, t0);
    r = BTL_SERVER_FLOW_GetSideEffectEntry(((struct Obj21934 *)b)->fB4, r, t1);
    return func_0218A0F4((u8 *)a, c, r != 0, 1, t2);
}







int func_02188A54(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 0);
    return ((struct Obj21935 *)b)->fC4;
}







int func_02188A64(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 1);
    return ((struct Obj21936 *)b)->fC4;
}






int func_02188A74(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 2);
    return ((struct Obj21937 *)b)->fC4;
}






int func_02188A84(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 3);
    return ((struct Obj21938 *)b)->fC4;
}






int func_02188A94(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 4);
    return ((struct Obj21939 *)b)->fC4;
}






int func_02188AA4(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 5);
    return ((struct Obj21940 *)b)->fC4;
}






int func_02188AB4(struct Cursor *a, unsigned char *b, int c) { int x,y; x=VM_GetU32(a); y=VM_GetU32(a); return func_0218A0F4((unsigned char *)a,c,((struct Obj21941 *)b)->f38,x,y); }






int func_02188AD8(void *a, unsigned char *b) { func_02188AF8(a,b,2); return ((struct Obj21942 *)b)->fC4; }






int func_02188AE8(void *a, unsigned char *b) { func_02188AF8(a,b,3); return ((struct Obj21943 *)b)->fC4; }






int func_02188AF8(struct Cursor *a, unsigned char *b, int c) { int x,y; x=VM_GetU32(a); y=VM_GetU32(a); return func_0218A0F4((unsigned char *)a,c,((struct Obj21944 *)b)->f2,x,y); }







int func_02188B1C(struct Cursor *a, int b)
{
    u16 *p;
    int m;
    int i;
    int v;

    p = (u16 *)(*(int *)&((struct Obj00005 *)a)->f14 + VM_GetU32(a));
    m = VM_GetU32(a);
    i = 0;
    do {
        v = p[i] | (p[i + 1] << 16);
        if (((struct Obj13651 *)b)->f38 == v) {
            VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
            break;
        }
        i += 2;
    } while (v != -1);
    return ((struct Obj13651 *)b)->fC4;
}






int func_02188B64(struct Cursor *a, int b)
{
    u16 *p;
    int m;
    int i;
    int v;

    p = (u16 *)(*(int *)&((struct Obj00005 *)a)->f14 + VM_GetU32(a));
    m = VM_GetU32(a);
    i = 0;
    do {
        v = p[i] | (p[i + 1] << 16);
        if (((struct Obj10175 *)b)->f38 == v)
            return ((struct Obj10175 *)b)->fC4;
        i += 2;
    } while (v != -1);
    VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return ((struct Obj10175 *)b)->fC4;
}






/*
 * Lever: b is a pointer to a Conn_02188284 struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   func_0218A378's second parameter is int (no truncation before the bl).
 */
/*
 * Lever: b is a pointer to a Conn struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   func_0218A378's second parameter is int (no truncation before the bl).
 */
int func_02188BB0(struct Cursor *a, Conn_02188284 *b)
{
    int m;
    int i;

    m = VM_GetU32(a);
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
        if (func_0218A378((Obj_02188284 *)b, BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return b->fc4;
}






/*
 * Lever: as func_02188BB0 (Conn_02188284 struct pointer, (Conn_02188284 *)(int second parameter)).
 */
/*
 * Lever: as func_02188BB0 (Conn struct pointer, int second parameter).
 */
int func_02188C1C(struct Cursor *a, Conn_02188284 *b)
{
    int m;
    int i;

    m = VM_GetU32(a);
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
        if (func_0218A378((Obj_02188284 *)b, BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i == BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return b->fc4;
}





int func_02188C88(int a, unsigned char *b) { ((struct Obj10176 *)b)->f38=BTL_SERVER_FLOW_GetTurnCount(*(struct Q7 * *)&((struct Obj10176 *)b)->fB4); return ((struct Obj10176 *)b)->fC4; }





/*
 * Lever: the source order of the switch arms decides which arm holds the
 *   shared tail and which becomes a stub jump; the original order is
 *   1,0,3,2,4,6,5,8,7 (not ascending).
 */
int func_02188CA0(struct Cursor *a, Conn_02188CA0 *b)
{
    u32 k;
    int p;
    int q;

    k = VM_GetU32(a);
    p = BTL_POKEPARAM_GetTypePair(b->fbc);
    q = BTL_POKEPARAM_GetTypePair(b->fc0);
    switch (k) {
    case 1:
        b->f38 = BTLV_CORE_GetHighByte(p);
        break;
    case 0:
        b->f38 = BTLV_CORE_GetHighByte(q);
        break;
    case 3:
        b->f38 = BTLV_CORE_GetLowByte(p);
        break;
    case 2:
        b->f38 = BTLV_CORE_GetLowByte(q);
        break;
    case 4:
        b->f38 = func_0218A378((Obj_02188284 *)b, b->f2, 0);
        break;
    case 6:
        b->f38 = BTLV_CORE_GetHighByte(BTL_POKEPARAM_GetTypePair(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 5:
        b->f38 = BTLV_CORE_GetHighByte(BTL_POKEPARAM_GetTypePair(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    case 8:
        b->f38 = BTLV_CORE_GetLowByte(BTL_POKEPARAM_GetTypePair(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 7:
        b->f38 = BTLV_CORE_GetLowByte(BTL_POKEPARAM_GetTypePair(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    }
    return b->fc4;
}




int func_02188D48(int a, unsigned char *b) { ((struct Obj10177 *)b)->f38=WAZA_TOOL_GetPower((void *)(((struct Obj10177 *)b)->f2)); return ((struct Obj10177 *)b)->fC4; }




u32 func_02188D5C(struct Cursor *a, u8 *p)
{
    int t = VM_GetU32(a);
    u8 x = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xBC));
    u8 y = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xC0));
    u32 best = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    int i;
    if (best == 0) {
        *(u32 *)(p + 0x38) = 0;
    } else {
        *(u32 *)(p + 0x38) = 2;
        for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)(*(u8 **)(p + 0xBC))); i++) {
            u16 c = BTL_POKEPARAM_GetMoveId(*(u8 **)(p + 0xBC), (u8)i);
            if (i != p[1]) {
                u32 r = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), x, y, c, 1, t);
                if (r > best) {
                    *(u32 *)(p + 0x38) = 1;
                    break;
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}





int func_02188E00(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13654 *)b)->f38 = t;
    return ((struct Obj13654 *)b)->fC4;
}





/*
 * Lever: x is a u16 local from the evidenced u16 callee return. Its word
 * spill reload stays after the outgoing fifth-argument store. All 5
 * relocation sites resolve; trailing two-byte padding is EXACT*.
 */
int func_02188E24(struct Cursor *a, u8 *b)
{
    int k;
    int m;
    u16 x;
    int y;

    k = VM_GetU32(a);
    m = VM_GetU32(a);
    x = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fBC, 1);
    y = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(*(u8 * *)&((struct Obj06341 *)b)->fB4, *(u8 * *)&((struct Obj06341 *)b)->fC0, 1);
    switch (k) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    }
    func_0218A0F4((u8 *)a, k, x, y, m);
    return ((struct Obj06341 *)b)->fC4;
}







/*
 * func_02188F08 is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 */
int func_02188E90(struct Cursor *a, Conn_02188E90 *b)
{
    int x;
    char *p;
    int n;

    x = BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, func_0218A160((u8 *)b, VM_GetU32(a)));
    p = BTL_SIDE_GetSlotOfClientThunk(b->fb8, x);
    n = BTL_MAIN_GetPositionsPerClientThunk((void *)b->fb0, x);
    b->f38 = 0;
    for (; n < BTL_SLOT_GetCount((struct Q1 *)p); n++) {
        if (BTL_POKEPARAM_IsAbleToBattle(func_0218A308(p, (u8)n)) != 0)
            b->f38++;
    }
    return b->fc4;
}







int func_02188F08(int a, Conn_02188E90 *b)
{
    b->f38 = b->f2;
    return b->fc4;
}






int func_02188F14(int a, unsigned char *b) { ((struct Obj10179 *)b)->f38=func_0218A378((void *)((int)b),((struct Obj10179 *)b)->f2,28); return ((struct Obj10179 *)b)->fC4; }






int func_02188F2C(struct Cursor *a,unsigned char *b) { int k; k=VM_GetU32(a); ((struct Obj13655 *)b)->f38=func_0218A220(b,k,func_0218A160(b,k)); return ((struct Obj13655 *)b)->fC4; }






int func_02188F50(int a, unsigned char *b) { return ((struct Obj21945 *)b)->fC4; }







int func_02188F58(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int y;
    int z;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    y = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06342 *)b)->fBC);
    z = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06342 *)b)->fC0);
    r = BTL_SERVER_FLOW_CalcMoveTypeEffectiveness((u8 *)(((struct Obj06342 *)b)->fB4), y, z, ((struct Obj06342 *)b)->f2);
    func_0218A0F4((u8 *)a, 2, r, t0, t1);
    return ((struct Obj06342 *)b)->fC4;
}






int func_02188FAC(struct Cursor *a, unsigned char *b) { func_02188FCC(a,(int)b,2); return ((struct Obj21946 *)b)->fC4; }






int func_02188FBC(struct Cursor *a, unsigned char *b) { func_02188FCC(a,(int)b,3); return ((struct Obj21947 *)b)->fC4; }







void func_02188FCC(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int n;
    char *handle;
    int i;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    n = BTL_MAIN_GetSlotClientIdThunk((char *)(((struct Obj10180 *)b)->fB0), func_0218A160((u8 *)b, t0));
    handle = BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj10180 *)b)->fB8, n);
    for (i = BTL_MAIN_GetPositionsPerClientThunk((void *)(((struct Obj10180 *)b)->fB0), n);
         i < BTL_SLOT_GetCount((struct Q1 *)handle); i++) {
        u8 *t = func_0218A308(handle, (unsigned char)i);

        if (BTL_POKEPARAM_IsFainted(t) == 0) {
            if (func_0218A0F4((u8 *)a, c, BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)t), 0, t1) != 0)
                break;
        }
    }
}






int func_0218905C(int a, unsigned char *b) { ((struct Obj13656 *)b)->f38=BTL_FIELD_GetCountdownValue(); return ((struct Obj13656 *)b)->fC4; }






int func_0218906C(void *a, unsigned char *b) { func_0218908C(a,(int)b,2); return ((struct Obj21948 *)b)->fC4; }






int func_0218907C(u8 * a, int b)
{
    func_0218908C(a, b, 3);
    return ((struct Obj21949 *)b)->fC4;
}






/*
 * return: func_0218A378's r0 is consumed by original caller, overriding its void forwarder declaration.
 */
void func_0218908C(u8 *a, int b, int c)
{
    int t0, t1;
    t0 = VM_GetU32((struct Cursor *)a);
    t1 = VM_GetU32((struct Cursor *)a);
    func_0218A0F4(a, c, func_0218A378((void *)b, ((struct Obj21950 *)b)->f2, 28), t0, t1);
}






int func_021890C0(struct Cursor *a, int b)
{
    func_02189100(a, b, 0);
    return ((struct Obj21951 *)b)->fC4;
}






int func_021890D0(struct Cursor *a, int b)
{
    func_02189100(a, b, 1);
    return ((struct Obj21952 *)b)->fC4;
}






int func_021890E0(struct Cursor *a, int b)
{
    func_02189100(a, b, 2);
    return ((struct Obj21953 *)b)->fC4;
}






int func_021890F0(struct Cursor *a, int b)
{
    func_02189100(a, b, 3);
    return ((struct Obj21954 *)b)->fC4;
}







int func_02189100(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int t3;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    r = func_021D59B4(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0)), t1);
    return func_0218A0F4((u8 *)a, c, r, t2, t3);
}






int func_02189150(struct Cursor *a, int b)
{
    func_02189170(a, b, 6);
    return ((struct Obj21955 *)b)->fC4;
}






int func_02189160(struct Cursor *a, int b)
{
    func_02189170(a, b, 1);
    return ((struct Obj21956 *)b)->fC4;
}







int func_02189170(struct Cursor *a, int b, int c)
{
    int t;
    int w;
    u8 y;
    u8 z;
    int r;

    VM_GetU32(a);
    t = VM_GetU32(a);
    w = func_021D59B4(*(u8 * *)&((struct Obj06343 *)b)->fC0, 0xd);
    y = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06343 *)b)->fBC);
    z = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06343 *)b)->fC0);
    r = BTL_SERVER_FLOW_CalcPredictedMoveDamage((u8 *)(((struct Obj06343 *)b)->fB4), y, z, ((struct Obj06343 *)b)->f2, 1, 0);
    return func_0218A0F4((u8 *)a, c, w, r, t);
}






int func_021891D4(int a, Obj_02188E90 * b)
{
    func_021891F4((struct Cursor *)a, (Obj_021891F4 *)b, 2);
    return ((struct Obj21957 *)((unsigned int)b))->fC4;
}






int func_021891E4(int a, Obj_02188E90 * b)
{
    func_021891F4((struct Cursor *)a, (Obj_021891F4 *)b, 3);
    return ((struct Obj21958 *)((unsigned int)b))->fC4;
}





/*
 * Lever: u16 value/result locals plus result binding give the original cmp operand order.
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int func_021891F4(struct Cursor *a, Obj_021891F4 *b, int c)
{
    u16 value, t;
    int k, z, r, i;
    u8 *s;
    int y;
    k = VM_GetU32(a);
    value = VM_GetU32(a);
    z = VM_GetU32(a);
    y = func_0218A160((u8 *)b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
            t = BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 3:
        s = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3));
        if (BTL_POKEPARAM_IsFainted(s) == 0) {
            for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)s); i++) {
                t = BTL_POKEPARAM_GetMoveId(s, (u8)i);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] == value) {
                r = 1;
                break;
            }
        }
        break;
    }
    return func_0218A0F4((u8 *)a, c, r, 1, z);
}





int func_021892D8(int a, Obj_021892D8 * b)
{
    func_021892F8((struct Cursor *)a, (Obj_021892F8 *)b, 2);
    return ((struct Obj21959 *)((unsigned int)b))->fC4;
}



int func_021892E8(int a, Obj_02188E90 * b)
{
    func_021892F8((struct Cursor *)a, (Obj_021892F8 *)((Obj_021892D8 *)b), 3);
    return ((struct Obj21960 *)((unsigned int)b))->fC4;
}






/*
 * Extent contains four followers at 021893AC, 021893B4, 021893CC, 021893D4.
 * Followers have 6,22,6,6 code bytes with 2 zero alignment bytes each.
 * Lever: bind each comparison's call result before comparing, per existing cmp idiom.
 * Caller-visible return overrides the tail-forwarder's void declaration.
 */
int func_021892F8(struct Cursor *a, Obj_021892F8 *b, int c)
{
    int k, z, y, r, i, t;
    unsigned int value;
    k = VM_GetU32(a);
    value = VM_GetU32(a);
    z = VM_GetU32(a);
    y = func_0218A160((u8 *)b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
            t = func_0218A378(b, (int)BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i), 28);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] != 0) {
                t = func_0218A378(b, b->values[y * 4 + i], 28);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    }
    return func_0218A0F4((u8 *)a, c, r, 1, z);
}






int func_021893AC(int a, Obj_021892F8 *b) { return b->fc4; }






int func_021893B4(int a, Obj_021892F8 *b) {
    ((u8 *)b)[0x44] |= 2;
    return b->fc4;
}






int func_021893CC(int a, Obj_021892F8 *b) { return b->fc4; }






int func_021893D4(int a, Obj_021892F8 *b) { return b->fc4; }








int func_021893DC(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetItem((struct QI *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13658 *)b)->f38 = t;
    return ((struct Obj13658 *)b)->fC4;
}








int func_02189400(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetItem((struct QI *)func_0218A2FC((u8 *)b, s));
    t = func_0218A3F4(b, (u16)t, 1);
    ((struct Obj13659 *)b)->f38 = t;
    return ((struct Obj13659 *)b)->fC4;
}








int func_02189434(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D59B4(func_0218A2FC((u8 *)b, s), 0x12);
    ((struct Obj13660 *)b)->f38 = t;
    return ((struct Obj13660 *)b)->fC4;
}







int func_0218945C(struct Cursor *a, int b) {
    int t;
    u8 s;
    int r;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = (int)func_0218A2FC((u8 *)b, s);
    r = 0;
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)t, 0) == 0) {
        r = 1;
    }
    ((struct Obj13661 *)b)->f38 = r;
    return ((struct Obj13661 *)b)->fC4;
}







/*
 * func_021894B4 and func_021894C4 are the unlabelled store-and-return stubs
 * after the lead function (function_starts seeds).
 */
int func_0218948C(struct Cursor *a, Conn_021892F8 *b)
{
    b->f38 = func_021D69AC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, VM_GetU32(a))), 0);
    return b->fc4;
}







int func_021894B4(int a, Conn_021892F8 *b)
{
    b->f38 = b->f98;
    return b->fc4;
}







int func_021894C4(int a, Conn_021892F8 *b)
{
    b->f38 = b->f9c;
    return b->fc4;
}





int func_021894D4(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetConsumedItem((struct QK *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13663 *)b)->f38 = t;
    return ((struct Obj13663 *)b)->fC4;
}






int func_021894F8(int a, Conn_021892F8 *b)
{
    return b->fc4;
}




int func_02189500(int a, int b) {
    int t;
    if (((struct Obj07923 *)b)->f38 != 0) {
        t = func_0218A378((void *)b, (u16)((struct Obj07923 *)b)->f38, 3);
    } else {
        t = 0;
    }
    ((struct Obj07923 *)b)->f38 = t;
    return ((struct Obj07923 *)b)->fC4;
}







int func_02189524(int a, int b) {
    int t;
    if (((struct Obj07924 *)b)->f38 != 0) {
        t = func_0218A378((void *)b, (u16)((struct Obj07924 *)b)->f38, 0x1c);
    } else {
        t = -1;
    }
    ((struct Obj07924 *)b)->f38 = t;
    return ((struct Obj07924 *)b)->fC4;
}






/*
 * 2026-10-05 (wD5 lane01): EXACT. The store is written in each arm (`p[0x38] = 0;` / `p[0x38] = f(q);`);
 *   a value local v merged at the join swapped p and q. Older notes below.
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes). Whole-body swap: image p=r4 q=r5, ours p=r5 q=r4. Allocation looks priority-ordered by reference count (q has four references, p four); no source tie-break found without changing the bytes.
 * note: 2026-10-04 Residue: whole-body register swap (original p in r4, q in r5; ours p in r5, q in r4); branch layout and instructions match otherwise. First param is unused (original uses r1 as p). Tried: ternary, early store, v-first, int v, copy of p, hoisted field pointer, struct p, split index locals, || vs && with Y-first.
 * note: 2026-10-05 (wD4 lane20): tried swapped declaration order of q and v, and the nested call chain split into three statements (a = f(x); a = g(p,a); q = h(p,a)); p stays r5, q r4. Residue unchanged: whole-body p/q colour swap (10 bytes).
 */
u32 func_02189548(struct Cursor *x, u8 *p)
{
    u8 *q;
    q = func_0218A2FC(p, func_0218A160(p, VM_GetU32(x)));
    if (BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)q) != 0xB6 && BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)q) != 0xC5 && BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)q) != 0xCB)
        *(u32 *)(p + 0x38) = 0;
    else
        *(u32 *)(p + 0x38) = BTL_POKEPARAM_GetMoveStreak(q);
    return *(u32 *)(p + 0xC4);
}






int func_02189590(struct Cursor *a, u8 *b)
{
    u32 t; t = VM_GetU32(a); VM_Jump((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + t); return ((struct Obj21964 *)b)->fC4;
}






int func_021895AC(u8 *a, u8 *b)
{
    b[0x44] |= 1; func_02011290((struct ScriptVm *)a); return 1;
}







int func_021895C4(struct Cursor *a, int b) {
    int r6;
    int r7;
    int x;
    int y;
    Tri t;
    r6 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    t = d_0218A580;
    x = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fBC, 15);
    y = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fC0, 15);
    func_0218A0F4((u8 *)a, ((int *)&t)[r6], x, y, r7);
    return ((struct Obj10184 *)b)->fC4;
}







int func_02189620(u8 *a, u8 *b)
{
    func_02189640((struct Cursor *)a, (int)b, 2); return ((struct Obj21966 *)b)->fC4;
}







int func_02189630(u8 *a, u8 *b)
{
    func_02189640((struct Cursor *)a, (int)b, 3); return ((struct Obj21967 *)b)->fC4;
}








int func_02189640(struct Cursor *a, int b, int c) {
    int r;
    int t;
    r = VM_GetU32(a);
    t = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)(*(u8 * *)&((struct Obj21968 *)b)->fC0), 0xb);
    return func_0218A0F4((u8 *)a, c, t, 1, r);
}








int func_02189668(struct Cursor *a, int b) {
    int r;
    r = VM_GetU32(a);
    func_0218A0F4((u8 *)a, 2, ((u8 *)b)[0x94] & 1, ((u8 *)b)[0x95] & 1, r);
    return ((struct Obj10185 *)b)->fC4;
}








int func_02189694(struct Cursor *a, int b) {
    int r;
    u8 k;
    int t;
    int p;
    u8 s;
    r = VM_GetU32(a);
    k = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r);
    p = BTL_POKEPARAM_GetTypePair(func_0218A2FC((u8 *)b, s));
    if (k == BTLV_CORE_GetHighByte(p) || k == BTLV_CORE_GetLowByte(p)) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13664 *)b)->f38 = t;
    return ((struct Obj13664 *)b)->fC4;
}








int func_021896E0(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    u8 s;
    r = VM_GetU32(a);
    r2 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r);
    t = func_0218A220((u8 *)b, r, s);
    if (t == r2) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13665 *)b)->f38 = t;
    return ((struct Obj13665 *)b)->fC4;
}








int func_02189718(struct Cursor *a, int b) {
    int r7;
    int r6;
    u8 *t;
    u8 s;
    r7 = VM_GetU32(a);
    r6 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r7);
    t = func_0218A2FC((u8 *)b, s);
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)t, 13)) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r6);
    }
    return ((struct Obj21969 *)b)->fC4;
}








int func_02189758(struct Cursor *a, int b) {
    int r0;
    int r6;
    int r7;
    u8 *t;
    u8 s;
    r0 = VM_GetU32(a);
    r6 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r0);
    t = func_0218A2FC((u8 *)b, s);
    if (r6 == BTL_POKEPARAM_GetItem((struct QI *)t)) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21970 *)b)->fC4;
}








int func_0218979C(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    r = VM_GetU32(a);
    r2 = VM_GetU32(a);
    t = BTL_FIELD_GetStaticSlotObject(r);
    func_0218A0F4((u8 *)a, 2, t, 1, r2);
    return ((struct Obj21971 *)b)->fC4;
}








int func_021897CC(struct Cursor *a, int b) {
    int r6;
    int r4;
    int t;
    r6 = VM_GetU32(a);
    r4 = VM_GetU32(a);
    t = func_0218A160((u8 *)b, r6);
    t = BTL_SERVER_FLOW_GetSideEffectEntry(((struct Obj10186 *)b)->fB4, t, r4);
    ((struct Obj10186 *)b)->f38 = t;
    return ((struct Obj10186 *)b)->fC4;
}








int func_02189800(struct Cursor *a, int b) {
    int r4;
    int x;
    u8 y;
    int r5;
    int t;
    r4 = VM_GetU32(a);
    x = VM_GetU32(a);
    y = func_0218A160((u8 *)b, r4);
    r5 = BTL_MAIN_GetSlotClientIdThunk((char *)(((struct Obj07925 *)b)->fB0), y);
    r4 = (int)BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj07925 *)b)->fB8, r5);
    r5 = BTL_MAIN_GetPositionsPerClientThunk((void *)(((struct Obj07925 *)b)->fB0), r5);
    for (; r5 < BTL_SLOT_GetCount((struct Q1 *)r4); r5++) {
        if (BTL_POKEPARAM_IsFainted(func_0218A308((void *)r4, (u8)r5)) == 0) {
            t = BTL_POKEPARAM_GetHpRatioFixed((struct Rat *)func_0218A2FC((u8 *)b, y));
            if (func_0218A0F4((u8 *)a, 0, t, 100, x) != 0) {
                break;
            }
        }
    }
    return ((struct Obj07925 *)b)->fC4;
}







/*
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int func_0218989C(struct Cursor *a, int b)
{
    int x, z, n;
    char *p;
    int i, j;
    u8 y;
    x = VM_GetU32(a);
    z = VM_GetU32(a);
    y = func_0218A160((u8 *)b, x);
    n = BTL_MAIN_GetSlotClientIdThunk((char *)(((struct Obj07926 *)b)->fB0), y);
    p = BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj07926 *)b)->fB8, n);
    i = BTL_MAIN_GetPositionsPerClientThunk((void *)(((struct Obj07926 *)b)->fB0), n);
    for (; i < BTL_SLOT_GetCount((struct Q1 *)p); i++) {
        if (BTL_POKEPARAM_IsFainted(func_0218A308(p, (u8)i)) == 0) {
            for (j = 0; j < BTL_POKEPARAM_GetMoveCount((struct QG *)func_0218A2FC((u8 *)b, y)); j++) {
                if (func_0218A0F4((u8 *)a, 3, BTL_POKEPARAM_GetMovePPLost(func_0218A2FC((u8 *)b, y), j), 0, z) != 0)
                    break;
            }
            if (j != BTL_POKEPARAM_GetMoveCount((struct QG *)func_0218A2FC((u8 *)b, y)))
                break;
        }
    }
    return ((struct Obj07926 *)b)->fC4;
}








int func_02189978(struct Cursor *a, int b) {
    int r;
    u8 t;
    int s;
    r = VM_GetU32(a);
    t = func_0218A160((u8 *)b, r);
    ((struct Obj10187 *)b)->f38 = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, t), 0x13) == 0) {
        s = BTL_POKEPARAM_GetItem((struct QI *)func_0218A2FC((u8 *)b, t));
        ((struct Obj10187 *)b)->f38 = func_0218A3F4(b, (u16)s, 10);
    }
    return ((struct Obj10187 *)b)->fC4;
}







int func_021899C4(u8 *a, u8 *b)
{
    ((struct Obj07927 *)b)->f38 = BTL_POKEPARAM_GetMovePPChecked(((struct Obj07927 *)b)->fBC, b[1]); return ((struct Obj07927 *)b)->fC4;
}








int func_021899DC(struct Cursor *a, int b) {
    int r4;
    int r7;
    u8 t;
    u8 *s;
    r4 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    t = func_0218A160((u8 *)b, r4);
    s = func_0218A2FC((u8 *)b, t);
    if (func_021D5478((struct Work *)s) >= BTL_POKEPARAM_GetMoveCount((struct QG *)s) && BTL_POKEPARAM_GetMoveCount((struct QG *)s) > 1) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21972 *)b)->fC4;
}







int func_02189A2C(u8 *a, u8 *b)
{
    ((struct Obj10188 *)b)->f38 = func_0218A378(b, ((struct Obj10188 *)b)->f2, 2); return ((struct Obj10188 *)b)->fC4;
}








int func_02189A44(int a, int b) {
    int t;
    t = BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)(*(u8 * *)&((struct Obj10189 *)b)->fC0));
    if (t != 0) {
        t = func_0218A378((void *)b, t, 2);
    } else {
        t = 0;
    }
    ((struct Obj10189 *)b)->f38 = t;
    return ((struct Obj10189 *)b)->fC4;
}








int func_02189A6C(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_SERVER_FLOW_CountFasterPokes((u8 *)(((struct Obj10190 *)b)->fB4), func_0218A2FC((u8 *)b, s), 1);
    ((struct Obj10190 *)b)->f38 = t;
    return ((struct Obj10190 *)b)->fC4;
}








/*
 *           unlabelled Thumb leaf in ov093 (it sits in a .word run in the
 *           ov093 listing), so neither `label` nor `sole-ref/code` can attest
 *           it, and the call at 0x02189AB4 is its only referrer image-wide.
 */
int func_02189A9C(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetTurnCount((int *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13666 *)b)->f38 = t;
    return ((struct Obj13666 *)b)->fC4;
}








/*
 * Lever: the second parameter is a struct pointer (see 02189B78).
 */
int func_02189AC0(struct Cursor *a, Obj_02189AC0 *b) {
    int c;
    int x;
    int r4;
    char *r7;
    u8 *r6;
    u32 base;
    c = VM_GetU32(a);
    x = VM_GetU32(a);
    r4 = BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, b->f94);
    r7 = BTL_SIDE_GetSlotOfClientThunk(b->fb8, r4);
    r4 = BTL_MAIN_GetPositionsPerClientThunk((void *)b->fb0, r4);
    base = func_0218A390((u8 *)((int)b), b->fbc, b->fc0, c);
    for (; r4 < BTL_SLOT_GetCount((struct Q1 *)r7); r4++) {
        r6 = func_0218A308(r7, (u8)r4);
        BTL_POKEPARAM_GetPokeId(r6);
        if (BTL_POKEPARAM_IsFainted(r6) == 0) {
            if (func_0218A390((u8 *)((int)b), r6, b->fc0, c) > base) {
                VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + x);
                break;
            }
        }
    }
    return b->fc4;
}








/*
 * Lever: the second parameter is a struct pointer; with an int base the
 * loop-invariant b+0xbc/b+0xc0 addresses were hoisted and b spilled.
 */
int func_02189B78(struct Cursor *a, Obj_02189B78 *b) {
    int r;
    int i;
    int c6;
    int c7;
    int c2;
    r = VM_GetU32(a);
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
        c6 = BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i);
        c7 = BTL_POKEPARAM_GetPokeId(b->fbc);
        c2 = BTL_POKEPARAM_GetPokeId(b->fc0);
        if ((u32)(BTL_SERVER_FLOW_CalcMoveTypeEffectiveness((u8 *)b->fb4, c7, c2, c6) - 4) <= 1) {
            VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r);
            break;
        }
    }
    return b->fc4;
}








int func_02189BFC(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int t2;
    u8 *v;
    unsigned int w;
    int x;
    u8 y;
    u8 z;
    unsigned int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    v = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0));
    w = func_0218A390((u8 *)b, *(u8 * *)&((struct Obj06344 *)b)->fBC, *(u8 * *)&((struct Obj06344 *)b)->fC0, t1);
    x = BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)v);
    y = BTL_POKEPARAM_GetPokeId(v);
    z = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06344 *)b)->fC0);
    r = BTL_SERVER_FLOW_CalcPredictedMoveDamage((u8 *)(((struct Obj06344 *)b)->fB4), y, z, x, 1, t1);
    if (w < r)
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + t2);
    return ((struct Obj06344 *)b)->fC4;
}








/*
 * Lever: the second parameter is a struct pointer (fields at 0x38, 0xc4);
 * with an int base and a local `int *p = b + 0x38` the store/adds order and
 * the r4/r5 roles were wrong.
 */
int func_02189C8C(struct Cursor *a, Obj_02189C8C *b) {
    u8 s;
    int v;
    u32 i;
    Seven t;
    s = func_0218A160((u8 *)b, VM_GetU32(a));
    t = d_0218A58C;
    i = 0;
    b->f38 = 0;
    for (; i < 7; i++) {
        v = func_021D59B4(func_0218A2FC((u8 *)b, s), t.v[i]);
        if (v > 6) {
            b->f38 += v - 6;
        }
    }
    return b->fc4;
}












/*
 * func_02189D30, func_02189D38 and func_02189D40 are the unlabelled
 * return-field stubs after the lead function (function_starts seeds).
 * The unit ends at 0x02189D48, where the next function starts.
 */
int func_02189CEC(struct Cursor *a, int b) {
    int r6;
    int r4;
    u8 s;
    u8 *t;
    int x;
    r6 = VM_GetU32(a);
    r4 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r6);
    t = func_0218A2FC((u8 *)b, s);
    x = func_021D59B4(t, r4);
    ((struct Obj10192 *)b)->f38 = x - func_021D59B4(*(u8 * *)&((struct Obj10192 *)b)->fBC, r4);
    return ((struct Obj10192 *)b)->fC4;
}












int func_02189D30(int a, int b) {
    return ((struct Obj21973 *)b)->fC4;
}












int func_02189D38(int a, int b) {
    return ((struct Obj21974 *)b)->fC4;
}












int func_02189D40(int a, int b) {
    return ((struct Obj21975 *)b)->fC4;
}











/*
 * 2026-10-05 (wD5 lane16): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 position arguments (a, b), and x, y, z are
 *   u8 locals (BTL_POKEPARAM_GetPokeId returns u8). That moves the `adds r1,rX` before the y reload at both calls.
 *   The ov093 callee also compiles EXACT with `u8 a, u8 b` (scratch test only, file not changed).
 */
u32 func_02189D48(struct Cursor *a, u8 *p)
{
    int t, k;
    u8 x, z;
    u8 *g;
    int j, sel;
    u8 y;
    u32 best;
    int n;
    t = VM_GetU32(a);
    k = BTL_MAIN_GetSlotClientIdThunk((char *)(*(u8 **)(p + 0xB0)), p[0x94]);
    g = (u8 *)BTL_SIDE_GetSlotOfClientThunk(*(char **)(p + 0xB8), k);
    n = BTL_MAIN_GetPositionsPerClientThunk(*(u8 **)(p + 0xB0), k);
    sel = BTL_SLOT_FindPoke(g, (u32)(*(u8 **)(p + 0xBC)));
    x = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xBC));
    y = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xC0));
    best = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    if (sel < 0 || best == 0) {
        *(u32 *)(p + 0x38) = 0;
        return *(u32 *)(p + 0xC4);
    }
    for (j = 0; j < n; j++) {
        u8 *m = func_0218A308(g, (u8)j);
        z = BTL_POKEPARAM_GetPokeId(m);
        if (BTL_POKEPARAM_IsAbleToBattle(m) != 0 && j != sel) {
            int i;
            *(u32 *)(p + 0x38) = 2;
            for (i = 0; i < (int)BTL_POKEPARAM_GetMoveCount((struct QG *)m); i++) {
                u16 c = BTL_POKEPARAM_GetMoveId(m, (u8)i);
                if (i != p[1]) {
                    u32 r = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), z, y, c, 1, t);
                    if (r > best) {
                        *(u32 *)(p + 0x38) = 1;
                        break;
                    }
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}











int func_02189E70(struct Cursor *a, u8 *b)
{
    func_02189E90(a,b,2); return ((struct Obj21976 *)b)->fC4;
}











int func_02189E80(struct Cursor *a, u8 *b)
{
    func_02189E90(a,b,3); return ((struct Obj21977 *)b)->fC4;
}












int func_02189E90(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    t = VM_GetU32(a);
    n = VM_GetU32(a);
    return func_0218A0F4((u8 *)a, c, BTL_POKEPARAM_IsFainted(func_0218A2FC(b, func_0218A160(b, t))), 1, n);
}











int func_02189ED0(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = VM_GetU32(a); s = func_0218A160(b,t); ((struct Obj13667 *)b)->f38 = func_021D59B4(func_0218A2FC(b,s),17); return ((struct Obj13667 *)b)->fC4;
}











int func_02189EF8(struct Cursor *a, u8 *b)
{
    int t; u32 n; u8 s; t = VM_GetU32(a); n = VM_GetU32(a); s = func_0218A160(b,t); if (BTL_POKEPARAM_HasSubstitute(func_0218A2FC(b,s))) VM_Jump((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + n); return ((struct Obj21978 *)b)->fC4;
}











int func_02189F34(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = VM_GetU32(a); s = func_0218A160(b,t); ((struct Obj13668 *)b)->f38 = BTL_POKEPARAM_GetSpecies((struct QF *)func_0218A2FC(b,s)); return ((struct Obj13668 *)b)->fC4;
}











int func_02189F58(u8 *a, u8 *b)
{
    func_02189F98(a,b,0); return ((struct Obj21979 *)b)->fC4;
}











int func_02189F68(unsigned char *a, unsigned char *b) { func_02189F98(a,b,1); return ((struct Obj21980 *)b)->fC4; }











int func_02189F78(unsigned char *a, unsigned char *b) { func_02189F98(a,b,2); return ((struct Obj21981 *)b)->fC4; }











int func_02189F88(unsigned char *a, unsigned char *b) { func_02189F98(a,b,3); return ((struct Obj21982 *)b)->fC4; }











/*
 * Two-byte zero alignment padding follows the compiled function.
 */
int func_02189F98(unsigned char *a, unsigned char *b, int c) { int x,y; x=VM_GetU32((struct Cursor *)a); y=VM_GetU32((struct Cursor *)a); return func_0218A0F4(a,c,((struct Obj21983 *)b)->fCC,x,y); }












int func_02189FC0(struct Cursor *a, u8 *b)
{
    int t;
    int u;
    int w;
    u16 *base;
    int m;
    int flag;
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    w = VM_GetU32(a);
    base = (u16 *)(*(u8 * *)&((struct Obj00005 *)a)->f14 + w);
    flag = 0;
    if (t == 0) {
        m = func_0218A378(b, ((struct Obj13669 *)b)->f2, 0x1c) * 2;
        if (m / 2 > u)
            flag = 1;
    } else {
        flag = 1;
    }
    if (flag == 1)
        return func_021895AC((u8 *)a, b);
    VM_Jump((struct Cur *)a, (u32)((u8 *)base + (base[m] | (base[m + 1] << 16))));
    return ((struct Obj13669 *)b)->fC4;
}











int func_0218A034(struct Cursor *a, u8 *b)
{
    int t;
    int n;
    t = VM_GetU32(a);
    n = VM_GetU32(a);
    if (BTL_SERVER_FLOW_CheckFieldEffectActive(((struct Obj13671 *)b)->fB4, func_0218A160(b, t), 3) != 0)
        VM_Jump((struct Cur *)a, (u32)(*(u8 * *)&((struct Obj00005 *)a)->f14 + n));
    return ((struct Obj13671 *)b)->fC4;
}










int func_0218A074(struct Cursor *a, unsigned char *b) { func_0218A0A4(a,b,0); return ((struct Obj21984 *)b)->fC4; }










int func_0218A084(struct Cursor *a, unsigned char *b) { func_0218A0A4(a,b,1); return ((struct Obj21985 *)b)->fC4; }










int func_0218A094(struct Cursor *a, unsigned char *b) { func_0218A0A4(a,b,2); return ((struct Obj21986 *)b)->fC4; }










int func_0218A0A4(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    u8 s;
    t = VM_GetU32(a);
    n = VM_GetU32(a);
    s = func_0218A160(b, t);
    func_021D59B4(func_0218A2FC(b, s), 8);
    return func_0218A0F4((u8 *)a, c, s, func_021D59B4(func_0218A2FC(b, s), 10), n);
}










int func_0218A0F4(u8 *a, int op, int x, int y, int z)
{
    int r = 0;
    switch (op) {
    case 0:
        if (x < y)
            r = 1;
        break;
    case 1:
        if (x > y)
            r = 1;
        break;
    case 2:
        if (x == y)
            r = 1;
        break;
    case 3:
        if (x != y)
            r = 1;
        break;
    case 4:
        if (x & y)
            r = 1;
        break;
    case 5:
        if (!(x & y))
            r = 1;
        break;
    case 6:
        if (x <= y)
            r = 1;
        break;
    case 7:
        if (x >= y)
            r = 1;
        break;
    }
    if (r == 1)
        VM_Jump((struct Cur *)a, (u32)(*(u8 * *)&((struct Obj00005 *)a)->f14 + z));
    return r;
}








u8 func_0218A160(u8 *p, int k)
{
    u32 v;
    switch (k) {
    case 1:
        return p[0x94];
    default:
    case 0:
        return p[0x95];
    case 3:
        switch (*(int *)&((struct Obj00067 *)p)->f98) {
        case 0:
        case 3:
            return p[0x94];
        case 1:
            return 2 ^ p[0x94];
        case 2:
            v = (u32)p[0x94] >> 1;
            if (v != 2)
                v = v + 1;
            else
                v = 1;
            return BTL_MAIN_GetOwnLanePos(p[0x94], (u8)v);
        }
        break;
    case 2:
        switch (*(int *)&((struct Obj00067 *)p)->f98) {
        case 0:
        case 3:
            return p[0x95];
        case 1:
            return 2 ^ p[0x95];
        case 2:
            v = (u32)p[0x95] >> 1;
            if (v != 2)
                v = v + 1;
            else
                v = 1;
            return BTL_MAIN_GetOwnLanePos(p[0x95], (u8)v);
        }
        break;
    }
}














/*
 * 2026-10-04 (wave D2 lane 08): re-tested, still MATCH: 11 of 12 relocations resolve; the only open site is func_021F8AFC (+002E). The symbols line already carries 'thumb ov094', but the sole witness src/matched/ov/ov094_func_021F8AE8.c lists four 'function:' keys and the parser keeps only the last, so 0x021F8AFC has no witness. Fix belongs in that unit's header or the parser (outside this lane's write set); bytes are correct.
 * its parsed function list: four repeated keys leave only func_021F8B28.
 * Concrete bytes correct; caller-only tu suggest-split has no viable cut.
 * lever: advance p itself before indexed store; random draw helper owns
 * its u64 temporary and returns u32 (random-below-n existing idiom).
 */
int func_0218A220(u8 *p, int k, u8 slot)
{
    void *mon;
    int a, b;
    u32 x, y, z, n;
    u32 values[3];
    mon = (void *)func_0218A2FC(p, slot);
    if (BTL_POKEPARAM_HasSick(mon, 0x10) != 0)
        return 0;
    if (k == 0 || k == 2) {
        p += 0x7c;
        p[slot] = func_021F8AFC(slot);
        if (p[slot] != 0)
            return p[slot];
        a = func_021D59B4(mon, 0x10);
        if (a == 0x17 || a == 0x2a || a == 0x47)
            return a;
        a = BTL_POKEPARAM_GetSpecies(mon);
        b = func_021D59B4(mon, 0x13);
        n = 0;
        x = func_02019C90(a, b, 0x1a);
        y = func_02019C90(a, b, 0x1b);
        z = func_02019C90(a, b, 0x1c);
        if (x != 0) values[n++] = x;
        if (y != 0) values[n++] = y;
        if (z != 0) values[n++] = z;
        return values[draw_below(n)];
    }
    return func_021D59B4(mon, 0x10);
}








/*
 * Resolved by the BTL_SIDE_GetPokeAtPos label in ov069 (thumb); cross-overlay target.
 */
u8 *func_0218A2FC(u8 *p, u8 i) { return BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00067 *)p)->fB8, i); }









/*
 * Resolved by the matched BTL_SLOT_GetPokeParam in ov093 (thumb); cross-overlay target.
 */
u8 *func_0218A308(void *p, u32 i) { return BTL_SLOT_GetPokeParam(p, i); }









void func_0218A310(unsigned int a) { int i; for(i=0;i<4;i++) *(int *)(a + (unsigned)i*4+4)=*(int *)(a + (unsigned)i*4+0x14); }










void func_0218A324(u8 *p)
{
    u8 *s;
    int i;
    u16 h;
    s = func_0218A2FC(p, p[0x95]);
    for (i = 0; i < 4; i++) {
        h = *(u16 *)(p + p[0x95] * 8 + i * 2 + 0x4c);
        if (h == BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)s))
            return;
        if (h == 0) {
            *(u16 *)(p + p[0x95] * 8 + 0x4c + i * 2) =BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)s);
            return;
        }
    }
}









int func_0218A378(void *a, int b, int c) { return WAZA_TOOL_GetParam(b, c); }









int func_0218A384(void *a, int b, int c) { return WAZA_TOOL_GetFlag(b, c); }









/*
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes, size 98 vs 100). Image order in the loop call: str r7,[sp,#4]; ldr r0,[sp,#8]; ldr r1,[sp,#0x10]; adds r0,#0xb4; ldr r0,[r0]; ldr r2. Ours loads a first, then the field, then x. Also tried const-qualified first parameter (callee and function) and a split pointer/xx copy; the compiler folds them back.
 * note: 2026-10-04 Residue: store order only. Original stores the stack arg d ([sp,#4]) before reloading spilled a ([sp,#8]) for the first call argument; ours loads a first. Tried: struct field, ptr casts, local hoist, u32/int d, u16 callee return, while loop, temp for the 54C0 result.
 * note: 2026-10-05 (wD4 lane20): tried the first argument and the 54C0 result as separate locals before the call (c = f(b,i); q = *(a+0xB4); g(q,x,y,c,1,d)) and a u32 first parameter; same 10 bytes (ldr r0,[sp,#8] still ahead of str r7,[sp,#4]).
 * 2026-10-05 (wD5 lane20): no new variant closed it. Reading: original emits the stack argument store (str r7,[sp,#4]) before the spilled-a reload and the field address chain; ours starts the chain first. Same 10 bytes as before; the sibling func_02188D5C shows the same tie-break in its loop call, so a common cause (IR order of stack-argument stores versus argument 0) is likely.
 * 2026-10-05 (wD6 lane15): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 a, u8 b (as in matched func_02189D48)
 *   and x, y are u8 locals; that fixes the stack-argument store order in the loop call.
 */
u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d)
{
    u32 best = 0;
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    u8 y = BTL_POKEPARAM_GetPokeId(c);
    int i;
    for (i = 0; i < (int)BTL_POKEPARAM_GetMoveCount((struct QG *)b); i++) {
        u32 r = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(a + 0xB4), x, y, (u32)BTL_POKEPARAM_GetMoveId(b, (u8)i), 1, d);
        if (r > best)
            best = r;
    }
    return best;
}










/*
 * The apparent register-scheduling residue was a missing third argument:
 *   the image keeps `b` (r1) live and loads the halfword into r2, which is
 *   only possible if the callee takes (field, b, h).  func_02020F20 is
 *   declared with the extra `int` argument and the call passes `b`.
 *   EXACT* because the follower at 0x0218A41A is an unlabelled `movs r0,r0`
 *   pad.
 */
int func_0218A3F4(int a, int b, int c) {
    u16 h;
    int p;
    int q;
    h = ((struct Obj13672 *)a)->fA0;
    p = func_02020F20(((struct Obj13672 *)a)->fA8, b, h);
    q = func_02021014((struct Rec *)p, c);
    func_020307B0((void *)p);
    return q;
}









void func_0218A41C(unsigned int a) { int i; if(D_0218A7C0==0) { D_0218A7C0=func_02030734(a,24,1,D_0218A7A0,3999); for(i=0;i<4;i++) D_0218A7C0->id[i]=255; } }









void func_0218A458(void) { int i; int zero; if(D_0218A7C0!=0) { zero=0; for(i=0;i<4;i++) { if(D_0218A7C0->obj[i]!=0) { func_020307B0(D_0218A7C0->obj[i]); D_0218A7C0->obj[i]=(void *)zero; } } func_020307B0(D_0218A7C0); D_0218A7C0=0; } }










void *func_0218A494(u8 *a)
{
    int i;
    u32 x;

    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == a[0x45]) {
            D_0218A7C0->ref[i]++;
            return D_0218A7C0->obj[i];
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == 0xff)
            break;
    }
    if (a[0x45] == 2)
        x = (u16)((((struct Obj04408 *)a)->fA0 & 0x7fff) | 0x8000);
    else
        x = ((struct Obj04408 *)a)->fA0;
    D_0218A7C0->id[i] = a[0x45];
    D_0218A7C0->ref[i]++;
    D_0218A7C0->obj[i] = ARC_TOOL_LoadHandleMember(((struct Obj04408 *)a)->fA4, a[0x45], (u16)x);
    return D_0218A7C0->obj[i];
}

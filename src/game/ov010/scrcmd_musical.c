/*
 * file:     scrcmd_musical.c
 * unit:     yes
 * function: func_0215D34C, func_0215D468, func_0215D504, func_0215D7D4, func_0215D864, func_0215D884, func_0215DADC, func_0215DB00, func_0215DB38, func_0215DDC8, func_0215DE0C, func_0215DE38, func_0215DE44, func_0215DE58, func_0215DEF0, func_0215DF6C, func_0215DF78, func_0215DFB4, func_0215E010, func_0215E068, func_0215E0B0, func_0215E0EC, func_0215E130, func_0215E184, func_0215E1C0, func_0215E2B8, func_0215E31C, func_0215E334, func_0215E33C, func_0215E34C, func_0215E358, func_0215E364, func_0215E3A0, func_0215E3E4, func_0215E404, func_0215E428, func_0215E440, func_0215E580, func_0215E5B0, func_0215E6A8, func_0215E6F8, func_0215E724, func_0215E740, func_0215E7DC, func_0215E804, func_0215E840, func_0215EA14, func_0215EA30, func_0215EA38, func_0215EA58, func_0215EA6C, func_0215EA94, func_0215EAC8, func_0215EAF0, func_0215EB18, func_0215EB4C, func_0215EB60, func_0215EB88, func_0215EBBC, func_0215EBD0, func_0215EBF8, func_0215EC2C
 * address:  0x0215D34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02155A98  0x02155A98  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02011290  0x02011290  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_02030734  0x02030734  arm
 *   func_0200A640  0x0200A640  thumb
 *   func_02014808  0x02014808  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021F675C  0x021F675C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021568E0  0x021568E0  thumb  ov010
 *   func_02156954  0x02156954  thumb  ov010
 *   func_02156978  0x02156978  thumb  ov010
 *   func_02156934  0x02156934  thumb  ov010
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_02156908  0x02156908  thumb  ov010
 *   func_0215699C  0x0215699C  thumb  ov010
 *   func_021569A4  0x021569A4  thumb  ov010
 *   func_021569EC  0x021569EC  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200A628  0x0200A628  thumb
 *   func_0200A644  0x0200A644  thumb
 *   func_0200A75C  0x0200A75C  thumb
 *   func_0200A780  0x0200A780  thumb
 *   func_0200A7A0  0x0200A7A0  thumb
 *   func_0200A7B8  0x0200A7B8  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   func_0200A7D4  0x0200A7D4  thumb
 *   func_0200A7E0  0x0200A7E0  thumb
 *   func_021F6744  0x021F6744  thumb  ov112
 *   func_0200A750  0x0200A750  thumb
 *   func_0200A6BC   0x0200A6BC  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   func_02156A3C  0x02156A3C  thumb  ov010
 *   func_02156AD4  0x02156AD4  thumb  ov010
 *   func_0200A7F8  0x0200A7F8  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0215A168 0x0215A168 thumb ov010
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_02012124  0x02012124  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021FCDEC  0x021FCDEC  thumb  ov132
 *   func_021FDA6C  0x021FDA6C  thumb  ov132
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 *   GAME_DATA_SetExternalWork  0x02012F74  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   func_020307B0  0x020307B0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021FC644  0x021FC644  thumb  ov132
 *   func_021FC684  0x021FC684  thumb
 *   func_020124E4 0x020124E4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012374 0x02012374 thumb
 *   func_02026454 0x02026454 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020121CC 0x020121CC thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_02172724     0x02172724  data
 *   func_021FC81C  0x021FC81C  thumb
 *   func_021CD688  0x021CD688  thumb
 *   func_021FC804  0x021FC804  thumb
 *   func_021CD5A4  0x021CD5A4  thumb
 *   func_021FCE00  0x021FCE00  thumb
 *   func_021FD844  0x021FD844  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021FD910  0x021FD910  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009370  0x02009370  thumb
 *   func_021B76F8  0x021B76F8  thumb  ov021
 *   func_021B7794  0x021B7794  thumb  ov021
 *   func_021B76B4  0x021B76B4  thumb  ov021
 *   func_021B7740  0x021B7740  thumb  ov021
 *   func_0201EF5C  0x0201EF5C  thumb
 *   ZONEDATA_GetEncountId  0x02013EC0  thumb
 *   func_020493D4  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204944C  0x0204944C  arm
 *   d_02172928 0x02172928 data a1
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA7DC  0x021AA7DC  thumb
 *   func_02012A38  0x02012A38  thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200D488 0x0200D488 thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D478 0x0200D478 thumb
 *   d_021711C6 0x021711C6 data a2
 *   func_0200D45C  0x0200D45C  thumb
 *   func_0200D50C  0x0200D50C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200D470  0x0200D470  thumb
 *   d_0217293C     0x0217293C  data
 *   func_0200D468 0x0200D468 thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200D494  0x0200D494  thumb
 *   func_0200D480  0x0200D480  thumb
 *   func_020113D8 0x020113D8 thumb
 *   d_021711A8 0x021711A8 data ov010 a2
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3250  0x021A3250  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021A3504  0x021A3504  thumb  ov021
 *   func_021A3524  0x021A3524  thumb  ov021
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0215F118  0x0215F118  thumb  ov010
 *   ZONEDATA_IsFlyEnabled  0x02013C40  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   ZONEDATA_IsRawZoneF6  0x0201400C  thumb
 *   ZONEDATA_IsRawZoneF7  0x02014018  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_02012B70  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 *   func_0215F088  0x0215F088  thumb  ov010
 *   func_0215F0B8  0x0215F0B8  thumb  ov010
 *   func_0215F104  0x0215F104  thumb  ov010
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_02159058 0x02159058 thumb ov010
 *   func_021C6078 0x021C6078 thumb ov021
 */

/*
 * This file holds three original source files back to back (cuts proposed in
 * the lane notes): scrcmd_musical.c (script commands for the musical link,
 * up to 0x0215E1C0), field_encount_st.c (0x0215E2B8..0x0215E34C, string
 * "field_encount_st.c" at 0x02172928) and move_pokemon.c (from 0x0215E358,
 * string "move_pokemon.c" at 0x0217293C): the two roaming legendaries and
 * the field skill (hidden move) checks and events.
 */

struct ScriptVm;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GameComm;
struct FieldMap;
struct MyStatus;
struct SaveControl;
struct ScriptCtl;
struct ScriptWork;
struct MusicalEvent;
struct MusicalSave;
struct WordSet;
struct MsgData;
struct Strbuf;
struct PokeParty;
struct Pokemon;
struct ArcFile;
struct EventWork;
struct BgmInfo;
struct FieldPlayer;
struct MapObject;
struct ZoneEncounter;
struct MoveModelSys;
struct WifiList;
struct MovePokemonSave;
struct MovePokemonEntry;
struct FieldSkillInfo;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef signed int s32;

typedef unsigned long long u64;

typedef s32 fx32;

typedef enum { FALSE, TRUE } BOOL;

/* Script VM (see ica_anime.c): command handlers get the VM and the user work. */
#include "../arm9/script_vm_types.h"

/* Event task callback: (task, state, work). */
typedef int (*EventTaskFn)(struct GameEvent *task, u32 *state, void *work);

typedef void (*SubProcCallback)(void *callbackArg);

/* Musical save block 0x2A (0x2A4 bytes), layout from mystery_data.c. */
typedef struct MusicalOutfit {
    u8 pokeSlot;                          /* 10: none */
    u8 props[5];
} MusicalOutfit;

typedef struct MusicalProgram {
    u8 state;                             /* 4: initial */
    u8 data[3];
} MusicalProgram;

/* The first word of the musical save block (what func_0200A640 points at). */
typedef struct MusicalHeadBits {
    u32 showcaseMonsNo : 16;
    u32 shotState : 5;
    u32 showcaseFlags : 11;
} MusicalHeadBits;

/* script command 0x0215D7D4 reads a program slot as {state, rank, score}. */
typedef struct MusicalProgramView {
    u8 state;
    u8 rank;
    u16 score;
} MusicalProgramView;

/* Link work hung on the game data external-work slot (0x38 bytes). */
typedef struct MusicalLinkWork {
    struct MusicalEvent *musicalEvent;    /* 0x00 */
    void *session;                        /* 0x04: ov132 comm session */
    u32 entryMenu;                        /* 0x08: comm entry menu handle */
    struct GameData *gameData;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 procMode;                         /* 0x28: 9 or 10 for the ov100 proc */
    u32 procWork;                         /* 0x2C */
    u16 *resultOut;                       /* 0x30: script variable receiving the result */
    u16 memberCount;                      /* 0x34 */
} MusicalLinkWork;

/* Wait context for the ov100 proc callback. */
typedef struct MusicalLinkWait {
    struct ScriptWork *scriptWork;
    MusicalLinkWork *link;
} MusicalLinkWait;

/* Task work of StartMusical. */
typedef struct MusicalStartTask {
    struct GameEvent *musicalSeq;         /* 0x00: musical link sequence event */
    MusicalLinkWork *link;                /* 0x04 */
    u32 mode;                             /* 0x08 */
} MusicalStartTask;

/* Arguments of the ov112 proc started by StartMusical (mode 2 and up). */
typedef struct MusicalProcArgs {
    u32 startMode;                        /* 0x00 */
    u32 isOffline;                        /* 0x04 */
    MusicalHeadBits *saveBits;            /* 0x08 */
} MusicalProcArgs;

typedef struct MusicalProcBox {
    MusicalProcArgs *args;
} MusicalProcBox;

/* Arguments handed to the musical system proc of ShowPartyMonMusical. */
typedef struct MusicalSystemArgs {
    u32 startMode;                        /* 0x00 */
    u32 musicalSystem;                    /* 0x04: result of MUSICAL_SYSTEM_Create */
    u32 musicalSave;                      /* 0x08 */
} MusicalSystemArgs;

typedef struct MusicalSystemTask {
    MusicalSystemArgs *args;
} MusicalSystemTask;

/* Reads the 0xE8-byte encounter table row of a zone. */
typedef struct EncountRow {
    u8 data0[7];
    u8 flags;                             /* 0x07: 0x80 set after load */
} EncountRow;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

/* Roaming legendary table (save block 0x38): see arm9 unit_0200C7C0.c. */
typedef struct RoamLocationLinks {
    u16 count;
    u8 next[4];
} RoamLocationLinks;

/* Work of the move_pokemon battle-result hook (battle setup, fields used here). */
typedef struct BattleResultWork {
    int resultKind0;                      /* 0x00 */
    int resultKind1;                      /* 0x04 */
    u8 pad08[0x8C - 0x08];
    int battleResult;                     /* 0x8C */
} BattleResultWork;

/* Field skill (hidden move) context filled by func_0215E840 (0x14 bytes). */
typedef struct FieldSkillInfo {
    u16 zoneId;                           /* 0x00 */
    u16 usableMask;                       /* 0x02: bit per skill */
    u32 playerState;                      /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    struct MapObject *playerObj;          /* 0x0C */
    struct FieldMap *fieldMap;            /* 0x10 */
} FieldSkillInfo;

/* Object returned by func_02188CE8 (field map, offset 0x90). */
typedef struct EffectEncountObj {
    u8 pad00[0x10];
    int encountParam;                     /* 0x10 */
} EffectEncountObj;

/* Field gimmick work (func_02012A38). */
typedef struct FieldGimmickWork {
    u8 pad00[0x0C];
    u32 state;                            /* 0x0C */
} FieldGimmickWork;

typedef struct SkillTarget {
    u16 id;                               /* 0x00 */
    u16 variant;                          /* 0x02 */
    u32 targetObj;                        /* 0x04 */
} SkillTarget;

typedef struct SkillEventWork {
    u32 magic;                            /* 0x19740205 */
    struct MapObject *playerObj;          /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    SkillTarget target;                   /* 0x0C */
} SkillEventWork;

/* script work (ov010) */
extern struct ScriptCtl *func_0215A5F4(struct ScriptWork *scriptWork);
extern struct GameSystem *func_0215A5DC(struct ScriptWork *scriptWork);
extern struct GameData *func_0215A5E4(struct ScriptWork *scriptWork);
extern u16 func_0215A5CC(struct ScriptWork *scriptWork);
extern int func_02158F58(struct ScriptCtl *scriptCtl);
extern struct WordSet *func_02158F74(struct ScriptCtl *scriptCtl);
extern void func_0215897C(struct ScriptCtl *scriptCtl, struct GameEvent *task);
extern void func_0215898C(struct ScriptCtl *scriptCtl, struct GameEvent *task);
extern u16 func_02159B10(ScriptVm *vm, struct ScriptWork *scriptWork);
extern u16 *func_02159AE8(ScriptVm *vm, struct ScriptWork *scriptWork);
extern struct GameEvent *func_0215A168(struct GameSystem *gameSys, u16 *partyIndexVar, u16 *resultVar);
extern int func_021587B0(int scriptCtl, int scriptId, int arg1, int arg2);
extern int func_02159058(int scriptWork, int eventId, int arg1, int arg2, u16 arg3);

/* game system, game event, game data */
extern struct FieldMap *func_0201210C(struct GameSystem *gameSys);
extern struct GameData *func_020120F4(struct GameSystem *gameSys);
extern struct GameComm *func_02012138(struct GameSystem *gameSys);
extern void func_02012124(struct GameSystem *gameSys, u32 state);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSys, u32 procId, void *procData, void *procArg);
extern u32 GAMESYSTEM_GetProcStatus(struct GameSystem *gameSys);
extern u32 func_020121CC(struct GameSystem *gameSys);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSys, void *parent, EventTaskFn taskFn, u32 workSize);
extern void *func_020124E8(struct GameEvent *task);
extern struct GameSystem *func_020124E4(struct GameEvent *task);
extern void func_02012374(struct GameEvent *task, struct GameEvent *callee);
extern ScriptVm *func_02011290(ScriptVm *vm);
/* the wait callback receives the user work of the script command */
typedef int (*ScriptWorkWaitFn)(ScriptVm *vm, struct ScriptWork *scriptWork);
extern void func_020113D0(ScriptVm *vm, ScriptWorkWaitFn waitFn);
extern void *GAME_DATA_GetExternalWork(struct GameData *gameData);
extern void GAME_DATA_SetExternalWork(struct GameData *gameData, void *externalWork);
extern struct MusicalSave *GAME_DATA_GetSaveBlock2A(struct GameData *gameData);
extern struct PokeParty *func_02012934(struct GameData *gameData);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct BgmInfo *func_02012A30(struct GameData *gameData);
extern struct FieldGimmickWork *func_02012A38(struct GameData *gameData);
extern u8 func_02012984(struct GameData *gameData);
extern u16 func_02012AC8(void *playerWork);
extern void *func_020127A4(struct GameData *gameData);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern struct MoveModelSys *func_02012B38(struct GameData *gameData);
extern int func_02012B70(struct GameData *gameData);
extern u32 func_020113D8(u32 season);
extern u16 func_02014470(struct MoveModelSys *moveModelSys);
extern void *func_02014808(struct GameSystem *gameSys, struct FieldMap *fieldMap, u32 overlayId, const void *procData, void *procArg, SubProcCallback callback, void *callbackArg);

/* overlay loading, heap, string helpers */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *ptr);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(s32 overlayId);
extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern void func_02082BCC(void *dst, int value, int size);
extern u32 func_02005728(u32 range);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
extern void func_02045808(struct Strbuf *strbuf);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
extern u32 func_02045C04(struct MsgData *msgData);
extern void func_0201EE0C(struct WordSet *wordSet, u32 slot, const struct Strbuf *str, u32 grammar, u32 form, u32 count);
extern void func_0201EF5C(struct WordSet *wordSet, u32 slot, u32 value);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dest);

/* musical save block */
extern struct MusicalOutfit *func_0200A628(struct MusicalSave *musical);
extern MusicalHeadBits *func_0200A640(struct MusicalSave *musical);
extern u32 func_0200A644(struct MusicalSave *musical, u8 prop);
extern void func_0200A6BC(struct MusicalSave *musical, u32 prop);
extern MusicalProgram *func_0200A750(struct MusicalSave *musical, u32 index);
extern u16 func_0200A75C(struct MusicalSave *musical);
extern u16 func_0200A780(struct MusicalSave *musical);
extern u8 func_0200A7A0(struct MusicalSave *musical, u32 index);
extern u8 func_0200A7B8(struct MusicalSave *musical);
extern u8 func_0200A7C8(struct MusicalSave *musical);
extern void func_0200A7D4(struct MusicalSave *musical, u8 value);
extern u8 func_0200A7E0(struct MusicalSave *musical);
extern u8 *func_0200A7F8(struct MusicalSave *musical);

/* musical event (ov010 musical_dressup_sys.c) */
extern struct GameEvent *func_02155A98(struct GameSystem *gameSys, struct GameData *gameData, u8 arg, u32 mode, MusicalLinkWork *link);
extern u8 func_021568E0(struct MusicalEvent *event);
extern u16 func_02156954(struct MusicalEvent *event);
extern u16 func_02156978(struct MusicalEvent *event);
extern u8 func_02156934(struct MusicalEvent *event, u8 index);
extern int func_021568E8(int event, u8 index);
extern u8 func_02156908(struct MusicalEvent *event);
extern u8 func_0215699C(struct MusicalEvent *event, u8 index);
extern u8 func_021569A4(struct MusicalEvent *event, u8 index);
extern u8 func_021569EC(struct MusicalEvent *event, u8 index);
extern struct Strbuf *func_02156914(int player, int heapId);
extern void func_02156A3C(struct MusicalEvent *event, u8 index, struct WordSet *wordSet, u32 slot);
extern void func_02156AD4(struct MusicalEvent *event, u8 index, struct WordSet *wordSet, u32 slot);
extern int func_02156BAC(struct MusicalEvent *event);
extern u32 func_02156BCC(struct MusicalEvent *event);

/* party and musical system */
extern u32 func_0201AA18(struct PokeParty *party);
extern struct Pokemon *func_0201AB28(struct PokeParty *party, u32 index);
extern int func_021F6744(struct Pokemon *mon);
extern u32 func_021F675C(struct Pokemon *mon, int mode);
extern u32 func_02008530(struct MyStatus *myStatus);

/* ov132 comm session, ov021 comm entry menu */
extern u32 func_0200FB24(void);
extern u32 func_021CD48C(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_021FCDEC(int session, int memberCount);
extern unsigned char *func_021FDA6C(struct GameData *gameData);
extern u32 func_020307B0(void *ptr);
extern void func_021FC644(int mode, void *procArg, void *comm, int arg);
extern int func_021FC684(void *session);
extern u32 func_02026454(struct GameComm *comm);
extern u32 func_02026474(struct GameComm *comm);
extern int func_0203CDBC(void);
extern int func_021FC81C();
extern int func_021CD688();
extern int func_021FC804();
extern int func_021CD5A4();
extern int func_021FCE00();
extern int func_021FD844();
extern int func_021FD910();

/* wifilist and ov021 postman service */
extern struct WifiList *func_02009448(void *saveBlock);
extern u32 func_02009370(const struct WifiList *wifiList);
extern int func_021B76F8(struct GameData *gameData, int key, struct WifiList *wifiList);
extern void *func_021B7794(struct GameSystem *gameSys);
extern void func_021B76B4(struct GameData *gameData, int key, int wifiList);
extern void *func_021B7740(struct GameData *gameData, int key, struct WifiList *wifiList, int index);

/* move_pokemon: roaming legendary save (arm9 unit_0200C7C0.c) */
extern void *func_0200D418(struct SaveControl *save);
extern u8 func_0200D488(struct MovePokemonSave *block, u32 index);
extern struct MovePokemonEntry *func_0200D4AC(struct MovePokemonSave *block, u32 index);
extern u8 func_0200D478(struct MovePokemonSave *block, u32 index);
extern int func_0200D45C();
extern void func_0200D50C(struct MovePokemonEntry *entry, u32 field, u32 value);
extern u32 func_020173EC(void);
extern void func_02017588(struct Pokemon *mon, u16 species, u16 level, unsigned long long personalId, u32 power, unsigned long long rand);
extern u32 func_02017E1C(struct Pokemon *mon, u32 paramId, u32 buf);
extern void *func_0200CA10(struct SaveControl *save);
extern void func_0200CFA0(void *boxData, struct Pokemon *mon);
extern void func_0200D470(struct MovePokemonSave *block, u32 index, u32 state);
extern u8 func_0200D468(struct MovePokemonSave *block, u32 index);
extern void func_0200D494(struct MovePokemonEntry *entry);
extern void func_0200D480(struct MovePokemonSave *block, u32 index, u8 location);
extern u32 func_0200D4B8(const struct MovePokemonEntry *entry, u32 field);
extern void *BTL_SETUP_GetParty(BattleResultWork *work, int index);

/* field encounter and field objects (ov021, ov010) */
extern int ZONEDATA_GetEncountId(u32 zoneId);
extern struct EffectEncountObj *func_02188CE8(struct FieldMap *fieldMap);
extern int func_021AA7DC(struct EffectEncountObj *obj, int param);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void *func_02188C7C(struct FieldMap *fieldMap);
extern u32 func_021A3098(struct FieldPlayer *player);
extern struct MapObject *func_021A3250(struct FieldPlayer *player);
extern u16 func_021A3050(struct FieldPlayer *player);
extern u32 func_021A30C8(struct FieldPlayer *player);
extern u32 func_021A3128(struct FieldPlayer *player, u32 index);
extern int func_021A3504(struct FieldPlayer *player, int a, int b);
extern int func_021A3524(struct FieldPlayer *player, int a, int b);
extern void func_021A35FC(struct FieldPlayer *player, u16 *x, u16 *y, u16 *z);
extern u16 func_0216D598(struct MapObject *obj);
extern void func_0216D88C(const struct MapObject *obj, VecFx32 *out);
extern int func_0216E5FC(u16 kind);
extern int func_0216E5B0(void *map, const VecFx32 *pos);
extern int func_0215F118(const Area *area, u16 x, u16 z, u32 eventFlag, struct FieldMap *fieldMap);
extern u32 ZONEDATA_IsFlyEnabled(u32 zoneId);
extern u32 func_02013C50(u32 zoneId);
extern int func_021CD440(struct FieldMap *fieldMap, u16 *out);
extern u32 func_02013FFC(u32 zoneId);
extern u32 ZONEDATA_IsRawZoneF6(u32 zoneId);
extern u32 ZONEDATA_IsRawZoneF7(u32 zoneId);
extern u32 func_02013E04(u32 zoneId);
extern void *func_021C6078(struct GameSystem *gameSys, struct FieldMap *fieldMap, u8 skillId);

/* field skill tables (ov010 event_field_proclink.c) */
typedef int (*SkillCheckFn)(struct FieldSkillInfo *info);
typedef struct GameEvent *(*SkillEventFn)(SkillTarget *target, FieldSkillInfo *info);
extern SkillCheckFn func_0215F088(FieldSkillInfo *info, int skillIndex);
extern SkillEventFn func_0215F0B8(FieldSkillInfo *info, int skillIndex);
extern int func_0215F104(FieldSkillInfo *info, int skillIndex);
extern void func_0215F0E8(SkillEventWork *work, const SkillTarget *target, FieldSkillInfo *info);

int func_0215D34C(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215D468(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215D504(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215D7D4(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215D864(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215D884(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215DADC(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215DB00(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215DB38(ScriptVm *vm, struct ScriptWork *scriptWork);
void func_0215DDC8(struct ScriptCtl *unused, struct GameData *gameData);
void func_0215DE0C(MusicalLinkWork *link, struct GameData *gameData);
void func_0215DE38(int link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg);
void func_0215DE44(MusicalLinkWork *link);
int func_0215DE58(struct GameEvent *task, u32 *state, void *work);
int func_0215DEF0(struct GameEvent *task, u32 *state, void *work);
void func_0215DF6C(void *callbackArg);
void func_0215DF78(void *callbackArg);
int func_0215DFB4(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E010(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E068(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E0B0(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E0EC(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E130(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E184(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E1C0(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0215E2B8(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex);
void *func_0215E31C(u32 heapId);
void func_0215E334(void *encountState);
int func_0215E33C(struct FieldMap *fieldMap);
FieldGimmickWork *func_0215E34C(struct GameData *gameData);
void func_0215E358(struct MovePokemonSave *block, u32 season, u16 slot);
void func_0215E364(struct GameData *gameData);
void func_0215E3A0(struct GameData *gameData);
u32 func_0215E3E4(struct MovePokemonSave *block, u32 slot);
int func_0215E404(struct MovePokemonSave *block);
void func_0215E428(struct MovePokemonSave *block, int value);
void func_0215E440(struct GameData *gameData, u8 slot);
void func_0215E580(struct GameData *gameData);
void func_0215E5B0(struct GameData *gameData, BattleResultWork *work);
int func_0215E6A8(struct GameData *gameData, int zoneId);
int func_0215E6F8(struct GameData *gameData);
int func_0215E724(int species);
void func_0215E740(struct MovePokemonSave *block, u32 season, u16 slot, int excludedLocation);
void func_0215E7DC(struct MovePokemonSave *block, u32 slot, u8 location, u32 zoneId);
struct MovePokemonEntry *func_0215E804(struct MovePokemonSave *block, int species);
void func_0215E840(struct FieldMap *fieldMap, FieldSkillInfo *out);
int func_0215EA14(int skillIndex, FieldSkillInfo *info);
void func_0215EA30(SkillTarget *target, u16 id, u16 variant, u32 targetObj);
struct GameEvent *func_0215EA38(int skillIndex, SkillTarget *target, FieldSkillInfo *info);
int func_0215EA58(FieldSkillInfo *info);
struct GameEvent *func_0215EA6C(SkillTarget *target, FieldSkillInfo *info);
int func_0215EA94(struct GameEvent *event, u32 *state, void *work);
int func_0215EAC8(FieldSkillInfo *info);
struct GameEvent *func_0215EAF0(SkillTarget *target, FieldSkillInfo *info);
int func_0215EB18(struct GameEvent *event, u32 *state, void *work);
int func_0215EB4C(FieldSkillInfo *info);
struct GameEvent *func_0215EB60(SkillTarget *target, FieldSkillInfo *info);
int func_0215EB88(struct GameEvent *event, u32 *state, void *work);
int func_0215EBBC(FieldSkillInfo *info);
struct GameEvent *func_0215EBD0(SkillTarget *target, FieldSkillInfo *info);
int func_0215EBF8(struct GameEvent *event, u32 *state, void *work);
int func_0215EC2C(FieldSkillInfo *info);
void *func_0215EC40(SkillTarget *target, FieldSkillInfo *info);

extern u8 ov112_id[];
extern const char d_02172914[];
extern u8 d_021F8360[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];
extern u8 ov132_id[];
extern const char d_02172724[];
extern const char d_02172928[];
extern const u16 d_021711C6[];
extern const char d_0217293C[];
extern const RoamLocationLinks d_021711A8[];
extern const Area d_021711EC;
extern const Area d_021711F4;



/*
 * Script command: start the ov010 musical link sequence (func_02155A98) for
 * mode 0/1, or push the ov112 proc through func_02014808 otherwise.
 *
 * Levers (all needed for the exact bytes): `d = (mode == 0) ? 0 : 1` instead
 * of an if (removes a register swap); func_02159B10 declared u16 with the
 * argument held in a u16 local (moves the outgoing stack store, see
 * docs/idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md).
 * The callback 0x0215DF6C is a 12-byte tail stub in the image.
 * func_02158F58 returns a+0x18 (result ignored); GAME_DATA_GetSaveBlock2A is void in its
 * own file, but this caller uses its result as the musical save pointer.
 */
int func_0215D34C(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 arg;
    u8 mode;

    scriptCtl = func_0215A5F4(scriptWork);
    gameSys = func_0215A5DC(scriptWork);
    gameData = func_0215A5E4(scriptWork);
    fieldMap = func_0201210C(gameSys);
    func_02158F58(scriptCtl);
    arg = func_02159B10(vm, scriptWork);
    mode = *vm->pc;
    vm->pc++;
    if (mode <= 1) {
        MusicalLinkWork *link = GAME_DATA_GetExternalWork(gameData);
        u32 startMode;
        struct GameEvent *task;
        MusicalStartTask *startTask;

        startMode = (mode == 0) ? 0 : 1;
        task = func_020122C0(gameSys, 0, func_0215DE58, sizeof(MusicalStartTask));
        startTask = func_020124E8(task);
        MI_CpuFill8(startTask, 0, sizeof(MusicalStartTask));
        startTask->musicalSeq = func_02155A98(gameSys, gameData, arg, startMode, link);
        startTask->link = link;
        startTask->mode = startMode;
        func_0215898C(scriptCtl, task);
        func_02012A30(gameData);
        func_02011290(vm);
        return 1;
    } else {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(gameData);
        MusicalProcBox *box;

        box = func_02030734(4, sizeof(MusicalProcBox), 1, d_02172914, 0xA9);
        box->args = func_02030734(4, 0x14, 1, d_02172914, 0xAA);
        box->args->startMode = 0;
        box->args->saveBits = func_0200A640(musical);
        box->args->isOffline = 1;
        func_0215897C(scriptCtl, func_02014808(gameSys, fieldMap, (u32)ov112_id, d_021F8360, box->args, func_0215DF6C, box));
        return 1;
    }
}


/*
 * Script command: show the musical of a party Pokemon. Reads a party index,
 * creates the musical system for that member and runs the proc d_02172724
 * on it from a task (func_0215DEF0), which frees the work when done.
 */
int func_0215D468(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = func_0215A5F4(scriptWork);
    struct GameSystem *gameSys = func_0215A5DC(scriptWork);
    struct GameData *gameData = func_0215A5E4(scriptWork);
    int partyIndex;
    u32 musicalSave, musicalSystem;
    struct GameEvent *task;
    MusicalSystemTask *systemTask;

    func_0201210C(gameSys);
    partyIndex = func_02159B10(vm, scriptWork);
    musicalSave = (u32)GAME_DATA_GetSaveBlock2A(gameData);
    musicalSystem = func_021F675C(func_0201AB28(func_02012934(gameData), partyIndex), 4);
    task = func_020122C0(gameSys, 0, func_0215DEF0, 4);
    systemTask = func_020124E8(task);
    func_02082BCC(systemTask, 0, 4);
    systemTask->args = func_02030734(4, 0xc, 1, d_02172914, 0xd7);
    systemTask->args->musicalSystem = musicalSystem;
    systemTask->args->musicalSave = musicalSave;
    systemTask->args->startMode = 0;
    func_0215897C(scriptCtl, task);
    return 1;
}


/*
 * Script command: read a one-byte query id from the script cursor, one
 * argument word and a result variable, and store the answer of the query
 * (musical save counters 0..15, link-result queries 30..39) into the variable.
 *
 * Levers: the per-case best/second locals at function scope in declaration
 * order with op declared last (sets the stack slots), max initialised before
 * best, case 10 loops over its own block-local slot, case 7 tests == 0 first.
 */
int func_0215D504(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u32 arg;
    u16 *resultVar;
    struct GameData *gameData;
    struct MusicalSave *musical;
    struct MusicalEvent *musicalEvent;
    u8 i;
    u8 maxCount;
    u8 uniqueTopSlot;
    u8 lowestSlot;
    u8 topSlot;
    u8 leaderSlot;
    u8 leaderPrevMax;
    u8 runnerUpSlot;
    struct PokeParty *party;
    u8 op;

    func_0215A5F4(scriptWork);
    op = *vm->pc;
    vm->pc++;
    arg = func_02159B10(vm, scriptWork);
    resultVar = func_02159AE8(vm, scriptWork);
    gameData = func_0215A5E4(scriptWork);
    musical = GAME_DATA_GetSaveBlock2A(gameData);
    musicalEvent = 0;
    if (op >= 30) {
        struct MusicalEvent **linkEvent = GAME_DATA_GetExternalWork(gameData);

        if (linkEvent == 0) {
            *resultVar = 0;
            return 0;
        }
        musicalEvent = *linkEvent;
    }
    switch (op) {
    case 0:
        *resultVar = func_0200A75C(musical);
        break;
    case 1:
        *resultVar = func_0200A780(musical);
        break;
    case 2:
        *resultVar = func_0200A7B8(musical);
        break;
    case 3: {
        /* equipped prop slot with the single highest value, 4 on a tie */
        maxCount = 0;
        uniqueTopSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = func_0200A7A0(musical, i);

            if (value > maxCount) {
                maxCount = value;
                uniqueTopSlot = i;
            } else if (value == maxCount) {
                uniqueTopSlot = 4;
            }
        }
        *resultVar = uniqueTopSlot;
        break;
    }
    case 4:
        *resultVar = func_0200A7C8(musical);
        break;
    case 5:
        func_0200A7D4(musical, arg);
        break;
    case 6:
        *resultVar = 0;
        for (i = 0; i < 4; i++) {
            if (func_0200A7A0(musical, i) != 0)
                *resultVar = 1;
        }
        break;
    case 7:
        if (func_0200A640(musical)->shotState == 0)
            *resultVar = 0;
        else
            *resultVar = 1;
        break;
    case 8: {
        /* slot with the lowest value (last one on a tie) */
        maxCount = 0xFF;
        lowestSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = func_0200A7A0(musical, i);

            if (value <= maxCount) {
                maxCount = value;
                lowestSlot = i;
            }
        }
        *resultVar = lowestSlot;
        break;
    }
    case 9: {
        /* slot with the highest value (first one on a tie) */
        maxCount = 0;
        topSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = func_0200A7A0(musical, i);

            if (value > maxCount) {
                maxCount = value;
                topSlot = i;
            }
        }
        *resultVar = topSlot;
        break;
    }
    case 10: {
        /* runner-up slot, 4 when the runner-up ties */
        u8 slot;

        leaderSlot = 4;
        leaderPrevMax = 0;
        maxCount = 0;
        runnerUpSlot = 4;

        for (slot = 0; slot < 4; slot++) {
            u8 value = func_0200A7A0(musical, slot);

            if (value > maxCount) {
                if (leaderPrevMax == maxCount) {
                    runnerUpSlot = 4;
                } else {
                    leaderPrevMax = maxCount;
                    runnerUpSlot = leaderSlot;
                }
                maxCount = value;
                leaderSlot = slot;
            }
        }
        *resultVar = runnerUpSlot;
        break;
    }
    case 11: {
        /* number of party members that can take part in a musical */
        u8 count = 0;
        u8 partyCount;

        party = func_02012934(gameData);
        partyCount = func_0201AA18(party);

        for (i = 0; i < partyCount; i++) {
            if ((u32)func_021F6744(func_0201AB28(party, (int)i)) == 1)
                count++;
        }
        *resultVar = count;
        break;
    }
    case 12:
        if ((u32)func_021F6744(func_0201AB28(func_02012934(gameData), (int)arg)) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 13: {
        /* any outfit slot in use */
        struct MusicalOutfit *outfits = func_0200A628(musical);

        *resultVar = 0;
        for (i = 0; i < 8; i++) {
            if (outfits[i].pokeSlot != 10)
                *resultVar = 1;
        }
        break;
    }
    case 14:
        if (func_0200A7E0(musical) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 15:
        if (func_0200A644(musical, (u8)arg) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 30:
        *resultVar = func_021568E0(musicalEvent);
        break;
    case 31:
        *resultVar = func_02156954(musicalEvent);
        break;
    case 32:
        *resultVar = func_02156978(musicalEvent);
        break;
    case 33:
        *resultVar = func_02156934(musicalEvent, arg);
        break;
    case 35:
        *resultVar = func_021568E8((int)musicalEvent, arg);
        break;
    case 36:
        *resultVar = func_02156908(musicalEvent);
        break;
    case 37:
        *resultVar = func_0215699C(musicalEvent, arg);
        break;
    case 38:
        *resultVar = func_021569A4(musicalEvent, arg);
        break;
    case 39:
        *resultVar = func_021569EC(musicalEvent, arg);
        break;
    }
    return 0;
}


/*
 * Script command: read a query kind and a program slot, store a derived
 * value of that musical program into a script variable.
 */
int func_0215D7D4(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int slot;
    u32 kind;
    u16 *resultVar;
    MusicalProgramView *program;

    slot = func_02159B10(vm, scriptWork);
    kind = *vm->pc;
    vm->pc++;
    resultVar = func_02159AE8(vm, scriptWork);
    program = (MusicalProgramView *)func_0200A750(GAME_DATA_GetSaveBlock2A(func_0215A5E4(scriptWork)), (u8)slot);
    switch (kind) {
    case 0:
        switch (program->state) {
        case 0: *resultVar = 0x18; break;
        case 1: *resultVar = 0xf; break;
        case 2: *resultVar = 0x2d; break;
        case 3: *resultVar = 0xc; break;
        case 4: *resultVar = 0; break;
        }
        break;
    case 1:
        *resultVar = slot + 5;
        break;
    case 2:
        slot += 0xf;
        *resultVar = slot;
        break;
    case 3:
        *resultVar = program->rank;
        break;
    case 4:
        *resultVar = program->score;
        break;
    }
    return 0;
}


/* Script command: mark a musical prop as owned. The id is truncated to a byte before the arm9 call. */
int func_0215D864(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int prop = func_02159B10(vm, scriptWork);

    func_0200A6BC(GAME_DATA_GetSaveBlock2A(func_0215A5E4(scriptWork)), (u8)prop);

    return 0;
}


/*
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into the
 * slot (stage name, message-bank entries, link member names, or the three
 * placement labels of a four-way ranking).
 */
int func_0215D884(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = func_0215A5F4(scriptWork);
    struct GameData *gameData = func_0215A5E4(scriptWork);
    u32 heapId = func_0215A5CC(scriptWork);
    struct WordSet *wordSet = func_02158F74(scriptCtl);
    u8 kind;
    u8 slot;
    u32 arg;
    struct MsgData *msgData;
    struct Strbuf *str;

    kind = *vm->pc;
    vm->pc++;
    slot = *vm->pc;
    vm->pc++;
    arg = func_02159B10(vm, scriptWork);

    switch (kind) {
    case 0: {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(func_0215A5E4(scriptWork));

        str = func_020457B0(0x26, heapId);
        func_02045994(str, (const u16 *)func_0200A7F8(musical), 0x26);
        func_0201EE0C(wordSet, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    }
    case 1:
    case 8:
        if (kind == 1)
            msgData = func_02045B38(0, 2, 0x4F, heapId);
        else
            msgData = func_02045B38(0, 2, 0x11A, heapId);
        str = func_02045EC0(msgData, arg + 3);
        func_0201EE0C(wordSet, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(msgData);
        break;
    case 2:
        str = func_02156914((int)(*((void **)GAME_DATA_GetExternalWork(gameData))), heapId);
        func_0201EE0C(wordSet, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    case 3:
        msgData = func_02045B38(0, 2, 0x4B, heapId);
        str = func_02045EC0(msgData, arg);
        func_0201EE0C(wordSet, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(msgData);
        break;
    case 4:
        msgData = func_02045B38(0, 2, 0x4B, heapId);
        str = func_02045EC0(msgData, arg + 4);
        func_0201EE0C(wordSet, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(msgData);
        break;
    case 5:
        func_02156A3C(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 6:
        func_02156AD4(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 7: {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(func_0215A5E4(scriptWork));
        u16 labelIds[3];
        u8 slotOrder[4];
        u8 slotValue[4];
        u8 i;
        u8 j;

        /* sort the four slots by value, descending (bubble sort) */
        for (i = 0; i < 4; i++) {
            slotOrder[i] = i;
            slotValue[i] = func_0200A7A0(musical, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 next = j + 1;

                if (slotValue[j] < slotValue[next]) {
                    u8 tmp = slotValue[j];

                    slotValue[j] = slotValue[next];
                    slotValue[next] = tmp;
                    tmp = slotOrder[j];
                    slotOrder[j] = slotOrder[next];
                    slotOrder[next] = tmp;
                }
            }
        }
        if (slotValue[0] == slotValue[1] && slotValue[0] == slotValue[2]) {
            labelIds[0] = 9;
            labelIds[1] = 8;
        } else {
            labelIds[0] = slotOrder[0] + 4;
            if (slotValue[1] == slotValue[2])
                labelIds[1] = 8;
            else
                labelIds[1] = slotOrder[1] + 4;
        }
        if (slotValue[1] == slotValue[3])
            labelIds[2] = slotOrder[1] + 4;
        else if (slotValue[2] == slotValue[3])
            labelIds[2] = slotOrder[2] + 4;
        else
            labelIds[2] = slotOrder[3] + 4;
        msgData = func_02045B38(0, 2, 0x4B, heapId);
        for (i = 0; i < 3; i++) {
            str = func_02045EC0(msgData, labelIds[i]);
            func_0201EE0C(wordSet, i, str, 0, 1, 2);
            func_02045808(str);
        }
        func_02045C04(msgData);
        break;
    }
    }
    return 0;
}


/* Script command: clear the rank byte of a musical program slot. */
int func_0215DADC(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int slot = func_02159B10(vm, scriptWork);
    MusicalProgramView *program = (MusicalProgramView *)func_0200A750(GAME_DATA_GetSaveBlock2A(func_0215A5E4(scriptWork)), (u8)slot);

    program->rank = 0;
    return 0;
}


/* Script command: open the party selection screen; the two script variables receive the choice. */
int func_0215DB00(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *partyIndexVar = func_02159AE8(vm, scriptWork);
    u16 *resultVar = func_02159AE8(vm, scriptWork);
    struct ScriptCtl *scriptCtl = func_0215A5F4(scriptWork);

    func_0215897C(scriptCtl, func_0215A168(func_0215A5DC(scriptWork), partyIndexVar, resultVar));
    return 1;
}


/*
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result variable, then opens or closes the link work (0, 1), starts
 * the ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the variable (19..21).
 *
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 * ov100_id is the overlay id of the ov100 proc (the symbol value is 0x64).
 */
int func_0215DB38(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 cmd;
    u16 arg;
    u16 *resultVar;
    int busy;
    MusicalLinkWork *link;

    scriptCtl = func_0215A5F4(scriptWork);
    gameSys = func_0215A5DC(scriptWork);
    gameData = func_0215A5E4(scriptWork);
    fieldMap = func_0201210C(gameSys);
    cmd = func_02159B10(vm, scriptWork);
    arg = func_02159B10(vm, scriptWork);
    func_02159B10(vm, scriptWork);
    resultVar = func_02159AE8(vm, scriptWork);
    busy = 0;
    link = 0;
    if (cmd != 0 && cmd != 0x15) {
        link = GAME_DATA_GetExternalWork(gameData);
        if (link->musicalEvent != 0) {
            func_02156BAC(link->musicalEvent);
            if (func_02156BCC(link->musicalEvent) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        func_0215DDC8(scriptCtl, gameData);
        break;
    case 1:
        func_0215DE0C(link, gameData);
        break;
    case 10:
        func_0215DE38((int)link, gameSys, func_02012138(gameSys), arg);
        break;
    case 11:
        func_0215DE44(link);
        func_020113D0(vm, func_0215E130);
        return 1;
    case 12:
        link->resultOut = resultVar;
        link->entryMenu = func_021CD48C(func_02012944(gameData), fieldMap, 2, 4, 4, 0, 1, 0);
        func_020113D0(vm, func_0215DFB4);
        return 1;
    case 13:
        link->resultOut = resultVar;
        link->entryMenu = func_021CD48C(func_02012944(gameData), fieldMap, 2, 4, 4, 1, 1, 0);
        func_020113D0(vm, func_0215E010);
        return 1;
    case 14:
        if (link->session == 0 || busy != 0)
            break;
        link->memberCount = arg;
        func_021FCDEC((int)link->session, (u8)link->memberCount);
        func_020113D0(vm, func_0215E068);
        return 1;
    case 15:
        if (link->session == 0 || busy != 0)
            break;
        func_020113D0(vm, func_0215E0B0);
        return 1;
    case 16:
        func_020113D0(vm, func_0215E0EC);
        return 1;
    case 17:
        if (link->session == 0 || busy != 0)
            break;
        func_020113D0(vm, func_0215E184);
        return 1;
    case 18: {
        MusicalLinkWait *wait = func_02030734(0x8004, 8, (u32)1, d_02172914, (u32)0x3C8);

        wait->scriptWork = scriptWork;
        wait->link = link;
        link->resultOut = resultVar;
        link->gameData = gameData;
        link->procWork = (u32)func_021FDA6C(gameData);
        link->procMode = arg == 0 ? 9 : 10;
        func_0215897C(scriptCtl, func_02014808(gameSys, fieldMap, (u32)ov100_id, d_021BB6A4, &link->gameData, func_0215DF78, wait));
        return 1;
    }
    case 19:
        if (link->session != 0 && busy == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 20:
        if (link->session != 0)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 21:
        if (func_0200FB24() != 0) {
            func_02012124(gameSys, 1);
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}


/*
 * Allocate the 0x38-byte link work, clear its first two words, attach it to
 * the game data external-work slot and load overlays 132 and 112.
 */
void func_0215DDC8(struct ScriptCtl *unused, struct GameData *gameData)
{
    MusicalLinkWork *link = func_02030734(4, 0x38, 1, d_02172914, 0x413);

    link->musicalEvent = 0;
    link->session = 0;
    GAME_DATA_SetExternalWork(gameData, link);
    func_02034AC4((u32)ov132_id);
    func_02034AC4((u32)ov112_id);
}


/* Unload overlays 112 and 132, free the link work and detach it. */
void func_0215DE0C(MusicalLinkWork *link, struct GameData *gameData)
{
    func_02034A5C((u32)ov112_id);
    func_02034A5C((u32)ov132_id);
    func_020307B0(link);
    GAME_DATA_SetExternalWork(gameData, 0);
}


/*
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 */
void func_0215DE38(int link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg)
{
    func_021FC644(4, (void *)gameSys, (void *)gameComm, arg);
}


/* Close the comm session of the link work, if any. */
void func_0215DE44(MusicalLinkWork *link)
{
    if (link->session != 0) {
        func_021FC684(link->session);
        link->session = 0;
    }
}


/*
 * Event task of StartMusical (states 0..3): call the link event, close the
 * session, wait for the comm (when mode 1), then free the link work.
 * Lever: the game data pointer stays live in r0 across the switch for
 * func_02012A30. Two zero alignment bytes follow the 150-byte function.
 */
int func_0215DE58(struct GameEvent *task, u32 *state, void *work)
{
    MusicalStartTask *startTask = work;
    struct GameData *gameData;

    gameData = func_020120F4(func_020124E4(task));
    switch (*state) {
    case 0:
        func_02012374(task, startTask->musicalSeq);
        (*state)++;
        break;
    case 1:
        func_02012A30(gameData);
        func_0215DE44(startTask->link);
        (*state)++;
        break;
    case 2:
        {
            struct GameComm *gameComm = func_02012138(func_020124E4(task));
            if (startTask->mode != 0) {
                if (func_02026454(gameComm) != 0)
                    break;
            }
        }
        (*state)++;
        break;
    case 3:
        if (func_0203CDBC() != 1) {
            if (startTask->mode != 0)
                break;
        }
        if (startTask->mode == 1) {
            func_020121CC(func_020124E4(task));
        }
        func_0215DE0C(startTask->link, gameData);
        (*state)++;
        return 1;
    }
    return 0;
}


/*
 * Event task of ShowPartyMonMusical: runs the proc d_02172724 on the musical
 * system arguments, then frees the system and the argument block.
 */
int func_0215DEF0(struct GameEvent *task, u32 *state, void *work)
{
    MusicalSystemTask *systemTask = work;
    struct GameSystem *gameSys = func_020124E4(task);

    func_020120F4(gameSys);
    func_0201210C(gameSys);
    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        (*state)++;
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSys, -1, (void *)d_02172724, systemTask->args);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSys) != 0)
            break;
        (*state)++;
        break;
    case 5:
        (*state)++;
        break;
    case 6:
        func_020307B0((void *)systemTask->args->musicalSystem);
        func_020307B0(systemTask->args);
        return 1;
    }
    return 0;
}


/* Proc callback: free the argument block of the ov112 proc. */
void func_0215DF6C(void *callbackArg)
{
    MusicalProcBox *box = callbackArg;

    func_020307B0(box->args);
}


/*
 * Callback of the ov100 proc: set the result variable to 1 (0 when the proc
 * mode is 12 or 13) and close the comm session otherwise.
 */
void func_0215DF78(void *callbackArg)
{
    MusicalLinkWait *wait = callbackArg;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLinkWork *link;

    gameSys = func_0215A5DC(wait->scriptWork);
    gameData = func_0215A5E4(wait->scriptWork);
    func_02012138(gameSys);
    link = wait->link;
    if (link->procMode != 0xc && link->procMode != 0xd) {
        *link->resultOut = 1;
        func_021FC81C(wait->link->session);
    } else {
        *link->resultOut = 0;
    }
}


/* Wait: entry menu opened as parent. Result 0 = accepted, 1 = declined, 2 = cancelled. */
int func_0215DFB4(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;
    int done;
    int status;

    func_0215A5F4(scriptWork);
    link = GAME_DATA_GetExternalWork(func_0215A5E4(scriptWork));
    status = func_021CD688(link->entryMenu);
    done = 0;
    switch (status) {
    case 1:
        *link->resultOut = 0;
        func_021FC804(link->session);
        done = 1;
        break;
    case 2:
        *link->resultOut = 1;
        done = 1;
        break;
    case 4:
        *link->resultOut = 2;
        done = 1;
        break;
    }
    if (done == 1) {
        func_021CD5A4(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}


/* Wait: entry menu opened as child. Result 3 = accepted, 4 = declined, 2 = cancelled. */
int func_0215E010(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;
    int done;
    int result;

    func_0215A5F4(scriptWork);
    link = GAME_DATA_GetExternalWork(func_0215A5E4(scriptWork));
    done = 0;
    switch (func_021CD688(link->entryMenu)) {
    case 1:
        *link->resultOut = 3;
        func_021FC804(link->session);
        done = 1;
        break;
    case 2:
        result = 4;
        *link->resultOut = result;
        done = 1;
        break;
    case 4:
        result = 2;
        *link->resultOut = result;
        done = 1;
        break;
    }
    if (done == 1) {
        func_021CD5A4(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}


/* Wait: member count set on the session (command 14). */
int func_0215E068(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    func_0215A5F4(scriptWork);
    link = GAME_DATA_GetExternalWork(func_0215A5E4(scriptWork));
    if (link->musicalEvent != 0) {
        func_02156BAC(link->musicalEvent);
        if (func_02156BCC(link->musicalEvent) == 1)
            return 1;
    }
    if (func_021FCE00(link->session, (u8)link->memberCount) == 1)
        return 1;
    return 0;
}


/* Wait: session ready (command 15). */
int func_0215E0B0(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    func_0215A5F4(scriptWork);
    link = GAME_DATA_GetExternalWork(func_0215A5E4(scriptWork));
    func_02156BAC(link->musicalEvent);
    if (func_02156BCC(link->musicalEvent) == 1)
        return 1;
    if (func_021FD844(link->session) == 1)
        return 1;
    return 0;
}


/* Wait: attach the link work to the comm session once the comm kind is 4 (command 16). */
int func_0215E0EC(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct GameComm *gameComm;
    MusicalLinkWork *link;

    func_0215A5F4(scriptWork);
    gameSys = func_0215A5DC(scriptWork);
    gameData = func_0215A5E4(scriptWork);
    gameComm = func_02012138(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (func_02026454(gameComm) == 4) {
        link->session = (void *)func_02026474(gameComm);
        return 1;
    }
    return 0;
}


/* Wait: the comm is gone and the musical event is idle (command 11). */
int func_0215E130(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameComm *gameComm;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLinkWork *link;

    func_0215A5F4(scriptWork);
    gameSys = func_0215A5DC(scriptWork);
    gameData = func_0215A5E4(scriptWork);
    gameComm = func_02012138(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (link->musicalEvent != 0) {
        func_02156BAC(link->musicalEvent);
        if (func_02156BCC(link->musicalEvent) == 1) {
            return 1;
        }
    }
    if (func_02026454(gameComm) == 0) {
        return 1;
    }
    return 0;
}


/* Wait: session finished (command 17). */
int func_0215E184(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    func_0215A5F4(scriptWork);
    link = GAME_DATA_GetExternalWork(func_0215A5E4(scriptWork));
    func_02156BAC(link->musicalEvent);
    if (func_02156BCC(link->musicalEvent) == 1)
        return 1;
    if (func_021FD910(link->session) == 1)
        return 1;
    return 0;
}


/*
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the wifi list func_02009448 returns;
 * sub-commands 0, 1 and 4 write a halfword result through the result
 * variable, 5 formats a value into the word set.
 */
int func_0215E1C0(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u32 cmd;
    u16 *resultVar;
    u16 key;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct WifiList *wifiList;
    u32 limit;
    void *postEvent;
    struct WordSet *wordSet;

    cmd = func_02159B10(vm, scriptWork);
    resultVar = func_02159AE8(vm, scriptWork);
    key = func_0215A5CC(scriptWork);
    gameSys = func_0215A5DC(scriptWork);
    gameData = func_0215A5E4(scriptWork);
    wifiList = func_02009448(func_02012EBC(gameData));
    limit = (int)func_02009370(wifiList);
    if (func_0201210C(gameSys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *resultVar = (int)func_02009370(wifiList) > 0 ? 1 : 0;
        break;
    case 1:
        if (func_021B76F8(gameData, key, wifiList) < limit) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 2:
        postEvent = func_021B7794(gameSys);
        func_0215897C(func_0215A5F4(scriptWork), postEvent);
        return 1;
    case 3:
        func_021B76B4(gameData, key, (int)wifiList);
        break;
    case 5:
        wordSet = func_02158F74(func_0215A5F4(scriptWork));
        func_0201EF5C(wordSet, 0, (u32)func_021B7740(gameData, key, wifiList, *resultVar));
        break;
    case 4:
        *resultVar = func_021B76F8(gameData, key, wifiList);
        break;
    }
    return 0;
}



/*
 * Read the encounter row of a zone from the encounter archive into `row`
 * (0xE8 bytes). Zones with one row use it for every season, zones with four
 * rows use the row of the season index. Returns 0 when the zone has no row
 * or the member has another size.
 */
int func_0215E2B8(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex)
{
    u32 rowCount;
    int member;

    func_02082BCC(row, 0, 0xe8);
    member = ZONEDATA_GetEncountId(zoneId);
    if (member == 0xffff) {
        return 0;
    }
    rowCount = func_020493D4(arc, member) / 0xe8;
    if (rowCount != 1 && rowCount != 4) {
        return 0;
    }
    if (rowCount == 1) {
        seasonIndex = 0;
    }
    func_0204944C(arc, member, seasonIndex * 0xe8, 0xe8, row);
    row->flags |= 0x80;
    return 1;
}


/* Allocate the 0x20-byte field encounter state. */
void *func_0215E31C(u32 heapId)
{
    return func_02030734(heapId, 32, 1, d_02172928, 45);
}


void func_0215E334(void *encountState)
{
    func_020307B0(encountState);
}


/* Result of the effect-encounter query for the field effect object of `fieldMap`. */
int func_0215E33C(struct FieldMap *fieldMap)
{
    EffectEncountObj *obj;

    obj = func_02188CE8(fieldMap);
    return func_021AA7DC(obj, obj->encountParam);
}


/* Clear the state word (offset 0xC) of the field gimmick work and return the work. */
FieldGimmickWork *func_0215E34C(struct GameData *gameData)
{
    FieldGimmickWork *gimmick;

    gimmick = func_02012A38(gameData);
    gimmick->state = 0;
    return gimmick;
}


/* Move entry `slot` to a new location, excluding no location (0xff). */
void func_0215E358(struct MovePokemonSave *block, u32 season, u16 slot)
{
    func_0215E740(block, season, slot, 0xff);
}


/* After a battle: move every active roaming entry. */
void func_0215E364(struct GameData *gameData)
{
    u8 i;
    u32 season;
    struct MovePokemonSave *block;

    block = func_0200D418(func_02012EBC(gameData));
    season = func_02012984(gameData);
    for (i = 0; i < 2; i++) {
        if (func_0200D488(block, i) != 0) func_0215E358(block, season, i);
    }
}


/* Same as func_0215E364, with an unused entry lookup per slot. */
void func_0215E3A0(struct GameData *gameData)
{
    u8 i;
    u32 season;
    struct MovePokemonSave *block;

    block = func_0200D418(func_02012EBC(gameData));
    season = func_02012984(gameData);
    for (i = 0; i < 2; i++) {
        func_0200D4AC(block, i);
        if (func_0200D488(block, i) != 0) {
            func_0215E358(block, season, i);
        }
    }
}


/* Zone id of the location an entry is in (319 for an invalid location). */
u32 func_0215E3E4(struct MovePokemonSave *block, u32 slot)
{
    u32 location = func_0200D478(block, slot);
    if (location > 16) return 319;
    return d_021711C6[location];
}


/* 1 when any of the two entries is active. */
int func_0215E404(struct MovePokemonSave *block)
{
    u8 i = 0;

    do {
        if (func_0200D488(block, i) != 0)
            return 1;
        i++;
    } while (i < 2);
    return 0;
}


/* Store the common area value when an entry is active. */
void func_0215E428(struct MovePokemonSave *block, int value)
{
    if (func_0215E404(block) != 0)
        func_0200D45C(block, value);
}


/*
 * Hand out the roaming legendary of entry `slot` (Thundurus 642 or Tornadus
 * 641 at level 40): fill the entry record, create the Pokemon into the box,
 * and mark the entry. Levers: level and the entry flag assigned the same
 * value in both switch arms (the tail-merged assignments keep them as
 * variables: level spilled to the frame, the flag in r6), species as u32
 * truncated at the call, `entries` declared before `save`.
 */
void func_0215E440(struct GameData *gameData, u8 slot)
{
    struct MovePokemonSave *block;
    struct SaveControl *save;
    struct MovePokemonEntry *entry;
    struct MyStatus *myStatus;
    struct Pokemon *mon;
    u32 species;
    u16 level;
    u32 flag;

    save = func_02012EBC(gameData);
    block = func_0200D418(save);
    entry = func_0200D4AC(block, slot);
    switch (slot) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }
    func_0200D50C(entry, 4, species);
    func_0200D50C(entry, 6, level);
    func_0200D50C(entry, 9, flag);
    myStatus = func_02012944(gameData);
    mon = func_02030734(0x8003, func_020173EC(), 1, d_0217293C, 0x12E);
    func_02017588(mon, species, level, func_02008530(myStatus), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    func_0200D50C(entry, 7, 0);
    func_0200D50C(entry, 8, 1);
    func_0200D50C(entry, 2, func_02017E1C(mon, 0xAC, 0));
    func_0200D50C(entry, 3, func_02017E1C(mon, 0, 0));
    func_0200D50C(entry, 10, func_02017E1C(mon, 0x70, 0));
    func_0200D50C(entry, 5, func_02017E1C(mon, 0xA1, 0));
    func_0200CFA0(func_0200CA10(save), mon);
    func_020307B0(mon);
    func_0215E740(block, (u32)((void *)func_02012984(gameData)), slot, 5);
    func_0200D470(block, slot, 1);
}


/* Spawn every entry that waits to appear (state 2). */
void func_0215E580(struct GameData *gameData)
{
    int i;
    struct MovePokemonSave *block = func_0200D418(func_02012EBC(gameData));
    for (i = 0; i < 2; i++) {
        if (func_0200D468(block, (u8)i) == 2) func_0215E440(gameData, i);
    }
}


/*
 * Battle-result hook: reads species (5), hp (0xA0) and status (0x9D) of the
 * lead party member of the battle setup, looks up the roaming entry for the
 * species (func_0215E804) and either rolls a 30% chance of moving the
 * entries (func_0215E364) when there is none, sets one of two states on it
 * for results 1-2 (with hp 0) or 5 (caught), or copies hp and status into it
 * and moves the entries.
 *
 * The local declaration order (mon, species, hp, index, block, status) is
 * load-bearing.
 */
void func_0215E5B0(struct GameData *gameData, BattleResultWork *work)
{
    struct Pokemon *mon;
    u16 species;
    u16 hp;
    u32 entryIndex;
    struct MovePokemonSave *block;
    u8 status;
    struct MovePokemonEntry *entry;

    if (work->resultKind1 != 0 || work->resultKind0 != 0) {
        return;
    }
    func_02012AC8(func_020127A4(gameData));
    mon = func_0201AB28(BTL_SETUP_GetParty(work, 1), 0);
    species = func_02017E1C(mon, 5, 0);
    hp = func_02017E1C(mon, 0xA0, 0);
    status = func_02017E1C(mon, 0x9D, 0);
    block = func_0200D418(func_02012EBC(gameData));
    entry = func_0215E804(block, species);
    if (entry == 0) {
        if (func_02005728(100) < 30) {
            func_0215E364(gameData);
        }
        return;
    }
    entryIndex = func_0215E724(species);
    if ((work->battleResult == 1 || work->battleResult == 2) && hp == 0) {
        func_0200D494(entry);
        func_0200D480(block, entryIndex, 0x10);
        func_0200D470(block, entryIndex, 2);
        return;
    }
    if (work->battleResult == 5) {
        func_0200D494(entry);
        func_0200D480(block, entryIndex, 0x10);
        func_0200D470(block, entryIndex, 3);
        return;
    }
    func_0200D50C(entry, 5, hp);
    func_0200D50C(entry, 7, status);
    func_0215E364(gameData);
}


/* Entry whose current zone is `zoneId`: returns 6 or 7 (the entry index + 6), 0xffff when none. */
int func_0215E6A8(struct GameData *gameData, int zoneId)
{
    u8 i;
    struct MovePokemonSave *block;

    block = func_0200D418(func_02012EBC(gameData));
    i = 0;
    if (func_0200D488(block, 0) != 0 && zoneId == func_0215E3E4(block, i)) {
        return 6;
    }
    i = 1;
    if (func_0200D488(block, 1) != 0 && zoneId == func_0215E3E4(block, i)) {
        return 7;
    }
    return 0xffff;
}


/* 1 when any of the two entries is active. */
int func_0215E6F8(struct GameData *gameData)
{
    struct MovePokemonSave *block;

    block = func_0200D418(func_02012EBC(gameData));
    if (func_0200D488(block, 0) != 0 || func_0200D488(block, 1) != 0)
        return 1;
    return 0;
}


/* Entry index of a roaming species: Thundurus 0, Tornadus 1, anything else 2. */
int func_0215E724(int species)
{
    switch(species) {
    case 642: return 0;
    case 641: return 1;
    }
    return 2;
}


/*
 * Move entry `slot` to a neighbouring location. Unless the entry is hidden
 * (location 0x10), there is a 20% chance to hide it instead. The candidates
 * are the links of the current area, minus the current location and
 * `excludedLocation`. Lever: slot is u16 in the function and both receiving
 * externs, causing its immediate home reload; the selected byte remains u8.
 */
void func_0215E740(struct MovePokemonSave *block, u32 season, u16 slot, int excludedLocation)
{
    const RoamLocationLinks *links;
    int currentLocation;
    u8 candidates[4];
    u8 chosen;
    int candidate;
    int candidateCount;
    int i;

    currentLocation = func_0200D478(block, slot);
    links = &d_021711A8[(u16)func_020113D8(season)];
    if (currentLocation != 0x10 && func_02005728(100) < 20) {
        func_0215E7DC(block, slot, 0x10, 0xffff);
        return;
    }
    candidateCount = 0;
    for (i = 0; i < links->count; i++) {
        candidate = links->next[i];
        if (candidate != currentLocation && candidate != excludedLocation) {
            candidates[candidateCount++] = candidate;
        }
    }
    chosen = candidates[func_02005728(candidateCount)];
    func_0215E7DC(block, slot, chosen, chosen > 0x10 ? 0x13f : d_021711C6[chosen]);
}


/* Set the location of an entry and the zone id that goes with it. */
void func_0215E7DC(struct MovePokemonSave *block, u32 slot, u8 location, u32 zoneId)
{
    struct MovePokemonEntry *entry = func_0200D4AC(block, slot);
    func_0200D480(block, slot, location);
    func_0200D50C(entry, 1, zoneId);
}


/* Active entry of `species`, or 0. */
struct MovePokemonEntry *func_0215E804(struct MovePokemonSave *block, int species)
{
    u8 i = 0;
    struct MovePokemonEntry *entry;

    do {
        if (func_0200D488(block, i) != 0) {
            entry = func_0200D4AC(block, i);
            if (species == func_0200D4B8(entry, 4))
                return entry;
        }
        i++;
    } while (i < 2);
    return 0;
}


/*
 * Fill the 0x14-byte skill info for the field: zone id, the ov021 handles,
 * and the usable-skill mask from the object kind, the map tests and the
 * save flags. One lever: the u16 for func_021CD440 is declared before x
 * (stack order).
 */
void func_0215E840(struct FieldMap *fieldMap, FieldSkillInfo *out)
{
    VecFx32 pos;
    u16 swimFlag;
    u16 tileX;
    u16 tileY;
    u16 tileZ;
    struct FieldPlayer *player;
    struct MapObject *playerObj;
    void *map;
    u16 objKind;
    u32 playerA;
    u32 playerB;
    u32 playerC;

    MI_CpuFill8(out, 0, sizeof(FieldSkillInfo));
    out->zoneId = func_02188C9C(fieldMap);
    out->gameSys = func_02188C80(fieldMap);
    out->fieldMap = fieldMap;
    player = func_02188CB4(fieldMap);
    out->playerState = func_021A3098(player);
    playerObj = func_021A3250(player);
    out->playerObj = playerObj;
    if (playerObj != 0) {
        objKind = func_0216D598(playerObj);
        map = func_02188C7C(fieldMap);
        func_0216D88C(playerObj, &pos);
        if (func_0216E5FC(objKind) && func_0216E5B0(map, &pos) == 0)
            out->usableMask |= 8;
        if (objKind == 0x6C)
            out->usableMask |= 1;
    }
    playerA = func_021A3050(player);
    playerB = func_021A30C8(player);
    playerC = func_021A3128(player, playerA);
    if (func_021A3504(player, playerB, playerC) == 1)
        out->usableMask |= 2;
    if (func_021A3524(player, playerB, playerC) == 1)
        out->usableMask |= 4;
    if (ZONEDATA_IsFlyEnabled(out->zoneId) == 1) {
        out->usableMask |= 0x10;
        out->usableMask |= 0x40;
    }
    if (func_02013C50(out->zoneId) == 1)
        out->usableMask |= 0x80;
    if (func_02014470(func_02012B38(func_020120F4(out->gameSys))) & 1)
        out->usableMask |= 0x20;
    if (func_021CD440(fieldMap, &swimFlag) == 1)
        out->usableMask |= 0x400;
    if (func_02013FFC(out->zoneId)) {
        func_021A35FC(func_02188CB4(out->fieldMap), &tileX, &tileY, &tileZ);
        if (ZONEDATA_IsRawZoneF6(out->zoneId) && func_0215F118(&d_021711EC, tileX, tileZ, 0x113, fieldMap))
            out->usableMask |= 0x20;
        if (ZONEDATA_IsRawZoneF7(out->zoneId) && func_0215F118(&d_021711F4, tileX, tileZ, 0x112, fieldMap))
            out->usableMask |= 8;
    }
    if (func_02013E04(out->zoneId) == 0) {
        out->usableMask = 0;
    } else {
        out->usableMask |= 0x100;
        out->usableMask |= 0x200;
    }
    if (func_02012B70(func_020120F4(out->gameSys)) == 1)
        out->usableMask = 0;
}


/* 1 when the skill has no check function (or its check says it is blocked). */
int func_0215EA14(int skillIndex, FieldSkillInfo *info)
{
    SkillCheckFn check;

    check = func_0215F088(info, skillIndex);
    if (check == 0) {
        return 1;
    }
    return check(info);
}


/* Fill a skill target (id, variant and object) for the skill events. */
void func_0215EA30(SkillTarget *target, u16 id, u16 variant, u32 targetObj)
{
    target->id = id;
    target->variant = variant;
    target->targetObj = targetObj;
}


/* Start the event of a skill through its table entry; 0 when it has none. */
struct GameEvent *func_0215EA38(int skillIndex, SkillTarget *target, FieldSkillInfo *info)
{
    SkillEventFn create;

    create = func_0215F0B8(info, skillIndex);
    if (create == 0) {
        return 0;
    }
    return create(target, info);
}


/* 1 when skill 0 is not usable. */
int func_0215EA58(FieldSkillInfo *info)
{
    int blocked = 0;

    if (func_0215F104(info, 0) == 0) {
        blocked = 1;
    }
    return blocked;
}


struct GameEvent *func_0215EA6C(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event = func_020122C0(info->gameSys, 0, func_0215EA94, 20);
    func_0215F0E8(func_020124E8(event), target, info);
    return event;
}


/* Event main of skill 0: script event 0x2715 on the event work. */
int func_0215EA94(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;

    func_0201296C(func_020120F4(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = func_021587B0((int)event, 0x2715, 0, 0);
    func_02159058(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* Skill 1: blocked states 2 and 3 map to 4 and 1, else 1 when not usable. */
int func_0215EAC8(FieldSkillInfo *info)
{
    int blocked;

    if (info->playerState == 2) {
        return 4;
    }
    if (info->playerState == 3) {
        return 1;
    }
    blocked = 1;
    if (func_0215F104(info, 1) != 0) {
        blocked = 0;
    }
    return blocked;
}


struct GameEvent *func_0215EAF0(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = func_020122C0(info->gameSys, 0, func_0215EB18, 20);
    func_0215F0E8(func_020124E8(event), target, info);
    return event;
}


/*
 * Event main of skill 1: script event 0x2713 on the event work.
 * Interface: 021587B0 returns its final ldr r0,[r4] at 021587DC; the caller
 * consumes that result despite older callers declaring void.
 */
int func_0215EB18(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    func_0201296C(func_020120F4(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = func_021587B0((int)event, 0x2713, 0, 0);
    func_02159058(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 2 is not usable. */
int func_0215EB4C(FieldSkillInfo *info)
{
    return func_0215F104(info, 2) != 0 ? FALSE : TRUE;
}


struct GameEvent *func_0215EB60(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = func_020122C0(info->gameSys, 0, func_0215EB88, 20);
    func_0215F0E8(func_020124E8(event), target, info);
    return event;
}


/* Event main of skill 2: script event 0x2717 on the event work. */
int func_0215EB88(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    func_0201296C(func_020120F4(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = func_021587B0((int)event, 0x2717, 0, 0);
    func_02159058(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 3 is not usable. */
int func_0215EBBC(FieldSkillInfo *info)
{
    return func_0215F104(info, 3) != 0 ? FALSE : TRUE;
}


struct GameEvent *func_0215EBD0(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = func_020122C0(info->gameSys, 0, func_0215EBF8, 20);
    func_0215F0E8(func_020124E8(event), target, info);
    return event;
}


/* Event main of skill 3: script event 0x2711 on the event work. */
int func_0215EBF8(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    func_0201296C(func_020120F4(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = func_021587B0((int)event, 0x2711, 0, 0);
    func_02159058(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 8 is not usable. */
int func_0215EC2C(FieldSkillInfo *info)
{
    return func_0215F104(info, 8) != 0 ? FALSE : TRUE;
}


/* Create the object of skill 8 from the target id. */
void *func_0215EC40(SkillTarget *target, FieldSkillInfo *info)
{
    return func_021C6078(info->gameSys, info->fieldMap, target->id);
}

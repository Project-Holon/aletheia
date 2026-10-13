/*
 * file:     namein_setup.c
 * unit:     yes
 * function: func_0216BFD4, func_0216C028, func_0216C0A4, func_0216C0C0, func_0216C0D4, func_0216C0E4, func_0216C0E8, func_0216C204, func_0216C270, func_0216C280, func_0216C2A4, func_0216C2FC, func_0216C44C, func_0216C484, func_0216C538, func_0216C640, func_0216C680, func_0216C6E8, func_0216C7FC, func_0216C860, func_0216C888, func_0216C8B0, func_0216C8CC, func_0216C978, func_0216C9CC, func_0216C9F4, func_0216CAA8, func_0216CAD4, func_0216CAF4, func_0216CB48, func_0216CC30, func_0216CC40
 * address:  0x0216BFD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 and 0x0216CC58 (__FILE__ anchors: namein_setup.c up to 0x0216CC40, fldmmdl.c from 0x0216CC58).
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   ICA_ANIME_CreateFull  0x020114D0  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02011610  0x02011610  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021F3714  0x021F3714  thumb  ov050
 *   func_021F37B8  0x021F37B8  thumb  ov050
 *   func_021F3758  0x021F3758  thumb  ov050
 *   func_021F3808  0x021F3808  thumb  ov050
 *   func_021F3744  0x021F3744  thumb  ov050
 *   func_021F3788  0x021F3788  thumb  ov050
 *   func_021BE92C  0x021BE92C  thumb
 *   func_021D2D50  0x021D2D50  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   func_021CBD08  0x021CBD08  thumb  ov021
 *   func_0216E8CC  0x0216E8CC  thumb  ov010
 *   func_02191388  0x02191388  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb
 *   func_021B09EC  0x021B09EC  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_020146F8  0x020146F8  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PROCSYS_Main  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   PROCSYS_Push  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 *   func_02161824  0x02161824  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   GAME_EVENT_Create   0x020122C0  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 */
struct IcaAnime;
typedef unsigned char u8;

typedef struct Strbuf Strbuf;
typedef unsigned short u16;
typedef unsigned int u32;
/*
 * Argument block of the name input screen (0x2c bytes). Kind 0 asks for a
 * player name; kind 1 asks for a monster nickname, either from a species and
 * traits pair or from the monster itself (func_0216C028).
 */
typedef struct NameInArgs {
    int kind;           /* 0x00 */
    u16 species;        /* 0x04 */
    u16 traits;         /* 0x06: gender in the high byte, form in the low byte */
    void *mon;          /* 0x08 */
    Strbuf *boxName;    /* 0x0C */
    void *boxManager;   /* 0x10 */
    int boxIndex;       /* 0x14 */
    int maxLen;         /* 0x18 */
    int canceled;       /* 0x1C */
    Strbuf *name;       /* 0x20 */
    u32 reserved24;     /* 0x24 */
    void *pokedex;      /* 0x28 */
} NameInArgs;

typedef int s32;
typedef s32 fx32;
typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct FieldMap FieldMap;
typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;
/* Eight words of camera target data, copied from the table at d_02172528. */
typedef struct CameraTarget {
    int words[8];
} CameraTarget;
/* Camera move request the fall event hands to the ov021 camera helper (0x4C bytes). */
typedef struct CameraMoveParam {
    int frames;         /* 0x00: 0x14 */
    int startArgs[8];   /* 0x04 */
    CameraTarget target;/* 0x24 */
    int easeIn;         /* 0x44 */
    int easeOut;        /* 0x48 */
} CameraMoveParam;
/* Work of the fall event (0x64 bytes): camera move, landing animation, hand-off to the land event. */
typedef struct FallEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    void *camera;               /* 0x08 */
    void *cameraStatus;         /* 0x0C */
    struct IcaAnime *anim;      /* 0x10 */
    CameraMoveParam cameraMove; /* 0x14 */
    void *playerObj;            /* 0x60 */
} FallEventWork;
/* Screen change request for the land event's result screen (0x18 bytes). */
typedef struct ScreenChangeParam {
    u16 mode;           /* 0x00 */
    u16 variant;        /* 0x02 */
    u16 startDelay;     /* 0x04 */
    u16 step;           /* 0x06 */
    u16 colorLow;       /* 0x08 */
    u16 colorHigh;      /* 0x0A */
    u16 screenMask;     /* 0x0C */
    u8 fadeOutKind;     /* 0x0E */
    u8 fadeInKind;      /* 0x0F */
    u32 effectKind;     /* 0x10 */
    u32 reserved14;     /* 0x14 */
} ScreenChangeParam;
/* Work of the land event (0x14 bytes). */
typedef struct LandEventWork {
    u16 heapId;                 /* 0x00 */
    GameSystem *gameSystem;     /* 0x04 */
    FieldMap *fieldMap;         /* 0x08 */
    void *camera;               /* 0x0C */
    struct IcaAnime *anim;      /* 0x10 */
} LandEventWork;
typedef struct GameData GameData;
typedef struct Mmdl Mmdl;
typedef struct MsgBank MsgBank;
/* Transition request record behind EncounterContext.transitionInfo; only the scene id is read here. */
typedef struct TransitionInfo {
    u8 reserved00[0x18];
    u16 sceneId;        /* 0x18 */
} TransitionInfo;
/* Summary screen argument block, embedded in PartyTaskWork (0x28 bytes). */
typedef struct SummaryArgs {
    void *party;        /* 0x00 */
    u32 reserved04;
    GameData *gameData; /* 0x08 */
    u8 mode;            /* 0x0C: 1 */
    u8 startSlot;       /* 0x0D */
    u8 partyCount;      /* 0x0E */
    u8 reserved0F;
    u8 startPage;       /* 0x10 */
    u8 reserved11[7];
    void *statusData;   /* 0x18 */
    u8 reserved1C[0xC];
} SummaryArgs;
/* Party screen argument block, embedded in PartyTaskWork (0x98 bytes). */
typedef struct PartyScreenArgs {
    void *party;        /* 0x00 */
    u8 reserved04[0x10];
    void *regulation;   /* 0x14: loaded for the screen, freed when it closes */
    u8 reserved18[0x1C];
    u32 screenType;     /* 0x34: 0x16 */
    u32 selectMode;     /* 0x38 */
    u32 pickedSlot;     /* 0x3C */
    u32 pickedSub;      /* 0x40 */
    u8 reserved44[5];
    u8 pickedSlots[6];  /* 0x49 */
    u8 reserved4F[0x49];
} PartyScreenArgs;
/* Work of the party pick task (0xD8 bytes). */
typedef struct PartyTaskWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    SummaryArgs summary;        /* 0x08 */
    PartyScreenArgs partyScreen;/* 0x30 */
    u16 *pickedSubOut;          /* 0xC8 */
    u16 *pickedSlotOut;         /* 0xCC */
    u8 *pickedSlotsOut;         /* 0xD0 */
    u8 reservedD4[4];
} PartyTaskWork;
/* Encounter context of the field caller (at least 0x7D0 bytes): what asked for the pick and where its results go. */
typedef struct EncounterContext {
    u8 reserved00[9];
    u8 kind;                    /* 0x009 */
    u8 reserved0A[0x72];
    u8 pickedSlots[6];          /* 0x07C */
    u16 pickResult;             /* 0x082 */
    u16 pickResultSub;          /* 0x084 */
    u8 reserved86[0x7C8 - 0x86];
    void *party;                /* 0x7C8 */
    int transitionInfo;         /* 0x7CC */
} EncounterContext;
/* Work of the name balloon tasks: C6E8 allocates 0xD8 bytes, CB48 only 0x1C. */
typedef struct NameBalloonWork {
    GameSystem *gameSystem;     /* 0x00 */
    u32 reserved04;
    VecFx32 pos;                /* 0x08 */
    void *balloon;              /* 0x14 */
    Strbuf *name;               /* 0x18 */
    u16 npcId;                  /* 0x1C */
} NameBalloonWork;
/* One 0x22-byte entry of the history table; the name balloon shows its name. */
typedef struct HistoryEntry {
    u8 reserved00[0x18];
    u16 nameChars[5];           /* 0x18 */
} HistoryEntry;
/* One 0x120-byte record of the table the name balloon reads its text from. */
typedef struct NameBalloonRecord {
    u8 reserved00[0xA0];
    u16 nameChars[2];           /* 0xA0: 0xFFFF then a message index, or the first characters of a name */
    u8 reservedA4[0x120 - 0xA4];
} NameBalloonRecord;
/* Work of the history screen task (0x14 bytes). */
typedef struct HistoryScreenWork {
    FieldMap *fieldMap;         /* 0x00 */
    GameSystem *gameSystem;     /* 0x04 */
    GameData *gameData;         /* 0x08 */
    int historyTagA;            /* 0x0C */
    int historyTagB;            /* 0x10 */
} HistoryScreenWork;
/* Parameter block of the sub proc call (the last three words of ProcCallWork). */
typedef struct ProcCallParam {
    GameData *gameData;         /* 0x00 */
    TransitionInfo *transitionInfo; /* 0x04 */
    void *extra;                /* 0x08 */
} ProcCallParam;
/* Work of the proc call task (0x3C bytes). */
typedef struct ProcCallWork {
    GameSystem *gameSystem;     /* 0x00 */
    TransitionInfo *transitionInfo; /* 0x04 */
    void *extra;                /* 0x08 */
    ProcCallParam param;        /* 0x0C */
    u8 reserved18[0x24];
} ProcCallWork;
/* Work of the scene event task (0x10 bytes). */
typedef struct SceneEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    TransitionInfo *transitionInfo; /* 0x08 */
    void *extra;                /* 0x0C */
} SceneEventWork;
extern void *func_02012EBC(GameData *gameData);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045838(Strbuf *dst, Strbuf *src);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02045808(Strbuf *s);
extern void func_020307B0(void *);
extern void func_0218FEA4(void *playerObj);
extern void func_0218FE78(void *camera, int *startArgs);
extern int func_0218FF00(u32 a);
extern int func_021C6E48(void *cameraStatus);
extern void func_0218FE98(void *playerObj);
extern u16 func_02188C84(FieldMap *fieldMap);
extern void *ICA_ANIME_CreateFull(u32 heap, u32 a1, u32 a2);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02011610(struct IcaAnime *anim, VecFx32 *out);
extern void *func_02188D2C(FieldMap *fieldMap);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(FieldMap *fieldMap);
extern void func_021A3038(void *playerObj, VecFx32 *out);
extern void func_021A3044(void *playerObj, void *pos);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_02011558(struct IcaAnime *p);
extern void *func_021BE8D4(GameSystem *, FieldMap *, u32, u32);
extern void *func_021854B0(GameSystem *gameSystem, FieldMap *fieldMap, u32 id, Pos *pos, u32 flag);
extern void func_02012374(GameEvent *event, GameEvent *next);
extern void func_0201235C(GameEvent *event, GameEvent *next);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, void *func, u32 size);
extern void *func_020124E8(GameEvent *event);
extern void *func_02188C58(FieldMap *fieldMap);
extern void *func_02188D38(FieldMap *fieldMap);
extern void *func_0218FE80(FieldMap *fieldMap);
extern void func_0218FEA0(void *playerObj, CameraMoveParam *param);
extern void func_02163E58(void *mapObj, VecFx32 *pos, fx32 *groundY);
extern void func_0218F0A8(void *camera);
extern u32 func_0218F0E8(void *camera);
extern void func_021F3714(FieldMap *fieldMap);
extern void func_021F37B8(FieldMap *fieldMap);
extern int func_021F3758(FieldMap *fieldMap);
extern int func_021F3808(FieldMap *fieldMap);
extern void func_021F3744(FieldMap *fieldMap);
extern void func_021F3788(FieldMap *fieldMap);
extern void *func_021BE92C(GameSystem *, FieldMap *, u32, u32, u32, u32, u32);
extern void *func_021D2D50(GameSystem *gameSystem, ScreenChangeParam *param);
extern void *func_021A3074(void *playerObj);
extern void func_020061F8(int i);
extern void func_020061E4(u32 se);
extern GameEvent *FIELD_STATUS_CreateFieldCloseEvent(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *func_02014910(GameSystem *gameSystem, FieldMap *fieldMap, PartyScreenArgs *partyScreen, SummaryArgs *summary);
extern GameEvent *FIELD_STATUS_CreateFieldOpenEvent(GameSystem *gameSystem);
extern void func_02082D44(const void *src, void *dst, int size);
extern GameData *func_020120F4(GameSystem *gameSystem);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern void *func_02012934(GameData *gameData);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_0201A354(int a, int b);
extern void *func_0200CA1C(GameData *gameData);
extern u32 func_0201AA18(void *party);
extern u32 func_0200CA38(void *p);
extern void BATTLE_REC_AllocWork(u32 heap);
extern u32 func_021CBD08(EncounterContext *ctx, GameSystem *gameSystem);
extern int func_0216E8CC(GameSystem *, FieldMap *, int);
extern int func_02191388();
extern void func_021914CC(void *balloon);
extern u32 func_020362DC(void);
extern int func_021912D8(void *balloon);
extern int func_021912F8();
extern void *func_02188C54(FieldMap *fieldMap);
extern MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(MsgBank *bank, u32 index, Strbuf *dest);
extern u32 func_02045C04(MsgBank *bank);
extern Strbuf *PMSI_PARAM_ToString(const u16 *chars, unsigned int heap);
extern void *func_02012964(GameData *gameData);
extern u32 func_0218EC2C(void *camera);
extern void func_021B09D8(VecFx32 *pos, VecFx32 *offset, u32 mapKind, void *camera, void *dir);
extern void func_021B09EC(int dir, int *kind, int *flags);
extern void *func_0219129C(void *manager, int kind, VecFx32 *pos, Strbuf *name, u32 c, u32 flags);
extern void *GAME_DATA_GetSaveBlock3B(GameData *gameData);
extern int func_0200DF40(void *history);
extern u8 func_0200DF4C(void *history);
extern GameEvent *func_020146F8(GameSystem *gameSystem, FieldMap *fieldMap, int procId, void *procData, void *param);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern void **func_0203159C(void *proc, int size, int heapId);
extern void *PROCSYS_Create(int heapId);
extern void func_0203133C(void *w);
extern void func_020315D4(void *proc);
extern void func_020306F0(unsigned int);
extern unsigned int PROCSYS_Main(void *p);
extern int func_02034AC4(s32 handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void *func_020399A8(void);
extern void GFL_NET_StartTimingSync(int, int);
extern u32 func_0200FB24(void);
extern int GFL_NET_CheckTimingSync(int, int);
extern void PROCSYS_Push(int, int, char *, int);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(s32 handle);
extern void GAMESYSTEM_CallProc(GameSystem *gameSystem, u32 id, const void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(GameSystem *gameSystem);
extern GameEvent *func_02161824(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(GameSystem *gameSystem, u32 b);
extern u32 func_02188CE8(FieldMap *fieldMap);
extern void func_021AAABC(int);
extern void *func_02189A08(FieldMap *fieldMap);
extern void func_021CF498(void *p, GameEvent *event, int mode);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(GameSystem *gameSystem);
extern GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(GameSystem *gameSystem);
extern void *func_021CBD84(EncounterContext *ctx);
extern int func_021B0A40(void *m2, VecFx32 *pos);
extern void *func_020071CC(void *saveControl, u32 id);
extern void *func_0200DF58(void *bsubwaySave, u32 heap);
extern GameSystem *func_0215A5DC(void *scriptWork);
extern void *func_02012EC4(GameData *gameData);
extern s32 *func_0200B3A4(void *fieldSave, u32 b);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern Mmdl *func_0216DE94(void *occupyInfo, u32 id);
extern void *func_0216DEE0(void *occupyInfo);
NameInArgs *func_0216BFD4(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *func_0216C028(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *func_0216C0A4(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex);
void func_0216C0C0(NameInArgs *args);
void func_0216C0D4(NameInArgs *args, Strbuf *dest);
int func_0216C0E4(NameInArgs *args);
int func_0216C0E8(GameEvent *event, u32 *state, FallEventWork *work);
GameEvent *func_0216C204(GameSystem *gameSystem, FieldMap *fieldMap);
int func_0216C270(LandEventWork *work);
void *func_0216C280(LandEventWork *work);
void func_0216C2A4(LandEventWork *work);
int func_0216C2FC(GameEvent *event, u32 *state, LandEventWork *work);
GameEvent *func_0216C44C(GameSystem *gameSystem, FieldMap *fieldMap);
int func_0216C484(GameEvent *event, int *state, PartyTaskWork *work);
GameEvent *func_0216C538(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty);
void func_0216C640(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int func_0216C680(GameEvent *event, int *state, NameBalloonWork *work, u32 extra);
GameEvent *func_0216C6E8(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir);
int func_0216C7FC(GameEvent *event, int *state, HistoryScreenWork *work);
GameEvent *func_0216C860(GameSystem *gameSystem);
int func_0216C888(void *proc, int *seq, void *pwk, void *mywk);
int func_0216C8B0(void *proc, int *seq, void *pwk, void **mywk);
int func_0216C8CC(void *proc, int *seq, int *pwk, int *mywk);
int func_0216C978(GameEvent *event, int *state, ProcCallWork *work);
GameEvent *func_0216C9CC(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra);
int func_0216C9F4(GameEvent *event, int *state, SceneEventWork *work);
GameEvent *func_0216CAA8(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra);
void func_0216CAD4(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int func_0216CAF4(GameEvent *event, int *state, NameBalloonWork *work);
GameEvent *func_0216CB48(GameSystem *gameSystem, int recordIndex, u8 npcId);
int func_0216CC30(void *scriptCtx, void *scriptWork);
void func_0216CC40(GameSystem *gameSystem);
extern char d_02172A60[];
extern CameraTarget d_02172528;
extern char d_021BA650[];
extern char id_00000045[];
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_02172548[];


/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. func_02045838 takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
NameInArgs *func_0216BFD4(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex)
{
    NameInArgs *args = func_02030734(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x37);
    func_02082BCC(args, 0, sizeof(NameInArgs));
    args->kind = kind;
    args->maxLen = maxLen;
    args->species = species;
    args->traits = traits;
    args->pokedex = pokedex;
    args->name = func_020457B0(0xb, heapId);
    if (initialName)
        func_02045838(args->name, initialName);
    return args;
}






/*
 * The heap id is a u16, as in func_0216BFD4; that keeps its entry spill
 * at the front of the prologue.
 */
NameInArgs *func_0216C028(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex)
{
    NameInArgs *args = func_02030734(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x59);
    func_02082BCC(args, 0, sizeof(NameInArgs));
    args->kind = 1;
    args->maxLen = maxLen;
    args->mon = mon;
    args->pokedex = pokedex;
    if (mon) {
        int low;
        args->species = func_02017E1C(mon, 5, 0);
        low = func_02017E1C(mon, 0x6f, 0);
        args->traits = (func_02017E1C(mon, 0x6e, 0) << 8) | low;
    }
    args->name = func_020457B0(0xb, heapId);
    if (initialName)
        func_02045838(args->name, initialName);
    return args;
}





NameInArgs *func_0216C0A4(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex)
{
    NameInArgs *args = func_0216C028(heapId, mon, maxLen, initialName, pokedex);
    args->boxName = boxName;
    args->boxManager = boxManager;
    args->boxIndex = boxIndex;
    return args;
}






void func_0216C0C0(NameInArgs *args)
{
    func_02045808(args->name);
    func_020307B0(args);
}






void func_0216C0D4(NameInArgs *args, Strbuf *dest)
{
    func_02045838(dest, args->name);
}





int func_0216C0E4(NameInArgs *args)
{
    return args->canceled;
}






/*
 * Eight-state proc of the field event beside func_0216C2FC: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 */
int func_0216C0E8(GameEvent *event, u32 *state, FallEventWork *work)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    void *cameraStatus = work->cameraStatus;
    void *playerObj;

    switch (*state) {
    case 0:
        func_0218FEA4(work->playerObj);
        func_0218FE78(work->camera, work->cameraMove.startArgs);
        func_0218FF00((u32)work->playerObj);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(cameraStatus) != 0) {
            func_0218FE98(work->playerObj);
            (*state)++;
        }
        break;
    case 2:
        work->anim = ICA_ANIME_CreateFull(func_02188C84(fieldMap), 0x9D, 0x18);
        func_0200616C((void *)1953, func_02006148(1953));
        (*state)++;
        break;
    case 3:
        func_02011610(work->anim, &cur);
        func_021BE480(func_02188D2C(fieldMap), 0, 0)->y = cur.y;
        playerObj = func_02188CB4(fieldMap);
        func_021A3038(playerObj, &v);
        v.y = cur.y;
        func_021A3044(playerObj, &v);
        if (func_02011590(work->anim, 0x1000) != 0) {
            func_02011558(work->anim);
            (*state)++;
        }
        break;
    case 4:
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        func_02012374(event, func_021854B0(gameSystem, fieldMap, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        func_0201235C(event, func_0216C44C(gameSystem, fieldMap));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}






GameEvent *func_0216C204(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, (void *)func_0216C0E8, 0x64);
    FallEventWork *work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->anim = 0;
    work->camera = func_02188C58(fieldMap);
    work->cameraStatus = func_02188D38(fieldMap);
    work->cameraMove.frames = 0x14;
    work->cameraMove.target = d_02172528;
    work->cameraMove.easeIn = 1;
    work->cameraMove.easeOut = 1;
    work->playerObj = func_0218FE80(fieldMap);
    func_0218FEA0(work->playerObj, &work->cameraMove);
    return event;
}






int func_0216C270(LandEventWork *work)
{
    return func_02011590(work->anim, 0x1000);
}




/*
 * unblocked: func_021BE480 (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  func_02188D2C was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 */
void *func_0216C280(LandEventWork *work)
{
    VecFx32 animPos;
    VecFx32 *mapPos;

    func_02011610(work->anim, &animPos);
    mapPos = func_021BE480(func_02188D2C(work->fieldMap), 0, 0);
    mapPos->y = animPos.y;

    return mapPos;
}



#pragma opt_propagation off


/*
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object.
 *
 * pass 6 2026-10-06 P6L05: closed from a capture of the compiler's register
 * colouring (debugger break at the colour select step of mwccarm). The
 * graph showed y with a long live range (stored after the x snap) was
 * coloured early and took r3. Storing v.y first makes y short-lived, so it
 * is coloured late, after x; reading z, y, x (x snapped first, its load
 * hoisted) gives the image's load order x, z, y. EXACT in c99 and c.
 */
void func_0216C2A4(LandEventWork *work)
{
    VecFx32 snapped;
    const VecFx32 *mapPos;
    void *playerObj;
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 k;

    mapPos = func_021BE480(func_02188D2C(work->fieldMap), 0, 0);
    playerObj = func_02188CB4(work->fieldMap);
    z = mapPos->z;
    y = mapPos->y;
    x = mapPos->x;
    k = 0x20000;
    z = z + k;
    snapped.y = y;
    snapped.x = (((x >> 12) / 16) << 16) + 0x8000;
    snapped.z = (((z >> 12) / 16) << 16) + 0x8000;
    func_021A3044(playerObj, &snapped);
}


#pragma opt_propagation reset






/*
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 */
int func_0216C2FC(GameEvent *event, u32 *state, LandEventWork *work)
{
    ScreenChangeParam param;
    VecFx32 playerPos;
    fx32 groundY;
    int landed;
    void *playerObj;
    void *mapObj;

    func_02188D2C(work->fieldMap);
    switch (*state) {
    case 0:
        work->anim = ICA_ANIME_CreateFull(work->heapId, 0x9D, 0x19);
        func_0216C280(work);
        func_0216C2A4(work);
        func_0218F0A8(work->camera);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(work->camera) == 0)
            (*state)++;
        break;
    case 2:
        func_021F3714(work->fieldMap);
        func_021F37B8(work->fieldMap);
        func_02012374(event, func_021BE92C(work->gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        landed = func_0216C270(work);
        if (landed == 0) {
            func_0216C280(work);
            func_0216C2A4(work);
        }
        if (landed != 0) {
            func_02011558(work->anim);
            func_020061F8(func_02006148(1953));
            func_020061E4(1775);
            param.mode = 2;
            param.variant = 0;
            param.effectKind = 3;
            param.fadeInKind = 2;
            param.fadeOutKind = 2;
            param.reserved14 = 0;
            param.startDelay = 0;
            param.step = 1;
            param.colorLow = 0;
            param.colorHigh = 0;
            param.screenMask = 2;
            func_02012374(event, func_021D2D50(work->gameSystem, &param));
            (*state)++;
        }
        break;
    case 4:
        if (func_021F3758(work->fieldMap) && func_021F3808(work->fieldMap)) {
            func_021F3744(work->fieldMap);
            func_021F3788(work->fieldMap);
            (*state)++;
        }
        break;
    case 5:
        playerObj = func_02188CB4(work->fieldMap);
        mapObj = func_021A3074(playerObj);
        func_021A3038(playerObj, &playerPos);
        func_02163E58(mapObj, &playerPos, &groundY);
        playerPos.y = groundY;
        func_021A3044(playerObj, &playerPos);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}







GameEvent *func_0216C44C(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event;
    LandEventWork *work;

    event = func_020122C0(gameSystem, 0, (void *)func_0216C2FC, 0x14);
    work = func_020124E8(event);
    work->heapId = func_02188C84(fieldMap);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->camera = func_02188C58(fieldMap);
    work->anim = 0;
    return event;
}








int func_0216C484(GameEvent *event, int *state, PartyTaskWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    switch (*state) {
    case 0:
        func_02012374(event, func_021BE8D4(gameSystem, work->fieldMap, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*state)++;
        break;
    case 2:
        func_02012374(event, func_02014910(gameSystem, work->fieldMap, &work->partyScreen, &work->summary));
        (*state)++;
        break;
    case 3:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 4:
        func_02012374(event, func_021BE92C(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        func_02082D44(work->partyScreen.pickedSlots, work->pickedSlotsOut, 6);
        *work->pickedSlotOut = work->partyScreen.pickedSlot;
        *work->pickedSubOut = work->partyScreen.pickedSub;
        func_020307B0(work->partyScreen.regulation);
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}








/*
 * Starts the func_0216C484 task over a 0xD8-byte work: points it at the
 * result fields of the encounter context, picks the party (the player's, or
 * the one at +0x7C8 when useOwnParty is set), and fills the party-screen and
 * summary argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * kind at +9 of the context.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order fieldMap, event,
 * gameData for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 */
GameEvent *func_0216C538(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty)
{
    FieldMap *fieldMap;
    GameEvent *event;
    GameData *gameData;
    PartyTaskWork *work;
    void *party;
    PartyScreenArgs *partyScreen;
    SummaryArgs *summary;
    void *statusData;
    u32 screenMode;
    u32 selectMode;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, func_0216C484, sizeof(PartyTaskWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->pickedSlotsOut = ctx->pickedSlots;
    work->pickedSlotOut = &ctx->pickResult;
    work->pickedSubOut = &ctx->pickResultSub;
    if (useOwnParty == 0)
        party = func_02012934(gameData);
    else
        party = ctx->party;
    screenMode = 0x14;
    selectMode = 0;
    partyScreen = &work->partyScreen;
    MI_CpuFill8(partyScreen, 0, sizeof(PartyScreenArgs));
    partyScreen->party = party;
    switch (ctx->kind) {
    case 1:
    case 6:
        screenMode = 0x15;
        selectMode = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        screenMode = 0x16;
        selectMode = 2;
        break;
    }
    partyScreen->regulation = func_0201A354(screenMode, 4);
    partyScreen->screenType = 0x16;
    partyScreen->selectMode = selectMode;
    summary = &work->summary;
    statusData = func_0200CA1C(gameData);
    MI_CpuFill8(summary, 0, sizeof(SummaryArgs));
    summary->party = party;
    summary->mode = 1;
    summary->partyCount = func_0201AA18(party);
    summary->startSlot = 0;
    summary->startPage = 0;
    summary->gameData = gameData;
    summary->statusData = (void *)func_0200CA38(statusData);
    return event;
}








/*
 * lever: The result of func_021CBD08 remains live in r2 and is the third argument of func_0216E8CC.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
void func_0216C640(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    int transitionInfo;
    BATTLE_REC_AllocWork(4);
    transitionInfo = func_021CBD08(ctx, gameSystem);
    ctx->transitionInfo = transitionInfo;
    if (ctx->kind == 3 || ctx->kind == 8) {
        func_0216CAD4(ctx, gameSystem, fieldMap);
        return;
    }
    func_0216E8CC(gameSystem, fieldMap, transitionInfo);
}








int func_0216C680(GameEvent *event, int *state, NameBalloonWork *work, u32 extra)
{
    switch (*state) {
    case 0:
        if (!func_02191388(work->balloon))
            break;
        (*state)++;
    case 1:
        func_021914CC(work->balloon);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(work->balloon);
        (*state)++;
        break;
    case 2:
        if (func_021912F8(work->balloon, (u32)state, (u32)work, extra) == 1) {
            func_02045808(work->name);
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 */
GameEvent *func_0216C6E8(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir)
{
    VecFx32 offset;
    int balloonKind;
    int balloonFlags;
    GameEvent *event;
    GameData *gameData;
    void *balloonManager;
    FieldMap *fieldMap;
    NameBalloonWork *work;
    MsgBank *bank;
    void *camera;
    u16 msgIndex;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    balloonManager = func_02188C54(fieldMap);
    event = func_020122C0(gameSystem, 0, func_0216C680, 0xD8);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->npcId = npcId;
    if (*(u16 *)((u32)records + 0xA0 + recordIndex * 0x120) == 0xFFFF) {
        work->name = func_020457B0(0x300, 4);
        bank = MSGDATA_CreateFromArchive(0, 2, 0xB8, 4);
        msgIndex = *(u16 *)((u32)records + 0xA2 + recordIndex * 0x120);
        if (msgIndex >= 0x3AE)
            msgIndex = 0;
        func_02045CAC(bank, msgIndex, work->name);
        func_02045C04(bank);
    } else {
        work->name = PMSI_PARAM_ToString((u16 *)((u32)records + 0xA0 + recordIndex * 0x120), 4);
    }
    func_0216D88C(func_0216DE94(func_02012964(gameData), work->npcId), &work->pos);
    camera = func_02188C58(fieldMap);
    func_021B09D8(&work->pos, &offset, func_0218EC2C(camera), camera, (void *)dir);
    work->pos.x += offset.x;
    work->pos.y += offset.y;
    work->pos.z += offset.z;
    func_021B09EC(dir, &balloonKind, &balloonFlags);
    work->balloon = func_0219129C(balloonManager, balloonKind, &work->pos, work->name, 0, balloonFlags);
    return event;
}








/*
 * blockers: GAME_DATA_GetSaveBlock3B (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C7FC(GameEvent *event, int *state, HistoryScreenWork *work)
{
    void *history;
    switch (*state) {
    case 0:
        work->gameData = func_020120F4(work->gameSystem);
        history = GAME_DATA_GetSaveBlock3B(work->gameData);
        work->historyTagA = func_0200DF40(history);
        work->historyTagB = func_0200DF4C(history);
        func_02012374(event, func_020146F8(work->gameSystem, work->fieldMap, (int)id_00000045, d_021BA650, &work->gameData));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}







GameEvent *func_0216C860(GameSystem *gameSystem)
{
    FieldMap *fieldMap;
    GameEvent *event;
    HistoryScreenWork *work;

    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, (void *)func_0216C7FC, 0x14);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}








/* GFL_PROC init callback: creates the 0x76 heap and the proc work holding one allocation. */
int func_0216C888(void *proc, int *seq, void *pwk, void *mywk)
{
    void **work;

    func_0203064C(1, 0x76, 0x4000);
    work = func_0203159C(proc, 4, 0x76);
    *work = PROCSYS_Create(0x76);
    return 1;
}







/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int func_0216C8B0(void *proc, int *seq, void *pwk, void **mywk)
{
    func_0203133C(*mywk);
    func_020315D4(proc);
    func_020306F0(0x76);
    return 1;
}






/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C8CC(void *proc, int *seq, int *pwk, int *mywk)
{
    int status = PROCSYS_Main((void *)mywk[0]);
    switch (*seq) {
    case 0:
        func_02034AC4((s32)id_0000005D);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync((int)func_020399A8(), 0xc8);
        *seq = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *seq = 4;
            break;
        }
        if (GFL_NET_CheckTimingSync((int)func_020399A8(), 0xc8) == 0)
            break;
        *seq = 2;
        break;
    case 2:
        PROCSYS_Push(mywk[0], ~0, d_021EFDAC, pwk[1]);
        *seq = 3;
        break;
    case 3:
        if (status == 1)
            break;
        *seq = 4;
        break;
    case 4:
        func_0203A5E4(0x100);
        func_02034A5C((s32)id_0000005D);
        *seq = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}






int func_0216C978(GameEvent *event, int *state, ProcCallWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    ProcCallParam *param;
    switch (*state) {
    case 0:
        param = &work->param;
        param->gameData = func_020120F4(gameSystem);
        param->transitionInfo = work->transitionInfo;
        param->extra = work->extra;
        GAMESYSTEM_CallProc(gameSystem, ~0, d_02172548, param);
        (*state)++;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            return 1;
        break;
    }
    return 0;
}





GameEvent *func_0216C9CC(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra)
{
    GameEvent *event;
    ProcCallWork *work;
    event = func_020122C0(gameSystem, 0, (void *)func_0216C978, 0x3c);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    return event;
}






int func_0216C9F4(GameEvent *event, int *state, SceneEventWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    switch (*state) {
    case 0:
        func_02012374(event, func_02161824(gameSystem, fieldMap));
        (*state)++;
        break;
    case 1:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, work->transitionInfo->sceneId));
        (*state)++;
        break;
    case 2:
        func_021AAABC(func_02188CE8(fieldMap));
        func_021CF498(func_02189A08(work->fieldMap), event, 9);
        (*state)++;
        break;
    case 3:
        func_02012374(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*state)++;
        break;
    case 4:
        func_02012374(event, func_0216C9CC(gameSystem, work->transitionInfo, work->extra));
        (*state)++;
        break;
    case 5:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        (*state)++;
        break;
    case 6:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 7:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    case 8:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}





GameEvent *func_0216CAA8(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra)
{
    GameEvent *event;
    SceneEventWork *work;
    event = func_020122C0(gameSystem, 0, (void *)func_0216C9F4, 0x10);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    work->fieldMap = fieldMap;
    return event;
}






/*
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The far field (0x7CC) of the context and the arm9 probe result are the
 * last two arguments of the four-argument overlay call.
 */
void func_0216CAD4(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    void *extra = func_021CBD84(ctx);

    func_0216CAA8(gameSystem, fieldMap, (TransitionInfo *)ctx->transitionInfo, extra);
}






int func_0216CAF4(GameEvent *event, int *state, NameBalloonWork *work)
{
    switch (*state) {
    case 0:
        if (func_02191388(work->balloon) == 1)
            (*state)++;
        break;
    case 1:
        if ((func_020362DC() & 3) == 0)
            break;
        func_021912D8(work->balloon);
        (*state)++;
        break;
    case 2:
        if (func_021912F8(work->balloon) == 1) {
            func_02045808(work->name);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the work->gameSystem store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */
GameEvent *func_0216CB48(GameSystem *gameSystem, int recordIndex, u8 npcId)
{
    GameData *gameData;
    FieldMap *fieldMap;
    void *balloonManager;
    GameEvent *event;
    NameBalloonWork *work;
    void *occupyInfo;
    void *mmdlSys;
    void *camera;
    VecFx32 offset;
    int balloonKind;
    int balloonFlags;
    HistoryEntry *entries;
    int dir;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    balloonManager = func_02188C54(fieldMap);
    event = func_020122C0(gameSystem, 0, func_0216CAF4, 0x1C);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    occupyInfo = func_02012964(gameData);
    mmdlSys = func_0216DEE0(occupyInfo);
    func_0216D88C(func_0216DE94(occupyInfo, npcId), &work->pos);
    dir = func_021B0A40(mmdlSys, &work->pos);
    camera = func_02188C58(fieldMap);
    func_021B09D8(&work->pos, &offset, func_0218EC2C(camera), camera, (void *)dir);
    work->pos.x += offset.x;
    work->pos.y += offset.y;
    work->pos.z += offset.z;
    entries = func_0200DF58(func_020071CC(func_02012EBC(gameData), 0x3b), 4);
    work->name = PMSI_PARAM_ToString(entries[recordIndex].nameChars, 4);
    func_020307B0(entries);
    func_021B09EC(dir, &balloonKind, &balloonFlags);
    work->balloon = func_0219129C(balloonManager, balloonKind, &work->pos, work->name, 0, balloonFlags);
    return event;
}






/* Script command: raise the save flag in the field save block (the command context is unused). */
int func_0216CC30(void *scriptCtx, void *scriptWork)
{
    GameSystem *gameSystem;

    gameSystem = func_0215A5DC(scriptWork);
    func_0216CC40(gameSystem);
    return 0;
}





/*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 */
void func_0216CC40(GameSystem *gameSystem)
{
    *func_0200B3A4(func_02012EC4(func_020120F4(gameSystem)), 0x34) = 1;
}

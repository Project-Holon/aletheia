/*
 * file:     scrcmd_work.c
 * unit:     yes
 * function: func_0215A514, func_0215A554, func_0215A55C, func_0215A5A4, func_0215A5CC, func_0215A5D0, func_0215A5D4, func_0215A5D8, func_0215A5DC, func_0215A5E4, func_0215A5EC, func_0215A5F4, func_0215A5FC, func_0215A60C, func_0215A610, func_0215A614, func_0215A61C, func_0215A624, func_0215A630, func_0215A63C, func_0215A644, func_0215A64C, func_0215A654, func_0215A660, func_0215A66C, func_0215A678, func_0215A684, func_0215A6FC, func_0215A738, func_0215A760, func_0215A77C, func_0215A7F0, func_0215A864, func_0215A920, func_0215A954, func_0215A990, func_0215A9C0, func_0215AA24, func_0215AA34, func_0215AA48, func_0215AA4C, func_0215AA50, func_0215AA60, func_0215AA90, func_0215AABC, func_0215AADC, func_0215AAF4, func_0215AB18, func_0215AB3C, func_0215AB60, func_0215AB98, func_0215ABD0, func_0215ABEC, func_0215AC1C, func_0215AC3C, func_0215AC68, func_0215ACA8, func_0215ACC8, func_0215AD38, func_0215AD50, func_0215AD7C, func_0215ADCC, func_0215AE34, func_0215AEB8, func_0215AEE8, func_0215AF40, func_0215AF98, func_0215AFE0, func_0215AFF4, func_0215B014, func_0215B028, func_0215B068, func_0215B084, func_0215B0B4, func_0215B104, func_0215B138, func_0215B158, func_0215B190, func_0215B214, func_0215B26C, func_0215B2C4, func_0215B328, func_0215B350, func_0215B378, func_0215B3AC, func_0215B3DC, func_0215B408, func_0215B438, func_0215B464
 * address:  0x0215A514
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
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0215AA4C  0x0215AA4C  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 *   func_0215AA48  0x0215AA48  thumb  ov010
 *   func_0215AA24  0x0215AA24  thumb  ov010
 *   func_02011290  0x02011290  thumb
 *   func_02014314  0x02014314  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02014184 0x02014184 thumb
 *   func_02159F84  0x02159F84  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02012964  0x02012964  thumb
 *   d_021728E0     0x021728E0  data  ov010  a4
 *   func_02158F6C 0x02158F6C thumb ov010
 *   func_02045C04  0x02045C04  arm
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02197DA0  0x02197DA0  thumb
 *   func_02197DAC  0x02197DAC  thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_0201F91C  0x0201F91C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045874  0x02045874  arm
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02190ACC  0x02190ACC  thumb  ov021
 *   func_02190AC4  0x02190AC4  thumb  ov021
 *   func_02190AEC  0x02190AEC  thumb  ov021
 *   func_02190B08  0x02190B08  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   d_02171140     0x02171140  data  ov010  a4
 *   func_021909BC  0x021909BC  thumb
 *   func_02045808  0x02045808  arm
 *   func_021909E4 0x021909E4 thumb ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_020202EC  0x020202EC  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 *   func_0215909C  0x0215909C  thumb  ov010
 *   func_021590D4  0x021590D4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_020056EC   0x020056EC  thumb
 *   func_0216F830  0x0216F830  thumb  ov010
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_021690F0  0x021690F0  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02169100  0x02169100  thumb  ov010
 *   func_02169110  0x02169110  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02087D28 0x02087D28 arm
 *   func_02008550   0x02008550  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C234 0x0200C234 thumb
 *   func_0200C248  0x0200C248  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 *   func_0200C258  0x0200C258  thumb
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 *   func_02012900  0x02012900  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02159F28  0x02159F28  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02159F54  0x02159F54  thumb  ov010
 *   func_020173F0  0x020173F0  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200D064  0x0200D064  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_0200D0CC  0x0200D0CC  thumb
 *   func_0200CF28  0x0200CF28  thumb
 *   func_0200CA28  0x0200CA28  thumb
 *   func_0200CA40  0x0200CA40  thumb
 *   func_02008428  0x02008428  thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 *   func_0200C308 0x0200C308 thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162A74  0x02162A74  thumb  ov010
 *   func_02162708  0x02162708  thumb  ov010
 *   func_02162748  0x02162748  thumb  ov010
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02012A44 0x02012A44 thumb
 *   func_0216EFA8 0x0216EFA8 thumb ov010
 *   d_02171160 0x02171160 data a2
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_0215A4EC  0x0215A4EC  thumb  ov010
 *   func_0215A500  0x0215A500  thumb  ov010
 */
#include "../arm9/btl_setup_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed short s16;
typedef signed int s32;

#define NULL ((void *)0)

struct ScriptWork;
struct ScriptVm;
struct GameSystem;
struct GameData;
struct OccupyInfo;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct BmpMenuWork;
struct BmpMenuList;
struct FieldMenu;
struct FieldMsgWindow;
struct AnimeTask;

/*
 * Field menu header (0x20 bytes) for the ov021 field menu list: a copy of
 * the template sScrcmdMenuHeader is completed by func_02190B08.
 */
typedef struct FieldMenuHeader {
    int itemCount;                  /* 0x00 */
    int maxLines;                   /* 0x04 */
    u16 frameId;                    /* 0x08 */
    u16 cursorMargin : 3;           /* 0x0A, added to the text width */
    u16 lineSpacing : 4;            /* 0x0A, added to the font height */
    int frameFlags;                 /* 0x0C */
    u16 fontId;                     /* 0x10 */
    u16 fontHeight;                 /* 0x12 */
    u16 posX;                       /* 0x14 */
    u16 posY;                       /* 0x16 */
    u16 width;                      /* 0x18, in characters */
    u16 height;                     /* 0x1A, in characters */
    int reserved;                   /* 0x1C */
} FieldMenuHeader;

/* Script menu state (0xA0 bytes, inside ScrcmdCommonWork at +0x34). */
typedef struct ScrcmdMenu {
    u16 x;                          /* 0x00 */
    u16 y;                          /* 0x02 */
    u16 cursorPos;                  /* 0x04 */
    u8 cancelable;                  /* 0x06 */
    u8 alignRight;                  /* 0x07, 1: x is the right edge */
    u16 *result;                    /* 0x08 */
    struct WordSet *wordSet;        /* 0x0C */
    int ownsMsgData;                /* 0x10 */
    struct MsgBank *msgData;        /* 0x14 */
    struct BmpMenuWork *items;      /* 0x18 */
    struct FieldMenu *fieldMenu;    /* 0x1C */
    struct Strbuf *itemHelp[32];    /* 0x20 */
} ScrcmdMenu;

/* Work shared by every script command of one script system (0x110 bytes). */
typedef struct ScrcmdCommonWork {
    struct ScriptWork *scriptWork;  /* 0x000 */
    struct GameSystem *gameSystem;  /* 0x004 */
    struct GameData *gameData;      /* 0x008 */
    struct OccupyInfo *occupyInfo;  /* 0x00C */
    void *targetObject;             /* 0x010 */
    struct AnimeTask *animeTasks[8]; /* 0x014 */
    ScrcmdMenu menu;                /* 0x034 */
    u8 wordSetWork[0x28];           /* 0x0D4 */
    struct FieldMsgWindow *msgWindow; /* 0x0FC */
    void *talkWindow;               /* 0x100 */
    u8 windowState;                 /* 0x104 */
    u8 windowKind;                  /* 0x105 */
    u16 waitCount;                  /* 0x106 */
    int fadeParam;                  /* 0x108 */
    int fadeState;                  /* 0x10C */
} ScrcmdCommonWork;

/* Start parameters of one script, copied into ScrcmdWork at +0x04. */
typedef struct ScrcmdWorkParam {
    u16 scriptId;                   /* 0x00 */
    u32 callParam;                  /* 0x04 */
    u32 callMode;                   /* 0x08 */
    struct ScriptWork *scriptWork;  /* 0x0C */
} ScrcmdWorkParam;

/* Per-script command work (0x24 bytes). */
typedef struct ScrcmdWork {
    u16 heapId;                     /* 0x00 */
    ScrcmdWorkParam param;          /* 0x04 */
    struct MsgBank *msgData;        /* 0x14 */
    u16 msgDataId;                  /* 0x18 */
    u8 childScriptIndex;            /* 0x1A */
    void *savedLocalWork;           /* 0x1C */
    ScrcmdCommonWork *common;       /* 0x20 */
} ScrcmdWork;

/* Owner information from the firmware user settings. */
typedef struct OwnerInfo {
    u8 language, color, month, day;
    u16 name[11], nameLength, comment[27], commentLength;
    u8 country, padding;
} OwnerInfo;

/* Calendar date as the RTC driver returns it (layout as in time_icon.c). */
typedef struct RtcDate {
    int year;
    int month;
    int day;
    int weekday;
} RtcDate;

struct ZukanSave;
struct MiscSave;
struct RecordSave;
struct BoxManager;
struct EventWork;
struct EventData;
struct MapMatrix;

/* script_work.c */
extern struct GameSystem *func_02158F54(struct ScriptWork *scriptWork);
extern int *func_02158F58(struct ScriptWork *scriptWork);
extern ScrcmdCommonWork *func_02158F6C(struct ScriptWork *scriptWork);
extern void *func_0215909C(struct ScriptWork *scriptWork);
extern int func_021590D4(struct ScriptWork *scriptWork, void *localWork);
extern int func_02159190(int);
extern int func_0215898C(struct ScriptWork *scriptWork, void *event);
u16 *func_02159AE8(struct ScriptVm *vm, ScrcmdWork *work);
unsigned int func_02159B10(struct ScriptVm *vm, ScrcmdWork *work);
extern int func_02011290(struct ScriptVm *vm);

/* map_matrix.c, map_replace.c, warp table */
int func_02159B94(struct MapMatrix *mapMatrix, int matrixId, u16 zoneId, int heapId);
void func_02159CC4(struct MapMatrix *mapMatrix, struct GameSystem *gameSystem, int heapId);
/* extent: two bytes of zero alignment padding at 0x02159F52. */
void func_02159F28(struct GameData *gameData, int replaceId, int enable);
int func_02159F54(struct GameData *gameData, int replaceId);
int func_02159F84(int warpId);

/* event_poke_status.c (event work flag offsets) */
/* interface: original narrows r1 by shift pairs; u16 extern preserves this. */
unsigned func_0215A4D8(struct EventWork *eventWork, unsigned offset);
void func_0215A4EC(struct EventWork *eventWork, unsigned offset);
void func_0215A500(struct EventWork *eventWork, unsigned offset);

/* game system and game data */
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct OccupyInfo *func_02012964(struct GameData *gameData);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *playerWork);
extern u32 func_02012AE4(const struct PlayerWork *playerWork);
extern struct PlayerPosition *func_02012AA0(struct PlayerWork *playerWork);
extern void func_0201289C(struct GameData *gameData, const struct Location *location);
extern void func_02012900(struct GameData *gameData, int warpId);
extern struct MapMatrix *func_02012974(struct GameData *gameData);
extern u8 func_02012984(struct GameData *gameData);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern struct BoxManager *func_0201293C(struct GameData *gameData);
extern struct MiscSave *func_02012F08(struct GameData *gameData);
extern struct RecordSave *GAME_DATA_GetSaveBlock21(struct GameData *gameData);
extern struct EventData *func_02012844(struct GameData *gameData);
extern u32 func_02012A44(struct GameData *gameData);
extern u32 func_02013B44(u32 zoneId);
extern void func_02014184(struct Location *location, int zoneId, int direction, int x, int y, int z);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern void func_02014314(struct EventWork *eventWork, int flagId);

/* save data */
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern int CONFIG_GetAppliedFlag(struct Config *config);
extern int CONFIG_SetAppliedFlag(struct Config *config, int flag);
extern int func_02008428(struct Config *config);
extern u8 func_02008550(const struct PlayerStatus *status);
extern u8 func_02008554(const struct PlayerStatus *status);
extern unsigned char func_020071EC(const struct SaveControl *saveControl);
extern u8 func_020071E4(const struct SaveControl *saveControl);
extern void func_0200723C(struct SaveControl *saveControl, unsigned *used, unsigned *total);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 id, u8 heapId);
extern void *func_020073D8(struct SaveControl *saveControl, u32 id, u32 index);
extern void func_020072A4(struct SaveControl *saveControl, u32 id);
extern void func_02007A68(struct BoxManager *boxManager, u32 bits);
extern u32 func_0200ECB4(void *extraSave);
extern struct RecordSave *func_020089C0(struct SaveControl *saveControl);
extern u8 func_020089F4(const struct RecordSave *record);
extern struct RecordSave *func_02008A00(struct RecordSave *record);
extern void func_02008A7C(struct RecordSave *record, u32 index, u32 year, u32 month, u32 day);
extern u32 func_0200C234(struct MiscSave *misc, u32 flagId);
extern void func_0200C248(struct MiscSave *misc, u32 flagId);
extern u32 func_0200C258(struct MiscSave *misc);
extern u8 func_0200C308(struct MiscSave *misc, u32 index);
extern void func_0200C2F0(struct MiscSave *misc, u32 index, u8 value);
extern struct ZukanSave *func_0200CA1C(struct GameData *gameData);
extern struct ZukanSave *func_0200CA28(struct ZukanSave *zukan);
extern u32 func_0200CA38(struct ZukanSave *zukan);
extern struct ZukanSave *func_0200CA40(struct ZukanSave *zukan);
extern void func_0200CFA0(struct ZukanSave *zukan, void *pokemon);
extern int func_0200D064(struct ZukanSave *zukan, int species);
extern int func_0200CED4(struct ZukanSave *zukan, int species);
extern u16 func_0200D0CC(struct ZukanSave *zukan);
extern u16 func_0200CF28(struct ZukanSave *zukan);
extern int func_0216F830(struct GameData *gameData);
extern int func_021690B4(struct GameData *gameData);
extern int func_021690F0(struct GameData *gameData);
extern int func_021690D0(struct GameData *gameData);
extern int func_021690E0(struct GameData *gameData);
extern int func_02169100(struct GameData *gameData);
extern int func_02169110(struct GameData *gameData);

/* event data, battle, network */
extern int func_02162A74(struct EventData *eventData, int eventId, u16 x, u16 y, u16 z);
extern void func_02162708(struct EventData *eventData, u32 eventId, u16 x, u32 y, u16 z);
extern int func_02162748(struct EventData *eventData, int eventId, int direction, u16 x, int y, u16 z);
extern int func_0216EFA8(u32 fieldMode, int silent);
extern void *func_0215F6E8(struct GameSystem *gameSystem);

/* system */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082A7C(int value, void *dest, int size);
extern void func_02082BCC(void *dest, int value, int size);
extern u32 func_020362DC(void);
extern u32 func_020056EC(u32 range);
extern u32 func_02025C88(u32 x);
extern void func_02087D28(OwnerInfo *info);
extern void func_0203F4E4(RtcDate *date);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heapId);

/* message data, strings, menus */
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02045C04(struct MsgBank *msgData);
extern void func_02045CAC(struct MsgBank *msgData, unsigned int index, struct Strbuf *dest);
extern struct Strbuf *func_02045874(struct Strbuf *src, unsigned int heapId);
extern int func_02045808(struct Strbuf *str);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern unsigned int func_0201F91C(struct BmpMenuWork *items);
extern ScrcmdWork *func_02020D0C(struct BmpMenuList *list);
extern void func_020202EC(struct BmpMenuList *list, u16 *out);
extern struct BmpMenuWork *func_02190A20(int count, int heapId);
extern int func_02190A64(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u32 heapId);
extern u32 func_02190ACC(int *heap, struct BmpMenuWork *items, u32 fontId, u32 margin);
extern unsigned func_02190AC4(struct BmpMenuWork *items);
extern unsigned func_02190AEC(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls);
extern int func_02190B08(FieldMenuHeader *header, u32 count, u32 x, u32 y, u32 width, u32 height);
extern struct FieldMenu *func_02190988(int *heap, const FieldMenuHeader *header, struct BmpMenuWork *items, void (*callback)(struct BmpMenuList *), ScrcmdWork *work, u16 unused, u16 cursorPos, u32 cancelable);
extern int func_021909BC(struct FieldMenu *fieldMenu);
extern int func_021909E4(struct FieldMenu *fieldMenu);
extern void func_02191164(struct FieldMsgWindow *window);
extern void func_02191184(struct FieldMsgWindow *window, u32 b, int c, struct Strbuf *str);
extern int func_02197DA0(struct AnimeTask *task);
extern int func_02197DAC(struct AnimeTask *task);

extern const char d_021728E0[];
extern FieldMenuHeader d_02171140;
extern const u16 d_02171160[];

void func_0215A9C0(struct BmpMenuList *list);

ScrcmdCommonWork *func_0215A514(struct ScriptWork *scriptWork, int heapId)
{
    ScrcmdCommonWork *common = func_02030734(heapId, 0x110, 1, d_021728E0, 0x78);

    common->scriptWork = scriptWork;
    common->gameSystem = func_02158F54(scriptWork);
    common->gameData = func_020120F4(common->gameSystem);
    common->occupyInfo = func_02012964(common->gameData);
    common->windowState = 7;
    return common;
}

/* Tail call through a pool word and `bx r3` into the arm9 heap free. */
void func_0215A554(ScrcmdCommonWork *common)
{
    func_020307B0(common);
}

/*
 * lever: const source pointer hoists its copy before the destination id store.
 */
ScrcmdWork *func_0215A55C(const ScrcmdWorkParam *param, int heapId)
{
    ScrcmdWork *work;
    const ScrcmdWorkParam *src;
    work = func_02030734((unsigned short)((heapId & 0x7fff) | 0x8000), 0x24, 1, d_021728E0, 0x94);
    src = param;
    work->heapId = heapId;
    work->param = *src;
    work->common = func_02158F6C(param->scriptWork);
    return work;
}

void func_0215A738(ScrcmdWork *work);

void func_0215A5A4(ScrcmdWork *work)
{
    if (work->savedLocalWork != NULL)
        func_020307B0(work->savedLocalWork);
    if (work->msgData != NULL)
        func_02045C04(work->msgData);
    func_0215A738(work);
    func_020307B0(work);
}

u16 func_0215A5CC(ScrcmdWork *work)
{
    return work->heapId;
}

u16 func_0215A5D0(ScrcmdWork *work)
{
    return work->param.scriptId;
}

u32 func_0215A5D4(ScrcmdWork *work)
{
    return work->param.callMode;
}

u32 func_0215A5D8(ScrcmdWork *work)
{
    return work->param.callParam;
}

struct GameSystem *func_0215A5DC(ScrcmdWork *work)
{
    return work->common->gameSystem;
}

struct GameData *func_0215A5E4(ScrcmdWork *work)
{
    return work->common->gameData;
}

struct OccupyInfo *func_0215A5EC(ScrcmdWork *work)
{
    return work->common->occupyInfo;
}

struct ScriptWork *func_0215A5F4(ScrcmdWork *work)
{
    return work->common->scriptWork;
}

int func_0215A5FC(ScrcmdWork *work)
{
    return *func_02158F58(func_0215A5F4(work));
}

struct MsgBank *func_0215A60C(ScrcmdWork *work)
{
    return work->msgData;
}

u16 func_0215A610(ScrcmdWork *work)
{
    return work->msgDataId;
}

void func_0215A614(ScrcmdWork *work, struct FieldMsgWindow *window)
{
    work->common->msgWindow = window;
}

struct FieldMsgWindow *func_0215A61C(ScrcmdWork *work)
{
    return work->common->msgWindow;
}

void func_0215A624(ScrcmdWork *work, void *window)
{
    work->common->talkWindow = window;
}

void *func_0215A630(ScrcmdWork *work)
{
    return work->common->talkWindow;
}

u8 *func_0215A63C(ScrcmdWork *work)
{
    return work->common->wordSetWork;
}

void func_0215A644(ScrcmdWork *work, void *object)
{
    work->common->targetObject = object;
}

void *func_0215A64C(ScrcmdWork *work)
{
    return work->common->targetObject;
}

u32 func_0215A654(ScrcmdWork *work)
{
    return work->common->windowState;
}

void func_0215A660(ScrcmdWork *work, u32 state)
{
    work->common->windowState = state;
}

u8 func_0215A66C(ScrcmdWork *work)
{
    return work->common->windowKind;
}

void func_0215A678(ScrcmdWork *work, u8 kind)
{
    work->common->windowKind = kind;
}

void func_0215A684(ScrcmdWork *work, unsigned short count)
{
    work->common->waitCount = count;
}

int func_0215A690(ScrcmdWork *work)
{
    unsigned short *waitCount = &work->common->waitCount;
    if (*waitCount == 0) {
        return 1;
    }
    *waitCount = *waitCount - 1;
    return 0;
}

int func_0215A6AC(ScrcmdWork *work)
{
    return work->common->fadeParam;
}

void func_0215A6B8(ScrcmdWork *work, int param)
{
    work->common->fadeParam = param;
}

int func_0215A6C4(ScrcmdWork *work)
{
    return work->common->fadeState;
}

void func_0215A6D0(ScrcmdWork *work, int state)
{
    work->common->fadeState = state;
}

void func_0215A6DC(ScrcmdWork *work, struct AnimeTask *task)
{
    int i;
    ScrcmdCommonWork *common = work->common;
    for (i = 0; i < 8; i++) {
        if (common->animeTasks[i] == NULL) {
            common->animeTasks[i] = task;
            return;
        }
    }
}

u32 func_0215A6FC(ScrcmdWork *work)
{
    int i;
    u32 busy = 0;
    for (i = 0; i < 8; i++) {
        if (work->common->animeTasks[i] != NULL) {
            if (func_02197DA0(work->common->animeTasks[i]) == 1) {
                func_02197DAC(work->common->animeTasks[i]);
                work->common->animeTasks[i] = NULL;
            } else {
                busy = 1;
            }
        }
    }
    return busy;
}

void func_0215A738(ScrcmdWork *work)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (work->common->animeTasks[i] != NULL) {
            func_02197DAC(work->common->animeTasks[i]);
            work->common->animeTasks[i] = NULL;
        }
    }
}

/*
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 */
void func_0215A760(ScrcmdWork *work, unsigned arcId, unsigned fileId)
{
    work->msgData = func_02045B38(0, (u16)arcId, (u16)fileId, work->heapId);
    work->msgDataId = fileId;
}

void func_0215A77C(ScrcmdWork *work, unsigned short x, unsigned short y,
                   unsigned short cursorPos, unsigned short cancelable,
                   int alignRight, u16 *result,
                   struct WordSet *wordSet, struct MsgBank *msgData)
{
    ScrcmdCommonWork *common = work->common;
    ScrcmdMenu *menu = &common->menu;
    func_02082BCC(menu, 0, 0xa0);
    common->menu.x = x;
    menu->y = y;
    menu->cursorPos = cursorPos;
    menu->cancelable = cancelable;
    menu->alignRight = alignRight;
    menu->result = result;
    menu->wordSet = wordSet;
    menu->msgData = msgData;
    func_02082A7C(0, menu->itemHelp, 0x80);
    if (menu->msgData == NULL) {
        menu->ownsMsgData = 1;
        menu->msgData = func_02045B38(0, 3, 0x80 + 0x86, work->heapId);
    }
    menu->items = func_02190A20(0x20, work->heapId);
}

void func_0215A7F0(ScrcmdWork *work, int msgId, int helpMsgId, int param, struct Strbuf *str, struct Strbuf *tmp)
{
    ScrcmdMenu *menu = &work->common->menu;
    if (helpMsgId != 0xffff) {
        unsigned index = func_0201F91C(menu->items);
        if (index >= 0x20) {
            return;
        }
        func_02045CAC(menu->msgData, helpMsgId, tmp);
        func_0201F250(menu->wordSet, str, tmp);
        menu->itemHelp[index] = func_02045874(str, work->heapId);
    }
    func_02045CAC(menu->msgData, msgId, tmp);
    func_0201F250(menu->wordSet, str, tmp);
    func_02190A64(menu->items, str, param, work->heapId);
}

/*
 * The ov021 leaves 0x02190AC4 and 0x02190AEC (unlabelled, formerly the
 * blockers) are matched in their own shards and attest as matched.
 */
void func_0215A864(ScrcmdWork *work)
{
    int width;
    int height;
    ScrcmdMenu *menu = &work->common->menu;
    FieldMenuHeader header = d_02171140;
    int *heap = (int *)func_0215A5FC(work);
    unsigned lines;
    unsigned count;
    width = func_02190ACC(heap, menu->items, header.fontId, header.cursorMargin);
    if (menu->alignRight == 1) {
        menu->x = menu->x - (unsigned short)width;
    }
    count = func_02190AC4(menu->items);
    lines = 6;
    if (count <= 6) {
        lines = count;
    }
    height = func_02190AEC(lines, header.fontHeight, header.lineSpacing, count > 6);
    func_02190B08(&header, (unsigned short)func_02190AC4(menu->items), (unsigned short)menu->x, (unsigned short)menu->y, (unsigned short)width, (unsigned short)height);
    menu->fieldMenu = func_02190988(heap, &header, menu->items, func_0215A9C0, work, 0, menu->cursorPos, menu->cancelable);
}

void func_0215A920(ScrcmdMenu *menu)
{
    int i;
    func_021909BC(menu->fieldMenu);
    if (menu->ownsMsgData == 1) {
        func_02045C04(menu->msgData);
    }
    for (i = 0; i < 0x20; i++) {
        if (menu->itemHelp[i] != NULL) {
            func_02045808(menu->itemHelp[i]);
            menu->itemHelp[i] = NULL;
        }
    }
}

int func_0215A954(ScrcmdWork *work)
{
    ScrcmdMenu *menu;
    int selected;
    menu = &work->common->menu;
    selected = func_021909E4(menu->fieldMenu);
    if (selected == -1)
        return 0;
    func_0215A920(menu);
    if (selected != -2)
        *menu->result = selected;
    else
        *menu->result = 65534;
    return 1;
}

/*
 * lever: result declared before pointer gives original r4/result, r5/base.
 */
int func_0215A990(ScrcmdWork *work)
{
    int done;
    ScrcmdMenu *menu;
    menu = &work->common->menu;
    done = func_0215A954(work);
    if (done == 0 && (func_020362DC() & 1024)) {
        func_0215A920(menu);
        *menu->result = 65533;
        done = 1;
    }
    return done;
}

void func_0215A9C0(struct BmpMenuList *list)
{
    unsigned short index = 0;
    ScrcmdWork *work = func_02020D0C(list);
    ScrcmdMenu *menu = &work->common->menu;
    func_020202EC(list, &index);
    if (menu->itemHelp[index] != NULL) {
        if (func_02159190(1) != 0) {
            struct FieldMsgWindow *window = func_0215A61C(work);
            func_02191164(window);
            func_02191184(window, 0, 0, menu->itemHelp[index]);
        } else if (func_02159190(2) == 0) {
            func_02159190(3);
        }
    }
}

void func_0215AA24(ScrcmdWork *work)
{
    work->savedLocalWork = func_0215909C(func_0215A5F4(work));
}

void func_0215AA34(ScrcmdWork *work)
{
    func_021590D4(func_0215A5F4(work), work->savedLocalWork);
    work->savedLocalWork = NULL;
}

void func_0215AA48(ScrcmdWork *work, int index)
{
    work->childScriptIndex = index;
}

u8 func_0215AA4C(ScrcmdWork *work)
{
    return work->childScriptIndex;
}

int func_0215AA50(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = 0x15;
    return 0;
}

int func_0215AA60(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    int flag;
    config = func_0200873C(func_02012EBC(func_0215A5E4(work)));
    flag = CONFIG_GetAppliedFlag(config);
    if (flag == 0) {
        flag = 1;
    } else if (flag == 1) {
        flag = 0;
    }
    CONFIG_SetAppliedFlag(config, flag);
    return 0;
}

int func_0215AA90(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = func_0200873C(func_02012EBC(func_0215A5E4(work)));
    ret = func_02159AE8(vm, work);
    *ret = CONFIG_GetAppliedFlag(config);
    return 0;
}

int func_0215AABC(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = (u16)func_020056EC(func_02159B10(vm, work));
    return 0;
}

int func_0215AADC(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0215A610(work);
    return 0;
}

int func_0215AAF4(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0216F830(gameData);
    return 0;
}

int func_0215AB18(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_021690B4(gameData);
    return 0;
}

int func_0215AB3C(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_021690F0(gameData);
    return 0;
}

int func_0215AB60(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    u16 *retFirst = func_02159AE8(vm, work);
    u16 *retSecond = func_02159AE8(vm, work);
    *retFirst = func_021690D0(gameData);
    *retSecond = func_021690E0(gameData);
    return 0;
}

int func_0215AB98(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    u16 *retFirst = func_02159AE8(vm, work);
    u16 *retSecond = func_02159AE8(vm, work);
    *retFirst = func_02169100(gameData);
    *retSecond = func_02169110(gameData);
    return 0;
}

int func_0215ABD0(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_02012984(func_0215A5E4(work));
    return 0;
}

/* extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment. */
int func_0215ABEC(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *retMonth;
    u16 *retDay;
    OwnerInfo info;
    retMonth = func_02159AE8(vm, work);
    retDay = func_02159AE8(vm, work);
    func_02087D28(&info);
    *retMonth = info.month;
    *retDay = info.day;
    return 0;
}

int func_0215AC1C(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = (u16)func_02008550(&func_020127A4(func_0215A5E4(work))->status);
    return 0;
}

int func_0215AC3C(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    int flagId = func_02159B10(vm, work);
    *ret = func_0200C234(func_02012F08(func_0215A5E4(work)), flagId);
    return 0;
}

int func_0215AC68(struct ScriptVm *vm, ScrcmdWork *work)
{
    RtcDate date;
    int flagId = func_02159B10(vm, work);
    struct GameData *gameData = func_0215A5E4(work);
    func_0200C248(func_02012F08(gameData), flagId);
    func_0203F4E4(&date);
    func_02008A7C(GAME_DATA_GetSaveBlock21(gameData), flagId, date.year, date.month, date.day);
    return 0;
}

int func_0215ACA8(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0200C258(func_02012F08(func_0215A5E4(work)));
    return 0;
}

int func_0215ACC8(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct SaveControl *saveControl;
    unsigned short *retFirst;
    unsigned short *retSecond;
    unsigned short *retThird;
    unsigned total;
    unsigned used;
    saveControl = func_02012EBC(func_0215A5E4(work));
    retFirst = func_02159AE8(vm, work);
    retSecond = func_02159AE8(vm, work);
    retThird = func_02159AE8(vm, work);
    total = 0;
    used = 0;
    *retFirst = func_020071EC(saveControl);
    *retSecond = func_020071E4(saveControl);
    func_0200723C(saveControl, &used, &total);
    if (used * 3 < total) {
        *retThird = 0;
    } else {
        *retThird = 1;
    }
    return 0;
}

int func_0215AD38(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0215A5D0(work);
    return 0;
}

int func_0215AD50(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    int warpId = func_02159B10(vm, work);
    if (func_02159F84(warpId) == 1) {
        func_02012900(gameData, warpId);
    }
    return 0;
}

/*
 * 0x02014184 is an unlabelled Thumb leaf in the ARM9 image with one caller
 * image-wide (label / sole-ref/code refuse it).
 */
int func_0215AD7C(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Location location;
    struct GameData *gameData = func_0215A5E4(work);
    struct PlayerWork *playerWork = func_020127A4(gameData);
    struct PlayerPosition *position = func_02012AA0(playerWork);
    int zoneId = func_02012AC8(playerWork);
    func_02014184(&location, zoneId, (short)func_02012AE4(playerWork), position->x, position->y, position->z);
    func_0201289C(gameData, &location);
    return 0;
}

int func_0215ADCC(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Location location;
    struct GameData *gameData = func_0215A5E4(work);
    int zoneId = func_02159B10(vm, work);
    int direction = func_02159B10(vm, work);
    int x = func_02159B10(vm, work);
    int y = func_02159B10(vm, work);
    int z = func_02159B10(vm, work);
    func_02014184(&location, zoneId, (s16)direction, x << 16, y << 16, z << 16);
    func_0201289C(gameData, &location);
    return 0;
}

int func_0215AE34(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = func_0215A5DC(work);
    struct GameData *gameData = func_0215A5E4(work);
    int replaceId = func_02159B10(vm, work);
    int enable = func_02159B10(vm, work);
    int applyNow = func_02159B10(vm, work);
    struct MapMatrix *mapMatrix;
    int matrixId, heapId;
    u16 zoneId;
    func_02159F28(gameData, replaceId, enable);
    if (applyNow != 0) {
        mapMatrix = func_02012974(gameData);
        zoneId = func_02012AC8(func_020127A4(gameData));
        matrixId = func_02013B44(zoneId);
        heapId = func_0215A5CC(work);
        func_02159B94(mapMatrix, matrixId, zoneId, heapId);
        func_02159CC4(mapMatrix, gameSystem, heapId);
    }
    return 0;
}

int func_0215AEB8(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    int replaceId = func_02159B10(vm, work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_02159F54(gameData, replaceId);
    return 0;
}

int func_0215AEE8(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int heapId;
    int mode, species;
    void *pokemon;
    zukan = func_0200CA1C(func_0215A5E4(work));
    heapId = func_0215A5CC(work);
    mode = (int)func_02159B10(vm, work);
    species = (int)func_02159B10(vm, work);
    pokemon = func_020173F0(species, 1, 0xFFFFFFFF00000000ULL, heapId);
    switch (mode) {
    case 0:
        func_0200CFA0(zukan, pokemon);
        break;
    case 1:
        break;
    }
    func_020307B0(pokemon);
    return 0;
}

int func_0215AF40(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int mode, species;
    u16 *ret;
    zukan = func_0200CA1C(func_0215A5E4(work));
    mode = (int)func_02159B10(vm, work);
    species = (int)func_02159B10(vm, work);
    ret = func_02159AE8(vm, work);
    switch (mode) {
    case 0:
        *ret = func_0200D064(zukan, species);
        break;
    case 1:
        *ret = func_0200CED4(zukan, species);
        break;
    default:
        *ret = 0;
        break;
    }
    return 0;
}

int func_0215AF98(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int mode;
    u16 *ret;
    zukan = func_0200CA1C(func_0215A5E4(work));
    mode = (int)func_02159B10(vm, work);
    ret = func_02159AE8(vm, work);
    switch (mode) {
    case 0:
        *ret = func_0200D0CC(zukan);
        break;
    case 1:
        *ret = func_0200CF28(zukan);
        break;
    default:
        *ret = 0;
        break;
    }
    return 0;
}

int func_0215AFE0(struct ScriptVm *vm, ScrcmdWork *work)
{
    func_0200CA28(func_0200CA1C(func_0215A5E4(work)));
    return 0;
}

int func_0215AFF4(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0200CA38(func_0200CA1C(func_0215A5E4(work)));
    return 0;
}

int func_0215B014(struct ScriptVm *vm, ScrcmdWork *work)
{
    func_0200CA40(func_0200CA1C(func_0215A5E4(work)));
    return 0;
}

int func_0215B028(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = func_0200873C(func_02012EBC(func_020120F4(func_0215A5DC(work))));
    ret = func_02159AE8(vm, work);
    switch (func_02008428(config)) {
    case 0:
        *ret = 0;
        break;
    case 1:
        *ret = 1;
        break;
    }
    return 0;
}

int func_0215B068(struct ScriptVm *vm, ScrcmdWork *work)
{
    func_02014314(func_0201296C(func_0215A5E4(work)), 0x963);
    return 0;
}

int func_0215B084(struct ScriptVm *vm, ScrcmdWork *work)
{
    int bits = (int)func_02159B10(vm, work);
    struct BoxManager *boxManager = func_0201293C(func_0215A5E4(work));
    if ((u16)(bits + 0xFFFF) <= 1)
        func_02007A68(boxManager, bits);
    return 0;
}

int func_0215B0B4(struct ScriptVm *vm, ScrcmdWork *work)
{
    unsigned short *retSecond;
    unsigned short *retFirst;
    struct GameData *gameData;
    struct PlayerWork *playerWork;
    struct RecordSave *record;
    retSecond = func_02159AE8(vm, work);
    retFirst = func_02159AE8(vm, work);
    gameData = func_0215A5E4(work);
    playerWork = func_020127A4(gameData);
    record = func_020089C0(func_02012EBC(gameData));
    *retFirst = func_02025C88(func_02008554(&playerWork->status));
    *retSecond = func_020089F4(record);
    func_02008A00(record);
    return 0;
}

int func_0215B104(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)func_02159B10(vm, work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = (func_0200C308(func_02012F08(func_0215A5E4(work)), index) & 1) != 0;
    return 0;
}

int func_0215B138(struct ScriptVm *vm, ScrcmdWork *work)
{
    u32 index = func_02159B10(vm, work);
    func_0200C2F0(func_02012F08(func_0215A5E4(work)), index, 1);
    return 0;
}

int func_0215B158(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)func_02159B10(vm, work);
    u16 *ret = func_02159AE8(vm, work);
    if (func_0200C308(func_02012F08(func_0215A5E4(work)), index) == 3)
        *ret = 1;
    else
        *ret = 0;
    return 0;
}

int func_0215B190(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    u16 *ret = func_02159AE8(vm, work);
    struct SaveControl *saveControl;
    int result;
    if (func_020142E8(eventWork, 0x97B) != 0) {
        saveControl = func_02012EBC(gameData);
        result = SAVE_CONTROL_LoadExtraSave(saveControl, 8, 4);
        switch (result) {
        case 0:
            *ret = 0;
            break;
        case 1:
        case 2:
            if (func_0200ECB4(func_020073D8(saveControl, 8, 0)) == 0) {
                *ret = 0;
            } else {
                *ret = 1;
            }
            break;
        default:
            *ret = 2;
            break;
        }
        func_020072A4(saveControl, 8);
    } else {
        *ret = 0;
    }
    return 0;
}

int func_0215B214(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)func_02159B10(vm, work);
    s16 x = (s16)func_02159B10(vm, work);
    s16 y = (s16)func_02159B10(vm, work);
    s16 z = (s16)func_02159B10(vm, work);
    func_02162A74(func_02012844(func_0215A5E4(work)), eventId, x, y, z);
    return 0;
}

int func_0215B26C(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)func_02159B10(vm, work);
    s16 x = (s16)func_02159B10(vm, work);
    s16 y = (s16)func_02159B10(vm, work);
    s16 z = (s16)func_02159B10(vm, work);
    func_02162708(func_02012844(func_0215A5E4(work)), eventId, x, (u16)y, z);
    return 0;
}

int func_0215B2C4(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)func_02159B10(vm, work);
    int direction = (int)func_02159B10(vm, work);
    s16 x = (s16)func_02159B10(vm, work);
    s16 y = (s16)func_02159B10(vm, work);
    s16 z = (s16)func_02159B10(vm, work);
    func_02162748(func_02012844(func_0215A5E4(work)), eventId, direction, x, y << 16, z);
    return 0;
}

int func_0215B328(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    unsigned offset = func_02159B10(vm, work);
    func_0215A4EC(eventWork, offset);
    return 0;
}

int func_0215B350(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = func_0215A5E4(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    unsigned offset = func_02159B10(vm, work);
    func_0215A500(eventWork, offset);
    return 0;
}

int func_0215B378(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct EventWork *eventWork = func_0201296C(func_0215A5E4(work));
    unsigned offset = func_02159B10(vm, work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = func_0215A4D8(eventWork, offset);
    return 0;
}

int func_0215B3AC(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = func_0215A5DC(work);
    struct ScriptWork *scriptWork = func_0215A5F4(work);
    func_0215898C(scriptWork, func_0215F6E8(gameSystem));
    func_02011290(vm);
    return 1;
}

int func_0215B3DC(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    int notSilent = 1;
    if (func_0216EFA8(func_02012A44(func_0215A5E4(work)), 1) == 1)
        *ret = 0;
    else
        *ret = notSilent;
    return 0;
}

int func_0215B408(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = func_0215A5DC(work);
    struct ScriptWork *scriptWork = func_0215A5F4(work);
    func_0215898C(scriptWork, func_0215F6E8(gameSystem));
    func_02011290(vm);
    return 1;
}

int func_0215B438(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = func_02159AE8(vm, work);
    int silent = 0;
    if (func_0216EFA8(func_02012A44(func_0215A5E4(work)), 0) == 1)
        *ret = silent;
    else
        *ret = 1;
    return 0;
}

int func_0215B464(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)func_02159B10(vm, work);
    u16 *ret = func_02159AE8(vm, work);
    *ret = d_02171160[index];
    return 0;
}

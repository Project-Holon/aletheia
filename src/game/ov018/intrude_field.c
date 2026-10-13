/*
 * file:     intrude_field.c
 * unit:     yes
 * function: func_0217AE20, func_0217AFC4, func_0217B044, func_0217B084, func_0217B1DC, func_0217B214, func_0217B410, func_0217B4D8, func_0217B5DC, func_0217B600, func_0217B810, func_0217B82C, func_0217B930, func_0217B94C, func_0217B968, func_0217BA48, func_0217BA54, func_0217BAB4, func_0217BBCC, func_0217BBD8, func_0217BC94, func_0217BCDC, func_0217BDE0, func_0217BEA8, func_0217BED4, func_0217BF1C, func_0217BF28, func_0217BF2C, func_0217BF84, func_0217BFD8, func_0217C070, func_0217C094, func_0217C0A8, func_0217C11C, func_0217C14C, func_0217C194, func_0217C1D0, func_0217C274, func_0217C294, func_0217C2A0, func_0217C37C, func_0217C458, func_0217C4D0, func_0217C658, func_0217C688
 * address:  0x0217AE20
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02175004  0x02175004  thumb  ov011
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167590  0x02167590  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_021679C4  0x021679C4  thumb  ov010
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021584A4  0x021584A4  thumb
 *   func_02175BE4  0x02175BE4  thumb  ov011
 *   func_02175548  0x02175548  thumb
 *   func_0217C758  0x0217C758  thumb
 *   func_0217C820  0x0217C820  thumb
 *   func_02188D20  0x02188D20  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02190758  0x02190758  thumb
 *   func_021BC5A0  0x021BC5A0  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216B340  0x0216B340  thumb  ov010
 *   d_02182B90     0x02182B90  data   a4
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02012798  0x02012798  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02185214  0x02185214  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021909BC  0x021909BC  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_02190E40  0x02190E40  thumb
 *   func_02190E74  0x02190E74  thumb
 *   func_02190EF0  0x02190EF0  thumb
 *   func_02190F64  0x02190F64  thumb
 *   func_021A3238  0x021A3238  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02012204  0x02012204  thumb
 *   func_020120D8  0x020120D8  thumb
 *   func_020392B8  0x020392B8  arm
 *   func_0202640C  0x0202640C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_02183AE0     0x02183AE0  data   a1
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02175274  0x02175274  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_0218CD20  0x0218CD20  thumb  ov021
 *   func_02012114  0x02012114  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_02175BBC  0x02175BBC  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02182124  0x02182124  thumb  ov018
 *   d_021DB810     0x021DB810  data   ov021  a2
 *   d_021DB834     0x021DB834  data   ov021  a2
 *   d_02182B9C 0x02182B9C data ov018 a4
 *   d_02182B60     0x02182B60  data   a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_02182B6C     0x02182B6C  data   a4
 *   d_02182B54 0x02182B54 data a4
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02176258 0x02176258 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B80  0x02012B80  thumb
 *   d_021700A4 0x021700A4 data a4
 *   d_02170128 0x02170128 data a2
 *   d_021835D4     0x021835D4  data   a4
 *   func_0202A188  0x0202A188  thumb
 *   d_0218360C     0x0218360C  data   a4
 *   d_0218362C     0x0218362C  data   a4
 *   func_0216D63C 0x0216D63C thumb ov010
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02008530  0x02008530  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_02166640  0x02166640  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0202A128  0x0202A128  thumb
 *   func_0202A170  0x0202A170  thumb
 *   func_02005728  0x02005728  thumb
 *   d_02183678     0x02183678  data  a4
 *   d_021835F8     0x021835F8  data  a4
 *   d_02183650     0x02183650  data  a4
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_02174E14  0x02174E14  thumb  ov011
 *   func_0217F528  0x0217F528  thumb  ov018
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F574  0x0217F574  thumb  ov018
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0217F58C  0x0217F58C  thumb  ov018
 *   func_02173FC0  0x02173FC0  thumb  ov011
 *   func_02175A24  0x02175A24  thumb  ov011
 *   func_0217F318  0x0217F318  thumb  ov018
 *   func_020061E4  0x020061E4  thumb
 *   d_021836A0     0x021836A0  data  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../ov011/intrude_comm_types.h"
#include "../ov010/fldmmdl_types.h"

struct GameSystem;
struct GameComm;
struct GameData;
struct GameEvent;
struct PlayerWork;
struct PlayerStatus;
struct FieldMap;
struct FieldPlayer;
struct FieldMsgBg;
struct MsgData;
struct MsgWin;
struct PromptWin;
struct YesNoMenu;
struct WordSet;
struct U16Vec;
struct MapMatrix;
struct TpokeData;
struct Pokemon;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Appearance of the player chosen for the Entralink visit. */
typedef struct PlayerLook {
    u8 flag;
    u8 kind;
    u16 objCode;
} PlayerLook;

/* Work of the player spin that changes the appearance (0x18 bytes). */
typedef struct PlayerSpinWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    s16 shownStep;                  /* 0x08 */
    s16 stepFrames;                 /* 0x0A: counts down from 15, the turn gets faster */
    u16 objCode;                    /* 0x0C: appearance to switch to */
    u8 kind;                        /* 0x0E */
    u8 flag;                        /* 0x0F */
    u8 state;                       /* 0x10 */
    u8 dirIndex;                    /* 0x11: index into the turn command list */
    u8 switched;                    /* 0x12: set once the appearance changed */
    u8 pad13;
    int reserved14;
} PlayerSpinWork;

/* Task that bounces the player off the edge of the map (0x18 bytes). */
typedef struct EdgeBlockWork {
    struct FieldMap *fieldMap;      /* 0x00 */
    Mmdl *playerMmdl;               /* 0x04 */
    struct MsgData *msgData;        /* 0x08 */
    struct MsgWin *msgWin;          /* 0x0C */
    int sessionBusy;                /* 0x10 */
    u16 edgeDir;                    /* 0x14: 2 left edge, 3 right edge */
    u16 moveDir;                    /* 0x16 */
} EdgeBlockWork;

/* Task that changes the area when the player crosses the edge (0x30 bytes). */
typedef struct AreaChangeWork {
    struct FieldMap *fieldMap;      /* 0x00 */
    Mmdl *playerMmdl;               /* 0x04 */
    struct MsgData *msgData;        /* 0x08 */
    struct MsgWin *msgWin;          /* 0x0C */
    struct WordSet *wordSet;        /* 0x10 */
    u16 edgeDir;                    /* 0x14 */
    u8 sessionBusy;                 /* 0x16 */
    u8 pad17;
    u8 transitionWork[0x18];        /* 0x18: set up by func_0217C758, stepped by func_0217C820 */
} AreaChangeWork;

/* Event that asks whether to leave the Entralink (0x2C bytes). */
typedef struct ExitConfirmWork {
    struct MsgData *msgData;        /* 0x00 */
    struct MsgWin *endMsgWin;       /* 0x04 */
    struct PromptWin *promptWin;    /* 0x08 */
    struct YesNoMenu *yesNoMenu;    /* 0x0C */
    PlayerSpinWork spin;            /* 0x10 */
    u16 waitFrames;                 /* 0x28 */
    u16 pad2A;
} ExitConfirmWork;

/* Event that shows a notice and spins the player (0x20 bytes). */
typedef struct NoticeEventWork {
    struct MsgData *msgData;        /* 0x00 */
    struct PromptWin *promptWin;    /* 0x04 */
    PlayerSpinWork spin;            /* 0x08 */
} NoticeEventWork;

/* Parameter block of GAME_COMM_Start for the Entralink (0x10 bytes). */
typedef struct IntrudeStartParam {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameComm *gameComm;      /* 0x04 */
    int reserved08;
    u16 reserved0C;
    u8 startKind;                   /* 0x0E: 1 when started from the field */
    u8 pad0F;
} IntrudeStartParam;

/* One zone of the Entralink with the tile position of its anchor (0x0C bytes). */
typedef struct IntrudeZonePos {
    u32 zoneId : 10;
    u32 rest : 22;
    s16 tileX;
    s16 tileY;
    s16 tileZ;
    u16 pad0A;
} IntrudeZonePos;

/* Position that a visit offer waits at, per offer index. */
typedef struct IntrudeTilePos {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
} IntrudeTilePos;

/* Move parameters per appearance of a spawned partner Pokemon. */
typedef struct IntrudeMmdlMoveParam {
    u16 moveCode;
    u8 moveLimitX;
    u8 moveLimitZ;
} IntrudeMmdlMoveParam;

/* One entry of a symbol map page (IntrudeSymbolPage.entries): one Pokemon wandering on the symbol map. */
typedef struct SymbolMonEntry {
    u32 species : 11;
    u32 move : 10;
    u32 sex : 2;
    u32 form : 6;
    u32 appearance : 3;
} SymbolMonEntry;

/* Context of the Pokemon spawn on a symbol map. */
typedef struct SymbolSpawnContext {
    struct TpokeData *tpoke;        /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    int objIdBase;                  /* 0x08 */
} SymbolSpawnContext;

/* Low byte of IntrudeRequestHead.reserved08: bit per net ID. */
typedef struct IntrudeNetIdMask {
    u8 netIds : 3;
    u8 rest : 5;
} IntrudeNetIdMask;

/* Placement of a model in MmdlHeader.pos: tile x and z, then the height. */
typedef struct MmdlGridPos {
    u16 x;
    u16 z;
    int y;
} MmdlGridPos;

/* Grid position of a model (three tile coordinates). */
typedef struct GridPos {
    s16 x;
    s16 y;
    s16 z;
} GridPos;

/* Definition of one model placed on each area (five halfwords). */
typedef struct IntrudeAreaMmdlDef {
    u16 objCode;
    u16 gridX;
    u16 gridZ;
    u16 eventId;
    u16 objIdBase;
} IntrudeAreaMmdlDef;

typedef enum AreaMmdlIndex {
    AREA_MMDL_FIRST,
    AREA_MMDL_SECOND
} AreaMmdlIndex;

/* Work of the event that shows the offered request (0x88 bytes). */
typedef struct OfferEventWork {
    u16 senderNetId;                /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;      /* 0x04 */
    u8 infoWindow[0x30];            /* 0x08: set up by func_0217F2B4 */
    IntrudeMemberRecord record;     /* 0x38: copy of the active offer */
    PlayerSpinWork spin;            /* 0x6C */
    u8 showInfo;                    /* 0x84 */
    u8 pad85[3];
} OfferEventWork;

/* GAMESYSTEM, GAME_DATA, GAME_COMM and GAME_EVENT access */
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern void *func_02026474(struct GameComm *gameComm);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct PlayerWork *func_020120F8(const struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern u32 func_02012114(const struct GameSystem *gameSystem);
extern u8 func_02012E40(const struct GameData *gameData);
extern u32 func_02026454(struct GameComm *gameComm);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *playerWork);
extern u32 func_02012AE4(const struct PlayerWork *playerWork);
extern u32 func_02013D5C(u32 zoneId);
extern u32 func_02013D9C(u32 zoneId);
extern u32 func_0200FB24(void);
extern int func_02012B70(const struct GameData *gameData);
extern u8 func_02012B58(const struct GameData *gameData);
extern u8 func_02012B80(const struct GameData *gameData);
extern struct PlayerStatus *func_02012950(struct GameData *gameData, u32 index);
extern struct PlayerStatus *func_02012944(struct GameData *gameData);
extern struct PlayerWork *func_02012798(struct GameData *gameData, int index);
extern void func_02012A90(struct PlayerWork *playerWork, const VecFx32 *pos);
extern u32 func_02012204(const struct GameSystem *gameSystem);
extern int func_020120D8(struct GameSystem *gameSystem);
extern u32 func_0202648C(struct GameComm *gameComm);
extern u32 func_02026460(struct GameComm *gameComm);
extern u32 func_0202647C(struct GameComm *gameComm);
extern struct GameData *func_02026478(struct GameComm *gameComm);
extern void func_02026400(struct GameComm *gameComm);
extern void func_0202640C(struct GameComm *gameComm, u32 callback, u32 callbackArg);
extern void func_020263D8(struct GameComm *gameComm, u32 kind, u32 param);
extern void *func_02030734(u32 heapId, u32 size, int clear, const void *file, u16 line);
extern int func_02035390(void);
extern int func_020353B0(void);
extern int func_020392B8(void);
extern u16 func_02039338(void);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, void *eventFunc, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_02012374(struct GameEvent *event, struct GameEvent *next);
extern void MI_CpuFill8(void *dst, int value, int size);
extern u32 func_020362DC(void);
extern u32 func_02005728(u32 range);
extern void func_020061E4(u32 seNo);
extern int func_02005F38(void);
extern int func_0203D1B4(void);
extern struct GameEvent *func_02029830(struct GameSystem *gameSystem, u32 bgmId);
extern struct GameEvent *func_02029620(struct GameSystem *gameSystem, u32 a1, u32 a2);
/* MyStatus, Pokemon and message helpers */
extern u8 func_02008530(const struct PlayerStatus *status);
extern u8 func_02008550(const struct PlayerStatus *status);
extern struct WordSet *func_0201EC64(u32 heapId);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, struct PlayerStatus *status);
extern void func_0201F250(struct WordSet *wordSet, struct STRBUF *dst, struct STRBUF *src);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern struct STRBUF *func_020457B0(u32 capacity, u32 heapId);
extern struct STRBUF *func_02045EC0(struct MsgData *msgData, u32 index);
extern void func_02045808(struct STRBUF *strbuf);
extern u32 func_02045C04(struct MsgData *msgData);
extern u8 *func_0204A1BC(int arcId, int a1, int a2, int heapId);
extern void func_020307B0(void *ptr);
extern u32 func_020186C8(u32 trainerId, int species, int form, int sex, int a4, int a5);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heapId);
extern void func_02017588(void *mon, u16 species, u16 level, unsigned long long id, u32 power, unsigned long long rnd);
extern void func_02018A00(void *mon, u32 species, u32 form);
extern u32 func_02017988(void *mon, u32 form);
extern u16 func_0201808C(void *mon, u16 move);
extern void func_020180F4(void *mon, int move);
extern struct TpokeData *func_0202A128(int heapId);
extern void func_0202A170(struct TpokeData *tpoke);
extern u32 func_0202A188(struct TpokeData *tpoke, u32 species, u32 sex, u32 form);
/* COMM_PLAYER, FLDMMDL and symbol map */
extern void func_02167590(struct GameSystem *gameSystem, struct CommPlayerWork *commPlayer);
extern int func_021677E4(struct CommPlayerWork *commPlayer, int index);
extern void func_021675D0(struct CommPlayerWork *commPlayer, int index, int objCode, IntrudePlayerPackage *package);
extern void func_02167848(struct CommPlayerWork *commPlayer, int index, IntrudePlayerPackage *package);
extern int func_021679C4(struct CommPlayerWork *commPlayer, int index);
extern int func_021679A4(struct CommPlayerWork *commPlayer, int gridX, int gridY, int gridZ, int *outIndex, int *outHit);
extern int func_02166618(int cellKind);
extern int func_02166640(int cellKind);
extern void func_02161FEC(u8 *returnSlots, u16 linkId);
extern struct GameEvent *func_0216B340(struct GameSystem *gameSystem, int a1, VecFx32 *pos, int a3, int a4);
extern Mmdl *func_0216CE60(MmdlSys *mmdlSys, const MmdlHeader *header, int zoneId);
extern int func_0216D3CC(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern void func_0216D410(Mmdl *mmdl, u16 acmd);
extern int func_0216D454(Mmdl *mmdl, u32 *seq, void *work, u32 extra);
extern int func_0216D480(Mmdl *mmdl);
extern int func_0216D63C(Mmdl *mmdl, int paramIndex);
extern void func_0216D828(Mmdl *mmdl, GridPos *pos);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern void func_0216D8C0(Mmdl *mmdl, const VecFx32 *offset);
extern void func_0216D9A0(MmdlSys *mmdlSys);
extern u32 *func_0216D9E4(MmdlSys *mmdlSys);
/* INTRUDE_COMM */
extern int func_02173FC0(IntrudeCommSys *work, IntrudeSession *session);
extern void func_02174E14(IntrudeCommSys *work, int state);
extern void func_02175004(IntrudeCommSys *work);
extern void func_02175274(IntrudeCommSys *work, int posX);
extern void func_02175548(struct PlayerStatus *status, u16 *objCode, u8 *kind, u8 *flag);
extern u16 func_02175598(const IntrudePeer *peer, struct PlayerStatus *status);
extern void func_02175710(IntrudeCommSys *work, u32 intrudeId);
extern int func_02175A24(IntrudeSession *session);
extern IntrudeMemberRecord *func_02175B34(IntrudeSession *session);
extern int func_02175B8C(IntrudeSession *session);
extern int func_02175BBC(IntrudeSession *session);
extern int func_02175BE4(IntrudeSession *session);
extern int func_02175CF4(IntrudeCommSys *work, IntrudeSession *session);
extern int func_02175E90(IntrudeCommSys *work, IntrudeSession *session);
extern int func_02176258(IntrudeCommSys *work);
extern void func_021762D8(IntrudeMemberRecord *record, IntrudeMemberName *name, int wordSet, u16 netId);
extern IntrudeCommSys *func_02158344(struct GameComm *gameComm);
extern int func_021584A4(struct GameComm *gameComm, struct GameData *gameData, int a2);
extern int func_02182124(struct GameSystem *gameSystem, IntrudeCommSys *work, IntrudeMemberRecord *offer);
extern struct GameEvent *func_02185214(struct GameSystem *gameSystem);
/* map matrix and field map */
extern struct MapMatrix *func_02159B48(int heapId);
extern int func_02159B94(struct MapMatrix *matrix, int a1, int a2, int a3);
extern void func_02159BBC(struct MapMatrix *matrix);
extern void func_0218CD20(struct FieldMap *fieldMap, int mapper, struct MapMatrix *matrix);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern int func_02188BE8(struct FieldMap *fieldMap);
extern MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern unsigned int func_02188C98(struct FieldMap *fieldMap);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern int func_02188D20(struct FieldMap *fieldMap);
extern void func_021BC5A0(int a0, int a1);
/* FIELD_MSGBG */
extern struct MsgData *func_021904B0(struct FieldMsgBg *msgBg, u32 msgDataId);
extern struct MsgWin *func_021907A8(struct FieldMsgBg *msgBg, struct MsgData *msgData);
extern int func_02190740(struct MsgWin *msgWin, u32 a1, u32 a2, u32 msgId);
extern void func_02190758(struct MsgWin *msgWin, u32 a1, u32 a2, struct STRBUF *strbuf);
extern int func_0219077C(struct MsgWin *msgWin);
extern void func_02190788(struct MsgWin *msgWin);
extern int func_02190728(struct MsgWin *msgWin);
extern struct PromptWin *func_02190F64(struct FieldMsgBg *msgBg, struct MsgData *msgData);
extern void func_02190E74(struct PromptWin *promptWin, u32 a1, u32 a2, u32 msgId);
extern int func_02190EF0(struct PromptWin *promptWin);
extern void func_02190E40(struct PromptWin *promptWin);
extern struct YesNoMenu *func_02190BE4(struct FieldMsgBg *msgBg, int a1);
extern int func_02190C78(struct YesNoMenu *menu);
extern void func_021909BC(struct YesNoMenu *menu);
/* FIELD_PLAYER */
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *pos);
extern void func_021A3044(struct FieldPlayer *player, const VecFx32 *pos);
extern Mmdl *func_021A3074(struct FieldPlayer *player);
extern unsigned int func_021A3098(struct FieldPlayer *player);
extern void func_021A3220(struct FieldPlayer *player, u32 form);
extern void func_021A322C(struct FieldPlayer *player);
extern int func_021A3238(struct FieldPlayer *player);
extern int func_021A3460(struct FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ);
/* next original file (sub display and transition steps) */
extern void func_0217F2B4();
extern void func_0217F318();
extern void func_0217F528();
extern void func_0217F574();
extern void func_0217F58C();
extern void func_0217C758();
extern int func_0217C820();

void func_0217AE20(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
int func_0217AFC4(IntrudeCommSys *work, struct FieldPlayer *player, int *outIndex);
struct GameEvent *func_0217B044(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 moveDir, u16 edgeDir, int sessionBusy);
int func_0217B084(struct GameEvent *event, u32 *seq, EdgeBlockWork *work, u32 eventArg3);
struct GameEvent *func_0217B1DC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 edgeDir);
int func_0217B214(struct GameEvent *event, u32 *seq, AreaChangeWork *work);
int func_0217B410(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
struct GameEvent *func_0217B4D8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, int *posX, u16 moveDir, u16 facingDir);
struct GameEvent *func_0217B5DC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work);
int func_0217B600(struct GameEvent *event, u32 *seq, ExitConfirmWork *work);
struct GameEvent *func_0217B810(struct GameSystem *gameSystem, VecFx32 *pos);
int func_0217B82C(struct GameEvent *event, u32 *seq, NoticeEventWork *work);
int func_0217B930(const VecFx32 *pos);
int func_0217B94C(const VecFx32 *pos);
void func_0217B968(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct GameComm *gameComm, struct FieldPlayer *player);
void func_0217BA48(struct GameSystem *gameSystem, int result);
void func_0217BA54(struct GameSystem *gameSystem);
void func_0217BAB4(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player, IntrudeCommSys *work);
void func_0217BBCC(int unusedArg0, int unusedArg1, IntrudeCommSys *work);
void func_0217BBD8(struct FieldMap *fieldMap, struct GameSystem *gameSystem, IntrudeCommSys *work);
void func_0217BC94(struct FieldMap *fieldMap, int count);
void func_0217BCDC(IntrudeCommSys *work, struct GameSystem *gameSystem, int objCode, u8 kind, u8 flag);
int func_0217BDE0(struct GameSystem *gameSystem, IntrudeCommSys *work, struct FieldPlayer *player);
IntrudeZonePos *func_0217BEA8(u32 zoneId);
int func_0217BED4(int zoneId, VecFx32 *out);
void func_0217BF1C(IntrudeStartParam *param);
u8 func_0217BF28(IntrudeStartParam *param);
void func_0217BF2C(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height, u16 objCode, u16 eventId, u16 objId);
void func_0217BF84(struct FieldMap *fieldMap);
int func_0217BFD8(struct GameSystem *gameSystem, int zoneId);
int func_0217C070(IntrudeCommSys *work);
void func_0217C094(IntrudeCommSys *work);
u8 func_0217C0A8(struct GameComm *gameComm);
int func_0217C11C(u32 zoneId);
void func_0217C14C(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height);
void func_0217C194(struct FieldMap *fieldMap);
void func_0217C1D0(const SymbolSpawnContext *spawn, const SymbolMonEntry *entry, u16 objId, u16 gridX, u16 gridZ, int height);
void func_0217C274(u32 *out, Mmdl *mmdl);
int func_0217C294(Mmdl *mmdl);
void *func_0217C2A0(int heapId, struct GameData *gameData, const SymbolMonEntry *entry);
void func_0217C37C(struct FieldMap *fieldMap, int objIdBase, SymbolMonEntry *entries, int unused, int cellKind);
struct GameEvent *func_0217C458(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work, u16 senderNetId);
int func_0217C4D0(struct GameEvent *event, u32 *seq, OfferEventWork *work);
void func_0217C658(PlayerSpinWork *spin, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 objCode, u8 kind, u8 flag);
int func_0217C688(PlayerSpinWork *spin, IntrudeCommSys *work);

extern const VecFx32 d_02182B90;
extern const char d_02183AE0[];
extern u16 d_021DB810[];
extern IntrudeTilePos d_021DB834[];
extern IntrudeZonePos d_02182B9C[];
extern const VecFx32 d_02182B60;
extern const MmdlHeader d_02182B6C;
extern const IntrudeAreaMmdlDef d_02182B54[];
extern const u32 d_021700A4;
extern const u16 d_02170128[];
extern const MmdlHeader d_021835D4;
extern const IntrudeMmdlMoveParam d_0218360C[];
extern const MmdlHeader d_0218362C;
extern const u8 d_02183678[20][2];
extern const u8 d_021835F8[20][2];
extern const u8 d_02183650[20][2];
extern const u8 d_021836A0[4];

void func_0217AE20(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player)
{
    int zoneId;
    struct GameComm *gameComm;
    IntrudeCommSys *work;
    struct GameData *gameData;
    int ownId;
    int i;
    int objCode;

    gameComm = func_02012138(gameSystem);
    work = func_02026474(gameComm);
    gameData = func_020120F4(gameSystem);
    if (func_02012E40(gameData) == 1)
        return;
    func_0217B968(fieldMap, gameSystem, gameComm, player);
    if (func_02026454(gameComm) != 2 || work == 0)
        return;
    zoneId = func_02012AC8(func_020127A4(gameData));
    if (work->specialZoneEntered == 0 && func_02013D5C(zoneId) == 1)
        work->specialZoneEntered = 1;
    func_0217BBD8(fieldMap, gameSystem, work);
    if (work->step != 7 || func_0200FB24() != 0)
        return;
    if (func_02012B70(gameData) == 0) {
        if (work->zoneCheck == 0) {
            if (func_0217C11C(work->localPeer.zoneId) == 1)
                work->zoneCheck = 1;
            else
                work->zoneCheck = 2;
        }
        if (work->zoneCheck == 2)
            return;
    }
    ownId = func_02012B58(gameData);
    func_02175004(work);
    func_02167590(gameSystem, work->commPlayer);
    for (i = 0; i < 3; i++) {
        if (i == ownId || !(work->peerMask & (1 << i)))
            continue;
        if (func_021677E4(work->commPlayer, i) == 0) {
            func_02012950(gameData, i);
            objCode = func_02175598(&work->peers[i], func_02012950(gameData, i));
            if (work->peers[i].objCode != 0 || func_02012B70(gameData) != 0)
                func_021675D0(work->commPlayer, i, objCode, &work->peers[i].package);
        } else {
            func_02167848(work->commPlayer, i, &work->peers[i].package);
            if (work->peers[i].package.vanish == 0) {
                if ((u16)(work->peers[i].state + 0xFFFE) <= 1)
                    func_021679C4(work->commPlayer, i);
            }
        }
    }
    func_0217BAB4(fieldMap, gameSystem, player, work);
}

int func_0217AFC4(IntrudeCommSys *work, struct FieldPlayer *player, int *outIndex)
{
    int moveState;
    int peerIndex;
    int hit;
    int result;
    s16 grid[3];

    result = 0;
    hit = result;
    if (work == 0 || work->commPlayer == 0)
        return 0;
    moveState = func_021A3098(player);
    if (moveState != 0 && moveState != 1)
        return result;
    func_021A3460(player, grid + 2, grid + 1, grid);
    for (;;) {
        moveState = func_021679A4(work->commPlayer, grid[2], grid[1], grid[0], &peerIndex, &hit);
        if (moveState != 1)
            break;
        if (work->peers[peerIndex].package.vanish == 0) {
            *outIndex = peerIndex;
            return 1;
        }
    }
    return 0;
}

struct GameEvent *func_0217B044(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 moveDir, u16 edgeDir, int sessionBusy)
{
    struct GameEvent *event;
    EdgeBlockWork *work;

    event = func_020122C0(gameSystem, 0, func_0217B084, sizeof(EdgeBlockWork));
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, sizeof(EdgeBlockWork));
    work->fieldMap = fieldMap;
    work->playerMmdl = func_021A3074(player);
    work->moveDir = moveDir;
    work->edgeDir = edgeDir;
    work->sessionBusy = sessionBusy;
    return event;
}

int func_0217B084(struct GameEvent *event, u32 *seq, EdgeBlockWork *work, u32 eventArg3)
{
    u16 turnAcmd;
    int acmd;
    struct FieldMsgBg *msgBg;

    switch (*seq) {
    case 0:
        if (func_0216D3CC(work->playerMmdl) == 1) {
            if (work->edgeDir == 3)
                acmd = 3;
            else
                acmd = 2;
            turnAcmd = acmd;
            if (work->edgeDir != func_0216D5F8(work->playerMmdl)) {
                func_0216D410(work->playerMmdl, turnAcmd);
                *seq += 1;
            } else {
                *seq = 2;
            }
        }
        break;
    case 1:
        if (func_0216D454(work->playerMmdl, seq, work, eventArg3) == 1) {
            func_0216D480(work->playerMmdl);
            *seq += 1;
        }
        break;
    case 2:
        func_0216D9A0(func_02188C7C(work->fieldMap));
        msgBg = func_02188C54(work->fieldMap);
        work->msgData = func_021904B0(msgBg, 0x2D);
        work->msgWin = func_021907A8(msgBg, work->msgData);
        func_02190740(work->msgWin, 0, 0, work->sessionBusy == 0 ? 0x52 : 0x4F);
        *seq += 1;
        break;
    case 3:
        if (func_0219077C(work->msgWin) == 1)
            *seq += 1;
        break;
    case 4:
        if (work->sessionBusy == 0) {
            if (func_020362DC() & 3)
                *seq += 1;
        } else {
            if (func_020362DC() & 0xF3)
                *seq = 8;
        }
        break;
    case 5:
        func_02190788(work->msgWin);
        func_02190740(work->msgWin, 0, 0, 0x53);
        *seq += 1;
        break;
    case 6:
        if (func_0219077C(work->msgWin) == 1)
            *seq += 1;
        break;
    case 7:
        if (func_020362DC() & 0xF3)
            *seq += 1;
        break;
    case 8:
        func_02190728(work->msgWin);
        func_02045C04(work->msgData);
        *seq += 1;
        break;
    case 9:
        if (func_0216D3CC(work->playerMmdl) == 1) {
            func_0216D410(work->playerMmdl, (u16)(work->edgeDir == 3 ? 10 : 11));
            *seq += 1;
        }
        break;
    case 10:
        if (func_0216D454(work->playerMmdl, seq, work, eventArg3) == 1) {
            func_0216D480(work->playerMmdl);
            func_0216D9E4(func_02188C7C(work->fieldMap));
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *func_0217B1DC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 edgeDir)
{
    struct GameEvent *event;
    AreaChangeWork *work;

    event = func_020122C0(gameSystem, 0, func_0217B214, sizeof(AreaChangeWork));
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, sizeof(AreaChangeWork));
    work->fieldMap = fieldMap;
    work->playerMmdl = func_021A3074(player);
    work->edgeDir = edgeDir;
    return event;
}

int func_0217B214(struct GameEvent *event, u32 *seq, AreaChangeWork *work)
{
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *intrudeWork;
    struct FieldMsgBg *msgBg;
    struct STRBUF *nameText;
    struct STRBUF *template;
    PlayerLook look;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    intrudeWork = func_02158344(gameComm);
    switch (*seq) {
    case 0:
        func_0216D9A0(func_02188C7C(work->fieldMap));
        *seq += 1;
        break;
    case 1:
        if (func_0216D3CC(work->playerMmdl) == 0)
            break;
        if (intrudeWork == 0) {
            *seq = 6;
            break;
        }
        if (func_02175BE4(&intrudeWork->session) == 1) {
            work->sessionBusy = 1;
            func_0217C758(work->transitionWork, gameSystem, work->fieldMap, intrudeWork, 0, 0, 0, work->edgeDir, 0);
        } else if (func_021584A4(gameComm, gameData, work->edgeDir) == 1) {
            func_0217C758(work->transitionWork, gameSystem, work->fieldMap, intrudeWork, 0, 0, 0, work->edgeDir, 1);
        } else {
            func_02175548(func_02012944(gameData), &look.objCode, &look.kind, &look.flag);
            func_0217C758(work->transitionWork, gameSystem, work->fieldMap, intrudeWork, look.objCode, look.kind, look.flag, work->edgeDir, 1);
        }
        *seq += 1;
        break;
    case 2:
        if (func_0217C820(work->transitionWork, intrudeWork) == 1)
            *seq += 1;
        break;
    case 3:
        if (intrudeWork == 0) {
            *seq = 6;
            break;
        }
        msgBg = func_02188C54(work->fieldMap);
        work->msgData = func_021904B0(msgBg, 0x2D);
        work->msgWin = func_021907A8(msgBg, work->msgData);
        work->wordSet = func_0201EC64(4);
        if (intrudeWork->localPeer.intrudeId == func_02012B58(gameData)) {
            if (work->sessionBusy == 1)
                func_02190740(work->msgWin, 0, 0, 0x4F);
            else
                func_02190740(work->msgWin, 0, 0, 0x4E);
        } else {
            nameText = func_020457B0(0x100, 0x15);
            func_0201F02C(work->wordSet, 0, func_02012950(gameData, intrudeWork->localPeer.intrudeId));
            if (work->sessionBusy == 1)
                template = func_02045EC0(work->msgData, 0x50);
            else
                template = func_02045EC0(work->msgData, 0x51);
            func_0201F250(work->wordSet, nameText, template);
            func_02190758(work->msgWin, 0, 0, nameText);
            func_02045808(template);
            func_02045808(nameText);
        }
        *seq += 1;
        break;
    case 4:
        if (func_0219077C(work->msgWin) == 1) {
            msgBg = (struct FieldMsgBg *)func_02188D20(work->fieldMap);
            func_021BC5A0((int)msgBg, func_02188C9C(work->fieldMap));
            *seq += 1;
        }
        break;
    case 5:
        if (func_020362DC() & 0xF3)
            *seq += 1;
        break;
    case 6:
        if (work->msgWin != 0) {
            func_02190728(work->msgWin);
            func_02045C04(work->msgData);
            func_0201ED04(work->wordSet);
        }
        func_0216D9E4(func_02188C7C(work->fieldMap));
        return 1;
    }
    return 0;
}

int func_0217B410(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player)
{
    int zoneId;
    IntrudeCommSys *work;
    int i;
    int areaBaseX;
    VecFx32 playerPos;
    VecFx32 markerPos;

    zoneId = func_02012AC8(func_020120F8(gameSystem));
    work = func_02158344(func_02012138(gameSystem));
    if (func_02013D5C(zoneId) == 0)
        return 0;
    func_021A3038(player, &playerPos);
    for (i = 0; i < 3; i++) {
        if (playerPos.x >= (i << 22) + 0x1F8000 && playerPos.x <= (i << 22) + 0x1F8000 && playerPos.z >= 0x2C8000 && playerPos.z <= 0x2C8000)
            return (int)func_0217B5DC(gameSystem, fieldMap, work);
    }
    areaBaseX = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (playerPos.x >= areaBaseX && playerPos.x < areaBaseX + 0x20000 && playerPos.z == 0x158000) {
            markerPos = d_02182B90;
            markerPos.x += playerPos.x - areaBaseX;
            return (int)func_0216B340(gameSystem, 1, &markerPos, 0, 4); /* int-typed on purpose: function returns int */
        }
        areaBaseX += 0x400000;
    }
    return 0;
}

struct GameEvent *func_0217B4D8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, int *posX, u16 moveDir, u16 facingDir)
{
    IntrudeCommSys *work;
    u16 edgeDir;
    int column;
    int x;
    int areaCount;
    int offsetInArea;

    work = func_02158344(func_02012138(gameSystem));
    edgeDir = 9;
    x = *posX;
    areaCount = 1;
    if (work)
        areaCount = work->memberCount;
    if (x <= 0) {
        x += areaCount << 22;
    } else if (x >= areaCount << 22) {
        x -= areaCount << 22;
    }
    column = ((x >> 12) / 16) % 64;
    offsetInArea = x % 0x400000;
    if (facingDir == 2) {
        if ((moveDir != 3 || (moveDir == 3 && offsetInArea <= 0x8000)) && column == 0)
            edgeDir = 2;
    } else if (facingDir == 3) {
        if ((moveDir != 2 || (moveDir == 2 && offsetInArea >= 0x3F8000)) && column == 0x3F)
            edgeDir = 3;
    }
    if (edgeDir != 9) {
        if (work == 0 || func_0203D1B4() <= 1 || work->memberCount < 2)
            return func_0217B044(gameSystem, fieldMap, player, moveDir, edgeDir, 0);
        if (func_02175BE4(&work->session) == 1)
            return func_0217B044(gameSystem, fieldMap, player, moveDir, edgeDir, 1);
        return func_0217B1DC(gameSystem, fieldMap, player, edgeDir);
    }
    return 0;
}

struct GameEvent *func_0217B5DC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work)
{
    struct GameEvent *event;
    ExitConfirmWork *eventWork;

    event = func_020122C0(gameSystem, 0, func_0217B600, sizeof(ExitConfirmWork));
    eventWork = func_020124E8(event);
    MI_CpuFill8(eventWork, 0, sizeof(ExitConfirmWork));
    return event;
}

/*
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * pool_02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * func_020127A4; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *func_02012798(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the player work indexer that belongs beside func_02012950 in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 */
int func_0217B600(struct GameEvent *event, u32 *seq, ExitConfirmWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameComm *gameComm;
    struct FieldMsgBg *msgBg;
    int answer;
    struct GameData *gameData;
    int i;
    u8 zeroPos[12];
    VecFx32 *zeroPosView;
    Mmdl *playerMmdl;

    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    gameComm = func_02012138(gameSystem);
    switch (*seq) {
    case 0:
        func_0216D9A0(func_02188C7C(fieldMap));
        msgBg = func_02188C54(fieldMap);
        work->msgData = func_021904B0(msgBg, 0x2D);
        work->promptWin = func_02190F64(msgBg, work->msgData);
        func_02190E74(work->promptWin, 0, 0, 0x54);
        *seq += 1;
        break;
    case 1:
        if (func_02190EF0(work->promptWin) == 1) {
            work->yesNoMenu = func_02190BE4(func_02188C54(fieldMap), 0);
            *seq += 1;
        }
        break;
    case 2:
        answer = func_02190C78(work->yesNoMenu);
        if (answer != 2) {
            func_021909BC(work->yesNoMenu);
            func_02190E40(work->promptWin);
            work->yesNoMenu = 0;
            work->promptWin = 0;
            if (answer == 0)
                *seq = 3;
            else
                *seq = 11;
        }
        break;
    case 3:
        if (func_0200FB24() == 0 && func_02026454(gameComm) == 2) {
            func_02026400(gameComm);
            work->endMsgWin = func_021907A8(func_02188C54(fieldMap), work->msgData);
            func_02190740(work->endMsgWin, 0, 0, 0x14);
        }
        *seq += 1;
        break;
    case 4:
        if (work->endMsgWin == 0 || func_0219077C(work->endMsgWin) == 1)
            *seq += 1;
        break;
    case 5:
        work->waitFrames++;
        if (work->endMsgWin != 0 && work->waitFrames <= 0x3C)
            break;
        if (func_02026454(gameComm) == 2)
            break;
        gameData = func_020120F4(gameSystem);
        zeroPosView = (VecFx32 *)zeroPos;
        zeroPosView->x = 0;
        zeroPosView->y = 0;
        zeroPosView->z = 0;
        for (i = 0; i < 3; i++)
            func_02012A90(func_02012798(gameData, i), zeroPosView);
        *seq += 1;
        break;
    case 6:
        if (work->endMsgWin != 0)
            func_02190728(work->endMsgWin);
        func_02045C04(work->msgData);
        *seq += 1;
        break;
    case 7:
        fieldMap = func_0201210C(gameSystem);
        if (func_02188BE8(fieldMap) != 1)
            break;
        if (func_021A3238(func_02188CB4(fieldMap)) == 0) {
            func_0217C658(&work->spin, gameSystem, fieldMap, 0, 0, 0);
            *seq += 1;
        } else {
            *seq = 9;
        }
        break;
    case 8:
        if (func_0217C688(&work->spin, 0) == 1)
            *seq += 1;
        break;
    case 9:
        func_02012374(event, func_02185214(gameSystem));
        *seq += 1;
        break;
    case 10:
        *seq = 14;
        break;
    case 11:
        func_02045C04(work->msgData);
        *seq = 12;
        break;
    case 12:
        playerMmdl = func_021A3074(func_02188CB4(fieldMap));
        if (func_0216D3CC(playerMmdl) == 1) {
            func_0216D410(playerMmdl, 8);
            *seq += 1;
        }
        break;
    case 13:
        if (func_0216D480(func_021A3074(func_02188CB4(fieldMap))) == 1)
            *seq = 14;
        break;
    case 14:
        func_0216D9E4(func_02188C7C(fieldMap));
        return 1;
    }
    return 0;
}

struct GameEvent *func_0217B810(struct GameSystem *gameSystem, VecFx32 *pos)
{
    struct GameEvent *event;
    NoticeEventWork *work;

    event = func_020122C0(gameSystem, 0, func_0217B82C, sizeof(NoticeEventWork));
    work = func_020124E8(event);
    return event;
}

int func_0217B82C(struct GameEvent *event, u32 *seq, NoticeEventWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct FieldMsgBg *msgBg;

    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    func_02012138(gameSystem);
    switch (*seq) {
    case 0:
        func_0216D9A0(func_02188C7C(fieldMap));
        msgBg = func_02188C54(fieldMap);
        work->msgData = func_021904B0(msgBg, 0x2D);
        work->promptWin = func_02190F64(msgBg, work->msgData);
        func_02190E74(work->promptWin, 0, 0, 0x60);
        (*seq)++;
        break;
    case 1:
        if (func_02190EF0(work->promptWin) == 1) {
            func_02190E40(work->promptWin);
            func_02045C04(work->msgData);
            (*seq)++;
        }
        break;
    case 2:
        fieldMap = func_0201210C(gameSystem);
        if (func_02188BE8(fieldMap) == 1) {
            if (func_021A3238(func_02188CB4(fieldMap)) == 0) {
                func_0217C658(&work->spin, gameSystem, fieldMap, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 4;
            }
        }
        break;
    case 3:
        if (func_0217C688(&work->spin, 0) == 1)
            (*seq)++;
        break;
    case 4:
        func_02012374(event, func_02185214(gameSystem));
        (*seq)++;
        break;
    case 5:
        if (fieldMap != 0 && func_02188BE8(fieldMap) == 1) {
            func_0216D9E4(func_02188C7C(fieldMap));
            return 1;
        }
        break;
    }
    return 0;
}

int func_0217B930(const VecFx32 *pos)
{
    if (pos->x >= 0x348000 || pos->x <= 0xb8000)
        return 1;
    return 0;
}

int func_0217B94C(const VecFx32 *pos)
{
    if (pos->x > 0x308000 || pos->x < 0xe8000)
        return 1;
    return 0;
}

void func_0217B968(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct GameComm *gameComm, struct FieldPlayer *player)
{
    VecFx32 playerPos;

    if (func_0202648C(gameComm) != 0)
        return;
    if (func_02026460(gameComm) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (func_02012204(gameSystem) == 1)
        return;
    if (func_020120D8(gameSystem) == 1)
        return;
    if (func_02013D5C(func_02012AC8(func_020127A4(func_020120F4(gameSystem)))) == 0)
        return;
    func_021A3038(player, &playerPos);
    switch (func_02026454(gameComm)) {
    case 0:
        if (func_0217B930(&playerPos) == 1)
            func_0217BA54(gameSystem);
        break;
    case 2:
        if (func_0217B930(&playerPos) != 0)
            return;
        if (func_020392B8() > 1)
            return;
        if (((IntrudeCommSys *)func_02026474(gameComm))->step == 4)
            return;
        func_02026400(gameComm);
        break;
    case 1:
        if (func_0217B930(&playerPos) == 1)
            func_0202640C(gameComm, (u32)func_0217BA48, (u32)gameSystem);
        break;
    }
}

void func_0217BA48(struct GameSystem *gameSystem, int result)
{
    if (result == 0)
        func_0217BA54(gameSystem);
}

void func_0217BA54(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    IntrudeStartParam *param;

    gameComm = func_02012138(gameSystem);
    if (func_0200FB24() != 0)
        return;
    if (func_02012204(gameSystem) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    param = func_02030734(0x8005, 0x10, 1, d_02183AE0, 0x528);
    param->startKind = 1;
    param->gameSystem = gameSystem;
    param->gameComm = gameComm;
    func_020263D8(gameComm, 2, (u32)param);
}

void func_0217BAB4(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player, IntrudeCommSys *work)
{
    int x;
    int areaIndex;
    VecFx32 playerPos;
    VecFx32 wrappedPos;
    int wrapped;
    int prevAreaId;
    int areaSpan;
    int zoneId;
    struct PlayerWork *playerWork;
    struct GameComm *gameComm;

    playerWork = func_020120F8(gameSystem);
    zoneId = func_02012AC8(playerWork);
    func_02012AE4(playerWork);
    gameComm = func_02012138(gameSystem);
    wrapped = 0;
    func_020120F4(gameSystem);
    if ((int)func_02026454(gameComm) != 2)
        return;
    if (work == 0)
        return;
    if (func_02013D5C(zoneId) == 0)
        return;
    if (work->memberCount < 2)
        return;
    if (func_02175E90(work, &work->session) == 1)
        return;
    func_021A3038(player, &playerPos);
    wrappedPos = playerPos;
    x = playerPos.x;
    prevAreaId = work->localPeer.intrudeId;
    areaSpan = (work->lastAreaIndex + 1) << 22;
    if (x < 0) {
        wrappedPos.x = areaSpan + x;
        wrapped = 1;
    } else if (x > areaSpan) {
        wrappedPos.x = x - areaSpan;
        wrapped = 1;
    }
    if (wrapped == 1) {
        x = wrappedPos.x;
        if (func_020120D8(gameSystem) == 1) {
            wrappedPos = playerPos;
            wrapped = 0;
        }
    }
    areaIndex = x / 0x400000;
    if (wrapped == 1) {
        func_021A3044(player, &wrappedPos);
        func_02175274(work, wrappedPos.x);
    }
    areaIndex += func_02039338();
    if (areaIndex > work->lastAreaIndex)
        areaIndex -= work->lastAreaIndex + 1;
    if (prevAreaId == areaIndex)
        return;
    func_02175710(work, areaIndex);
    work->peerStatusDirty = 1;
    func_02161FEC(work->returnSlots, (u8)areaIndex);
}

void func_0217BBCC(int unusedArg0, int unusedArg1, IntrudeCommSys *work)
{
    work->lastAreaIndex = 0;
}

void func_0217BBD8(struct FieldMap *fieldMap, struct GameSystem *gameSystem, IntrudeCommSys *work)
{
    VecFx32 playerPos;
    int areaLimit;
    struct FieldPlayer *player;
    struct MapMatrix *matrix;

    if (work == 0 || fieldMap == 0)
        return;
    if (func_02188C98(fieldMap) == 0)
        return;
    if (func_02013D5C(func_02188C9C(fieldMap)) == 0)
        return;
    areaLimit = work->memberCount - 1;
    if (areaLimit <= 0)
        areaLimit = 1;
    if (work->flagBit5 == 1)
        areaLimit = 1;
    if (work->lastAreaIndex >= areaLimit)
        return;
    player = func_02188CB4(fieldMap);
    if (player == 0)
        return;
    func_021A3038(player, &playerPos);
    playerPos.x = playerPos.x % 0x400000;
    if (func_0217B94C(&playerPos) == 1)
        return;
    matrix = func_02159B48(0x8015);
    func_02159B94(matrix, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        func_0218CD20(fieldMap, func_02188C98(fieldMap), matrix);
        work->lastAreaIndex++;
    } while (work->lastAreaIndex < areaLimit);
    func_02159BBC(matrix);
}

void func_0217BC94(struct FieldMap *fieldMap, int count)
{
    struct MapMatrix *matrix;

    if (count >= 3)
        count = 2;
    matrix = func_02159B48(0x15);
    func_02159B94(matrix, 0x76, 0x76 + 0xa1, 0x8015);
    while (count > 0) {
        func_0218CD20(fieldMap, func_02188C98(fieldMap), matrix);
        count--;
    }
    func_02159BBC(matrix);
}

void func_0217BCDC(IntrudeCommSys *work, struct GameSystem *gameSystem, int objCode, u8 kind, u8 flag)
{
    int playerForm;
    struct FieldPlayer *player;
    int gender;
    struct PlayerStatus *myStatus;
    struct GameData *gameData = func_020120F4(gameSystem);
    VecFx32 drawOffset = { 0, 0, 0 };

    if (func_02012114(gameSystem) == 0)
        return;
    myStatus = func_02012944(func_020120F4(gameSystem));
    gender = func_02008550(myStatus);
    if (work != 0) {
        if (objCode == 0xFFFF) {
            if (work->localPeer.intrudeId == func_02012B58(gameData))
                objCode = 0;
        }
        if (objCode == 0) {
            kind = gender == 0 ? 3 : 4;
            flag = gender;
        }
        if (work->localPeer.objCode == objCode)
            return;
        work->localPeer.objCode = objCode;
        work->localPeer.lookKind = kind;
        work->localPeer.lookFlag = flag;
        work->peerStatusDirty = 1;
        playerForm = func_02175598(&work->localPeer, myStatus);
    } else {
        objCode = 0;
        playerForm = 1;
        if (gender)
            playerForm = 4;
    }
    player = func_02188CB4(func_0201210C(gameSystem));
    func_021A3220(player, (u16)playerForm);
    func_0216D8C0(func_021A3074(player), &drawOffset);
    if (objCode == 0)
        func_021A322C(player);
}

int func_0217BDE0(struct GameSystem *gameSystem, IntrudeCommSys *work, struct FieldPlayer *player)
{
    IntrudeMemberRecord *offer;
    int zoneId;
    int offerIndex;
    GridPos playerGrid;

    if (func_02175B8C(&work->session) != 1)
        goto fail;
    if (func_02175BBC(&work->session) != 0)
        goto fail;
    offer = func_02175B34(&work->session);
    if (offer == 0)
        goto fail;
    if (offer->head.kind != 4)
        goto fail;
    if (work->localPeer.intrudeId != offer->name.netId)
        goto fail;
    if (func_02175CF4(work, &work->session) != 0)
        goto fail;
    zoneId = func_02012AC8(func_020120F8(gameSystem));
    func_0216D828(func_021A3074(player), &playerGrid);
    offerIndex = offer->head.param.x;
    if (zoneId != d_021DB810[offerIndex])
        goto fail;
    if (playerGrid.x != d_021DB834[offerIndex].x)
        goto fail;
    if (playerGrid.y != d_021DB834[offerIndex].y)
        goto fail;
    if (playerGrid.z != d_021DB834[offerIndex].z)
        goto fail;
    return func_02182124(gameSystem, work, offer);
fail:
    return 0;
}

IntrudeZonePos *func_0217BEA8(u32 zoneId)
{
    u32 i;

    for (i = 0; i < 218; i++) {
        if (d_02182B9C[i].zoneId == zoneId)
            return &d_02182B9C[i];
    }
    return 0;
}

int func_0217BED4(int zoneId, VecFx32 *out)
{
    IntrudeZonePos *entry;
    int x, y, z;

    if (func_02013D5C(zoneId) != 1) {
        entry = func_0217BEA8(zoneId);
        if (entry == 0)
            return 0;
        z = entry->tileZ << 16;
        y = entry->tileY << 16;
        x = entry->tileX << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = d_02182B60;
    }
    return 1;
}

void func_0217BF1C(IntrudeStartParam *param)
{
    MI_CpuFill8(param, 0, 0x10);
}

u8 func_0217BF28(IntrudeStartParam *param)
{
    return param->startKind;
}

void func_0217BF2C(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height, u16 objCode, u16 eventId, u16 objId)
{
    MmdlHeader header;
    MmdlGridPos *gridPos;
    MmdlSys *mmdlSys;
    int zoneId;

    mmdlSys = func_02188C7C(fieldMap);
    zoneId = func_02188C9C(fieldMap);
    header = d_02182B6C;
    header.objId = objId;
    header.objCode = objCode;
    header.eventId = eventId;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    func_0216CE60(mmdlSys, &header, zoneId);
}

/*
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 */
void func_0217BF84(struct FieldMap *fieldMap)
{
    AreaMmdlIndex defIndex;
    int areaIndex;
    unsigned int gridX;

    areaIndex = 1;
    do {
        defIndex = AREA_MMDL_FIRST;
        do {
            gridX = d_02182B54[defIndex].gridX;
            func_0217BF2C(fieldMap, gridX + (areaIndex << 6), d_02182B54[defIndex].gridZ, 0x2001F, d_02182B54[defIndex].objCode, d_02182B54[defIndex].eventId, areaIndex + d_02182B54[defIndex].objIdBase - 1);
            defIndex++;
        } while ((unsigned int)defIndex < 1);
        areaIndex++;
    } while (areaIndex < 3);
}

int func_0217BFD8(struct GameSystem *gameSystem, int zoneId)
{
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *work;

    gameData = func_020120F4(gameSystem);
    gameComm = func_02012138(gameSystem);
    work = func_02158344(gameComm);
    if (func_02012B70(gameData) == 0)
        return 0;
    if (work != 0)
        return 0;
    if (func_02012204(gameSystem) == 1)
        return 1;
    if (func_02013D5C(zoneId) == 1) {
        if (func_0202648C(gameComm) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(zoneId) == 1) {
        if (func_02026454(gameComm) == 2 || (func_02026454(gameComm) == 0 && func_0202647C(gameComm) == 2 && func_0202648C(gameComm) != 0))
            return 1;
        return 0;
    }
    return 1;
}

int func_0217C070(IntrudeCommSys *work)
{
    if (work->startFlag == 1 || func_02176258(work) == 1)
        return 1;
    return 0;
}

void func_0217C094(IntrudeCommSys *work)
{
    if (work != 0) {
        work->flagBit5 = 1;
    }
}

u8 func_0217C0A8(struct GameComm *gameComm)
{
    struct GameData *gameData;
    IntrudeCommSys *hostWork;
    struct PlayerStatus *status;

    gameData = func_02026478(gameComm);
    if (func_02012B70(gameData) == 0) {
        status = func_02012944(gameData);
    } else if (func_02012B80(gameData) == func_02012B58(gameData)) {
        status = func_02012944(gameData);
    } else {
        hostWork = 0;
        if (func_02026454(gameComm) == 2 && func_02026474(gameComm) != 0)
            hostWork = func_02026474(gameComm);
        if (hostWork == 0) {
            status = func_02012944(gameData);
        } else if (func_02013D5C(hostWork->localPeer.zoneId) == 1) {
            status = func_02012944(gameData);
        } else {
            status = func_02012950(gameData, func_02012B80(gameData));
        }
    }
    return func_02008550(status);
}

/*
 * lever: index declared before count preserves r3/r4 allocation.
 */
int func_0217C11C(u32 zoneId)
{
    u32 i;
    u32 count;

    count = d_021700A4;
    for (i = 0; i < count; ++i) {
        if (zoneId == d_02170128[i])
            return 1;
    }
    return 0;
}

void func_0217C14C(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height)
{
    MmdlSys *mmdlSys;
    int zoneId;
    MmdlHeader header;
    MmdlGridPos *gridPos;

    mmdlSys = func_02188C7C(fieldMap);
    zoneId = func_02188C9C(fieldMap);
    header = d_021835D4;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    func_0216CE60(mmdlSys, &header, zoneId);
}

/*
 * extent: two alignment bytes at 0x0217C1CE.
 */
void func_0217C194(struct FieldMap *fieldMap)
{
    int i;

    if (func_02013D5C(func_02188C9C(fieldMap)) != 0) {
        for (i = 0; i < 3; ++i)
            func_0217C14C(fieldMap, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}

/*
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 */
void func_0217C1D0(const SymbolSpawnContext *spawn, const SymbolMonEntry *entry, u16 objId, u16 gridX, u16 gridZ, int height)
{
    const IntrudeMmdlMoveParam *moveParam;
    int mmdlSys;
    u16 zoneId;
    MmdlHeader header;
    MmdlGridPos *gridPos;

    moveParam = &d_0218360C[entry->appearance];
    mmdlSys = (int)func_02188C7C(spawn->fieldMap);
    zoneId = func_02188C9C(spawn->fieldMap);
    header = d_0218362C;
    header.objId = objId;
    header.objCode = func_0202A188(spawn->tpoke, (u16)entry->species, (u16)entry->sex, (u16)entry->form);
    header.moveCode = moveParam->moveCode;
    header.moveLimitX = moveParam->moveLimitX;
    header.moveLimitZ = moveParam->moveLimitZ;
    header.param0 = spawn->objIdBase + objId;
    header.param1 = *(const u32 *)entry;
    header.param2 = *(const u32 *)entry >> 16;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    func_0216CE60((MmdlSys *)mmdlSys, &header, zoneId);
}

void func_0217C274(u32 *out, Mmdl *mmdl)
{
    int low;

    low = func_0216D63C(mmdl, 1);
    *out = low | (func_0216D63C(mmdl, 2) << 16);
}

/*
 * Recursive MATCH unblocker: callee of func_0216AC90 (ov010) +0026 and
 * func_0216ACCC (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 */
int func_0217C294(Mmdl *mmdl)
{
    return func_0216D63C(mmdl, 0);
}

/*
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 */
void *func_0217C2A0(int heapId, struct GameData *gameData, const SymbolMonEntry *entry)
{
    u8 *levelTable;
    u8 level;
    u32 trainerId;
    u32 personality;
    void *mon;

    levelTable = func_0204A1BC(0xE3, 0, 0, heapId);
    level = levelTable[entry->species];
    func_020307B0(levelTable);
    trainerId = func_02008530(func_02012944(gameData));
    personality = func_020186C8(trainerId, (u16)entry->species, (u16)entry->form, entry->sex, 0, 0);
    mon = func_020173F0(entry->species, level, -1, heapId);
    func_02017588(mon, entry->species, level, trainerId, -1, personality);
    func_02018A00(mon, entry->species, entry->form);
    func_02017988(mon, (u16)entry->form);
    if (entry->move != 0) {
        if (func_0201808C(mon, entry->move) == 0xFFFF)
            func_020180F4(mon, (u16)entry->move);
    }
    return mon;
}

void func_0217C37C(struct FieldMap *fieldMap, int objIdBase, SymbolMonEntry *entries, int unused, int cellKind)
{
    const u8 (*offsets)[2];
    SymbolSpawnContext spawn;
    Mmdl *playerMmdl;
    u16 playerGridX;
    u16 playerGridZ;
    int i;
    int jitterX;
    int jitterZ;
    int x;
    int z;

    if (func_02166618(cellKind))
        offsets = d_02183678;
    else if (func_02166640(cellKind))
        offsets = d_021835F8;
    else
        offsets = d_02183650;

    spawn.tpoke = func_0202A128(func_02188C84(fieldMap));
    spawn.fieldMap = fieldMap;
    spawn.objIdBase = objIdBase;
    playerMmdl = func_021A3074(func_02188CB4(fieldMap));
    playerGridX = func_0216D83C(playerMmdl);
    playerGridZ = func_0216D86C(playerMmdl);

    for (i = 0; i < 20; i++) {
        if (entries[i].species != 0) {
            jitterX = func_02005728(2) - 1;
            jitterZ = func_02005728(2) - 1;
            x = jitterX + offsets[i][0];
            z = jitterZ + offsets[i][1];
            if (playerGridX == x && playerGridZ == z) {
                if (jitterX != 0)
                    x -= jitterX;
                else if (jitterZ != 0)
                    z -= jitterZ;
                else
                    x++;
            }
            func_0217C1D0(&spawn, &entries[i], i, x, z, 0);
        }
    }
    func_0202A170(spawn.tpoke);
}

struct GameEvent *func_0217C458(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work, u16 senderNetId)
{
    IntrudeMemberRecord *offer;
    OfferEventWork *eventWork;
    struct GameEvent *event;

    offer = func_02175B34(&work->session);
    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_0217C4D0, sizeof(OfferEventWork));
    eventWork = func_020124E8(event);
    MI_CpuFill8(eventWork, 0, sizeof(OfferEventWork));
    eventWork->senderNetId = senderNetId;
    eventWork->fieldMap = fieldMap;
    eventWork->record = *offer;
    eventWork->showInfo = 1;
    func_0217F2B4(eventWork->infoWindow, gameSystem);
    func_02174E14(work, 5);
    return event;
}

/*
 * Task callback registered by func_0217C458 (0x88-byte work, state word
 * in the second argument).
 */
int func_0217C4D0(struct GameEvent *event, u32 *seq, OfferEventWork *work)
{
    struct GameSystem *gameSystem;
    IntrudeCommSys *intrudeWork;
    u16 pointIndex;
    u8 ownId;

    gameSystem = func_020124E4(event);
    intrudeWork = func_02158344(func_02012138(gameSystem));
    if (intrudeWork == 0 && *seq == 0)
        *seq = 8;

    switch (*seq) {
    case 0:
        if (work->showInfo == 0) {
            *seq = 4;
            break;
        }
        func_0217F528(work->infoWindow, gameSystem, 1, 1, 0x1E, 0x10);
        func_021762D8(&work->record, &work->record.name, *(int *)work->infoWindow, work->senderNetId);
        pointIndex = work->record.head.pointIndex;
        func_0217F574(work->infoWindow, (u16)work->record.head.kind, 8, 0);
        func_0217F574(work->infoWindow, (u16)pointIndex, 8, 0x10);
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_02029830(gameSystem, 0x52B));
        (*seq)++;
        break;
    case 2:
        if (func_02005F38() == 0) {
            func_02012374(event, func_02029620(gameSystem, 0, 6));
            (*seq)++;
        }
        break;
    case 3:
        func_0217F58C(work->infoWindow);
        (*seq)++;
        break;
    case 4:
        ownId = (int)func_02012B58(func_020120F4(gameSystem));
        func_0217C658(&work->spin, gameSystem, work->fieldMap, work->record.head.ids[ownId], work->record.head.grades[ownId], ((IntrudeNetIdMask *)&work->record.head.reserved08)->netIds & (1 << ownId));
        (*seq)++;
        break;
    case 5:
        if (func_0217C688(&work->spin, intrudeWork) == 1)
            (*seq)++;
        break;
    case 6:
        if (intrudeWork != 0) {
            if (func_02173FC0(intrudeWork, &intrudeWork->session) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 7:
        if (intrudeWork != 0) {
            if (func_02175A24(&intrudeWork->session) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 8:
        func_0217F318(work->infoWindow);
        if (intrudeWork != 0)
            func_02174E14(intrudeWork, 0);
        return 1;
    }
    return 0;
}

/*
 * extent: two alignment bytes at 0x0217C686.
 */
void func_0217C658(PlayerSpinWork *spin, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 objCode, u8 kind, u8 flag)
{
    MI_CpuFill8(spin, 0, sizeof(PlayerSpinWork));
    spin->gameSystem = gameSystem;
    spin->fieldMap = fieldMap;
    spin->objCode = objCode;
    spin->kind = kind;
    spin->flag = flag;
    spin->stepFrames = 15;
    spin->shownStep = spin->stepFrames;
}

/*
 * Per-frame step of the 0x18-byte record func_0217C658 initialises.
 */
int func_0217C688(PlayerSpinWork *spin, IntrudeCommSys *work)
{
    Mmdl *playerMmdl;
    s16 frames;

    switch (spin->state) {
    case 0:
        spin->stepFrames = 15;
        spin->shownStep = spin->stepFrames;
        func_020061E4(0x738);
        spin->state++;
        break;
    case 1:
        if (func_02188BE8(spin->fieldMap) == 1) {
            playerMmdl = func_021A3074(func_02188CB4(spin->fieldMap));
            if (func_0216D3CC(playerMmdl) == 1) {
                if (spin->stepFrames >= 15 && spin->switched != 0 && d_021836A0[spin->dirIndex] == 1) {
                    spin->state++;
                    break;
                }
                spin->dirIndex = (spin->dirIndex + 1) & 3;
                frames = spin->stepFrames;
                spin->shownStep = frames;
                if (spin->switched == 0) {
                    spin->stepFrames--;
                    if (spin->stepFrames <= 1) {
                        func_020120F4(spin->gameSystem);
                        func_0217BCDC(work, spin->gameSystem, spin->objCode, spin->kind, spin->flag);
                        spin->switched++;
                    }
                } else if (frames < 15) {
                    spin->stepFrames++;
                }
                func_0216D410(playerMmdl, d_021836A0[spin->dirIndex]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}

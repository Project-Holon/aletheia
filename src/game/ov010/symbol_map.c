/*
 * file:     symbol_map.c
 * unit:     yes
 * function: func_0216630C, func_02166324, func_021663F4, func_02166434, func_0216649C, func_021664CC, func_021665D0, func_021665F0, func_02166618, func_0216662C, func_02166640, func_02166658, func_0216666C, func_021666A4, func_021666B8, func_0216670C, func_02166714, func_02166734, func_021667E0, func_02166824, func_02166834, func_02166854, func_02166908, func_02166980, func_021669C0, func_02166A00, func_02166A6C, func_02166B0C, func_02166B2C, func_02166B58, func_02166C4C, func_02166C7C, func_02166CD0, func_02166D30, func_02166E50, func_02166F1C, func_02166F9C, func_02167044, func_02167080, func_021670F8, func_0216711C, func_02167154, func_02167168, func_02167178, func_021671CC, func_021671DC, func_021671EC, func_021671FC, func_021672B4, func_021672D0, func_021672E4, func_021672F8, func_0216730C
 * address:  0x0216630C
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
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_021673C4  0x021673C4  thumb  ov010
 *   func_021673A8  0x021673A8  thumb  ov010
 *   func_02158344  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPartnerRecord  0x02176880  thumb  ov011
 *   d_02171EF4 0x02171EF4 data a4
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02030734  0x02030734  arm
 *   func_0216749C  0x0216749C  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021729EC     0x021729EC  data  a1
 *   func_02161CDC 0x02161CDC thumb ov010
 *   func_020307B0  0x020307B0  arm
 *   func_020124E8 0x020124E8 thumb
 *   func_02012444 0x02012444 thumb
 *   ov203_id 0x000000CB data a1
 *   d_021BFB3C 0x021BFB3C data ov203 a4
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_021C87A0  0x021C87A0  thumb ov021
 *   func_021C87AC  0x021C87AC  thumb ov021
 *   func_021C87B8  0x021C87B8  thumb ov021
 *   func_021C87C8  0x021C87C8  thumb ov021
 *   func_0215897C 0x0215897C thumb ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009794  0x02009794  thumb
 *   func_020095C8  0x020095C8  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   ov_id_DA  0x000000DA  data
 *   d_021BAB5C  0x021BAB5C  data  a4 ov218
 *   func_02012F38  0x02012F38  thumb
 *   d_02172BA4  0x02172BA4  data  ov010  a4
 *   d_021729FC  0x021729FC  data  ov010  a4
 *   func_0207AD58  0x0207AD58  thumb
 *   func_0207D59C  0x0207D59C  arm
 *   _fadd  0x0209C95C  arm
 *   _fdiv  0x0209CE10  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   func_02005654  0x02005654  thumb
 *   func_0207AD40 0x0207AD40 arm
 *   func_02017E1C  0x02017E1C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216559C  0x0216559C  thumb  ov010
 *   ov215_id       0x000000D7  data   a1
 *   d_021F7118     0x021F7118  data   ov215  a4
 *   func_02013E40  0x02013E40  thumb
 *   func_02012894  0x02012894  thumb
 *   d_02171F2C  0x02171F2C  data  ov010  a4
 *   func_0201296C  0x0201296C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02009590  0x02009590  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   PMSI_PARAM_Create  0x02024044  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   PMSI_PARAM_SetSentence  0x02024108  thumb
 *   PMSI_PARAM_CheckCanceled  0x0202411C  thumb
 *   PMSI_PARAM_GetWords  0x02024128  thumb
 *   PMSI_PARAM_GetWord  0x02024124  thumb
 *   PMSI_PARAM_GetSentence  0x02024134  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_0200E714  0x0200E714  thumb
 *   PMSI_PARAM_Delete  0x020240FC  thumb
 *   ov110_id       0x0000006E  data   a1
 *   d_021C39B8     0x021C39B8  data   ov110  a4
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0202C794  0x0202C794  thumb
 *   func_021A1BE4  0x021A1BE4  thumb  ov021
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 *   ov_id_D9  0x000000D9  data
 *   d_021C3FE0  0x021C3FE0  data  ov217
 *   d_02172A00 0x02172A00 data a1
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C54 0x02188C54 thumb ov021
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190728  0x02190728  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F31C  0x0201F31C  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_02190788  0x02190788  thumb
 *   GAME_DATA_GetSaveControlWork  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed int     s32;

struct GameSystem;
struct GameData;
struct ScriptVm;
struct GameTask;
struct FieldMap;
struct GameEvent;
struct SymbolMapSave;
struct SymbolMapSaveEntry;
struct MsgBank;
struct WordSet;
struct InfoWindow;
struct StrBuf;
struct ReportBlock;
struct Pokemon;

/* One list entry of the link record: an 11-bit id and 21 bits of payload. */
typedef struct SymbolMapEntry {
    u32 id : 11;
    u32 payload : 21;
} SymbolMapEntry;

/* The 0x54-byte record two players exchange over the link. */
typedef struct SymbolMapLinkRecord {
    SymbolMapEntry entries[20];   /* 0x00 */
    u32 entryCount : 6;           /* 0x50 */
    u32 symbolIndex : 4;          /* 0..6, low part of the grid table index */
    u32 symbolGroup : 4;          /* multiplied by 7 in the grid table index */
    u32 state : 4;                /* 4 = local record */
    u32 page : 6;
    u32 reserved : 8;
} SymbolMapLinkRecord;

/* Holder of the link record pointer (first field of the owner struct). */
typedef struct SymbolMapOwner {
    SymbolMapLinkRecord *linkRecord;
} SymbolMapOwner;

/* Progress record updated by the ov203 task. */
typedef struct SymbolMapProgress {
    u8 pad00[4];
    s16 lastResult;               /* 0x04 */
    u8 pad06[2];
    int bestRank;                 /* 0x08 */
} SymbolMapProgress;

/* Work of the ov203 record task (created by func_0216666C). */
typedef struct SymbolMapRecordWork {
    u32 linkWork[2];              /* 0x00, set up by the proc link starter */
    int lastResult;               /* 0x08 */
    u8 pad0C[4];
    u32 measuredValue;            /* 0x10, written by ov203 */
    u32 resultCode;               /* 0x14, 2 = completed */
    SymbolMapProgress *progress;  /* 0x18 */
    u16 *outCompleted;            /* 0x1C */
} SymbolMapRecordWork;

/* Header of the save sync block: a count and a list of byte items. */
typedef struct SaveSyncBlock {
    u8 type;                      /* 0x00 */
    u8 count;                     /* 0x01 */
    u8 variant;                   /* 0x02 */
    u8 items[1];                  /* 0x03, count entries */
} SaveSyncBlock;

/* Work of the ov218 picker task. ov218 writes the result bytes in the first 8 bytes. */
typedef struct SymbolMapPickerWork {
    u8 mode;                      /* 0x00 */
    u8 resultKind;                /* 0x01, written by ov218 */
    u16 resultValue;              /* 0x02, written by ov218 */
    int resultCode;               /* 0x04, 1 = picked */
    u16 candidateIds[20];         /* 0x08 */
    u8 ownedFlags[232];           /* 0x30, entries 1..232 */
    u8 pad118[4];
    u16 *outKind;                 /* 0x11C */
    u16 *outValue;                /* 0x120 */
    u16 *outPicked;               /* 0x124 */
} SymbolMapPickerWork;

/* One 0x1C-byte entry of the event state table; only the value at +0x14 is read. */
typedef struct EventStateEntry {
    u8 pad00[0x14];
    u32 value;                    /* 0x14 */
    u8 pad18[4];
} EventStateEntry;

/* Special location record: only the zone id is read. */
typedef struct SpecialLocation {
    u16 pad00[2];
    u16 zoneId;                   /* 0x04 */
} SpecialLocation;

typedef struct ZoneRemapEntry {
    u32 target;
    u32 source;
} ZoneRemapEntry;

/* Work of the ov215 task: runs the field close event, the ov215 proc and the field open event. */
typedef struct PokeEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    u32 transitionArg;              /* 0x08, argument of the field close and open events */
    struct Pokemon *poke;           /* 0x0C */
    struct {
        struct GameData *gameData;
        struct Pokemon *poke;
    } procParam;                    /* 0x10 */
} PokeEventWork;

/* Work of the PMS input task. */
typedef struct PmsInputWork {
    u32 kind;                       /* 0x00 */
    u16 *outWord0;                  /* 0x04 */
    u16 *outWord1;                  /* 0x08 */
    u16 *outResult;                 /* 0x0C */
    void *pmsParam;                 /* 0x10 */
    u32 sentenceId;                 /* 0x14 */
    u32 hasSentence;                /* 0x18 */
} PmsInputWork;

typedef struct PmsInputWords {
    u16 first;
    u16 second;
} PmsInputWords;

typedef struct PmsInputSentence {
    u16 header[2];
    u16 first;
    u16 second;
} PmsInputSentence;

/* Heap block handed to ov217: it holds the game system. */
typedef struct ResearchTopParam {
    struct GameSystem *gameSystem;
} ResearchTopParam;

/* Work of the ov217 task (close field, run ov217, open field). */
typedef struct ResearchTopTaskWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    int transitionArg;              /* 0x04, argument of the field close and open events */
    ResearchTopParam *param;        /* 0x08 */
} ResearchTopTaskWork;

/* Work of the research report task. */
typedef struct ResearchReportWork {
    u16 heapId;                     /* 0x00 */
    u8 pad02[2];
    struct GameSystem *gameSystem;  /* 0x04 */
    struct GameData *gameData;      /* 0x08 */
    struct FieldMap *fieldMap;      /* 0x0C */
    void *fx;                       /* 0x10 */
    struct InfoWindow *window;      /* 0x14 */
    struct MsgBank *msgBank;        /* 0x18 */
    struct WordSet *wordSet;        /* 0x1C */
} ResearchReportWork;

extern void *func_020120F4(const struct GameSystem *gameSystem);
extern void *func_02012EBC(struct GameData *gameData);
extern void *func_0200E0B0(void *saveControl);
extern u32 func_02012138(const struct GameSystem *gameSystem);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData);
extern u8 func_021673C4(u8 *saveData);
extern u8 func_021673A8(u8 *saveData);
extern int func_02158344(int comm);
extern u8 *INTRUDE_COMM_GetPartnerRecord(u8 *link);
extern int func_02012FB0(u8 *gameData);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u16 func_0216749C(SymbolMapEntry *entries, SymbolMapEntry *out, u32 capacity, int page, u8 *count);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern struct GameTask *func_020122C0(void *parent, void *reserved, void *mainFunc, u32 workSize);
extern void *func_020124E8(struct GameTask *task);
extern void func_02161CDC(void *work, void *gameSystem, u8 startFlag, u8 param);
extern int func_020307B0();
extern void func_02012444(struct GameTask *task, u32 overlayId, u32 procTable, u32 param);
extern void *func_0215A5F4(void *work);
extern void *func_0215A5DC(void *work);
extern u8 *func_02012ED0(struct GameData *gameData);
extern u16 func_02159B10(void *vm, void *work);
extern u16 func_02011330(struct ScriptVm *vm);
extern u16 *func_02159AE8(void *vm, void *work);
extern u32 func_021C87A0(void *eventState, u32 index);
extern u32 func_021C87AC(void *eventState, u32 index);
extern u32 func_021C87B8(void *eventState, u32 index, u32 index2);
extern u32 func_021C87C8(void *eventState, u32 index);
extern void func_0215897C(void *scriptSystem, void *task);
extern struct SymbolMapSave *func_02009470(void *saveControl);
extern u32 func_02009794(const struct SymbolMapSave *save, u32 index);
extern u8 func_020095C8(const struct SymbolMapSave *save);
extern struct SymbolMapSaveEntry *func_0200973C(struct SymbolMapSave *save, int index);
extern u8 func_0200856C(const struct SymbolMapSaveEntry *entry);
extern SaveSyncBlock *func_02012F38(struct GameData *gameData);
extern void func_0207AD58(void *dst, int scaleX, int scaleY);
extern void func_0207D59C(void *reg, void *matrix, int centerX, int centerY, int unusedA, int unusedB);
extern int func_02005654(int callback, int param);
extern void func_0207AD40(void *matrix);
extern void func_0200566C(void);
extern u32   func_02017E1C(void *poke, u32 key, u32 extra);
extern int FIELD_STATUS_CreateFieldCloseEvent(int gameSystem, int transitionArg);
extern void func_02012374(struct GameTask *task, struct GameEvent **event);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procTable, void *param);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSystem);
extern int func_021BE8D4(void *gameSystem, int transitionArg, int sel, int d);
extern int func_021BE92C(void *gameSystem, int transitionArg, int sel, int d, int e, u8 f, u8 g);
extern void  func_0216559C(u16 species);
extern u32 func_02013E40(u32 zoneId);
extern SpecialLocation *func_02012894(void *gameData);
extern u32 func_0201296C(const struct GameData *gameData);
extern void *func_02012F08(void *gameData);
extern u8 *func_02012944(void *gameData);
extern u8 func_02009590(void *save, u32 b, u32 c);
extern u32 func_020142E8(void *eventWork, s32 flagId);
extern int func_0216BF9C(void *miscSave, int keyId, void *myStatus);
extern void *func_0215A5E4(void *work);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *PMSI_PARAM_Create(u32 mode, u32 a1, void *src, u32 flag, void *saveControl, u32 hh);
extern void *func_0200E6F0(u32 saveControl);
extern void func_0200E6FC(void *table, int index, void *dst);
extern void PMSI_PARAM_SetSentence(u16 *pmsParam, const u16 *sentence);
extern int PMSI_PARAM_CheckCanceled(unsigned char *pmsParam);
extern void  PMSI_PARAM_GetWords(void *pmsParam, PmsInputWords *out);
extern unsigned int PMSI_PARAM_GetWord(unsigned short *pmsParam);
extern void PMSI_PARAM_GetSentence(char *pmsParam, void *out);
extern void *func_020124E4(struct GameTask *task);
extern void func_0200E714(void *table, int index, void *src);
extern void  PMSI_PARAM_Delete(void *pmsParam);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern u32 func_02188C6C(u8 *fieldMap);
extern u16 func_02188C9C(u8 *fieldMap);
extern u8 func_0202C794(void *gameSystem, u32 a1);
extern void func_021A1BE4(int a, int b);
extern void func_021A1BDC(int a, int b);
extern void GAME_DATA_SetSubscreenMode(struct GameData *gameData, u8 mode);
extern int func_0219077C(struct InfoWindow *window);
extern u32 func_020362DC(void);
extern void func_02082BCC(void *dst, int value, int size);
extern u16 func_02188C84(void *fieldMap);
extern u32 func_02188C54(void *fieldMap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02045C04();
extern struct InfoWindow *func_02190708(void *fx, struct MsgBank *msgBank, u16 x, u16 y, u16 width, u16 height);
extern int func_02190728();
extern struct WordSet *func_0201EC64(u32 heapId);
extern int func_0201ED04();
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, void *myStatus);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *wordSet, void *dst, void *src);
extern void func_0201F31C(struct WordSet *wordSet);
extern int func_02190758(struct InfoWindow *window, u32 b, u32 c, u32 text);
extern u32 func_021907C0(struct InfoWindow *window);
extern u8 func_02045730(void *bmpWin);
extern void func_020409B4(u32 index);
extern void func_02045808(struct StrBuf *buf);
extern int func_02190788();
extern void *GAME_DATA_GetSaveControlWork(struct GameData *gameData);
extern void *func_0200C0E8(void *saveControlWork);
extern u8 func_0200C224(struct ReportBlock *block);
extern u32 func_0200C1DC(struct ReportBlock *block);
extern u32 func_0200C1C4(struct ReportBlock *block);
u8 func_0216630C();
int func_02166324(u8 *grid, int id);
int func_021663F4();
int func_02166434(void *gameSystem, u32 *outSymbolIndex, u32 *outSymbolGroup);
u8 *func_0216649C(void *gameSystem);
SymbolMapLinkRecord *func_021664CC(u16 heapId, void *gameSystem, u32 *outStart);
int func_021665D0(void *gameSystem, int cellId);
int func_021665F0(void *gameSystem, int cellId, int dir);
int func_02166618(int cellId);
int func_0216662C(int cellId);
int func_02166640(int cellId);
u32 func_02166658(void *entries, u32 index);
void *func_0216666C(void *gameSystem, void *progress, void *outCompleted);
void func_021666A4(SymbolMapOwner *owner);
int func_021666B8(void *task, u32 *state);
int func_0216670C(void *progress);
void func_02166714(SymbolMapProgress *progress, int value);
int func_02166734(void *vm, void *work);
int func_021667E0(void *vm, void *work);
int func_02166824(SaveSyncBlock *block, unsigned index);
int func_02166834(SaveSyncBlock *block, int sel);
void *func_02166854(void *gameSystem, int mode, u32 outKind, u32 outValue, u32 outPicked);
int func_02166908(void *task, int *state);
int func_02166980(void *vm, void *work);
int func_021669C0(void *vm, void *work);
int func_02166A00(void *vm, void *work);
void func_02166A6C(void);
void func_02166B0C(void);
void func_02166B2C(void);
u32 func_02166B58(void *task, u32 *state, PokeEventWork *work);
void *func_02166C4C(void *gameSystem, void *transitionArg, void *poke);
u32 func_02166C7C(void *gameData, u32 zoneId);
int func_02166CD0(void *gameData, u32 flagId);
int func_02166D30(void *vm, void *work);
u32 func_02166E50(void *task, u32 *state);
int func_02166F1C(void *vm, void *work);
int func_02166F9C(void *task, int *state, ResearchTopTaskWork *work);
void *func_02167044(void *gameSystem, void *transitionArg);
int func_02167080(void *task, int *state, ResearchReportWork *work, int extra);
void *func_021670F8(void *gameSystem);
void func_0216711C(ResearchReportWork *work, void *gameSystem);
struct MsgBank *func_02167154(ResearchReportWork *work, int stateRef, ResearchReportWork *workCopy, int extra);
int func_02167168(ResearchReportWork *work);
void func_02167178(ResearchReportWork *work);
int func_021671CC(ResearchReportWork *work);
struct WordSet *func_021671DC(ResearchReportWork *work);
int func_021671EC(ResearchReportWork *work);
void func_021671FC(ResearchReportWork *work);
void func_021672B4(ResearchReportWork *work);
int func_021672D0(ResearchReportWork *work);
int func_021672E4(ResearchReportWork *work);
int func_021672F8(ResearchReportWork *work);
int func_0216730C(unsigned int kind);
extern u8 *d_02171EF4[];
extern const char d_021729EC[];
extern u8 ov203_id[];
extern u8 d_021BFB3C[];
extern char ov_id_DA[];
extern char d_021BAB5C[];
extern float d_02172BA4[2];
extern float d_021729FC;
extern char ov215_id[];
extern char d_021F7118[];
extern ZoneRemapEntry d_02171F2C[2];
extern char ov110_id[];
extern char d_021C39B8[];
extern char ov_id_D9[];
extern char d_021C3FE0[];
extern const char d_02172A00[];


/*
 * Finds the position of a cell id in a 30-entry grid (three columns). The
 * result defaults to 1 when the id is absent.
 */
u8 func_0216630C(grid, id)
u8 *grid;
int id;
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (id == grid[i])
            return (u8)i;
    }
    return 1;
}

/*
 * Picks the tile of a cell from the grid: id 1 and id 5 have their own
 * tiles, the others depend on the left, right, upper and lower neighbours.
 */
int func_02166324(u8 *grid, int id)
{
    int pos = func_0216630C(grid, id);
    int left = 0;
    int col = pos % 3;
    int right;
    int up;
    int down;

    if (col != 0 && pos != 1) {
        left = 1;
    }
    right = 0;
    if (col != 2 && pos != 1) {
        right = 1;
    }
    up = 0;
    if (pos - 3 >= 0 && grid[pos - 3] != 0) {
        up = 1;
    }
    down = 0;
    if (pos + 3 < 30 && grid[pos + 3] != 0) {
        down = 1;
    }

    if (id == 1) {
        return 0x119;
    }
    if (id == 5) {
        return 0x118;
    }
    if (left && right) {
        return 0x11D;
    }
    if (left && !right) {
        if (up && down) {
            return 0x11E;
        }
        if (up) {
            return 0x120;
        }
        if (down) {
            return 0x11B;
        }
    }
    if (!left && right) {
        if (up && down) {
            return 0x11C;
        }
        if (up) {
            return 0x11F;
        }
        if (down) {
            return 0x11A;
        }
    }
    return 0x119;
}

/*
 * Finds the position of a cell id in a grid (func_0216630C) and returns the
 * cell a step away from it: 0 = three back, 1 = three on, 2 = one back,
 * 3 = one on; any other direction returns the cell id itself.
 */
int func_021663F4(grid, cellId, dir, extra)
u8 *grid;
int cellId;
unsigned dir;
int extra;
{
    int pos = func_0216630C((u8 *)grid, cellId, dir, extra);

    switch (dir) {
    case 0:
        return grid[pos - 3];
    case 1:
        return grid[pos + 3];
    case 2:
        return grid[pos - 1];
    case 3:
        return grid[pos + 1];
    }
    return cellId;
}

/*
 * Reads the symbol index and group of the current selection (two 4-bit
 * fields of the link record) into the out parameters, or takes them from
 * the two ov010 save accessors when the exchange state is 4.
 */
int func_02166434(void *gameSystem, u32 *outSymbolIndex, u32 *outSymbolGroup)
{
    void *gameData;
    u8 *saveData;
    void *comm;
    SymbolMapLinkRecord *record;

    gameData = func_020120F4(gameSystem);
    saveData = func_0200E0B0(func_02012EBC(gameData));
    comm = (void *)func_02012138(gameSystem);
    if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4) {
        *outSymbolIndex = func_021673C4(saveData);
        *outSymbolGroup = func_021673A8(saveData);
        return 1;
    }
    comm = (void *)func_02158344((int)comm);
    if (comm == 0) {
        *outSymbolIndex = 0;
        *outSymbolGroup = 0;
        return 0;
    }
    record = (SymbolMapLinkRecord *)INTRUDE_COMM_GetPartnerRecord(comm);
    *outSymbolIndex = record->symbolIndex;
    *outSymbolGroup = record->symbolGroup;
    return 1;
}

/*
 * Returns the grid of the current selection from the table of 7 symbols
 * per group, or 0 when there is no selection. A zero case with a default
 * continuation keeps the failure exit first.
 */
u8 *func_0216649C(void *gameSystem) {
    u32 symbolIndex;
    u32 symbolGroup;
    switch (func_02166434(gameSystem, &symbolIndex, &symbolGroup)) {
    case 0: return 0;
    default: break;
    }
    return d_02171EF4[symbolIndex + symbolGroup * 7u];
}

/*
 * Builds the 0x54-byte record sent over the link: locally from the
 * selected list page plus three packed status fields (with the page
 * start written to *outStart), or as a copy of the partner's record when
 * the exchange is not in state 4 (*outStart = 530).
 *
 * recoup 2026-10-05 (lane Y5): EXACT in c99 and c. The older draft was DIFF10/260: the
 * fifth argument store of the second allocation sat after the argument copies. Fix: the
 * heap id is u16 in this function and in the allocator prototype (both sides, as in the
 * ov010 and SDK callers that declare u16 heap). Plain literals 0x1DC and 530 already
 * derive 530 from the held 0x1DC; a constant local did not change the schedule.
 * Twin search: grep -rl -E "func_0216749C|func_021673C4|func_021673A8" src/matched src/pending
 * (hits ov010 02166434, 021673C4, 021673A8, 0216749C, ov011 02174D5C); ov010 02166434 has
 * the same front half and was the shape source. Callees return real types: INTRUDE_COMM_GetPartnerSlot u8,
 * func_02012FB0 int, func_0216749C u16, func_021673C4/A8 u8, func_02030734 void *.
 */
SymbolMapLinkRecord *func_021664CC(u16 heapId, void *gameSystem, u32 *outStart)
{
    void *gameData;
    void *saveData;
    void *comm;
    void *partnerLink;
    SymbolMapLinkRecord *record;
    u32 page;
    u8 count;

    gameData = func_020120F4(gameSystem);
    saveData = func_0200E0B0(func_02012EBC(gameData));
    comm = (void *)func_02012138(gameSystem);
    if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4) {
        page = func_02012FB0(gameData);
        record = func_02030734(heapId, sizeof(SymbolMapLinkRecord), 1, d_021729EC, 0x1C9);
        *outStart = func_0216749C(saveData, record->entries, 20, page, &count);
        record->entryCount = count;
        record->symbolIndex = func_021673C4(saveData);
        record->symbolGroup = func_021673A8(saveData);
        record->state = 4;
        record->page = page;
        return record;
    }
    partnerLink = (void *)func_02158344((int)comm);
    if (partnerLink == 0)
        return 0;
    record = func_02030734(heapId, sizeof(SymbolMapLinkRecord), 1, d_021729EC, 0x1DC);
    MI_CpuCopy8(INTRUDE_COMM_GetPartnerRecord(partnerLink), record, sizeof(SymbolMapLinkRecord));
    *outStart = 530;
    return record;
}

/* Tile of a cell of the current selection's grid (0x118 when there is no grid). */
int func_021665D0(void *gameSystem, int cellId)
{
    u8 *grid = func_0216649C(gameSystem);

    if (grid != 0)
        return func_02166324(grid, (u8)(cellId + 1));
    return 0x118;
}

/* Neighbour of a cell in a direction, as a 0-based id (4 when there is no grid). */
int func_021665F0(void *gameSystem, int cellId, int dir)
{
    u8 *grid = func_0216649C(gameSystem);

    if (grid != 0)
        return (u8)func_021663F4(grid, (u8)(cellId + 1), (u8)dir) - 1;
    return 4;
}

/*
 * Unlabelled leaf: true when the argument plus one, truncated to a byte,
 * is 1 (the home cell).
 */
int func_02166618(int cellId)
{
    if ((u8)(cellId + 1) == 1)
        return 1;
    return 0;
}

/* True when the cell id plus one, truncated to a byte, is 5 (the blank cell). */
int func_0216662C(int cellId)
{
    if ((u8)(cellId + 1) == 5)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C37C): true when the
 * argument plus one, truncated to a byte, is 2, 3 or 4 (a plain cell).
 * Twin of func_02166618.
 */
int func_02166640(int cellId)
{
    u8 internalId = cellId + 1;

    if ((u8)(internalId + 0xFE) <= 2)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf (no lr save) called from func_02166734 case 4; 18 bytes
 * plus 2 bytes of alignment padding before func_0216666C. Reads the u32 at
 * +0x14 of a 0x1C-byte entry, or 10 when there is no table.
 */
u32 func_02166658(void *entries, u32 index)
{
    if (entries == 0)
        return 10;
    return ((EventStateEntry *)entries)[index].value;
}

/*
 * Creates the ov203 record task: it links a comm proc, remembers the
 * progress record and the completion flag, and copies the last result.
 */
void *func_0216666C(void *gameSystem, void *progress, void *outCompleted) {
    struct GameTask *task;
    SymbolMapRecordWork *work;
    task = func_020122C0(gameSystem, 0, func_021666B8, 32);
    work = func_020124E8(task);
    work->progress = progress;
    work->outCompleted = outCompleted;
    func_02161CDC(work, gameSystem, 1, 0);
    work->lastResult = func_0216670C(progress);
    return task;
}

void func_021666A4(SymbolMapOwner *owner)
{
    if (owner->linkRecord != 0) {
        func_020307B0(owner->linkRecord);
        owner->linkRecord = 0;
    }
}

/* Task main of func_0216666C: runs ov203, then stores its result and the completion flag. */
int func_021666B8(void *task, u32 *state)
{
    SymbolMapRecordWork *work = func_020124E8(task);
    switch (*state) {
    case 0:
        func_02012444(task, (u32)ov203_id, (u32)d_021BFB3C, (u32)work);
        *state = *state + 1;
        break;
    case 1:
        if (work->resultCode == 2) *work->outCompleted = 1;
        else *work->outCompleted = 0;
        func_02166714(work->progress, work->measuredValue);
        return 1;
    }
    return 0;
}

/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216670C.c \
 *       --func func_0216670C --addr 0x0216670C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216670C(void *progress) { return ((SymbolMapProgress *)progress)->lastResult; }

/* Stores a result and raises the best rank when the result / 1350 beats it. */
void func_02166714(SymbolMapProgress *progress, int value) {
    int rank;
    progress->lastResult = value;
    rank = progress->lastResult / 1350;
    if (progress->bestRank <= rank) progress->bestRank = rank;
}

/*
 * Script command: queries the event state by sub-command (4..8, the
 * others answer 0) and writes the answer to a script variable.
 *
 * The five unlabelled leaf callees are filed as their own shards
 * (matched witnesses): ov010_func_02166658.c, ov021_func_021C87A0.c,
 * ov021_func_021C87AC.c, ov021_func_021C87B8.c, ov021_func_021C87C8.c.
 * (ov128_func_021C87A0.c is a different overlay's function at that
 * address; ov010 runs with ov021 loaded.)
 * lever (wave 82 R8): each arm writes the store `*(u16 *)a = ...` out
 *   itself, case 8 included (`if (...) *a = 1; else *a = 0;`). Cross-jumping
 *   then leaves cases 5-8 branching onto case 4's `b` and case 8's else as a
 *   dead `b` onto default. A shared `v` stored after the switch is 170 B
 *   (36 bytes out); with case 8's `else v = 0;` it is 172 B but DIFF21
 *   (a/p colours swapped, direct branches). An inline switch helper is the
 *   same DIFF21.
 */
int func_02166734(void *vm, void *work)
{
    u8 *eventState;
    u32 index;
    u16 subCommand;
    u32 index2;
    u16 *out;

    func_0215A5F4(work);
    eventState = func_02012ED0(func_020120F4(func_0215A5DC(work)));
    index = func_02159B10(vm, work);
    subCommand = func_02011330(vm);
    index2 = func_02159B10(vm, work);
    out = func_02159AE8(vm, work);
    switch (subCommand) {
    case 4:
        *out = func_02166658(*(void **)eventState, index);
        break;
    case 5:
        *out = func_021C87A0(*(void **)eventState, index);
        break;
    case 6:
        *out = func_021C87AC(*(void **)eventState, index);
        break;
    case 7:
        *out = func_021C87B8(*(void **)eventState, index, index2);
        break;
    case 8:
        if (func_021C87C8(*(void **)eventState, index) != 0)
            *out = 1;
        else
            *out = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    default:
        *out = 0;
        break;
    }
    return 0;
}

/*
 * Script command: starts the ov203 record task for the progress record in
 * the event state. The returned task remains live as func_0215897C's second
 * argument.
 */
int func_021667E0(void *vm, void *work)
{
    void *scriptSystem = func_0215A5F4(work);
    void *gameSystem = func_0215A5DC(work);
    void **eventState;
    void *task;
    eventState = (void **)func_02012ED0(func_020120F4(gameSystem));
    task = func_0216666C(gameSystem, *eventState, func_02159AE8(vm, work));
    if (task == 0)
        return 1;
    func_0215897C(scriptSystem, task);
    return 1;
}

/* Reads item `index` of the save sync block, or 0xB when out of range. */
int func_02166824(SaveSyncBlock *block, unsigned index)
{
    if (index >= block->count)
        return 0xb;
    return block->items[index];
}

/* Reads a header byte of the save sync block: 0 = count, 1 = type, 2 = variant. */
int func_02166834(SaveSyncBlock *block, int sel)
{
    switch (sel) {
    case 0:
        return block->count;
    case 1:
        return block->type;
    case 2:
        return block->variant;
    }
    return 0;
}

/*
 * Creates the ov218 picker task: it copies the mode and the three output
 * pointers, then fills a 232-entry owned-flag table (+0x30) and a 20-entry
 * halfword table (+0x08) from the save object, zero padding the halfwords.
 */
void *func_02166854(void *gameSystem, int mode, u32 outKind, u32 outValue, u32 outPicked)
{
    struct GameTask *task;
    SymbolMapPickerWork *work;
    struct SymbolMapSave *save;
    int i;
    int count;
    int flagIndex;

    task = func_020122C0(gameSystem, 0, func_02166908, 0x128);
    work = func_020124E8(task);
    work->mode = mode;
    work->outPicked = (u16 *)outPicked;
    work->outKind = (u16 *)outKind;
    work->outValue = (u16 *)outValue;
    save = func_02009470(func_02012EBC(func_020120F4(gameSystem)));
    for (i = 1; i < 0xE9; i++) {
        flagIndex = i - 1;
        if (func_02009794(save, i))
            work->ownedFlags[flagIndex] = 1;
        else
            work->ownedFlags[flagIndex] = 0;
    }
    count = func_020095C8(save);
    if (count > 20)
        count = 20;
    for (i = 0; i < count; i++)
        work->candidateIds[i] = func_0200856C(func_0200973C(save, i));
    for (; i < 20; i++)
        work->candidateIds[i] = 0;
    return task;
}

/*
 * Former blocker: ABS32 for 0x000000DA (overlay id 218) and 0x021BAB5C (its callback table) have no
 * witness outside this function; func_02012444 is not a listed overlay-id consumer and the
 * word is referenced only from this pool. Every concrete byte matches.
 *
 * 2026-10-05 (D8 lane 15): the callback table d_021BAB5C lives in ov218 (loaded by this function); the data line now carries the ov218 token and the relocation resolves.
 */
int func_02166908(void *task, int *state)
{
    SymbolMapPickerWork *work = func_020124E8(task);
    switch (*state) {
    case 0:
        func_02012444(task, (u32)ov_id_DA, (u32)d_021BAB5C, (u32)work);
        *state = *state + 1;
        break;
    case 1:
        if (work->resultCode == 1) {
            *work->outPicked = 1;
            *work->outKind = work->resultKind;
            *work->outValue = work->resultValue;
        } else {
            *work->outPicked = 0;
            *work->outKind = 0;
            *work->outValue = 0;
        }
        return 1;
    }
    return 0;
}

/*
 * Script command: reads item `index` (u8-truncated sub-command) of the save
 * sync block into a script variable.
 */
int func_02166980(void *vm, void *work)
{
    SaveSyncBlock *block;
    int index;
    void *gameData;
    u16 *out;

    func_0215A5F4(work);
    gameData = func_0215A5DC(work);
    gameData = func_020120F4(gameData);
    block = func_02012F38(gameData);
    index = (u8)func_02011330(vm);
    out = func_02159AE8(vm, work);
    *out = func_02166824(block, index);
    return 0;
}

/* Script command: reads a header byte of the save sync block into a script variable. */
int func_021669C0(void *vm, void *work)
{
    void *gameData;
    u16 *out;
    int sel;
    SaveSyncBlock *block;

    func_0215A5F4(work);
    gameData = func_0215A5DC(work);
    gameData = func_020120F4(gameData);
    block = func_02012F38(gameData);
    sel = func_02159B10(vm, work);
    out = func_02159AE8(vm, work);
    *out = func_02166834(block, sel);
    return 0;
}

/*
 * Script command: starts the ov218 picker task (mode and three output
 * variables from the script).
 */
int func_02166A00(void *vm, void *work)
{
    void *scriptSystem = func_0215A5F4(work);
    void *gameSystem = func_0215A5DC(work);
    int mode;
    unsigned short *outKind;
    unsigned short *outValue;
    unsigned short *outPicked;
    int task;
    func_02012F38(func_020120F4(gameSystem));
    mode = func_02159B10(vm, work);
    outKind = func_02159AE8(vm, work);
    outValue = func_02159AE8(vm, work);
    outPicked = func_02159AE8(vm, work);
    task = (int)func_02166854(gameSystem, mode, (u32)outKind, (u32)outValue, (u32)outPicked);
    if (task == 0)
        return 1;
    func_0215897C(scriptSystem, (void *)task);
    return 1;
}

/* Per-frame callback: during VBlank, grows the BG2 scale and rewrites the BG2 matrix. */
void func_02166A6C(void)
{
    int fixedScale;
    int matrix[4];
    float scale;
    float rounded;
    float zero = 0.0f;
    if (*(volatile u16 *)0x04000004 & 1) {
        scale = d_02172BA4[0] + d_021729FC;
        d_02172BA4[0] = scale;
        if (1.0f / scale > zero)
            rounded = 4096.0f * (1.0f / scale) + 0.5f;
        else
            rounded = 4096.0f * (1.0f / scale) - 0.5f;
        fixedScale = (int)rounded;
        func_0207AD58(matrix, fixedScale, fixedScale);
        func_0207D59C((void *)0x04000020, matrix, 0x80, 0x5c, 0, 0);
    }
}

/*
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum (scale
 * 1.0, unused 0), then tail-calls func_02005654(func_02166A6C, 0).
 */
void func_02166B0C(void)
{
    d_02172BA4[0] = 1.0f;
    d_02172BA4[1] = 0.0f;
    func_02005654((int)func_02166A6C, 0);
}

/* Resets the BG2 matrix to identity and stops the per-frame callback. */
void func_02166B2C(void) {
    int matrix[4];
    func_0207AD40(matrix);
    func_0207D59C((void *)0x04000020, matrix, 128, 92, 0, 0);
    func_0200566C();
}

/*
 * Stage machine on *state, same family as ov002 func_021542C0.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0xD7 (215), a linker overlay id for
 * ov215; the third, 0x021F7118, lies in its window. Skips straight to the
 * end unless the Pokemon is an egg that is not flagged invalid.
 */
u32 func_02166B58(void *task, u32 *state, PokeEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = work->gameData;
    u32 transitionArg = work->transitionArg;

    switch (*state) {
    case 0:
        if (func_02017E1C(work->poke, 0x4C, 0) == 0 || func_02017E1C(work->poke, 3, 0) == 1) {
            *state = 7;
        } else {
            *state = 1;
        }
        break;
    case 1:
        work->procParam.gameData = gameData;
        work->procParam.poke = work->poke;
        *state = 2;
        break;
    case 2:
        func_02012374(task, (struct GameEvent **)func_021BE8D4(gameSystem, transitionArg, 0, 0));
        *state = 3;
        break;
    case 3:
        func_02012374(task, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, transitionArg));
        *state = 4;
        break;
    case 4:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov215_id, d_021F7118, &work->procParam);
        *state = 5;
        break;
    case 5:
        func_02012374(task, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *state = 6;
        break;
    case 6:
        func_02012374(task, (struct GameEvent **)func_021BE92C(gameSystem, transitionArg, 0, 0, 1, 0, 0));
        func_0216559C(func_02017E1C(work->poke, 5, 0));
        *state = 7;
        break;
    case 7:
        return 1;
    }
    return 0;
}

/* Creates the ov215 task (see func_02166B58). */
void *func_02166C4C(void *gameSystem, void *transitionArg, void *poke) {
    struct GameTask *task;
    PokeEventWork *work;
    task = func_020122C0(gameSystem, 0, func_02166B58, 24);
    work = func_020124E8(task);
    work->gameSystem = gameSystem;
    work->transitionArg = (u32)transitionArg;
    work->gameData = func_020120F4(gameSystem);
    work->poke = poke;
    return task;
}

/*
 * Maps a zone id to the zone it is shown as: the special location's zone
 * for zone 0x1A6, a table entry when the zone has one, else the zone
 * parent itself.
 *
 * stand-in: the goto and the word load plus u16 truncation of the table
 * entry are the only forms that give the original bytes; a break loop or
 * a halfword field access changes them.
 */
u32 func_02166C7C(void *gameData, u32 zoneId)
{
    u32 parentZone = func_02013E40(zoneId);
    u32 remapped;
    int i;
    if (parentZone == 0x1A6)
        return func_02013E40(func_02012894(gameData)->zoneId);
    for (i = 0; i < 2; i++) {
        if (d_02171F2C[i].source == parentZone) {
            remapped = (u16)*(u32 *)((char *)d_02171F2C + i * 8);
            goto done;
        }
    }
    remapped = 0xFFFF;
done:
    if (remapped != 0xFFFF)
        parentZone = (u16)remapped;
    return parentZone;
}

/*
 * Checks an event flag; 0xF000 asks whether the beacon trainer key is set
 * and 0xF001 whether the save object holds an entry, every other id is a
 * plain zone event flag.
 */
int func_02166CD0(void *gameData, u32 flagId)
{
    void *eventWork = (void *)func_0201296C(gameData);
    void *miscSave = func_02012F08(gameData);
    void *myStatus = func_02012944(gameData);
    void *save;
    int result;
    save = func_02009470(func_02012EBC(gameData));
    switch (flagId) {
    case 0xF000:
        return func_0216BF9C(miscSave, 1, myStatus);
    case 0xF001:
        result = 0;
        if (func_02009590(save, (u32)myStatus, 0) >= 1)
            result = 1;
        return result;
    }
    return func_020142E8(eventWork, flagId);
}

/*
 * Script command: reads a kind and three variable pointers, starts the
 * func_02166E50 task over a 0x1C-byte work, and for kinds 0..5 opens the
 * matching PMS input (PMSI_PARAM_Create), optionally filled with a sentence.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): byte-correct; the one
 * wildcard is the bl to arm9 0x02024108, a Thumb function (`ldrh r2, [r1]`
 * ...) with no witness outside this file (seed for the ARM9 session).
 */
int func_02166D30(void *vm, void *work)
{
    u8 sentenceBuf[8];
    u16 *outResult;
    u16 *outWord1;
    u16 *outWord0;
    void *gameSystem;
    void *gameData;
    void *scriptSystem;
    PmsInputWork *inputWork;
    struct GameTask *task;
    u16 kind;
    u32 mode;

    gameSystem = func_0215A5DC(work);
    gameData = func_0215A5E4(work);
    scriptSystem = func_0215A5F4(work);
    kind = func_02159B10(vm, work);
    outWord0 = func_02159AE8(vm, work);
    outWord1 = func_02159AE8(vm, work);
    outResult = func_02159AE8(vm, work);
    mode = 0;
    task = func_020122C0(gameSystem, 0, func_02166E50, sizeof(PmsInputWork));
    inputWork = func_020124E8(task);
    MI_CpuFill8(inputWork, 0, sizeof(PmsInputWork));
    inputWork->kind = kind;
    inputWork->outWord0 = outWord0;
    inputWork->outWord1 = outWord1;
    inputWork->outResult = outResult;
    *outResult = 0;
    switch (kind) {
    case 0:
        inputWork->sentenceId = 1;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 1:
        inputWork->sentenceId = 2;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 2:
        inputWork->sentenceId = 3;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 3:
        inputWork->sentenceId = 4;
        inputWork->hasSentence = 1;
        mode = 2;
        break;
    case 4:
        inputWork->hasSentence = 0;
        break;
    case 5:
        inputWork->hasSentence = 0;
        mode = 1;
        break;
    default:
        inputWork->pmsParam = 0;
        func_0215897C(scriptSystem, task);
        return 1;
    }
    inputWork->pmsParam = PMSI_PARAM_Create(mode, 0, 0, 0, func_02012EBC(gameData), 1);
    if (inputWork->hasSentence) {
        func_0200E6FC(func_0200E6F0((u32)func_02012EBC(func_020120F4(gameSystem))), inputWork->sentenceId, sentenceBuf);
        PMSI_PARAM_SetSentence(inputWork->pmsParam, (const u16 *)sentenceBuf);
    }
    func_0215897C(scriptSystem, task);
    return 1;
}

/*
 * Two-stage task: stage 0 starts an ov110 sub-task (pooled 0x6E is the
 * overlay id, 0x021C39B8 a table in its window) on the PMS parameter at +0x10;
 * stage 1 reads back its result by the kind at +0x00 into the u16 outputs
 * at +0x04/+0x08 and flags +0x0C, then frees the parameter.
 *
 * Byte-correct (lane B5, run 1).  7 of 14 sites unresolved, no C change helps:
 *   - ov110_id 0x6E: overlay_id refuses, func_02012444 is not in
 *     OVERLAY_ID_CONSUMERS (it stores a1 in a descriptor for the state
 *     machine GAME_EVENT_CallProcSeq rather than passing it straight to a loader).
 *   - d_021C39B8: with the ov110 token the hint is "contested" and no
 *     overlay_id site loads ov110; without it, "no witness".  Resolves once
 *     ov110_id does.
 *   - arm9 unlabelled leaves 0x0202411C, 0x02024124, 0x02024128,
 *     0x02024134 (a .word run in asm/arm9/main.s after PMSI_PARAM_Delete) and
 *     0x0200E714: no witness outside this range; each needs its own EXACT
 *     arm9 entry (matched class).
 * Same blocker family as ov010_func_02166908 / ov010_func_0216B004.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
u32 func_02166E50(void *task, u32 *state)
{
    PmsInputWork *work = func_020124E8(task);
    void *pmsParam = work->pmsParam;
    PmsInputWords words;
    PmsInputSentence sentence;
    u16 second;
    u16 result;

    switch (*state) {
    case 0:
        if (pmsParam == 0) {
            return 1;
        }
        func_02012444(task, (u32)ov110_id, (u32)d_021C39B8, (u32)pmsParam);
        (*state)++;
        break;
    case 1:
        if (PMSI_PARAM_CheckCanceled(pmsParam) != 0) {
            result = 0;
        } else {
            if (work->kind == 5) {
                PMSI_PARAM_GetWords(pmsParam, &words);
                *work->outWord0 = words.first;
                second = words.second;
            } else if (work->kind == 4) {
                *work->outWord0 = PMSI_PARAM_GetWord(pmsParam);
                second = 0;
            } else {
                PMSI_PARAM_GetSentence(pmsParam, &sentence);
                if (work->hasSentence != 0) {
                    func_0200E714(func_0200E6F0((u32)func_02012EBC(func_020120F4(func_020124E4(task)))), work->sentenceId, (&sentence));
                }
                *work->outWord0 = sentence.first;
                second = sentence.second;
            }
            *work->outWord1 = second;
            result = 1;
        }
        *work->outResult = result;
        PMSI_PARAM_Delete(work->pmsParam);
        return 1;
    }
    return 0;
}

/*
 * Script command: reads a sub-screen id (0xFFFF = default) and an enable
 * flag, calls one of two field map functions and sets the sub-screen mode.
 */
int func_02166F1C(void *vm, void *work)
{
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    int fieldState;
    int modeId;
    int enable;
    func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    gameData = func_0215A5E4(work);
    fieldMap = func_0201210C(gameSystem);
    fieldState = func_02188C6C(fieldMap);
    modeId = func_02159B10(vm, work);
    enable = func_02159B10(vm, work);
    if (modeId == 0xFFFF)
        modeId = func_0202C794(gameSystem, func_02188C9C(fieldMap));
    if (enable != 0)
        func_021A1BE4(fieldState, modeId);
    else
        func_021A1BDC(fieldState, modeId);
    GAME_DATA_SetSubscreenMode(gameData, modeId & 0xff);
    return 0;
}

/*
 * Task main of func_02167044: closes the field, runs ov217 (pooled 0xD9)
 * on the heap block, opens the field and frees the block.
 */
int func_02166F9C(void *task, int *state, ResearchTopTaskWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    int transitionArg = work->transitionArg;
    switch (*state) {
    case 0:
        func_02012374(task, (struct GameEvent **)func_021BE8D4(gameSystem, transitionArg, 0, 0));
        *state = 1;
        break;
    case 1:
        func_02012374(task, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, transitionArg));
        *state = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov_id_D9, d_021C3FE0, work->param);
        *state = 3;
        break;
    case 3:
        func_02012374(task, (struct GameEvent **)((int)FIELD_STATUS_CreateFieldOpenEvent(gameSystem)));
        *state = 4;
        break;
    case 4:
        func_02012374(task, (struct GameEvent **)func_021BE92C(gameSystem, transitionArg, 0, 0, 1, 0, 0));
        *state = 5;
        break;
    case 5:
        func_020307B0(work->param);
        return 1;
    }
    return 0;
}

/* Creates the ov217 task (see func_02166F9C) with a 4-byte heap block that holds the game system. */
void *func_02167044(void *gameSystem, void *transitionArg) {
    struct GameTask *task;
    ResearchTopTaskWork *work;
    ResearchTopParam *param;
    task = func_020122C0(gameSystem, 0, func_02166F9C, 12);
    work = func_020124E8(task);
    work->gameSystem = gameSystem;
    work->transitionArg = (int)transitionArg;
    param = func_02030734(4, 4, 0, d_02172A00, 117);
    work->param = param;
    param->gameSystem = gameSystem;
    return task;
}

/*
 * Task main of the research report: builds the message window (stage 0),
 * waits for it to open (1), waits for a key press (2) and tears it all down (3).
 */
int func_02167080(void *task, int *state, ResearchReportWork *work, int extra)
{
    switch (*state) {
    case 0:
        func_02167154(work, (int)state, work, extra);
        func_02167178(work);
        func_021671DC(work);
        func_021671FC(work);
        *state = *state + 1;
        break;
    case 1:
        if (func_0219077C(work->window) == 1)
            *state = *state + 1;
        break;
    case 2:
        if (func_020362DC() & 0xf3)
            *state = *state + 1;
        break;
    case 3:
        func_021672B4(work);
        func_021671EC(work);
        func_021671CC(work);
        func_02167168(work);
        return 1;
    }
    return 0;
}

void *func_021670F8(void *gameSystem) {
    struct GameTask *task;
    task = func_020122C0(gameSystem, 0, func_02167080, 32);
    func_0216711C(func_020124E8(task), gameSystem);
    return task;
}

/*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 */
void func_0216711C(ResearchReportWork *work, void *gameSystem) {
    void *fieldMap;
    fieldMap = func_0201210C(gameSystem);
    func_02082BCC(work, 0, 32);
    work->heapId = func_02188C84(fieldMap);
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->fieldMap = fieldMap;
    work->fx = (void *)func_02188C54(fieldMap);
}

/* Loads the report message bank. */
struct MsgBank *func_02167154(ResearchReportWork *work, int stateRef, ResearchReportWork *workCopy, int extra)
{
    struct MsgBank *bank;

    bank = func_02045B38(0, 3, 0x2f, work->heapId);
    work->msgBank = bank;
    return bank;
}

int func_02167168(ResearchReportWork *work)
{
    func_02045C04(work->msgBank);
    work->msgBank = 0;
    return 0;
}

/* Opens the info window; it is 4 lines high for report kind 0 and 8 lines for the others. */
void func_02167178(ResearchReportWork *work)
{
    int x;
    int width;
    int height;
    switch (func_021672D0(work)) {
    case 0:
        x = 1;
        width = 0x1e;
        height = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        x = 1;
        width = 0x1e;
        height = 8;
        break;
    }
    work->window = func_02190708(work->fx, work->msgBank, x, x, width, height);
}

int func_021671CC(ResearchReportWork *work)
{
    func_02190728(work->window);
    work->window = 0;
    return 0;
}

struct WordSet *func_021671DC(ResearchReportWork *work)
{
    struct WordSet *wordSet;

    wordSet = func_0201EC64(work->heapId);
    work->wordSet = wordSet;
    return wordSet;
}

int func_021671EC(ResearchReportWork *work)
{
    func_0201ED04(work->wordSet);
    work->wordSet = 0;
    return 0;
}

/* Formats the report text (player name and two numbers) and prints it in the info window. */
void func_021671FC(ResearchReportWork *work)
{
    struct StrBuf *rawText;
    struct StrBuf *formattedText;
    int messageId;
    int numberA;
    int numberB;
    rawText = func_020457B0(0x100, work->heapId);
    formattedText = func_020457B0(0x100, work->heapId);
    messageId = func_021672D0(work);
    numberA = func_021672E4(work);
    numberB = func_021672F8(work);
    messageId = func_0216730C(messageId);
    func_0201F02C(work->wordSet, 0, func_02012944(work->gameData));
    func_0201EFA4(work->wordSet, 1, numberA, 5, 1, 1);
    func_0201EFA4(work->wordSet, 2, numberB, 5, 1, 1);
    func_02045CAC(work->msgBank, messageId, rawText);
    func_0201F250(work->wordSet, formattedText, rawText);
    func_0201F31C(work->wordSet);
    func_02190758(work->window, 8, 0, (u32)formattedText);
    func_020409B4(func_02045730((void *)func_021907C0(work->window)));
    func_02045808(rawText);
    func_02045808(formattedText);
}

void func_021672B4(ResearchReportWork *work)
{
    func_02190788(work->window);
    func_020409B4(func_02045730((void *)func_021907C0(work->window)));
}

/* Report kind (0..5) from the research report block. */
int func_021672D0(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = func_0200C0E8(gameDataSave);
    result = func_0200C224(block);
    return result;
}

/* First number of the research report block. */
int func_021672E4(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = func_0200C0E8(gameDataSave);
    result = func_0200C1DC(block);
    return result;
}

/* Second number of the research report block. */
int func_021672F8(ResearchReportWork *work)
{
    void *gameDataSave;
    void *block;
    int result;

    gameDataSave = GAME_DATA_GetSaveControlWork(work->gameData);
    block = func_0200C0E8(gameDataSave);
    result = func_0200C1C4(block);
    return result;
}

/* Message id of the report text for a report kind (0..5), 0 otherwise. */
int func_0216730C(unsigned int kind)
{
    switch (kind) {
    case 0:
        return 0x174;
    case 1:
        return 0x175;
    case 2:
        return 0x176;
    case 3:
        return 0x177;
    case 4:
        return 0x178;
    case 5:
        return 0x179;
    }
    return 0;
}

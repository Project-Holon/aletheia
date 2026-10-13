/*
 * file:     gimmick_obj_elboard.c
 * unit:     yes
 * function: func_021F3D38, func_021F3D78, func_021F3DA8, func_021F3DF0, func_021F3E2C, func_021F3E6C, func_021F3EE8, func_021F4058, func_021F4104, func_021F4188, func_021F420C, func_021F4290, func_021F4314, func_021F43E4, func_021F440C, func_021F4454, func_021F4488, func_021F44B8, func_021F44D8, func_021F4590, func_021F45F0, func_021F4650, func_021F4698, func_021F472C, func_021F474C, func_021F4784, func_021F47B0, func_021F47B4, func_021F47B8, func_021F47BC, func_021F4948, func_021F4B40, func_021F4B54, func_021F4B7C, func_021F4BF0, func_021F4C10, func_021F4C20, func_021F4DBC, func_021F4DE4, func_021F4DF4, func_021F4E3C
 * address:  0x021F3D38
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F3A50  0x021F3A50  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_021F3A70  0x021F3A70  thumb
 *   func_021F3D24  0x021F3D24  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02088864  0x02088864  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F230  0x0201F230  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 *   func_0201EC74  0x0201EC74  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_021F5124     0x021F5124  data  a4
 *   func_021A9810  0x021A9810  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_021F3AB4  0x021F3AB4  thumb  ov048
 *   func_021F3AD4  0x021F3AD4  thumb  ov048
 *   func_021F3B64  0x021F3B64  thumb  ov048
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021F3C2C 0x021F3C2C thumb ov048
 *   d_021F50C4     0x021F50C4  data  a2
 *   d_021F50EC     0x021F50EC  data  a4
 *   d_021F5108     0x021F5108  data  a4
 *   func_021F3CB0 0x021F3CB0 thumb ov048
 *   d_021F4E84 0x021F4E84 data a4
 *   func_02188C70  0x02188C70  thumb  ov021
 *   d_021F4E5C     0x021F4E5C  data  a2
 *   d_021F4E5E     0x021F4E5E  data  a1
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0215E404  0x0215E404  thumb  ov010
 *   func_0215E3E4  0x0215E3E4  thumb  ov010
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021F523C     0x021F523C  data  a1
 *   func_0201D83C 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02047788  0x02047788  arm
 *   G3D_SYSTEM_GetRenderTexRes  0x02047554  arm
 *   func_021875F4  0x021875F4  thumb  ov020
 *   func_02047790  0x02047790  arm
 *   func_02047674  0x02047674  arm
 *   func_02047804  0x02047804  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fgr           0x0209BBB0  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   func_02187684 0x02187684 thumb ov020
 *   func_0218768C  0x0218768C  thumb  ov020
 *   func_020478B8  0x020478B8  arm
 *   func_02048F74 0x02048F74 arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_021F3790  0x021F3790  thumb  ov048
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 */

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * (1 << 12) + 0.5f) : ((x) * (1 << 12) - 0.5f)))
#define FX_Mul(a, b) ((fx32)(((s64)(a) * (b) + 0x800LL) >> 12))

typedef long long      s64;

#include "field_gimmick_gate_types.h"

struct EventWork;
struct FieldCamera;
struct FieldTaskManager;
struct FieldTask;
struct WordSet;
struct Strbuf;
struct MsgData;
struct GfFont;
struct GameEvent;
struct ScriptContext;
struct ScrCmdWork;
struct ScriptWork;
struct EncounterState;
struct ElboardText;

typedef struct GimmickObjElboard GimmickObjElboard;

/*
 * The part of GateBoardRecord.elboardParams (0x18, 23 words) that this file
 * reads.
 */
typedef struct ElboardRecordParams {
    u32 dateMsgId;          /* 0x00: message of the date line */
    u32 unusedMsgId;        /* 0x04 */
    u32 newsMsgId;          /* 0x08 */
    u32 dayMsgId[9];        /* 0x0C: the daily lines read three consecutive entries */
    u32 weekMsgId[7];       /* 0x30: one message per weekday, Monday first */
    u32 defaultPlaceId[4];  /* 0x4C */
} ElboardRecordParams;

#define ELBOARD_RECORD_PARAMS(record) ((ElboardRecordParams *)(record)->elboardParams)

/* Date as the RTC call returns it. */
typedef struct RtcDate {
    int year;
    int month;
    int day;
    int week;
} RtcDate;

#define ELBOARD_NO_PLACE 0x1AB  /* empty place slot */

/* Up to four places the board points out, each with the kind of the place. */
typedef struct ElboardHighlights {
    u16 placeId[4];
    u8  kind[4];
} ElboardHighlights;

/*
 * Layout table of the board lanes (d_021F50C0, 0x64 bytes), shared with
 * field_gimmick_gate.c. The label message ids that follow it in the data are
 * d_021F5124. They stay out of the struct on purpose: with a struct above
 * about 0x70 bytes the compiler schedules func_021F3E6C differently.
 */
typedef struct ElboardLayout {
    fx32        scrollSpeed;        /* 0x00 */
    u16         animIndex[20];      /* 0x04: d_021F50C4, one animation per lane */
    const char *textureName[7];     /* 0x2C: d_021F50EC */
    const char *paletteName[7];     /* 0x48: d_021F5108 */
} ElboardLayout;

/* A message to put on the board: where its text is drawn and which text it is. */
typedef struct ElboardMessage {
    u16 animIndex;
    u16 pad02;
    const char *textureName;
    const char *paletteName;
    u32 arcId;
    u32 fileId;
    u32 msgId;
    struct WordSet *wordSet;    /* 0 when the message has no tags */
} ElboardMessage;

/* One scrolling line of the board (0x24 bytes). */
typedef struct ElboardLine {
    u8 lineIndex;                   /* 0x00 */
    int isPlaying;                  /* 0x04 */
    int nextStarted;                /* 0x08: the next line was told to start */
    struct ElboardText *text;       /* 0x0C */
    G3dObject *render;              /* 0x10 */
    u16 animIndex;                  /* 0x14 */
    fx32 elapsed;                   /* 0x18 */
    fx32 nextStartTime;             /* 0x1C: time at which the next line starts */
    fx32 endTime;                   /* 0x20: time at which the line has left the board */
} ElboardLine;

/* The board: a fixed set of lines that scroll one after the other (0x1C bytes). */
struct GimmickObjElboard {
    u16 heapId;                     /* 0x00 */
    u8 lineCount;                   /* 0x02 */
    u8 lineCapacity;                /* 0x03 */
    u8 leadChars;                   /* 0x04: blank characters before the text */
    u8 trailChars;                  /* 0x05: blank characters after the text */
    u8 pad06[2];
    ElboardLine **lines;            /* 0x08 */
    int *startRequest;              /* 0x0C: per line, set when the line before it ends */
    G3dObject *render;              /* 0x10 */
    struct GfFont *font;            /* 0x14 */
    fx32 scroll;                    /* 0x18 */
};

typedef struct ElboardConfig {
    u16 heapId;
    u8 lineCapacity;
    u8 leadChars;
    u8 trailChars;
    u8 pad05[3];
    G3dObject *render;
} ElboardConfig;

/* Work of the camera event (field_gimmick_gate.c script command). */
typedef struct GateCameraEventWork {
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 frames;
    u16 savedPitch;
    u16 savedYaw;
    u16 pad0E;
    u32 savedDistance;
    VecFx32 savedTarget;
} GateCameraEventWork;

extern void func_021F3A50(GateWork *work, int kind, int param);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern void func_0201433C(struct EventWork *eventWork, int flagId);
extern int func_021F3A70(GateWork *work);
extern int func_021F3D24(GateWork *work);
extern struct WordSet *func_0201EC64(u32 heapId);
extern int func_02088864(RtcDate *date);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 keta, u32 dispType, u32 codeType);
extern void func_0201F230(struct WordSet *wordSet, u32 index, u32 month);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern struct WordSet *func_0201EC74(u32 wordMax, u32 bufLen, u16 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02013E4C(u32 placeId);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const struct Strbuf *str, u32 sex, u32 singular, u32 lang);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void func_02045808(struct Strbuf *str);
extern u32 func_02045C04(struct MsgData *msgData);
extern u16 func_021A9810(struct GameData *gameData);
extern u8 func_02012984(struct GameData *gameData);
extern int func_021F3AB4(GateWork *work);
extern void func_021F3AD4(GateWork *work, u32 *outIds, int *outCount);
extern void func_021F3B64(GateWork *work, u32 *outIds, int *outCount);
extern void func_0201EE60(struct WordSet *wordSet, u32 index, u16 value);
extern void *func_02012944(struct GameData *gameData);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, void *myStatus);
extern GateNewsEntry *func_021F3C2C(GateWork *work);
extern GateNewsEntry *func_021F3CB0(GateWork *work);
extern int func_02188C70(struct FieldMap *fieldMap, int placeId);
extern void *func_02012EBC(struct GameData *gameData);
extern struct EncounterState *func_0200D418(void *saveControl);
extern int func_0215E404(struct EncounterState *state);
extern u32 GPOWER_GetSpecialPowerId(void);
extern u32 func_0215E3E4(struct EncounterState *state, u32 slot);
extern struct ScriptWork *func_0215A5F4(struct ScrCmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(struct ScrCmdWork *cmdWork);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern unsigned int func_02159B10(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork);
extern void func_020061E4(u32 seId);
extern void func_0215897C(struct ScriptWork *scriptWork, struct GameEvent *event);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern unsigned int func_0201D83C(struct GfFont *font);
extern u32 func_020307B0(void *p);
extern int func_0209C0A4(int a, int b);
extern u32 func_0204784C(G3dObject *obj, u16 animIndex, s32 *frame);
extern u32 func_020477A4(G3dObject *obj, u32 animIndex);
extern int func_020477D4(G3dObject *obj, u32 animIndex);
extern u32 func_0201D304(struct Strbuf *str, struct GfFont *font, u32 spacing);
extern G3dRender *func_02047788(G3dObject *obj);
extern G3dResource *G3D_SYSTEM_GetRenderTexRes(G3dRender *render);
extern struct ElboardText *func_021875F4(G3dResource *texRes, const char *textureName, const char *paletteName, struct Strbuf *str, u16 width, u16 flag, u16 heapId);
extern G3dAnime *func_02047790(G3dObject *obj, int animIndex);
extern NNSG3dAnmObj *func_02047674(G3dAnime *anime);
extern u32 func_02047804(G3dObject *obj, u16 animIndex);
extern void func_02187684(struct ElboardText *text);
extern void func_0218768C(struct ElboardText *text);
extern int func_020478B8(G3dObject *obj, int animIndex, int step);
extern void func_02048F74(void *dst, u32 archiveId, u32 memberIndex, u32 mode, u32 size);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern struct FieldTaskManager *func_02188D38(struct FieldMap *fieldMap);
extern u16 func_0218ED2C(struct FieldCamera *camera);
extern u16 func_0218ED40(struct FieldCamera *camera);
extern u32 func_0218ED54(struct FieldCamera *camera);
extern void func_0218ECC4(struct FieldCamera *camera, VecFx32 *outTarget);
extern u8 func_021F3790(struct FieldMap *fieldMap);
extern struct FieldTask *func_021C6F00(struct FieldMap *fieldMap, u16 frames, u32 distance);
extern struct FieldTask *func_021C7058(struct FieldMap *fieldMap, u16 frames, u16 pitch);
extern struct FieldTask *func_021C701C(struct FieldMap *fieldMap, u16 frames, u16 yaw);
extern struct FieldTask *func_021C7AE4(struct FieldMap *fieldMap, u16 frames, VecFx32 *target);
extern void func_021C6DE0(struct FieldTaskManager *taskManager, struct FieldTask *task, u32 flag);
extern int func_021C6E48(struct FieldTaskManager *taskManager);
extern u32 func_020362DC(void);
typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
void func_021F3D38(GateWork *work, ElboardMessage *msg, int kind, GateNewsEntry *entry);
void func_021F3D78(GateWork *work);
void func_021F3DA8(GateWork *work);
void func_021F3DF0(GateWork *work);
void func_021F3E2C(GateWork *work);
void func_021F3E6C(GateWork *work);
void func_021F3EE8(GateWork *work);
void func_021F4058(GateWork *work);
void func_021F4104(GateWork *work);
void func_021F4188(GateWork *work);
void func_021F420C(GateWork *work);
void func_021F4290(GateWork *work);
void func_021F4314(GateWork *work);
void func_021F43E4(GateWork *work);
void func_021F440C(GateWork *work, GateNewsEntry *entry, int lane);
void func_021F4454(GateWork *work);
int func_021F4488(ElboardHighlights *highlights);
void func_021F44B8(ElboardHighlights *highlights);
void func_021F44D8(GateWork *work, ElboardHighlights *out);
void func_021F4590(GateWork *work, ElboardHighlights *out);
void func_021F45F0(GateWork *work, ElboardHighlights *out);
int func_021F4650(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork);
GimmickObjElboard *func_021F4698(ElboardConfig *config);
void func_021F472C(GimmickObjElboard *board, const ElboardMessage *msg);
void func_021F474C(GimmickObjElboard *board);
void func_021F4784(GimmickObjElboard *board, int step);
int func_021F47B0(GimmickObjElboard *board);
int func_021F47B4(GimmickObjElboard *board);
int func_021F47B8(GimmickObjElboard *board);
void func_021F47BC(GimmickObjElboard *board, int scroll);
ElboardLine *func_021F4948(GimmickObjElboard *board, const ElboardMessage *msg, int lineIndex);
void func_021F4B40(ElboardLine *line);
void func_021F4B54(ElboardLine *line);
void func_021F4B7C(GimmickObjElboard *board, ElboardLine *line, int step);
void func_021F4BF0(ElboardLine *line);
int func_021F4C10(void *dst, u32 archiveId, u32 memberIndex);
int func_021F4C20(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *func_021F4DBC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int frames);
int func_021F4DE4(void *dst, u32 archiveId, u32 memberIndex);
int func_021F4DF4(GateNewsEntry *entry, int zoneId);
int func_021F4E3C(GateNewsEntry *entry);
extern ElboardLayout d_021F50C0;
extern u32 d_021F5124[];        /* labelMsgId, inside d_021F50C0 */
extern u16 d_021F50C4[];        /* animIndex, inside d_021F50C0 */
extern const char *d_021F50EC[];  /* textureName, inside d_021F50C0 */
extern const char *d_021F5108[];  /* paletteName, inside d_021F50C0 */
extern const int d_021F4E84[];  /* lanes of the notice list: 2, 3, 4, 5 */
extern u16 d_021F4E5C[1];       /* places looked up in the table: {0x71} */
extern u8 d_021F4E5E[3];        /* kinds that qualify: {6, 7, 8} */
extern const char d_021F523C[]; /* "gimmick_obj_elboard.c", the __FILE__ string of this unit */


/*
 * Put a message on the board and remember its kind in the gate work (the
 * pending list is saved with the gate state, so the board refills the same
 * way after a reload). A notice (kind 8) also clears its event flag when the
 * table asks for it.
 */
void func_021F3D38(GateWork *work, ElboardMessage *msg, int kind, GateNewsEntry *entry)
{
    func_021F472C(work->board, msg);
    if (kind == GATE_MESSAGE_TYPE_NEWS)
        func_021F3A50(work, kind, entry->eventFlag);
    else
        func_021F3A50(work, kind, 0);
    if (kind == GATE_MESSAGE_TYPE_NEWS && entry->clearsFlagWhenShown == 1) {
        func_0201433C(func_0201296C(work->gameData), (unsigned short)entry->eventFlag);
    }
}


void func_021F3D78(GateWork *work)
{
    if (func_021F3A70(work) == 1) {
        func_021F3DF0(work);
        return;
    }
    if (func_021F3D24(work) != 0) {
        func_021F3E2C(work);
        return;
    }
    func_021F3DA8(work);
}


void func_021F3DA8(GateWork *work)
{
    if (func_021F47B8(work->board) == 0) {
        GateBoardRecord *record = work->record;

        if (record != 0 && record->enabled != 0) {
            func_021F4058(work);
            func_021F3E6C(work);
            func_021F3EE8(work);
            func_021F4104(work);
            func_021F4188(work);
            func_021F420C(work);
            func_021F4290(work);
        }
    }
}


void func_021F3DF0(GateWork *work)
{
    if (func_021F47B8(work->board) == 0) {
        GateBoardRecord *record = work->record;

        if (record != 0 && record->enabled != 0) {
            func_021F4058(work);
            func_021F3E6C(work);
            func_021F3EE8(work);
            func_021F4314(work);
            func_021F4290(work);
        }
    }
}


void func_021F3E2C(GateWork *work)
{
    if (func_021F47B8(work->board) == 0) {
        if (work->newsList != 0) {
            GateBoardRecord *record = work->record;

            if (record != 0 && record->enabled != 0) {
                func_021F4058(work);
                func_021F3E6C(work);
                func_021F3EE8(work);
                func_021F43E4(work);
                func_021F4290(work);
            }
        }
    }
}


void func_021F3E6C(GateWork *work)
{
    struct { RtcDate date; ElboardMessage msg; } locals;
    struct WordSet *wordSet;

    wordSet = func_0201EC64(work->heapId);
    func_02088864(&locals.date);
    func_0201EFA4(wordSet, 2, locals.date.year, 2, 2, 1);
    func_0201F230(wordSet, 0, locals.date.month);
    func_0201EFA4(wordSet, 1, locals.date.day, 2, 0, 1);
    locals.msg.animIndex = d_021F50C0.animIndex[0];
    locals.msg.textureName = d_021F50C0.textureName[0];
    locals.msg.paletteName = d_021F50C0.paletteName[0];
    locals.msg.arcId = 2;
    locals.msg.fileId = 0x26;
    locals.msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dateMsgId;
    locals.msg.wordSet = wordSet;
    func_021F3D38(work, &locals.msg, 1, 0);
    func_0201ED04(wordSet);
}


/*
 * Lists the places the board points out, up to four, as one message with
 * four word-set entries. Each entry is "place, label".
 *
 * `bufLen = 4; bufLen = 0x100;` is the original's str/adds #0xfc/str pair into
 * one spill slot (a dead store survives in a stack-homed local); f declared
 * before h1 puts its slot highest.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`bufLen = 4;` before `bufLen = 0x100;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang c99
 * and --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021F3EE8(GateWork *work)
{
    ElboardMessage msg;
    ElboardHighlights highlights;
    int bufLen;
    int msgId;
    struct WordSet *words;
    struct MsgData *placeNames;
    struct MsgData *boardText;
    int i;
    int kindIndex;
    struct Strbuf *placeName;
    struct Strbuf *labelText;
    struct WordSet *pairWords;
    struct Strbuf *pairTemplate;
    struct Strbuf *pairText;

    func_021F44D8(work, &highlights);
    bufLen = 0x100;
    words = func_0201EC74(4, bufLen, work->heapId);
    placeNames = func_02045B38(0, 2, 0x59, work->heapId);
    boardText = func_02045B38(0, 2, 0x26, work->heapId);
    for (i = 0; i < 4; i++) {
        if (highlights.placeId[i] == ELBOARD_NO_PLACE)
            continue;
        kindIndex = highlights.kind[i];
        placeName = func_02045EC0(placeNames, func_02013E4C(highlights.placeId[i]));
        labelText = func_02045EC0(boardText, d_021F5124[kindIndex]);
        pairWords = func_0201EC74(2, bufLen, work->heapId);
        pairTemplate = func_02045EC0(boardText, 0xc0);
        pairText = func_020457B0(0x40, work->heapId);
        func_0201EE0C(pairWords, 0, placeName, 0, 1, 0);
        func_0201EE0C(pairWords, 1, labelText, 0, 1, 0);
        func_0201F250(pairWords, pairText, pairTemplate);
        func_02045808(pairTemplate);
        func_0201ED04(pairWords);
        func_0201EE0C(words, i, pairText, 0, 1, 0);
        func_02045808(placeName);
        func_02045808(labelText);
        func_02045808(pairText);
    }
    func_02045C04(boardText);
    func_02045C04(placeNames);
    switch (func_021F4488(&highlights)) {
    case 0:
        break;
    case 1:
        msgId = 0xc1;
        break;
    case 2:
        msgId = 0xc2;
        break;
    case 3:
        msgId = 0xc3;
        break;
    case 4:
        msgId = 0xc4;
        break;
    }
    msg.animIndex = d_021F50C0.animIndex[1];
    msg.textureName = d_021F50C0.textureName[1];
    msg.paletteName = d_021F50C0.paletteName[1];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = msgId;
    msg.wordSet = words;
    func_021F3D38(work, &msg, 2, 0);
    func_0201ED04(words);
}


/* Message about the place the player came from (skipped for place 0xFFFF). */
void func_021F4058(GateWork *work)
{
    ElboardMessage msg;
    int placeId;
    struct WordSet *words;
    struct MsgData *placeNames;
    struct Strbuf *placeName;

    placeId = func_021A9810(work->gameData);
    if (placeId == 0xFFFF)
        return;
    if (placeId == 0x159 && func_02012984(work->gameData) == 3)
        return;
    words = func_0201EC64(work->heapId);
    placeNames = func_02045B38(0, 2, 0x59, work->heapId);
    placeName = func_02045EC0(placeNames, func_02013E4C(placeId));
    func_0201EE0C(words, 0, placeName, 0, 1, 0);
    func_02045808(placeName);
    func_02045C04(placeNames);
    msg.animIndex = d_021F50C0.animIndex[2];
    msg.textureName = d_021F50C0.textureName[2];
    msg.paletteName = d_021F50C0.paletteName[2];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->newsMsgId;
    msg.wordSet = words;
    func_021F3D38(work, &msg, 3, 0);
    func_0201ED04(words);
}


/* Daily line 1: the message is picked by the weekday. */
void func_021F4104(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    func_02088864(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[0]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[1]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    }
    msg.animIndex = d_021F50C0.animIndex[3];
    msg.textureName = d_021F50C0.textureName[3];
    msg.paletteName = d_021F50C0.paletteName[3];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    func_021F3D38(work, &msg, 4, 0);
}


/* Daily line 2: same weekday pick, one entry further in the daily table. */
void func_021F4188(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    func_02088864(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[7]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[1]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    }
    msg.animIndex = d_021F50C0.animIndex[4];
    msg.textureName = d_021F50C0.textureName[4];
    msg.paletteName = d_021F50C0.paletteName[4];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    func_021F3D38(work, &msg, 5, 0);
}


/* Daily line 3: same weekday pick, two entries further in the daily table. */
void func_021F420C(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    func_02088864(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[8]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[7]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    }
    msg.animIndex = d_021F50C0.animIndex[5];
    msg.textureName = d_021F50C0.textureName[5];
    msg.paletteName = d_021F50C0.paletteName[5];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    func_021F3D38(work, &msg, 6, 0);
}


/* Weekly line: one message per weekday, Monday first. */
void func_021F4290(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    func_02088864(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[6]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[0]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[1]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[2]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[3]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[4]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[5]; break;
    }
    msg.animIndex = d_021F50C0.animIndex[6];
    msg.textureName = d_021F50C0.textureName[6];
    msg.paletteName = d_021F50C0.paletteName[6];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    func_021F3D38(work, &msg, 7, 0);
}


/* Message with the ids stored in the save (up to six), one word-set entry each. */
void func_021F4314(GateWork *work)
{
    ElboardMessage msg;
    u32 savedIds[6];
    int savedCount;
    struct WordSet *words;
    int i;
    int msgId;

    words = func_0201EC64(func_021F47B4(work->board));
    if (func_021F3AB4(work))
        func_021F3AD4(work, savedIds, &savedCount);
    else
        func_021F3B64(work, savedIds, &savedCount);
    switch (savedCount) {
    case 0: break;
    case 1: msgId = 0xcd; break;
    case 2: msgId = 0xce; break;
    case 3: msgId = 0xcf; break;
    case 4: msgId = 0xd0; break;
    case 5: msgId = 0xd1; break;
    case 6: msgId = 0xd2; break;
    }
    for (i = 0; i < savedCount; i++)
        func_0201EE60(words, i, savedIds[i]);
    func_0201F02C(words, 6, func_02012944(work->gameData));
    msg.animIndex = d_021F50C0.animIndex[3];
    msg.textureName = d_021F50C0.textureName[3];
    msg.paletteName = d_021F50C0.paletteName[3];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = msgId;
    msg.wordSet = words;
    func_021F3D38(work, &msg, 9, 0);
    func_0201ED04(words);
}

void func_021F43E4(GateWork *work)
{
    GateNewsEntry *entry;

    entry = func_021F3C2C(work);
    switch (entry->kind) {
    case GATE_NEWS_KIND_SINGLE:
        func_021F440C(work, entry, 3);
        break;
    case GATE_NEWS_KIND_LIST:
        func_021F4454(work);
        break;
    }
}


/* Put one notice on the board, on the given lane of the layout table. */
void func_021F440C(GateWork *work, GateNewsEntry *entry, int lane)
{
    ElboardMessage msg;

    msg.animIndex = d_021F50C4[lane];
    msg.textureName = d_021F50EC[lane];
    msg.paletteName = d_021F5108[lane];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = entry->messageId;
    msg.wordSet = 0;
    func_021F3D38(work, &msg, GATE_MESSAGE_TYPE_NEWS, entry);
}

/*
 * lever: Post-increment in the table subscript schedules the counter update before the call.
 */
void func_021F4454(GateWork *work)
{
    int i;
    GateNewsEntry *entry;

    i = 0;
    entry = func_021F3CB0(work);
    while (entry && i < 4) {
        func_021F440C(work, entry, d_021F4E84[i++]);
        entry = func_021F3CB0(work);
    }
}

/*
 * Number of used place slots. The kind byte is compared with 0xFFFF, so the
 * second test is always true (as in the original).
 */
int func_021F4488(ElboardHighlights *highlights)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < 4; i++)
        if (highlights->placeId[i] != ELBOARD_NO_PLACE && highlights->kind[i] != 0xffff)
            count++;
    return count;
}


/*
 * Empties the list: the four place ids get ELBOARD_NO_PLACE and the four
 * kind bytes 0xFF.
 */
void func_021F44B8(ElboardHighlights *highlights)
{
    int i;

    for (i = 0; i < 4; i++) {
        highlights->placeId[i] = ELBOARD_NO_PLACE;
        highlights->kind[i] = 0xFF;
    }
}


/* Two highlights at most: first the G-Power place, then the table places, else the gate defaults. */
void func_021F44D8(GateWork *work, ElboardHighlights *out)
{
    ElboardHighlights fromTable;
    ElboardHighlights fromGPower;
    int count, j, k;

    count = 0;
    func_021F44B8(out);
    func_021F4590(work, &fromTable);
    func_021F45F0(work, &fromGPower);
    for (j = 0; j < 4; j++) {
        if (fromGPower.placeId[j] == ELBOARD_NO_PLACE)
            break;
        if (fromGPower.kind[j] == 0xFFFF)
            break;
        if (count >= 2)
            break;
        out->placeId[count] = fromGPower.placeId[j];
        out->kind[count] = fromGPower.kind[j];
        count++;
    }
    for (j = 0; j < 4; j++) {
        if (fromTable.placeId[j] == ELBOARD_NO_PLACE)
            break;
        if (fromTable.kind[j] == 0xFFFF)
            break;
        if (count >= 2)
            break;
        out->placeId[count] = fromTable.placeId[j];
        out->kind[count] = fromTable.kind[j];
        count++;
    }
    if (count == 0) {
        GateBoardRecord *record = work->record;

        out->placeId[0] = ELBOARD_RECORD_PARAMS(record)->defaultPlaceId[0];
        out->placeId[1] = ELBOARD_RECORD_PARAMS(record)->defaultPlaceId[1];
        out->placeId[2] = ELBOARD_RECORD_PARAMS(record)->defaultPlaceId[2];
        out->placeId[3] = ELBOARD_RECORD_PARAMS(record)->defaultPlaceId[3];
    }
    for (k = 0; k < 4; k++)
        out->kind[k] = func_02188C70(work->fieldMap, out->placeId[k]);
}


/*
 * The one-trip outer loop survives only because its int counter is compared
 * against an unsigned (sizeof) bound: `i < 1` or an unsigned counter is
 * folded away as a single pass. Tables: d_021F4E5C = {0x0071} (u16),
 * d_021F4E5E = {6,7,8} (u8). func_02188C70 returns int (its own file); the
 * u8 local is what emits the lsls/lsrs #24.
 */
void func_021F4590(GateWork *work, ElboardHighlights *out)
{
    int i, j, count;

    func_021F44B8(out);
    count = 0;
    for (i = 0; i < sizeof(d_021F4E5C) / sizeof(d_021F4E5C[0]); i++) {
        u16 placeId = d_021F4E5C[i];
        u8 kind = func_02188C70(work->fieldMap, placeId);

        for (j = 0; j < sizeof(d_021F4E5E); j++) {
            if (kind == d_021F4E5E[j]) {
                if (count >= 4)
                    break;
                out->placeId[count] = placeId;
                out->kind[count] = kind;
                count++;
            }
        }
    }
}


/* The place tied to the active G-Power (powers 0x14 and 0x15), if the save holds one. */
void func_021F45F0(GateWork *work, ElboardHighlights *out)
{
    struct EncounterState *encounter;
    int slot;
    int kind;
    int placeId;

    encounter = func_0200D418(func_02012EBC(work->gameData));
    func_021F44B8(out);
    if (func_0215E404(encounter)) {
        placeId = GPOWER_GetSpecialPowerId();
        switch (placeId) {
        case 0x14:
            slot = 0;
            break;
        case 0x15:
            slot = 1;
            break;
        }
        switch (slot) {
        case 0:
            kind = 6;
            break;
        case 1:
            kind = 7;
            break;
        }
        placeId = func_0215E3E4(encounter, (unsigned char)slot);
        if (placeId != 0xFFFF) {
            out->placeId[0] = placeId;
            out->kind[0] = kind;
        }
    }
}


/* Script command: run the camera event of the gate board (SE 0x547 first). */
int func_021F4650(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    int frames;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    frames = (int)func_02159B10(ctx, cmdWork);
    func_020061E4(0x547);
    func_0215897C(scriptWork, func_021F4DBC(gameSystem, fieldMap, frames));
    return 1;
}


GimmickObjElboard *func_021F4698(ElboardConfig *config)
{
    int i;
    GimmickObjElboard *board;

    board = func_02030734(config->heapId, 0x1c, 0, d_021F523C, 0x60);
    i = 0;
    board->heapId = config->heapId;
    board->lineCount = i;
    board->lineCapacity = config->lineCapacity;
    board->leadChars = config->leadChars;
    board->trailChars = config->trailChars;
    board->render = config->render;
    board->scroll = i;
    board->lines = func_02030734(config->heapId, config->lineCapacity * 4, 0, d_021F523C, 0x6d);
    board->startRequest = func_02030734(config->heapId, config->lineCapacity * 4, 0, d_021F523C, 0x6f);
    for (i = 0; i < config->lineCapacity; i++) {
        board->lines[i] = 0;
        board->startRequest[i] = 0;
    }
    board->startRequest[0] = 1;
    board->font = func_0201D7EC(0x17, 0, 0, 0, board->heapId);
    return board;
}

void func_021F472C(GimmickObjElboard *board, const ElboardMessage *msg)
{
    if (board->lineCapacity > board->lineCount) {
        board->lines[board->lineCount] = func_021F4948(board, msg, board->lineCount);
        board->lineCount++;
    }
}

void func_021F474C(GimmickObjElboard *board)
{
    int i;

    func_0201D83C(board->font);
    for (i = 0; i < board->lineCount; i++)
        func_021F4B40(board->lines[i]);
    func_020307B0(board->lines);
    func_020307B0(board->startRequest);
    func_020307B0(board);
}

void func_021F4784(GimmickObjElboard *board, int step)
{
    int i;

    for (i = 0; i < board->lineCount; i++)
        func_021F4B7C(board, board->lines[i], step);
    board->scroll += step;
}


/*
 * int getter, u16 getter, u8 getter.
 */
int func_021F47B0(GimmickObjElboard *board)
{
    return board->scroll;
}


int func_021F47B4(GimmickObjElboard *board)
{
    return board->heapId;
}


int func_021F47B8(GimmickObjElboard *board)
{
    return board->lineCount;
}


/*
 * Jump the board to a scroll position. The lines run one after another in a
 * loop of `totalFrames` frames; each line gets its own local time, which
 * decides if it plays and if the next line was already started.
 */
void func_021F47BC(GimmickObjElboard *board, int scroll)
{
    int *lineStart;
    int *localFrame;
    int i, totalFrames, frame, j, flag;
    ElboardLine *line;

    frame = scroll >> 12;
    totalFrames = 0;
    /* heap id with the high bit set: the temporary arrays come from the other end of the heap */
    lineStart = (int *)func_02030734((u16)((board->heapId & 0x7FFF) | 0x8000), board->lineCount * 4, 0, d_021F523C, 0x11A);
    localFrame = (int *)func_02030734((u16)((board->heapId & 0x7FFF) | 0x8000), board->lineCount * 4, 0, d_021F523C, 0x11C);
    board->scroll = scroll;
    for (i = 0; i < board->lineCount; i++) {
        board->startRequest[i] = 0;
        totalFrames += board->lines[i]->nextStartTime >> 12;
        if (i == 0) {
            lineStart[i] = 0;
        } else {
            lineStart[i] = lineStart[i - 1] + (board->lines[i - 1]->nextStartTime >> 12);
        }
    }
    for (i = 0; i < board->lineCount; i++) {
        line = board->lines[i];
        localFrame[i] = frame % totalFrames - lineStart[i];
        flag = 0;
        if (localFrame[i] > 0 && localFrame[i] < (line->endTime >> 12)) {
            flag = 1;
        }
        line->isPlaying = flag;
        flag = 0;
        if ((line->nextStartTime >> 12) < localFrame[i] && localFrame[i] < (line->endTime >> 12)) {
            flag = 1;
        }
        line->nextStarted = flag;
        if (localFrame[i] < 0) {
            localFrame[i] = 0;
        }
        line->elapsed = localFrame[i] << 12;
        func_0204784C(line->render, line->animIndex, &line->elapsed);
        if (line->isPlaying) {
            func_020477A4(line->render, line->animIndex);
        } else {
            func_020477D4(line->render, line->animIndex);
        }
    }
    if (board->lineCount != 0 && frame == 0) {
        line = board->lines[0];
        line->isPlaying = 1;
        func_020477A4(line->render, line->animIndex);
    }
    for (i = 0; i < board->lineCount; i++) {
        j = (i + 1) % board->lineCount;
        flag = 0;
        if (board->lines[i]->nextStarted != 0 && board->lines[j]->isPlaying == 0) {
            flag = 1;
        }
        board->startRequest[j] = flag;
    }
    func_020307B0(lineStart);
    func_020307B0(localFrame);
}


/*
 * Build one line: render the message text into the texture of the lane and
 * work out when the line starts, when the next line may start and when it
 * ends, as fractions of the 1024 pixel texture scaled to the animation length.
 */
ElboardLine *func_021F4948(GimmickObjElboard *board, const ElboardMessage *msg, int lineIndex)
{
    ElboardLine *line;
    struct MsgData *msgData;
    struct Strbuf *str;
    struct Strbuf *tmp;
    int width;
    int totalWidth;
    int leadWidth;
    int textWidth;
    int textAndTrail;
    fx32 animFrames;

    line = func_02030734(board->heapId, 0x24, 0, d_021F523C, 0x180);
    msgData = func_02045B38(0, (u16)msg->arcId, (u16)msg->fileId, board->heapId);
    if (msg->wordSet != 0) {
        str = func_020457B0(0xC0, board->heapId);
        tmp = func_02045EC0(msgData, msg->msgId);
        func_0201F250(msg->wordSet, str, tmp);
        func_020307B0(tmp);
    } else {
        str = func_02045EC0(msgData, msg->msgId);
    }
    width = func_0201D304(str, board->font, 1);
    line->text = func_021875F4(G3D_SYSTEM_GetRenderTexRes(func_02047788(board->render)), msg->textureName, msg->paletteName, str, board->leadChars * 14, 1, board->heapId);
    func_020307B0(str);
    func_02045C04(msgData);
    animFrames = func_02047674(func_02047790(board->render, msg->animIndex))->resAnm->numFrame << 12;
    leadWidth = board->leadChars * 13;
    totalWidth = leadWidth + width;
    textWidth = totalWidth - leadWidth;
    textAndTrail = textWidth + board->trailChars * 13;
    line->elapsed = 0;
    line->nextStartTime = FX_F32_TO_FX32((float)textAndTrail / 1024.0f);
    line->nextStartTime = FX_Mul(line->nextStartTime, animFrames);
    line->endTime = FX_F32_TO_FX32((float)totalWidth / 1024.0f);
    line->endTime = FX_Mul(line->endTime, animFrames);
    line->lineIndex = lineIndex;
    line->isPlaying = 0;
    line->nextStarted = 0;
    line->render = board->render;
    line->animIndex = msg->animIndex;
    func_020477D4(line->render, line->animIndex);
    func_02047804(line->render, line->animIndex);
    return line;
}

void func_021F4B40(ElboardLine *line)
{
    func_02187684(line->text);
    func_020307B0(line);
}

void func_021F4B54(ElboardLine *line)
{
    if (line->isPlaying != 1) {
        line->isPlaying = 1;
        line->nextStarted = 0;
        line->elapsed = 0;
        func_020477A4(line->render, line->animIndex);
        func_02047804(line->render, line->animIndex);
    }
}


/* One step of a line: advance it while it plays, start the next line, or start itself on request. */
void func_021F4B7C(GimmickObjElboard *board, ElboardLine *line, int step)
{
    int newElapsed;

    if (line->isPlaying == 1) {
        func_0218768C(line->text);
        func_020478B8(line->render, line->animIndex, step);
        newElapsed = line->elapsed + step;
        line->elapsed = newElapsed;
        if (line->nextStartTime < newElapsed) {
            if (line->nextStarted != 1) {
                board->startRequest[(line->lineIndex + 1) % board->lineCount] = 1;
                line->nextStarted = 1;
            }
        }
        if (line->endTime < line->elapsed) {
            func_021F4BF0(line);
            return;
        }
    } else {
        if (board->startRequest[line->lineIndex] == 1) {
            func_021F4B54(line);
            board->startRequest[line->lineIndex] = 0;
        }
    }
}

void func_021F4BF0(ElboardLine *line)
{
    if (line->isPlaying == 1) {
        line->isPlaying = 0;
        func_020477D4(line->render, line->animIndex);
        func_02047804(line->render, line->animIndex);
    }
}

/* Read one record of the gate table (arc 0xAE, 0x7C bytes). */
int func_021F4C10(void *dst, u32 archiveId, u32 memberIndex)
{
    func_02048F74(dst, archiveId, memberIndex, 0, 0x7c);
    return 1;
}


/*
 * Camera event of the board: save the camera, move it to a fixed view of the
 * board (the view depends on the way the gate faces), wait for a direction key
 * or B, then move the camera back. Returns 1 when done.
 */
int func_021F4C20(struct GameEvent *event, int *seq, void *eventWork)
{
    GateCameraEventWork *work = eventWork;
    struct FieldMap *fieldMap;
    struct FieldCamera *camera;
    struct FieldTaskManager *taskManager;
    u32 keys;

    fieldMap = work->fieldMap;
    camera = func_02188C58(fieldMap);
    taskManager = func_02188D38(fieldMap);
    switch (*seq) {
    case 0:
        work->savedPitch = func_0218ED2C(camera);
        work->savedYaw = func_0218ED40(camera);
        work->savedDistance = func_0218ED54(camera);
        func_0218ECC4(camera, &work->savedTarget);
        (*seq)++;
        break;
    case 1: {
        VecFx32 target;
        int pitch;
        int yaw;
        u32 distance;
        struct FieldTask *distanceTask;
        struct FieldTask *pitchTask;
        struct FieldTask *yawTask;
        struct FieldTask *targetTask;

        switch (func_021F3790(fieldMap)) {
        case 1:
        default:
            pitch = 0xEE5;
            distance = 0x86000;
            yaw = 0;
            target.x = 0;
            target.y = 0x1B000;
            target.z = -0x6C000;
            break;
        case 3:
            pitch = 0xEE5;
            distance = 0x86000;
            yaw = 0x3FFF;
            target.x = -0x6C000;
            target.y = 0x1B000;
            target.z = 0;
            break;
        }
        distanceTask = func_021C6F00(fieldMap, work->frames, distance);
        pitchTask = func_021C7058(fieldMap, work->frames, pitch);
        yawTask = func_021C701C(fieldMap, work->frames, yaw);
        targetTask = func_021C7AE4(fieldMap, work->frames, &target);
        func_021C6DE0(taskManager, distanceTask, 0);
        func_021C6DE0(taskManager, pitchTask, 0);
        func_021C6DE0(taskManager, yawTask, 0);
        func_021C6DE0(taskManager, targetTask, 0);
        (*seq)++;
        break;
    }
    case 2:
        if (func_021C6E48(taskManager))
            (*seq)++;
        break;
    case 3:
        keys = func_020362DC();
        /* Left, Right, Down or B */
        if ((keys & 0x20) || (keys & 0x10) || (keys & 0x80) || (keys & 2))
            (*seq)++;
        break;
    case 4: {
        struct FieldTask *distanceTask;
        struct FieldTask *pitchTask;
        struct FieldTask *yawTask;
        struct FieldTask *targetTask;

        distanceTask = func_021C6F00(fieldMap, work->frames, work->savedDistance);
        pitchTask = func_021C7058(fieldMap, work->frames, work->savedPitch);
        yawTask = func_021C701C(fieldMap, work->frames, work->savedYaw);
        targetTask = func_021C7AE4(fieldMap, work->frames, &work->savedTarget);
        func_021C6DE0(taskManager, distanceTask, 0);
        func_021C6DE0(taskManager, pitchTask, 0);
        func_021C6DE0(taskManager, yawTask, 0);
        func_021C6DE0(taskManager, targetTask, 0);
        (*seq)++;
        break;
    }
    case 5:
        if (func_021C6E48(taskManager))
            (*seq)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

struct GameEvent *func_021F4DBC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int frames)
{
    struct GameEvent *event;
    GateCameraEventWork *work;

    event = func_020122C0(gameSystem, 0, func_021F4C20, 0x20);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frames = frames;
    return event;
}

/* Read one record of the notice table (arc 0xA6, 0x24 bytes). */
int func_021F4DE4(void *dst, u32 archiveId, u32 memberIndex)
{
    func_02048F74(dst, archiveId, memberIndex, 0, 0x24);
    return 1;
}

/*
 * True when the notice names no zone (four GATE_NEWS_ZONE_ANY entries) or
 * names the given zone.
 */
int func_021F4DF4(GateNewsEntry *entry, int zoneId)
{
    if (entry->zoneIds[0] == GATE_NEWS_ZONE_ANY && entry->zoneIds[1] == GATE_NEWS_ZONE_ANY
        && entry->zoneIds[2] == GATE_NEWS_ZONE_ANY && entry->zoneIds[3] == GATE_NEWS_ZONE_ANY)
        return 1;
    if (entry->zoneIds[0] == zoneId || entry->zoneIds[1] == zoneId
        || entry->zoneIds[2] == zoneId || entry->zoneIds[3] == zoneId)
        return 1;
    return 0;
}

/* True when the notice has no G-Power requirement or the active special power matches. */
int func_021F4E3C(GateNewsEntry *entry)
{
    if (entry->specialPowerId == 0)
        return 1;
    if (entry->specialPowerId == GPOWER_GetSpecialPowerId())
        return 1;
    return 0;
}

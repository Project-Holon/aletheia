/*
 * file:     gimmick_obj_elboard.c
 * unit:     yes
 * function: GIMMICK_OBJ_ELBOARD_AddMessage, GIMMICK_OBJ_ELBOARD_FillMessages, GIMMICK_OBJ_ELBOARD_FillDefaultMessages, GIMMICK_OBJ_ELBOARD_FillSavedListMessages, GIMMICK_OBJ_ELBOARD_FillNoticeMessages, GIMMICK_OBJ_ELBOARD_AddDateMessage, GIMMICK_OBJ_ELBOARD_AddPlaceListMessage, GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage, GIMMICK_OBJ_ELBOARD_AddDailyMessage1, GIMMICK_OBJ_ELBOARD_AddDailyMessage2, GIMMICK_OBJ_ELBOARD_AddDailyMessage3, GIMMICK_OBJ_ELBOARD_AddWeekdayMessage, GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage, GIMMICK_OBJ_ELBOARD_AddNoticeMessages, GIMMICK_OBJ_ELBOARD_AddNoticeMessage, GIMMICK_OBJ_ELBOARD_AddNoticeList, GIMMICK_OBJ_ELBOARD_CountHighlights, GIMMICK_OBJ_ELBOARD_ClearHighlights, GIMMICK_OBJ_ELBOARD_CollectHighlights, GIMMICK_OBJ_ELBOARD_CollectTableHighlights, GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight, GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent, GIMMICK_OBJ_ELBOARD_Create, GIMMICK_OBJ_ELBOARD_AddLine, GIMMICK_OBJ_ELBOARD_Delete, GIMMICK_OBJ_ELBOARD_Advance, GIMMICK_OBJ_ELBOARD_GetScroll, GIMMICK_OBJ_ELBOARD_GetHeapId, GIMMICK_OBJ_ELBOARD_GetLineCount, GIMMICK_OBJ_ELBOARD_SetScroll, GIMMICK_OBJ_ELBOARD_CreateLine, GIMMICK_OBJ_ELBOARD_DeleteLine, GIMMICK_OBJ_ELBOARD_StartLine, GIMMICK_OBJ_ELBOARD_UpdateLine, GIMMICK_OBJ_ELBOARD_StopLine, GIMMICK_OBJ_ELBOARD_ReadGateInfo, GIMMICK_OBJ_ELBOARD_CameraEventMain, GIMMICK_OBJ_ELBOARD_CreateCameraEvent, GIMMICK_OBJ_ELBOARD_ReadGateEntry, GIMMICK_OBJ_ELBOARD_CheckEntryZone, GIMMICK_OBJ_ELBOARD_CheckEntryGPower
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
 *   FIELD_GIMMICK_GATE_LogMessage  0x021F3A50  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   FIELD_GIMMICK_GATE_HasMessagesToShow  0x021F3A70  thumb
 *   func_021F3D24  0x021F3D24  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   RTC_GetDate  0x02088864  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F230  0x0201F230  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   gElboardLayout     0x021F50C0  data  a4
 *   WORDSET_Create  0x0201EC74  thumb
 *   func_02045B38  0x02045B38  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   gElboardLabelMsgId     0x021F5124  data  a4
 *   FIELD_ENCOUNT_GetSwarmZoneId  0x021A9810  thumb  ov021
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_GIMMICK_GATE_IsExtraSaveListOn  0x021F3AB4  thumb  ov048
 *   FIELD_GIMMICK_GATE_ReadExtraSaveValues  0x021F3AD4  thumb  ov048
 *   FIELD_GIMMICK_GATE_ReadSaveBlockValues  0x021F3B64  thumb  ov048
 *   WORDSET_Callback  0x0201EE60  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   FIELD_GIMMICK_GATE_FindNewsEntry 0x021F3C2C thumb ov048
 *   gElboardLayoutAnimIndex     0x021F50C4  data  a2
 *   gElboardLayoutTextureName     0x021F50EC  data  a4
 *   gElboardLayoutPaletteName     0x021F5108  data  a4
 *   FIELD_GIMMICK_GATE_FindListNewsEntry 0x021F3CB0 thumb ov048
 *   gElboardNoticeLanes 0x021F4E84 data a4
 *   FIELDMAP_QueryIssSwitch  0x02188C70  thumb  ov021
 *   gElboardPlaceTable     0x021F4E5C  data  a2
 *   gElboardPlaceKinds     0x021F4E5E  data  a1
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_HasActiveEntry  0x0215E404  thumb  ov010
 *   MOVE_POKEMON_GetEntryZoneId  0x0215E3E4  thumb  ov010
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   gElboardFileName     0x021F523C  data  a1
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 *   func_0201D304  0x0201D304  thumb
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_GetRenderTexRes  0x02047554  arm
 *   EL_SCOREBOARD_CreateLamp  0x021875F4  thumb  ov020
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fgr           0x0209BBB0  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   EL_SCOREBOARD_DeleteLamp 0x02187684 thumb ov020
 *   EL_SCOREBOARD_TickLamp  0x0218768C  thumb  ov020
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   ARC_TOOL_ReadMemberRange 0x02048F74 arm
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_GetPitch  0x0218ED2C  thumb  ov021
 *   FIELD_CAMERA_GetYaw  0x0218ED40  thumb  ov021
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_GIMMICK_GATE_GetBoardFacing  0x021F3790  thumb  ov048
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateCameraPitchTween  0x021C7058  thumb  ov021
 *   FIELD_TASK_CreateCameraYawTween  0x021C701C  thumb  ov021
 *   FIELD_TASK_CreateCameraTargetTween  0x021C7AE4  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
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
 * Layout table of the board lanes (gElboardLayout, 0x64 bytes), shared with
 * field_gimmick_gate.c. The label message ids that follow it in the data are
 * gElboardLabelMsgId. They stay out of the struct on purpose: with a struct above
 * about 0x70 bytes the compiler schedules GIMMICK_OBJ_ELBOARD_AddDateMessage differently.
 */
typedef struct ElboardLayout {
    fx32        scrollSpeed;        /* 0x00 */
    u16         animIndex[20];      /* 0x04: gElboardLayoutAnimIndex, one animation per lane */
    const char *textureName[7];     /* 0x2C: gElboardLayoutTextureName */
    const char *paletteName[7];     /* 0x48: gElboardLayoutPaletteName */
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

extern void FIELD_GIMMICK_GATE_LogMessage(GateWork *work, int kind, int param);
extern struct EventWork *GAME_DATA_GetEventWork(struct GameData *gameData);
extern void ZONEDATA_ResetEventFlag(struct EventWork *eventWork, int flagId);
extern int FIELD_GIMMICK_GATE_HasMessagesToShow(GateWork *work);
extern int func_021F3D24(GateWork *work);
extern struct WordSet *GF_FONT_Create_EC64(u32 heapId);
extern int RTC_GetDate(RtcDate *date);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 keta, u32 dispType, u32 codeType);
extern void func_0201F230(struct WordSet *wordSet, u32 index, u32 month);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern struct WordSet *WORDSET_Create(u32 wordMax, u32 bufLen, u16 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 ZONEDATA_GetPlaceNameId(u32 placeId);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const struct Strbuf *str, u32 sex, u32 singular, u32 lang);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void STRBUF_Delete(struct Strbuf *str);
extern u32 MSGDATA_Delete(struct MsgData *msgData);
extern u16 FIELD_ENCOUNT_GetSwarmZoneId(struct GameData *gameData);
extern u8 GAME_DATA_GetSeason(struct GameData *gameData);
extern int FIELD_GIMMICK_GATE_IsExtraSaveListOn(GateWork *work);
extern void FIELD_GIMMICK_GATE_ReadExtraSaveValues(GateWork *work, u32 *outIds, int *outCount);
extern void FIELD_GIMMICK_GATE_ReadSaveBlockValues(GateWork *work, u32 *outIds, int *outCount);
extern void WORDSET_Callback(struct WordSet *wordSet, u32 index, u16 value);
extern void *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, void *myStatus);
extern GateNewsEntry *FIELD_GIMMICK_GATE_FindNewsEntry(GateWork *work);
extern GateNewsEntry *FIELD_GIMMICK_GATE_FindListNewsEntry(GateWork *work);
extern int FIELDMAP_QueryIssSwitch(struct FieldMap *fieldMap, int placeId);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct EncounterState *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);
extern int MOVE_POKEMON_HasActiveEntry(struct EncounterState *state);
extern u32 GPOWER_GetSpecialPowerId(void);
extern u32 MOVE_POKEMON_GetEntryZoneId(struct EncounterState *state, u32 slot);
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrCmdWork *cmdWork);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrCmdWork *cmdWork);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern void SCRIPT_SYS_CallEvent(struct ScriptWork *scriptWork, struct GameEvent *event);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern unsigned int GF_FONT_Delete(struct GfFont *font);
extern u32 func_020307B0(void *p);
extern int func_0209C0A4(int a, int b);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 animIndex, s32 *frame);
extern u32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 animIndex);
extern int G3D_SYSTEM_DisableObjectAnime(G3dObject *obj, u32 animIndex);
extern u32 func_0201D304(struct Strbuf *str, struct GfFont *font, u32 spacing);
extern G3dRender *G3D_SYSTEM_GetObjectRender(G3dObject *obj);
extern G3dResource *G3D_SYSTEM_GetRenderTexRes(G3dRender *render);
extern struct ElboardText *EL_SCOREBOARD_CreateLamp(G3dResource *texRes, const char *textureName, const char *paletteName, struct Strbuf *str, u16 width, u16 flag, u16 heapId);
extern G3dAnime *G3D_SYSTEM_GetObjectAnime(G3dObject *obj, int animIndex);
extern NNSG3dAnmObj *G3D_SYSTEM_GetAnimeObj(G3dAnime *anime);
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(G3dObject *obj, u16 animIndex);
extern void EL_SCOREBOARD_DeleteLamp(struct ElboardText *text);
extern void EL_SCOREBOARD_TickLamp(struct ElboardText *text);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int animIndex, int step);
extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archiveId, u32 memberIndex, u32 mode, u32 size);
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern struct FieldTaskManager *FIELDMAP_GetTaskManager(struct FieldMap *fieldMap);
extern u16 FIELD_CAMERA_GetPitch(struct FieldCamera *camera);
extern u16 FIELD_CAMERA_GetYaw(struct FieldCamera *camera);
extern u32 FIELD_CAMERA_GetDistance(struct FieldCamera *camera);
extern void FIELD_CAMERA_GetTargetShift(struct FieldCamera *camera, VecFx32 *outTarget);
extern u8 FIELD_GIMMICK_GATE_GetBoardFacing(struct FieldMap *fieldMap);
extern struct FieldTask *FIELD_TASK_CreateCameraDistanceTween(struct FieldMap *fieldMap, u16 frames, u32 distance);
extern struct FieldTask *FIELD_TASK_CreateCameraPitchTween(struct FieldMap *fieldMap, u16 frames, u16 pitch);
extern struct FieldTask *FIELD_TASK_CreateCameraYawTween(struct FieldMap *fieldMap, u16 frames, u16 yaw);
extern struct FieldTask *FIELD_TASK_CreateCameraTargetTween(struct FieldMap *fieldMap, u16 frames, VecFx32 *target);
extern void FIELD_TASK_MANAGER_AddTask(struct FieldTaskManager *taskManager, struct FieldTask *task, u32 flag);
extern int FIELD_TASK_MANAGER_IsEmpty(struct FieldTaskManager *taskManager);
extern u32 KEY_GetTrg(void);
typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
void GIMMICK_OBJ_ELBOARD_AddMessage(GateWork *work, ElboardMessage *msg, int kind, GateNewsEntry *entry);
void GIMMICK_OBJ_ELBOARD_FillMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillDefaultMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillSavedListMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_FillNoticeMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDateMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage1(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage2(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddDailyMessage3(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddNoticeMessages(GateWork *work);
void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(GateWork *work, GateNewsEntry *entry, int lane);
void GIMMICK_OBJ_ELBOARD_AddNoticeList(GateWork *work);
int GIMMICK_OBJ_ELBOARD_CountHighlights(ElboardHighlights *highlights);
void GIMMICK_OBJ_ELBOARD_ClearHighlights(ElboardHighlights *highlights);
void GIMMICK_OBJ_ELBOARD_CollectHighlights(GateWork *work, ElboardHighlights *out);
void GIMMICK_OBJ_ELBOARD_CollectTableHighlights(GateWork *work, ElboardHighlights *out);
void GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight(GateWork *work, ElboardHighlights *out);
int GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork);
GimmickObjElboard *GIMMICK_OBJ_ELBOARD_Create(ElboardConfig *config);
void GIMMICK_OBJ_ELBOARD_AddLine(GimmickObjElboard *board, const ElboardMessage *msg);
void GIMMICK_OBJ_ELBOARD_Delete(GimmickObjElboard *board);
void GIMMICK_OBJ_ELBOARD_Advance(GimmickObjElboard *board, int step);
int GIMMICK_OBJ_ELBOARD_GetScroll(GimmickObjElboard *board);
int GIMMICK_OBJ_ELBOARD_GetHeapId(GimmickObjElboard *board);
int GIMMICK_OBJ_ELBOARD_GetLineCount(GimmickObjElboard *board);
void GIMMICK_OBJ_ELBOARD_SetScroll(GimmickObjElboard *board, int scroll);
ElboardLine *GIMMICK_OBJ_ELBOARD_CreateLine(GimmickObjElboard *board, const ElboardMessage *msg, int lineIndex);
void GIMMICK_OBJ_ELBOARD_DeleteLine(ElboardLine *line);
void GIMMICK_OBJ_ELBOARD_StartLine(ElboardLine *line);
void GIMMICK_OBJ_ELBOARD_UpdateLine(GimmickObjElboard *board, ElboardLine *line, int step);
void GIMMICK_OBJ_ELBOARD_StopLine(ElboardLine *line);
int GIMMICK_OBJ_ELBOARD_ReadGateInfo(void *dst, u32 archiveId, u32 memberIndex);
int GIMMICK_OBJ_ELBOARD_CameraEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *GIMMICK_OBJ_ELBOARD_CreateCameraEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int frames);
int GIMMICK_OBJ_ELBOARD_ReadGateEntry(void *dst, u32 archiveId, u32 memberIndex);
int GIMMICK_OBJ_ELBOARD_CheckEntryZone(GateNewsEntry *entry, int zoneId);
int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(GateNewsEntry *entry);
extern ElboardLayout gElboardLayout;
extern u32 gElboardLabelMsgId[];        /* labelMsgId, inside gElboardLayout */
extern u16 gElboardLayoutAnimIndex[];        /* animIndex, inside gElboardLayout */
extern const char *gElboardLayoutTextureName[];  /* textureName, inside gElboardLayout */
extern const char *gElboardLayoutPaletteName[];  /* paletteName, inside gElboardLayout */
extern const int gElboardNoticeLanes[];  /* lanes of the notice list: 2, 3, 4, 5 */
extern u16 gElboardPlaceTable[1];       /* places looked up in the table: {0x71} */
extern u8 gElboardPlaceKinds[3];        /* kinds that qualify: {6, 7, 8} */
extern const char gElboardFileName[]; /* "gimmick_obj_elboard.c", the __FILE__ string of this unit */


/*
 * Put a message on the board and remember its kind in the gate work (the
 * pending list is saved with the gate state, so the board refills the same
 * way after a reload). A notice (kind 8) also clears its event flag when the
 * table asks for it.
 */
void GIMMICK_OBJ_ELBOARD_AddMessage(GateWork *work, ElboardMessage *msg, int kind, GateNewsEntry *entry)
{
    GIMMICK_OBJ_ELBOARD_AddLine(work->board, msg);
    if (kind == GATE_MESSAGE_TYPE_NEWS)
        FIELD_GIMMICK_GATE_LogMessage(work, kind, entry->eventFlag);
    else
        FIELD_GIMMICK_GATE_LogMessage(work, kind, 0);
    if (kind == GATE_MESSAGE_TYPE_NEWS && entry->clearsFlagWhenShown == 1) {
        ZONEDATA_ResetEventFlag(GAME_DATA_GetEventWork(work->gameData), (unsigned short)entry->eventFlag);
    }
}


void GIMMICK_OBJ_ELBOARD_FillMessages(GateWork *work)
{
    if (FIELD_GIMMICK_GATE_HasMessagesToShow(work) == 1) {
        GIMMICK_OBJ_ELBOARD_FillSavedListMessages(work);
        return;
    }
    if (func_021F3D24(work) != 0) {
        GIMMICK_OBJ_ELBOARD_FillNoticeMessages(work);
        return;
    }
    GIMMICK_OBJ_ELBOARD_FillDefaultMessages(work);
}


void GIMMICK_OBJ_ELBOARD_FillDefaultMessages(GateWork *work)
{
    if (GIMMICK_OBJ_ELBOARD_GetLineCount(work->board) == 0) {
        GateBoardRecord *record = work->record;

        if (record != 0 && record->enabled != 0) {
            GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(work);
            GIMMICK_OBJ_ELBOARD_AddDateMessage(work);
            GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(work);
            GIMMICK_OBJ_ELBOARD_AddDailyMessage1(work);
            GIMMICK_OBJ_ELBOARD_AddDailyMessage2(work);
            GIMMICK_OBJ_ELBOARD_AddDailyMessage3(work);
            GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(work);
        }
    }
}


void GIMMICK_OBJ_ELBOARD_FillSavedListMessages(GateWork *work)
{
    if (GIMMICK_OBJ_ELBOARD_GetLineCount(work->board) == 0) {
        GateBoardRecord *record = work->record;

        if (record != 0 && record->enabled != 0) {
            GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(work);
            GIMMICK_OBJ_ELBOARD_AddDateMessage(work);
            GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(work);
            GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(work);
            GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(work);
        }
    }
}


void GIMMICK_OBJ_ELBOARD_FillNoticeMessages(GateWork *work)
{
    if (GIMMICK_OBJ_ELBOARD_GetLineCount(work->board) == 0) {
        if (work->newsList != 0) {
            GateBoardRecord *record = work->record;

            if (record != 0 && record->enabled != 0) {
                GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(work);
                GIMMICK_OBJ_ELBOARD_AddDateMessage(work);
                GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(work);
                GIMMICK_OBJ_ELBOARD_AddNoticeMessages(work);
                GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(work);
            }
        }
    }
}


void GIMMICK_OBJ_ELBOARD_AddDateMessage(GateWork *work)
{
    struct { RtcDate date; ElboardMessage msg; } locals;
    struct WordSet *wordSet;

    wordSet = GF_FONT_Create_EC64(work->heapId);
    RTC_GetDate(&locals.date);
    func_0201EFA4(wordSet, 2, locals.date.year, 2, 2, 1);
    func_0201F230(wordSet, 0, locals.date.month);
    func_0201EFA4(wordSet, 1, locals.date.day, 2, 0, 1);
    locals.msg.animIndex = gElboardLayout.animIndex[0];
    locals.msg.textureName = gElboardLayout.textureName[0];
    locals.msg.paletteName = gElboardLayout.paletteName[0];
    locals.msg.arcId = 2;
    locals.msg.fileId = 0x26;
    locals.msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dateMsgId;
    locals.msg.wordSet = wordSet;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &locals.msg, 1, 0);
    WORDSET_DeleteStrbufED04(wordSet);
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
void GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(GateWork *work)
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

    GIMMICK_OBJ_ELBOARD_CollectHighlights(work, &highlights);
    bufLen = 0x100;
    words = WORDSET_Create(4, bufLen, work->heapId);
    placeNames = func_02045B38(0, 2, 0x59, work->heapId);
    boardText = func_02045B38(0, 2, 0x26, work->heapId);
    for (i = 0; i < 4; i++) {
        if (highlights.placeId[i] == ELBOARD_NO_PLACE)
            continue;
        kindIndex = highlights.kind[i];
        placeName = func_02045EC0(placeNames, ZONEDATA_GetPlaceNameId(highlights.placeId[i]));
        labelText = func_02045EC0(boardText, gElboardLabelMsgId[kindIndex]);
        pairWords = WORDSET_Create(2, bufLen, work->heapId);
        pairTemplate = func_02045EC0(boardText, 0xc0);
        pairText = STRBUF_Create(0x40, work->heapId);
        func_0201EE0C(pairWords, 0, placeName, 0, 1, 0);
        func_0201EE0C(pairWords, 1, labelText, 0, 1, 0);
        func_0201F250(pairWords, pairText, pairTemplate);
        STRBUF_Delete(pairTemplate);
        WORDSET_DeleteStrbufED04(pairWords);
        func_0201EE0C(words, i, pairText, 0, 1, 0);
        STRBUF_Delete(placeName);
        STRBUF_Delete(labelText);
        STRBUF_Delete(pairText);
    }
    MSGDATA_Delete(boardText);
    MSGDATA_Delete(placeNames);
    switch (GIMMICK_OBJ_ELBOARD_CountHighlights(&highlights)) {
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
    msg.animIndex = gElboardLayout.animIndex[1];
    msg.textureName = gElboardLayout.textureName[1];
    msg.paletteName = gElboardLayout.paletteName[1];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = msgId;
    msg.wordSet = words;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 2, 0);
    WORDSET_DeleteStrbufED04(words);
}


/* Message about the place the player came from (skipped for place 0xFFFF). */
void GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(GateWork *work)
{
    ElboardMessage msg;
    int placeId;
    struct WordSet *words;
    struct MsgData *placeNames;
    struct Strbuf *placeName;

    placeId = FIELD_ENCOUNT_GetSwarmZoneId(work->gameData);
    if (placeId == 0xFFFF)
        return;
    if (placeId == 0x159 && GAME_DATA_GetSeason(work->gameData) == 3)
        return;
    words = GF_FONT_Create_EC64(work->heapId);
    placeNames = func_02045B38(0, 2, 0x59, work->heapId);
    placeName = func_02045EC0(placeNames, ZONEDATA_GetPlaceNameId(placeId));
    func_0201EE0C(words, 0, placeName, 0, 1, 0);
    STRBUF_Delete(placeName);
    MSGDATA_Delete(placeNames);
    msg.animIndex = gElboardLayout.animIndex[2];
    msg.textureName = gElboardLayout.textureName[2];
    msg.paletteName = gElboardLayout.paletteName[2];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->newsMsgId;
    msg.wordSet = words;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 3, 0);
    WORDSET_DeleteStrbufED04(words);
}


/* Daily line 1: the message is picked by the weekday. */
void GIMMICK_OBJ_ELBOARD_AddDailyMessage1(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    RTC_GetDate(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[0]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[1]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    }
    msg.animIndex = gElboardLayout.animIndex[3];
    msg.textureName = gElboardLayout.textureName[3];
    msg.paletteName = gElboardLayout.paletteName[3];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 4, 0);
}


/* Daily line 2: same weekday pick, one entry further in the daily table. */
void GIMMICK_OBJ_ELBOARD_AddDailyMessage2(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    RTC_GetDate(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[7]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[1]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    }
    msg.animIndex = gElboardLayout.animIndex[4];
    msg.textureName = gElboardLayout.textureName[4];
    msg.paletteName = gElboardLayout.paletteName[4];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 5, 0);
}


/* Daily line 3: same weekday pick, two entries further in the daily table. */
void GIMMICK_OBJ_ELBOARD_AddDailyMessage3(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    RTC_GetDate(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[8]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[5]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[2]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[6]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[3]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[7]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->dayMsgId[4]; break;
    }
    msg.animIndex = gElboardLayout.animIndex[5];
    msg.textureName = gElboardLayout.textureName[5];
    msg.paletteName = gElboardLayout.paletteName[5];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 6, 0);
}


/* Weekly line: one message per weekday, Monday first. */
void GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(GateWork *work)
{
    ElboardMessage msg;
    RtcDate date;

    RTC_GetDate(&date);
    switch (date.week) {
    case 0: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[6]; break;
    case 1: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[0]; break;
    case 2: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[1]; break;
    case 3: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[2]; break;
    case 4: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[3]; break;
    case 5: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[4]; break;
    case 6: msg.msgId = ELBOARD_RECORD_PARAMS(work->record)->weekMsgId[5]; break;
    }
    msg.animIndex = gElboardLayout.animIndex[6];
    msg.textureName = gElboardLayout.textureName[6];
    msg.paletteName = gElboardLayout.paletteName[6];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.wordSet = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 7, 0);
}


/* Message with the ids stored in the save (up to six), one word-set entry each. */
void GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(GateWork *work)
{
    ElboardMessage msg;
    u32 savedIds[6];
    int savedCount;
    struct WordSet *words;
    int i;
    int msgId;

    words = GF_FONT_Create_EC64(GIMMICK_OBJ_ELBOARD_GetHeapId(work->board));
    if (FIELD_GIMMICK_GATE_IsExtraSaveListOn(work))
        FIELD_GIMMICK_GATE_ReadExtraSaveValues(work, savedIds, &savedCount);
    else
        FIELD_GIMMICK_GATE_ReadSaveBlockValues(work, savedIds, &savedCount);
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
        WORDSET_Callback(words, i, savedIds[i]);
    func_0201F02C(words, 6, GAME_DATA_GetMyStatus(work->gameData));
    msg.animIndex = gElboardLayout.animIndex[3];
    msg.textureName = gElboardLayout.textureName[3];
    msg.paletteName = gElboardLayout.paletteName[3];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = msgId;
    msg.wordSet = words;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, 9, 0);
    WORDSET_DeleteStrbufED04(words);
}

void GIMMICK_OBJ_ELBOARD_AddNoticeMessages(GateWork *work)
{
    GateNewsEntry *entry;

    entry = FIELD_GIMMICK_GATE_FindNewsEntry(work);
    switch (entry->kind) {
    case GATE_NEWS_KIND_SINGLE:
        GIMMICK_OBJ_ELBOARD_AddNoticeMessage(work, entry, 3);
        break;
    case GATE_NEWS_KIND_LIST:
        GIMMICK_OBJ_ELBOARD_AddNoticeList(work);
        break;
    }
}


/* Put one notice on the board, on the given lane of the layout table. */
void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(GateWork *work, GateNewsEntry *entry, int lane)
{
    ElboardMessage msg;

    msg.animIndex = gElboardLayoutAnimIndex[lane];
    msg.textureName = gElboardLayoutTextureName[lane];
    msg.paletteName = gElboardLayoutPaletteName[lane];
    msg.arcId = 2;
    msg.fileId = 0x26;
    msg.msgId = entry->messageId;
    msg.wordSet = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(work, &msg, GATE_MESSAGE_TYPE_NEWS, entry);
}

/*
 * lever: Post-increment in the table subscript schedules the counter update before the call.
 */
void GIMMICK_OBJ_ELBOARD_AddNoticeList(GateWork *work)
{
    int i;
    GateNewsEntry *entry;

    i = 0;
    entry = FIELD_GIMMICK_GATE_FindListNewsEntry(work);
    while (entry && i < 4) {
        GIMMICK_OBJ_ELBOARD_AddNoticeMessage(work, entry, gElboardNoticeLanes[i++]);
        entry = FIELD_GIMMICK_GATE_FindListNewsEntry(work);
    }
}

/*
 * Number of used place slots. The kind byte is compared with 0xFFFF, so the
 * second test is always true (as in the original).
 */
int GIMMICK_OBJ_ELBOARD_CountHighlights(ElboardHighlights *highlights)
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
void GIMMICK_OBJ_ELBOARD_ClearHighlights(ElboardHighlights *highlights)
{
    int i;

    for (i = 0; i < 4; i++) {
        highlights->placeId[i] = ELBOARD_NO_PLACE;
        highlights->kind[i] = 0xFF;
    }
}


/* Two highlights at most: first the G-Power place, then the table places, else the gate defaults. */
void GIMMICK_OBJ_ELBOARD_CollectHighlights(GateWork *work, ElboardHighlights *out)
{
    ElboardHighlights fromTable;
    ElboardHighlights fromGPower;
    int count, j, k;

    count = 0;
    GIMMICK_OBJ_ELBOARD_ClearHighlights(out);
    GIMMICK_OBJ_ELBOARD_CollectTableHighlights(work, &fromTable);
    GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight(work, &fromGPower);
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
        out->kind[k] = FIELDMAP_QueryIssSwitch(work->fieldMap, out->placeId[k]);
}


/*
 * The one-trip outer loop survives only because its int counter is compared
 * against an unsigned (sizeof) bound: `i < 1` or an unsigned counter is
 * folded away as a single pass. Tables: gElboardPlaceTable = {0x0071} (u16),
 * gElboardPlaceKinds = {6,7,8} (u8). FIELDMAP_QueryIssSwitch returns int (its own file); the
 * u8 local is what emits the lsls/lsrs #24.
 */
void GIMMICK_OBJ_ELBOARD_CollectTableHighlights(GateWork *work, ElboardHighlights *out)
{
    int i, j, count;

    GIMMICK_OBJ_ELBOARD_ClearHighlights(out);
    count = 0;
    for (i = 0; i < sizeof(gElboardPlaceTable) / sizeof(gElboardPlaceTable[0]); i++) {
        u16 placeId = gElboardPlaceTable[i];
        u8 kind = FIELDMAP_QueryIssSwitch(work->fieldMap, placeId);

        for (j = 0; j < sizeof(gElboardPlaceKinds); j++) {
            if (kind == gElboardPlaceKinds[j]) {
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
void GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight(GateWork *work, ElboardHighlights *out)
{
    struct EncounterState *encounter;
    int slot;
    int kind;
    int placeId;

    encounter = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(work->gameData));
    GIMMICK_OBJ_ELBOARD_ClearHighlights(out);
    if (MOVE_POKEMON_HasActiveEntry(encounter)) {
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
        placeId = MOVE_POKEMON_GetEntryZoneId(encounter, (unsigned char)slot);
        if (placeId != 0xFFFF) {
            out->placeId[0] = placeId;
            out->kind[0] = kind;
        }
    }
}


/* Script command: run the camera event of the gate board (SE 0x547 first). */
int GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent(struct ScriptContext *ctx, struct ScrCmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    int frames;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    frames = (int)SCRIPT_WORK_ReadWorkValue(ctx, cmdWork);
    GFL_USE_PlaySeDefaultVolume(0x547);
    SCRIPT_SYS_CallEvent(scriptWork, GIMMICK_OBJ_ELBOARD_CreateCameraEvent(gameSystem, fieldMap, frames));
    return 1;
}


GimmickObjElboard *GIMMICK_OBJ_ELBOARD_Create(ElboardConfig *config)
{
    int i;
    GimmickObjElboard *board;

    board = func_02030734(config->heapId, 0x1c, 0, gElboardFileName, 0x60);
    i = 0;
    board->heapId = config->heapId;
    board->lineCount = i;
    board->lineCapacity = config->lineCapacity;
    board->leadChars = config->leadChars;
    board->trailChars = config->trailChars;
    board->render = config->render;
    board->scroll = i;
    board->lines = func_02030734(config->heapId, config->lineCapacity * 4, 0, gElboardFileName, 0x6d);
    board->startRequest = func_02030734(config->heapId, config->lineCapacity * 4, 0, gElboardFileName, 0x6f);
    for (i = 0; i < config->lineCapacity; i++) {
        board->lines[i] = 0;
        board->startRequest[i] = 0;
    }
    board->startRequest[0] = 1;
    board->font = GF_FONT_Create(0x17, 0, 0, 0, board->heapId);
    return board;
}

void GIMMICK_OBJ_ELBOARD_AddLine(GimmickObjElboard *board, const ElboardMessage *msg)
{
    if (board->lineCapacity > board->lineCount) {
        board->lines[board->lineCount] = GIMMICK_OBJ_ELBOARD_CreateLine(board, msg, board->lineCount);
        board->lineCount++;
    }
}

void GIMMICK_OBJ_ELBOARD_Delete(GimmickObjElboard *board)
{
    int i;

    GF_FONT_Delete(board->font);
    for (i = 0; i < board->lineCount; i++)
        GIMMICK_OBJ_ELBOARD_DeleteLine(board->lines[i]);
    func_020307B0(board->lines);
    func_020307B0(board->startRequest);
    func_020307B0(board);
}

void GIMMICK_OBJ_ELBOARD_Advance(GimmickObjElboard *board, int step)
{
    int i;

    for (i = 0; i < board->lineCount; i++)
        GIMMICK_OBJ_ELBOARD_UpdateLine(board, board->lines[i], step);
    board->scroll += step;
}


/*
 * int getter, u16 getter, u8 getter.
 */
int GIMMICK_OBJ_ELBOARD_GetScroll(GimmickObjElboard *board)
{
    return board->scroll;
}


int GIMMICK_OBJ_ELBOARD_GetHeapId(GimmickObjElboard *board)
{
    return board->heapId;
}


int GIMMICK_OBJ_ELBOARD_GetLineCount(GimmickObjElboard *board)
{
    return board->lineCount;
}


/*
 * Jump the board to a scroll position. The lines run one after another in a
 * loop of `totalFrames` frames; each line gets its own local time, which
 * decides if it plays and if the next line was already started.
 */
void GIMMICK_OBJ_ELBOARD_SetScroll(GimmickObjElboard *board, int scroll)
{
    int *lineStart;
    int *localFrame;
    int i, totalFrames, frame, j, flag;
    ElboardLine *line;

    frame = scroll >> 12;
    totalFrames = 0;
    /* heap id with the high bit set: the temporary arrays come from the other end of the heap */
    lineStart = (int *)func_02030734((u16)((board->heapId & 0x7FFF) | 0x8000), board->lineCount * 4, 0, gElboardFileName, 0x11A);
    localFrame = (int *)func_02030734((u16)((board->heapId & 0x7FFF) | 0x8000), board->lineCount * 4, 0, gElboardFileName, 0x11C);
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
        G3D_SYSTEM_SetObjectAnimeFrame(line->render, line->animIndex, &line->elapsed);
        if (line->isPlaying) {
            G3D_SYSTEM_EnableObjectAnime(line->render, line->animIndex);
        } else {
            G3D_SYSTEM_DisableObjectAnime(line->render, line->animIndex);
        }
    }
    if (board->lineCount != 0 && frame == 0) {
        line = board->lines[0];
        line->isPlaying = 1;
        G3D_SYSTEM_EnableObjectAnime(line->render, line->animIndex);
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
ElboardLine *GIMMICK_OBJ_ELBOARD_CreateLine(GimmickObjElboard *board, const ElboardMessage *msg, int lineIndex)
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

    line = func_02030734(board->heapId, 0x24, 0, gElboardFileName, 0x180);
    msgData = func_02045B38(0, (u16)msg->arcId, (u16)msg->fileId, board->heapId);
    if (msg->wordSet != 0) {
        str = STRBUF_Create(0xC0, board->heapId);
        tmp = func_02045EC0(msgData, msg->msgId);
        func_0201F250(msg->wordSet, str, tmp);
        func_020307B0(tmp);
    } else {
        str = func_02045EC0(msgData, msg->msgId);
    }
    width = func_0201D304(str, board->font, 1);
    line->text = EL_SCOREBOARD_CreateLamp(G3D_SYSTEM_GetRenderTexRes(G3D_SYSTEM_GetObjectRender(board->render)), msg->textureName, msg->paletteName, str, board->leadChars * 14, 1, board->heapId);
    func_020307B0(str);
    MSGDATA_Delete(msgData);
    animFrames = G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(board->render, msg->animIndex))->resAnm->numFrame << 12;
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
    G3D_SYSTEM_DisableObjectAnime(line->render, line->animIndex);
    G3D_SYSTEM_ResetObjectAnimeFrame(line->render, line->animIndex);
    return line;
}

void GIMMICK_OBJ_ELBOARD_DeleteLine(ElboardLine *line)
{
    EL_SCOREBOARD_DeleteLamp(line->text);
    func_020307B0(line);
}

void GIMMICK_OBJ_ELBOARD_StartLine(ElboardLine *line)
{
    if (line->isPlaying != 1) {
        line->isPlaying = 1;
        line->nextStarted = 0;
        line->elapsed = 0;
        G3D_SYSTEM_EnableObjectAnime(line->render, line->animIndex);
        G3D_SYSTEM_ResetObjectAnimeFrame(line->render, line->animIndex);
    }
}


/* One step of a line: advance it while it plays, start the next line, or start itself on request. */
void GIMMICK_OBJ_ELBOARD_UpdateLine(GimmickObjElboard *board, ElboardLine *line, int step)
{
    int newElapsed;

    if (line->isPlaying == 1) {
        EL_SCOREBOARD_TickLamp(line->text);
        G3D_SYSTEM_IncObjectAnimeFrame(line->render, line->animIndex, step);
        newElapsed = line->elapsed + step;
        line->elapsed = newElapsed;
        if (line->nextStartTime < newElapsed) {
            if (line->nextStarted != 1) {
                board->startRequest[(line->lineIndex + 1) % board->lineCount] = 1;
                line->nextStarted = 1;
            }
        }
        if (line->endTime < line->elapsed) {
            GIMMICK_OBJ_ELBOARD_StopLine(line);
            return;
        }
    } else {
        if (board->startRequest[line->lineIndex] == 1) {
            GIMMICK_OBJ_ELBOARD_StartLine(line);
            board->startRequest[line->lineIndex] = 0;
        }
    }
}

void GIMMICK_OBJ_ELBOARD_StopLine(ElboardLine *line)
{
    if (line->isPlaying == 1) {
        line->isPlaying = 0;
        G3D_SYSTEM_DisableObjectAnime(line->render, line->animIndex);
        G3D_SYSTEM_ResetObjectAnimeFrame(line->render, line->animIndex);
    }
}

/* Read one record of the gate table (arc 0xAE, 0x7C bytes). */
int GIMMICK_OBJ_ELBOARD_ReadGateInfo(void *dst, u32 archiveId, u32 memberIndex)
{
    ARC_TOOL_ReadMemberRange(dst, archiveId, memberIndex, 0, 0x7c);
    return 1;
}


/*
 * Camera event of the board: save the camera, move it to a fixed view of the
 * board (the view depends on the way the gate faces), wait for a direction key
 * or B, then move the camera back. Returns 1 when done.
 */
int GIMMICK_OBJ_ELBOARD_CameraEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    GateCameraEventWork *work = eventWork;
    struct FieldMap *fieldMap;
    struct FieldCamera *camera;
    struct FieldTaskManager *taskManager;
    u32 keys;

    fieldMap = work->fieldMap;
    camera = FIELDMAP_GetCamera(fieldMap);
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    switch (*seq) {
    case 0:
        work->savedPitch = FIELD_CAMERA_GetPitch(camera);
        work->savedYaw = FIELD_CAMERA_GetYaw(camera);
        work->savedDistance = FIELD_CAMERA_GetDistance(camera);
        FIELD_CAMERA_GetTargetShift(camera, &work->savedTarget);
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

        switch (FIELD_GIMMICK_GATE_GetBoardFacing(fieldMap)) {
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
        distanceTask = FIELD_TASK_CreateCameraDistanceTween(fieldMap, work->frames, distance);
        pitchTask = FIELD_TASK_CreateCameraPitchTween(fieldMap, work->frames, pitch);
        yawTask = FIELD_TASK_CreateCameraYawTween(fieldMap, work->frames, yaw);
        targetTask = FIELD_TASK_CreateCameraTargetTween(fieldMap, work->frames, &target);
        FIELD_TASK_MANAGER_AddTask(taskManager, distanceTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, pitchTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, yawTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, targetTask, 0);
        (*seq)++;
        break;
    }
    case 2:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager))
            (*seq)++;
        break;
    case 3:
        keys = KEY_GetTrg();
        /* Left, Right, Down or B */
        if ((keys & 0x20) || (keys & 0x10) || (keys & 0x80) || (keys & 2))
            (*seq)++;
        break;
    case 4: {
        struct FieldTask *distanceTask;
        struct FieldTask *pitchTask;
        struct FieldTask *yawTask;
        struct FieldTask *targetTask;

        distanceTask = FIELD_TASK_CreateCameraDistanceTween(fieldMap, work->frames, work->savedDistance);
        pitchTask = FIELD_TASK_CreateCameraPitchTween(fieldMap, work->frames, work->savedPitch);
        yawTask = FIELD_TASK_CreateCameraYawTween(fieldMap, work->frames, work->savedYaw);
        targetTask = FIELD_TASK_CreateCameraTargetTween(fieldMap, work->frames, &work->savedTarget);
        FIELD_TASK_MANAGER_AddTask(taskManager, distanceTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, pitchTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, yawTask, 0);
        FIELD_TASK_MANAGER_AddTask(taskManager, targetTask, 0);
        (*seq)++;
        break;
    }
    case 5:
        if (FIELD_TASK_MANAGER_IsEmpty(taskManager))
            (*seq)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

struct GameEvent *GIMMICK_OBJ_ELBOARD_CreateCameraEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int frames)
{
    struct GameEvent *event;
    GateCameraEventWork *work;

    event = func_020122C0(gameSystem, 0, GIMMICK_OBJ_ELBOARD_CameraEventMain, 0x20);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->frames = frames;
    return event;
}

/* Read one record of the notice table (arc 0xA6, 0x24 bytes). */
int GIMMICK_OBJ_ELBOARD_ReadGateEntry(void *dst, u32 archiveId, u32 memberIndex)
{
    ARC_TOOL_ReadMemberRange(dst, archiveId, memberIndex, 0, 0x24);
    return 1;
}

/*
 * True when the notice names no zone (four GATE_NEWS_ZONE_ANY entries) or
 * names the given zone.
 */
int GIMMICK_OBJ_ELBOARD_CheckEntryZone(GateNewsEntry *entry, int zoneId)
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
int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(GateNewsEntry *entry)
{
    if (entry->specialPowerId == 0)
        return 1;
    if (entry->specialPowerId == GPOWER_GetSpecialPowerId())
        return 1;
    return 0;
}

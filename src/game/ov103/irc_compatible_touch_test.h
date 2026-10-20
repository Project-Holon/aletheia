#ifndef GAME_OV103_IRC_COMPATIBLE_TOUCH_TEST_H
#define GAME_OV103_IRC_COMPATIBLE_TOUCH_TEST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_compatible_touch_test.c, prototypes copied from their definitions. */

struct IrcTouchWork;
struct IrcMarkers;
struct TcbTask;
struct IrcTouchSprites;
struct IrcScene3d;
struct IrcModel;
struct IrcDrawingExchange;
struct IrcDrawingPacket;
struct IrcTouchPoint;
struct IrcTrail;
struct IrcTrailSprite;
struct IrcStroke;
typedef struct IrcTouchWork IrcTouchWork;
typedef struct IrcMarkers IrcMarkers;
typedef struct IrcTouchSprites IrcTouchSprites;
typedef struct IrcScene3d IrcScene3d;
typedef struct IrcModel IrcModel;
typedef struct IrcDrawingExchange IrcDrawingExchange;
typedef struct IrcDrawingPacket IrcDrawingPacket;
typedef struct IrcTouchPoint IrcTouchPoint;
typedef struct IrcTrail IrcTrail;
typedef struct IrcTrailSprite IrcTrailSprite;
typedef struct IrcStroke IrcStroke;

#include "../ov101/compatible_irc_sys_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../ov102/irc_text_system_types.h"
#include "../ov102/irc_screen_types.h"

int IRC_COMPATIBLE_TOUCH_TEST_ProcInit(void *proc, int unused, IrcSecondTestArgs *args);
int IRC_COMPATIBLE_TOUCH_TEST_ProcExit(void *proc, int unused, int unused2, IrcTouchWork *work);
int IRC_COMPATIBLE_TOUCH_TEST_ProcMain(void *unused, u32 *state, int unused2, IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_InitScene(IrcTouchWork *work, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitScene(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(IrcTouchWork *work);
void *IRC_COMPATIBLE_TOUCH_TEST_GetSprite(IrcTouchWork *work, int index);
void *IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(IrcTouchWork *work);
IrcMarkers *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankTask(struct TcbTask *taskId, void *work);
void IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(u32 *charRange, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(u32 *charRange);
void IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(void *unused);
void IRC_COMPATIBLE_TOUCH_TEST_InitSprites(IrcTouchSprites *sprites, const void *config, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(IrcTouchSprites *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(void *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(void *sprites);
void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor(IrcTouchSprites *sprites, u32 index);
void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit(IrcTouchSprites *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_Init3D(IrcScene3d *scene, int heapId);
void IRC_COMPATIBLE_TOUCH_TEST_Exit3D(IrcScene3d *scene);
void IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(IrcScene3d *scene);
void IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(IrcScene3d *scene);
IrcModel *IRC_COMPATIBLE_TOUCH_TEST_Get3DModel(IrcScene3d *scene, u16 index);
void IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay(void);
void IRC_COMPATIBLE_TOUCH_TEST_InitModel(IrcModel *model, void *arc, const u16 *fileIds, int polygonId, int unused);
void IRC_COMPATIBLE_TOUCH_TEST_ExitModel(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_DrawModel(IrcModel *model);
u32 IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(IrcModel *model, VecFx32 *position);
void IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(IrcModel *model, int active);
u32 IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_InitText(IrcTextSystem *text, int skipFont, u32 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitText(IrcTextSystem *text);
u32 IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(IrcTextSystem *text);
void IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(IrcWindow *win);
int IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(IrcWindow *win, IrcTextSystem *text);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(IrcWindow *win, IrcTextSystem *text, int msgId, const IrcCompatibleProfile *profile, s16 x, s16 y, int heapId);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(IrcWindow *win, IrcTouchWork *work, int msgId);
void IRC_COMPATIBLE_TOUCH_TEST_ClearWindow(IrcWindow *win);
void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleScoring(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_InitExchange(IrcDrawingExchange *exchange, IrcSys *sys);
void IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(IrcDrawingExchange *exchange);
int IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(IrcDrawingExchange *exchange, const IrcDrawingPacket *packet);
void IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(IrcDrawingExchange *exchange, IrcDrawingPacket *out);
void IRC_COMPATIBLE_TOUCH_TEST_ExchangeReceiveCallback(u32 netId, u32 size, u32 data, IrcDrawingExchange *exchange, void *handle);
IrcDrawingPacket *IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer(u32 netId, IrcDrawingExchange *exchange);
void IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(IrcMarkers *markers, IrcScene3d *scene, int unused);
void IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(IrcMarkers *markers);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(IrcMarkers *markers);
void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(IrcMarkers *markers, int index, int active);
void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(IrcMarkers *markers, int index, int x, int y);
int IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(const u32 *rect, IrcTouchPoint *out);
int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(const u32 *rect, IrcTouchPoint *out);
u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(IrcTouchWork *work);
u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke(const IrcTouchPoint *refOrigin, const IrcTouchPoint *ref, const IrcTouchPoint *curOrigin, const IrcTouchPoint *cur);
void IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock(void *arc, int memberId, int bgLayer, int tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 palette, int compressed, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(int mask, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrail(IrcTrail *trail, IrcTouchWork *work, int mode, int paletteOffset, int firstSprite, u8 kind);
void IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(IrcTrail *trail);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(IrcTrailSprite *sprite, void *actor, int paletteOffset, u8 kind);
void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(IrcStroke *stroke);
int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(IrcStroke *stroke, const u32 *rect);
int IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(IrcStroke *stroke);
/* END mkheaders: generated region */

#endif

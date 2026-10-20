#ifndef GAME_OV102_IRC_COMPATIBLE_MENU_H
#define GAME_OV102_IRC_COMPATIBLE_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_compatible_menu.c, prototypes copied from their definitions. */

struct IrcMenuWork;
struct TcbTask;
struct IrcBgSetup;
struct IrcMenuSprites;
struct IrcButtons;
struct IrcButtonRow;
struct IrcScrollEffect;
struct IrcFloater;
struct IrcFloaters;
struct IrcLinearStep;
typedef struct IrcMenuWork IrcMenuWork;
typedef struct IrcBgSetup IrcBgSetup;
typedef struct IrcMenuSprites IrcMenuSprites;
typedef struct IrcButtons IrcButtons;
typedef struct IrcButtonRow IrcButtonRow;
typedef struct IrcScrollEffect IrcScrollEffect;
typedef struct IrcFloater IrcFloater;
typedef struct IrcFloaters IrcFloaters;
typedef struct IrcLinearStep IrcLinearStep;

#include "../ov101/compatible_irc_sys_types.h"
#include "../types.h"
#include "../ov102/irc_text_system_types.h"
#include "../ov102/irc_screen_types.h"

int IRC_COMPATIBLE_MENU_ProcInit(void *proc, int unused, IrcMenuArgs *args);
int IRC_COMPATIBLE_MENU_ProcExit(void *proc, int unused, int unused2, IrcMenuWork *work);
int IRC_COMPATIBLE_MENU_ProcMain(void *unused, u32 *state, int unused2, IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_InitDisplay(IrcMenuWork *work, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitDisplay(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_DrawSprites(IrcMenuWork *work);
void *IRC_COMPATIBLE_MENU_GetSprite(IrcMenuWork *work, int index);
void *IRC_COMPATIBLE_MENU_GetSpriteUnit(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_VBlankTask(struct TcbTask *taskId, void *work);
void IRC_COMPATIBLE_MENU_InitBackgrounds(IrcBgSetup *bg, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitBackgrounds(IrcBgSetup *bg);
void IRC_COMPATIBLE_MENU_BackgroundVBlank(struct TcbTask *taskId, void *work);
void IRC_COMPATIBLE_MENU_InitSprites(IrcMenuSprites *sprites, const void *config, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitSprites(IrcMenuSprites *sprites);
void IRC_COMPATIBLE_MENU_DrawSpriteSystem(void);
void IRC_COMPATIBLE_MENU_VBlankSpriteSystem(void *sprites);
void *IRC_COMPATIBLE_MENU_SpriteSetGetActor(IrcMenuSprites *sprites, int index);
void *IRC_COMPATIBLE_MENU_SpriteSetGetUnit(IrcMenuSprites *sprites);
void IRC_COMPATIBLE_MENU_InitText(IrcTextSystem *text, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitText(IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_UpdateTextQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetFont(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetPrintQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetMsgData(IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId);
void IRC_COMPATIBLE_MENU_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitWindow(IrcWindow *win);
int IRC_COMPATIBLE_MENU_UpdateWindow(IrcWindow *win, IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y);
void IRC_COMPATIBLE_MENU_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId);
void IRC_COMPATIBLE_MENU_SetFinished(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_HandleStartTests(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleChoice(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleFinish(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleOpen(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleQuit(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleCheckLink(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_UpdateScene(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_InitButtons(IrcButtons *buttons, int bgLayer, const IrcButtonRow *rows, int count, IrcTextSystem *text, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitButtons(IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_UpdateButtons(IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_SetButtonsEnabled(IrcButtons *buttons, u32 enabled);
int IRC_COMPATIBLE_MENU_IsButtonPressed(IrcButtons *buttons);
int IRC_COMPATIBLE_MENU_PollChoice(IrcButtons *buttons, int *out);
void IRC_COMPATIBLE_MENU_ResetButtonPalettes(IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_ButtonCallback(u16 value, int flag, IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_InitScrollEffect(IrcScrollEffect *effect, u32 unused);
void IRC_COMPATIBLE_MENU_ExitScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_UpdateScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_StartScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_InitFloater(IrcFloater *floater, void *actor, int isSpecial, int unused);
void IRC_COMPATIBLE_MENU_ExitFloater(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_UpdateFloater(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_ResetFloaterPath(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_InitFloaters(IrcFloaters *floaters, IrcMenuWork *work, void *records, int unused);
void IRC_COMPATIBLE_MENU_ExitFloaters(IrcFloaters *floaters);
void IRC_COMPATIBLE_MENU_UpdateFloaters(IrcFloaters *floaters);
void IRC_COMPATIBLE_MENU_InitLinearStep(IrcLinearStep *step, int start, int target, int duration);
int IRC_COMPATIBLE_MENU_StepLinear(IrcLinearStep *step);
/* END mkheaders: generated region */

#endif

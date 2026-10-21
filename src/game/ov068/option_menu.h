#ifndef GAME_OV068_OPTION_MENU_H
#define GAME_OV068_OPTION_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of option_menu.c, prototypes copied from their definitions. */

struct Proc;
struct ClactActor;
struct Unit;
struct BmpWindow;
struct Task;
struct GfFont;
struct MsgBank;
struct TaskList;
struct PrintSys;
struct TaskMenuRes;
struct GameData;
struct Config;

#include "../ov068/option_menu_types.h"
#include "../types.h"

int OPTION_MENU_Init(struct Proc *proc, int *seq, OptionMenuArgs *args);
int OPTION_MENU_Exit(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
int OPTION_MENU_Main(struct Proc *proc, int *seq, void *args, OptionMenuWork *work);
void OPTION_MENU_InitScreen(OptionMenuScreen *screen, u16 heapId);
void OPTION_MENU_ExitScreen(OptionMenuScreen *screen);
void OPTION_MENU_UpdateScreen(OptionMenuScreen *screen);
struct ClactActor *OPTION_MENU_GetScreenSpriteActor(OptionMenuScreen *screen, int index);
struct Unit *OPTION_MENU_GetScreenSpriteUnit(OptionMenuScreen *screen);
struct BmpWindow *OPTION_MENU_GetScreenWindow(OptionMenuScreen *screen, int index);
void OPTION_MENU_RestartScreenBlink(OptionMenuScreen *screen);
void OPTION_MENU_ScreenTaskMain(struct Task *task, OptionMenuScreen *screen);
void OPTION_MENU_InitGfx(OptionMenuGfx *gfx, u16 heapId);
void OPTION_MENU_ExitGfx(OptionMenuGfx *gfx);
void OPTION_MENU_UpdateGfxBlink(OptionMenuGfx *gfx);
struct BmpWindow *OPTION_MENU_GetGfxWindow(OptionMenuGfx *gfx, int index);
void OPTION_MENU_CreateLabelWindows(OptionMenuGfx *gfx);
void OPTION_MENU_RestartGfxBlink(OptionMenuGfx *gfx);
void OPTION_MENU_FlushGfx(OptionMenuGfx *gfx);
void BLINK_PALANM_BlendStep(u16 *outColor, u16 *angle, int step, u32 paletteIndex, u8 slot, u16 color0, u16 color1);
void OPTION_MENU_InitSprites(OptionMenuSprites *sprites, const void *res, u32 heapId);
void OPTION_MENU_ExitSprites(OptionMenuSprites *sprites);
void OPTION_MENU_UpdateSprites(OptionMenuSprites *sprites);
void OPTION_MENU_DrawSprites(OptionMenuSprites *sprites);
struct ClactActor *OPTION_MENU_GetSpriteActor(OptionMenuSprites *sprites, int index);
struct Unit *OPTION_MENU_GetSpriteUnit(OptionMenuSprites *sprites);
void OPTION_MENU_InitInput(OptionMenuInput *input, int heapId);
void OPTION_MENU_ExitInput(OptionMenuInput *input);
void OPTION_MENU_ReadInput(OptionMenuInput *input);
int OPTION_MENU_GetInputCommand(const OptionMenuInput *input);
void OPTION_MENU_GetInputPoint(const OptionMenuInput *input, int which, OptionMenuPoint *out);
void OPTION_MENU_InitTextBox(OptionMenuTextBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct PrintSys *printSys, u16 heapId);
void OPTION_MENU_ExitTextBox(OptionMenuTextBox *box);
void OPTION_MENU_PrintText(OptionMenuTextBox *box, u32 messageId, u32 wait, u32 useStream);
void OPTION_MENU_PrintTextFromBank(OptionMenuTextBox *box, struct MsgBank *msgBank, u32 messageId, u32 wait, u32 useStream);
int OPTION_MENU_IsTextDone(OptionMenuTextBox *box);
void OPTION_MENU_InitButtons(OptionMenuButtons *buttons, struct Unit *unit, struct GfFont *font, struct PrintSys *printSys, struct MsgBank *msgBank, struct TaskMenuRes *menuRes, struct GameData *gameData, u16 heapId);
void OPTION_MENU_ExitButtons(OptionMenuButtons *buttons);
void OPTION_MENU_UpdateButtons(OptionMenuButtons *buttons, const OptionMenuInput *input, const OptionMenuList *list);
void OPTION_MENU_UpdateButtonWindows(OptionMenuButtons *buttons);
int OPTION_MENU_GetButtonChoice(OptionMenuButtons *buttons, int *choice);
u32 OPTION_MENU_IsButtonFinished(OptionMenuButtons *buttons);
void OPTION_MENU_ResetButtons(OptionMenuButtons *buttons);
void OPTION_MENU_CreateButtonWindows(OptionMenuButtons *buttons, u16 heapId);
int OPTION_MENU_HasButtonFocusChanged(OptionMenuButtons *buttons);
void OPTION_MENU_InitList(OptionMenuList *list, u16 mainLayer, u16 subLayer, OptionMenuScreen *screen, const OptionSettings *settings, u32 heapId);
void OPTION_MENU_ExitList(OptionMenuList *list);
void OPTION_MENU_UpdateList(OptionMenuList *list, const OptionMenuInput *input, OptionMenuTextBox *helpText, OptionMenuScreen *screen, OptionMenuButtons *buttons);
void OPTION_MENU_ClearListHighlight(OptionMenuList *list, OptionMenuScreen *screen);
int OPTION_MENU_GetListCursor(const OptionMenuList *list);
void OPTION_MENU_GetListSettings(const OptionMenuList *list, OptionSettings *out);
void OPTION_MENU_RedrawList(OptionMenuList *list, int unused);
void OPTION_MENU_SetListButtonMode(OptionMenuList *list, u8 value);
void OPTION_MENU_DrawList(OptionMenuList *list, int highlight);
void OPTION_MENU_ScrollList(OptionMenuList *list, int delta, int min, int max);
void OPTION_MENU_SelectChoiceAtTouch(OptionMenuList *list, const OptionMenuPoint *touch);
void OPTION_MENU_ApplySoundMode(OptionMenuList *list, u32 soundMode, u32 force);
void OPTION_MENU_StepSelectedSetting(OptionMenuList *list, int delta);
int OPTION_MENU_GetRowAtTouch(OptionMenuList *list, const OptionMenuPoint *touch);
void OPTION_MENU_ShiftInputTrail(OptionMenuList *list);
void OPTION_MENU_InitMessageBox(OptionMenuMessageBox *box, struct BmpWindow *window, struct GfFont *font, struct MsgBank *msgBank, struct TaskList *taskList, struct TaskMenuRes *menuRes, struct PrintSys *printSys, u16 heapId);
void OPTION_MENU_ExitMessageBox(OptionMenuMessageBox *box);
void OPTION_MENU_UpdateMessageBox(OptionMenuMessageBox *box);
void OPTION_MENU_PrintDiscardPrompt(OptionMenuMessageBox *box, u32 wait);
u16 OPTION_MENU_GetMessageBoxAnswer(const OptionMenuMessageBox *box);
void OPTION_MENU_PrintHelpMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait);
void OPTION_MENU_PrintMessage(OptionMenuMessageBox *box, u32 messageId, u32 wait);
int OPTION_MENU_IsMessageDone(OptionMenuMessageBox *box);
void OPTION_MENU_InitSettings(OptionSettings *settings, struct Config *config);
void OPTION_MENU_ExitSettings(OptionSettings *settings);
void OPTION_MENU_WriteSettings(const OptionSettings *settings);
void OPTION_MENU_SelectChoice(OptionSettings *settings, int choiceIndex);
void OPTION_MENU_StepSetting(OptionSettings *settings, int row, int delta);
int OPTION_MENU_IsChoiceSelected(const OptionSettings *settings, int choiceIndex);
u32 OPTION_MENU_GetTextSpeedWait(const OptionSettings *settings);
int OPTION_MENU_TakeChangedSetting(OptionSettings *settings);
int OPTION_MENU_AreSettingsEqual(const OptionSettings *a, const OptionSettings *b);
void OPTION_MENU_InitRunner(OptionMenuRunner *runner, OptionMenuWork *work, OptionMenuStateFn callback);
void OPTION_MENU_ExitRunner(OptionMenuRunner *runner);
void OPTION_MENU_UpdateRunner(OptionMenuRunner *runner);
int OPTION_MENU_IsRunnerFinished(OptionMenuRunner *runner);
void OPTION_MENU_SetRunnerState(OptionMenuRunner *runner, OptionMenuStateFn callback);
void OPTION_MENU_FinishRunner(OptionMenuRunner *runner);
void OPTION_MENU_StateFadeIn(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateFadeOut(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateMain(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateDiscardPrompt(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateKeepSaved(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
void OPTION_MENU_StateApply(OptionMenuRunner *runner, u32 *state, OptionMenuWork *work);
int OPTION_MENU_IsPointInRect(const OptionMenuRect *rect, const OptionMenuPoint *point);
/* END mkheaders: generated region */

#endif

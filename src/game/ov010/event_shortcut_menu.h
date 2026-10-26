#ifndef GAME_OV010_EVENT_SHORTCUT_MENU_H
#define GAME_OV010_EVENT_SHORTCUT_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_shortcut_menu.c, prototypes copied from their definitions. */

struct GameSystem;
struct GameEvent;
struct FieldMap;
struct ShortcutMenuWork;
struct ShortcutLink;
struct ShortcutProcTask;
struct ShortcutHooks;
typedef struct ShortcutMenuWork ShortcutMenuWork;
typedef struct ShortcutLink ShortcutLink;
typedef struct ShortcutProcTask ShortcutProcTask;
typedef struct ShortcutHooks ShortcutHooks;

#include "../types.h"

int EVENT_SHORTCUT_MENU_HasShortcuts(struct GameSystem *gameSystem);
struct GameEvent *EVENT_SHORTCUT_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
int EVENT_SHORTCUT_MENU_MainEvent(struct GameEvent *event, int *seq, void *work);
int EVENT_SHORTCUT_MENU_ReturnEvent(struct GameEvent *event, int *seq, void *work);
int EVENT_SHORTCUT_MENU_ResolveShortcut(ShortcutLink *link, u32 shortcutId);
int EVENT_SHORTCUT_MENU_GetAvailBit(u32 shortcutId, u32 *availBit, u32 *isUnknownId);
void EVENT_SHORTCUT_MENU_OpenLink(int mode, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_CloseLink(ShortcutMenuWork *work, int *seq);
int EVENT_SHORTCUT_MENU_ResumeLinkHook(ShortcutLink *link, ShortcutMenuWork *work);
int EVENT_SHORTCUT_MENU_SuspendLinkHook(ShortcutLink *link, ShortcutMenuWork *work);
void *EVENT_SHORTCUT_MENU_OpenMessage(struct GameSystem *gameSystem, u32 messageIndex);
int EVENT_SHORTCUT_MENU_CheckPartyRibbon(ShortcutMenuWork *work);
struct GameEvent *EVENT_SHORTCUT_MENU_CreateProcEvent(ShortcutLink *link, u16 id);
int EVENT_SHORTCUT_MENU_ProcEventMain(struct GameEvent *event, int *seq, void *work);
int EVENT_SHORTCUT_MENU_CallResumeHook(ShortcutHooks *hooks);
int EVENT_SHORTCUT_MENU_CallSuspendHook(ShortcutHooks *hooks);
int EVENT_SHORTCUT_MENU_CallExitHook(ShortcutHooks *hooks);
/* END mkheaders: generated region */

#endif

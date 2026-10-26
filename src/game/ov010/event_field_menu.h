#ifndef GAME_OV010_EVENT_FIELD_MENU_H
#define GAME_OV010_EVENT_FIELD_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_field_menu.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;
struct ShortcutRequest;
struct FieldMenuWork;
typedef struct ShortcutRequest ShortcutRequest;
typedef struct FieldMenuWork FieldMenuWork;

#include "../types.h"

struct GameEvent *EVENT_FIELD_MENU_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
struct GameEvent *EVENT_FIELD_MENU_CreateForZone(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
int EVENT_FIELD_MENU_Main(struct GameEvent *event, int *seq, void *workArg);
u32 EVENT_FIELD_MENU_GetProcKindOfButton(u32 button);
int EVENT_FIELD_MENU_OnUpdate(ShortcutRequest *request, FieldMenuWork *work);
int EVENT_FIELD_MENU_OnClose(ShortcutRequest *request, FieldMenuWork *work);
int EVENT_FIELD_MENU_OnFinish(ShortcutRequest *request, FieldMenuWork *work);
/* END mkheaders: generated region */

#endif

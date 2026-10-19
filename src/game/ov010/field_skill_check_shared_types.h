#ifndef FIELD_SKILL_CHECK_SHARED_TYPES_H
#define FIELD_SKILL_CHECK_SHARED_TYPES_H

struct GameData;

struct GameSystem;

struct PlayerWork;

#include "../types.h"

struct GameEvent;

struct FieldMap;

typedef struct GameEvent *(*FieldLinkEventFn)(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

#endif

#ifndef FIELD_SKILL_CHECK_SHARED_TYPES_H
#define FIELD_SKILL_CHECK_SHARED_TYPES_H

struct GameData;

struct GameSystem;

struct PlayerWork;

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

struct GameEvent;

struct FieldMap;

typedef struct GameEvent *(*FieldLinkEventFn)(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

#endif

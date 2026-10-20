#ifndef GAME_ARM9_CURSOR_MOVE_H
#define GAME_ARM9_CURSOR_MOVE_H

/* Public functions of cursor_move.c, prototypes copied from their definitions. */

struct Cursor;
struct CursorEntry;
struct CursorVtbl;

#include "../types.h"

u32 CURSOR_MOVE_GetTableValue(u32 x);
u32 CURSOR_MOVE_GetTableGroup(u32 x);
u32 CURSOR_MOVE_GetTableKind(u32 x);
u32 CURSOR_MOVE_FindTableGroupIndex(u32 v);
struct Cursor *CURSOR_MOVE_Create(struct CursorEntry *entries, struct CursorVtbl *vt, u32 ctx, u32 state, u8 start, u16 heapId);
u32 CURSOR_MOVE_Delete(void *cursor);
void CURSOR_MOVE_EnableInput(struct Cursor *obj);
void CURSOR_MOVE_SetMode(struct Cursor *obj);
int CURSOR_MOVE_PollInput(struct Cursor *obj);
int CURSOR_MOVE_PollRepeatInput(struct Cursor *obj);
int CURSOR_MOVE_PollTouch(struct Cursor *obj, int *out);
u32 CURSOR_MOVE_GetNeighbour(const struct CursorEntry *entries, u32 idx, u32 type);
int CURSOR_MOVE_StartInput(struct Cursor *obj);
int CURSOR_MOVE_HandlePendingInput(struct Cursor *obj);
int CURSOR_MOVE_MoveCursor(struct Cursor *obj, u32 dir, int sel);
u8 CURSOR_MOVE_GetCurrent(struct Cursor *obj);
void CURSOR_MOVE_SetCurrent(struct Cursor *obj, u8 sel);
u32 CURSOR_MOVE_GetState(struct Cursor *obj);
void CURSOR_MOVE_SetState(struct Cursor *obj, u32 state);
void CURSOR_MOVE_ClearSkipBit(struct Cursor *obj, u32 idx);
void CURSOR_MOVE_SetSkipBit(struct Cursor *obj, u32 idx);
struct CursorEntry *CURSOR_MOVE_GetEntry(struct Cursor *obj, u32 idx);
int CURSOR_MOVE_IsWrapNeighbour(const struct CursorEntry *entry, u32 type);
int CURSOR_MOVE_TestSkipBit(const u32 *bitmap, u32 bit);

#endif

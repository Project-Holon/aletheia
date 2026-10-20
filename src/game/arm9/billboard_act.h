#ifndef GAME_ARM9_BILLBOARD_ACT_H
#define GAME_ARM9_BILLBOARD_ACT_H

/* Public functions of billboard_act.c, prototypes copied from their definitions. */

struct BbActSys;
struct BbBoard;
struct BbActSlot;
struct BbActEntry;
struct BbActRec;
struct BbActDesc;
struct BbActCmd;

#include "../types.h"

void BILLBOARD_ACT_Delete(struct BbActSys *sys);
struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys);
void BILLBOARD_ACT_InitSlot(struct BbActSlot *slot);
void BILLBOARD_ACT_ResetPlayback(struct BbActEntry *entry);
void BILLBOARD_ACT_InitEntry(struct BbActEntry *entry);
u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);
u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 boardId, u32 payload);
void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);
int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, u32 slot);
u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex);
u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 baseSlot, const struct BbActDesc *descs, u32 count, u32 mode);
void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count);
void BILLBOARD_ACT_UpdateEntries(struct BbActSys *sys);
void BILLBOARD_ACT_UpdateEntry(struct BbActSys *sys, struct BbActEntry *entry);
void BILLBOARD_ACT_UploadSlotFrame(struct BbActSys *sys, struct BbActSlot *slot, u32 frame);
u32 BILLBOARD_ACT_UploadSlotPalette(struct BbActSys *sys, struct BbActSlot *slot);
void BILLBOARD_ACT_Draw(struct BbActSys *sys, void *camera, void *light);
int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags);
int BILLBOARD_ACT_GetEntryFlags(struct BbActSys *sys, int entryIndex);
void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled);
void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, struct BbActCmd **cmdLists, u16 listCount);
void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex);
u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex);
void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor);
u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex);
int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int srcSlot);
int BILLBOARD_ACT_GetEntryElemId(struct BbActSys *sys, int entryIndex);
u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex);
u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *lastCommand);
int BILLBOARD_ACT_IsControlCommand(struct BbActCmd *cmd);
int BILLBOARD_ACT_RunControlCommand(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdEnd(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdSetList(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdLoop(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdJump(struct BbActEntry *entry, struct BbActCmd *cmd);

#endif

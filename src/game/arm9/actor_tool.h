#ifndef GAME_ARM9_ACTOR_TOOL_H
#define GAME_ARM9_ACTOR_TOOL_H

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of actor_tool.c, prototypes copied from their definitions. */

struct ActorTool;

#include "../types.h"

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count);
void ACTOR_TOOL_Delete(struct ActorTool *tool);
int ACTOR_TOOL_AllocRun(struct ActorTool *tool, int len, u32 bank);
void ACTOR_TOOL_FreeRun(struct ActorTool *tool, u32 start, u32 bank);
s32 ACTOR_TOOL_LoadChar(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
int ACTOR_TOOL_LoadCharSimple(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
u32 ACTOR_TOOL_LoadCharPalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
u32 ACTOR_TOOL_LoadCharSimplePalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
unsigned int ACTOR_TOOL_GetCharBlock(int tool, int charOffset, int bank);
void ACTOR_TOOL_FreeChar(struct ActorTool *tool, u32 charOffset, u32 bank);
/* END mkheaders: generated region */

#endif

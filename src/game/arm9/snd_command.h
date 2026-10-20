#ifndef GAME_ARM9_SND_COMMAND_H
#define GAME_ARM9_SND_COMMAND_H

#include "../types.h"

/* Sound command queue entry. */

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

void SND_CommandInit(void);
const SNDCommand *SND_RecvCommandReply(u32 flags);
SNDCommand *SND_AllocCommand(u32 flags);
void SND_PushCommand(SNDCommand *command);
BOOL SND_FlushCommand(u32 flags);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
BOOL SND_IsFinishedCommandTag(u32 tag);
int SND_CountFreeCommand(void);
int SND_CountReservedCommand(void);
int SND_CountWaitingCommand(void);
void PxiFifoCallback(int tag, u32 data, BOOL err);
void InitPXI(void);
void RequestCommandProc(void);
SNDCommand *AllocCommand(void);
BOOL IsCommandAvailable(void);

#endif

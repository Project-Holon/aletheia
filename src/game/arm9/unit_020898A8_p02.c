/*
 * file:     unit_020898A8_p02.c
 * unit:     yes
 * function: func_02089CD4, func_02089D40, func_02089D6C
 * address:  0x02089CD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_RecvCommandReply      0x02089978  arm
 *   RequestCommandProc        0x02089ED8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   sFreeList             0x0215146C  data
 */
typedef unsigned long u32;

typedef int BOOL;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

/* snd_command.o's .bss statics from sFreeList on, in their laid-out order */
typedef struct {
    SNDCommand *freeList;
    u32 finishedTag;
    SNDCommand *reserveList;
    SNDCommand *reserveListEnd;
    SNDCommand *freeListEnd;
    u32 unk14;
    int waitingCommandListQueueWrite;
    int waitingCommandListCount;
    u32 currentTag;
} SNDCommandState;

extern BOOL SND_IsFinishedCommandTag(u32 tag);
extern const void *SND_RecvCommandReply(u32 flags);
extern void RequestCommandProc(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
void func_02089CD4(u32 tag);
u32 func_02089D40(void);
BOOL func_02089D6C(u32 tag);
extern SNDCommandState sFreeList;


/*
 * sdk:      SND_WaitForCommandProc (snd_command.o)
 */
void func_02089CD4(u32 tag)
{
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    while (SND_RecvCommandReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    do {
        (void)SND_RecvCommandReply(1);
    } while (!SND_IsFinishedCommandTag(tag));
}



/*
 * sdk:      SND_GetCurrentCommandTag (snd_command.o)
 */
u32 func_02089D40(void)
{
    unsigned long bak_psr = OS_DisableInterrupts();
    u32 tag;

    if (sFreeList.reserveList == 0) {
        tag = sFreeList.finishedTag;
    } else {
        tag = sFreeList.currentTag;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return tag;
}



/*
 * sdk:      SND_IsFinishedCommandTag (snd_command.o)
 */
BOOL func_02089D6C(u32 tag)
{
    unsigned long bak_psr = OS_DisableInterrupts();
    BOOL result;

    if (tag > sFreeList.finishedTag) {
        if (tag - sFreeList.finishedTag < 0x80000000) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        if (sFreeList.finishedTag - tag < 0x80000000) {
            result = 1;
        } else {
            result = 0;
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return result;
}

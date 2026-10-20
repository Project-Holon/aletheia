#ifndef OV101_IRC_APPBAR_H
#define OV101_IRC_APPBAR_H
/*
 * Single-button bar of the infrared compatibility screens. Owner header: the
 * screens of ov102 to ov106 include it instead of declaring their own view.
 */
#include "../ov101/compatible_irc_sys_types.h"

struct TaskMenuState;
struct ClactActor;

/* Single-button bar of the infrared screens (96 bytes, heap allocated). */
typedef struct IrcAppBar {
    u8 *taskMenuWin;                   /* 0x00 button window */
    struct TaskMenuState *taskMenuRes; /* 0x04 button resources */
    struct ClactActor *actors[7];             /* 0x08 cell actors; slot 0 is the bar icon */
    u8 reserved[12];                   /* 0x24 */
    int paletteId;                     /* 0x30 */
    int charId;                        /* 0x34 */
    int cellAnimId;                    /* 0x38 */
    u32 layer;                         /* 0x3C screen layer */
    u8 unused40[4];                    /* 0x40 */
    int result;                        /* 0x44 -1 none, 1 button pressed */
    int prevResult;                    /* 0x48 */
    u8 unused4C[4];                    /* 0x4C */
    int state;                         /* 0x50 0 idle, 1 pressed, 2 done */
    u32 labelIndex;                    /* 0x54 */
    u16 heapId;                        /* 0x58 */
    u8 pad5A[2];                       /* 0x5A */
    int enabled;                       /* 0x5C */
} IrcAppBar;

IrcAppBar *IRC_APPBAR_Create(u32 unusedArg,void *clactUnit,u16 layer,u16 x,u8 paletteSlot,u32 unusedExtra,void *font,void *printQueue,u16 heapId);
void IRC_APPBAR_Delete(IrcAppBar *bar);
void IRC_APPBAR_Update(IrcAppBar *bar);
int IRC_APPBAR_GetResult(IrcAppBar *bar);
int IRC_APPBAR_IsPressed(IrcAppBar *bar);
void IRC_APPBAR_Reset(IrcAppBar *bar);
int IRC_APPBAR_IsBusy(IrcAppBar *bar);
void IRC_APPBAR_SetEnabled(IrcAppBar *bar,int enable);
void IRC_APPBAR_SetActive(IrcAppBar *bar,int enable);
void IRC_APPBAR_SetLabel(IrcAppBar *bar,unsigned labelIndex);
void IRC_APPBAR_LoadResources(IrcAppBar *bar,unsigned charOffset,int unusedChoice,int unusedExtra,int unusedX,u8 paletteSlot,unsigned heapId);
void IRC_APPBAR_ReleaseResources(IrcAppBar *bar);
void IRC_APPBAR_CreateActor(IrcAppBar *bar,unsigned clactUnit,int unusedArg,unsigned anim,u8 priority,u16 heapId);
extern char gIrcAppBarFileName[];

#include "../types.h"
void IRC_APPBAR_DeleteActors(void *bar);

#endif

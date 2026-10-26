/*
 * file:     irc_appbar.c
 * unit:     yes
 * function: IRC_APPBAR_Create, IRC_APPBAR_Delete, IRC_APPBAR_Update, IRC_APPBAR_GetResult, IRC_APPBAR_IsPressed, IRC_APPBAR_Reset, IRC_APPBAR_IsBusy, IRC_APPBAR_SetEnabled, IRC_APPBAR_SetActive, IRC_APPBAR_SetLabel, IRC_APPBAR_LoadResources, IRC_APPBAR_ReleaseResources, IRC_APPBAR_CreateActor, IRC_APPBAR_DeleteActors
 * address:  0x021B70DC
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   IRC_APPBAR_DeleteActors 0x021B73E8 thumb ov101
 *   APP_TASKMENU_WIN_IsTouch  0x0202824C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   gIrcAppBarFileName 0x021B7550 data a1
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   BG_SYS_GetPriority  0x020416D4  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 *   BG_SYS_SetPlaneVisible  0x02040588  arm  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 *   MSGDATA_AllocString  0x02045EC0  arm  arm9
 *   ARC_TOOL_CreateHandle  0x020490F4  arm  arm9
 */
struct MsgBank;
struct Rec;
struct U16Vec;
struct TaskMenuState;
struct ClactActor;
#include "irc_appbar.h"

typedef enum { SIDE_ZERO, SIDE_ONE } Side;

typedef struct { void *str; u16 color,pad; u32 flag; } MsgDesc;

#include "../types.h"

typedef struct { struct Strbuf *data; u16 tag,pad; unsigned flag; } LabelDesc;


#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
struct PrintQueue;
struct GFont;
struct TaskMenuRes;
#include "../arm9/app_taskmenu.h"
#include "../arm9/bg_sys.h"
#include "../arm9/msgdata.h"
struct Strbuf;
struct TaskMenuItem;
struct TaskMenuWin;
#include "../arm9/strbuf.h"
extern void IRC_APPBAR_DeleteActors(void *);
#include "../arm9/gfl_use.h"
#include "../arm9/arc_tool.h"
/* Original prototypes (docs/ORIGINAL_BUGS.tsv): ../arm9/clact.h */
#ifdef __MWERKS__
#define CLACT_RegisterCharacter CLACT_RegisterCharacter_header
#define CLACT_RegisterPaletteEx CLACT_RegisterPaletteEx_header
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
#undef CLACT_RegisterCharacter
s32 CLACT_RegisterCharacter(void *archive, u32 file_idx, u32 compressed, u32 vram_mode, u32 heap_id);
#undef CLACT_RegisterPaletteEx
s32 CLACT_RegisterPaletteEx(void *archive, u32 file_idx, u32 vram_mode, u16 vram_offset, u16 first_color, u16 color_count, u32 heap_id);
#endif
struct ClactActor;

/*
 * lever: distinct enum first/choice values preserve branch-local setup and saved-register allocation.
 * prototype: own 27F60 fixes layer/x/heap as u16; stack x/heap forward unchanged without truncation.
 * GFL_HEAP_Alloc 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * IRC_APPBAR_LoadResources 0x021B732C thumb ov101
 * APP_TASKMENU_RES_Create 0x02027F60 thumb
 * BG_SYS_GetPriority 0x020416D4 arm
 * IRC_APPBAR_CreateActor 0x021B739C thumb ov101
 * MSGDATA_CreateFromArchive 0x02045B38 arm
 * MSGDATA_AllocString 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * STRBUF_Delete 0x02045808 arm
 * MSGDATA_Delete 0x02045C04 arm
 * gIrcAppBarFileName 0x021B7550 data a1
 */
IrcAppBar *IRC_APPBAR_Create(u32 unusedArg,void *clactUnit,u16 layer,u16 x,u8 paletteSlot,u32 unusedExtra,void *font,void *printQueue,u16 heapId)
{
    Side side=SIDE_ZERO;
    MsgDesc desc;
    IrcAppBar *bar;
    void *bank;
    Side choice,first;
    bar=GFL_HEAP_Alloc(heapId,sizeof(*bar),0,gIrcAppBarFileName,125);
    MI_CpuFill8(bar,0,sizeof(*bar));
    bar->layer=layer;
    bar->result=side-1;
    bar->prevResult=side-1;
    bar->labelIndex=side;
    bar->heapId=heapId;
    bar->enabled=1;
    if(layer>=4) { side=1; first=1; choice=4; }
    else { first=0; choice=0; }
    IRC_APPBAR_LoadResources(bar,first,choice,unusedExtra,x,paletteSlot,heapId);
    bar->taskMenuRes=(struct TaskMenuState *)APP_TASKMENU_RES_Create(layer,x,(struct GFont *)font,(struct PrintQueue *)printQueue,heapId);
    IRC_APPBAR_CreateActor(bar,clactUnit,unusedArg,side,BG_SYS_GetPriority(layer),heapId);
    bank=MSGDATA_CreateFromArchive(0,2,49,heapId);
    MI_CpuFill8(&desc,0,sizeof(desc));
    desc.color=0x39e3;
    desc.str=MSGDATA_AllocString(bank,8);
    desc.flag=1;
    bar->taskMenuWin=(u8 *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)bar->taskMenuRes,(struct TaskMenuItem *)(&desc),19,21,13,heapId);
    STRBUF_Delete(desc.str);
    MSGDATA_Delete(bank);
    return bar;
}

void IRC_APPBAR_Delete(IrcAppBar *bar) { APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)bar->taskMenuWin); IRC_APPBAR_DeleteActors(bar); APP_TASKMENU_RES_Delete((struct TaskMenuRes *)bar->taskMenuRes); IRC_APPBAR_ReleaseResources(bar); GFL_HEAP_Free(bar); }

void IRC_APPBAR_Update(IrcAppBar *bar)
{
    if (bar->enabled != 0) {
        switch (bar->state) {
        case 0:
            bar->result = -1;
            if (APP_TASKMENU_WIN_IsTouch((struct TaskMenuWin *)bar->taskMenuWin)) {
                GFL_USE_PlaySeDefaultVolume(0x551);
                APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)bar->taskMenuWin, 1);
                bar->state = 1;
            }
            break;
        case 1:
            if (APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)bar->taskMenuWin)) {
                APP_TASKMENU_WIN_ResetDecide((struct TaskMenuWin *)bar->taskMenuWin);
                APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)bar->taskMenuWin, 0);
                bar->state = 2;
            }
            break;
        case 2:
            bar->result = 1;
            break;
        }
        APP_TASKMENU_WIN_Update((struct TaskMenuWin *)bar->taskMenuWin);
    }
}

int IRC_APPBAR_GetResult(IrcAppBar *bar) { return bar->result; }

/*
 * note: Parent-cleared leaf for ov102 021B81B0. Getter starts immediately after separately filed 4-byte 021B7250; 14 bytes of code followed by two zero alignment bytes before 021B7264.
 */
int IRC_APPBAR_IsPressed(IrcAppBar *bar) { if(bar->state>0) return 1; return 0; }

/*
 * APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 * APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
void IRC_APPBAR_Reset(IrcAppBar *bar) {
 APP_TASKMENU_WIN_ResetDecide((struct TaskMenuWin *)bar->taskMenuWin);
 APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)bar->taskMenuWin,0);
 bar->state=0;
}

int IRC_APPBAR_IsBusy(IrcAppBar *bar) { if(bar->state) return 1; return 0; }

/*
 * BG_SYS_SetPlaneVisible 0x02040588 arm
 */
void IRC_APPBAR_SetEnabled(IrcAppBar *bar,int enable) {
 bar->enabled=enable;
 BG_SYS_SetPlaneVisible((u8)bar->layer,(u8)enable);
}

void IRC_APPBAR_SetActive(IrcAppBar *bar,int enable) {
 bar->enabled=enable;
 bar->state=0;
}

/*
 * APP_TASKMENU_WIN_Delete 0x02028148 thumb
 * MSGDATA_CreateFromArchive 0x02045B38 arm
 * MI_CpuFill8 0x02082BCC arm
 * MSGDATA_AllocString 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * STRBUF_Delete 0x02045808 arm
 * MSGDATA_Delete 0x02045C04 arm
 */
void IRC_APPBAR_SetLabel(IrcAppBar *bar,unsigned labelIndex) {
 struct MsgBank *bank;
 LabelDesc desc;
 if(labelIndex==bar->labelIndex) return;
 APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)bar->taskMenuWin);
 bank=MSGDATA_CreateFromArchive(0,2,0x31,bar->heapId);
 MI_CpuFill8(&desc,0,sizeof(LabelDesc));
 desc.tag=0x39e3;
 desc.data=MSGDATA_AllocString(bank,labelIndex+8);
 desc.flag=1;
 bar->taskMenuWin=(u8 *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)bar->taskMenuRes,(struct TaskMenuItem *)(&desc),0x13,0x15,0xd,bar->heapId);
 STRBUF_Delete(desc.data);
 MSGDATA_Delete(bank);
 bar->labelIndex=labelIndex; bar->state=0; bar->result=-1;
}

/*
 * ARC_TOOL_CreateHandle 0x020490F4 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 */
/* The two register calls pass the heap id unmasked (likely original mismatch, narrow-arg in docs/DEBT.tsv). */
void IRC_APPBAR_LoadResources(IrcAppBar *bar,unsigned charOffset,int unusedChoice,int unusedExtra,int unusedX,u8 paletteSlot,unsigned heapId) {
 void *arc;
 arc=ARC_TOOL_CreateHandle(0x5e,heapId);
 bar->paletteId=CLACT_RegisterPaletteEx(arc,0x29,charOffset,paletteSlot<<5,0,1,heapId);
 bar->charId=CLACT_RegisterCharacter(arc,0x28,0,charOffset,heapId);
 bar->cellAnimId=CLACT_RegisterCellAnim(arc,0x27,0x26,heapId);
 ARC_TOOL_DeleteHandle(arc);
}

void IRC_APPBAR_ReleaseResources(IrcAppBar *bar) { CLACT_ReleaseCellAnim(bar->cellAnimId); CLACT_ReleaseCharacter(bar->charId); CLACT_ReleasePalette(bar->paletteId); }

void IRC_APPBAR_CreateActor(IrcAppBar *bar,void *clactUnit,int unusedArg,unsigned anim,u8 priority,u16 heapId) {
 struct ActorInitParam tmpl;
 MI_CpuFill8(&tmpl,0,8);
 tmpl.x=128; tmpl.y=96; tmpl.anim_seq=0; tmpl.bg_priority=priority+1;
 bar->actors[0]=CLACT_CreateActor(clactUnit,bar->charId,bar->paletteId,bar->cellAnimId,&tmpl,anim,heapId);
}

/*
 * Deletes every actor of the bar's actor array.
 * CLACT_DeleteActor 0x0204B3B4 arm
 */
void IRC_APPBAR_DeleteActors(void *bar)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (((IrcAppBar *)bar)->actors[i])
            CLACT_DeleteActor(((IrcAppBar *)bar)->actors[i]);
    }
}

/*
 * file:     mus_shot_info.c
 * unit:     yes
 * function: MUSICAL_SHOT_INFO_Create, MUSICAL_SHOT_INFO_Delete, MUSICAL_SHOT_INFO_Main, MUSICAL_SHOT_INFO_IsFinished, MUSICAL_SHOT_INFO_InitGraphics, MUSICAL_SHOT_INFO_InitBgLayer, MUSICAL_SHOT_INFO_InitWindows, MUSICAL_SHOT_INFO_DeleteWindows, MUSICAL_SHOT_INFO_PrintMessageStream, MUSICAL_SHOT_INFO_PrintMessageQueued, MUSICAL_SHOT_INFO_OpenYesNoMenu
 * address:  0x021F4284
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_shot_sys.c, musical_mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MUSICAL_SHOT_INFO_Create 0x021F4284 thumb ov112
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   MUSICAL_SHOT_INFO_Delete 0x021F4300 thumb ov112
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_SHOT_INFO_Main 0x021F4350 thumb ov112
 *   MUSICAL_SHOT_INFO_IsFinished 0x021F44E8 thumb ov112
 *   BMP_WIN_Delete 0x020452E8 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021F8394 0x021F8394 data a1
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   MUSICAL_SAVE_NoOp 0x0200A640 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   TCBL_Main 0x020310C4 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "mus_shot_info_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"
struct BmpWin;

#include "../arm9/bmp_win.h"
struct GfFont;

#include "../arm9/gf_font.h"

#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"


#ifdef __MWERKS__
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetPlaneVisible
#undef BG_SYS_FreeSlot
void BG_SYS_SetPlaneVisible(u32, unsigned char);
void BG_SYS_FreeSlot(u32);
#endif



struct TaskMenuRes;

struct Bank;

struct Obj;

struct TaskMenuState;

struct Actor;

struct PrintSys;

struct Rec3;

struct TaskMenu;

struct Tcbl;

struct S02031140;

struct TaskMenuTmpl;


typedef struct { u8 b[8]; } MusShotInfoBox;

typedef struct MusShotInfoItem { void *data; u16 value; u16 pad; int zero; } MusShotInfoItem;

typedef struct MusShotInfoMenu { u32 heap; u8 count; u8 pad[3]; MusShotInfoItem *items; int zero; u8 a,b,c,d; } MusShotInfoMenu;

/* A word used both as a pointer handle and as a raw integer by different views. */
typedef union { void *ptr; u32 val; } McssPtrWord;

/*
 * The MUSICAL_MCSS work object. MUSICAL_SHOT_INFO_Create allocates 0x5C bytes for it.
 * Main, Delete, CreateUnits, InitWindows, DeleteWindows, PrintStream, PrintQue
 * and OpenMenu all read this one record.
 */
typedef struct MusicalMcssWork {
    u16 heap;               /* 0x00 */
    u16 pad_2;              /* 0x02 */
    u32 state;              /* 0x04 */
    u8 counter;             /* 0x08 */
    u8 pad_9[3];            /* 0x09 */
    u32 mode;               /* 0x0C */
    void *src;              /* 0x10 */
    void *dst;              /* 0x14 */
    McssPtrWord tcbl;       /* 0x18 text control block handle */
    McssPtrWord win;        /* 0x1C window bitmap */
    McssPtrWord font;       /* 0x20 */
    McssPtrWord printStream;/* 0x24 */
    McssPtrWord msgBank;    /* 0x28 */
    McssPtrWord strbuf;     /* 0x2C */
    u32 queActive;          /* 0x30 */
    McssPtrWord timeIcon;   /* 0x34 */
    McssPtrWord printQue;   /* 0x38 */
    void *taskMenu;         /* 0x3C */
    u32 taskMenuRes;        /* 0x40 */
    void *musComm;          /* 0x44 */
    void *unit;             /* 0x48 */
    u32 palette;            /* 0x4C */
    u32 character;          /* 0x50 */
    u32 cellAnim;           /* 0x54 */
    void *actor;            /* 0x58 */
} MusicalMcssWork;

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"



#include "../arm9/msgdata.h"

struct Strbuf;

#include "../arm9/strbuf.h"





struct PrintQueue;
struct GFont;

#include "../arm9/app_taskmenu.h"

#include "../arm9/net.h"



#include "../arm9/clact.h"






#include "../arm9/gfl_use.h"

#include "../arm9/wipe.h"
struct TaskMenuWork;





#include "../arm9/musical_save.h"

#include "../arm9/mi_memory.h"

#include "../ov132/mus_comm_func.h"


#include "../arm9/net_err.h"

#include "../arm9/key.h"

#include "../arm9/touchpanel.h"



struct TextPrinter;

#include "../arm9/printsys.h"



struct TcblList;
struct TimeIcon;

#include "../arm9/time_icon.h"
struct TcblSystem;

#include "../arm9/tcbl.h"






#include "../arm9/app_icon.h"













#include "../arm9/bmp_menuwork.h"








#include "../arm9/msg_speed.h"



struct TaskMenuInitWork;


void *MUSICAL_SHOT_INFO_Create(u32 a, u32 b, u32 c, u32 d, u16 heap);

void MUSICAL_SHOT_INFO_Delete(u8 *p);

void MUSICAL_SHOT_INFO_Main(u8 *p);

int MUSICAL_SHOT_INFO_IsFinished(u32 *p);

void MUSICAL_SHOT_INFO_InitGraphics(u8 *p);

void MUSICAL_SHOT_INFO_InitBgLayer(const void *a,u32 b,u32 c);

void MUSICAL_SHOT_INFO_InitWindows(u8 *p);

void MUSICAL_SHOT_INFO_DeleteWindows(u8 *p);

void MUSICAL_SHOT_INFO_PrintMessageStream(u8 *p,u32 index);

void MUSICAL_SHOT_INFO_PrintMessageQueued(u8 *p,u32 index);

void MUSICAL_SHOT_INFO_OpenYesNoMenu(u8 *p);

extern char d_021F8394[];

extern const MusShotInfoBox d_021F8290;

extern const u32 d_021F8298[];

extern const u32 d_021F82B8[];

extern const u32 d_021F82D8[];

void *MUSICAL_SHOT_INFO_Create(u32 a, u32 b, u32 c, u32 d, u16 heap)
{
    u8 *p = GFL_HEAP_Alloc(*(u16 *)&heap, 0x5c, 1, d_021F8394, 0x8d);
    *(u16 *)p = *(u16 *)&heap;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x44) = d;
    *(u32 *)(p + 0x2c) = 0;
    *(u8 *)(p + 8) = 0;
    if (c == 1) *(u32 *)(p + 4) = 0; else *(u32 *)(p + 4) = 1;
    MUSICAL_SHOT_INFO_InitGraphics(p);
    MUSICAL_SHOT_INFO_InitWindows(p);
    *(u32 *)(p + 0x40) = (uptr)APP_TASKMENU_RES_Create(4, 12, *(struct GFont **)(p + 0x20), *(struct PrintQueue **)(p + 0x38), *(u16 *)p);
    GFL_NET_RefreshWmIconAtTopRight(0, *(u16 *)&heap);
    BG_SYS_SetSubPlaneVisible(16, 1);
    return p;
}

/*
 * extent: trailing two-byte padding at 0x021F434E.
 */
void MUSICAL_SHOT_INFO_Delete(u8 *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(((MusicalMcssWork *)p)->taskMenuRes));
    if (((MusicalMcssWork *)p)->mode==0) {
        CLACT_ReleasePalette(((MusicalMcssWork *)p)->palette);
        CLACT_ReleaseCharacter(((MusicalMcssWork *)p)->character);
        CLACT_ReleaseCellAnim(((MusicalMcssWork *)p)->cellAnim);
        CLACT_DeleteActor((struct ClactActor *)((struct Actor *)(((MusicalMcssWork *)p)->actor)));
    }
    CLACT_DeleteUnit((struct Unit *)((struct Bank *)(((MusicalMcssWork *)p)->unit)));
    MUSICAL_SHOT_INFO_DeleteWindows(p);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    GFL_HEAP_Free(p);
}

/*
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 */
void MUSICAL_SHOT_INFO_Main(u8 *p)
{
    u8 v;
    switch (((MusicalMcssWork *)p)->state) {
    case 0:
        ((MusicalMcssWork *)p)->state=1;
        GFL_USE_PlaySeDefaultVolume(1583);
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(((MusicalMcssWork *)p)->mode==1) {
                MUSICAL_SHOT_INFO_PrintMessageStream(p,3);
                ((MusicalMcssWork *)p)->state=2;
            } else ((MusicalMcssWork *)p)->state=5;
        }
        break;
    case 2:
        if(!((MusicalMcssWork *)p)->printStream.ptr) {
            MUSICAL_SHOT_INFO_OpenYesNoMenu(p);
            ((MusicalMcssWork *)p)->state=3;
        }
        break;
    case 3:
        APP_TASKMENU_UpdateMenu((TaskMenuWork *)(((MusicalMcssWork *)p)->taskMenu));
        if(APP_TASKMENU_IsFinish((TaskMenuWork *)(((MusicalMcssWork *)p)->taskMenu))==1) {
            v=APP_TASKMENU_GetCursorPos((const TaskMenuWork *)(*(u8 * *)&((MusicalMcssWork *)p)->taskMenu));
            APP_TASKMENU_CloseMenu(((MusicalMcssWork *)p)->taskMenu);
            if(v==0) MI_CpuCopy8(((MusicalMcssWork *)p)->src,MUSICAL_SAVE_NoOp(((MusicalMcssWork *)p)->dst),432);
            if(*(int *)&((MusicalMcssWork *)p)->musComm) {
                ((MusicalMcssWork *)p)->state=4;
                MUS_COMM_FUNC_SetTimingSync(*(int *)&((MusicalMcssWork *)p)->musComm,71);
                MUSICAL_SHOT_INFO_PrintMessageQueued(p,6);
            } else ((MusicalMcssWork *)p)->state=7;
        } else if(GFL_NET_ERR_GetErrorLevel()!=0) {
            APP_TASKMENU_CloseMenu(((MusicalMcssWork *)p)->taskMenu);
            ((MusicalMcssWork *)p)->state=7;
        }
        break;
    case 4:
        if(MUS_COMM_FUNC_CheckTimingSync(((MusicalMcssWork *)p)->musComm,71)==1) ((MusicalMcssWork *)p)->state=7;
        else if(GFL_NET_ERR_GetErrorLevel()!=0) ((MusicalMcssWork *)p)->state=7;
        break;
    case 5:
        if((KEY_GetTrg()&2)||!TOUCHPANEL_HitTrg((const TouchHitTable *)&d_021F8290)) {
            GFL_USE_PlaySeDefaultVolume(1361);
            ((MusicalMcssWork *)p)->state=6;
            CLACT_SetActorAnimSeq(((MusicalMcssWork *)p)->actor,9);
            CLACT_SetActorAutoAnim(((MusicalMcssWork *)p)->actor,1);
        }
        break;
    case 6:
        if(!CLACT_IsActorAnimActive(((MusicalMcssWork *)p)->actor)) ((MusicalMcssWork *)p)->state=7;
        break;
    case 7: break;
    }
    if(((MusicalMcssWork *)p)->printStream.ptr&&PRINTSYS_PrintStreamGetState(((MusicalMcssWork *)p)->printStream.ptr)==2) {
        PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
        ((MusicalMcssWork *)p)->printStream.ptr=0;
    }
    PRINTSYS_QUE_Main(((MusicalMcssWork *)p)->printQue.ptr);
    if(((MusicalMcssWork *)p)->queActive==1&&PRINTSYS_QUE_IsFinished(((MusicalMcssWork *)p)->printQue.ptr)==1) {
        ((MusicalMcssWork *)p)->queActive=0;
        *(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr=(u8 *)TIME_ICON_CreateNode(*(struct TcblList **)&((MusicalMcssWork *)p)->tcbl.ptr,((MusicalMcssWork *)p)->win.ptr,15,16,((MusicalMcssWork *)p)->heap);
        BMP_WIN_TransferChars(((MusicalMcssWork *)p)->win.ptr);
    }
    TCBL_Main(((MusicalMcssWork *)p)->tcbl.ptr);
    (*(volatile u8 *)&((MusicalMcssWork *)p)->counter)++;
    if(*(volatile u8 *)&((MusicalMcssWork *)p)->counter>1) {
        *(volatile u8 *)&((MusicalMcssWork *)p)->counter=0;
        BG_SYS_ChangeScroll(7,1,1);
        BG_SYS_ChangeScroll(7,5,1);
    }
}

int MUSICAL_SHOT_INFO_IsFinished(u32 *p) { if(p[1]==7) return 1; return 0; }

/*
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 */
void MUSICAL_SHOT_INFO_InitGraphics(u8 *p)
{
    MusShotInfoDesc d;
    void *t;
    u32 v;
    u32 w;
    MUSICAL_SHOT_INFO_InitBgLayer(d_021F8298,4,0);
    MUSICAL_SHOT_INFO_InitBgLayer(d_021F82B8,6,0);
    MUSICAL_SHOT_INFO_InitBgLayer(d_021F82D8,7,0);
    ((MusicalMcssWork *)p)->unit=CLACT_CreateUnit(8,0,((MusicalMcssWork *)p)->heap);
    CLACT_SetUnitDefaultRenderer(((MusicalMcssWork *)p)->unit);
    BG_SYS_SetSubPlaneVisible(16,1);
    t=ARC_TOOL_CreateHandle((unsigned int)46,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((uptr)t),4,4,0,0,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadBgCharFromHandle((void *)((uptr)t),7,7,0,0,0,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)((uptr)t),12,7,0,0,0,((MusicalMcssWork *)p)->heap);
    ARC_TOOL_DeleteHandle(t);
    if (((MusicalMcssWork *)p)->mode==0) {
        t=ARC_TOOL_CreateHandle((unsigned int)APP_ICON_GetArchiveId(),((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadPaletteFromHandleWhole((void *)((uptr)t),APP_ICON_GetStatusAnimFileId(),4,288,32,((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadBgCharFromHandle((void *)((uptr)t),APP_ICON_GetStatusFrameFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)((uptr)t),APP_ICON_GetStatusDataFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        BG_SYS_FillTileMap(6,0,21,32,3,9);
        BG_SYS_PushTile(6);
        ((MusicalMcssWork *)p)->palette=CLACT_RegisterPaletteEx((void *)((uptr)t),APP_ICON_GetMoveKindPaletteFileId(),1,0,0,3,((MusicalMcssWork *)p)->heap);
        ((MusicalMcssWork *)p)->character=CLACT_RegisterCharacter((void *)((uptr)t),APP_ICON_GetMoveKindAnimFileId(),0,1,((MusicalMcssWork *)p)->heap);
        v=APP_ICON_GetStatusCellFileId(0);
        w=APP_ICON_GetStatusPaletteFileId(0);
        ((MusicalMcssWork *)p)->cellAnim=CLACT_RegisterCellAnim((void *)((uptr)t),v,w,((MusicalMcssWork *)p)->heap);
        ARC_TOOL_DeleteHandle(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((MusicalMcssWork *)p)->actor=CLACT_CreateActor((struct Unit *)(*(void **)&((MusicalMcssWork *)p)->unit),((MusicalMcssWork *)p)->character,((MusicalMcssWork *)p)->palette,((MusicalMcssWork *)p)->cellAnim,(const struct ActorInitParam *)&d,1,((MusicalMcssWork *)p)->heap);
    }
}

void MUSICAL_SHOT_INFO_InitBgLayer(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); BG_SYS_SetPlaneVisible(b,1); BG_SYS_FreeSlot(b); BG_SYS_PushTile(b); }

void MUSICAL_SHOT_INFO_InitWindows(u8 *p)
{
    int zero;
    ((MusicalMcssWork *)p)->win.val=(uptr)BMP_WIN_Create(4,1,1,30,4,10,1);
    BMP_WIN_TransferChars((struct BmpWin *)((MusicalMcssWork *)p)->win.val);
    BMP_WIN_MakeScreen((struct BmpWin *)(((MusicalMcssWork *)p)->win.val));
    BG_SYS_PushTile(4);
    zero=0;
    ((MusicalMcssWork *)p)->font.val=(uptr)GF_FONT_Create(23,0,0,0,((MusicalMcssWork *)p)->heap);
    ((MusicalMcssWork *)p)->msgBank.val=(uptr)MSGDATA_CreateFromArchive(0,2,78,((MusicalMcssWork *)p)->heap);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,320,32,((MusicalMcssWork *)p)->heap);
    GF_FONT_SetDefaultTextColor();
    ((MusicalMcssWork *)p)->tcbl.val=(uptr)TCBL_Create(((MusicalMcssWork *)p)->heap,((MusicalMcssWork *)p)->heap,3,256);
    ((MusicalMcssWork *)p)->printStream.val=zero;
    ((MusicalMcssWork *)p)->strbuf.val=zero;
    ((MusicalMcssWork *)p)->queActive=zero;
    ((MusicalMcssWork *)p)->timeIcon.val=zero;
    ((MusicalMcssWork *)p)->printQue.val=(uptr)PRINTSYS_QUE_Create((u32)(((MusicalMcssWork *)p)->heap));
}

void MUSICAL_SHOT_INFO_DeleteWindows(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((MusicalMcssWork *)p)->printQue.val));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((MusicalMcssWork *)p)->printQue.val));
    if (*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr) {
        TIME_ICON_Delete((struct TimeIcon *)(*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr));
        *(u32 *)&((MusicalMcssWork *)p)->timeIcon.ptr=0;
    }
    if (((MusicalMcssWork *)p)->printStream.ptr) PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
    if (((MusicalMcssWork *)p)->strbuf.ptr) STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
    MSGDATA_Delete(((MusicalMcssWork *)p)->msgBank.ptr);
    BMP_WIN_Delete(((MusicalMcssWork *)p)->win.ptr);
    GF_FONT_Delete(((MusicalMcssWork *)p)->font.ptr);
    TCBL_Destroy(((MusicalMcssWork *)p)->tcbl.ptr);
}

void MUSICAL_SHOT_INFO_PrintMessageStream(u8 *p,u32 index)
{
    u32 t;
    if (((MusicalMcssWork *)p)->printStream.ptr) {
        PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->printStream.ptr=0;
    }
    if (((MusicalMcssWork *)p)->strbuf.ptr) {
        STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr=0;
    }
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp(*(struct BmpWin **)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    t=MSG_SPEED_GetWait();
    ((MusicalMcssWork *)p)->printStream.ptr=PRINTSYS_PrintStream((struct BmpWin *)((MusicalMcssWork *)p)->win.ptr,0,0,(struct Strbuf *)((MusicalMcssWork *)p)->strbuf.ptr,(struct GfFont *)((MusicalMcssWork *)p)->font.ptr,t,(struct Tcbl *)((MusicalMcssWork *)p)->tcbl.ptr,2,((MusicalMcssWork *)p)->heap,0);
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}

void MUSICAL_SHOT_INFO_PrintMessageQueued(u8 *p,u32 index)
{
    uptr win;
    if (((MusicalMcssWork *)p)->strbuf.ptr) {
        STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr=0;
    }
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp(*(struct BmpWin **)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    win=(uptr)BMP_WIN_GetBmp(*(struct BmpWin **)&((MusicalMcssWork *)p)->win.ptr);
    PRINTSYS_PrintQue((struct PrintQueue *)(((MusicalMcssWork *)p)->printQue.val),(struct Bmp *)win,0,0,((MusicalMcssWork *)p)->strbuf.ptr,(struct GfFont *)(((MusicalMcssWork *)p)->font.val));
    ((MusicalMcssWork *)p)->queActive=1;
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}

void MUSICAL_SHOT_INFO_OpenYesNoMenu(u8 *p)
{
    MusShotInfoItem items[2];
    MusShotInfoMenu menu;
    items[0].data=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),4);
    items[1].data=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),5);
    items[0].value=0x39e0;
    items[1].value=0x39e0;
    items[0].zero=0;
    items[1].zero=0;
    menu.heap=((MusicalMcssWork *)p)->heap;
    menu.count=2;
    menu.items=items;
    menu.zero=0;
    menu.a=24;
    menu.b=6;
    menu.c=8;
    menu.d=3;
    ((MusicalMcssWork *)p)->taskMenu=APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&menu),(void *)(((MusicalMcssWork *)p)->taskMenuRes));
    STRBUF_Delete(items[0].data);
    STRBUF_Delete(items[1].data);
}

/*
 * file:     mus_shot_info.c
 * unit:     yes
 * function: MUSICAL_MCSS_Create, MUSICAL_MCSS_Delete, MUSICAL_MCSS_Main, MUSICAL_MCSS_NoOp2, MUSICAL_MCSS_CreateUnits, MUSICAL_MCSS_InitBg, MUSICAL_MCSS_InitWindows, MUSICAL_MCSS_DeleteWindows, MUSICAL_MCSS_PrintStream, MUSICAL_MCSS_PrintQue, MUSICAL_MCSS_OpenMenu
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
 *   MUSICAL_MCSS_Create 0x021F4284 thumb ov112
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   MUSICAL_MCSS_Delete 0x021F4300 thumb ov112
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_Main 0x021F4350 thumb ov112
 *   MUSICAL_MCSS_NoOp2 0x021F44E8 thumb ov112
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
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
 *   BG_SYS_ResetSlot 0x02041EE4 arm
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

extern u32 GFL_HEAP_Free(void *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern u32 GF_FONT_Delete(void *ptr);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_SetPlaneVisible(u32 which, unsigned char enable);

extern void BG_SYS_FreeSlot(u32);

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

typedef struct { u16 v; u16 pad; } H16;

typedef struct { u8 b[8]; } Box;

typedef struct Item { void *data; u16 value; u16 pad; int zero; } Item;

typedef struct Menu { u32 heap; u8 count; u8 pad[3]; Item *items; int zero; u8 a,b,c,d; } Menu;

/* A word used both as a pointer handle and as a raw integer by different views. */
typedef union { void *ptr; u32 val; } McssPtrWord;

/*
 * The MUSICAL_MCSS work object. MUSICAL_MCSS_Create allocates 0x5C bytes for it.
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

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BG_SYS_PushTile(u32);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern u32 WIPE_SYS_EndCheck(void);

extern void APP_TASKMENU_UpdateMenu(void *);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern void *MUSICAL_SAVE_NoOp(void *);

extern void MI_CpuCopy8(const void *,void *,u32);

extern void MUS_COMM_FUNC_SetTimingSync(int,int);

extern int MUS_COMM_FUNC_CheckTimingSync(char *p, int id);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const void *p);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern u32 PRINTSYS_PrintStreamGetState(void *);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);

extern void TCBL_Main(struct Tcbl *p);

extern void BG_SYS_ResetSlot(u32,u32,u32);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 APP_ICON_GetArchiveId(void);

extern u32 APP_ICON_GetStatusAnimFileId(void);

extern u32 APP_ICON_GetStatusFrameFileId(void);

extern u32 APP_ICON_GetStatusDataFileId(void);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32 APP_ICON_GetMoveKindPaletteFileId(void);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern u32 APP_ICON_GetMoveKindAnimFileId(void);

extern u32 APP_ICON_GetStatusCellFileId(u32);

extern u32 APP_ICON_GetStatusPaletteFileId(u32);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern void GF_FONT_SetDefaultTextColor(u32);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern u32 PRINTSYS_QUE_Create(void *p);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void TIME_ICON_Delete(u8 *);

extern void TCBL_Destroy(struct S02031140 *p);

extern signed char MSG_SPEED_GetWait(void);

extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);

extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);

extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

void *MUSICAL_MCSS_Create(u32 a, u32 b, u32 c, u32 d, H16 heap);

void MUSICAL_MCSS_Delete(u8 *p);

void MUSICAL_MCSS_Main(u8 *p);

int MUSICAL_MCSS_NoOp2(u32 *p);

void MUSICAL_MCSS_CreateUnits(u8 *p);

void MUSICAL_MCSS_InitBg(const void *a,u32 b,u32 c);

void MUSICAL_MCSS_InitWindows(u8 *p);

void MUSICAL_MCSS_DeleteWindows(u8 *p);

void MUSICAL_MCSS_PrintStream(u8 *p,u32 index);

void MUSICAL_MCSS_PrintQue(u8 *p,u32 index);

void MUSICAL_MCSS_OpenMenu(u8 *p);

extern char d_021F8394[];

extern const Box d_021F8290;

extern const u32 d_021F8298[];

extern const u32 d_021F82B8[];

extern const u32 d_021F82D8[];

void *MUSICAL_MCSS_Create(u32 a, u32 b, u32 c, u32 d, H16 heap)
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
    MUSICAL_MCSS_CreateUnits(p);
    MUSICAL_MCSS_InitWindows(p);
    *(u32 *)(p + 0x40) = (u32)APP_TASKMENU_RES_Create(4, 12, *(u32 *)(p + 0x20), *(u32 *)(p + 0x38), *(u16 *)p);
    GFL_NET_RestartWithDefaultTimeout(0, *(u16 *)&heap);
    BG_SYS_SetSubPlaneVisible(16, 1);
    return p;
}

/*
 * extent: trailing two-byte padding at 0x021F434E.
 */
void MUSICAL_MCSS_Delete(u8 *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((MusicalMcssWork *)p)->taskMenuRes));
    if (((MusicalMcssWork *)p)->mode==0) {
        CLACT_ReleasePalette(((MusicalMcssWork *)p)->palette);
        CLACT_ReleaseCharacter(((MusicalMcssWork *)p)->character);
        CLACT_ReleaseCellAnim(((MusicalMcssWork *)p)->cellAnim);
        CLACT_DeleteActor((struct Obj *)(((MusicalMcssWork *)p)->actor));
    }
    CLACT_DeleteUnit((struct Bank *)(((MusicalMcssWork *)p)->unit));
    MUSICAL_MCSS_DeleteWindows(p);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    GFL_HEAP_Free(p);
}

/*
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 */
void MUSICAL_MCSS_Main(u8 *p)
{
    u8 v;
    switch (((MusicalMcssWork *)p)->state) {
    case 0:
        ((MusicalMcssWork *)p)->state=1;
        GFL_USE_PlaySeDefaultVolume(1583);
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(((MusicalMcssWork *)p)->mode==1) {
                MUSICAL_MCSS_PrintStream(p,3);
                ((MusicalMcssWork *)p)->state=2;
            } else ((MusicalMcssWork *)p)->state=5;
        }
        break;
    case 2:
        if(!((MusicalMcssWork *)p)->printStream.ptr) {
            MUSICAL_MCSS_OpenMenu(p);
            ((MusicalMcssWork *)p)->state=3;
        }
        break;
    case 3:
        APP_TASKMENU_UpdateMenu(((MusicalMcssWork *)p)->taskMenu);
        if(APP_TASKMENU_IsFinish(((MusicalMcssWork *)p)->taskMenu)==1) {
            v=APP_TASKMENU_GetCursorPos(*(u8 * *)&((MusicalMcssWork *)p)->taskMenu);
            APP_TASKMENU_CloseMenu(((MusicalMcssWork *)p)->taskMenu);
            if(v==0) MI_CpuCopy8(((MusicalMcssWork *)p)->src,MUSICAL_SAVE_NoOp(((MusicalMcssWork *)p)->dst),432);
            if(*(int *)&((MusicalMcssWork *)p)->musComm) {
                ((MusicalMcssWork *)p)->state=4;
                MUS_COMM_FUNC_SetTimingSync(*(int *)&((MusicalMcssWork *)p)->musComm,71);
                MUSICAL_MCSS_PrintQue(p,6);
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
        if((KEY_GetTrg()&2)||!TOUCHPANEL_HitTrg(&d_021F8290)) {
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
        *(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr=TIME_ICON_CreateNode(*(u32 *)&((MusicalMcssWork *)p)->tcbl.ptr,((MusicalMcssWork *)p)->win.ptr,15,16,((MusicalMcssWork *)p)->heap);
        BMP_WIN_TransferChars(((MusicalMcssWork *)p)->win.ptr);
    }
    TCBL_Main(((MusicalMcssWork *)p)->tcbl.ptr);
    (*(volatile u8 *)&((MusicalMcssWork *)p)->counter)++;
    if(*(volatile u8 *)&((MusicalMcssWork *)p)->counter>1) {
        *(volatile u8 *)&((MusicalMcssWork *)p)->counter=0;
        BG_SYS_ResetSlot(7,1,1);
        BG_SYS_ResetSlot(7,5,1);
    }
}

int MUSICAL_MCSS_NoOp2(u32 *p) { if(p[1]==7) return 1; return 0; }

/*
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 */
void MUSICAL_MCSS_CreateUnits(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    MUSICAL_MCSS_InitBg(d_021F8298,4,0);
    MUSICAL_MCSS_InitBg(d_021F82B8,6,0);
    MUSICAL_MCSS_InitBg(d_021F82D8,7,0);
    ((MusicalMcssWork *)p)->unit=CLACT_CreateUnit(8,0,((MusicalMcssWork *)p)->heap);
    CLACT_SetUnitDefaultRenderer(((MusicalMcssWork *)p)->unit);
    BG_SYS_SetSubPlaneVisible(16,1);
    t=ARC_TOOL_CreateHandle((unsigned int)46,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)t),4,4,0,0,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadBgCharFromHandle((void *)((u32)t),7,7,0,0,0,((MusicalMcssWork *)p)->heap);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)((u32)t),12,7,0,0,0,((MusicalMcssWork *)p)->heap);
    ARC_TOOL_DeleteHandle(t);
    if (((MusicalMcssWork *)p)->mode==0) {
        t=ARC_TOOL_CreateHandle((unsigned int)APP_ICON_GetArchiveId(),((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)t),APP_ICON_GetStatusAnimFileId(),4,288,32,((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadBgCharFromHandle((void *)((u32)t),APP_ICON_GetStatusFrameFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)((u32)t),APP_ICON_GetStatusDataFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        BG_SYS_FillTileMap(6,0,21,32,3,9);
        BG_SYS_PushTile(6);
        ((MusicalMcssWork *)p)->palette=CLACT_RegisterPaletteEx((void *)((u32)t),APP_ICON_GetMoveKindPaletteFileId(),1,0,0,3,((MusicalMcssWork *)p)->heap);
        ((MusicalMcssWork *)p)->character=CLACT_RegisterCharacter((void *)((u32)t),APP_ICON_GetMoveKindAnimFileId(),0,1,((MusicalMcssWork *)p)->heap);
        v=APP_ICON_GetStatusCellFileId(0);
        w=APP_ICON_GetStatusPaletteFileId(0);
        ((MusicalMcssWork *)p)->cellAnim=CLACT_RegisterCellAnim((void *)((u32)t),v,w,((MusicalMcssWork *)p)->heap);
        ARC_TOOL_DeleteHandle(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((MusicalMcssWork *)p)->actor=CLACT_CreateActor((void *)*(u32 *)&((MusicalMcssWork *)p)->unit,((MusicalMcssWork *)p)->character,((MusicalMcssWork *)p)->palette,((MusicalMcssWork *)p)->cellAnim,&d,1,((MusicalMcssWork *)p)->heap);
    }
}

void MUSICAL_MCSS_InitBg(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); BG_SYS_SetPlaneVisible(b,1); BG_SYS_FreeSlot(b); BG_SYS_PushTile(b); }

void MUSICAL_MCSS_InitWindows(u8 *p)
{
    int zero;
    ((MusicalMcssWork *)p)->win.val=BMP_WIN_Create(4,1,1,30,4,10,1);
    BMP_WIN_TransferChars((struct Descriptor *)((MusicalMcssWork *)p)->win.val);
    BMP_WIN_MakeScreen((struct Cfg *)(((MusicalMcssWork *)p)->win.val));
    BG_SYS_PushTile(4);
    zero=0;
    ((MusicalMcssWork *)p)->font.val=(u32)GF_FONT_Create(23,0,0,0,((MusicalMcssWork *)p)->heap);
    ((MusicalMcssWork *)p)->msgBank.val=(u32)MSGDATA_CreateFromArchive(0,2,78,((MusicalMcssWork *)p)->heap);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,((MusicalMcssWork *)p)->heap);
    GF_FONT_SetDefaultTextColor(ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,320,32,((MusicalMcssWork *)p)->heap));
    ((MusicalMcssWork *)p)->tcbl.val=(u32)TCBL_Create(((MusicalMcssWork *)p)->heap,((MusicalMcssWork *)p)->heap,3,256);
    ((MusicalMcssWork *)p)->printStream.val=zero;
    ((MusicalMcssWork *)p)->strbuf.val=zero;
    ((MusicalMcssWork *)p)->queActive=zero;
    ((MusicalMcssWork *)p)->timeIcon.val=zero;
    ((MusicalMcssWork *)p)->printQue.val=PRINTSYS_QUE_Create((void *)(((MusicalMcssWork *)p)->heap));
}

void MUSICAL_MCSS_DeleteWindows(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val));
    if (*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr) {
        TIME_ICON_Delete(*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->timeIcon.ptr=0;
    }
    if (((MusicalMcssWork *)p)->printStream.ptr) PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
    if (((MusicalMcssWork *)p)->strbuf.ptr) STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
    MSGDATA_Delete(((MusicalMcssWork *)p)->msgBank.ptr);
    BMP_WIN_Delete(((MusicalMcssWork *)p)->win.ptr);
    GF_FONT_Delete(((MusicalMcssWork *)p)->font.ptr);
    TCBL_Destroy(((MusicalMcssWork *)p)->tcbl.ptr);
}

void MUSICAL_MCSS_PrintStream(u8 *p,u32 index)
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
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    t=MSG_SPEED_GetWait();
    *(u32 *)&((MusicalMcssWork *)p)->printStream.ptr=PRINTSYS_PrintStream(*(u32 *)&((MusicalMcssWork *)p)->win.ptr,0,0,*(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr,((MusicalMcssWork *)p)->font.val,t,((MusicalMcssWork *)p)->tcbl.val,2,((MusicalMcssWork *)p)->heap,0);
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}

void MUSICAL_MCSS_PrintQue(u8 *p,u32 index)
{
    u32 win;
    if (((MusicalMcssWork *)p)->strbuf.ptr) {
        STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=MSGDATA_AllocString((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    win=(u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr);
    PRINTSYS_PrintQue((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val),win,0,0,((MusicalMcssWork *)p)->strbuf.ptr,((MusicalMcssWork *)p)->font.val);
    ((MusicalMcssWork *)p)->queActive=1;
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}

void MUSICAL_MCSS_OpenMenu(u8 *p)
{
    Item items[2];
    Menu menu;
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
    ((MusicalMcssWork *)p)->taskMenu=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),(void *)(((MusicalMcssWork *)p)->taskMenuRes));
    STRBUF_Delete(items[0].data);
    STRBUF_Delete(items[1].data);
}

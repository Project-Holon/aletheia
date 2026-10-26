/*
 * file:     namein_graphic_main.c
 * unit:     yes
 * function: NAMEIN_GRAPHIC_Create, NAMEIN_GRAPHIC_Delete, NAMEIN_GRAPHIC_Main, NAMEIN_GRAPHIC_LoadBgPalette, NAMEIN_GRAPHIC_UpdateBg, NAMEIN_GRAPHIC_CreateActors, NAMEIN_GRAPHIC_DeleteActors, NAMEIN_GRAPHIC_GetActor, NAMEIN_GRAPHIC_InitCursor, NAMEIN_GRAPHIC_ClearCursor, NAMEIN_GRAPHIC_SetupCursor, NAMEIN_GRAPHIC_UpdateCursor
 * address:  0x021F1440
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MISC_GetInputFlag  0x0200C104  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   NAMEIN_GRAPHIC_CreateDisplay  0x021F4AE4  thumb  ov194
 *   NAMEIN_GRAPHIC_GetDisplayHandle  0x021F4BEC  thumb  ov194
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   NAMEIN_GRAPHIC_GetIconMode  0x021F4408  thumb  ov194
 *   NAMEIN_GRAPHIC_InitIconActor  0x021F3FBC  thumb  ov194
 *   NAMEIN_GRAPHIC_CreateMembers  0x021F4D3C  thumb  ov194
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   NAMEIN_GRAPHIC_IsNameCharValid  0x021F5004  thumb  ov194
 *   STRBUF_Clear  0x0204581C  arm
 *   NAMEIN_GRAPHIC_InitCallback  0x021F45EC  thumb  ov194
 *   NAMEIN_GRAPHIC_CallbackWaitDraw  0x021F463C  thumb  ov194
 *   NAMEIN_GRAPHIC_InitInputField  0x021F1E28  thumb  ov194
 *   NAMEIN_GRAPHIC_InitGrid  0x021F3008  thumb  ov194
 *   NAMEIN_GRAPHIC_InitMsgBox  0x021F3CD0  thumb  ov194
 *   NAMEIN_GRAPHIC_InitTcbl  0x021F3EB0  thumb  ov194
 *   PROF_WORD_Create  0x021F5304  thumb  ov194
 *   NAMEIN_GRAPHIC_PrintPokeMsg  0x021F3DE0  thumb  ov194
 *   NAMEIN_GRAPHIC_PrintMonMsg  0x021F3E18  thumb  ov194
 *   NAMEIN_GRAPHIC_PrintMsg  0x021F3D70  thumb  ov194
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   SAVE_CONTROL_INTR_Resume  0x021BD374  thumb  ov088
 *   PROF_WORD_Delete 0x021F5354 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteTcbl 0x021F3ED0 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteMsgBox 0x021F3D54 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteGrid 0x021F31B8 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteMembers 0x021F4D78 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteInputField 0x021F1F7C thumb ov194
 *   NAMEIN_GRAPHIC_ClearCallback 0x021F4608 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteIconActor 0x021F42A0 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteDisplay 0x021F4B84 thumb ov194
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   NAMEIN_GRAPHIC_RunCallback 0x021F4614 thumb ov194
 *   NAMEIN_GRAPHIC_DrawDisplay 0x021F4BD8 thumb ov194
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   NAMEIN_GRAPHIC_FlushIconOam 0x021F436C thumb ov194
 *   NAMEIN_GRAPHIC_GetCallbackState 0x021F4628 thumb ov194
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   NAMEIN_GRAPHIC_FadeCellColor 0x021F1D58 thumb ov194
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021F5780 0x021F5780 data a4 ov194
 */
struct U16Vec;
struct Blk34;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Proc;
struct PrintSys;
struct Rec;
struct Proc;
struct ClactActor;
struct Actor;
#include "../types.h"
#include "../ov194/prof_word.h"

#include "../ov010/namein_args.h"

/* A glyph source loaded by ARC_UTIL_LoadPaletteBlockFromArchive: a pointer to the glyph table at 0x0C. */
typedef struct NameinGraphicGlyphSrc {
    unsigned char pad_0[12];
    unsigned char *glyphs;      /* 0x0C */
} NameinGraphicGlyphSrc;

#include "../arm9/bg_sys.h"
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/msgdata.h"
#include "namein_graphic.h"
struct BmpOamSys;
#include "../arm9/bmp_oam.h"
#include "namein_data.h"
struct Strbuf;
#include "../arm9/strbuf.h"
/* The DS code passes b and c as words (the original prototype); the definition keeps halfword parameters. The host build uses the header. */
#ifdef __MWERKS__
#define NAMEIN_GRAPHIC_InitInputField NAMEIN_GRAPHIC_InitInputField_header
#endif
#include "namein_graphic_field.h"
#ifdef __MWERKS__
#undef NAMEIN_GRAPHIC_InitInputField
extern void NAMEIN_GRAPHIC_InitInputField(u8 *p, struct Strbuf *a, u32 b, u32 c, struct PrintQueue *d, u8 *e, int f);
#endif
#include "../arm9/net.h"
struct SaveControlIntr;
#include "../ov088/save_control_intr.h"
#include "prof_word.h"
#include "../arm9/wordset.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
/* The DS code passes the flags as a word (the original prototype); the definition takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define ARC_UTIL_LoadPaletteBlockFromArchive ARC_UTIL_LoadPaletteBlockFromArchive_header
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_LoadPaletteBlockFromArchive
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, void *unpackedOut, u32 flags);
#endif
#include "../arm9/bmp_menuwork.h"
#include "../arm9/clact.h"
struct ClactActor;
#include "../arm9/ui.h"
struct ClactVec2;
u32 NAMEIN_GRAPHIC_Create(struct Proc *a, u32 b, NameInArgs *args);
int NAMEIN_GRAPHIC_Delete(void *a,u32 b,u32 c,u8 *d);
int NAMEIN_GRAPHIC_Main(int a,int b,int c,u8 *p);
void NAMEIN_GRAPHIC_LoadBgPalette(void *unused,u16 heap);
void NAMEIN_GRAPHIC_UpdateBg(void *unused);
void NAMEIN_GRAPHIC_CreateActors(char *p,struct Unit *owner,u16 heap);
void NAMEIN_GRAPHIC_DeleteActors(u8 *p);
void *NAMEIN_GRAPHIC_GetActor(u8 *p,u32 i);
void NAMEIN_GRAPHIC_InitCursor(u8 *a,int b,void *c,u32 d);
void NAMEIN_GRAPHIC_ClearCursor(void *p);
void NAMEIN_GRAPHIC_SetupCursor(char *p,int mode,const NameinGraphicMainRect *rect,int flag,int selected);
void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect);
extern u32 d_021F5780[];

u32 NAMEIN_GRAPHIC_Create(struct Proc *a, u32 b, NameInArgs *args)
{
    NameinGraphicWork *w;
    int mode;
    struct Unit *s;
    u16 h;

    mode = 0;
    if (args->pokedex != 0) {
        mode = MISC_GetInputFlag(args->pokedex, args->kind);
        if (mode >= 5) {
            mode = 0;
        }
    }
    GFL_HEAP_CreateChildHeap(1, 0x1e, 0x70000);
    w = PROCSYS_AllocProcWork(a, sizeof(NameinGraphicWork), 0x1e);
    MI_CpuFill8(w, 0, sizeof(NameinGraphicWork));
    w->args = args;
    w->font = GF_FONT_Create(0x17, 0, 1, 0, 0x1e);
    w->printSys = PRINTSYS_QUE_CreateEx(0x1000, 0x1e);
    w->msgBank = MSGDATA_CreateFromArchive(1, 2, 0x51, 0x1e);
    w->wordSet = WORDSET_CreateDefault(0x1e);
    w->display = NAMEIN_GRAPHIC_CreateDisplay(0, 0x1e);
    w->oamSys = BMP_OAM_CreateSys(0x1e, NAMEIN_GRAPHIC_GetDisplayHandle(w->display));
    NAMEIN_GRAPHIC_LoadBgPalette(&w->paletteTag, 0x1e);
    s = NAMEIN_GRAPHIC_GetDisplayHandle(w->display);
    NAMEIN_GRAPHIC_CreateActors((char *)&w->actors, s, 0x1e);
    h = args->species;
    NAMEIN_GRAPHIC_InitIconActor(&w->icon, NAMEIN_GRAPHIC_GetIconMode(args->kind, h), h, args->traits, s,
                  w->font, w->printSys, w->msgBank, w->oamSys, 0x1e);
    w->members = NAMEIN_GRAPHIC_CreateMembers(0x1e);
    w->nameStrbuf = STRBUF_Clone(args->name, 0x1e);
    if (STRBUF_GetLength(w->nameStrbuf) != 0) {
        if (STRBUF_GetLength(w->nameStrbuf) > (u32)args->maxLen
            || NAMEIN_GRAPHIC_IsNameCharValid(STRBUF_GetChars(w->nameStrbuf), 0x1e) == 0) {
            STRBUF_Clear(w->nameStrbuf);
        }
    }
    NAMEIN_GRAPHIC_InitCallback(&w->callback, w, NAMEIN_GRAPHIC_CallbackWaitDraw);
#ifdef __MWERKS__
    NAMEIN_GRAPHIC_InitInputField((u8 *)&w->inputField, w->nameStrbuf, (u8)args->maxLen, (u32)w->font,
                  w->printSys, (u8 *)&w->actors, 0x1e);
#else
    NAMEIN_GRAPHIC_InitInputField((u8 *)&w->inputField, w->nameStrbuf, (u8)args->maxLen, w->font,
                  w->printSys, (u8 *)&w->actors, 0x1e);
#endif
    NAMEIN_GRAPHIC_InitGrid((u8 *)&w->grid, mode, w->font, w->printSys, w->members, (u8 *)&w->actors, 0x1e);
    NAMEIN_GRAPHIC_InitMsgBox((u8 *)&w->msgBox, w->font, w->msgBank, w->printSys, w->wordSet, 0x1e);
    NAMEIN_GRAPHIC_InitTcbl((char *)&w->tcbl, 0x1e);
    w->profWord = PROF_WORD_Create(0x1e);
    if (args->kind == 1) {
        if (args->mon == 0) {
            NAMEIN_GRAPHIC_PrintPokeMsg((char *)&w->msgBox, args->kind, args->species, args->traits, 0x1e);
        } else {
            NAMEIN_GRAPHIC_PrintMonMsg((char *)&w->msgBox, args->kind, args->mon);
        }
    } else {
        NAMEIN_GRAPHIC_PrintMsg((char *)&w->msgBox, args->kind);
    }
    if (GFL_NET_GetRunState()) {
        GFL_NET_RefreshWmIconAtTopRight(1, 0x1e);
    }
    if (w->args->saveIntr != 0) {
        SAVE_CONTROL_INTR_Resume(w->args->saveIntr);
    }
    return 1;
}

int NAMEIN_GRAPHIC_Delete(void *a,u32 b,u32 c,u8 *d)
{
    PROF_WORD_Delete(((NameinGraphicWork *)d)->profWord);
    NAMEIN_GRAPHIC_DeleteTcbl((u8 *)&((NameinGraphicWork *)d)->tcbl);
    NAMEIN_GRAPHIC_DeleteMsgBox((u8 *)&((NameinGraphicWork *)d)->msgBox);
    NAMEIN_GRAPHIC_DeleteGrid((u8 *)&((NameinGraphicWork *)d)->grid);
    STRBUF_Delete(((NameinGraphicWork *)d)->nameStrbuf);
    NAMEIN_GRAPHIC_DeleteMembers(((NameinGraphicWork *)d)->members);
    NAMEIN_GRAPHIC_DeleteInputField((u8 *)&((NameinGraphicWork *)d)->inputField);
    NAMEIN_GRAPHIC_ClearCallback(&((NameinGraphicWork *)d)->callback);
    NAMEIN_GRAPHIC_DeleteIconActor((u8 *)&((NameinGraphicWork *)d)->icon);
    NAMEIN_GRAPHIC_DeleteActors((u8 *)&((NameinGraphicWork *)d)->actors);
    NAMEIN_GRAPHIC_UpdateBg(&((NameinGraphicWork *)d)->paletteTag);
    BMP_OAM_DeleteSys(((NameinGraphicWork *)d)->oamSys);
    NAMEIN_GRAPHIC_DeleteDisplay(((NameinGraphicWork *)d)->display);
    WORDSET_Delete(((NameinGraphicWork *)d)->wordSet);
    MSGDATA_Delete(((NameinGraphicWork *)d)->msgBank);
    PRINTSYS_QUE_Clear(((NameinGraphicWork *)d)->printSys);
    PRINTSYS_QUE_Delete(((NameinGraphicWork *)d)->printSys);
    GF_FONT_Delete(((NameinGraphicWork *)d)->font);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(30);
    return 1;
}

int NAMEIN_GRAPHIC_Main(int a,int b,int c,u8 *p) { NAMEIN_GRAPHIC_RunCallback(&((NameinGraphicWork *)p)->callback);NAMEIN_GRAPHIC_DrawDisplay(*(u8 * *)&((NameinGraphicWork *)p)->display);PRINTSYS_QUE_Main((struct PrintQueue *)(((NameinGraphicWork *)p)->printSys));NAMEIN_GRAPHIC_FlushIconOam((u8 *)&((NameinGraphicWork *)p)->icon);if(NAMEIN_GRAPHIC_GetCallbackState(&((NameinGraphicWork *)p)->callback))return 1;return 0; }

/*
 * extent: Two trailing zero alignment bytes at 021F1876; existing NAMEIN_GRAPHIC_UpdateBg begins immediately afterward.
 */
void NAMEIN_GRAPHIC_LoadBgPalette(void *unused,u16 heap)
{
    void *p;
    p=ARC_TOOL_CreateHandle(118,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(p,2,4,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(p,1,5,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(p,3,5,0,0,0,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(p,2,0,0,0,heap);
    ARC_UTIL_UploadPaletteFromHandle(p,2,0,64,96,32,heap);
    ARC_UTIL_UploadPaletteFromHandle(p,2,0,64,128,32,heap);
    ARC_UTIL_UploadBgCharFromHandle(p,1,0,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(p,0,0,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(p,4,2,0,0,0,heap);
    ARC_TOOL_DeleteHandle(p);
    p=ARC_TOOL_CreateHandle(23,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(p,6,4,480,32,heap);
    ARC_TOOL_DeleteHandle(p);
    BG_SYS_Init(4,0,1,0);
    BMP_MENUWORK_LoadCharAndPltt(4,1,14,0,heap);
}

void NAMEIN_GRAPHIC_UpdateBg(void *unused)
{
    BG_SYS_FreeTiles(4, 1, 0);
}

void NAMEIN_GRAPHIC_CreateActors(char *p,struct Unit *owner,u16 heap)
{
    short pos[4];
    void *handle;
    int i;
    int zero;
    handle=ARC_TOOL_CreateHandle(118,heap);
    *(int *)&((NameinGraphicActors *)p)->palette=CLACT_RegisterPalette(handle,9,0,0,heap);
    *(int *)&((NameinGraphicActors *)p)->cellAnim=CLACT_RegisterCellAnim(handle,7,6,heap);
    *(int *)&((NameinGraphicActors *)p)->character=CLACT_RegisterCharacter(handle,8,0,0,heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(pos,0,8);
    pos[2]=0;
    zero=0;
    for(i=0;i<16;i++)
        ((struct NameinGraphicActors *)p)->list[i]=CLACT_CreateActor(owner,((NameinGraphicActors *)p)->character,((NameinGraphicActors *)p)->palette,((NameinGraphicActors *)p)->cellAnim,(const struct ActorInitParam *)pos,zero,heap);
    pos[2]=1;
    ((NameinGraphicActors *)p)->list[17]=CLACT_CreateActor(owner,((NameinGraphicActors *)p)->character,((NameinGraphicActors *)p)->palette,((NameinGraphicActors *)p)->cellAnim,(const struct ActorInitParam *)pos,zero,heap);
    CLACT_SetActorDrawEnable(((NameinGraphicActors *)p)->list[17],zero);
    for(i=18;i<20;i++) {
        pos[0]=-32;
        pos[1]=-32;
        pos[2]=i-15;
        ((struct NameinGraphicActors *)p)->list[i]=CLACT_CreateActor(owner,((NameinGraphicActors *)p)->character,((NameinGraphicActors *)p)->palette,((NameinGraphicActors *)p)->cellAnim,(const struct ActorInitParam *)pos,0,heap);
        CLACT_SetActorAutoAnim(((struct NameinGraphicActors *)p)->list[i],1);
        CLACT_SetActorDrawEnable(((struct NameinGraphicActors *)p)->list[i],0);
    }
}

void NAMEIN_GRAPHIC_DeleteActors(u8 *p) { int i; 
for(i=0;i<21;i++) { void *q=((struct NameinGraphicActors *)p)->list[(u32)i]; if(q)CLACT_DeleteActor(q); }
 CLACT_ReleasePalette(((NameinGraphicActors *)p)->palette);CLACT_ReleaseCharacter((u32)(((NameinGraphicActors *)p)->character));CLACT_ReleaseCellAnim(((NameinGraphicActors *)p)->cellAnim); }

void *NAMEIN_GRAPHIC_GetActor(u8 *p,u32 i) { 
return ((struct NameinGraphicActors *)p)->list[i];
 }

void NAMEIN_GRAPHIC_InitCursor(u8 *a,int b,void *c,u32 d)
{
    int i;
    void *x;
    void *p;
    u8 *q;
    int j;
    MI_CpuFill8(a,0,sizeof(NameinGraphicCursor));
    ((NameinGraphicCursor *)a)->selected=b;
    for(i=0;i<2;i++) *(void **)((u8 *)&((NameinGraphicCursor *)a)->actorA + i*(int)sizeof(void *)) = NAMEIN_GRAPHIC_GetActor(c,i+18);
    p=ARC_UTIL_LoadPaletteBlockFromArchive(118,2,(void *)((&x)),d);
    q=*(u8 * *)&((NameinGraphicGlyphSrc *)x)->glyphs;
    for(i=0;i<16;i++) *(u16 *)(a+i*2)=*(u16 *)(q+32+i*2);
    for(j=0;j<16;j++) *(u16 *)(a+32+j*2)=*(u16 *)(q+64+j*2);
    GFL_HEAP_Free(p);
}

void NAMEIN_GRAPHIC_ClearCursor(void *p) { MI_CpuFill8(p,0,sizeof(NameinGraphicCursor)); }

/*
 * extent: 478 instruction bytes; 021F1BFA is two-byte zero alignment before021F1BFC.
 * lever: const Rect source schedules the loads ahead of argument stores; signed y destinations avoid an extra unsigned truncation pair (484/224 to482/157 toEXACT*478).
 */
void NAMEIN_GRAPHIC_SetupCursor(char *p,int mode,const NameinGraphicMainRect *rect,int flag,int selected)
{
    int x;
    short y;
    ((NameinGraphicCursor *)p)->active=0;
    ((NameinGraphicCursor *)p)->mode=mode;
    ((NameinGraphicCursor *)p)->flag=flag;
    ((NameinGraphicCursor *)p)->selected=selected;
    BG_SYS_FillTileMap(2,0,0,32,24,1);
    BG_SYS_FillTileMap(1,0,0,32,24,1);
    if(flag!=0 && selected==3) {
        BG_SYS_FillTileMap(1,3,16,4,3,4);
        BG_SYS_FillTileMap(1,23,16,4,3,4);
    }
    x=(selected+1)*3;
    BG_SYS_FillTileMap(1,x,20,3,3,4);
    BG_SYS_FillTileMap(2,x,20,3,3,4);
    if(rect && mode!=0) {
        ((NameinGraphicCursor *)p)->rect=*rect;
        if(mode==2) {
            BG_SYS_FillTileMap(2,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
            BG_SYS_FillTileMap(1,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
        }
        if(UI_GetInputMode()==0) {
            ((NameinGraphicCursor *)p)->actorAX=rect->left*8+7;
            y=rect->top*8+(rect->bottom-rect->top)*4-3;
            ((NameinGraphicCursor *)p)->actorAY=y;
            ((NameinGraphicCursor *)p)->actorBX=rect->right*8-7;
            ((NameinGraphicCursor *)p)->actorBY=y;
            CLACT_RestartActorAnim(((NameinGraphicCursor *)p)->actorA);
            CLACT_RestartActorAnim(((NameinGraphicCursor *)p)->actorB);
            CLACT_SetActorDrawEnable(((NameinGraphicCursor *)p)->actorA,1);
            CLACT_SetActorDrawEnable(((NameinGraphicCursor *)p)->actorB,1);
        }
    }
    if(mode==0 || UI_GetInputMode()==1) {
        CLACT_SetActorDrawEnable(((NameinGraphicCursor *)p)->actorA,0);
        CLACT_SetActorDrawEnable(((NameinGraphicCursor *)p)->actorB,0);
    }
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(1);
    if(mode!=0) {
        MI_CpuFill8(((void *)&((struct NameinGraphicCursor *)p)->phase),0,32);
        ((NameinGraphicCursor *)p)->blinkTimer=0;
        ((NameinGraphicCursor *)p)->active=1;
    }
}

/*
 * note 2026-10-05 (wD7 lane05): the third parameter is dead after the switch; the source reuses it
 *   for the address of the Vec2 scratch (`rect = &v;`), which keeps that address in r7 across both
 *   CLACT_AddActorSurfacePos calls (idiom a-dead-stack-parameter-reassigned-to-a-locals-address-keeps-a-callee-saved-register).
 *   Parameter declared `const void *` so no casts are needed.
 */
void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect)
{
    struct NameinGraphicMainVec2 v;
    u32 d, c;
    int i;
    if (((struct NameinGraphicCursor *)p)->active != 0) {
        u16 *a, *b;
        switch (((struct NameinGraphicCursor *)p)->mode) {
        case 0:
            break;
        case 1:
            d = 2;
            c = (u16)d_021F5780[0];
            break;
        case 2:
            d = 3;
            c = 0x1999;
            if ((((struct NameinGraphicCursor *)p)->blinkTimer)++ > 10) {
                if (UI_GetInputMode() == 0)
                    NAMEIN_GRAPHIC_SetupCursor(p, 1, (const NameinGraphicMainRect *)rect, ((struct NameinGraphicCursor *)p)->flag, sel);
                else
                    NAMEIN_GRAPHIC_SetupCursor(p, 0, (const NameinGraphicMainRect *)rect, ((struct NameinGraphicCursor *)p)->flag, sel);
            }
            break;
        }
        a = (u16 *)p;
        a += 0x20;
        b = (u16 *)p;
        b += 0x30;
        for (i = 0; i < 16; i++)
            NAMEIN_GRAPHIC_FadeCellColor(a + i, b + i, c, d, i, ((u16 *)p)[i], ((u16 *)p)[i + 0x10]);
    }
    rect = &v;
    v.x = ((struct NameinGraphicCursor *)p)->actorAX;
    v.y = *(u16 *)&((struct NameinGraphicCursor *)p)->actorAY;
    v.y = v.y - (s16)(BG_SYS_GetScrollY(2) << 3);
    CLACT_AddActorSurfacePos(((struct NameinGraphicCursor *)p)->actorA, (struct ClactVec2 *)rect, 0);
    v.x = ((struct NameinGraphicCursor *)p)->actorBX;
    v.y = *(u16 *)&((struct NameinGraphicCursor *)p)->actorBY;
    v.y = v.y - (s16)(BG_SYS_GetScrollY(2) << 3);
    CLACT_AddActorSurfacePos(((struct NameinGraphicCursor *)p)->actorB, (struct ClactVec2 *)rect, 0);
    if (((struct NameinGraphicCursor *)p)->selected != sel) {
        if (UI_GetInputMode() == 0)
            NAMEIN_GRAPHIC_SetupCursor(p, 1, &((NameinGraphicCursor *)p)->rect, ((struct NameinGraphicCursor *)p)->flag, sel);
        else
            NAMEIN_GRAPHIC_SetupCursor(p, 0, &((NameinGraphicCursor *)p)->rect, ((struct NameinGraphicCursor *)p)->flag, sel);
    }
}

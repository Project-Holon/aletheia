/*
 * file:     poke_summary_actor.c
 * unit:     yes
 * function: POKE_SUMMARY_ACTOR_InitSystem, POKE_SUMMARY_ACTOR_DeleteSystem, POKE_SUMMARY_ACTOR_RegisterResources, POKE_SUMMARY_ACTOR_TransferCharacter, POKE_SUMMARY_ACTOR_SetMoveIcon, POKE_SUMMARY_ACTOR_FlushPendingTransfers, POKE_SUMMARY_ACTOR_LayoutMoveActors, POKE_SUMMARY_ACTOR_SetMoveAnim, POKE_SUMMARY_ACTOR_CreateActors, POKE_SUMMARY_ACTOR_PositionMonActor, POKE_SUMMARY_ACTOR_StartWipe, POKE_SUMMARY_ACTOR_StartProc, POKE_SUMMARY_ACTOR_StartNetRestart, POKE_SUMMARY_ACTOR_CreateSound, POKE_SUMMARY_ACTOR_UpdateSound, POKE_SUMMARY_ACTOR_Noop, POKE_SUMMARY_ACTOR_SelectRow, POKE_SUMMARY_ACTOR_HandleCursorInput, POKE_SUMMARY_ACTOR_ToggleTaskMenu, POKE_SUMMARY_ACTOR_IsTaskMenuOpen, POKE_SUMMARY_ACTOR_UpdateScrollArrows, POKE_SUMMARY_ACTOR_SetScrollAnim, POKE_SUMMARY_ACTOR_SetIdleAnim, POKE_SUMMARY_ACTOR_OpenDecideWin, POKE_SUMMARY_ACTOR_ConfirmDecide, POKE_SUMMARY_ACTOR_ConfirmDecideById, POKE_SUMMARY_ACTOR_WaitDecide, POKE_SUMMARY_ACTOR_ShowTextKind2, POKE_SUMMARY_ACTOR_ShowTextKind1Or4, POKE_SUMMARY_ACTOR_SetSubBrightness
 * address:  0x021B7658
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021B820C 0x021B820C data a4
 *   d_021B8250 0x021B8250 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021B85E0 0x021B85E0 data a4
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   k_83 0x00000083 data a1
 *   POKE_SUMMARY_MAIN_ExitScreen 0x021B6460 thumb ov173
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   POKE_SUMMARY_MAIN_InitScreen  0x021B63AC  thumb  ov173
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   d_021B83A8 0x021B83A8 data a4
 *   d_021B81DC 0x021B81DC data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   POKE_SUMMARY_MAIN_RedrawMoveList 0x021B70D8 thumb ov173
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   CURSOR_MOVE_SetSkipBit 0x0202614C thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   POKE_SUMMARY_MAIN_StartTextStream  0x021B7460  thumb  ov173
 *   POKE_SUMMARY_MAIN_CountFreeMoves 0x021B7568 thumb ov173
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 */

#include "poke_summary_types.h"
#include "../sdk_ioreg.h"
struct Cfg;
struct Unit;
struct ClactActor;
struct Sav;
struct NNSG2dCharacterData;
struct ClactVec2;
struct Ctx;
struct IcaAnime;
struct CursorMove;
struct Sound;
struct ClactActor;
#include "../types.h"

typedef enum { OFFSET=14 } Offset;

typedef struct {short x,y;u16 unused,z;u32 a,b,c,d,e,f,g,h,i;} Row;

typedef struct {short x,y;u16 z;u8 a,b;} Position;
struct DispVramCfg;
struct ClactSysInit;
struct ClactSysInit;

#include "../arm9/clact.h"
#include "../arm9/bg_sys.h"
struct ClactActor;
#include "../arm9/app_icon.h"
#include "../arm9/pokegra.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
struct BoxPokemon;
#include "../arm9/arc_util.h"
struct NNSG2dCharacterData;
#include "../arm9/gfl_heap_wrap.h"
/* The original forwards the full entry r1 without halfword truncation. */
struct ClactVec2;
#include "../arm9/wipe.h"
#include "poke_summary_main.h"
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
#include "../arm9/net.h"
struct CursorVtbl;
struct CursorEntry;
struct Cursor;
#include "../arm9/cursor_move.h"
#include "../arm9/gfl_use.h"
#include "../arm9/arc_tool.h"
#include "../arm9/waza_tool.h"
struct TaskMenuItem;
struct TaskMenuRes;
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/g2.h"
void POKE_SUMMARY_ACTOR_InitSystem(u8 *p, void *archiveHandle);
void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p);
void POKE_SUMMARY_ACTOR_RegisterResources(char *p,void *other);
void POKE_SUMMARY_ACTOR_TransferCharacter(u32 a,int b,u32 c,u32 d,u16 heap);
void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *p, u16 id, u16 i);
void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *p);
void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *p);
void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *p, u16 id);
void POKE_SUMMARY_ACTOR_CreateActors(char *p,void *arg);
void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused);
int POKE_SUMMARY_ACTOR_StartWipe(u8 *p);
int POKE_SUMMARY_ACTOR_StartProc(char *p);
int POKE_SUMMARY_ACTOR_StartNetRestart(void *p);
void POKE_SUMMARY_ACTOR_CreateSound(u8 *p);
int POKE_SUMMARY_ACTOR_UpdateSound(int *p);
void POKE_SUMMARY_ACTOR_Noop(void);
void POKE_SUMMARY_ACTOR_SelectRow(char *p,int row,int old);
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *p,int i);
void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag);
int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *p);
void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *p);
void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *p,int direction);
void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *p);
int POKE_SUMMARY_ACTOR_OpenDecideWin(char *p, u16 v);
int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *p,u16 n);
int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *p,unsigned short id);
int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p);
int POKE_SUMMARY_ACTOR_ShowTextKind2(char *p);
int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p);
void POKE_SUMMARY_ACTOR_SetSubBrightness(int a);
extern const struct Cfg d_021B820C;
extern u8 d_021B8250[];
extern const Row d_021B85E0[];
extern char gPokeStatusProcData[];
extern char k_83[];
extern u8 d_021B81DC[];
extern const u8 d_021B83A8[];

void POKE_SUMMARY_ACTOR_InitSystem(u8 *work, void *archiveHandle) {Offset off;struct Unit *b;CLACT_InitSystem((struct ClactSysInit *)(&d_021B820C),(struct DispVramCfg *)d_021B8250,79);off=OFFSET;b=CLACT_CreateUnit(14,0,79);off+=242;*(struct Unit **)(work+off)=b;CLACT_SetUnitDefaultRenderer(b);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}

void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *work) {u32 i;for(i=0;i<14;i++)CLACT_DeleteActor(((struct PokeSummaryWork *)work)->actors[i]);CLACT_DeleteUnit(*(struct Unit * *)&((struct PokeSummaryWork *)work)->unit);CLACT_ExitSystem();ARC_TOOL_DeleteHandle(((struct PokeSummaryWork *)work)->resourceHandle);}

void POKE_SUMMARY_ACTOR_RegisterResources(char *work,void *archiveHandle)
{
    void *bank;
    u32 i;
    u32 first;
    sptr second;
    void *mon;
    u32 save;
    bank=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),79);
    ((struct PokeSummaryWork *)work)->reg.named.charHandles[0]=CLACT_RegisterCharacter(bank,APP_ICON_GetMoveKindAnimFileId(),0,1,79);
    ((struct PokeSummaryWork *)work)->reg.named.charHandles[1]=CLACT_RegisterCharacter(archiveHandle,17,0,1,79);
    ((struct PokeSummaryWork *)work)->reg.named.charHandles[2]=CLACT_RegisterCharacter(archiveHandle,26,0,1,79);
    for(i=4;i<8;i++) ((struct PokeSummaryWork *)work)->reg.named.charHandles[i]=CLACT_RegisterCharacter(bank,APP_ICON_GetTypeCellFileId(0),0,0,79);
    ((struct PokeSummaryWork *)work)->reg.named.charHandles[3]=CLACT_RegisterCharacter(archiveHandle,23,0,1,79);
    ((struct PokeSummaryWork *)work)->reg.named.paletteHandles[0]=CLACT_RegisterPaletteEx(bank,APP_ICON_GetMoveKindPaletteFileId(),1,0,0,4,79);
    ((struct PokeSummaryWork *)work)->reg.named.paletteHandles[1]=CLACT_RegisterPaletteEx(archiveHandle,5,1,128,0,1,79);
    ((struct PokeSummaryWork *)work)->reg.named.paletteHandles[2]=CLACT_RegisterPaletteEx(bank,APP_ICON_GetTouchBarFileId(),1,192,0,3,79);
    ((struct PokeSummaryWork *)work)->reg.named.paletteHandles[3]=CLACT_RegisterPalette(bank,APP_ICON_GetTouchBarFileId(),0,0,79);
    first=APP_ICON_GetStatusCellFileId(1);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[0]=CLACT_RegisterCellAnim(bank,first,APP_ICON_GetStatusPaletteFileId(1),79);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[1]=CLACT_RegisterCellAnim(archiveHandle,7,8,79);
    first=APP_ICON_GetTypePaletteFileId(1);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[2]=CLACT_RegisterCellAnim(bank,first,APP_ICON_GetTypeAnimFileId(1),79);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[3]=CLACT_RegisterCellAnim(archiveHandle,24,25,79);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[4]=CLACT_RegisterCellAnim(archiveHandle,27,28,79);
    ARC_TOOL_DeleteHandle(bank);
    second=(sptr)POKEGRA_OpenHandle(79);
    mon=POKE_TOOL_CastToBoxParam(((struct PokeSummaryWork *)work)->mon->party);
    save=POKE_TOOL_DecodeBoxParam(mon);
    ((struct PokeSummaryWork *)work)->reg.named.cgrHandle=POKEGRA_RegisterCgrPP(second,mon,0,0,79);
    ((struct PokeSummaryWork *)work)->reg.named.paletteHandles[4]=POKEGRA_RegisterPalettePP(second,mon,0,0,128,79);
    ((struct PokeSummaryWork *)work)->reg.named.cellAnimHandle2=POKEGRA_RegisterCellAnimPP(mon,0,1,0,79);
    POKE_TOOL_EncodeBoxParam(mon,save);
    ARC_TOOL_DeleteHandle((void *)second);
}

void POKE_SUMMARY_ACTOR_TransferCharacter(u32 archiveHandle,int charId,u32 memberIdx,u32 heapID,u16 heap) {void *raw;struct NNSG2dCharacterData *out;raw=ARC_UTIL_LoadScreenDataFromHandle((void *)archiveHandle,memberIdx,heapID,(&out),heap);CLACT_TransferCharacter(charId,out);GFL_HEAP_Free(raw);}

void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *work, u16 id, u16 i) {u32 n;n=WAZA_TOOL_GetParam(id,0);((struct PokeSummaryWork *)work)->transfers[i].param=n;((struct PokeSummaryWork *)work)->transfers[i].flag=1;CLACT_SetActorPaletteOffset((struct ClactActor *)(*(struct ClactActor **)(work+(i+8)*4+260)),APP_ICON_GetTypePaletteOffset((u8)n),1);}

void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *work)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (((struct PokeSummaryWork *)work)->transfers[i].flag != 0) {
            POKE_SUMMARY_ACTOR_TransferCharacter((uptr)(((struct PokeSummaryWork *)work)->resourceHandle), (int)(((struct PokeSummaryWork *)work)->reg.flat[4+i]), APP_ICON_GetTypeCellFileId((u8)((struct PokeSummaryWork *)work)->transfers[i].param), 0, 0x4f);
            ((struct PokeSummaryWork *)work)->transfers[i].flag = 0;
        }
    }
}

void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *work)
{
    u16 rect[2];
    u32 off;
    u32 i;
    u32 value;
    off = 0x1b8;
    for (i = 0; i < 4; i++) {
        rect[0] = 0x2f;
        rect[1] = i * 24 + 0x50;
        CLACT_AddActorSurfacePos(((struct PokeSummaryWork *)work)->actors[4+i], (struct ClactVec2 *)rect, 1);
        if (((struct PokeSummaryWork *)work)->mon->scrollIndex + i >= *(u8 *)(work + off)) {
            CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[4+i], 0);
        } else {
            value = WAZA_TOOL_GetParam(*(u16 *)(*(char * *)&((struct PokeSummaryWork *)work)->mon->moveList + (((struct PokeSummaryWork *)work)->mon->scrollIndex + i) * 2), 0);
            CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[4+i], 1);
            CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[4+i], value);
        }
    }
}

void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *work, u16 id) {CLACT_SetActorAnimSeq((struct ClactActor *)(*(struct ClactActor * *)&((struct PokeSummaryWork *)work)->actors[3]),WAZA_TOOL_GetParam(id,2));}

/*
 * abi: B294 returns the Obj pointer stored and used by this caller.
 */
void POKE_SUMMARY_ACTOR_CreateActors(char *work,void *archiveHandle)
{
    u32 i;
    Position pos;
    POKE_SUMMARY_ACTOR_InitSystem((u8 *)work,archiveHandle);
    POKE_SUMMARY_ACTOR_RegisterResources(work,archiveHandle);
    ((struct PokeSummaryWork *)work)->resourceHandle=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),79);
    for(i=0;i<14;i++) {
        pos.x=d_021B85E0[i].x;
        pos.y=d_021B85E0[i].y;
        pos.z=d_021B85E0[i].z;
        pos.a=d_021B85E0[i].a;
        pos.b=d_021B85E0[i].h;
        ((struct PokeSummaryWork *)work)->actors[i]=CLACT_CreateActor((struct Unit *)((void *)((struct PokeSummaryWork *)work)->unit),((struct PokeSummaryWork *)work)->reg.named.charHandles[d_021B85E0[i].d],((struct PokeSummaryWork *)work)->reg.named.paletteHandles[d_021B85E0[i].e],((struct PokeSummaryWork *)work)->reg.named.cellAnimHandles[d_021B85E0[i].f],(const struct ActorInitParam *)&pos,d_021B85E0[i].c,79);
        CLACT_SetActorAutoAnim(((struct PokeSummaryWork *)work)->actors[i],0);
    }
    CLACT_SetActorAutoAnim(((struct PokeSummaryWork *)work)->actors[13],1);
    CLACT_SetActorAutoAnim(((struct PokeSummaryWork *)work)->actors[2],1);
    CLACT_SetActorAutoAnim(((struct PokeSummaryWork *)work)->actors[1],1);
    CLACT_SetActorAutoAnim(((struct PokeSummaryWork *)work)->actors[0],1);
}

void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *work, u32 idx, int unused)
{
    u16 local[2];

    if (idx < 4) {
        local[0] = 0x82;
        local[1] = idx * 0x18 + 0x54;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), (struct ClactVec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), 0);
    } else if (idx < 6) {
        local[0] = (idx - 4) * 0x28;
        local[1] = 0xa8;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), (struct ClactVec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), 1);
    } else {
        local[0] = 0xc0;
        local[1] = 0xa0;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), (struct ClactVec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[2]), 2);
    }
}

int POKE_SUMMARY_ACTOR_StartWipe(u8 *work) {WIPE_SYS_Start(0,0,0,0,6,1,79);((struct PokeSummaryWork *)work)->state=11;return 0;}

int POKE_SUMMARY_ACTOR_StartProc(char *work)
{
    char *q;
    u32 zero;
    POKE_SUMMARY_MAIN_ExitScreen(work);
    q = *(char * *)&((struct PokeSummaryWork *)work)->mon;
    ((struct PokeSummaryWork *)work)->procArgs.party = (uptr)((struct PokeSummaryMon *)q)->party;
    ((struct PokeSummaryWork *)work)->procArgs.config = ((struct PokeSummaryMon *)q)->config;
    ((struct PokeSummaryWork *)work)->procArgs.gameData = GAMESYSTEM_GetGameData(((struct PokeSummaryMon *)q)->gameSystem);
    zero = 0;
    ((struct PokeSummaryWork *)work)->procArgs.type = zero;
    ((struct PokeSummaryWork *)work)->procArgs.partyPos = zero;
    ((struct PokeSummaryWork *)work)->procArgs.slotCount = 1;
    ((struct PokeSummaryWork *)work)->procArgs.record = POKE_SUMMARY_MAIN_GetRecordWord((char **)work);
    ((struct PokeSummaryWork *)work)->procArgs.enabled = 2;
    ((struct PokeSummaryWork *)work)->procArgs.mode = zero;
    ((struct PokeSummaryWork *)work)->procArgs.nationalDexEnabled = zero;
    GAMESYSTEM_CallProc(((struct PokeSummaryMon *)(*(char * *)&((struct PokeSummaryWork *)work)->mon))->gameSystem, (uptr)k_83, gPokeStatusProcData, work + 0x180);
    return 12;
}

int POKE_SUMMARY_ACTOR_StartNetRestart(void *work)
{
    unsigned char v;

    POKE_SUMMARY_MAIN_InitScreen(work);
    POKE_SUMMARY_ACTOR_PositionMonActor(work, (unsigned char)(*(unsigned short *)((char *)((struct PokeSummaryWork *)work)->mon + 0x14)), 3);
    GFL_NET_RefreshWmIconAtTopRight(1, 0x4f);
    v = ((struct PokeSummaryWork *)work)->procArgs.netFlagB;
    if (v == 0) {
        v = ((struct PokeSummaryWork *)work)->procArgs.netFlagA;
    } else {
        v = 4;
    }
    *(unsigned char *)((char *)((struct PokeSummaryWork *)work)->mon + 0x1b) = v;
    ((struct PokeSummaryWork *)work)->state = 7;
    return 0;
}

void POKE_SUMMARY_ACTOR_CreateSound(u8 *work) {struct CursorMove *q;q=(struct CursorMove *)CURSOR_MOVE_Create((struct CursorEntry *)d_021B83A8,(struct CursorVtbl *)d_021B81DC,(uptr)work,1,0,79);((struct PokeSummaryWork *)work)->sound=q;CURSOR_MOVE_ClearSkipBit((struct Cursor *)q,8);POKE_SUMMARY_ACTOR_UpdateScrollArrows((char *)work);}

/*
 *   CURSOR_MOVE_Delete (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int POKE_SUMMARY_ACTOR_UpdateSound(int *work)
{
    return CURSOR_MOVE_Delete((void *)(((struct PokeSummaryWork *)work)->sound));
}

void POKE_SUMMARY_ACTOR_Noop(void)
{
}

void POKE_SUMMARY_ACTOR_SelectRow(char *work,int row,int old)
{
    
    POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,0);
    if(row<=3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        ((struct PokeSummaryWork *)work)->mon->selectedIndex=row;
        if(((struct PokeSummaryWork *)work)->mon->scrollIndex+((struct PokeSummaryWork *)work)->mon->selectedIndex<((struct PokeSummaryWork *)work)->moveCount) POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
        else POKE_SUMMARY_MAIN_DrawMoveDetail(work,-2);
    } else if(row==6) {
        if(old==3 && ((struct PokeSummaryWork *)work)->mon->scrollIndex+4<((struct PokeSummaryWork *)work)->moveCount) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,row=3);
            (((struct PokeSummaryWork *)work)->mon->scrollIndex)++;
            POKE_SUMMARY_MAIN_RedrawMoveList(work);
            POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(work);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)work,1);
        } else if(old==0) {
            if(((struct PokeSummaryWork *)work)->mon->scrollIndex!=0) {
                GFL_USE_PlaySeDefaultVolume(0x54C);
                (((struct PokeSummaryWork *)work)->mon->scrollIndex)--;
                POKE_SUMMARY_MAIN_RedrawMoveList(work);
                POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
                POKE_SUMMARY_ACTOR_UpdateScrollArrows(work);
                POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)work,-1);
            }
            row=0;
            CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,0);
        } else {
            row=3;
            CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,3);
        }
    } else GFL_USE_PlaySeDefaultVolume(0x54C);
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)work,(u8)row,3);
}

/*
 *   one --thumb, no region: EXACT, 10 bytes, blocker260E4.log.
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p,unsigned value) {
 *       p[13]=value; p[14]=255; p[15]=255;
 *   }
 */
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *work,int i)
{
    if(i<=3) {
        ((struct PokeSummaryWork *)work)->mon->selectedIndex=i;
        if(((struct PokeSummaryWork *)work)->mon->scrollIndex+((struct PokeSummaryWork *)work)->mon->selectedIndex<((struct PokeSummaryWork *)work)->moveCount) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,1);
            POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
        } else {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,0);
            POKE_SUMMARY_MAIN_DrawMoveDetail(work,-2);
        }
    } else if(i==4) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=((struct PokeSummaryWork *)work)->mon->selectedIndex;
        (((struct PokeSummaryWork *)work)->mon->scrollIndex)++;
        POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
        POKE_SUMMARY_MAIN_RedrawMoveList(work);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(work);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)work,1);
        CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,i);
    } else if(i==5) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=((struct PokeSummaryWork *)work)->mon->selectedIndex;
        (((struct PokeSummaryWork *)work)->mon->scrollIndex)--;
        POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
        POKE_SUMMARY_MAIN_RedrawMoveList(work);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(work);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)work,-1);
        CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,i);
    } else if(i==6) {
        if(((struct PokeSummaryWork *)work)->cursorIndex!=6) {
            i=((struct PokeSummaryWork *)work)->mon->selectedIndex;
            CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,i);
        }
    } else if(i==7) {
        i=((struct PokeSummaryWork *)work)->mon->selectedIndex;
        CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,i);
    } else if(i==8) {
        if(((struct PokeSummaryWork *)work)->cursorIndex!=6) {
            i=((struct PokeSummaryWork *)work)->mon->selectedIndex;
            CURSOR_MOVE_SetCurrent(((struct PokeSummaryWork *)work)->sound,i);
        }
    }
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)work,(u8)i,3);
}

/*
 * extent: padding at 0x021B7F4E; separate follower POKE_SUMMARY_ACTOR_IsTaskMenuOpen at 0x021B7F50.
 */
void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *work, int flag)
{
    if (flag == 1) {
        if (*(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[0] == 0) {
            *(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[0] = (uptr)APP_TASKMENU_WIN_Create(((struct PokeSummaryWork *)work)->taskMenuRes, (struct TaskMenuItem *)((work + 0x1e4)), 13, 21, 9, 0x4f);
            *(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[1] = (uptr)APP_TASKMENU_WIN_Create(((struct PokeSummaryWork *)work)->taskMenuRes, (struct TaskMenuItem *)((work + 0x1f0)), 22, 21, 9, 0x4f);
            CURSOR_MOVE_SetSkipBit(((struct PokeSummaryWork *)work)->sound, 8);
            ((struct PokeSummaryWork *)work)->cursorSkipFlag = 1;
            return;
        }
    } else {
        if (*(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[0] != 0) {
            APP_TASKMENU_WIN_Delete(((struct PokeSummaryWork *)work)->taskMenuWindows[0]);
            APP_TASKMENU_WIN_Delete(((struct PokeSummaryWork *)work)->taskMenuWindows[1]);
            BG_SYS_PushTile(4);
            *(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[0] = 0;
            *(u32 *)&((struct PokeSummaryWork *)work)->taskMenuWindows[1] = 0;
        }
        CURSOR_MOVE_ClearSkipBit(((struct PokeSummaryWork *)work)->sound, 8);
        ((struct PokeSummaryWork *)work)->cursorSkipFlag = 0;
    }
}

int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *work)
{
    if (((struct PokeSummaryWork *)work)->taskMenuWindows[0] != 0)
        return 1;
    return 0;
}

void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *work)
{
    if (((struct PokeSummaryWork *)work)->moveCount < 4) {
        CURSOR_MOVE_ClearSkipBit(((struct PokeSummaryWork *)work)->sound, 4);
        CURSOR_MOVE_ClearSkipBit(((struct PokeSummaryWork *)work)->sound, 5);
        return;
    }
    if (((struct PokeSummaryWork *)work)->mon->scrollIndex == 0)
        CURSOR_MOVE_ClearSkipBit(((struct PokeSummaryWork *)work)->sound, 5);
    else
        CURSOR_MOVE_SetSkipBit(((struct PokeSummaryWork *)work)->sound, 5);
    if (((struct PokeSummaryWork *)work)->mon->scrollIndex + 4 >= ((struct PokeSummaryWork *)work)->moveCount) {
        CURSOR_MOVE_ClearSkipBit(((struct PokeSummaryWork *)work)->sound, 4);
        return;
    } else {
        CURSOR_MOVE_SetSkipBit(((struct PokeSummaryWork *)work)->sound, 4);
        return;
    }
}

void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *work,int direction)
{
    CLACT_SetActorAnimFrame(((struct PokeSummaryWork *)work)->actors[1],0);
    CLACT_SetActorAnimFrame(((struct PokeSummaryWork *)work)->actors[0],0);
    if(direction>0) {
        if(((struct PokeSummaryWork *)work)->mon->scrollIndex+4 < ((struct PokeSummaryWork *)work)->moveCount) CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],10);
        else CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],23);
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],3);
    } else {
        if(((struct PokeSummaryWork *)work)->mon->scrollIndex==0) CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],24);
        else CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],11);
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],2);
    }
}

void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *work)
{
    if(((struct PokeSummaryWork *)work)->moveCount<=4) {
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],17);
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],16);
        return;
    }
    if(((struct PokeSummaryWork *)work)->mon->scrollIndex+4 < ((struct PokeSummaryWork *)work)->moveCount) {
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],17);
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],2);
        return;
    }
    if(((struct PokeSummaryWork *)work)->mon->scrollIndex==0) {
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[1],3);
        CLACT_SetActorAnimSeq(((struct PokeSummaryWork *)work)->actors[0],16);
    }
}

int POKE_SUMMARY_ACTOR_OpenDecideWin(char *work, u16 result)
{
    char *q = work + 0x1d0;

    ((struct PokeSummaryDecide *)q)->active = 0;
    ((struct PokeSummaryDecide *)q)->windowIndex = 0xd;
    ((struct PokeSummaryDecide *)q)->result = result;
    CLACT_SetActorAnimSeq((struct ClactActor *)(((struct PokeSummaryWork *)work)->actors[13]), 9);
    return 0xd;
}

int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *work,u16 result) {u8 *q;q=work+464;((struct PokeSummaryDecide *)q)->active=1;((struct PokeSummaryDecide *)q)->windowIndex=0;((struct PokeSummaryDecide *)q)->result=result;APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)(*(char **)(work+((struct PokeSummaryDecide *)q)->windowIndex*4+544)),1);return 13;}

int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *work,unsigned short id) {unsigned short *q=(unsigned short *)(work+0x1d0);q[5]=1;q[3]=1;q[4]=id;APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)(*(char **)((uptr)work+q[3]*4+0x220)),1);return 13;}

int POKE_SUMMARY_ACTOR_WaitDecide(u8 *work)
{
    u8 *s;
    s=work+464;
    if(((struct PokeSummaryDecide *)s)->active==0) {
        if(CLACT_IsActorAnimActive(*(void **)(work+260+((struct PokeSummaryDecide *)s)->windowIndex*4))==0) return ((struct PokeSummaryDecide *)s)->result;
    } else if(((struct PokeSummaryDecide *)s)->active==1) {
        if(APP_TASKMENU_WIN_IsFinish(*(void **)(work+544+((struct PokeSummaryDecide *)s)->windowIndex*4))!=0) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)work,0);
            return ((struct PokeSummaryDecide *)s)->result;
        }
    }
    return 13;
}

int POKE_SUMMARY_ACTOR_ShowTextKind2(char *work)
{
    POKE_SUMMARY_MAIN_StartTextStream(work, 2);
    ((struct PokeSummaryWork *)work)->textKind = 1;
    ((struct PokeSummaryWork *)work)->state = 3;
    return 2;
}

int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *work) {unsigned char flag;if(POKE_SUMMARY_MAIN_CountFreeMoves((void ***)work)<4) {POKE_SUMMARY_MAIN_StartTextStream(work,1);flag=0;} else {POKE_SUMMARY_MAIN_StartTextStream(work,4);flag=2;}((struct PokeSummaryWork *)work)->textKind=flag;((struct PokeSummaryWork *)work)->state=3;return 2;}

void POKE_SUMMARY_ACTOR_SetSubBrightness(int enable)
{
    volatile unsigned short *p = (volatile unsigned short *)REG_DB_BLDCNT_ADDR;

    if (enable == 1) {
        G2x_SetBlendBrightness_((uptr)p, 0x1e, -8);
    } else {
        *p = 0;
    }
}

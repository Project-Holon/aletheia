/*
 * file:     viewer_text.c
 * unit:     yes
 * function: VIEWER_TEXT_Init, VIEWER_TEXT_Exit, VIEWER_TEXT_Draw, VIEWER_TEXT_DrawTable, VIEWER_TEXT_DrawList, VIEWER_TEXT_FlushWindow, VIEWER_TEXT_DrawWindow, VIEWER_TEXT_PrintColorAt, VIEWER_TEXT_DrawRow, VIEWER_TEXT_AddRow, VIEWER_TEXT_BuildRowList, VIEWER_TEXT_DrawPage, VIEWER_TEXT_PrintNumber, VIEWER_TEXT_PrintDigits, VIEWER_TEXT_PrintString, VIEWER_TEXT_PrintStringClipped, VIEWER_TEXT_PrintStringPad, VIEWER_TEXT_PrintWrapped, VIEWER_TEXT_Print, VIEWER_TEXT_PrintRow, VIEWER_TEXT_NoOp, VIEWER_TEXT_InitActors, VIEWER_TEXT_CreateActor, VIEWER_TEXT_DeleteActors, VIEWER_TEXT_SetActorAnim, VIEWER_TEXT_Create, VIEWER_TEXT_Main, VIEWER_TEXT_Delete, VIEWER_TEXT_VBlank, VIEWER_TEXT_LoadResources, VIEWER_TEXT_FreeResources, VIEWER_TEXT_InitVram, VIEWER_TEXT_InitBg, VIEWER_TEXT_ExitBg, VIEWER_TEXT_LoadBgResources, VIEWER_TEXT_FreeBgResources, VIEWER_TEXT_InitClact
 * address:  0x021C6000
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   d_021C8773  0x021C8773  data
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   PMS_DRAW_Print  0x0202DC48  thumb
 *   PMS_DRAW_SetVisible  0x0202DCB0  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GAME_DATA_GetTrainerCardSign  0x02012F5C  thumb
 *   TRCARD_SIGN_GetSeenBefore  0x020089F4  thumb
 *   CURSOR_MOVE_GetTableKind  0x02025C9C  thumb
 *   d_021C876C     0x021C876C  data  a1
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021C8768     0x021C8768  data  a2
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   WORDSET_FormatNumber  0x0201F35C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PLAYTIME_GetHours  0x0200864C  thumb
 *   PLAYTIME_GetMinutes  0x02008650  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021C87A4     0x021C87A4  data  a4
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   VIEWER_ACTOR_CreateObjects  0x021C75E4  thumb
 *   VIEWER_ACTOR_Init3D  0x021C76A4  thumb
 *   VIEWER_ACTOR_CreateModel  0x021C7744  thumb
 *   VIEWER_ACTOR_InitBgWindow  0x021C78C4  thumb
 *   VIEWER_ACTOR_CreateFont  0x021C7934  thumb
 *   VIEWER_ACTOR_SetSelection  0x021C81A4  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   VIEWER_ACTOR_DispatchState  0x021C79A0  thumb
 *   VIEWER_ACTOR_DrawModel  0x021C7830  thumb
 *   VIEWER_ACTOR_PrintQueMain  0x021C7970  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   VIEWER_ACTOR_DeleteFont  0x021C795C  thumb
 *   VIEWER_ACTOR_DeleteBgWindow  0x021C78F8  thumb
 *   VIEWER_ACTOR_DeleteModel  0x021C7808  thumb
 *   VIEWER_ACTOR_Exit3D  0x021C7730  thumb
 *   VIEWER_ACTOR_DeleteObjects  0x021C7658  thumb
 *   VIEWER_ACTOR_SaveBadgeTimers  0x021C81C0  thumb
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_GetHeapHeadChecked  0x0203084C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Create  0x0201EC74  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   VIEWER_ACTOR_SetPageCount  0x021C80B4  thumb
 *   VIEWER_ACTOR_LoadBadgeTimers  0x021C8208  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C88FC  0x021C88FC  data
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   d_021C895C  0x021C895C  data
 *   d_021C89E0  0x021C89E0  data
 *   d_021C885C  0x021C885C  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_MENUWORK_LoadPltt  0x0201F57C  thumb
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "viewer_types.h"
#include "../sdk_ioreg.h"

struct CharBuf;
struct Descriptor;
struct PrintSys;
struct PmsDraw;
struct Strbuf;
struct Cfg;
struct MsgBank;
struct Rec;
struct Sub020089A8Obj;
struct U16Vec;
struct StrObj;
struct WordSet;
struct PlayTime;
struct Bank;
struct Obj;
struct Actor;
struct Proc;
struct Proc;
struct Node;
struct DispVram;
struct DispConfig;

typedef struct {
    u16 x;
    u16 y;
    u8 chr;
    u8 cell;
    u8 anm;
    u8 pri;
    u32 z;
} ViewerActorTemplate;

typedef struct {
    ViewerActorTemplate t[8];
} ViewerActorTemplateTable;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pad6;
    u8 pri;
} ViewerActorPos;

typedef struct { u32 w[4]; } ViewerBankCfg;

#include "../sdk_gx.h"

#include "../arm9/bmp_win.h"
struct BmpWin;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#ifdef __MWERKS__
#define BG_SYS_InitBgLayer BG_SYS_InitBgLayer_hdr
#endif
#include "../arm9/bg_sys.h"

typedef struct { struct BgTemplate t[6]; } ViewerBgTemplates;
#ifdef __MWERKS__
#undef BG_SYS_InitBgLayer
void BG_SYS_InitBgLayer(u8, const struct BgTemplate *, int);
#endif
#include "../arm9/bmp_menuwork.h"
#include "../arm9/arc_util.h"
struct PrintQueue;
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_hdr
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
void PRINTSYS_PrintColor(struct Bmp *, short, short, struct Strbuf *, struct GfFont *, unsigned short);
#endif
struct GfFont;
#include "../arm9/strbuf.h"
#include "../arm9/pms_draw.h"
struct BeaconDetailGraQuad;
#include "../arm9/msgdata.h"
struct GameData;
#include "../arm9/game_data.h"
struct TrainerCardSignature;
#include "../arm9/trcard_sign.h"
#include "../arm9/cursor_move.h"
#include "../arm9/wordset.h"
#include "../arm9/playtime.h"
#include "../arm9/arc_tool.h"
struct DispVramCfg;
struct SysInit;
#include "../arm9/clact.h"
#include "../arm9/app_icon.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "viewer_actor.h"
#include "../arm9/net.h"
#include "../arm9/wipe.h"
#include "../arm9/gfl_heap_wrap.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/g2.h"
void VIEWER_TEXT_Init(ViewerWork *p);
void VIEWER_TEXT_Exit(ViewerWork *p);
void VIEWER_TEXT_Draw(ViewerWork *p, void **bg, const ViewerInfo *info);
void VIEWER_TEXT_DrawTable(ViewerWork *p, int k, int flush);
void VIEWER_TEXT_DrawList(ViewerWork *p, int k, int flush);
void VIEWER_TEXT_FlushWindow(ViewerWork *p, void **bg);
void VIEWER_TEXT_DrawWindow(ViewerWork *p, void *bg, void *info);
void VIEWER_TEXT_PrintColorAt(void *a, ViewerWork *p, int x, int y, void *s, int idx);
void VIEWER_TEXT_DrawRow(ViewerWork *p, void *a, u32 sel, int y, int idx);
void VIEWER_TEXT_AddRow(ViewerWork *p, int v);
void VIEWER_TEXT_BuildRowList(void *p, ViewerInfo *info);
void VIEWER_TEXT_DrawPage(ViewerWork *p, int scroll, int flush, int idx);
void VIEWER_TEXT_PrintNumber(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
void VIEWER_TEXT_PrintDigits(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
void VIEWER_TEXT_PrintString(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
void VIEWER_TEXT_PrintStringClipped(ViewerWork *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col);
void VIEWER_TEXT_PrintStringPad(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
void VIEWER_TEXT_PrintWrapped(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
void VIEWER_TEXT_Print(ViewerWork *p, void *a, int x, int dx, int y, void *s);
void VIEWER_TEXT_PrintRow(ViewerWork *p, void *a, int y, const ViewerInfo *info, void *s, int idx);
void VIEWER_TEXT_NoOp(void *work, void *bg, u32 flag, void *str);
void VIEWER_TEXT_InitActors(ViewerAnim *a, const struct DispVramCfg *x);
void VIEWER_TEXT_CreateActor(ViewerAnim *a);
void VIEWER_TEXT_DeleteActors(ViewerAnim *a);
void VIEWER_TEXT_SetActorAnim(ViewerAnim *p, int idx, u8 a, u8 b);
int VIEWER_TEXT_Create(void *proc, int *seq, void *parent);
int VIEWER_TEXT_Main(void *a, void *b, int c, ViewerTextWork *p);
int VIEWER_TEXT_Delete(void *proc, void *seq, int c, ViewerTextWork *p);
void VIEWER_TEXT_VBlank(struct TcbTask *unused, void *pArg);
void VIEWER_TEXT_LoadResources(ViewerTextWork *p, ViewerArgs *parent);
void VIEWER_TEXT_FreeResources(ViewerTextWork *p);
void VIEWER_TEXT_InitVram(void);
void VIEWER_TEXT_InitBg(ViewerTextWork *p);
void VIEWER_TEXT_ExitBg(ViewerTextWork *p);
void VIEWER_TEXT_LoadBgResources(ViewerTextWork *p);
void VIEWER_TEXT_FreeBgResources(ViewerTextWork *p);
void VIEWER_TEXT_InitClact(ViewerTextWork *p);
extern const u8 d_021C8773[8][6];
extern const u8 d_021C876C[];
extern const u16 d_021C8768[];
extern const u8 gClActorInitParam[];
extern const ViewerActorTemplateTable d_021C87A4;
extern const unsigned char d_021C88FC[];
extern const ViewerBankCfg d_021C895C;
extern const ViewerBgTemplates d_021C89E0;
extern const u32 d_021C885C[];





/*
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_Init(ViewerWork *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    BMP_WIN_Init(p->heap);
    for (i = 0; i < 8; i++) {
        p->bg[i] = (void *)BMP_WIN_Create(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        BMP_Clear(BMP_WIN_GetBmp(p->bg[i]), 0);
    }
    BG_SYS_Init(7, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(4, 0x31, 0xD, p->charVariant, p->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    BG_SYS_MarkTileDirty(7);
    BG_SYS_MarkTileDirty(4);
    p->printQue = (void *)PRINTSYS_QUE_Create((u32)p->heap);
}





void VIEWER_TEXT_Exit(ViewerWork *p)
{
    u16 i;

    PRINTSYS_QUE_Delete(p->printQue);
    for (i = 0; i < 8; i++) {
        BMP_WIN_Delete(p->bg[i]);
    }
    BMP_WIN_Exit();
}




/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_Draw(ViewerWork *p, void **bg, const ViewerInfo *info)
{
    u8 i;
    void *s;

    for (i = 0; i < 5; i++) {
        BMP_Clear(BMP_WIN_GetBmp(bg[i]), 0);
        if (i != 3 || (i == 3 && info->f4_2)) {
            PRINTSYS_Print(BMP_WIN_GetBmp(bg[i]), 0, 0, p->msgText[i], p->font);
        }
    }
    s = p->strbuf3;
    STRBUF_SetString(p->strbuf2, info->name);
    VIEWER_TEXT_Print((ViewerWork *)p, bg[0], 0x88, 8, 0, p->strbuf2);
    if (info->f4_2) {
        VIEWER_TEXT_PrintStringPad((ViewerWork *)p, bg[3], 0x88, 8, 0, s, info->topPadValue, 1, 0);
    }
    VIEWER_TEXT_DrawTable((ViewerWork *)p, info->rowIndex, 0);
    VIEWER_TEXT_DrawList((ViewerWork *)p, info->listIndex, 0);
    VIEWER_TEXT_PrintDigits((ViewerWork *)p, bg[4], 0xD8, 8, 0, s, info->topValue, 7, 1, 1, 0);
    PMS_DRAW_SetNullColorPalette(p->pmsDraw, 0);
    PMS_DRAW_Print(p->pmsDraw, bg[5], (struct BeaconDetailGraQuad *)p->info->decoData, 0);
    if (p->decoVisible != 0) {
        PMS_DRAW_SetVisible(p->pmsDraw, 0, 0);
    }
}









void VIEWER_TEXT_DrawTable(ViewerWork *p, int k, int flush)
{
    void *bank;
    void *str;
    u32 w;

    bank = MSGDATA_CreateFromArchive(0, 2, 0xBF, p->heap);
    if (TRCARD_SIGN_GetSeenBefore(GAME_DATA_GetTrainerCardSign(p->args->gameData))) {
        str = MSGDATA_AllocString(bank, CURSOR_MOVE_GetTableKind(k));
    } else {
        str = MSGDATA_AllocString(bank, 0);
    }
    w = PRINTSYS_MeasureWidestLine(str, p->font, 0);
    BMP_Clear(BMP_WIN_GetBmp(p->bg[1]), 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[1]), 0x80 - w, 0, str, p->font);
    STRBUF_Delete(str);
    MSGDATA_Delete(bank);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[1]);
        BMP_WIN_TransferChars(p->bg[1]);
        BG_SYS_MarkTileDirty(7);
    }
}










void VIEWER_TEXT_DrawList(ViewerWork *p, int k, int flush)
{
    void *str;
    u32 w;

    str = MSGDATA_AllocString(p->msgBank, k + 0x1F);
    w = PRINTSYS_MeasureWidestLine(str, p->font, 0);
    BMP_Clear(BMP_WIN_GetBmp(p->bg[2]), 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[2]), 0, 0, p->msgText[2], p->font);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[2]), 0x80 - w, 0, str, p->font);
    STRBUF_Delete(str);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[2]);
        BMP_WIN_TransferChars(p->bg[2]);
        BG_SYS_MarkTileDirty(7);
    }
}










void VIEWER_TEXT_FlushWindow(ViewerWork *p, void **bg)
{
    int i;

    if (p->decoVisible != 0) {
        BMP_WIN_MakeScreen(bg[6]);
        BMP_WIN_TransferChars(bg[6]);
    } else {
        for (i = 0; i <= 5; i++) {
            if (d_021C876C[i] != 0) {
                BMP_WIN_MakeScreen(bg[i]);
                BMP_WIN_TransferChars(bg[i]);
            }
        }
    }
    BG_SYS_MarkTileDirty(7);
    BG_SYS_MarkTileDirty(4);
}








void VIEWER_TEXT_DrawWindow(ViewerWork *p, void *bg, void *info)
{
    VIEWER_TEXT_DrawPage((ViewerWork *)p, p->scroll, 0, 0);
}







void VIEWER_TEXT_PrintColorAt(void *a, ViewerWork *p, int x, int y, void *s, int idx)
{
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x, y, s, p->font, d_021C8768[idx]);
}






void VIEWER_TEXT_DrawRow(ViewerWork *p, void *a, u32 sel, int y, int idx)
{
    void *s = p->strbuf3;
    ViewerInfo *info = p->info;
    u32 w;

    switch (sel) {
    case 0:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[5], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0x60, 0, y, s, info->row0Value, 5, 2, idx);
        break;
    case 1:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[6], idx);
        VIEWER_TEXT_PrintRow((ViewerWork *)p, a, y, (ViewerInfo *)((const ViewerInfo *)p->info), p->strbuf0, idx);
        break;
    case 2:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[7], idx);
        break;
    case 3:
        VIEWER_TEXT_PrintString((ViewerWork *)p, a, 0xD8, 0, y, s, 0, idx);
        break;
    case 4:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[8], idx);
        break;
    case 5:
        if (info->month2 != 0) {
            VIEWER_TEXT_PrintStringClipped((ViewerWork *)p, a, 0xD8, 0, y, s, 0, idx);
        } else {
            w = PRINTSYS_MeasureWidestLine(p->msgText[24], p->font, 0);
            VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0xD8 - w, y, p->msgText[24], idx);
        }
        break;
    case 6:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[9], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row6Value, 9, 1, idx);
        break;
    case 7:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[10], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row7Value, 9, 1, idx);
        break;
    case 8:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[11], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row8Value, 9, 1, idx);
        break;
    case 9:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[12], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row9Value, 9, 1, idx);
        break;
    case 10:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[13], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row10Value, 9, 1, idx);
        break;
    case 11:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[14], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row11Value, 9, 1, idx);
        break;
    case 12:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[15], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row12Value, 9, 1, idx);
        break;
    case 13:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[16], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row13Value, 5, 1, idx);
        break;
    case 14:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[17], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row14Value, 4, 1, idx);
        break;
    case 15:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[18], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row15Value, 2, 1, idx);
        break;
    case 16:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[19], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row16Value, 4, 1, idx);
        break;
    case 17:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[20], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row17Value, 3, 1, idx);
        break;
    case 18:
        VIEWER_TEXT_PrintColorAt(a, (ViewerWork *)p, 0, y, p->msgText[21], idx);
        VIEWER_TEXT_PrintNumber((ViewerWork *)p, a, 0xD8, 8, y, s, info->row18Value, 4, 1, idx);
        break;
    }
}






void VIEWER_TEXT_AddRow(ViewerWork *p, int v)
{
    p->rowList[p->rowCount] = v;
    p->rowCount++;
}






void VIEWER_TEXT_BuildRowList(void *p, ViewerInfo *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        VIEWER_TEXT_AddRow(p, i);
    }
    if (info->hasRow14) {
        VIEWER_TEXT_AddRow(p, 14);
        VIEWER_TEXT_AddRow(p, 13);
    }
    if (info->hasRow15) {
        VIEWER_TEXT_AddRow(p, 15);
    }
    if (info->hasRow16) {
        VIEWER_TEXT_AddRow(p, 16);
    }
    if (info->hasRow17) {
        VIEWER_TEXT_AddRow(p, 17);
    }
    if (info->hasRow18) {
        VIEWER_TEXT_AddRow(p, 18);
    }
}






void VIEWER_TEXT_DrawPage(ViewerWork *p, int scroll, int flush, int idx)
{
    void *bg = p->bg[6];
    int i;
    int top = -(scroll / 16);

    BMP_Clear(BMP_WIN_GetBmp(bg), 0);
    for (i = 0; i < 5; i++) {
        VIEWER_TEXT_DrawRow((ViewerWork *)p, bg, p->rowList[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        BMP_WIN_TransferChars(bg);
        BMP_WIN_MakeScreen(bg);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(bg));
    }
}






void VIEWER_TEXT_PrintNumber(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx)
{
    u32 w;

    WORDSET_FormatNumber(s, n, kind, mode, 1);
    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font, d_021C8768[idx]);
}





void VIEWER_TEXT_PrintDigits(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->wordSet, 0, n, digits, mode, 1);
    WORDSET_CopyTaggedText(p->wordSet, (void *)(s), p->taggedText[k]);
    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font, d_021C8768[idx]);
}





void VIEWER_TEXT_PrintString(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->wordSet, 0, p->info->year1 + 2000, 4, mode, 1);
    WORDSET_SetSlotNumber(p->wordSet, 1, p->info->month1, 2, mode, 1);
    WORDSET_SetSlotNumber(p->wordSet, 2, p->info->day1, 2, mode, 1);
    WORDSET_CopyTaggedText(p->wordSet, (void *)(s), p->taggedText[2]);
    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font, d_021C8768[idx]);
}






void VIEWER_TEXT_PrintStringClipped(ViewerWork *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col)
{
    int w;

    WORDSET_SetSlotNumber(p->wordSet, 0, p->info->year2 + 2000, 4, mode, 1);
    WORDSET_SetSlotNumber(p->wordSet, 1, p->info->month2, 2, mode, 1);
    WORDSET_SetSlotNumber(p->wordSet, 2, p->info->day2, 2, mode, 1);
    WORDSET_SetSlotNumber(p->wordSet, 3, p->info->row2Value, 2, 2, 1);
    WORDSET_SetSlotNumber(p->wordSet, 4, p->info->row5Value, 2, 2, 1);
    WORDSET_CopyTaggedText(p->wordSet, str, p->taggedText[3]);
    w = PRINTSYS_MeasureWidestLine(str, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(win), x - (w + ofs), y, str, p->font, d_021C8768[col]);
}






void VIEWER_TEXT_PrintStringPad(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx)
{
    u32 w;

    WORDSET_SetSlotNumber(p->wordSet, 0, n, 3, mode, 1);
    WORDSET_CopyTaggedText(p->wordSet, (void *)(s), p->taggedText[4]);
    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font, d_021C8768[idx]);
}






void VIEWER_TEXT_PrintWrapped(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx)
{
    u32 w;

    WORDSET_FormatNumber(s, n, kind, mode, 1);
    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font, d_021C8768[idx]);
}






void VIEWER_TEXT_Print(ViewerWork *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = PRINTSYS_MeasureWidestLine(s, p->font, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->font);
}






void VIEWER_TEXT_PrintRow(ViewerWork *p, void *a, int y, const ViewerInfo *info, void *s, int idx)
{
    int v;

    if (info->playTime == 0) {
        VIEWER_TEXT_PrintWrapped((ViewerWork *)p, a, 0xD8, 0, y, s, info->row1Pad, 2, 2, 0xD0, 0x10, idx);
        VIEWER_TEXT_PrintWrapped((ViewerWork *)p, a, 0xD8, 0x13, y, s, info->row1Value, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->strbuf1, p->font, d_021C8768[idx]);
    } else {
        v = PLAYTIME_GetHours(info->playTime);
        if (v > 999) {
            v = 999;
        }
        VIEWER_TEXT_PrintWrapped((ViewerWork *)p, a, 0xD8, 0, y, s, PLAYTIME_GetMinutes(info->playTime), 2, 2, 0xD0, 0x10, idx);
        VIEWER_TEXT_PrintWrapped((ViewerWork *)p, a, 0xD8, 0x13, y, s, v, 3, 1, 0xAD, 0x1B, idx);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), 0xC6, y, p->strbuf1, p->font, d_021C8768[idx]);
    }
}






void VIEWER_TEXT_NoOp(void *work, void *bg, u32 flag, void *str) { }






void VIEWER_TEXT_InitActors(ViewerAnim *a, const struct DispVramCfg *x)
{
    void *h;

    h = ARC_TOOL_CreateHandle(0x28, a->heap);
    CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam, x, a->heap);
    a->unit = CLACT_CreateUnit(0x23, 0, a->heap);
    a->res[0].palette = CLACT_RegisterPaletteEx(h, 0xC, 1, 0, 0, 5, a->heap);
    a->res[0].chr = CLACT_RegisterCharacter(h, 0x1D, 0, 1, a->heap);
    a->res[0].cellAnim = CLACT_RegisterCellAnim(h, 0x2E, 0x30, a->heap);
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), a->heap);
    a->res[1].palette = CLACT_RegisterPalette(h, APP_ICON_GetMoveKindPaletteFileId(), 1, 0xA0, a->heap);
    a->res[1].chr = CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, 1, a->heap);
    a->res[1].cellAnim = CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(0), APP_ICON_GetStatusPaletteFileId(0), a->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}






void VIEWER_TEXT_CreateActor(ViewerAnim *a)
{
    ViewerActorTemplateTable tbl = d_021C87A4;
    ViewerActorPos pos;
    int i;

    for (i = 0; i < 8; i++) {
        pos.x = tbl.t[i].x;
        pos.y = tbl.t[i].y;
        pos.z = tbl.t[i].z;
        pos.pri = tbl.t[i].pri;
        a->obj[i] = CLACT_CreateActor(a->unit, a->res[tbl.t[i].cell].palette, a->res[tbl.t[i].chr].chr, a->res[tbl.t[i].anm].cellAnim, (const struct ActorInitParam *)&pos, 1, a->heap);
        CLACT_SetActorDrawEnable(a->obj[i], 1);
        CLACT_SetActorAutoAnimSpeed(a->obj[i], 0x1000);
        CLACT_SetActorAutoAnim(a->obj[i], 1);
        if (i == 3) {
            CLACT_SetActorDrawEnable(a->obj[i], 0);
        }
    }
    CLACT_SetActorDrawEnable(a->obj[5], 0);
}






void VIEWER_TEXT_DeleteActors(ViewerAnim *a)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        CLACT_ReleasePalette(a->res[i].palette);
        CLACT_ReleaseCharacter(a->res[i].chr);
        CLACT_ReleaseCellAnim(a->res[i].cellAnim);
    }
    CLACT_DeleteUnit(a->unit);
    CLACT_ExitSystem();
    *(volatile u32 *)REG_DISPCNT_ADDR = (*(volatile u32 *)REG_DISPCNT_ADDR & ~0x300010) | 0x10;
}






void VIEWER_TEXT_SetActorAnim(ViewerAnim *p, int idx, u8 a, u8 b)
{
    CLACT_SetActorAnimSeq(p->obj[idx], a);
    CLACT_RestartActorAnim(p->obj[idx]);
    CLACT_SetActorDrawEnable(p->obj[idx], b);
}






int VIEWER_TEXT_Create(void *proc, int *seq, void *parent)
{
    ViewerTextWork *p;

    GFL_HEAP_CreateChildHeap(1, 0x27, 0x20000);
    p = PROCSYS_AllocProcWork(proc, sizeof(*p), 0x27);
    MIi_CpuClearFast(0, p, sizeof(*p));
    VIEWER_TEXT_LoadResources((ViewerTextWork *)p, (ViewerArgs *)parent);
    VIEWER_TEXT_InitVram();
    VIEWER_TEXT_InitBg((ViewerTextWork *)p);
    VIEWER_TEXT_LoadBgResources((ViewerTextWork *)p);
    VIEWER_TEXT_InitClact((ViewerTextWork *)p);
    VIEWER_ACTOR_CreateObjects(p);
    VIEWER_ACTOR_Init3D(p);
    VIEWER_ACTOR_CreateModel(p);
    VIEWER_ACTOR_InitBgWindow(p);
    VIEWER_ACTOR_CreateFont(p);
    VIEWER_ACTOR_SetSelection(p, p->page);
    GFL_NET_RefreshWmIconAtTopRight(1, 0x27);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}






int VIEWER_TEXT_Main(void *a, void *b, int c, ViewerTextWork *p)
{
    if (VIEWER_ACTOR_DispatchState(p) == 0) {
        return 1;
    }
    VIEWER_ACTOR_DrawModel(p);
    VIEWER_ACTOR_PrintQueMain(p);
    CLACT_DrawSystem();
    if (++p->vblankCount >= 0x100) {
        p->vblankCount = 0;
    }
    return 0;
}





int VIEWER_TEXT_Delete(void *proc, void *seq, int c, ViewerTextWork *p)
{
    VIEWER_ACTOR_DeleteFont(p);
    VIEWER_ACTOR_DeleteBgWindow(p);
    VIEWER_ACTOR_DeleteModel(p);
    VIEWER_ACTOR_Exit3D(p);
    VIEWER_ACTOR_DeleteObjects(p);
    VIEWER_TEXT_FreeBgResources((ViewerTextWork *)p);
    VIEWER_TEXT_ExitBg((ViewerTextWork *)p);
    VIEWER_TEXT_FreeResources((ViewerTextWork *)p);
    VIEWER_ACTOR_SaveBadgeTimers(p);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_GetHeapHeadChecked(0x27);
    GFL_HEAP_DeleteChecked(0x27);
    return 1;
}





void VIEWER_TEXT_VBlank(struct TcbTask *unused, void *pArg)
{
    ViewerTextWork *p = pArg;
    int v = -(p->vblankCount / 2);

    BG_SYS_ChangeScrollImmediate(6, 0, v);
    BG_SYS_ChangeScrollImmediate(6, 3, v);
    BG_SYS_ChangeScrollImmediate(3, 0, v);
    BG_SYS_ChangeScrollImmediate(3, 3, v);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}





void VIEWER_TEXT_LoadResources(ViewerTextWork *p, ViewerArgs *parent)
{
    int i;

    p->parent = parent;
    p->action = 0;
    p->arc = ARC_TOOL_CreateHandle(0x28, 0x27);
    p->msgBank = MSGDATA_CreateFromArchive(0, 2, 0xBB, 0x27);
    for (i = 0; i < 7; i++) {
        p->rowText[i] = MSGDATA_AllocString(p->msgBank, i);
        STRBUF_GetChars(p->rowText[i]);
    }
    p->strbuf = STRBUF_Create(0x68, 0x27);
    p->wordSet = WORDSET_Create(8, 0x40, 0x27);
    p->vblankTask = GFL_USE_AddMainTask(VIEWER_TEXT_VBlank, (void *)p, 0);
    p->rowCount = 8;
    p->snap = -1;
    VIEWER_ACTOR_SetPageCount(p);
    p->saveBlock = GAME_DATA_GetTrainerCardSign(p->parent->gameData);
    VIEWER_ACTOR_LoadBadgeTimers(p);
}





void VIEWER_TEXT_FreeResources(ViewerTextWork *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        STRBUF_Delete(p->rowText[i]);
    }
    STRBUF_Delete(p->strbuf);
    WORDSET_Delete(p->wordSet);
    MSGDATA_Delete(p->msgBank);
    TCB_DeleteTask(p->vblankTask);
    ARC_TOOL_DeleteHandle(p->arc);
}





static inline void GX_SetDispSelect(GXDispSelect sel)
{
    *(volatile u16 *)REG_POWCNT1_ADDR = (u16)((*(volatile u16 *)REG_POWCNT1_ADDR & ~0x8000) | (sel << 15));
}





void VIEWER_TEXT_InitVram(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C88FC);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
}





void VIEWER_TEXT_InitBg(ViewerTextWork *p)
{
    ViewerBankCfg bank;
    ViewerBgTemplates tmpl;
    u32 i;

    BG_SYS_Create(0x27);
    bank = d_021C895C;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&bank));
    tmpl = d_021C89E0;
    for (i = 0; i < 6; i++) {
        u32 v = d_021C885C[i];
        BG_SYS_InitBgLayer(v, &tmpl.t[i], 0);
        BG_SYS_ClearSlot((u8)v);
        BG_SYS_InitRun(v, 0x20, 0, 0x27);
        BG_SYS_SetPlaneVisible(v, 1);
    }
    BG_SYS_SetPlaneVisible(7, 0);
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 2, 4, 7, 0x10);
}





void VIEWER_TEXT_ExitBg(ViewerTextWork *p)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        BG_SYS_FreeLayerBuf((u8)d_021C885C[i]);
    }
    BG_SYS_Delete();
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
}





/*
 * lever:    enum-typed zero in the eighth call preserves copied argument registers and the preceding late heap store.
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_TEXT_LoadBgResources(ViewerTextWork *p)
{
    typedef enum { Zero } ZeroArg;
    ZeroArg z = Zero;
    void *arc = p->arc;
    void *arc2;
    int i;

    ARC_UTIL_UploadBgCharFromHandle(arc, 0x19, 6, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x22, 6, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 4, 0, 0, 0x27);
    ARC_UTIL_UploadBgCharFromHandle(arc, 0x1A, 5, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x23, 5, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgCharFromHandle(arc, 0x19, 3, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x22, 3, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, z, z, z, z, 0x27);
    ARC_UTIL_UploadBgCharFromHandle(arc, 0x19, 1, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x21, 1, 0, 0, 0, 0x27);
    arc2 = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x27);
    ARC_UTIL_UploadBgCharFromHandle(arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0, 0x27);
    ARC_UTIL_UploadBgPaletteFromHandle(arc2, APP_ICON_GetStatusDataFileId(), 2, 0, 0, 0, 0x27);
    ARC_UTIL_UploadPaletteFromHandle(arc2, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x1C0, 0x20, 0x27);
    BG_SYS_FillTileMap(2, 0, 0x15, 0x20, 3, 0xE);
    BG_SYS_PushTile(2);
    ARC_TOOL_DeleteHandle(arc2);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1E0, 0x20, 0x27);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1E0, 0x20, 0x27);
    BMP_MENUWORK_LoadPltt(4, 0xE, 0, 0x27);
    BMP_MENUWORK_LoadChar(4, 1, 0, 0x27);
    for (i = 0; i < 3; i++) {
        p->res14C[i] = ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc, 4 - i, (&p->res158[i]), 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->res164[i] = ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc, 0x17 - i, (&p->res170[i]), 0x27);
    }
}





void VIEWER_TEXT_FreeBgResources(ViewerTextWork *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        GFL_HEAP_Free(p->res164[i]);
    }
    for (i = 0; i < 3; i++) {
        GFL_HEAP_Free(p->res14C[i]);
    }
}





void VIEWER_TEXT_InitClact(ViewerTextWork *p)
{
    void *arc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x27);

    CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam, (const struct DispVramCfg *)d_021C88FC, 0x27);
    p->unit = CLACT_CreateUnit(0x24, 1, 0x27);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    p->resSet.named.chr = CLACT_RegisterCharacter(p->arc, 0x1B, 0, 0, 0x27);
    p->resSet.named.palette = CLACT_RegisterPalette(p->arc, 2, 0, 0, 0x27);
    p->resSet.named.cellAnim = CLACT_RegisterCellAnim(p->arc, 0x2D, 0x2F, 0x27);
    p->resSet.named.chr2 = CLACT_RegisterCharacter(arc, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x27);
    p->resSet.named.palette2 = CLACT_RegisterPaletteEx(arc, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x160, 0, 3, 0x27);
    p->resSet.named.cellAnim2 = CLACT_RegisterCellAnim(arc, APP_ICON_GetStatusCellFileId(0), APP_ICON_GetStatusPaletteFileId(0), 0x27);
    ARC_TOOL_DeleteHandle(arc);
}

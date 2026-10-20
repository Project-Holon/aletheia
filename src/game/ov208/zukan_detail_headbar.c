/*
 * file:     zukan_detail_headbar.c
 * unit:     yes
 * function: ZUKAN_DETAIL_HEADBAR_Create, ZUKAN_DETAIL_HEADBAR_Delete, ZUKAN_DETAIL_HEADBAR_Update, ZUKAN_DETAIL_HEADBAR_SetIconKind, ZUKAN_DETAIL_HEADBAR_GetIconKind, ZUKAN_DETAIL_HEADBAR_SetIconSpecies, ZUKAN_DETAIL_HEADBAR_SetIconForm, ZUKAN_DETAIL_HEADBAR_NoOp, ZUKAN_DETAIL_HEADBAR_CreateWindows, ZUKAN_DETAIL_HEADBAR_DeleteWindows, ZUKAN_DETAIL_HEADBAR_DrawIcon, ZUKAN_DETAIL_HEADBAR_ClearIcon, ZUKAN_DETAIL_HEADBAR_FlushIcon
 * address:  0x021BE710
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_headbar.c, zukan_detail_page.c, zukan_detail_voice.c, zukan_detail_form.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Create 0x021BE710 thumb
 *   ZUKAN_DETAIL_HEADBAR_Delete 0x021BE778 thumb ov208
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Update 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   ZUKAN_DETAIL_HEADBAR_DrawIcon 0x021BE920 thumb ov208
 *   ZUKAN_DETAIL_HEADBAR_NoOp 0x021BE864 thumb ov208
 *   d_021C8DFC 0x021C8DFC data a1
 *   ZUKAN_DETAIL_HEADBAR_FlushIcon 0x021BE9CC thumb ov208
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_GetByteSize 0x020437EC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BG_SYS_CreateTileRun 0x02040B58 arm
 *   ARC_UTIL_UploadBgPaletteAddFromArchive 0x0204994C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_CopyPixels        0x02043814  arm
 *   BMP_Delete        0x020437AC  arm
 *   MSGDATA_AllocString        0x02045EC0  arm
 *   PRINTSYS_PrintQueColor        0x0201C724  thumb
 *   STRBUF_Delete        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind  0x021BE840  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind  0x021BE82C  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies  0x021BE844  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm  0x021BE854  thumb  ov208
 */
#include "zukan_detail_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_util.h"

#include "../arm9/bg_sys.h"

#include "../arm9/arc_tool.h"


struct TcbTask;

#include "../arm9/tcb_list.h"
struct PrintQueue;

#include "../arm9/printsys.h"


struct Ov208PalTbl {
    u32 v[5];
};


#include "../arm9/gfl_use.h"





extern void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *);

extern void ZUKAN_DETAIL_HEADBAR_NoOp(void *);


extern void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *);

struct BmpWin;

#include "../arm9/bmp_win.h"
struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"







#include "../arm9/msgdata.h"




struct Strbuf;

struct GfFont;


#include "../arm9/strbuf.h"




struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg);

void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Icon *m);

void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon *p, int kind);

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_NoOp(void *p);

void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Icon *g);

void ZUKAN_DETAIL_HEADBAR_DeleteWindows(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_ClearIcon();

void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *p);

extern const char d_021C8DFC[];

extern const struct Ov208PalTbl data_021C84F4;

struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg)
{
    struct Ov208Icon *p=GFL_HEAP_Alloc(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->font=arg;p->state=0;p->kind=5;
    BG_SYS_ChangeScrollImmediate(5,3,24);
    BG_SYS_SetPriority(5,0);
    ZUKAN_DETAIL_HEADBAR_CreateWindows(p);
    ZUKAN_DETAIL_HEADBAR_DrawIcon(p);
    p->task=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))((unsigned)ZUKAN_DETAIL_HEADBAR_NoOp),(void *)((unsigned)p),1);
    p->queue=(unsigned int)PRINTSYS_QUE_Create((unsigned int)(unsigned)p->heap);
    p->dirty=0;
    return p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Icon *m)
{
    PRINTSYS_QUE_Clear((void *)m->queue);
    PRINTSYS_QUE_Delete((struct PrintQueue *)m->queue);
    TCB_DeleteTask((struct TcbTask *)m->task);
    ZUKAN_DETAIL_HEADBAR_ClearIcon(m);
    ZUKAN_DETAIL_HEADBAR_DeleteWindows(m);
    GFL_HEAP_Free(m);
}

/*
 * matching: direct byte field access avoids a persistent extracted pointer register.
 */
void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p)
{
    switch(p->state) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)BG_SYS_GetScrollY(5)<=0) {
                BG_SYS_ChangeScroll(5,3,0);p->state=2;
            } else {BG_SYS_ChangeScroll(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)BG_SYS_GetScrollY(5)>=24) {
                BG_SYS_ChangeScroll(5,3,24);p->state=0;
            } else {BG_SYS_ChangeScroll(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    ZUKAN_DETAIL_HEADBAR_FlushIcon(p);
    PRINTSYS_QUE_Main((struct PrintQueue *)p->queue);
}

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon *p, int kind)
{
    p->kind = kind;
    ZUKAN_DETAIL_HEADBAR_ClearIcon();
    ZUKAN_DETAIL_HEADBAR_DrawIcon(p);
}

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon *p)
{
    return p->state;
}

void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->count = 0;
    }
}

void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->count = 0;
    }
}

void ZUKAN_DETAIL_HEADBAR_NoOp(void *p)
{
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Icon *g)
{
    g->window = (unsigned int)BMP_WIN_Create((unsigned int)5, (unsigned int)0, (unsigned int)0, 0x10, 1, 13, 0);
    BMP_Clear((struct Bmp *)((int)BMP_WIN_GetBmp((struct BmpWin *)g->window)), 0);
    BMP_WIN_TransferChars((struct BmpWin *)g->window);
    g->bmp = BMP_CreateFromArchive(0x9f, 14, 0, g->heap);
    g->size = BMP_GetByteSize(g->bmp);
    g->tile = BG_SYS_CreateTileRun(5, BMP_GetPixels(g->bmp), g->size);
    ARC_UTIL_UploadBgPaletteAddFromArchive(0x9f, 0x25, 5, 0, g->tile, 0xc0, 0, g->heap);
    BG_SYS_FillTileMap(5, 0, 0, 0x20, 0x18, 13);
    g->msg = MSGDATA_CreateFromArchive(0, 2, 0xea, g->heap);
}

void ZUKAN_DETAIL_HEADBAR_DeleteWindows(struct Ov208Icon *p)
{
    MSGDATA_Delete((struct MsgBank *)p->msg);
    BG_SYS_FreeTileRun(5, p->tile, p->size);
    BMP_Delete((struct Bmp *)p->bmp);
    BMP_WIN_Delete((struct BmpWin *)p->window);
}

void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->kind < 0 || p->kind >= 5)
        return;
    h = ARC_TOOL_CreateHandle(0x9f, p->heap);
    pal = data_021C84F4;
    ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, pal.v[p->kind] << 5, 0x1a0, 0x20, p->heap);
    ARC_TOOL_DeleteHandle(h);
    h = BMP_CreateFromArchive(0x9f, 0xe, 0, p->heap);
    BMP_CopyPixels((const struct Bmp *)h, (struct Bmp *)p->bmp);
    BMP_Delete(h);
    s = (u32)MSGDATA_AllocString(p->msg, p->kind + 0xb2);
    PRINTSYS_PrintQueColor((void *)p->queue, p->bmp, 0x18, 5, (struct Strbuf *)s, (struct GfFont *)p->font, 0x3dc0);
    STRBUF_Delete((struct Strbuf *)s);
    p->dirty = 1;
    ZUKAN_DETAIL_HEADBAR_FlushIcon(p);
}

void ZUKAN_DETAIL_HEADBAR_ClearIcon()
{
}

void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *p)
{
    if (p->dirty != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)p->queue, (void *)p->bmp) == 0) {
        BG_SYS_LoadTileData(5, BMP_GetPixels((const struct Bmp *)p->bmp), p->size, p->tile);
        BG_SYS_MarkTileDirty(5);
        p->dirty = 0;
    }
}

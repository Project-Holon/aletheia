/*
 * file:     zknsearch_result.c
 * unit:     yes
 * function: ZKNSEARCH_RESULT_InitFrameList, ZKNSEARCH_RESULT_DeleteFrameList, ZKNSEARCH_RESULT_SetRow1, ZKNSEARCH_RESULT_Noop1, ZKNSEARCH_RESULT_Noop2, ZKNSEARCH_RESULT_SetRow2, ZKNSEARCH_RESULT_Noop3, ZKNSEARCH_RESULT_MoveRow1, ZKNSEARCH_RESULT_SetRowMulti, ZKNSEARCH_RESULT_Noop4, ZKNSEARCH_RESULT_MoveRow2, ZKNSEARCH_RESULT_SetRow3, ZKNSEARCH_RESULT_Noop5, ZKNSEARCH_RESULT_MoveRow3, ZKNSEARCH_RESULT_SetRow4, ZKNSEARCH_RESULT_Noop6, ZKNSEARCH_RESULT_MoveRow4
 * address:  0x021C04CC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   d_021C0CC0 0x021C0CC0 data a4
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 *   ZKNSEARCH_MAIN_PrintListRow 0x021BEC60 thumb ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor 0x021BF7B0 thumb ov210
 *   ZKNSEARCH_MAIN_MoveColumnActors 0x021BFBF8 thumb ov210
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 *   ZKNSEARCH_MAIN_GetListIndexB 0x021BCEF0 thumb ov210
 *   ZKNSEARCH_MAIN_TransferRowChars 0x021BECAC thumb ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor3 0x021BFA14 thumb ov210
 *   ZKNSEARCH_MAIN_PlacePageActor 0x021BFB8C thumb ov210
 *   ZKNSEARCH_MAIN_MoveScrollActors  0x021BFCE4  thumb  ov210
 */
#include "zknsearch_types.h"

struct FrameList;
struct Tmpl;
struct U16Vec;

typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;



#include "../arm9/arc_tool.h"
struct FrameListParams;
#include "../ov067/frame_list.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "zknsearch_main.h"
void ZKNSEARCH_RESULT_InitFrameList(ZknSearchWork *ctx);
void ZKNSEARCH_RESULT_DeleteFrameList(ZknSearchWork *work);
void ZKNSEARCH_RESULT_SetRow1(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop1(void);
void ZKNSEARCH_RESULT_Noop2(void);
void ZKNSEARCH_RESULT_SetRow2(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop3(void);
void ZKNSEARCH_RESULT_MoveRow1(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRowMulti(ZknSearchWork *work,int index,void *data,int value,int flag);
void ZKNSEARCH_RESULT_Noop4(void);
void ZKNSEARCH_RESULT_MoveRow2(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRow3(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop5(void);
void ZKNSEARCH_RESULT_MoveRow3(ZknSearchWork *work, int delta);
void ZKNSEARCH_RESULT_SetRow4(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag);
void ZKNSEARCH_RESULT_Noop6(void);
void ZKNSEARCH_RESULT_MoveRow4(ZknSearchWork *work, int delta);
extern const Template d_021C0CC0;






void ZKNSEARCH_RESULT_InitFrameList(ZknSearchWork *ctx)
{
    void *archive = ARC_TOOL_CreateHandle(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ctx->frameList = FRAME_LIST_Create((struct FrameListParams *)(&config), 123);
    ctx->entryCount = config.count;
    FRAME_LIST_CopyMapToBuffer(ctx->frameList, archive, 98, 0, 0);
    FRAME_LIST_LoadPalettes(ctx->frameList, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i < 14; i++) FRAME_LIST_AddItem(ctx->frameList, 0, i);
}







/*
 * Addresses are Black-image addresses.
 */
void ZKNSEARCH_RESULT_DeleteFrameList(ZknSearchWork *work)
{
    unsigned i;

    FRAME_LIST_Delete((struct FrameList *)(work->frameList));
    work->frameList = 0;
    for (i = 0; i < 0x32; i++) {
        if (work->entries[i] != 0) {
            STRBUF_Delete(work->entries[i]);
            work->entries[i] = 0;
        }
    }
}






void ZKNSEARCH_RESULT_SetRow1(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow(work, window, work->entries[row]);
    if (work->save->record[1] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor(work, 0, y, flag);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop1(void)
{
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop2(void)
{
}





void ZKNSEARCH_RESULT_SetRow2(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow(work, window, work->entries[row]);
    if (work->save->record[2] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor(work, 0, y, flag);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop3(void)
{
}






void ZKNSEARCH_RESULT_MoveRow1(ZknSearchWork *work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors(work, 1);
}






/*
 * trailing: unit aligns the bx-lr follower at 021C065C after zero pad
 * 021C065A; two additional zero alignment bytes at 021C065E follow the unit.
 */
void ZKNSEARCH_RESULT_SetRowMulti(ZknSearchWork *work,int index,void *data,int value,int flag)
{
    ZKNSEARCH_MAIN_PrintListRow(work,data,work->entries[index]);
    if(index==PM_LANG_JA(ZKNSEARCH_MAIN_GetListIndexB(work, work->save->record[3]), ZKNSEARCH_MAIN_LookupSavedEntryId(work, work->save->record[3])))ZKNSEARCH_MAIN_PlaceColumnActor(work,0,value,flag);
    if(index==PM_LANG_JA(ZKNSEARCH_MAIN_GetListIndexB(work, work->save->record[4]), ZKNSEARCH_MAIN_LookupSavedEntryId(work, work->save->record[4])))ZKNSEARCH_MAIN_PlaceColumnActor(work,1,value,flag);
}






void ZKNSEARCH_RESULT_Noop4(void){}







void ZKNSEARCH_RESULT_MoveRow2(ZknSearchWork *work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors(work, 1);
}





void ZKNSEARCH_RESULT_SetRow3(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow(work, window, work->entries[row]);
    if (work->save->record[5] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor(work, 0, y, flag);
}





/* hidden function: empty leaf (bx lr) in an address gap */
/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void ZKNSEARCH_RESULT_Noop5(void)
{
}




void ZKNSEARCH_RESULT_MoveRow3(ZknSearchWork *work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors(work, 1);
}




void ZKNSEARCH_RESULT_SetRow4(ZknSearchWork *work, unsigned row, ZknSearchBmpWin *window, int y, int flag)
{
    ZKNSEARCH_MAIN_TransferRowChars(work, window);
    if (work->save->record[6] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor3(work, y, flag);
    ZKNSEARCH_MAIN_PlacePageActor(work, (unsigned short)row, y, flag);
}


/* Empty callback. */
void ZKNSEARCH_RESULT_Noop6(void)
{
}


void ZKNSEARCH_RESULT_MoveRow4(ZknSearchWork *work, int delta)
{
    ZKNSEARCH_MAIN_MoveScrollActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors(work, 1);
}

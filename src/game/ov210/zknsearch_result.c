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
typedef int YCoord;
#include "zknsearch_main.h"
void ZKNSEARCH_RESULT_InitFrameList(char *ctx);
void ZKNSEARCH_RESULT_DeleteFrameList(u8 *p);
void ZKNSEARCH_RESULT_SetRow1(int p, unsigned a, int b, int c, int d);
void ZKNSEARCH_RESULT_Noop1(void);
void ZKNSEARCH_RESULT_Noop2(void);
void ZKNSEARCH_RESULT_SetRow2(int p, unsigned a, int b, int c, int d);
void ZKNSEARCH_RESULT_Noop3(void);
void ZKNSEARCH_RESULT_MoveRow1(int p, int v);
void ZKNSEARCH_RESULT_SetRowMulti(char *p,int index,void *data,int value,int flag);
void ZKNSEARCH_RESULT_Noop4(void);
void ZKNSEARCH_RESULT_MoveRow2(int p, int v);
void ZKNSEARCH_RESULT_SetRow3(int p, unsigned a, int b, int c, int d);
void ZKNSEARCH_RESULT_Noop5(void);
void ZKNSEARCH_RESULT_MoveRow3(int p, int v);
void ZKNSEARCH_RESULT_SetRow4(int p, unsigned a, unsigned *b, int c, int d);
void ZKNSEARCH_RESULT_Noop6(void);
void ZKNSEARCH_RESULT_MoveRow4(int a, int b);
extern const Template d_021C0CC0;






void ZKNSEARCH_RESULT_InitFrameList(char *ctx)
{
    void *archive = ARC_TOOL_CreateHandle(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((ZknSearchWork *)ctx)->frameList = FRAME_LIST_Create((struct FrameListParams *)(&config), 123);
    ((ZknSearchWork *)ctx)->entryCount = config.count;
    FRAME_LIST_CopyMapToBuffer(((ZknSearchWork *)ctx)->frameList, archive, 98, 0, 0);
    FRAME_LIST_LoadPalettes(((ZknSearchWork *)ctx)->frameList, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i < 14; i++) FRAME_LIST_AddItem(((ZknSearchWork *)ctx)->frameList, 0, i);
}







/*
 * Addresses are Black-image addresses.
 */
void ZKNSEARCH_RESULT_DeleteFrameList(u8 *work)
{
    unsigned i;

    FRAME_LIST_Delete((struct FrameList *)(((ZknSearchWork *)work)->frameList));
    ((ZknSearchWork *)work)->frameList = 0;
    for (i = 0; i < 0x32; i++) {
        int *q = (int *)(work + i * 4);

        if (q[0x79] != 0) {
            STRBUF_Delete((struct Strbuf *)q[0x79]);
            q[0x79] = 0;
        }
    }
}






void ZKNSEARCH_RESULT_SetRow1(int work, unsigned row, int window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow((char *)work, (int *)window, *(struct Strbuf **)(work + row * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((ZknSearchWork *)work)->save + 2))[1] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor((char *)work, 0, y, flag);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop1(void)
{
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop2(void)
{
}





void ZKNSEARCH_RESULT_SetRow2(int work, unsigned row, int window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow((char *)work, (int *)window, *(struct Strbuf **)(work + row * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((ZknSearchWork *)work)->save + 2))[2] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor((char *)work, 0, y, flag);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void ZKNSEARCH_RESULT_Noop3(void)
{
}






void ZKNSEARCH_RESULT_MoveRow1(int work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)work, 1);
}






/*
 * trailing: unit aligns the bx-lr follower at 021C065C after zero pad
 * 021C065A; two additional zero alignment bytes at 021C065E follow the unit.
 */
void ZKNSEARCH_RESULT_SetRowMulti(char *work,int index,void *data,int value,int flag)
{
    ZKNSEARCH_MAIN_PrintListRow(work,data,(*(struct Strbuf **)(work+484+index*4)));
    if(index==ZKNSEARCH_MAIN_GetListIndexB((uptr)work,(unsigned char)(*(char **)(*(char * *)&((ZknSearchWork *)work)->save+8))[3]))ZKNSEARCH_MAIN_PlaceColumnActor(work,0,value,flag);
    if(index==ZKNSEARCH_MAIN_GetListIndexB((uptr)work,(unsigned char)(*(char **)(*(char * *)&((ZknSearchWork *)work)->save+8))[4]))ZKNSEARCH_MAIN_PlaceColumnActor(work,1,value,flag);
}






void ZKNSEARCH_RESULT_Noop4(void){}







void ZKNSEARCH_RESULT_MoveRow2(int work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)work, 1);
}





void ZKNSEARCH_RESULT_SetRow3(int work, unsigned row, int window, int y, int flag)
{
    ZKNSEARCH_MAIN_PrintListRow((char *)work, (int *)window, *(struct Strbuf **)(work + row * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((ZknSearchWork *)work)->save + 2))[5] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor((char *)work, 0, y, flag);
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




void ZKNSEARCH_RESULT_MoveRow3(int work, int delta)
{
    ZKNSEARCH_MAIN_MoveColumnActors(work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)work, 1);
}




void ZKNSEARCH_RESULT_SetRow4(int work, unsigned row, unsigned *window, int y, int flag)
{
    ZKNSEARCH_MAIN_TransferRowChars(work, window);
    if ((*(u8 **)(*(int * *)&((ZknSearchWork *)work)->save + 2))[6] == row)
        ZKNSEARCH_MAIN_PlaceColumnActor3((char *)work, y, flag);
    ZKNSEARCH_MAIN_PlacePageActor((char *)work, (unsigned short)row, y, flag);
}


/* Empty callback. */
void ZKNSEARCH_RESULT_Noop6(void)
{
}


void ZKNSEARCH_RESULT_MoveRow4(int work, int delta)
{
    ZKNSEARCH_MAIN_MoveScrollActors((char *)work, (signed char)(-delta));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)work, 1);
}

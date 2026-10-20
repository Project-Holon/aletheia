/*
 * file:     manual_common.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateData, MANUAL_COMMON_DeleteData, MANUAL_COMMON_DrawData, MANUAL_COMMON_SetScreenId, MANUAL_COMMON_InitDisplay, MANUAL_COMMON_DataNoop
 * address:  0x021B9D18
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from manual_common.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MANUAL_GRAPHIC_CreateScreen 0x021B9900 thumb ov225
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   gManualCommonDataAllocFile 0x021BC004 data ov225 a1
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MANUAL_GRAPHIC_DeleteScreen 0x021B99A0 thumb ov225
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   MANUAL_GRAPHIC_DrawScreen 0x021B99F4 thumb ov225
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MANUAL_COMMON_CreateMenuTable 0x021B9B3C thumb ov225
 *   MANUAL_COMMON_DeleteMenuTable 0x021B9BA4 thumb ov225
 *   MANUAL_COMMON_GetDefaultId 0x021B9CDC thumb ov225
 *   MANUAL_COMMON_CreateTouchbar 0x021B9F24 thumb ov225
 *   MANUAL_COMMON_DeleteTouchbar 0x021B9F8C thumb ov225
 */
#include "../version.h"
#include "../sdk_ioreg.h"

#if VERSION == VERSION_WHITE
#define MANUAL_MSG_ARCHIVE_1 63
#else
#define MANUAL_MSG_ARCHIVE_1 62
#endif
#include "../types.h"
#include "manual_common_shared_types.h"

struct GfFont;

struct MsgBank;

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_util.h"


#include "manual_graphic.h"

#include "../arm9/gf_font.h"
struct PrintQueue;

#include "../arm9/printsys.h"

#include "../arm9/msgdata.h"

#include "../arm9/arc_tool.h"










#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"

#include "../arm9/bg_sys.h"

extern void PRINTSYS_QUE_Clear(struct PrintQueue *),BMP_WIN_Delete(struct Descriptor *);

#include "manual_data.h"



void *MANUAL_COMMON_CreateData(void *owner,u16 heap);

void MANUAL_COMMON_DeleteData(char *p);

void MANUAL_COMMON_DrawData(char *p);

void MANUAL_COMMON_SetScreenId(char *p,unsigned id);

void MANUAL_COMMON_InitDisplay(void *unused);

void MANUAL_COMMON_DataNoop(void *unused);

#include "manual_touchbar.h"


extern const char gManualCommonDataAllocFile[];

void *MANUAL_COMMON_CreateData(void *owner,u16 heap)
{
    struct ManualData *data=GFL_HEAP_Alloc(heap,0x38,1,gManualCommonDataAllocFile,0x4b);
    data->owner=owner; data->heap=heap;
    data->screen=MANUAL_GRAPHIC_CreateScreen(1,data->heap);
    data->font=(uptr)GF_FONT_Create(23,0,0,0,data->heap);
    data->printQue[0]=(uptr)PRINTSYS_QUE_Create((u32)(u32)data->heap);
    data->printQue[1]=(uptr)PRINTSYS_QUE_Create((u32)(u32)data->heap);
    data->printQue[2]=(uptr)PRINTSYS_QUE_Create((u32)(u32)data->heap);
    data->bank[0]=MSGDATA_CreateFromArchive(0,2,61,data->heap);
    data->bank[1]=MSGDATA_CreateFromArchive(0,2,MANUAL_MSG_ARCHIVE_1,data->heap);
    data->arc[0]=ARC_TOOL_CreateHandle(223,data->heap);
    data->arc[1]=ARC_TOOL_CreateHandle(231,data->heap);
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,64,32,data->heap);
    data->assets=MANUAL_COMMON_CreateMenuTable(data->arc[0],data->heap);
    MANUAL_COMMON_InitDisplay(data);
    data->id=65535;
    MANUAL_COMMON_SetScreenId((char *)data,MANUAL_COMMON_GetDefaultId(data->assets));
    data->group=MANUAL_COMMON_CreateTouchbar((char *)data);
    return data;
}

void MANUAL_COMMON_DeleteData(char *data)
{
    MANUAL_COMMON_DeleteTouchbar(((struct ManualData *)data)->group);MANUAL_COMMON_SetScreenId(data,0xffff);MANUAL_COMMON_DataNoop(data);
    MANUAL_COMMON_DeleteMenuTable(((struct ManualData *)data)->assets);ARC_TOOL_DeleteHandle(((struct ManualData *)data)->arc[0]);ARC_TOOL_DeleteHandle(((struct ManualData *)data)->arc[1]);
    MSGDATA_Delete(*(struct MsgBank * *)&((struct ManualData *)data)->bank[0]);MSGDATA_Delete(*(struct MsgBank * *)&((struct ManualData *)data)->bank[1]);
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[0]);PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[0]));
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[1]);PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[1]));
    PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[2]);PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[2]));
    GF_FONT_Delete((void *)((struct ManualData *)data)->font);MANUAL_GRAPHIC_DeleteScreen(*(char * *)&((struct ManualData *)data)->screen);GFL_HEAP_Free(data);
}

void MANUAL_COMMON_DrawData(char *data){PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[0]));PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[1]));PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintQueue * *)&((struct ManualData *)data)->printQue[2]));MANUAL_GRAPHIC_DrawScreen(*(char * *)&((struct ManualData *)data)->screen);}

void MANUAL_COMMON_SetScreenId(char *data,unsigned id)
{
    if(((struct ManualData *)data)->id!=id) {
        unsigned size;
        void *buf;
        ((struct ManualData *)data)->id=id;
        if(((struct ManualData *)data)->id==0xffff) {
            buf=GFL_HEAP_Alloc(((struct ManualData *)data)->heap,0x18000,1,gManualCommonDataAllocFile,245);
            size=0x18000;
        } else {
            buf=ARC_UTIL_LoadHandleMemberWithSize(((struct ManualData *)data)->arc[1],((struct ManualData *)data)->id,1,((struct ManualData *)data)->heap,&size);
        }
        DC_FlushRange(buf,size);GX_LoadBG2Scr(buf,0,0x18000);GFL_HEAP_Free(buf);
    }
}

/*
 * volatile: 021B9EEC,021B9EF8 re-read 0400000C;021B9F02 read 04000008.
 */
void MANUAL_COMMON_InitDisplay(void *unused){*(volatile unsigned short *)REG_BG2CNT_ADDR=(*(volatile unsigned short *)REG_BG2CNT_ADDR&0x43)|0x4084;*(volatile unsigned short *)REG_BG2CNT_ADDR=(unsigned short)(*(volatile unsigned short *)REG_BG2CNT_ADDR&~3);*(volatile unsigned short *)REG_BG0CNT_ADDR&=~0x40;BG_SYS_SetPlaneVisible(2,1);}

void MANUAL_COMMON_DataNoop(void *unused){}

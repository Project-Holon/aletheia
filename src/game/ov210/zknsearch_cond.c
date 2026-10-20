/*
 * file:     zknsearch_cond.c
 * function: ZKNSEARCH_COND_InitFrameList
 * address: 0x021C0434
 * packet: pkt_ov210_021C0434
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   d_021C0C98 0x021C0C98 data a4
 */
#include "zknsearch_types.h"
typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;
extern const Template d_021C0C98;
#include "../arm9/arc_tool.h"
struct FrameList;
struct Tmpl;
struct FrameListParams;
#include "../ov067/frame_list.h"
struct MsgBank;
struct Strbuf;
#include "../arm9/msgdata.h"
void ZKNSEARCH_COND_InitFrameList(char *ctx)
{
    void *archive = ARC_TOOL_CreateHandle(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C98;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((ZknSearchWork *)ctx)->frameList = FRAME_LIST_Create((struct FrameListParams *)(&config), 123);
    ((ZknSearchWork *)ctx)->entryCount = config.count;
    FRAME_LIST_CopyMapToBuffer(((ZknSearchWork *)ctx)->frameList, archive, 97, 0, 0);
    FRAME_LIST_LoadPalettes(((ZknSearchWork *)ctx)->frameList, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 96; i <= 105; i++) { FRAME_LIST_AddItem(((ZknSearchWork *)ctx)->frameList, 0, i - 96); ((void **)(ctx + 0x64))[i] = MSGDATA_AllocString(((ZknSearchWork *)ctx)->msgBank, i); }
}

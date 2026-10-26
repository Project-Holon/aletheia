/*
 * file:     zknsearch_list.c
 * unit:     yes
 * function: ZKNSEARCH_LIST_InitFrameList, ZKNSEARCH_LIST_InitFrameList2
 * address:  0x021C02DC
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
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   d_021C0C70 0x021C0C70 data a4
 *   ZKNSEARCH_MAIN_LookupEntryId 0x021BCEF4 thumb ov210
 *   d_021C0C48 0x021C0C48 data a4
 */
#include "zknsearch_types.h"

struct FrameList;
struct Tmpl;
struct MsgBank;

typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;



#include "../arm9/arc_tool.h"
struct FrameListParams;
#include "../ov067/frame_list.h"
struct Strbuf;
#include "../arm9/msgdata.h"
#include "zknsearch_main.h"
void ZKNSEARCH_LIST_InitFrameList(ZknSearchWork *ctx);
void ZKNSEARCH_LIST_InitFrameList2(ZknSearchWork *ctx);
extern const Template d_021C0C70;
extern const Template d_021C0C48;

void ZKNSEARCH_LIST_InitFrameList(ZknSearchWork *ctx)
{
    void *archive = ARC_TOOL_CreateHandle(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C70;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ctx->frameList = FRAME_LIST_Create((struct FrameListParams *)(&config), 123);
    ctx->entryCount = config.count;
    FRAME_LIST_CopyMapToBuffer(ctx->frameList, archive, 97, 0, 0);
    FRAME_LIST_LoadPalettes(ctx->frameList, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i < 26; i++) { FRAME_LIST_AddItem(ctx->frameList, 0, i); ctx->entries[i] = MSGDATA_AllocString(ctx->msgBank, i + 51); }
}

void ZKNSEARCH_LIST_InitFrameList2(ZknSearchWork *ctx)
{
    void *archive = ARC_TOOL_CreateHandle(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C48;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ctx->frameList = FRAME_LIST_Create((struct FrameListParams *)(&config), 123);
    ctx->entryCount = config.count;
    FRAME_LIST_CopyMapToBuffer(ctx->frameList, archive, 97, 0, 0);
    FRAME_LIST_LoadPalettes(ctx->frameList, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i <= 16; i++) { FRAME_LIST_AddItem(ctx->frameList, 0, i); ctx->entries[i] = MSGDATA_AllocString(ctx->msgBank, ZKNSEARCH_MAIN_LookupEntryId(ctx, i)); }
}

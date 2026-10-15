/*
 * function: ZKNSEARCH_RESULT_InitFrameList
 * address: 0x021C04CC
 * packet: pkt_ov210_021C04CC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Template is 40 bytes with ctx at 36; a 44-byte decode adds a stack word and moves its store.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   d_021C0CC0 0x021C0CC0 data a4
 */
#include "../include/Obj06699.h"
typedef unsigned short u16;
typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;
extern const Template d_021C0CC0;
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct S;
struct Tmpl;
extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, unsigned int heap);
extern void FRAME_LIST_CopyMapToBuffer(unsigned char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int index);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void ARC_TOOL_DeleteHandle(void *);
extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);
void ZKNSEARCH_RESULT_InitFrameList(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj06699 *)ctx)->f1E0 = FRAME_LIST_Create((struct Tmpl *)(&config), 123);
    ((struct Obj06699 *)ctx)->f2AC = config.count;
    FRAME_LIST_CopyMapToBuffer(((struct Obj06699 *)ctx)->f1E0, (unsigned int)archive, 98, 0, 0);
    FRAME_LIST_LoadPalettes(((struct Obj06699 *)ctx)->f1E0, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i < 14; i++) FRAME_LIST_AddItem(((struct Obj06699 *)ctx)->f1E0, 0, i);
}

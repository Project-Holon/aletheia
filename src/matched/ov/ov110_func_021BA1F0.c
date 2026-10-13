/*
 * function: PMS_INPUT_VIEW_TaskUpdateCategoryFocus
 * address: 0x021BA1F0
 * packet: pkt_ov110_021BA1F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   PMS_INPUT_VIEW_UpdateCategoryFocus 0x021BAE94 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMS_INPUT_VIEW_UpdateCategoryFocus(u8 *p, u8 *q, void *a2);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskUpdateCategoryFocus(void *unused, u8 *p)
{
    PMS_INPUT_VIEW_UpdateCategoryFocus(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    PMS_INPUT_VIEW_EndTask(p);
}

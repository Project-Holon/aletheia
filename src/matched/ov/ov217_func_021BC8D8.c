/*
 * function: RESEARCH_LIST_DeleteFont
 * address:  0x021BC8D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to GF_FONT_Delete.
 *
 * symbols:
 *   GF_FONT_Delete  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25876.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 GF_FONT_Delete(void *ptr);

void RESEARCH_LIST_DeleteFont(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct Obj25876 *)a0)->fC)));
}


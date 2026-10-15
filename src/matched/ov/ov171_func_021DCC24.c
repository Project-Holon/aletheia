/*
 * function: DENDOU_VIEW_InitText
 * address: 0x021DCC24
 * packet: pkt_ov171_021DCC24
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj03850.h"
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void DENDOU_VIEW_InitText(char *p)
{
    ((struct Obj03850 *)p)->fB60=func_02045B38(0,2,0x55,0x8c);
    ((struct Obj03850 *)p)->fB58=GF_FONT_Create(0x17,0,0,0,0x8c);
    ((struct Obj03850 *)p)->fB5C=GF_FONT_Create(0x17,3,0,0,0x8c);
    ((struct Obj03850 *)p)->fB64=GF_FONT_Create_EC64(0x8c);
    ((struct Obj03850 *)p)->fB6C=(void *)PRINTSYS_QUE_Create((void *)0x8c);
    ((struct Obj03850 *)p)->fB68=STRBUF_Create(0x400,0x8c);
}

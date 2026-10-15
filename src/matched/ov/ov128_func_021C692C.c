/*
 * function: Wf2dmapFriend_InitFont
 * address: 0x021C692C
 * packet: pkt_ov128_021C692C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 */
#include "../include/Obj05377.h"
typedef unsigned char u8;
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *TCBL_Create(unsigned,unsigned,unsigned,unsigned);
extern u32 PRINTSYS_QUE_Create(void *p);
void Wf2dmapFriend_InitFont(u8 *p, int heap)
{
    GF_FONT_SetDefaultTextColor();
    ((struct Obj05377 *)p)->f0=WORDSET_CreateDefault(heap);
    ((struct Obj05377 *)p)->f4=func_02045B38(0,2,211,heap);
    ((struct Obj05377 *)p)->f17C=GF_FONT_Create(23,0,0,0,heap);
    ((struct Obj05377 *)p)->f28=TCBL_Create(heap,heap,3,256);
    ((struct Obj05377 *)p)->f2C=0;
    ((struct Obj05377 *)p)->f34=(void *)PRINTSYS_QUE_Create((void *)heap);
}

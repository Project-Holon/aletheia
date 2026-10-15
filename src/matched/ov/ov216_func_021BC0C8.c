/*
 * function: func_021BC0C8
 * address: 0x021BC0C8
 * packet: pkt_ov216_021BC0C8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Create 0x0203101C arm
 *   func_020490F4 0x020490F4 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj00366.h"
typedef unsigned short u16;

struct Tcbl; struct GfFont; struct WordSet; struct MsgBank; struct U16Vec;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
extern void *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);
extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *STRBUF_Create(unsigned,unsigned);
void func_021BC0C8(char *p)
{
    *(struct Tcbl * *)&((struct Obj00366 *)p)->f18=TCBL_Create(((struct Obj00366 *)p)->f0,((struct Obj00366 *)p)->f0,64,128);
    ((struct Obj00366 *)p)->f54=func_020490F4(173,((struct Obj00366 *)p)->f0);
    GF_FONT_SetTextColor(7,8,15);
    ((struct Obj00366 *)p)->f12C=PRINTSYS_QUE_CreateEx(2048,((struct Obj00366 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00366 *)p)->f128=GF_FONT_Create(23,0,0,0,((struct Obj00366 *)p)->f0);
    *(struct WordSet * *)&((struct Obj00366 *)p)->f138=WORDSET_Create(8,64,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f130=func_02045B38(0,2,7,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f134=func_02045B38(0,2,231,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f13C=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f140=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f144=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
}

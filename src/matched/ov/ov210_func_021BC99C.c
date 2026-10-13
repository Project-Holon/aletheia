/*
 * function: func_021BC99C
 * address:  0x021BC99C
 * packet:   pkt_ov210_021BC99C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct PrintSys;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);

u32 func_021BC99C(u8 *p)
{
    STRBUF_Delete((struct U16Vec *)(((struct Obj00085 *)p)->f1D8));
    func_0201C4C0((struct PrintSys *)(((struct Obj00085 *)p)->f1DC));
    func_0201ED04((struct WordSet *)(((struct Obj00085 *)p)->f1D4));
    GF_FONT_Delete((void *)(((struct Obj00085 *)p)->f1CC));
    return MSGDATA_Delete((struct Rec *)(((struct Obj00085 *)p)->f1D0));
}

/*
 * function: POKELIST_PrintTextSubDirect
 * address:  0x021B9CB0
 * packet:   pkt_ov091_021B9CB0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 */
#include "../include/Obj13242.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);

void POKELIST_PrintTextSubDirect(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj13242 *)p)->f134), idx);
    PRINTSYS_PrintColor((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)win)), x, y, text, (void *)(((struct Obj13242 *)p)->f13C), color);
    STRBUF_Delete(text);
}

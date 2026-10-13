/*
 * function: POKELIST_PrintTextSub
 * address:  0x021B9C64
 * packet:   pkt_ov091_021B9C64
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj09926.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void POKELIST_PrintTextSub(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09926 *)p)->f134), idx);
    PRINTSYS_PrintQueColor((void *)(((struct Obj09926 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, (u32)text,
                  ((struct Obj09926 *)p)->f13C, color);
    STRBUF_Delete(text);
}

/*
 * function: POKELIST_PrintExpandedTextMain
 * address:  0x021B9CF4
 * packet:   pkt_ov091_021B9CF4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj06211.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void POKELIST_PrintExpandedTextMain(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color)
{
    void *buf = STRBUF_Create(16, ((struct Obj06211 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj06211 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    PRINTSYS_PrintQueColor((void *)(((struct Obj06211 *)p)->f140), (u32)func_02045770((struct Descriptor *)win), x, y, (u32)buf,
                  ((struct Obj06211 *)p)->f138, color);
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}

/*
 * function: POKELIST_PrintExpandedTextSubDirect
 * address:  0x021B9DC0
 * packet:   pkt_ov091_021B9DC0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 */
#include "../include/Obj09927.h"

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
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);

void POKELIST_PrintExpandedTextSubDirect(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color)
{
    void *buf = STRBUF_Create(16, ((struct Obj09927 *)p)->f0);
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj09927 *)p)->f134), idx);
    func_0201F250(set, buf, text);
    PRINTSYS_PrintColor((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, buf, (void *)(((struct Obj09927 *)p)->f13C), color);
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}

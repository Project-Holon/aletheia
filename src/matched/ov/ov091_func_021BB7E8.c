/*
 * function: PLIST_MESSAGE_PrintText
 * address:  0x021BB7E8
 * packet:   pkt_ov091_021BB7E8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   PLIST_MESSAGE_RedrawWindow  0x021BBA28  thumb  ov091
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj09930.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PLIST_MESSAGE_RedrawWindow(int a, int b);
extern void func_0201C6EC(struct PrintSys *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void PLIST_MESSAGE_PrintText(u8 *a, u32 *s, u32 x)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj09930 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)STRBUF_Create(0x100, ((struct Obj09930 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        STRBUF_Delete((struct U16Vec *)t);
        t = n;
    }
    PLIST_MESSAGE_RedrawWindow((int)a, (int)s);
    func_0201C6EC((struct PrintSys *)s[10]);
    PRINTSYS_PrintQueColor((void *)s[10], (u32)func_02045770((struct Descriptor *)s[1]), 1, 1, t, ((struct Obj09930 *)a)->f138, 0x440);
    s[9] = 1;
    STRBUF_Delete((struct U16Vec *)t);
}

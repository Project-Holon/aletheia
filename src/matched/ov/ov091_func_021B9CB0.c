/*
 * function: func_021B9CB0
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
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 */
#include "../include/Obj13242.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);

void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0((struct MsgBank *)(((struct Obj13242 *)p)->f134), idx);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)win)), x, y, text, (void *)(((struct Obj13242 *)p)->f13C), color);
    func_02045808(text);
}

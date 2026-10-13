/*
 * function: func_021BA6B8
 * address:  0x021BA6B8
 * packet:   pkt_ov068_021BA6B8
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The stores through a 12-byte element struct (P/Ent) versus the byte-offset
 * reads keep two separate i*12 multiplies, as in the original.
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02028148  0x02028148  thumb
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 */
#include "../include/Obj06169.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 h; u16 x; u16 pad; u32 idx; } Ent;
typedef struct { u8 pad[0x1c]; Ent e[2]; } P;

struct MsgBank;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02028148(u8 *p);
extern u32  APP_TASKMENU_WIN_Create(u32 a, u8 *b, u8 c, u32 d, u32 e, u32 f);

void func_021BA6B8(u8 *p, u32 arg)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 12 + 0x1c) != 0) {
            func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 0x1c)));
        }
        ((P *)p)->e[i].h = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06169 *)p)->f18), i + 8);
        ((P *)p)->e[i].x = 0x39e3;
        ((P *)p)->e[i].idx = i;
        if (*(u32 *)(p + i * 4 + 0x34) != 0) {
            func_02028148((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
        }
        *(u32 *)(p + i * 4 + 0x34) =
            APP_TASKMENU_WIN_Create(((struct Obj06169 *)p)->f14, p + 0x1c + i * 12, i * 9 + 14, 0x15, 9, arg);
    }
}

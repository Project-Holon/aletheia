/*
 * function: func_021CA318
 * address:  0x021CA318
 * packet:   pkt_ov093_021CA318
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

extern u8 *func_021B9934(char *p, int i);
struct Msg;
extern int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);

u8 func_021CA318(u8 *p, const struct Q *q)
{
    int out[1];
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q->f);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->b);
    if (func_021C3810(p, b, a, q->lo, out, q->e, q->hi, (const struct Msg *)((u8 *)q + 8))) return 1;
    return 0;
}

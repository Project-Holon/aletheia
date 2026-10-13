/*
 * function: func_021C9F0C
 * address:  0x021C9F0C
 * packet:   pkt_ov093_021C9F0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_ReplaceMove  0x021D5734  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
};

extern u8 *func_021B9934(char *p, int i);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_POKEPARAM_ReplaceMove(u8 *p, u8 i, u16 a, u8 b, u32 c);

int func_021C9F0C(u8 *w, const struct Cmd *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)w)->fC, 0x1F, c->b4, c->b5, c->b6, c->b7, c->h8);
    BTL_POKEPARAM_ReplaceMove(r, c->b5, c->h8, c->b6, c->b7);
    return 1;
}

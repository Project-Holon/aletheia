/*
 * function: func_021CA1D0
 * address:  0x021CA1D0
 * packet:   pkt_ov093_021CA1D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_RunSickEndEvent  0x021C2CA8  thumb  ov093
 *   BTL_POKEPARAM_PassEffects  0x021D65C8  thumb  ov093
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BSUBWAY_SCR_SetWinCount  0x021CA238  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 pad;
    u8 b4;
    u8 b5;
};

extern u8 *func_021B9934(char *p, int i);
struct Unk021D62A8;
struct Work;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_RunSickEndEvent(u8 *p, u8 *a);
extern void BTL_POKEPARAM_PassEffects(struct Work *p, struct Work *q);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern int BSUBWAY_SCR_SetWinCount(void *p, u8 i);

int func_021CA1D0(u8 *w, const struct Cmd *c)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b5);
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x10) != 0) BTL_SERVER_FLOW_RunSickEndEvent(w, b);
    BTL_POKEPARAM_PassEffects((struct Work *)b, (struct Work *)a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)w)->fC, 0x26, c->b4, c->b5);
    if (BTL_POKEPARAM_HasSubstitute(b) != 0) {
        int r = BSUBWAY_SCR_SetWinCount(w + 0x1AB8, c->b5);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)w)->fC, 0x51, r);
    }
    return 1;
}

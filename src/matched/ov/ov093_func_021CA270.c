/*
 * function: func_021CA270
 * address:  0x021CA270
 * packet:   pkt_ov093_021CA270
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_AddHp  0x021D5FA4  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberIn  0x021BD9D4  thumb  ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn  0x021BDA00  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

extern u8 *func_021B9934(char *p, int i);
struct Unk021D5FA4;
extern void BTL_POKEPARAM_AddHp(struct Unk021D5FA4 *p, u16 n);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021B8DDC(u32 x);
extern int func_021B8DEC(void *p, int s);
extern void BTL_SERVER_FLOW_ProcMemberIn(void *w, int a, int b, int c, int d);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *p);

int func_021CA270(u8 *w, const struct Cmd *c)
{
    int s;
    int a;
    int b;
    BTL_POKEPARAM_AddHp((struct Unk021D5FA4 *)func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4), c->h6);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)w)->fC, 2, c->b4, c->h6);
    *(u8 *)(w + c->b4 + 0x7A9) = 0;
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    s = func_021B8D8C(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC(((struct Obj00003 *)w)->f4, s);
        BTL_SERVER_FLOW_ProcMemberIn(w, a, b, b, 1);
        BTL_SERVER_FLOW_ProcAfterMemberIn(w);
    }
    return 1;
}

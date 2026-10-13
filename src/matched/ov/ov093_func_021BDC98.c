/*
 * function: BTL_SERVER_FLOW_ProcMemberChange
 * address:  0x021BDC98
 * packet:   pkt_ov093_021BDC98
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushMemberOutCmd  0x021BDC78  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberOut  0x021BDD00  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberIn  0x021BD9D4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_FLOW_PushMemberOutCmd(u8 *p, u8 *a);
extern int BTL_SERVER_FLOW_ProcMemberOut(u8 *p, u8 *a, int c);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021B8E28(u8 *p, u32 n, u8 *out, u8 *cnt_out);
extern void BTL_SERVER_FLOW_ProcMemberIn(u8 *p, u8 i, u8 a, u8 b, int c);

void BTL_SERVER_FLOW_ProcMemberChange(u8 *p, u8 *a, u8 v)
{
    u8 buf[2];
    int r;
    u8 *q;
    BTL_SERVER_FLOW_PushMemberOutCmd(p, a);
    if (BTL_SERVER_FLOW_ProcMemberOut(p, a, 0)) {
        r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, BTL_POKEPARAM_GetPokeId(a));
        func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, r, &buf[1], &buf[0]);
        q = p + 0x7D9;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        BTL_SERVER_FLOW_ProcMemberIn(p, buf[1], buf[0], v, 1);
    }
}

/*
 * function: func_021CA3D0
 * address:  0x021CA3D0
 * packet:   pkt_ov093_021CA3D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   BTL_SERVER_FLOW_ShiftPokes  0x021BD43C  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchShiftEvents  0x021BD4E4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B8DDC(u32 x);
extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern char *func_021B9AEC(char *p, int i);
struct Msg;
extern int func_021B9C98(u8 *p, u32 v);
extern void BTL_SERVER_FLOW_ShiftPokes(u8 *p, int i, u8 a, u8 b, int c);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_DispatchShiftEvents(u8 *p, int i, u8 a, u8 b);

int func_021CA3D0(u8 *p, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
            m2 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
            if (!BTL_POKEPARAM_IsFainted(m1) && !BTL_POKEPARAM_IsFainted(m2)) {
                o = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, a);
                i = func_021B9C98((u8 *)o, (u32)m1);
                j = func_021B9C98((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    BTL_SERVER_FLOW_ShiftPokes(p, a, i, j, 0);
                    func_021C99A0(p, (const struct Msg *)(q + 8));
                    BTL_SERVER_FLOW_DispatchShiftEvents(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}

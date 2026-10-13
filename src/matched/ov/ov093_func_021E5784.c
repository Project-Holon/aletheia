/*
 * unit:     yes
 * function: func_021E5784, func_021E57F4
 * address:  0x021E5784
 * packet:   pkt_ov093_021E5784
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F29E8     0x021F29E8  data   ov093  a4
 */
#include "../include/Obj06273.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Q7;
struct QQ;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
extern u8 BTL_MAIN_GetEnemyLanePos(int kind, u32 flags, u32 v);
extern void *func_021C88A4(char *p, int a, int b);
extern u16 func_021C8138(struct Q7 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern int d_021F29E8[];

void func_021E5784(void *a, void *b, int c, int d)
{
    u8 *m;
    int n;

    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
        if (d == 6) {
            n = func_021C8010(b, c);
            d = BTL_MAIN_GetEnemyLanePos(func_021C815C(b), n, 0);
        }
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj06273 *)m)->f4 = 3;
        m[8] = d;
        ((struct Obj06273 *)m)->fC = func_021C8138(b) + 2;
        ((struct Obj06273 *)m)->f10 = BTL_EVENT_GetFactorKey(a);
        m[0x1c] = 2;
        func_021C88C8(b, m);
    }
}

int *func_021E57F4(int *p)
{
    *p = 2;
    return d_021F29E8;
}

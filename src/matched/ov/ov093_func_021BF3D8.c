/*
 * function: BTL_SERVER_FLOW_ProcAccuracyCheck
 * address:  0x021BF3D8
 * packet:   pkt_ov093_021BF3D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8A0  0x021CC8A0  thumb  ov093
 *   func_021CC8B0  0x021CC8B0  thumb  ov093
 *   func_021BF46C  0x021BF46C  thumb  ov093
 *   func_021BF47C  0x021BF47C  thumb  ov093
 *   func_021BF48C  0x021BF48C  thumb  ov093
 *   func_021BF49C  0x021BF49C  thumb  ov093
 *   BTL_SERVER_FLOW_CalcTypeEffectiveness  0x021C6E3C  thumb  ov093
 *   func_021C7C24  0x021C7C24  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 */
#include "../include/Obj13315.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021CC8A0(u32 *p);
extern void func_021CC8B0(u32 *p, u32 i, u32 b);
extern void func_021BF46C(int d);
extern u8 *func_021BF47C(int d);
extern void func_021BF48C(int d, u8 *x);
extern u8 *func_021BF49C(int d);
extern int BTL_SERVER_FLOW_CalcTypeEffectiveness(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *p);
extern void func_021BA1B4(char **p, int i);

void BTL_SERVER_FLOW_ProcAccuracyCheck(u8 *p, int b, u8 *a, int d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_021BF46C(d);
    x = func_021BF47C(d);
    while (x != 0) {
        r = BTL_SERVER_FLOW_CalcTypeEffectiveness(p, a, x, (u8 *)b, 1);
        func_021CC8B0(arr, BTL_POKEPARAM_GetPokeId(x), r);
        if (r == 0) {
            func_021BF48C(d, x);
            func_021C7C24((u16 *)(p + 0x1f7c), (int)p, a, x, 0);
            e = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
            if (e == func_021B8FF4(*(u8 * *)&((struct Obj13315 *)p)->f4))
                func_021BA1B4((char **)(*(u8 * *)&((struct Obj13315 *)p)->f4), 0x4b);
        }
        x = func_021BF49C(d);
    }
}

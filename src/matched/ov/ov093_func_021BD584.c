/*
 * function: BTL_SERVER_FLOW_ProcEscape
 * address:  0x021BD584
 * packet:   pkt_ov093_021BD584
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   BTL_SERVER_FLOW_TryEscape  0x021BD60C  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *p);
extern int BTL_SERVER_FLOW_TryEscape(u8 *p, u8 *a, u8 flag);
extern void func_021BA1B4(char **p, int i);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

int BTL_SERVER_FLOW_ProcEscape(u8 *p, u8 *a)
{
    int k = func_021B8DDC(BTL_POKEPARAM_GetPokeId(a));
    int m = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    int s = BTL_SERVER_FLOW_TryEscape(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)(*(u8 * *)&((struct Obj00003 *)p)->f4), 0x4e);
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0x49, 0xffff0000);
    } else {
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x36b, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
    }
    if (k == m) {
        p[0x786]++;
        if (p[0x786] > 0x1e) p[0x786] = 0x1e;
    }
    return s;
}

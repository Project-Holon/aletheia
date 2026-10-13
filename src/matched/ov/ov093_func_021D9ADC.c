/*
 * unit:     yes
 * function: HAND_TOKUSEI_ShedSkinOnTurnEnd, HAND_TOKUSEI_AddShedSkin
 * address:  0x021D9ADC
 * packet:   pkt_ov093_021D9ADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_CALC_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0878     0x021F0878  data   ov093  a4
 */
#include "../include/Obj06251.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_CALC_RollChanceOrFlag(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F0878[];

void HAND_TOKUSEI_ShedSkinOnTurnEnd(int a, void *b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(b, c))) {
            if (BTL_CALC_RollChanceOrFlag((int)b, 0x21)) {
                p = func_021C88A4(b, 0xb, c);
                ((struct Obj06251 *)p)->f0 |= 0x800000;
                ((struct Obj06251 *)p)->f0 |= 0x2000000;
                ((struct Obj06251 *)p)->f4 = 0x24;
                p[8] = c;
                p[0x14] = 1;
                func_021C88C8(b, p);
            }
        }
    }
}

int *HAND_TOKUSEI_AddShedSkin(int *p)
{
    *p = 1;
    return d_021F0878;
}

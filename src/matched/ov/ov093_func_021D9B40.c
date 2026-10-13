/*
 * unit:     yes
 * function: HAND_TOKUSEI_PoisonHealOnSickDamage, HAND_TOKUSEI_AddPoisonHeal
 * address:  0x021D9B40
 * packet:   pkt_ov093_021D9B40
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   d_021F0870     0x021F0870  data   ov093  a4
 */
#include "../include/Obj10058.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int d_021F0870[];

void HAND_TOKUSEI_PoisonHealOnSickDamage(int a, void *b, int c)
{
    void *q;
    u8 *p;

    if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(0x1d) == 5) {
        q = func_021C7CF4(b, c);
        BTL_EVENT_OverwriteVar(0x32, 0);
        p = func_021C88A4(b, 5, c);
        ((struct Obj10058 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(q, 8);
        p[6] = c;
        ((struct Obj10058 *)p)->f0 |= 0x800000;
        func_021C88C8(b, p);
    }
}

int *HAND_TOKUSEI_AddPoisonHeal(int *p)
{
    *p = 1;
    return d_021F0870;
}

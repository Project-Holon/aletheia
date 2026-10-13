/*
 * function: HAND_TOKUSEI_SynchronizeOnSickAdded
 * address:  0x021DA04C
 * packet:   pkt_ov093_021DA04C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   BTLV_CORE_IsSlotKind1Index15   0x021E8A78  thumb ov093
 *   BTL_CALC_MakeSickContFromKind   0x021D7DC0  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */
#include "../include/Obj07810.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern void *func_021C7CF4(int *p, int i);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
typedef struct { int x; } S;
extern int BTLV_CORE_IsSlotKind1Index15(S a);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *out);
extern void func_021C88C8(void *a, void *b);

void HAND_TOKUSEI_SynchronizeOnSickAdded(int a, int b, int c)
{
    u8 *p;
    int m;
    u8 k;
    void *s;
    S t;

    if (c != BTL_EVENT_GetVar(4))
        return;
    m = BTL_EVENT_GetVar(0x1d);
    if (m != 5 && m != 1 && m != 4)
        return;
    k = BTL_EVENT_GetVar(3);
    if (k == 0x1f || k == c)
        return;
    s = func_021C7CF4((int *)b, c);
    t.x = BTL_EVENT_GetVar(0x1e);
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 0xc, c);
    p[0xf] = k;
    ((struct Obj07810 *)p)->f4 = m;
    if (m == 5 && BTLV_CORE_IsSlotKind1Index15(t))
        ((struct Obj07810 *)p)->f8 = t.x;
    else
        BTL_CALC_MakeSickContFromKind(m, s, p + 8);
    p[0xc] = 1;
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}

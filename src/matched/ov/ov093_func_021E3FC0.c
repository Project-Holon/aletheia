/*
 * unit:     yes
 * function: func_021E3FC0, func_021E4074
 * address:  0x021E3FC0
 * packet:   pkt_ov093_021E3FC0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame: 0x1c bytes of locals needs the two BTL_POKEPARAM_GetMajorStatusIndex calls and
 * BTLV_CORE_MakeSlotKind1Index15 declared as returning a one-word struct (Word); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 * Word on BTL_POKEPARAM_GetSickContRaw or BTL_CALC_MakeDefaultSickCont as well gives a larger frame.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F27BC     0x021F27BC  data   a4
 */
#include "../include/Obj03704.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Word { unsigned int v; } Word;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern Word BTL_POKEPARAM_GetMajorStatusIndex(void *q);
extern u32 BTL_POKEPARAM_GetSickContRaw(u8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTLV_CORE_IsSlotKind1Index15(int s);
extern Word BTLV_CORE_MakeSlotKind1Index15(void);
extern int BTL_CALC_MakeDefaultSickCont(int k);
extern void func_021C88C8(void *a, void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int d_021F27BC[];

void func_021E3FC0(int u, void *a, int c)
{
    void *q;
    int r;
    u8 k;
    int s;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(a, c);
        r = BTL_POKEPARAM_GetMajorStatusIndex(q).v;
        if (r != 0) {
            k = BTL_EVENT_GetVar(6);
            if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(a, k)).v == 0) {
                s = BTL_POKEPARAM_GetSickContRaw(q, r);
                p = func_021C88A4(a, 0xc, c);
                ((struct Obj03704 *)p)->f4 = r;
                if (r == 5 && BTLV_CORE_IsSlotKind1Index15(s) != 0)
                    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Index15();
                else
                    ((struct Obj03704 *)p)->f8 = BTL_CALC_MakeDefaultSickCont(r);
                p[0xf] = k;
                p[0xc] = 1;
                func_021C88C8(a, p);
                p = func_021C88A4(a, 0xb, c);
                ((struct Obj03704 *)p)->f4 = r;
                p[0x14] = 1;
                p[8] = c;
                ((struct Obj03704 *)p)->f0 |= 0x1000000;
                func_021C88C8(a, p);
                BTL_EVENT_OverwriteVar(0x51, 0);
            }
        }
    }
}

int *func_021E4074(int *p)
{
    *p = 1;
    return d_021F27BC;
}

/*
 * function: HAND_WAZA_Conversion2ChangeType
 * address:  0x021E45CC
 * packet:   pkt_ov093_021E45CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastTargetPos  0x021D67B0  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_CALC_ListResistingTypes  0x021D7A9C  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13520.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QM;
extern u8 BTL_POKEPARAM_GetLastTargetPos(struct QM *p);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *s, int k);
extern u8 BTL_CALC_ListResistingTypes(int a, u8 *out);
extern int BTL_POKEPARAM_HasType(void *p, int k);
extern void func_02082D44(u8 *src, u8 *dst, u32 n);
extern u32 BTL_CALC_Random(u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTLV_CORE_PackByteTwice(int a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_Conversion2ChangeType(int a0, u8 *s, int k)
{
    int t;
    u8 *p;
    u32 n;
    u8 *q;
    u32 i;
    int c;
    u8 *e;

    if (k == BTL_EVENT_GetVar(3)) {
        t = BTL_POKEPARAM_GetLastTargetPos((struct QM *)BTL_SERVER_FLOW_GetPokeParam((int *)s, (u8)BTL_EVENT_GetVar(6)));
        if (t != 0x11) {
            p = BTL_SERVER_FLOW_GetScratchBuffer(s, 0x11);
            n = BTL_CALC_ListResistingTypes(t, p);
            if (n != 0) {
                q = BTL_SERVER_FLOW_GetPokeParam((int *)s, k);
                i = 0;
                while (i < n) {
                    if (BTL_POKEPARAM_HasType(q, p[i]) != 0) {
                        if ((int)(n - 1 - i) > 0)
                            func_02082D44(p + (i + 1), p + i, n - 1 - i);
                        n--;
                    } else {
                        i++;
                    }
                }
                if (n != 0) {
                    c = p[BTL_CALC_Random(n)];
                    e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 0x14, k);
                    ((struct Obj13520 *)e)->f4 = BTLV_CORE_PackByteTwice(c);
                    e[6] = k;
                    BTL_SERVER_FLOW_CommitCmdRecord(s, e);
                }
            }
        }
    }
}

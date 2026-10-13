/*
 * function: func_021E0468
 * address:  0x021E0468
 * packet:   pkt_ov093_021E0468
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13503.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QG;
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_POKEPARAM_HasType(void *q, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 BTL_CALC_Random(u32 range);
extern int BTLV_CORE_PackByteTwice(int a);
extern void func_021C88C8(void *a, void *b);

void func_021E0468(void *a, void *b, int c)
{
    u8 buf[4];
    void *q;
    u32 n;
    u16 i;
    u16 cnt;
    u32 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(b, c);
        n = BTL_POKEPARAM_GetMoveCount(q);
        i = 0;
        cnt = 0;
        for (; i < n; i++) {
            v = BTL_POKEPARAM_GetMoveId(q, (u8)i);
            if (v != BTL_EVENT_GetFactorKey(a)) {
                v = WAZA_TOOL_GetType((void *)v);
                if (BTL_POKEPARAM_HasType(q, v) == 0) {
                    buf[cnt++] = v;
                }
            }
        }
        if (cnt != 0) {
            p = func_021C88A4(b, 0x14, c);
            ((struct Obj13503 *)p)->f4 = BTLV_CORE_PackByteTwice(buf[(u16)BTL_CALC_Random(cnt)]);
            ((struct Obj13503 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}

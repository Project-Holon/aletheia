/*
 * function: HAND_WAZA_ConversionEffect
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
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_TYPEPAIR_MakeSingle  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13503.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QG;
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_POKEPARAM_HasType(void *q, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_TYPEPAIR_MakeSingle(int a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_ConversionEffect(void *a, void *b, int c)
{
    u8 buf[4];
    void *q;
    u32 n;
    u16 i;
    u16 cnt;
    u32 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(b, c);
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
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x14, c);
            ((struct Obj13503 *)p)->f4 = BTL_TYPEPAIR_MakeSingle(buf[(u16)BTL_CALC_Random(cnt)]);
            ((struct Obj13503 *)p)->f6 = c;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}

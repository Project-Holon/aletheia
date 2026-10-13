/*
 * unit:     yes
 * function: HAND_WAZA_PsychoShiftTransferStatus, HAND_WAZA_GetPainSplitHandlers
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
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gPainSplitHandlers     0x021F27BC  data   a4
 */
#include "../include/Obj03704.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Word { unsigned int v; } Word;

extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern Word BTL_POKEPARAM_GetMajorStatusIndex(void *q);
extern u32 BTL_POKEPARAM_GetSickContRaw(u8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTLV_CORE_IsSlotKind1Index15(int s);
extern Word BTLV_CORE_MakeSlotKind1Index15(void);
extern int BTL_CALC_MakeDefaultSickCont(int k);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gPainSplitHandlers[];

void HAND_WAZA_PsychoShiftTransferStatus(int u, void *a, int c)
{
    void *q;
    int r;
    u8 k;
    int s;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(a, c);
        r = BTL_POKEPARAM_GetMajorStatusIndex(q).v;
        if (r != 0) {
            k = BTL_EVENT_GetVar(6);
            if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(a, k)).v == 0) {
                s = BTL_POKEPARAM_GetSickContRaw(q, r);
                p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xc, c);
                ((struct Obj03704 *)p)->f4 = r;
                if (r == 5 && BTLV_CORE_IsSlotKind1Index15(s) != 0)
                    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Index15();
                else
                    ((struct Obj03704 *)p)->f8 = BTL_CALC_MakeDefaultSickCont(r);
                p[0xf] = k;
                p[0xc] = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(a, p);
                p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xb, c);
                ((struct Obj03704 *)p)->f4 = r;
                p[0x14] = 1;
                p[8] = c;
                ((struct Obj03704 *)p)->f0 |= 0x1000000;
                BTL_SERVER_FLOW_CommitCmdRecord(a, p);
                BTL_EVENT_OverwriteVar(0x51, 0);
            }
        }
    }
}

int *HAND_WAZA_GetPainSplitHandlers(int *p)
{
    *p = 1;
    return gPainSplitHandlers;
}

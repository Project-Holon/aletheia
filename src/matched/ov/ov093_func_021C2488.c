/*
 * function: BTL_SERVER_FLOW_ProcMoveSickAllTargets
 * address: 0x021C2488
 * packet: pkt_ov093_021C2488
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   BTL_CALC_MakeSickContFromSpec 0x021D7C70 thumb ov093
 *   func_021C2564 0x021C2564 thumb ov093
 *   func_021C2574 0x021C2574 thumb ov093
 *   ghiPostAddXml 0x021C2584 arm ov093
 *   func_021C2594 0x021C2594 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveSickOnTarget 0x021C25A4 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed 0x021C5718 thumb ov093
 */
#include "../include/Obj21083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 v; } W;
typedef struct { u32 v; } Word;
typedef struct { u8 pad[5]; u8 f:1; } BF;
typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State;
extern u32 WAZA_TOOL_GetParam(u16, u32);
extern W WAZA_TOOL_GetSickCont(u16);
extern void BTL_CALC_MakeSickContFromSpec(W, u32, Word *);
extern u32 func_021C2564(u32);
extern void func_021C2574(u32);
extern u32 ghiPostAddXml(u32);
extern u32 func_021C2594(u32);
extern int BTL_SERVER_FLOW_ProcMoveSickOnTarget(u8 *, u32, u32, u32, u32, Word, u32);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *, u8 *, u32);
void BTL_SERVER_FLOW_ProcMoveSickAllTargets(u8 *p, u16 id, u8 *a, u32 c)
{
    u32 s;
    W w;
    Word out;
    u32 t;
    int got;
    s = WAZA_TOOL_GetParam(id, 11);
    w = WAZA_TOOL_GetSickCont(id);
    got = 0;
    if (func_021C2564(c)) {
        func_021C2574(c);
        for (t = ghiPostAddXml(c); t; t = func_021C2594(c)) {
            BTL_CALC_MakeSickContFromSpec(w, (u32)a, &out);
            if (BTL_SERVER_FLOW_ProcMoveSickOnTarget(p, (u32)a, t, id, s, out, 1)) {
                BF *flag = *(BF * *)&((struct Obj21083 *)p)->f4A8;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State *)p)->f) BTL_SERVER_FLOW_PushMsgStdFailed(p, a, id);
    } else {
        BTL_SERVER_FLOW_PushMsgStdFailed(p, a, id);
    }
}

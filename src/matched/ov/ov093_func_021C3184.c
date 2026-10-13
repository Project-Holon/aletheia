/*
 * function: BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets
 * address:  0x021C3184
 * packet:   pkt_ov093_021C3184
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * WAZA_TOOL_GetSickCont is declared here as returning a one-halfword struct (the
 * store of r0 with no sign extension and the dead-looking second strh are
 * the struct-return temp plus its copy); its own file says s16.
 * BTL_CALC_MakeSickContFromSpec's first argument and BTL_SERVER_FLOW_ProcMoveSickOnTarget's sixth are structs
 * passed by value.
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_GetSickCont  0x0201BF58  thumb
 *   BTL_CALC_MakeSickContFromSpec  0x021D7C70  thumb  ov093
 *   func_021C3244  0x021C3244  thumb  ov093
 *   func_021C3254  0x021C3254  thumb  ov093
 *   func_021C3264  0x021C3264  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveRankEffects  0x021C2E64  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveSickOnTarget  0x021C25A4  thumb  ov093
 */
#include "../include/Obj13327.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } BF;
typedef struct { u16 v; } W;
typedef struct { u32 x; } O;

extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern W WAZA_TOOL_GetSickCont(u16 id);
extern void BTL_CALC_MakeSickContFromSpec(W w, u32 b, O *out);
extern void func_021C3244(u32 c);
extern u32 func_021C3254(u32 c);
extern u32 func_021C3264(u32 c);
extern int BTL_SERVER_FLOW_ProcMoveRankEffects(u8 *p, const u16 *q, u8 *a, u8 *b, int k);
extern int BTL_SERVER_FLOW_ProcMoveSickOnTarget(u8 *p, u32 a, u32 b, u32 unused, u32 s0, O s1, u32 s2);

void BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(u8 *p, const u16 *q, u32 r, u32 c)
{
    u32 t, s;
    O out;
    W v;
    s = WAZA_TOOL_GetParam(*q, 0xB);
    v = WAZA_TOOL_GetSickCont(*q);
    BTL_CALC_MakeSickContFromSpec(v, r, &out);
    func_021C3244(c);
    for (t = func_021C3254(c); t != 0; t = func_021C3264(c)) {
        if (BTL_SERVER_FLOW_ProcMoveRankEffects(p, (const u16 *)((u32)q), (u8 *)r, (u8 *)t, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
        if (BTL_SERVER_FLOW_ProcMoveSickOnTarget(p, r, t, *q, s, out, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}

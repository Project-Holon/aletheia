/*
 * function: BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb
 * address:  0x021BFEAC
 * packet:   pkt_ov093_021BFEAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Body matches instruction for instruction; the only residue is the frame:
 * original `sub sp,#0x18` / `add sp,#0x18` (3 sites), compiled 0x10. The
 * original stores only [sp]..[sp+0xc] (the four stack arguments of
 * BTL_SERVER_FLOW_ProcSickAdded), so 8 bytes of frame belong to something else that never
 * appears in the code (a local that is never stored, or an outgoing area for a
 * 10-argument call whose last two arguments are never written).
 *
 * checks: 1 BTL_SERVER_FLOW_ProcSickAdded reads [sp+0x20],+0x24,+0x28,+0x2c = 4 stack args, 8 arguments in all, matches the caller's four stores, BTL_SERVER_FLOW_SetPokeCounter takes (p,a,i,u8) as in its matched file; 2 no matched twin with the same 0x18 frame (ov093 21C0780/21C5620 callers checked); 3 int/u8 for n and out no change, struct W {int v;} by value gave push {r4-r7} + 0x14 (same 40 bytes total, rearranged), struct W {int a,b;} local gave 188 bytes; unused int pad[2] is dropped by the compiler (0x10); 4 none fits (no idiom names an unreferenced 8-byte frame slot); 5 no new idiom. Sweep I would run: the permuter over local declarations, plus a 5th/6th dummy argument on BTL_SERVER_FLOW_ProcSickAdded's prototype.
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_SetContFlag  0x021C60EC  thumb  ov093
 *   BTL_SERVER_FLOW_SetPokeCounter  0x021C0780  thumb  ov093
 *   BTL_SICKCONT_MakeKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_ProcSickAdded  0x021C2910  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_IsFainted(void *p);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
struct UtilWork;
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_FLOW_SetContFlag(u8 *p, u8 *a, u32 n);
extern void BTL_SERVER_FLOW_SetPokeCounter(u8 *p, u8 *a, int i, u8 v);
typedef struct { u32 v; } Word;
extern Word BTL_SICKCONT_MakeKind3(u32 a);
extern void BTL_SERVER_FLOW_ProcSickAdded(u8 *p, u8 *a, u8 *b, int k, Word e, int f, int g, int h);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(u8 *p, u8 *a, u8 *b, int *out)
{
    u8 n;
    Word t;
    *out = 0;
    if (BTL_POKEPARAM_IsFainted(b) == 0 && BTL_POKEPARAM_HasSubstitute(b) == 0 && BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)b) == 0) {
        if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)b, 7) == 0) {
            n = BTL_POKEPARAM_GetPokeId(b);
            BTL_SERVER_FLOW_SetContFlag(p, a, 3);
            BTL_SERVER_FLOW_SetContFlag(p, b, 3);
            BTL_SERVER_FLOW_SetPokeCounter(p, a, 4, n + 1);
            t = BTL_SICKCONT_MakeKind3(BTL_POKEPARAM_GetPokeId(a));
            BTL_SERVER_FLOW_ProcSickAdded(p, b, a, 0x21, t, 0, 0, 0);
            return 1;
        }
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x20b, BTL_POKEPARAM_GetPokeId(b), 0xffff0000);
        *out = 1;
    }
    return 0;
}

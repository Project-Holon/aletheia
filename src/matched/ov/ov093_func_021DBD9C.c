/*
 * function: HAND_TOKUSEI_CursedBody_DisableAttackerMove
 * address:  0x021DBD9C
 * packet:   pkt_ov093_021DBD9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     BTLV_CORE_MakeSlotKind2 returns a one-word struct (Word): its return temporary is
 *           the unreferenced third frame word and moves n/k to r6/r7
 *           (an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md);
 *           the enum N keeps n + 1 out of constant folding.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021DBE50  0x021DBE50  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10064.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef enum { N_4 = 4, N_5 = 5 } N;
typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
struct UtilWork;
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int func_021DBE50(u32 k);
extern int HAND_TOKUSEI_RollChanceOrFlag(int a, u32 b);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind2(int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_CursedBody_DisableAttackerMove(int u, void *a, int b)
{
    u8 t;
    u16 k;
    N n;
    void *m;
    u8 *e;
    n = N_4;
    if (b == BTL_EVENT_GetVar(4)
        && BTL_EVENT_GetVar(0x46) == 0
        && BTL_SERVER_FLOW_CheckShowdownThunk(a) == 0) {
        t = BTL_EVENT_GetVar(3);
        m = BTL_SERVER_FLOW_GetPokeParam(a, t);
        if (BTL_POKEPARAM_HasSick(m, 0xd) == 0) {
            k = BTL_EVENT_GetVar(0x14);
            if (k != 0 && k != 0xa5 && func_021DBE50(k) == 0
                && HAND_TOKUSEI_RollChanceOrFlag((int)a, 0x1e) != 0) {
                if (BTL_POKEPARAM_TestTurnFlag(m, 1) != 0) {
                    n = (N)(u8)(n + 1);
                }
                e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xc, b);
                ((struct Obj10064 *)e)->f4 = 0xd;
                *(Word *)(e + 8) = BTLV_CORE_MakeSlotKind2(n, k);
                e[0xf] = t;
                ((struct Obj10064 *)e)->f0 |= 2 << 22;
                BTL_SERVER_FLOW_CommitCmdRecord(a, e);
            }
        }
    }
}

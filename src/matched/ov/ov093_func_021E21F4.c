/*
 * function: HAND_WAZA_ThrashStartLock
 * address:  0x021E21F4
 * packet:   pkt_ov093_021E21F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind2  0x021E896C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *
 * Lever: BTL_SICKCONT_MakeKind2 returns a one-word struct (Word), which reserves the
 * third frame word (`sub sp, #0xc` with push {r4-r7, lr}); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 */
#include "../include/Obj10075.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QQ;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 BTL_CALC_Random(u32 range);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern Word BTL_SICKCONT_MakeKind2(int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_ThrashStartLock(void *u, int a, int b, int *p)
{
    u8 *r;
    u8 t;

    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)a, b), 0x19) == 0 && p[6] == 0) {
            t = BTL_CALC_Random(2) + 2;
            r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xc, b);
            ((struct Obj10075 *)r)->f4 = 0x19;
            *(Word *)(r + 8) = BTL_SICKCONT_MakeKind2(t, BTL_EVENT_GetFactorKey(u));
            r[0xc] = 0;
            r[0xf] = b;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
            p[6] = 1;
            p[0] = t;
        }
    }
}

/*
 * function: BTL_SERVER_FLOW_ProcPreTurnMoveCheck
 * address:  0x021BC568
 * packet:   pkt_ov093_021BC568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: the record array as p->e[i] of the S the EXACT twins use
 * (BTL_SERVER_FLOW_FindActionByPokeId, BTL_SERVER_FLOW_FindPendingActionByMove, BTL_SERVER_FLOW_GetActionWordByPokeId: count at +0x782, 16-byte
 * records at +0x7e0), and the bitfield word read through an entry pointer
 * e = &p->e[i] (hoists p+0x7e0 into [sp+4] and reads e->b at #4); reading
 * p->e[i].b directly hoists p+0x7e4 instead and comes out 4 bytes short.
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   HAND_WAZA_AddMoveHandler  0x021E02DC  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyMoveEvent  0x021C6394  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerUnlessKept  0x021E0394  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 kind : 4; u32 pad : 3; u32 id : 16; u32 rest : 9; } B;
typedef struct { u8 *a; B b; u32 c; u32 d; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; } S;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int func_021D59B4(u8 *p, int k);
extern int HAND_WAZA_AddMoveHandler(u8 *a, u16 key, u32 sub_pri);
extern void BTL_SERVER_FLOW_NotifyMoveEvent(u8 *p, u8 *a, unsigned int n);
extern void HAND_WAZA_RemoveMoveHandlerUnlessKept(u8 *a, int b);

void BTL_SERVER_FLOW_ProcPreTurnMoveCheck(S *p)
{
    u32 lk = BTL_SERVER_FLOW_BeginHandExScope((u8 *)p + 0x1d74, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        E *e;
        e = &p->e[i];
        if (e->b.kind == 1)
            id = e->b.id;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (HAND_WAZA_AddMoveHandler(a, id, func_021D59B4(a, 12))) {
                BTL_SERVER_FLOW_NotifyMoveEvent((u8 *)p, a, id);
                HAND_WAZA_RemoveMoveHandlerUnlessKept(a, id);
            }
        }
    }
    BTL_SERVER_FLOW_EndHandExScope((u32 *)((u8 *)p + 0x1d74), lk, 0x5a0);
}

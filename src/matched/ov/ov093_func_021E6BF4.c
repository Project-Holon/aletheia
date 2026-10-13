/*
 * function: HAND_WAZA_AssistPickMove
 * address: 0x021E6BF4
 * packet: pkt_ov093_021E6BF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Both loop bounds and their accessor returns are u8; u32 n loses
 * its pre-loop reload, and u32 count schedules its reload before i's spill.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPartyOfPoke 0x021C7FCC thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   func_021E6CC0 0x021E6CC0 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget 0x021C8030 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct Q1;
struct QG;
struct S2;
extern char *BTL_SERVER_FLOW_GetPartyOfPoke(u8 *p, int i);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int func_021E6CC0(u16);
extern u32 BTL_CALC_Random(u32);
extern int BTL_SERVER_FLOW_DecideMoveTarget(u8 *p, int v, u16 k);
extern int BTL_EVENT_OverwriteVar(int, u32);
void HAND_WAZA_AssistPickMove(void *x, void *a, int c)
{
    void *party;
    u16 *moves;
    u8 count;
    u8 i;
    u8 n;
    u8 used, j;
    void *mon;
    u16 move;
    u8 pick;
    int slot;
    if (c == BTL_EVENT_GetVar(2)) {
        party = BTL_SERVER_FLOW_GetPartyOfPoke(a, c);
        moves = (u16 *)BTL_SERVER_FLOW_GetScratchBuffer(a, 48);
        used = 0;
        count = BTL_SLOT_GetCount(party);
        for (i = 0; i < count; i++) {
            mon = BTL_SLOT_GetPokeParam(party, i);
            if (c != BTL_POKEPARAM_GetPokeId(mon)) {
                n = BTL_POKEPARAM_GetMoveCount(mon);
                for (j = 0; j < n; j++) {
                    move = BTL_POKEPARAM_GetMoveId(mon, j);
                    if (func_021E6CC0(move) == 0) {
                        moves[used++] = move;
                    }
                }
            }
        }
        if (used != 0) {
            pick = BTL_CALC_Random(used);
            slot = BTL_SERVER_FLOW_DecideMoveTarget(a, c, moves[pick]);
            BTL_EVENT_OverwriteVar(18, moves[pick]);
            BTL_EVENT_OverwriteVar(13, slot);
        }
    }
}

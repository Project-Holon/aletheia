/*
 * function: BTL_SERVER_FLOW_FindPendingMoveActionForPoke
 * address:  0x021BCB14
 * packet:   pkt_ov093_021BCB14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_FindPendingActionByMove  0x021BCAAC  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionIndex  0x021BCB68  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 *a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern E *BTL_SERVER_FLOW_FindPendingActionByMove(S *p, u8 x, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern int BTL_SERVER_FLOW_GetActionIndex(S *p, E *cur);

E *BTL_SERVER_FLOW_FindPendingMoveActionForPoke(S *p, u8 x, u32 y)
{
    E *e = BTL_SERVER_FLOW_FindPendingActionByMove(p, x, 0);
    while (e) {
        if (BTL_MAIN_IsPokeSamePair(y, BTL_POKEPARAM_GetPokeId(e->a)) && BTL_POKEPARAM_IsFainted(e->a) == 0)
            return e;
        e = BTL_SERVER_FLOW_FindPendingActionByMove(p, x, (u8)(BTL_SERVER_FLOW_GetActionIndex(p, e) + 1));
    }
    return 0;
}

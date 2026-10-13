/*
 * function: BTL_SERVER_FLOW_FindPendingActionByMove
 * address:  0x021BCAAC
 * packet:   pkt_ov093_021BCAAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_ActionGetKind  0x021D8454  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern u32 BTL_CALC_ActionGetKind(u32 *m);
extern u32 BTL_ACTION_GetFightMove(u32 *m);

E *BTL_SERVER_FLOW_FindPendingActionByMove(S *p, u8 x, u32 i)
{
    for (; i < p->n; i++) {
        if (p->e[i].flag == 0 && BTL_CALC_ActionGetKind(&p->e[i].b) == 1 && x == BTL_ACTION_GetFightMove(&p->e[i].b))
            return &p->e[i];
    }
    return 0;
}

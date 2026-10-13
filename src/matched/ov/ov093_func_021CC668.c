/*
 * function: BTL_SERVER_FLOW_CheckBattleOutcome
 * address: 0x021CC668
 * packet: pkt_ov093_021CC668
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_CountLiving 0x021B9B98 thumb ov093
 *   BTL_MAIN_GetClientSide 0x021B8BC4 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_IsCommTrainerBattle 0x021BA534 thumb ov093
 *   func_021CC758 0x021CC758 thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   BTL_SERVER_FLOW_CompareSideRemaining 0x021CC768 thumb ov093
 */
#include "../include/Obj05196.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern char *BTL_SIDE_GetSlotOfClient(char *,int);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 BTL_SLOT_CountLiving(u8 *p);
extern unsigned char BTL_MAIN_GetClientSide(int unused, unsigned int b);
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern int BTL_MAIN_IsCommTrainerBattle(void ***p);
extern int func_021CC758(void *);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern int BTL_SERVER_FLOW_CompareSideRemaining(void *,u8 *,u8 *,int);
int BTL_SERVER_FLOW_CheckBattleOutcome(u8 *p)
{
    u8 live[2];
    u8 counts[2];
    u32 i;
    char *list;
    u8 side;
    u8 other;
    int k;
    live[0] = live[1] = 0;
    counts[0] = counts[1] = 0;
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(((struct Obj05196 *)p)->f4, i)) {
            list = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj05196 *)p)->f8,i);
            if (BTL_SLOT_GetCount((struct Q1 *)list)) {
                side = BTL_MAIN_GetClientSide((int)(((struct Obj05196 *)p)->f4),(u8)i);
                live[side] += BTL_SLOT_CountLiving((u8 *)list);
                counts[side] += BTL_SLOT_GetCount((struct Q1 *)list);
            }
        }
    }
    side = BTL_MAIN_GetClientSide((int)(((struct Obj05196 *)p)->f4),(u8)BTL_MAIN_GetOwnClientId(((struct Obj05196 *)p)->f4));
    other = side ^ 1;
    if (live[side] == 0 && live[other] != 0) return 0;
    if (live[other] == 0 && live[side] != 0) return 1;
    if (!BTL_MAIN_IsCommTrainerBattle(((struct Obj05196 *)p)->f4)) return 2;
    if (live[0] == 0) {
        k = func_021CC758(p+0x3e0);
        if (k != 31) {
            k = BTL_MAIN_IsPokeIdInSecondPair(k);
            if (k == side) return 1;
            return 0;
        }
        return 2;
    }
    return BTL_SERVER_FLOW_CompareSideRemaining(p, live, counts, side);
}

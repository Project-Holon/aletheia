/*
 * function: HAND_TOKUSEI_SwapAbilityHandlers
 * address:  0x021D8564
 * packet:   pkt_ov093_021D8564
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   HAND_TOKUSEI_AddAbilityHandlers  0x021D8484  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Node;
struct Node *BTL_EVENT_FindFactor(int id, int sub);
void BTL_EVENT_RemoveFactor(struct Node *n);
void *HAND_TOKUSEI_AddAbilityHandlers(void *a);

void HAND_TOKUSEI_SwapAbilityHandlers(int a, int b)
{
    int sa = BTL_POKEPARAM_GetPokeId((u8 *)a);
    int sb = BTL_POKEPARAM_GetPokeId((u8 *)b);
    void *x = BTL_EVENT_FindFactor(4, sa);
    void *y = BTL_EVENT_FindFactor(4, sb);

    if (x != 0)
        BTL_EVENT_RemoveFactor(x);
    if (y != 0)
        BTL_EVENT_RemoveFactor(y);
    HAND_TOKUSEI_AddAbilityHandlers((void *)a);
    HAND_TOKUSEI_AddAbilityHandlers((void *)b);
}

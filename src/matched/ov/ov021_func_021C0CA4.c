/*
 * function: FIELD_PLAYER_GRID_EVENT_TryPushBoulder
 * address:  0x021C0CA4
 * packet:   pkt_ov021_021C0CA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetCore  0x021A5728  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMmdl  0x021A572C  thumb  ov021
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_GRID_CheckCoreAction  0x021A44BC  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags  0x021C0CE4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_GRID_GetCore(u8 *p);
extern void *FIELD_PLAYER_GRID_GetMmdl(u8 *p);
extern u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(u32 a, u32 v);
extern int FIELD_PLAYER_GRID_CheckCoreAction(int a, int b);
extern int FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(u8 *a, u32 b, u32 flags);

int FIELD_PLAYER_GRID_EVENT_TryPushBoulder(u8 *a, int b, int c, int d)
{
    int r7, r4;
    r7 = FIELD_PLAYER_GRID_GetCore((u8 *)a);
    FIELD_PLAYER_GRID_GetMmdl((u8 *)a);
    r4 = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(r7, c);
    if (FIELD_PLAYER_GRID_CheckCoreAction((int)a, r4) == 0)
        return 0;
    r7 = FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(a, r4, d);
    if (r7 == 0)
        return 0;
    return r7;
}

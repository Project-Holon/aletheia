/*
 * function: FIELD_PLAYER_GRID_EVENT_CreateHopTask
 * address:  0x021C1024
 * packet:   pkt_ov021_021C1024
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFileFieldPlayerGridEvent     0x021DE3AC  data  ov021  a4
 *   FIELD_PLAYER_GetFieldMap  0x021A3068  thumb  ov021
 *   FIELD_PLAYER_GetGrid  0x021A36E0  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   FIELD_PLAYER_GRID_EVENT_HopTask  0x021C10B4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05075.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u8 gFileFieldPlayerGridEvent;
extern u32 FIELD_PLAYER_GetFieldMap(u8 *p);
extern u32 FIELD_PLAYER_GetGrid(u8 *p);
extern u16 MAP_ATTR_GetTerrainId(u32 a);
extern int MAP_ATTR_IsLongHopEdge(int id);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern void FIELD_PLAYER_GRID_EVENT_HopTask();

void FIELD_PLAYER_GRID_EVENT_CreateHopTask(u32 a, u16 b, u32 c, u32 d)
{
    u32 *r;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x18, 1, (const char *)&gFileFieldPlayerGridEvent, 0x1e6);
    r[3] = FIELD_PLAYER_GetFieldMap((u8 *)a);
    ((struct Obj05075 *)r)->f6 = b;
    r[4] = a;
    r[5] = FIELD_PLAYER_GetGrid((u8 *)a);
    if (MAP_ATTR_IsLongHopEdge(MAP_ATTR_GetTerrainId(c)) == 1)
        ((struct Obj05075 *)r)->f8 = 1;
    func_02030DA8(FIELDMAP_GetTcblSys((u8 *)r[3]), FIELD_PLAYER_GRID_EVENT_HopTask, r, 0);
}

/*
 * function: FIELD_GIMMICK_GATE_FindListNewsEntry
 * address:  0x021F3CB0
 * packet:   pkt_ov048_021F3CB0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   GIMMICK_OBJ_ELBOARD_CheckEntryZone  0x021F4DF4  thumb
 */
#include "../include/Obj03647.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct BigObj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int GIMMICK_OBJ_ELBOARD_CheckEntryZone(int *, int);

int *FIELD_GIMMICK_GATE_FindListNewsEntry(int *p)
{
    int a = FIELDMAP_GetZoneId((u8 *)p[1]);
    int b = GAME_DATA_GetEventWork((const struct BigObj *)p[2]);
    int i;

    if (p[8] == 0)
        return 0;
    for (i = 0; i < ((struct Obj03647 *)p)->f24; i++) {
        int off = i * 0x24;
        int t = ZONEDATA_CheckEventFlag((void *)b, (u16)((int *)(p[8] + off))[1]);
        int r = GIMMICK_OBJ_ELBOARD_CheckEntryZone((int *)(p[8] + off), a);

        if (t != 0 && r != 0 && ((int *)(p[8] + off))[4] == 2)
            return (int *)(p[8] + off);
    }
    return 0;
}

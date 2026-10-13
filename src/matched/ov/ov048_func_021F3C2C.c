/*
 * function: FIELD_GIMMICK_GATE_FindNewsEntry
 * address:  0x021F3C2C
 * packet:   pkt_ov048_021F3C2C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   GIMMICK_OBJ_ELBOARD_CheckEntryZone  0x021F4DF4  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_CheckEntryGPower  0x021F4E3C  thumb  ov048
 */
#include "../include/Obj03646.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern int ZONEDATA_CheckEventFlag(u32 a, u32 b);
extern int GIMMICK_OBJ_ELBOARD_CheckEntryZone(int *p, int v);
extern int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(int *p);

u8 *FIELD_GIMMICK_GATE_FindNewsEntry(u8 *o)
{
    int b;
    int a;
    int i;
    int off;
    int c;
    int d;

    a = FIELDMAP_GetZoneId((u8 *)(((struct Obj03646 *)o)->f4));
    b = GAME_DATA_GetEventWork((const struct BigObj *)(((struct Obj03646 *)o)->f8));
    if (*(u8 * *)&((struct Obj03646 *)o)->f20 == 0) {
        return 0;
    }
    for (i = 0; i < ((struct Obj03646 *)o)->f24; i++) {
        off = i * 0x24;
        c = ZONEDATA_CheckEventFlag(b, (u16)*(u32 *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off + 4));
        d = GIMMICK_OBJ_ELBOARD_CheckEntryZone((int *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off), a);
        if (GIMMICK_OBJ_ELBOARD_CheckEntryGPower((int *)(*(u8 * *)&((struct Obj03646 *)o)->f20 + off)) && c && d) {
            return *(u8 * *)&((struct Obj03646 *)o)->f20 + off;
        }
    }
    return 0;
}

/*
 * function: FIELDMAP_AddZoneNpcs
 * address:  0x021894E0
 * packet:   pkt_ov021_021894E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderList  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
void FLDMMDL_AddMmdlHeaderList(u32 a, u8 *p, u32 b, u32 n, u32 c);

void FIELDMAP_AddZoneNpcs(int a, int b, int c, int d)
{
    int r = EVENTDATA_SYSTEM_GetNpcCount((u8 *)c);
    int y;
    if (r != 0) {
        y = GAME_DATA_GetEventWork((const struct BigObj *)a);
        FLDMMDL_AddMmdlHeaderList(b, (u8 *)EVENTDATA_SYSTEM_GetNpcHeaders((u8 *)c), d, r, y);
    }
}

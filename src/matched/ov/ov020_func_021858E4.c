/*
 * function: EVENT_MAPCHANGE_AddEventDataMmdl
 * address:  0x021858E4
 * packet:   pkt_ov020_021858E4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderList  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u32 GAME_DATA_GetEventData(const struct BigObj *p);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
void FLDMMDL_AddMmdlHeaderList(u32 a, u8 *p, u32 b, u32 n, u32 c);

void EVENT_MAPCHANGE_AddEventDataMmdl(int a, const short *p)
{
    int t = GAME_DATA_GetEventData((const struct BigObj *)a);
    int v = EVENTDATA_SYSTEM_GetNpcCount((u8 *)t);

    if (v != 0) {
        int r6 = GAME_DATA_GetEventWork((const struct BigObj *)a);
        int r5 = GAME_DATA_GetOccupyInfo((const struct BigObj *)a);
        int r1 = EVENTDATA_SYSTEM_GetNpcHeaders((u8 *)t);
        int s = p[2];
        FLDMMDL_AddMmdlHeaderList(r5, (u8 *)r1, s, v, r6);
    }
}

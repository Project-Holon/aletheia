/*
 * function: FIELD_PALACE_SYS_IsZoneFlagSet
 * address:  0x021D3554
 * packet:   pkt_021D3554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PALACE_SYS_IsZoneFlagSet 0x021D3554 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_IsZoneGroup118To13C 0x02013D74 thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   sPalaceZoneFlags    0x021DD944 data
 */

typedef unsigned short u16;

struct BigObj;
extern unsigned int GAME_DATA_GetEventWork(const struct BigObj *p);
typedef signed int     s32;
typedef unsigned int   u32;
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

struct Entry {
    u16 key;
    u16 val;
};

extern struct Entry sPalaceZoneFlags[];

int FIELD_PALACE_SYS_IsZoneFlagSet(void *arg0, int arg1)
{
    void *r4 = (void *)GAME_DATA_GetEventWork(arg0);
    if (ZONEDATA_IsZoneGroup118To13C(arg1) == 1) {
        unsigned int i;
        for (i = 0; i < 25; i++) {
            if (arg1 == sPalaceZoneFlags[i].key) {
                if (ZONEDATA_CheckEventFlag(r4, sPalaceZoneFlags[i].val) == 1) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}

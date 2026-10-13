/*
 * function: INTRUDE_COMM_HasUnlockFlags
 * address: 0x02158590
 * packet: pkt_ov010_02158590
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   sIntrudeUnlockFlags 0x021700A8 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *, int);
extern const u16 sIntrudeUnlockFlags[2];
int INTRUDE_COMM_HasUnlockFlags(void *p)
{
    void *q = (void *)GAME_DATA_GetEventWork(p);
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (ZONEDATA_CheckEventFlag(q, sIntrudeUnlockFlags[i]) == 0)
            return 0;
    }
    return 1;
}

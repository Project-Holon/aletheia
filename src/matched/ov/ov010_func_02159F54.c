/*
 * function: MAP_REPLACE_CheckFlag
 * address: 0x02159F54
 * packet: pkt_ov010_02159F54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MAP_REPLACE_FindFlagEntry 0x02159F04 thumb ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;
extern Ent *MAP_REPLACE_FindFlagEntry(int, int);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32, u32);
int MAP_REPLACE_CheckFlag(int a, int b)
{
    Ent *p = MAP_REPLACE_FindFlagEntry(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)ZONEDATA_GetEventWorkAddress(GAME_DATA_GetEventWork((const struct BigObj *)a), p->f02);
        if (p->f04 == *q)
            return 1;
        else
            return 0;
    }
    return 0;
}

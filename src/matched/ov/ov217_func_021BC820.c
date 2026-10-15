/*
 * function: RESEARCH_LIST_CountUnlockedEntries
 * address: 0x021BC820
 * packet: pkt_ov217_021BC820
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC8B2.
 * Initialize n after the getter expression; initializing in its declaration
 * schedules movs r5,#1 before both getters (14 concrete bytes differ).
 * symbols:
 *   RESEARCH_LIST_GetAppResource 0x021BC628 thumb ov217
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb  arm9
 * 021BC628 forwards to the +8 getter 021C09B4; its void source leaves r0
 * live and the original immediately feeds that result to 0201296C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern u32 RESEARCH_LIST_GetAppResource(u8 *a0);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *);
extern u32 ZONEDATA_CheckEventFlag(void *, int);
void RESEARCH_LIST_CountUnlockedEntries(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)GAME_DATA_GetEventWork((const struct BigObj *)RESEARCH_LIST_GetAppResource(p));
    n = 1;
    if (ZONEDATA_CheckEventFlag(bitmap, 240) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 241) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 242) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 243) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 244) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 245) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 246) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 247) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 248) == 1) n++;
    p[0x30] = n;
}

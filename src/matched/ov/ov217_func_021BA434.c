/*
 * function: RESEARCH_TOP_CountUnlockedEntries
 * address: 0x021BA434
 * packet: pkt_ov217_021BA434
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 * symbols:
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 */
#include "../include/Obj25823.h"
extern unsigned RESEARCH_COMMON_GetAppResource(void *);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned ZONEDATA_CheckEventFlag(void *,int);
unsigned char RESEARCH_TOP_CountUnlockedEntries(char *p)
{
    void *bitmap=(void *)GAME_DATA_GetEventWork((const struct BigObj *)RESEARCH_COMMON_GetAppResource(((struct Obj25823 *)p)->f0));
    int count=1;
    if(ZONEDATA_CheckEventFlag(bitmap,240)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,241)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,242)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,243)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,244)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,245)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,246)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,247)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,248)==1)count++;
    return count;
}

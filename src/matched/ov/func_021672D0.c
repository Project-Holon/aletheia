/*
 * function: EVENT_RESEARCH_RADAR_GetReportKind
 * address:  0x021672D0
 * packet:   pkt_021672D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControlWork  0x02012EC0  thumb
 *   MISC_GetFromSave  0x0200C0E8  thumb
 *   MISC_GetResearchRank  0x0200C224  thumb
 */
#include "../include/Obj17729.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *GAME_DATA_GetSaveControlWork(struct Big *p);
extern void *MISC_GetFromSave(void *sys);
struct Blk34;
extern u8 MISC_GetResearchRank(struct Blk34 *p);

int EVENT_RESEARCH_RADAR_GetReportKind(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17729 *)a0)->f8;
    big = GAME_DATA_GetSaveControlWork((struct Big *)a0);
loc_021672D8:
    sys = MISC_GetFromSave(big);
loc_021672DC:
    a0 = MISC_GetResearchRank(sys);
loc_021672E0:
    return a0;}

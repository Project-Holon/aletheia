/*
 * function: EVENT_RESEARCH_RADAR_GetReportNumberA
 * address:  0x021672E4
 * packet:   pkt_021672E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControlWork  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 */
#include "../include/Obj17730.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *GAME_DATA_GetSaveControlWork(struct Big *p);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u32 func_0200C1DC(struct Blk34 *p);

int EVENT_RESEARCH_RADAR_GetReportNumberA(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17730 *)a0)->f8;
    big = GAME_DATA_GetSaveControlWork((struct Big *)a0);
loc_021672EC:
    sys = func_0200C0E8(big);
loc_021672F0:
    a0 = func_0200C1DC(sys);
loc_021672F4:
    return a0;}

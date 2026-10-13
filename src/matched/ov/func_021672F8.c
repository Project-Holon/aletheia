/*
 * function: func_021672F8
 * address:  0x021672F8
 * packet:   pkt_021672F8
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
 *   func_0200C1C4  0x0200C1C4  thumb
 */
#include "../include/Obj17731.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *GAME_DATA_GetSaveControlWork(struct Big *p);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u32 func_0200C1C4(struct Blk34 *p);

int func_021672F8(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17731 *)a0)->f8;
    big = GAME_DATA_GetSaveControlWork((struct Big *)a0);
loc_02167300:
    sys = func_0200C0E8(big);
loc_02167304:
    a0 = func_0200C1C4(sys);
loc_02167308:
    return a0;}

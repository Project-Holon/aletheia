/*
 * function: GURU2_MAIN_StateResultDelay
 * address: 0x021DF434
 * packet: pkt_ov137_021DF434
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_ClearNameWindow 0x021E0478 thumb ov137
 *   GURU2_MAIN_PrintMessageWithName 0x021E01B0 thumb ov137
 *   GURU2_MAIN_PushAndPlayBgm 0x021E1988 thumb ov137
 */
#include "../include/Obj06541.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void GURU2_MAIN_ClearNameWindow(u8 *p, u32 i);
extern void GURU2_MAIN_PrintMessageWithName(u8 *p, int message, void *value);
extern void GURU2_MAIN_PushAndPlayBgm(unsigned int n);
int GURU2_MAIN_StateResultDelay(u8 *p)
{
    int i;
    ((struct Obj06541 *)p)->fC += 1;
    if (((struct Obj06541 *)p)->fC < 120) return 0;
    ((struct Obj06541 *)p)->fC = 0;
    for (i = 0; i < ((struct Obj06541 *)p)->f30; i++) GURU2_MAIN_ClearNameWindow(p, i);
    GURU2_MAIN_PrintMessageWithName(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int **)(p + 40))[3])));
    GURU2_MAIN_PushAndPlayBgm(1302);
    ((struct Obj06541 *)p)->f0 = 37;
    return 0;
}

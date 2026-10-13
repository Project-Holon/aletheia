/*
 * function: BTLV_CORE_StartBallWindowOpen
 * address: 0x021EADA4
 * packet: pkt_ov093_021EADA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_StartBallWindowOpen 0x021EE264 thumb ov093
 */
#include "../include/Obj21571.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct T;
extern void BTLV_SCU_StartBallWindowOpen(char *, int, struct T *);
void BTLV_CORE_StartBallWindowOpen(u8 *p, int a, struct T *b)
{
    BTLV_SCU_StartBallWindowOpen(*(char * *)&((struct Obj21571 *)p)->f17C, a, b);
}

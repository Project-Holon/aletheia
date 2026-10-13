/*
 * function: func_021EADD4
 * address: 0x021EADD4
 * packet: pkt_ov093_021EADD4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_UpdateBallWindowRefresh 0x021EE318 thumb ov093
 */
#include "../include/Obj21574.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern int BTLV_SCU_UpdateBallWindowRefresh(struct O *);
int func_021EADD4(u8 *p)
{
    return BTLV_SCU_UpdateBallWindowRefresh(*(struct O * *)&((struct Obj21574 *)p)->f17C);
}

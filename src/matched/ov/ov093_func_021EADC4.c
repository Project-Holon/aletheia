/*
 * function: func_021EADC4
 * address: 0x021EADC4
 * packet: pkt_ov093_021EADC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_StartBallWindowRefresh 0x021EE2F8 thumb ov093
 */
#include "../include/Obj21573.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern void BTLV_SCU_StartBallWindowRefresh(struct O *);
void func_021EADC4(u8 *p)
{
    BTLV_SCU_StartBallWindowRefresh(*(struct O * *)&((struct Obj21573 *)p)->f17C);
}

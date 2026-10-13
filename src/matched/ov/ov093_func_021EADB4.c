/*
 * function: BTLV_CORE_UpdateBallWindowOpen
 * address: 0x021EADB4
 * packet: pkt_ov093_021EADB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_UpdateBallWindowOpen 0x021EE2A0 thumb ov093
 */
#include "../include/Obj21572.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern int BTLV_SCU_UpdateBallWindowOpen(struct O *);
int BTLV_CORE_UpdateBallWindowOpen(u8 *p)
{
    return BTLV_SCU_UpdateBallWindowOpen(*(struct O * *)&((struct Obj21572 *)p)->f17C);
}

/*
 * function: BTL_SERVER_FLOW_RecordSpecialMoveUse
 * address: 0x021BEC2C
 * packet: pkt_ov093_021BEC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_IsPlayerSidePoke 0x021BEC08 thumb ov093
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 */
#include "../include/Obj09965.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_IsPlayerSidePoke(u8 *,u8 *);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);
void BTL_SERVER_FLOW_RecordSpecialMoveUse(u8 *p,u8 *a,int c)
{
    if(BTL_SERVER_FLOW_IsPlayerSidePoke(p,a)) {
        if(c==150) BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),73);
        else if(c==165) BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj09965 *)p)->f4),74);
    }
}

/*
 * function: COMM_BTL_DEMO_MAIN_LayoutRows
 * address: 0x021B9A84
 * packet: pkt_ov213_021B9A84
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_InitRows 0x021BA38C thumb ov213
 *   COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 *   COMM_BTL_DEMO_MAIN_CountFlags 0x021BAA8C thumb ov213
 *   COMM_BTL_DEMO_MAIN_InitBattleContext 0x021BA5A0 thumb ov213
 */
#include "../include/Obj02260.h"
typedef unsigned short u16;
extern void COMM_BTL_DEMO_MAIN_InitRows(char *);
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(unsigned),COMM_BTL_DEMO_MAIN_CountFlags(char *);
extern void COMM_BTL_DEMO_MAIN_InitBattleContext(char *,void *,void *,u16,u16,unsigned char);
int COMM_BTL_DEMO_MAIN_LayoutRows(int unused,char *p)
{
    u16 a,b;
    COMM_BTL_DEMO_MAIN_InitRows(p);
    if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct Obj02260 *)p)->f49C8)) {
        a=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4);
        b=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4+16);
    } else {
        a=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4);
        a+=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4+16);
        b=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4+32);
        b+=COMM_BTL_DEMO_MAIN_CountFlags(*(char * *)&((struct Obj02260 *)p)->f4+48);
    }
    COMM_BTL_DEMO_MAIN_InitBattleContext(p+0x498C,p+0xC,p+0x24,a,b,((struct Obj02260 *)p)->f49C8);
    return 1;
}

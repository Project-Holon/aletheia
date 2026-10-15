/*
 * function: COMM_BTL_DEMO_MAIN_MarkRowsDone
 * address: 0x021BA480
 * packet: pkt_ov213_021BA480
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 *   COMM_BTL_DEMO_MAIN_MarkRowDone 0x021BA1C0 thumb ov213
 */
#include "../include/Obj25703.h"
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(unsigned);extern void COMM_BTL_DEMO_MAIN_MarkRowDone(char *);
enum Count{CountZero,CountTwo=2,CountFour=4};void COMM_BTL_DEMO_MAIN_MarkRowsDone(char *p){int i;enum Count count;if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(((struct Obj25703 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x485C;for(i=0;i<count;i++)COMM_BTL_DEMO_MAIN_MarkRowDone(p+i*84);}

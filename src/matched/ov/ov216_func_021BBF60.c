/*
 * function: func_021BBF60
 * address: 0x021BBF60
 * packet: pkt_ov216_021BBF60
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj10942.h"
extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
int func_021BBF60(char *p){switch(((struct Obj10942 *)p)->f4){case 0:FADE_Start(3,16,0,0);(((struct Obj10942 *)p)->f4)++;break;case 1:if(FADE_IsActive()==0){((struct Obj10942 *)p)->f4=0;return 2;}break;}return 1;}

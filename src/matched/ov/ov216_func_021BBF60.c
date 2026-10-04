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
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 */
#include "../include/Obj10942.h"
extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
int func_021BBF60(char *p){switch(((struct Obj10942 *)p)->f4){case 0:func_0204E720(3,16,0,0);(((struct Obj10942 *)p)->f4)++;break;case 1:if(func_0204E804()==0){((struct Obj10942 *)p)->f4=0;return 2;}break;}return 1;}

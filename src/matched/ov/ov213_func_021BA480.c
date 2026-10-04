/*
 * function: func_021BA480
 * address: 0x021BA480
 * packet: pkt_ov213_021BA480
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BA1C0 0x021BA1C0 thumb ov213
 */
#include "../include/Obj25703.h"
extern int func_021B9E50(unsigned);extern void func_021BA1C0(char *);
enum Count{CountZero,CountTwo=2,CountFour=4};void func_021BA480(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25703 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x485C;for(i=0;i<count;i++)func_021BA1C0(p+i*84);}

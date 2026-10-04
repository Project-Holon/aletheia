/*
 * function: func_021D5C64
 * address: 0x021D5C64
 * packet: pkt_ov123_021D5C64
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_SNPrintf 0x0208D80C arm
 *   func_021C5C04 0x021C5C04 arm ov114
 *   d_021DAA74 0x021DAA74 data a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 */
#include "../include/Obj22946.h"
extern const char d_021DAA74[],d_021DAA54[];
extern int OS_SNPrintf(char *,int,const char *,...);
extern int func_021C5C04(void *,const char *,const char *);
int func_021D5C64(char *p,void *arg,int value){char buf[20];int ok=0;((struct Obj22946 *)p)->fB0=0;OS_SNPrintf(buf,20,d_021DAA74,value);if(func_021C5C04(arg,buf,d_021DAA54))ok=1;return ok;}

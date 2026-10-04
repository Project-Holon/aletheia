/*
 * function: func_021B6448
 * address: 0x021B6448
 * packet: pkt_ov179_021B6448
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B6268 0x021B6268 thumb ov179
 *   func_02049238 0x02049238 arm
 *   func_021B6248 0x021B6248 thumb ov179
 *   func_021B6220 0x021B6220 thumb ov179
 */
#include "../include/Obj14387.h"
typedef unsigned int   u32;
extern u32 func_020221A4(void); extern int func_02005E50(void); extern void func_02005D28(void);
extern void func_021B6268(char *); extern void func_02049238(void *); extern void func_021B6248(char *); extern void func_021B6220(void);
int func_021B6448(char *p) {
 if(func_020221A4()==0) return 1;
 if(func_02005E50()==1) return 1;
 func_02005D28();
 if(((struct Obj14387 *)p)->f6058==1) { func_021B6268(p); func_02049238(((struct Obj14387 *)p)->f4); func_021B6248(p); func_021B6220(); }
 return 6;
}

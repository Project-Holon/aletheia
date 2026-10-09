/*
 * file:     unit_021D7CEC_p01.c
 * unit:     yes
 * function: func_021D7CEC, func_021D7CF4, func_021D7D20
 * address:  0x021D7CEC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087058 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   d_021D9E40 0x021D9E40 data a4
 */
#include "../../matched/include/G_Clear.h"

extern int func_02087058(void);
extern void func_02086FE8(void);
int func_021D7CEC(void *p);
int func_021D7CF4(void);
void func_021D7D20(void);
extern struct Clear d_021D9E40;


int func_021D7CEC(void *p){return 1;}


int func_021D7CF4(void){if(!func_02087058())func_02086FE8();*(int*)(((char *)&d_021D9E40)+0x270)=16;return 1;}

void func_021D7D20(void){}

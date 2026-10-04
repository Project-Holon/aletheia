/*
 * function: func_021D849C
 * address: 0x021D849C
 * packet: pkt_ov121_021D849C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00326.h"
extern void func_021DA2A8(void *),func_021DA280(void *);
extern void func_020409B4(unsigned),func_02040588(unsigned,unsigned);
void func_021D849C(char *p) {
 if(((struct Obj00326 *)p)->f28C) {
  *(unsigned short *)0x04001050=0;
  func_021DA2A8(((struct Obj00326 *)p)->f28C);func_021DA280(((struct Obj00326 *)p)->f28C);
  *(unsigned *)&((struct Obj00326 *)p)->f28C=0;
  func_020409B4(4);func_02040588(6,0);
 }
}

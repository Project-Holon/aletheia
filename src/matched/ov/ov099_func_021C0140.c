/*
 * function: func_021C0140
 * address: 0x021C0140
 * packet: pkt_ov099_021C0140
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj07959.h"
extern unsigned int KEY_GetTrg(void);
extern void func_021BAAB8(char *,int,int);
int func_021C0140(char *p,int ret) {
 if (((struct Obj07959 *)p)->f1E0>0) { --((struct Obj07959 *)p)->f1E0; return ret; }
 if (KEY_GetTrg()&3) {
  func_021BAAB8(p,26,1);
  ((struct Obj07959 *)p)->f1CC=51;
  ((struct Obj07959 *)p)->f1E0=1;
 }
 return ret;
}

/*
 * function: func_021DEC4C
 * address: 0x021DEC4C
 * packet: pkt_ov119_021DEC4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E69C0 0x021E69C0 thumb ov119
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021DEBA0 0x021DEBA0 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj05337.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021E69C0(char *p);
extern void func_021E68F4(int p, int i);
extern void func_021DEBD4(void *);
extern void func_021DEBA0(char *p);
extern void func_021D8E84(void *,int);
extern u8 func_020355C4(void);
extern u32 WIPE_SYS_EndCheck(void);
void func_021DEC4C(void *p) {
 if(func_021E69C0(p)) {
  if(func_020355C4()) {func_021E68F4((int)p,-1);((struct Obj05337 *)p)->f10A0=0;}
  else {func_021E68F4((int)p,0);((struct Obj05337 *)p)->f10A0=0;}
  if(WIPE_SYS_EndCheck()) {func_021DEBD4(p);func_021D8E84(p,(int)func_021DEBA0);}
 }
}

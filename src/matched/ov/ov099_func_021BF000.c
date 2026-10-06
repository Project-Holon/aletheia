/*
 * function: func_021BF000
 * address: 0x021BF000
 * packet: pkt_ov099_021BF000
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEEBC 0x021BEEBC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../include/Obj00008.h"
extern void func_021BEEBC(char *);
extern void func_021C18C8(char *,int,int);
extern void func_021BDE30(void *,int,int);
extern void func_021C2408(char *);
typedef unsigned char  u8;
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
int func_021BF000(char *p,int ret) {
 func_021BEEBC(p);
 func_021C18C8(p,1,2);
 func_021BDE30(p,1,2);
 ((struct Obj00008 *)p)->f1CC=11;
 func_021C2408(p);
 func_0203D7B0(0);
 func_0203D7BC(0);
 return ret;
}

/*
 * function: func_021B6F80
 * address: 0x021B6F80
 * packet: pkt_ov180_021B6F80
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6188 0x021B6188 thumb ov180
 *   func_021B7390 0x021B7390 thumb ov180
 *   func_021B66D4 0x021B66D4 thumb ov180
 *   func_021B7F0C 0x021B7F0C thumb ov180
 *   func_021B6340 0x021B6340 thumb ov180
 *   func_021B6914 0x021B6914 thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021B6188(u8 *p);
extern void func_021B7390(char *);
extern void func_021B66D4(int *p);
extern void func_021B7F0C(int *p);
extern void func_021B6340(void);
extern void func_021B6914(int *);
int func_021B6F80(char *p){func_021B6188((u8 *)p);func_021B7F0C((int *)p);func_021B7390(p);func_021B6340();func_021B6914((int *)p);func_021B66D4((int *)p);((struct Obj04569 *)p)->f8=0;return 1;}

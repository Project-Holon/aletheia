/*
 * function: func_021B6B70
 * address: 0x021B6B70
 * packet: pkt_ov180_021B6B70
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6188 0x021B6188 thumb ov180
 *   func_021B7D44 0x021B7D44 thumb ov180
 *   func_021B7390 0x021B7390 thumb ov180
 *   func_021B675C 0x021B675C thumb ov180
 *   func_021B6770 0x021B6770 thumb ov180
 *   func_021B66D4 0x021B66D4 thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021B6188(u8 *p);
extern void func_021B7D44(int *);
extern void func_021B7390(char *);
extern void func_021B675C(void);
extern void func_021B6770(void);
extern void func_021B66D4(int *p);
int func_021B6B70(char *p){func_021B6188((u8 *)p);*(u16 *)0x04000050=0;*(u16 *)0x04001050=0;func_021B7D44((int *)p);func_021B7390(p);func_021B675C();func_021B6770();func_021B66D4((int *)p);((struct Obj04569 *)p)->f8=0;return 7;}

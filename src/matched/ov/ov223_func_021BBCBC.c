/*
 * function: func_021BBCBC
 * address: 0x021BBCBC
 * packet: pkt_ov223_021BBCBC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword clear at021BBCC2/021BBCC8 to04000050/04001050.
 * symbols:
 *   func_021BB35C 0x021BB35C thumb ov223
 *   func_021BAC6C 0x021BAC6C thumb ov223
 *   func_021BABFC 0x021BABFC thumb ov223
 *   func_021B98F4 0x021B98F4 thumb ov223
 */
#include "../include/Obj05570.h"
extern void func_021BB35C(char *p);
extern void func_021B98F4(char *p);
extern void func_021BAC6C(unsigned char *);
extern int func_021BABFC(unsigned char *);
int func_021BBCBC(unsigned char *p){*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;func_021BB35C((char *)p);func_021BAC6C(p);func_021BABFC(p);func_021B98F4((char *)p);((struct Obj05570 *)p)->f10=0;return 7;}

/*
 * unit: yes
 * function: func_021B727C, func_021B728C, func_021B72A0
 * address: 0x021B727C
 * packet: pkt_ov101_021B727C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02040588 0x02040588 arm
 */
#include "../include/Obj13722.h"
#include "../include/Obj13723.h"
#include "../include/Obj22132.h"
typedef unsigned char u8;
extern void func_02040588(u8,u8);
int func_021B727C(int p) { if(((struct Obj22132 *)p)->f50) return 1; return 0; }
void func_021B728C(int p,int b) {
 ((struct Obj13722 *)p)->f5C=b;
 func_02040588(((struct Obj13722 *)p)->f3C,b);
}
void func_021B72A0(int p,int b) {
 ((struct Obj13723 *)p)->f5C=b;
 ((struct Obj13723 *)p)->f50=0;
}

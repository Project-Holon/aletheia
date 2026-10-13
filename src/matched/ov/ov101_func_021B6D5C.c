/*
 * unit: yes
 * function: IRC_COMPATIBLE_FirstTestCreateArgs, IRC_COMPATIBLE_FirstTestDestroyArgs
 * address: 0x021B6D5C
 * packet: pkt_ov101_021B6D5C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
#include "../include/Obj10228.h"
#include "../include/Obj10229.h"
#include "../include/Obj10230.h"
#include "../include/Obj10231.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern char IRC_COMPATIBLE_SourceFileName[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(int,int,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int IRC_COMPATIBLE_FirstTestCreateArgs(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x18,0,IRC_COMPATIBLE_SourceFileName,0x3e4);
 func_02082BCC(q,0,0x18);
 ((struct Obj10229 *)q)->f0=**(int * *)&((struct Obj10228 *)p)->f10;
 ((struct Obj10229 *)q)->f4=((struct Obj10228 *)p)->f0;
 ((struct Obj10229 *)q)->f8=((struct Obj10228 *)p)->f3C;
 return q;
}
void IRC_COMPATIBLE_FirstTestDestroyArgs(int p,int q) {
 ((struct Obj10231 *)q)->f28=((struct Obj10230 *)p)->fC;
 ((struct Obj10231 *)q)->f2C=((struct Obj10230 *)p)->f10;
 ((struct Obj10231 *)q)->f2D=((struct Obj10230 *)p)->f14;
 func_020307B0((void *)p);
}

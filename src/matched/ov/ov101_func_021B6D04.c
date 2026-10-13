/*
 * unit: yes
 * function: IRC_COMPATIBLE_SecondTestCreateArgs, IRC_COMPATIBLE_SecondTestDestroyArgs
 * address: 0x021B6D04
 * packet: pkt_ov101_021B6D04
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * MI_CpuFill8 0x02082BCC arm
 * IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
#include "../include/Obj07969.h"
#include "../include/Obj07970.h"
#include "../include/Obj10226.h"
#include "../include/Obj10227.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern char IRC_COMPATIBLE_SourceFileName[];
extern void *func_02030734(unsigned heapId,unsigned size,int clear,const char *site,u16 tag);
extern void MI_CpuFill8(int,int,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int IRC_COMPATIBLE_SecondTestCreateArgs(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x14,0,IRC_COMPATIBLE_SourceFileName,0x3af);
 MI_CpuFill8(q,0,0x14);
 ((struct Obj10227 *)q)->f0=**(int * *)&((struct Obj10226 *)p)->f10;
 ((struct Obj10227 *)q)->f4=((struct Obj10226 *)p)->f0;
 ((struct Obj10227 *)q)->f8=((struct Obj10226 *)p)->f3C;
 return q;
}
void IRC_COMPATIBLE_SecondTestDestroyArgs(int p,int q) {
 ((struct Obj07970 *)q)->f24=((struct Obj07969 *)p)->fC;
 ((struct Obj07970 *)q)->f2E=((struct Obj07969 *)p)->f10;
 ((struct Obj07970 *)q)->f2F=((struct Obj07969 *)p)->f11;
 ((struct Obj07970 *)q)->f30=((struct Obj07969 *)p)->f12;
 func_020307B0((void *)p);
}

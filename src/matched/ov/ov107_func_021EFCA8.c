/*
 * function: func_021EFCA8
 * address: 0x021EFCA8
 * packet: pkt_ov107_021EFCA8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F0DDC 0x021F0DDC thumb ov107
 *   func_021F0AE4 0x021F0AE4 thumb ov107
 *   func_021F0D28 0x021F0D28 thumb ov107
 *   func_0208459C 0x0208459C arm
 *   WIH_End 0x02179570 thumb ov014
 *   d_021F6EA0 0x021F6EA0 data ov107 a4
 *   func_021EFC10 0x021EFC10 thumb ov107
 */
#include "../include/Obj22279.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021F0DDC(void);
extern void func_021F0AE4(void);
extern u16 func_021F0D28(void);
typedef unsigned int   u32;
extern void func_0208459C(int clear, u32 irqFlags);
extern int WIH_End(void (*cb)(int));
extern u8 d_021F6EA0[];
extern int func_021EFC10(void);
void func_021EFCA8(u8 *p) {
 unsigned v=func_021F0DDC();
 if(v==1) func_021F0AE4();
 while(func_021F0D28()!=0&&func_021F0D28()!=5) func_0208459C(1,1);
 if(((struct Obj22279 *)p)->f1C==1) {
 *(int *)(d_021F6EA0+8)=0;
 while(WIH_End((void (*)(int))((int)func_021EFC10))) func_0208459C(1,1);
 while(*(int *)(d_021F6EA0+8)==0) func_0208459C(1,1);
 }
}

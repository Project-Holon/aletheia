/*
 * function: func_021B7860
 * address: 0x021B7860
 * packet: pkt_ov102_021B7860
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021B787A and 0x021B7884 read display registers for update.
 * symbols:
 * func_02082BCC 0x02082BCC arm
 * func_0204335C 0x0204335C arm
 * func_0204363C 0x0204363C arm
 * func_0204361C 0x0204361C arm
 * func_020433E0 0x020433E0 arm
 * func_021B7AB4 0x021B7AB4 thumb ov102
 * func_021B78FC 0x021B78FC thumb ov102
 * func_020056A0 0x020056A0 thumb
 * d_021B8B2C 0x021B8B2C data a4
 */
#include "../../../matched/include/Obj22140.h"
extern void func_02082BCC(void *,int,unsigned);
extern void func_0204335C(unsigned);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_021B7AB4(void *,const void *,unsigned);
extern void func_021B78FC(unsigned,void *);
extern unsigned func_020056A0(void (*)(unsigned,void *),void *,unsigned);
extern unsigned d_021B8B2C[];
void func_021B7860(char *p,unsigned b) {
 func_02082BCC(p,0,0x94);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 func_0204335C(0);
 func_0204363C(0);
 func_0204361C();
 func_020433E0((const struct DispVram *)d_021B8B2C);
 func_021B7AB4(p,d_021B8B2C,b);
 ((struct Obj22140 *)p)->f90=func_020056A0(func_021B78FC,p,0);
}

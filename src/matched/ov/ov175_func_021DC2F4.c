/*
 * function: func_021DC2F4
 * address: 0x021DC2F4
 * packet: pkt_ov175_021DC2F4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   d_021E2FA4 0x021E2FA4 data a1
 */
#include "../include/Obj14347.h"
extern void MI_CpuFill8(void *,int,int);
extern int func_0208D7E0(char *,const char *,...);
extern const char d_021E2FA4[];
void func_021DC2F4(char *p,unsigned a)
{
    ((struct Obj14347 *)p)->f12C=0;
    ((struct Obj14347 *)p)->f1458=0;
    MI_CpuFill8(p+0x144c,0,10);
    MI_CpuFill8(p+0x1390,0,0xb0);
    func_0208D7E0(p+0x144c,d_021E2FA4,a);
}

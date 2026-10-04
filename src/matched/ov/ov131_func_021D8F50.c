/*
 * function: func_021D8F50
 * address: 0x021D8F50
 * packet: pkt_ov131_021D8F50
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_021D91F0 0x021D91F0 thumb ov131
 */
#include "../include/Obj02845.h"

typedef unsigned char  u8;
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_021D91F0(u8 *a, u8 *p, u8 *entry);
void func_021D8F50(void *a, unsigned char *p)
{
    unsigned char i;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj02845 *)p)->f14=0;
    ((struct Obj02845 *)p)->f0=1;
    ((struct Obj02845 *)p)->f4=0;
    ((struct Obj02845 *)p)->f8=0;
    ((struct Obj02845 *)p)->fC=1;
    ((struct Obj02845 *)p)->f20=0;
    ((struct Obj02845 *)p)->f24=0;
    for(i=0;i<10;i++) {
        *(unsigned short *)(p+i*20+0x70)=func_021D9428(p,i);
        func_021D91F0(a,p,p+0x70+i*20);
    }
}

/*
 * function: func_021C72E4
 * address: 0x021C72E4
 * packet: pkt_ov128_021C72E4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02040618 0x02040618 arm
 *   func_021CA16C 0x021CA16C thumb ov128
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14035.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void func_02041090(unsigned,void *,unsigned,unsigned,u8,u8);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_021CA16C(u8 *,int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021C72E4(u8 *p,int *q,u8 *ctx)
{
    u16 *data;
    func_021C6ADC(ctx,ctx+12,0);
    data=*(u16 * *)&((struct Obj14035 *)p)->f18;
    func_02041090(2,(u8 *)data+12,0,0,data[0]>>3,data[1]>>3);
    func_02040618(2,0,0);
    func_02040618(2,3,0);
    if(*q==0) func_021CA16C(ctx,((struct Obj14035 *)p)->f0);
    else func_02041B6C(2);
}

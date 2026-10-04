/*
 * function: func_021FD71C
 * address: 0x021FD71C
 * packet: pkt_ov186_021FD71C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj14467.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Callback)(u8 *,int *,u32);
void func_021FD71C(u8 *p)
{
    if(*(Callback *)&((struct Obj14467 *)p)->f0!=0)(*(Callback *)p)(p,(int *)(p+4),((struct Obj14467 *)p)->f8);
}

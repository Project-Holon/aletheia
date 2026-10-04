/*
 * function: func_021D9C3C
 * address: 0x021D9C3C
 * packet: pkt_ov131_021D9C3C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DC2C2 0x021DC2C2 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045798 0x02045798 arm
 *   func_021D9E30 0x021D9E30 thumb ov131
 *   func_021DB7D4 0x021DB7D4 thumb ov131
 */
#include "../include/Obj04511.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021DC2C2[];
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void func_02045798(struct Descriptor *p, u8 v);
extern void func_021D9E30(void *a, int b);
extern void func_021DB7D4(u8 *p, u8 *q, u8 *entry);
void func_021D9C3C(void *a,u8 *p)
{
    u8 i;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(((struct Obj04511 *)p)->f60,13);
    func_021D9E30(a,(int)p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    p[41]=255;
    ((struct Obj04511 *)p)->f0=1;
    ((struct Obj04511 *)p)->f20=0;
    p[40]=0;
}

/*
 * function: func_021D7C38
 * address: 0x021D7C38
 * packet: pkt_ov131_021D7C38
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_020450F0 0x020450F0 arm
 *   d_021DC288 0x021DC288 data a1
 *   func_021D7F04 0x021D7F04 thumb ov131
 *   func_021D8288 0x021D8288 thumb ov131
 */
#include "../include/Obj01547.h"

typedef unsigned char  u8;
extern void *func_021D6064(unsigned char *p);
typedef unsigned int   u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern const unsigned char d_021DC288[];
extern void func_021D7F04(u8 *p, u8 *q, void *mon);
extern void func_021D8288(u8 *a, u8 *p, void *mon);
void func_021D7C38(void *a, unsigned char *p)
{
    void *arc=func_021D6064(a);
    unsigned char i;
    for(i=0;i<10;i++) {
        unsigned int offset=i*4;
        *(void **)(p+offset+0xc)=(void *)func_020450F0(1,d_021DC288[offset],d_021DC288[offset+1],d_021DC288[offset+2],d_021DC288[offset+3],14,1);
    }
    ((struct Obj01547 *)p)->f34=(void *)func_020450F0(4,4,5,24,20,14,1);
    func_021D7F04(a,p,arc);
    func_021D8288(a,p,arc);
    ((struct Obj01547 *)p)->f4=1;
}

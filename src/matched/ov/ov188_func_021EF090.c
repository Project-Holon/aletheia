/*
 * function: func_021EF090
 * address: 0x021EF090
 * packet: pkt_ov188_021EF090
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008494 0x02008494 thumb
 *   func_021EF140 0x021EF140 thumb ov188
 */
#include "../include/Obj14492.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02008494(void *, void *);
extern void func_021EF140(u8 *, u8 *);
void func_021EF090(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        p = b+i*0x44;
        switch(((struct Obj14492 *)p)->f16C8) {
        case 1: func_02008494(b+0x16CC+i*0x44, *(void **)(a+0x34+i*4)); break;
        case 2: func_021EF140(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44); break;
        }
        a[0x44+i] = ((struct Obj14492 *)p)->f16CA;
    }
}

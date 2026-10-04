/*
 * function: func_021EF140
 * address: 0x021EF140
 * packet: pkt_ov188_021EF140
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045924 0x02045924 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02045A98 0x02045A98 arm
 */
#include "../include/Obj01970.h"
#include "../include/Obj02529.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Strbuf;
struct U16Vec;
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_02045A98(void);
void func_021EF140(u8 *a, u8 *b)
{
    unsigned i;
    u16 *p;
    ((struct Obj01970 *)a)->f0 = ((struct Obj02529 *)b)->f4;
    ((struct Obj01970 *)a)->f4 = ((struct Obj02529 *)b)->f6;
    ((struct Obj01970 *)a)->f8 = ((struct Obj02529 *)b)->f0;
    ((struct Obj01970 *)a)->f18 = ((struct Obj02529 *)b)->f30;
    ((struct Obj01970 *)a)->f1A = ((struct Obj02529 *)b)->f32;
    ((struct Obj01970 *)a)->f1C = ((struct Obj02529 *)b)->f34;
    ((struct Obj01970 *)a)->f1E = ((struct Obj02529 *)b)->f36;
    ((struct Obj01970 *)a)->f20 = ((struct Obj02529 *)b)->f38;
    ((struct Obj01970 *)a)->f22 = ((struct Obj02529 *)b)->f3A;
    ((struct Obj01970 *)a)->f24 = ((struct Obj02529 *)b)->f3C;
    ((struct Obj01970 *)a)->f26 = ((struct Obj02529 *)b)->f3E;
    for(i=0;i<4;i++) *(u16 *)(a+12+i*2) = *(u16 *)(b+8+i*2);
    func_02045924(((struct Obj01970 *)a)->f14, (u16 *)(b+16));
    p = func_02045A90(((struct Obj01970 *)a)->f14);
    while (*p != func_02045A98()) p++;
}

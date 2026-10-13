/*
 * function: func_021EF0F4
 * address: 0x021EF0F4
 * packet: pkt_ov188_021EF0F4
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_ToChars 0x02045A38 arm
 */
#include "../include/Obj02238.h"
#include "../include/Obj02528.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
void func_021EF0F4(u8 *a, u8 *b)
{
    unsigned i;
    ((struct Obj02528 *)b)->f4 = ((struct Obj02238 *)a)->f0;
    ((struct Obj02528 *)b)->f6 = ((struct Obj02238 *)a)->f4;
    ((struct Obj02528 *)b)->f0 = ((struct Obj02238 *)a)->f8;
    ((struct Obj02528 *)b)->f30 = ((struct Obj02238 *)a)->f18;
    ((struct Obj02528 *)b)->f32 = ((struct Obj02238 *)a)->f1A;
    ((struct Obj02528 *)b)->f34 = ((struct Obj02238 *)a)->f1C;
    ((struct Obj02528 *)b)->f36 = ((struct Obj02238 *)a)->f1E;
    ((struct Obj02528 *)b)->f38 = ((struct Obj02238 *)a)->f20;
    ((struct Obj02528 *)b)->f3A = ((struct Obj02238 *)a)->f22;
    ((struct Obj02528 *)b)->f3C = ((struct Obj02238 *)a)->f24;
    ((struct Obj02528 *)b)->f3E = ((struct Obj02238 *)a)->f26;
    for(i=0;i<4;i++) *(u16 *)(b+8+i*2) = *(u16 *)(a+12+i*2);
    STRBUF_ToChars(((struct Obj02238 *)a)->f14, (u16 *)(b+16), 16);
}

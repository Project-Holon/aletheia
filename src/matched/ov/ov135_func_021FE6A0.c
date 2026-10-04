/*
 * function: func_021FE6A0
 * address: 0x021FE6A0
 * packet: pkt_ov135_021FE6A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8B18 0x021C8B18 arm ov114
 *   func_021C8BC4 0x021C8BC4 arm ov114
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj01161.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } Request;
extern void func_021C8B18(void *, int, void *);
extern void func_021C8BC4(void *, void *);
extern void func_02082BCC(void *, int, u32);
int func_021FE6A0(u8 *p)
{
    Request q;
    if (((struct Obj01161 *)p)->fF84 == 0) {
        func_021C8B18(p + 0xb56, 7, p + 0x20c);
    } else {
        func_02082BCC(&q, 0, 8);
        q.id = *(short *)&((struct Obj01161 *)p)->fB56;
        q.a = *(s8 *)&((struct Obj01161 *)p)->fB58;
        q.b = *(s8 *)(p + 0xb59);
        q.c = *(s8 *)&((struct Obj01161 *)p)->fB5A;
        q.d = *(s8 *)(p + 0xb5b);
        q.mode = 7;
        q.flag = ((struct Obj01161 *)p)->fF84;
        func_021C8BC4(&q, p + 0x20c);
    }
    ((struct Obj01161 *)p)->fB5C = ((struct Obj01161 *)p)->fB56;
    ((struct Obj01161 *)p)->fB5E = ((struct Obj01161 *)p)->fB58;
    ((struct Obj01161 *)p)->fB60 = ((struct Obj01161 *)p)->fB5A;
    ((struct Obj01161 *)p)->fB64 = *(u32 *)&((struct Obj01161 *)p)->fF84;
    ((struct Obj01161 *)p)->fF8C = 0;
    ((struct Obj01161 *)p)->f28 = 18;
    ((struct Obj01161 *)p)->fE1A = 0;
    return 2;
}

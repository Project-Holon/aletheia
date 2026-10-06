/*
 * function: func_021BCCCC
 * address:  0x021BCCCC
 * packet:   pkt_ov091_021BCCCC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BCE84  0x021BCE84  thumb  ov091
 *   func_021BCEAC  0x021BCEAC  thumb  ov091
 *   func_021BD05C  0x021BD05C  thumb  ov091
 *   func_021BD59C  0x021BD59C  thumb  ov091
 */
#include "../include/Obj00047.h"
#include "../include/Obj07737.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021BCE84(char *p);
extern void func_021BCEAC(u8 *p);
typedef unsigned int   u32;
extern u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w);
extern void func_021BD59C(char *p);

void func_021BCCCC(int p)
{
    int r;
    func_021BCE84((char *)p);
    func_021BCEAC((u8 *)p);
    r = ((struct Obj00047 *)p)->f280;
    if (((struct Obj07737 *)r)->f8C == 1) {
        switch (((struct Obj07737 *)r)->f64) {
        case 1:
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x74), 10, 0, 2);
            break;
        case 2:
            ((struct Obj00047 *)p)->f1F0 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x68), 0, 0, 0);
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x74), 0xb, 0, 0);
            ((struct Obj00047 *)p)->f1F8 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x80), 0x16, 0, 0);
            break;
        }
    }
    r = ((struct Obj00047 *)p)->f280;
    ((struct Obj00047 *)p)->f20C = ((struct Obj07737 *)r)->f94;
    ((struct Obj00047 *)p)->f20D = 0;
    if (((struct Obj07737 *)r)->f90 == 1) {
        func_021BD59C((char *)p);
    }
    ((struct Obj00047 *)p)->f24E = 0;
}

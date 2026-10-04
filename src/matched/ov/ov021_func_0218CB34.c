/*
 * function: func_0218CB34
 * address:  0x0218CB34
 * packet:   pkt_ov021_0218CB34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218DD70  0x0218DD70  thumb  ov021
 *   func_0218D1D0  0x0218D1D0  thumb  ov021
 *   func_0218D304  0x0218D304  thumb  ov021
 *   func_0218D444  0x0218D444  thumb  ov021
 *   func_0218D570  0x0218D570  thumb  ov021
 *   func_0218D7A8  0x0218D7A8  thumb  ov021
 *   func_0218DE78  0x0218DE78  thumb  ov021
 *   func_02169520  0x02169520  thumb  ov010
 *   func_02169308  0x02169308  thumb  ov010
 *   func_0218DEFC  0x0218DEFC  thumb  ov021
 *   func_0218DF80  0x0218DF80  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0218B83C  0x0218B83C  thumb  ov021
 *   func_021A73DC  0x021A73DC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00807.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_0218DD70(void *e);
typedef unsigned int   u32;
struct Elem;
extern void func_0218D1D0(char *p, void *a, struct Elem *e);
extern void func_0218D304(char *p, void *a, void *b);
extern void func_0218D444(char *p, void *a, void *b);
extern void func_0218D570(char *p, void *a, void *b);
struct Cell;
struct Obj;
extern int func_0218D7A8(struct Obj *p, struct Cell *nc);
extern void func_0218DE78(char *p);
extern int func_02169520(int a0, int a1);
extern void func_02169308(u8 *p);
extern void func_0218DEFC(char *p, int o, int i);
extern void func_0218DF80(char *p);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0218B83C(char *p);
extern void func_021A73DC(u32 *s);

int func_0218CB34(char *p)
{
    int i;
    int r;
    int x;
    int y;
    u16 *h;

    if (((struct Obj00807 *)p)->f1C == 0)
        return 0;
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++)
        func_0218DD70(*(char * *)&((struct Obj00807 *)p)->f28 + i * 16);
    switch (((struct Obj00807 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 3:
        func_0218D570(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    }
    func_0218D7A8((struct Obj *)p, ((struct Obj00807 *)p)->f28);
    r = 0;
    func_0218DE78(p);
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++) {
        func_02169520(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), (int)(&h));
        if (*h == 1)
            r = 1;
        func_02169308((u8 *)(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28)));
        func_0218DEFC(p, *(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), i);
    }
    func_0218DF80(p);
    x = func_0207C768(((struct Obj00807 *)p)->f34, ((struct Obj00807 *)p)->f4);
    y = func_0207C768(((struct Obj00807 *)p)->f3C, ((struct Obj00807 *)p)->f4);
    ((struct Obj00807 *)p)->f30 = (x >> 12) + (y >> 12) * ((struct Obj00807 *)p)->f14;
    func_0218B83C(((struct Obj00807 *)p)->f64);
    if (((struct Obj00807 *)p)->f68 != 0)
        func_021A73DC(((struct Obj00807 *)p)->f68);
    return r;
}

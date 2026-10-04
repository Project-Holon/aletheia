/*
 * function: func_02185764
 * address:  0x02185764
 * packet:   pkt_ov023_02185764
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02186660  0x02186660  thumb  ov023
 *   func_02186164  0x02186164  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02184114  0x02184114  thumb  ov022
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02039338  0x02039338  arm
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */
#include "../include/Obj05108.h"

typedef unsigned int u32;

extern int func_02186660(char *p);
extern int func_02186164(char *p);
typedef unsigned short u16;
extern void func_02186444(char *p, u32 v);
extern int func_02184114(unsigned char *p);
extern void func_021852F4(void *p, int flag);
extern void func_0201F7A8(void *desc, u32 kind);
extern u16 func_02039338(void);
extern void func_02184560(char *p, int a);
extern void func_02185354(char *p);

int func_02185764(char *p, int x)
{
    int m;

    m = func_02186660(p);
    if (((struct Obj05108 *)p)->f1AC != func_02186164(p) || ((struct Obj05108 *)p)->f9280 != 0) {
        func_02185354(p);
        return x;
    }
    switch (m) {
    case 0:
        func_02186444(p, 0x11);
        func_02184114((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj05108 *)p)->f4));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(((struct Obj05108 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj05108 *)p)->f11C), 2);
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            ((struct Obj05108 *)p)->f9E6C = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}

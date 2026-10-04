/*
 * function: func_02012DD0
 * address:  0x02012DD0
 * packet:   pkt_02012DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012DD0.c \
 *       --func func_02012DD0 --addr 0x02012DD0 --cc 1.1p1 --thumb
 */
#include "../include/Obj11252.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int  func_02005C64(void);
struct Sub02007168;
extern u32 func_02007168(struct Sub02007168 *p);
extern int func_020351A0(u32 v);
extern void func_02010444(void);

int func_02012DD0(u8 *p)
{
    int r;

    if (func_02005C64() == 1) {
        return 0;
    }
    r = func_02007168((struct Sub02007168 *)(((struct Obj11252 *)p)->f0));
    if ((u32)(r - 2) <= 1) {
        func_020351A0(2);
        func_02010444();
        ((struct Obj11252 *)p)->f1CE = 0;
    }
    return r;
}

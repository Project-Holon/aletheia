/*
 * function: func_021EFC78
 * address:  0x021EFC78
 * packet:   pkt_ov093_021EFC78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: func_021E8AFC takes a one-word struct by value (its own file spells
 * it as a union); the `adds r0,r5,#0 ; adds r0,#0x28 ; ldr r0,[r0]` argument
 * setup is that struct copy, not a plain u32 load.
 *
 * symbols:
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_021E8AFC  0x021E8AFC  thumb  ov093
 *   func_021EFCD4  0x021EFCD4  thumb  ov093
 *   func_021EF83C  0x021EF83C  thumb  ov093
 */
#include "../include/Obj06299.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021EFCE4(char *a, int b);
typedef struct { u32 v; } Slot;
extern u8 func_021E8AFC(Slot s);
extern void func_021EFCD4(u32 a);
extern void func_021EF83C(char *a, u32 b);

void func_021EFC78(char *a, void (*cb)(u32, u32), u32 arg)
{
    u32 k;

    for (k = 1; k < 8; k++) {
        char *e;
        u32 lim;

        if (func_021EFCE4(a, k) == 0)
            continue;
        e = a + k * 4;
        lim = func_021E8AFC(*(Slot *)(e + 0x28));
        if (lim == 0)
            continue;
        ((struct Obj06299 *)e)->f48 += 1;
        if (((struct Obj06299 *)e)->f48 < lim)
            continue;
        if (((struct Obj06299 *)e)->f8 != 0) {
            func_021EFCD4(((struct Obj06299 *)e)->f8);
            ((struct Obj06299 *)e)->f8 = 0;
        }
        func_021EF83C(a, k);
        if (cb != 0)
            cb(k, arg);
    }
}

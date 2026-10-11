/*
 * file:     unit_021EFC1C.c
 * unit:     yes
 * function: func_021EFC1C, func_021EFC78
 * address:  0x021EFC1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06898080  0x06898080  thumb
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5750  0x021D5750  thumb  ov093
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_021E8AFC  0x021E8AFC  thumb  ov093
 *   func_021EF83C  0x021EF83C  thumb  ov093
 */
#include "../../matched/include/Obj06299.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[0xB0];
    u32 id[0x4D - 0x2C];    /* 0x0B0 */
    u32 count;              /* 0x134 */
} S;

typedef struct { u32 v; } Slot;

extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u8 a, u8 b);
extern u8 *func_021B9940(char *p, u8 i);
extern int func_021D5750(u8 *p, u16 id);
extern void *func_021EFCE4(char *a, int b);
extern u8 func_021E8AFC(Slot s);
extern void func_06898080(u32 a);
extern void func_021EF83C(char *a, u32 b);
int func_021EFC1C(S *a, char *x, void *m, u16 y);
void func_021EFC78(char *a, void (*cb)(u32, u32), u32 arg);


int func_021EFC1C(S *a, char *x, void *m, u16 y)
{
    u8 mon;
    u8 c;
    u32 i;
    u32 n;

    mon = func_021D5440(m);
    n = a->count;
    for (i = 0; i < n; i++) {
        c = a->id[i];
        if (func_021B9A24(mon, c) == 0) {
            if (func_021D5750(func_021B9940(x, c), y) != 0)
                return 1;
        }
    }
    return 0;
}


/*
 * Lever: func_021E8AFC takes a one-word struct by value (its own file spells
 * it as a union); the `adds r0,r5,#0 ; adds r0,#0x28 ; ldr r0,[r0]` argument
 * setup is that struct copy, not a plain u32 load.
 */
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
            func_06898080(((struct Obj06299 *)e)->f8);
            ((struct Obj06299 *)e)->f8 = 0;
        }
        func_021EF83C(a, k);
        if (cb != 0)
            cb(k, arg);
    }
}

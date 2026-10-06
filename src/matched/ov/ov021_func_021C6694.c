/*
 * function: func_021C6694
 * address:  0x021C6694
 * packet:   pkt_ov021_021C6694
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020478B8  0x020478B8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12952.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 k : 2; } K;

extern int func_020478B8(void *a, int idx, int amount);

int func_021C6694(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12952 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_020478B8((void *)(((struct Obj12952 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}

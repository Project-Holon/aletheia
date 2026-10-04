/*
 * function: func_0202C198
 * address:  0x0202C198
 * packet:   pkt_0202C198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Teardown for the list node func_0202C148 builds: walk the pointer array and
 * release each element, then free the array and clear all three headers.
 *
 * symbols:
 *   func_0202C308  0x0202C308  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202C198.c \
 *       --func func_0202C198 --addr 0x0202C198 --thumb --cc 1.1p1
 */
#include "../include/Obj04743.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202C308(void *p);
extern void func_020307B0(void *p);

void func_0202C198(u8 *p)
{
    int n = p[4];
    int i;

    for (i = 0; i < n; i++) {
        func_0202C308(*(u8 **)(*(u32 *)&((struct Obj04743 *)p)->f8 + (i << 2)));
    }
    func_020307B0(((struct Obj04743 *)p)->f8);
    p[4] = 0;
    *(u32 *)&((struct Obj04743 *)p)->f8 = 0;
    ((struct Obj04743 *)p)->fC = 0;
}

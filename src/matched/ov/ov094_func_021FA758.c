/*
 * function: func_021FA758
 * address:  0x021FA758
 * packet:   pkt_ov094_021FA758
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: releases the emitter slot for a key and marks it free.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FDB08 0x021FDB08 thumb ov094
 */
#include "../include/Obj00325.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *p, int v);
extern void func_021FDB08(void *);

int func_021FA758(void *a, char *s)
{
    int slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));

    if (slot != 16) {
        void **e = (void **)(s + 0xc) + slot;
        func_021FDB08(*e);
        *e = 0;
        ((int *)(s + 0x4c))[slot] = -1;
    }
    return ((struct Obj00325 *)s)->f23C;
}

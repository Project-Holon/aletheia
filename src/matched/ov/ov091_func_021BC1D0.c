/*
 * function: PLIST_MENU_FindItemTarget
 * address:  0x021BC1D0
 * packet:   pkt_ov091_021BC1D0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   PLIST_DEMO_CheckItemUsable  0x021BDD78  thumb  ov091
 */
#include "../include/Obj20908.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    char pad[0x27e];
    int *f;
} P;

extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern int PLIST_DEMO_CheckItemUsable(void *a, u32 id, int slot, u32 heap);

int PLIST_MENU_FindItemTarget(P *p)
{
    u8 n;
    u8 i;
    n = func_0201AA18((void *)*p->f);
    for (i = 0; i < n; i++) {
        int **q = &p->f;
        int e = (int)func_0201AB28((void *)*p->f, i);
        if (PLIST_DEMO_CheckItemUsable((void *)e, ((struct Obj20908 *)((char *)*q))->f44, 0, p->id) == 1)
            return i;
    }
    return -1;
}

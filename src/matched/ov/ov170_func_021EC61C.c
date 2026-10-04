/*
 * function: func_021EC61C
 * address:  0x021EC61C
 * packet:   pkt_ov170_021EC61C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021EC000 0x021EC000 thumb
 *   d_021EFD4C 0x021EFD4C data a1
 *
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
#include "../include/Obj24007.h"
#include "../include/Obj24008.h"

typedef struct {
    short x;
    short y;
} Pos;

typedef unsigned int   u32;
extern u32 func_0201AA18(void *p);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021EC000(char *p, int i, int v);
extern const Pos d_021EFD4C[];

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EC61C(unsigned char *p)
{
    unsigned n = func_0201AA18(((struct Obj24008 *)(*(char * *)&((struct Obj24007 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, d_021EFD4C[i].x + 0x98, d_021EFD4C[i].y, 0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}

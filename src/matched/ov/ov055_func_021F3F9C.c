/*
 * function: CROWD_SpawnPerson
 * address:  0x021F3F9C
 * packet:   pkt_ov055_021F3F9C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levers, each measured: CROWD_StartPerson's u16 parameters (its own file) put
 * y in r7 and spill x; the else arm's x is an if/else, not a ternary (the
 * shared truncation then stays ahead of the c[0]/c[1] loads); u8 t0 moves
 * the stack parameter's load to the front of the prologue; const a and c
 * let the final call's field loads rise above the argument stores.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   CROWD_FindPersonAtSpawn  0x021F3B48  thumb  ov055
 *   CROWD_StartPerson  0x021F3D0C  thumb  ov055
 */
#include "../include/Obj05137.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020056EC(u32);
struct Entry;
struct Table;
extern struct Entry *CROWD_FindPersonAtSpawn(struct Table *t, int x, int y, unsigned int dir, int unused, int *out);
struct O;
extern void CROWD_StartPerson(struct O *o, int a1, int a2, int idx, u16 p4, u16 p5, u16 p6, u16 p7, void *p8);

void CROWD_SpawnPerson(const char *a, int b, const u16 *c, u8 *d, u16 e)
{
    int out;
    u16 x;
    u16 y;
    u8 t0;
    u32 rnd;
    u16 m;

    t0 = 0;
    rnd = func_020056EC(0);
    m = c[4];
    if (m <= 1) {
        x = c[2] + rnd % (c[3] - c[2] + 1);
        if (m == 0)
            y = c[0] - e;
        else
            y = c[0] + e;
    } else {
        if (m == 2)
            x = c[2] - e;
        else
            x = c[2] + e;
        y = c[0] + rnd % (c[1] - c[0] + 1);
    }
    if (CROWD_FindPersonAtSpawn((struct Table *)a, x, y, m, 1, &out) == 0) {
        if (rnd % 10 == 0)
            t0 = 1;
    }
    if (out == 0)
        CROWD_StartPerson((struct O *)d, *(const int *)&((struct Obj05137 *)a)->f4, *(const int *)&((struct Obj05137 *)a)->f0, t0, x, y, c[4], (u16)(c[5] - e), (void *)c);
}

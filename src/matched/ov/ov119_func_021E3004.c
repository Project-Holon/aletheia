/*
 * function: func_021E3004
 * address:  0x021E3004
 * packet:   pkt_ov119_021E3004
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   func_02087A3C  0x02087A3C  arm
 *   func_020056BC  0x020056BC  thumb
 *   PARTICLE_SetupSystemBorrowed  0x02051360  arm
 */
#include "../include/Obj13911.h"

typedef unsigned int u32;

extern void func_02087A3C(int clear, u32 flags);
extern u32 func_020056BC(void);
extern void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3);

void func_021E3004(char *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        func_02087A3C(1, 1);
        PARTICLE_SetupSystemBorrowed(((void **)p)[i], (unsigned int)(((struct Obj13911 *)p)->fB4), 1, func_020056BC());
    }
}

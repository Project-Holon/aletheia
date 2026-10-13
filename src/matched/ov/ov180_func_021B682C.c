/*
 * function: func_021B682C
 * address:  0x021B682C
 * packet:   pkt_021B682C
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_StartEffect  0x020515B4  arm
 */
#include "../include/Obj24486.h"

extern int PARTICLE_StartEffect(void *p, int b, int c);

void func_021B682C(int *p, int a)
{
    int buf[3] = {0, 0, 0};

    PARTICLE_StartEffect(((struct Obj24486 *)p)->f2C, a, (int)buf);
}

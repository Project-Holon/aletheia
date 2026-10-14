/*
 * function: PALETTE_ANIME_BindImpl
 * address: 0x021C2DE0
 * packet: pkt_ov217_021C2DE0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C408C 0x021C408C data ov217 a1
 */
#include "../include/Obj06721.h"
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern char d_021C408C[];
void PALETTE_ANIME_BindImpl(char *p, unsigned short *dst, unsigned short *src, int count)
{
    int i;
    ((struct Obj06721 *)p)->f4 = 1;
    *(unsigned short * *)&((struct Obj06721 *)p)->f8 = dst;
    ((struct Obj06721 *)p)->f10 = count;
    *(unsigned short * *)&((struct Obj06721 *)p)->fC = func_02030734(((struct Obj06721 *)p)->f0, count * 2, 0, d_021C408C, 728);
    for (i = 0; i < count; i++)
        (*(unsigned short **)(p + 12))[i] = src[i];
}

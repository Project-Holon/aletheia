/*
 * function: func_021BF7F0
 * address: 0x021BF7F0
 * packet: pkt_ov204_021BF7F0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_RestartAnime 0x02016374 thumb
 */
#include "../include/Obj10882.h"
typedef unsigned char u8;
extern void MCSS_RestartAnime(void *);
void func_021BF7F0(u8 *p)
{
    ((struct Obj10882 *)p)->f4=1;
    if(((struct Obj10882 *)p)->f8==1)MCSS_RestartAnime(((struct Obj10882 *)p)->f0);
}

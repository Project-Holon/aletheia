/*
 * function: INTRO_MCSS_Main
 * address: 0x021BF610
 * packet: pkt_ov204_021BF610
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 */
#include "../include/Obj14627.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct McssSys;
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *);
void INTRO_MCSS_Main(u8 *p)
{
    MCSS_Main(*(char * *)&((struct Obj14627 *)p)->f4);
    MCSS_Draw(*(struct McssSys * *)&((struct Obj14627 *)p)->f4);
}

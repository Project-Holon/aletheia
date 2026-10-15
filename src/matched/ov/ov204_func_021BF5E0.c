/*
 * function: INTRO_MCSS_Delete
 * address: 0x021BF5E0
 * packet: pkt_ov204_021BF5E0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14626.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MCSS_Del(void *,void *);
extern void MCSS_Exit(u8 *);
extern u32 func_020307B0(void *p);
void INTRO_MCSS_Delete(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)MCSS_Del(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    MCSS_Exit(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}

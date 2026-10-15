/*
 * function: MUSICAL_MCSS_CreateMon
 * address: 0x021F675C
 * packet: pkt_ov112_021F675C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 */
#include "../include/Obj03759.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 POKE_TOOL_IsShiny(void *);
extern const char d_021F83E4[];
char *MUSICAL_MCSS_CreateMon(void *a,u16 heap)
{
    char *p;
    int i;
    p=func_02030734(heap,124,1,d_021F83E4,141);
    ((struct Obj03759 *)p)->f0=4;
    ((struct Obj03759 *)p)->f4=a;
    ((struct Obj03759 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    ((struct Obj03759 *)p)->f8=POKE_TOOL_GetPartyValue(a,5,0);
    p[10]=POKE_TOOL_GetPartyValue(a,110,0);
    p[11]=POKE_TOOL_GetPartyValue(a,111,0);
    p[12]=POKE_TOOL_IsShiny(a);
    ((struct Obj03759 *)p)->f10=POKE_TOOL_GetPartyValue(a,0,0);
    return p;
}

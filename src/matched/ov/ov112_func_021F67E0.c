/*
 * function: MUSICAL_MCSS_AllocMon
 * address: 0x021F67E0
 * packet: pkt_ov112_021F67E0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F83E4 0x021F83E4 data a4
 */
#include "../include/Obj03247.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021F83E4[];
char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap)
{
    int i;
    char *p;
    int j;
    p=func_02030734(heap,124,1,d_021F83E4,165);
    ((struct Obj03247 *)p)->f0=4; ((struct Obj03247 *)p)->f4=0; ((struct Obj03247 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    for(j=0;j<4;j++) *(u16 *)(p+76+2*j)=0;
    ((struct Obj03247 *)p)->f78=0;
    ((struct Obj03247 *)p)->f8=a; p[10]=b; p[11]=c; p[12]=d; ((struct Obj03247 *)p)->f10=e;
    return p;
}

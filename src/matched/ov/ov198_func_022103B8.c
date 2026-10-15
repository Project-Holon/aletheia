/*
 * function: B_PLIST_MAIN_BeginFadeOut
 * address: 0x022103B8
 * packet: pkt_ov198_022103B8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOwnerFlag18 0x02210EFC thumb ov198
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj14567.h"
#include "../include/Obj25237.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_PLIST_MAIN_GetOwnerFlag18(char **p);
extern int PALANM_RequestFade(void *,u16,u16,short,u8,u8,u16,void *);
int B_PLIST_MAIN_BeginFadeOut(char *p)
{
    if (B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1 && (*(u8 **)p)[0x20]!=6)
        (*(u8 **)p)[0x20]/=2u;
    PALANM_RequestFade(((struct Obj14567 *)p)->f1D8,10,0xffff,0,0,0x10,0,((struct Obj25237 *)(*(char * *)&((struct Obj14567 *)p)->f0))->f28);
    return 0x20;
}

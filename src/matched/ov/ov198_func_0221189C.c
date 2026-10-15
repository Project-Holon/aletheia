/*
 * function: B_PLIST_MAIN_HasSwappable
 * address: 0x0221189C
 * packet: pkt_ov198_0221189C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOwnerFlag18 0x02210EFC thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 */
#include "../include/Obj14570.h"
typedef unsigned char u8;
typedef struct { u8 lo:7; u8 high:1; } Bits;
extern int B_PLIST_MAIN_GetOwnerFlag18(char **p);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
int B_PLIST_MAIN_HasSwappable(u8 *p)
{
    u8 i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) return 0;
    i=(*(u8 **)p)[0x22];
    if(i==1) return 0;
    for(;i<6;i++) {
        u8 *record=p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c;
        if(((struct Obj14570 *)record)->f8!=0 && ((Bits *)(record+0x1b))->high==0 && ((struct Obj14570 *)record)->f14!=0) return 1;
    }
    return 0;
}

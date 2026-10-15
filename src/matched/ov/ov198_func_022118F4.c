/*
 * function: B_PLIST_MAIN_CommitSwap
 * address: 0x022118F4
 * packet: pkt_ov198_022118F4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: associate the index with the destination pointer before adding 0x48.
 * symbols:
 *   B_PLIST_MAIN_GetOwnerFlag18 0x02210EFC thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 */
#include "../include/Obj14571.h"
typedef unsigned char u8;
extern int B_PLIST_MAIN_GetOwnerFlag18(char **p);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
void B_PLIST_MAIN_CommitSwap(u8 *p)
{
    unsigned i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) {
        (*(u8 **)p)[0x48]=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    } else {
        for(i=0;i<3;i++) {
            if(*(unsigned short *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c+0x14)==0) {
                ((*(u8 * *)&((struct Obj14571 *)p)->f0)+i)[0x48]=(*(u8 **)p)[0x20];
                break;
            }
        }
    }
}

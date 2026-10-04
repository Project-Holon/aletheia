/*
 * function: func_021FD964
 * address: 0x021FD964
 * packet: pkt_ov186_021FD964
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj24847.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *,u32);
void func_021FD964(void *unused,int *state,u8 *p)
{
    int i;
    switch(*state) {
    case 0:
        for(i=0;i<12;i++)func_0204B3DC(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),0);
        ((struct Obj24847 *)p)->f22C=1;
        *state=1;
        break;
    case 1:break;
    }
}

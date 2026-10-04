/*
 * function: func_0220FCE0
 * address: 0x0220FCE0
 * packet: pkt_ov198_0220FCE0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_02211958 0x02211958 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 */
#include "../include/Obj10850.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern int func_02025DE8(struct Sound *);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u32);
extern u32 func_02210F1C(u8 *p);
extern u32 func_02211958(u8 **);
extern int func_022110D4(u8 *,int);
int func_0220FCE0(u8 *p)
{
    u32 sel;
    int row;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj10850 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+func_022110D4(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                func_02211970((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 7;
}

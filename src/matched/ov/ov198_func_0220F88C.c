/*
 * function: func_0220F88C
 * address: 0x0220F88C
 * packet: pkt_ov198_0220F88C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02211958 0x02211958 thumb ov198
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_02210E20 0x02210E20 thumb ov198
 *   func_02210ED4 0x02210ED4 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02211844 0x02211844 thumb ov198
 *   func_022118F4 0x022118F4 thumb ov198
 */
#include "../include/Obj03907.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern u32 func_02211958(u8 **);
extern int func_02025DE8(struct Sound *);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u32);
extern int func_02210E20(u8 *);
extern u8 func_02210ED4(u8 *);
extern int func_022110D4(u8 *,int);
extern int func_02211844(u8 *);
extern void func_022118F4(u8 *);
int func_0220F88C(u8 *p)
{
    u32 sel;
    u8 *q;
    if(func_02211958((u8 **)p)==1) return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj03907 *)p)->f2184);
    switch(sel) {
    case 0:
        func_02211970((u8 **)p,1357);
        func_0220B760(p,7);
        if(func_02210E20(p)==1) {
            q=*(u8 * *)&((struct Obj03907 *)p)->f0;
            if(q[31]!=2) {
                (q+q[33])[72]=func_022110D4(p,q[32]);
                return 31;
            }
            if(func_02211844(p)==0) {func_022118F4(p);return 31;}
            ((struct Obj03907 *)p)->f217C=19;return 29;
        }
        ((struct Obj03907 *)p)->f217C=21;return 29;
    case 1:
        if(func_02210ED4(p)==1) break;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,8);
        ((struct Obj03907 *)p)->f217C=13;return 29;
    case 2:
        if(func_02210ED4(p)==1) break;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,10);
        ((struct Obj03907 *)p)->f217C=14;return 29;
    case 3:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 4;
}

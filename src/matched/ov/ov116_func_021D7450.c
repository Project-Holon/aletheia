/*
 * function: func_021D7450
 * address: 0x021D7450
 * packet: pkt_ov116_021D7450
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 * symbols:
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D6EC4 0x021D6EC4 thumb ov116
 *   func_021D6E50 0x021D6E50 thumb ov116
 *   func_021D7060 0x021D7060 thumb ov116
 *   func_021D70B0 0x021D70B0 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 *   func_021D81D0 0x021D81D0 thumb ov116
 *   func_021D81EC 0x021D81EC thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 */
#include "../include/Obj01926.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D8010(void *,u32);
extern int func_021D6EC4(u8 *,u8 *,int);
extern void func_021D6E50(u8 *,u8 *,int,int);
extern void func_021D7060(u8 *,u8 *);
typedef signed int     s32;
struct Blk1AC;
extern int func_021D70B0(void *unused, u8 *p);
extern int func_021D80CC(void *);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void func_021D81D0(u8 *);
extern int func_021D81EC(u8 *);
extern void func_021D81B4(u8 *p);
int func_021D7450(u8 *p,int b)
{
    int v;
    switch (((struct Obj01926 *)p)->fB6C) {
    case 0: func_021D8010(p+4,7); ++((struct Obj01926 *)p)->fB6C; break;
    case 1: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 2:
        v=func_021D6EC4(p+0x1610,p+0x182c,0);
        if(v==1) ((struct Obj01926 *)p)->fB6C=5;
        else if(v==2) ((struct Obj01926 *)p)->fB6C=3;
        break;
    case 3: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 4:
        if(func_021D6EC4(p+0x1610,p+0x182c,1)==1) ((struct Obj01926 *)p)->fB6C=5;
        break;
    case 5: func_021D7060(p+0x1610,p+0x182c); ++((struct Obj01926 *)p)->fB6C; break;
    case 6:
        if(func_021D70B0(p+0x1610,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C;
        break;
    case 7: func_0200DBA0(((struct Obj01926 *)p)->f1858,1,2); func_021D81D0(p); ++((struct Obj01926 *)p)->fB6C; break;
    case 8:
        if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,8); ++((struct Obj01926 *)p)->fB6C; }
        break;
    case 9: if(func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C; break;
    case 10: return 1;
    }
    return 0;
}

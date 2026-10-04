/*
 * function: func_021FD5E4
 * address: 0x021FD5E4
 * packet: pkt_ov132_021FD5E4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * followers: own leaf files 021FD634 and 021FD68C.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../include/Obj10566.h"
#include "../include/Obj23288.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_021FD5E4(char *p,u32 i)
{
    char *q;
    char *s;
    u16 n;
    q=*(char * *)&((struct Obj23288 *)p)->f140;
    n=0x3800;
    s=*(char * *)&((struct Obj10566 *)q)->f10+i*0x3800;
    if((i+1)*0x3800>((struct Obj10566 *)q)->f2C) n=((struct Obj10566 *)q)->f2C%0x3800U;
    return func_0203D3F8((u32)func_0203996C(0xff),0xff,0x1105,n,(u32)s,0,1,1);
}

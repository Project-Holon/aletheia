/*
 * function: func_021FD22C
 * address: 0x021FD22C
 * packet: pkt_ov132_021FD22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173E8 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../include/Obj14127.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020173E8(void);
typedef signed int     s32;
struct Entry;
extern int func_02008468(void);
extern void func_02082D44(void *,void *,u32);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_021FD22C(char *p)
{
    u8 i;
    u32 n;
    u32 m;
    char *q;
    u32 k;
    void *h;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char * *)&((struct Obj14127 *)p)->f13C;
        k=i*(m+4+n);
        m=func_02008468();
        n=func_020173E8();
        func_02082D44(*(void **)(p+i*0x30+0x8c),q+k,m+4+n);
    }
    h=func_0203996C(0xff);
    m=func_02008468();
    n=func_020173E8();
    return func_0203D3F8((u32)h,0xff,0x1102,(m+4+n)*4,(u32)(((struct Obj14127 *)p)->f13C),1,0,1);
}

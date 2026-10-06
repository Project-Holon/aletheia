/*
 * function: func_02210D4C
 * address: 0x02210D4C
 * packet: pkt_ov198_02210D4C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EB4 0x02049EB4 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   d_022121D4 0x022121D4 data a4
 */
#include "../include/Obj25267.h"
#include "../include/Obj25269.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_022121D4[];
extern void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u8);
extern void func_020307B0(void *);
void func_02210D4C(u8 *p,u32 n)
{
    u32 i=0;
    const u32 *table=d_022121D4+n*2;
    u8 *out;
    void *buf;
    for(;i<2;i++) {
        buf=func_02049EB4(100,table[i],1,(u32)(&out),((struct Obj25269 *)(*(u8 * *)&((struct Obj25267 *)p)->f0))->f10);
        func_02041090((u8)(i+6),(u32)(out+12),0,0,32,24);
        func_02041B6C(i+6);
        func_020307B0(buf);
    }
}

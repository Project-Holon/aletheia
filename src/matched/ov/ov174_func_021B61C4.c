/*
 * function: func_021B61C4
 * address: 0x021B61C4
 * packet: pkt_ov174_021B61C4
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B622A..0x021B622C is two zero alignment bytes.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B6824 0x021B6824 thumb ov174
 *   func_021B6D00 0x021B6D00 thumb ov174
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02049238 0x02049238 arm
 *   func_021B6508 0x021B6508 thumb ov174
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00681.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02030EAC(void *);
extern void func_0204B3B4(void *);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(void *);
extern void func_02049238(void *);
extern void func_020307B0(void *);
extern void func_021B6824(u8 *),func_021B6508(u8 *),func_021B6D00(u8 *,void *);
void func_021B61C4(u8 *p)
{
    u8 i;
    func_02030EAC(((struct Obj00681 *)p)->f4);
    func_021B6824(p);
    for(i=0;i<((struct Obj00681 *)p)->f8;i++) if(*(void **)(p+28+i*4)) func_021B6D00(p,*(void **)(p+28+i*4));
    func_0204B3B4(((struct Obj00681 *)p)->f54);
    func_0204ADA4((u32)(((struct Obj00681 *)p)->f44));
    func_0204A8D4((u32)(((struct Obj00681 *)p)->f48));
    func_0204AFD8((u32)(((struct Obj00681 *)p)->f4C));
    func_0204B1CC(((struct Obj00681 *)p)->f50);
    func_02049238(((struct Obj00681 *)p)->f18);
    func_021B6508(p);
    func_020307B0(((struct Obj00681 *)p)->f38);
}

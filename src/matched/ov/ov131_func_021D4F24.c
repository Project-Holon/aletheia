/*
 * function: func_021D4F24
 * address: 0x021D4F24
 * packet: pkt_ov131_021D4F24
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero alignment bytes at 0x021D4FBA.
 * symbols:
 *   func_021D8904 0x021D8904 thumb ov131
 *   func_021D9A04 0x021D9A04 thumb ov131
 *   func_021D7BF0 0x021D7BF0 thumb ov131
 *   func_021D6808 0x021D6808 thumb ov131
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj08143.h"
typedef unsigned char u8;
struct S;
extern void func_021D8904(void *a, struct S *s);
extern void func_021D9A04(void *,void *);
extern void func_021D7BF0(void *a, unsigned char *p);
extern void func_021D6808(void *,void *);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021D4F24(char *p)
{
    u8 i;
    func_021D8904(p,((struct Obj08143 *)p)->f94);
    func_021D9A04(p,((struct Obj08143 *)p)->f90);
    func_021D7BF0(p,((struct Obj08143 *)p)->f8C);
    func_021D6808(p,((struct Obj08143 *)p)->f88);
    for(i=0;i<=11;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x98)));
    for(i=12;i<=24;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x98)));
    for(i=25;i<=37;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x98)));
    for(i=0;i<17;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x130)));
}

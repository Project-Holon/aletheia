/*
 * function: func_021C758C
 * address: 0x021C758C
 * packet: pkt_ov136_021C758C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021C73C8 0x021C73C8 thumb ov136
 * func_021C7420 0x021C7420 thumb ov136
 * func_021C5BE0 0x021C5BE0 thumb ov136
 * func_021C5B40 0x021C5B40 thumb ov136
 * func_021C66B8 0x021C66B8 thumb ov136
 * func_021C5C00 0x021C5C00 thumb ov136
 * func_021C630C 0x021C630C thumb ov136
 * func_021C71A8 0x021C71A8 thumb ov136
 */
#include "../include/Obj00127.h"
#include "../include/Obj23656.h"
#include "../include/Obj23657.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_021C73C8(u8 *p);
extern void func_021C7420(u8 *p);
extern void func_021C5BE0(u8 *p);
extern void func_021C5B40(u8 *p);
extern void func_021C5C00(u8 *p);
extern void func_021C66B8(u8 *p, int i, u32 v);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021C630C(u8 *p, unsigned int i);
extern int func_021C71A8(char *p, int v, int w);
void func_021C758C(u8 *p)
{
    u16 n;
    func_021C73C8(p); func_021C7420(p); func_021C5BE0(p); func_021C5B40(p);
    if(((struct Obj23656 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f2FC<=10) {
        func_021C66B8(((struct Obj00127 *)p)->f8,0,0);
        func_021C66B8(((struct Obj00127 *)p)->f8,1,0);
    }
    n=((struct Obj23657 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f2FE;
    if(((struct Obj00127 *)p)->f1C>n) { ((struct Obj00127 *)p)->f1C=n; p[30]=0; }
    func_021C5C00(p);
    func_0202CC70(**(void ** *)&((struct Obj00127 *)p)->f8,10);
    func_021C630C(p,1);
    func_021C71A8((char *)p,1,18);
}

/*
 * function: func_0217AE20
 * address: 0x0217AE20
 * packet: pkt_ov176_0217AE20
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov67_id 0x43 data
 *   ov177_id 0xB1 data
 *   func_0217AEF4 0x0217AEF4 thumb ov176
 *   func_0217AF2C 0x0217AF2C thumb ov176
 *   func_0217AF50 0x0217AF50 thumb ov176
 *   func_0217B014 0x0217B014 thumb ov176
 *   func_021E8A3C 0x021E8A3C thumb ov177
 */
#include "../include/Obj10694.h"
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern int func_02034AC4(signed int);
extern char ov67_id[],ov177_id[];
extern void func_0217AEF4(int *);
extern void func_0217AF2C(int *);
extern void func_0217AF50(char *);
extern void func_0217B014(void *,int *,char *);
extern int *func_021E8A3C(int a, int b, int c);
int func_0217AE20(void *a,void *b,void *context)
{
    char *p;
    func_0203064C(1,0x4e,0x30200);
    p=func_0203159C(a,0x34,0x4e);
    func_02082BCC(p,0,0x34);
    ((struct Obj10694 *)p)->f28=context;
    ((struct Obj10694 *)p)->f0=0x4e;
    func_02034AC4((int)ov67_id);
    func_02034AC4((int)ov177_id);
    func_0217AEF4((int *)p);
    func_0217AF2C((int *)p);
    func_0217AF50(p);
    ((struct Obj10694 *)p)->f4=func_021E8A3C((int)p,(int)func_0217B014,0x4e);
    return 1;
}

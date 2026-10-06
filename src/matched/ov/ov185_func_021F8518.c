/*
 * function: func_021F8518
 * address: 0x021F8518
 * packet: pkt_ov185_021F8518
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E60 0x021F8E60 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F8F58 0x021F8F58 thumb ov185
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj03337.h"
#include "../include/Obj04583.h"
extern void func_021F8D5C(char *,char *);
extern void func_021F8E60(char *,char *);
extern void func_021F8EE8(char *p, int *a1);
extern void func_021F8F58(char *,char *);
extern void func_021F8FB0(char *,char *);
struct PrintSys;
extern void func_021FD714(void *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_02025588(void *p);
extern void func_0201C4C0(struct PrintSys *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int);
extern char ov112_id[];
int func_021F8518(int obj,int b,char *q,char *p)
{
    int i;
    func_021F8D5C(p,q);
    func_021F8E60(p,q);
    func_021F8EE8(p,(int *)q);
    func_021F8F58(p,q);
    func_021F8FB0(p,q);
    func_021FD714((void *)(((struct Obj03337 *)p)->f24));
    func_021F8F58(p,q);
    func_021FC0C8((char *)(*(int *)&((struct Obj04583 *)q)->fC),6);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+56));
    func_02025588((void *)(((struct Obj03337 *)p)->f28));
    func_0201C4C0((struct PrintSys *)(((struct Obj03337 *)p)->f2C));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}

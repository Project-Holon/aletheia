/*
 * function: func_021DBB3C
 * address: 0x021DBB3C
 * packet: pkt_ov183_021DBB3C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021DD1D4 0x021DD1D4 thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj00050.h"
#include "../include/Obj06598.h"
#include "../include/Obj24541.h"
extern void func_021DCE28(char *,char *);
extern void func_021DCE48(char *,char *);
extern void func_021DD054(char *,char *);
extern void func_021DD0F4(char *,char *);
extern void func_021DD1D4(char *,char *);
typedef unsigned int   u32;
struct PrintSys;
extern void func_020409B4(u32 index);
extern void func_021FD15C(void *,int);
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void BMP_OAM_DeleteSys(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
int func_021DBB3C(int task,int b,char *q,char *p)
{
    int i;
    func_021DCE28(p,q);
    func_021DCE48(p,q);
    func_021DD054(p,q);
    func_021DD0F4(p,q);
    func_021DD1D4(p,q);
    ((struct Obj06598 *)q)->f4=((struct Obj00050 *)p)->fC8;
    func_020409B4(4);
    func_020409B4(1);
    if(((struct Obj00050 *)p)->f18) {
        func_021FD15C(((struct Obj00050 *)p)->f18,((struct Obj24541 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        ((struct Obj00050 *)p)->f18=0;
    }
    for(i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0xc));
    func_021FD714((void *)(((struct Obj00050 *)p)->f8));
    func_0201C4C0(((struct Obj00050 *)p)->f4);
    BMP_OAM_DeleteSys((void *)(((struct Obj00050 *)p)->f0));
    func_020315D4((struct S020315D4 *)task);
    return 1;
}

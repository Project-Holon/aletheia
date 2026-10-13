/*
 * function: func_021F851C
 * address: 0x021F851C
 * packet: pkt_ov184_021F851C
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   func_021F88E0 0x021F88E0 thumb ov184
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj02233.h"
#include "../include/Obj04581.h"
struct PrintSys;
extern void func_021FD714(void *p);
extern void func_021F89D0(int *,char *);
extern void func_021F88E0(char *,char *);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void BMP_OAM_DeleteSys(void *p);
extern void func_0201C4C0(struct PrintSys *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_02034A5C(int);
extern char ov112_id[];
int func_021F851C(int obj,int b,char *q,char *p)
{
    int i;
    func_021FD714((void *)(((struct Obj02233 *)p)->fC));
    func_021F89D0((int *)p,q);
    func_021F88E0(p,q);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x14));
    if (((struct Obj02233 *)p)->f10) {
        func_021FD15C(((struct Obj02233 *)p)->f10,((struct Obj04581 *)q)->fC);
        *(int *)&((struct Obj02233 *)p)->f10=0;
    }
    BMP_OAM_DeleteSys((void *)(((struct Obj02233 *)p)->f1C));
    func_0201C4C0((struct PrintSys *)(((struct Obj02233 *)p)->f20));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}

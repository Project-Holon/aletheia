/*
 * unit:     no
 * function: NNSi_G2dRefreshCellAnimation
 * address:  0x0206419C
 * packet:   pkt_02064178
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNSi_G2dRequestCellTransferState  0x02066ABC  arm
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 */
#include "../include/Obj00260.h"
#include "../include/Obj03025.h"
#include "../include/Obj16427.h"
#include "../include/Obj16428.h"
struct CellAnim;
extern void *func_02062D40(struct CellAnim *anim);
typedef unsigned int   u32;
struct CellDataBank;
extern void *func_0206285C(struct CellDataBank *bank, u32 idx);
struct O02064140;
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
extern void func_020640DC(char *p, int a, int b);
extern void func_02064120(char *p, int a, int b);
typedef unsigned short u16;
struct Obj02064100;
extern void func_02064100(struct Obj02064100 *obj, u16 val);
extern int NNSi_G2dRequestCellTransferState(int a0, int a1, int a2);

void NNSi_G2dRefreshCellAnimation(char *self)
{
    char *p;
    char *o;
    int kind;
    int q;
    int r;
    int r2;
    if (*(unsigned short *)(*(int *)&((struct Obj00260 *)self)->f4 + 4) == 0)
        return;
    func_02062D40((struct CellAnim *)self);
    p = func_02062D40((struct CellAnim *)self);
    o = *(char * *)&((struct Obj00260 *)self)->f34;
    ((struct Obj00260 *)self)->f30 = (int)func_0206285C((struct CellDataBank *)o, ((struct Obj03025 *)p)->f0);
    kind = *(int *)(*(int *)&((struct Obj00260 *)self)->f1C + 4) & 0xff;
    NNSi_G2dSrtcInitControl((struct O02064140 *)(self + 0x3c), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x3c, *(short *)&((struct Obj03025 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x3c, ((struct Obj03025 *)p)->f4, ((struct Obj03025 *)p)->f8);
        func_02064100((struct Obj02064100 *)(self + 0x3c), ((struct Obj03025 *)p)->f2);
        func_020640DC(self + 0x3c, ((struct Obj03025 *)p)->fC, ((struct Obj03025 *)p)->fE);
        break;
    }
    q = ((struct Obj16427 *)o)->fC;
    r = !!q;
    if (r == 0) return;
    if (*(volatile int *)&((struct Obj00260 *)self)->f38 != -1) r2 = 1; else r2 = 0;
    if (r2 == 0) return;
    {
        int *t = (int *)(((struct Obj16428 *)q)->f4 + ((struct Obj03025 *)p)->f0 * 8);
        NNSi_G2dRequestCellTransferState(((struct Obj00260 *)self)->f38, t[0], t[1]);
    }
}

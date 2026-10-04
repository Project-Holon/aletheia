/*
 * function: func_021D6854
 * address:  0x021D6854
 * packet:   pkt_ov175_021D6854
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC                0x020362DC  arm
 *   func_021E8738                0x021E8738  thumb  ov177
 *   func_021E8844                0x021E8844  thumb  ov177
 *   func_021D6550                0x021D6550  thumb
 *   func_021D65DC                0x021D65DC  thumb
 *   func_021D65C8                0x021D65C8  thumb
 *   func_021DA434                0x021DA434  thumb
 *   func_021E7E0C                0x021E7E0C  thumb  ov177
 *   func_021DA36C                0x021DA36C  thumb
 *   func_0200FB24                0x0200FB24  thumb
 *   func_0203CD98                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 */
#include "../include/Obj00171.h"

typedef unsigned long u32;

extern u32 func_020362DC(void);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *p);
extern void func_021D6550(u32 *obj, int kind);
extern int func_021D65DC(char *obj);
extern void func_021D65C8(char *obj);
extern int func_021DA434(u32 h);
extern void func_021E7E0C(void **p, int on);
extern void func_021DA36C(u32 h);
extern u32 func_0200FB24(void);
extern int func_0203CD98(void);
extern void DWC_CloseAllConnectionsHard(void);

int func_021D6854(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00171 *)obj)->fE4) {
    case 0:
        if (trigger != 0 && (func_020362DC() & 2))
            ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        else return 0;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x23, 1);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00171 *)obj)->f24)))
            break;
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 3:
        func_021D6550((u32 *)obj, 0);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 4:
        r = func_021D65DC(obj);
        if (r == -1)
            break;
        func_021D65C8(obj);
        switch (r) {
        case 0:
            ((struct Obj00171 *)obj)->fE4 = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x21, 0);
            ((struct Obj00171 *)obj)->fE4 = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x2b, 2);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00171 *)obj)->f30);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        func_021E7E0C((void **)(((struct Obj00171 *)obj)->f20), 0);
        func_021DA36C(((struct Obj00171 *)obj)->f30);
        if (!func_0200FB24() && func_0203CD98())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00171 *)obj)->fE4 = 0;
        return 3;
    }
    return 1;
}

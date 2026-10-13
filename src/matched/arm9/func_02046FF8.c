/*
 * function: func_02046FF8
 * address:  0x02046FF8
 * packet:   pkt_02046FF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964  0x0206E964  arm
 *   G3D_SYSTEM_AllocTexVramKeys  0x02047260  arm
 *   G3D_SYSTEM_AllocPlttVramKey  0x020472F8  arm
 *   func_02069FF8  0x02069FF8  arm
 *   NNS_G3dPlttSetPlttKey  0x0206A124  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0206A00C  0x0206A00C  arm
 *   NNS_G3dPlttLoad  0x0206A12C  arm
 *
 * First guard exits through the shared epilogue at the end of the function
 * (a plain `return 0` there is if-converted and loses the branch).
 */
#include "../include/Obj04802.h"

typedef unsigned int   u32;
struct Up;
extern unsigned char *func_0206E964(unsigned char *p);
struct Layer;
extern int G3D_SYSTEM_AllocTexVramKeys(u32 a0, u32 *a1, u32 *a2);
extern int G3D_SYSTEM_AllocPlttVramKey(struct Layer *layer, u32 *out);
extern void func_02069FF8(char *p, int a, int b);
extern void NNS_G3dPlttSetPlttKey(int *p, int v);
extern void func_020862F0(int a, int b);
extern void func_0206A00C(struct Up *u, u32 wrap);
extern void NNS_G3dPlttLoad(int a, int b);

int func_02046FF8(int *self)
{
    int v8;
    int v4;
    int v0;
    int h;
    int p;

    h = self[1];
    p = (int)func_0206E964((unsigned char *)h);
    if (p == 0)
        goto fail;
    if (G3D_SYSTEM_AllocTexVramKeys(p, (u32 *)(&v8), (u32 *)(&v4)) == 0)
        return 0;
    if (G3D_SYSTEM_AllocPlttVramKey((struct Layer *)p, (u32 *)(&v0)) == 0)
        return 0;
    func_02069FF8((char *)p, v8, v4);
    NNS_G3dPlttSetPlttKey((int *)p, v0);
    func_020862F0(h, *(int *)&((struct Obj04802 *)h)->f8);
    func_0206A00C((struct Up *)p, 1);
    NNS_G3dPlttLoad(p, 1);
    return 1;
fail:
    return 0;
}

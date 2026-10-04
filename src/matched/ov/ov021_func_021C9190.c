/*
 * function: func_021C9190
 * address:  0x021C9190
 * packet:   pkt_ov021_021C9190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02730.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct V3 { int v[3]; } V3;

extern int func_0216DA30(int);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_021AC1CC(u32, V3 *);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);

void func_021C9190(u32 a, u8 *b)
{
    V3 v;

    if (func_0216DA30(((struct Obj02730 *)b)->f10) != 0) {
        func_0216D88C((const struct Actor *)((struct Obj02730 *)b)->f10, (struct VecFx32 *)&v);
        *(V3 *)(b + 0x28) = v;
        func_021AC1CC(a, &v);
        ((struct Obj02730 *)b)->f2C -= 0x4000;
        ((struct Obj02730 *)b)->f30 += 0x2800;
        if (b[0x14] == 0) {
            func_02047910((void *)(((struct Obj02730 *)b)->f18), 0, 0x1000);
        }
        if (b[0x15] == 1 && b[0x16] == 0) {
            if (func_020478B8((void *)(((struct Obj02730 *)b)->f18), 1, 0x1000) == 0) {
                b[0x16] = 1;
            }
        }
    }
}

/*
 * function: func_021F3CC4
 * address:  0x021F3CC4
 * packet:   pkt_ov056_021F3CC4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216DC18  0x0216DC18  thumb  ov010
 */
#include "../include/Obj01881.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

struct Actor;
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern int func_02164010(int a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern void func_0216DC18(void *m, u32 v);

void func_021F3CC4(u8 *p, int flag)
{
    VecFx32 v;

    if (flag) {
        ((struct Obj01881 *)p)->f5C = 1;
        func_0216DAC8(((struct Obj01881 *)p)->f68, 1);
        return;
    }
    ((struct Obj01881 *)p)->f5C = 0;
    func_0216DAC8(((struct Obj01881 *)p)->f68, 0);
    func_0216E084(((struct Obj01881 *)p)->f68, (s16)(((struct Obj01881 *)p)->f6C), (s16)(((struct Obj01881 *)p)->f70),
                  (s16)(((struct Obj01881 *)p)->f74), ((struct Obj01881 *)p)->f78);
    func_02164010((int)(((struct Obj01881 *)p)->f68));
    func_0216D88C(((struct Obj01881 *)p)->f68, &v);
    func_021A3044(((struct Obj01881 *)p)->f64, &v);
    func_0216DC18(((struct Obj01881 *)p)->f68, 0);
}

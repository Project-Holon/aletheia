/*
 * function: func_021BA73C
 * address:  0x021BA73C
 * packet:   pkt_ov093_021BA73C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021CD95C takes two arguments (its own file: `p->v = v`), and the
 * value passed second is the func_021E8F20 result just stored at p + 4:
 * that is the `adds r1, r0, #0` the one-argument prototype could not
 * produce (twin: ov093_func_021B835C).
 *
 * symbols:
 *   func_021B6818  0x021B6818  thumb  ov093
 *   func_021D787C  0x021D787C  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021B9424  0x021B9424  thumb  ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B9460  0x021B9460  thumb  ov093
 *   func_021CD984  0x021CD984  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021E8E28  0x021E8E28  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021BAB40  0x021BAB40  thumb  ov093
 */
#include "../include/Obj02131.h"
#include "../include/Obj21020.h"
#include "../include/Obj21021.h"

typedef unsigned char u8;

extern int func_021B6818(int *);
extern void func_021D787C(void *);
extern void func_021B68D8(void *, void *);
typedef unsigned int   u32;
struct QA;
extern void func_021B9424(char *p);
extern int func_021B8B9C(void *, u8);
extern void func_021B9460(void *, void *, u8);
extern void func_021CD984(void *, int);
typedef unsigned short u16;
struct Scene;
extern void func_021E9034(char *p);
extern void func_021E8E28(void *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021BAB40(char *p);

void func_021BA73C(char *p, int x)
{
    unsigned int i;
    int t;

    t = func_021B6818(*(int * *)&((struct Obj02131 *)p)->f0);
    func_021D787C(p + 0x3f0);
    func_021B68D8(p, ((struct Obj02131 *)p)->f0);
    func_021B9424(p + 0xc8);
    func_021B9424(p + 0x1b0);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            func_021B9460(p + 0x1b0, p, i);
            func_021B9460(p + 0xc8, p, i);
            func_021CD984(*(void **)(p + i * 4 + 0x10), x);
        }
    }
    func_021E9034((char *)(((struct Obj02131 *)p)->f4));
    func_021E8E28((void *)0x13);
    ((struct Obj02131 *)p)->f4 = (int)func_021E8F20(p, *(void **)(p + (((struct Obj21020 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), (u32)(p + 0xc8), t, 0x13);
    func_021CD95C(*(void **)(p + (((struct Obj21021 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), ((struct Obj02131 *)p)->f4);
    func_021BAB40((char *)(((struct Obj02131 *)p)->f8));
}

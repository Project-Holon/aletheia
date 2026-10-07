/*
 * file:     weather_task_p63.c
 * unit:     yes
 * function: func_021A5630, func_021A569C, func_021A56C0, func_021A56F4
 * address:  0x021A5630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3920  0x021A3920  thumb  ov021
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021A55DC  0x021A55DC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D8A24  0x021D8A24  data  a2
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021A5378  0x021A5378  thumb  ov021
 *   func_021A39AC  0x021A39AC  thumb  ov021
 */
#include "../../matched/include/Obj09571.h"
#include "../../matched/include/Obj12739.h"
#include "../../matched/include/Obj18049.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_021A3920(u8 *p);
extern int func_021A5788(u32, u32, u32 *);
extern u16 func_021AB0F0(u32 attr);
extern int func_021A55DC(int a);
extern int func_021AB11C(u32);
int func_021A5264(u8 *a, void *b, unsigned int c, int *d);
void *func_021A3960(unsigned char *p);
void func_0216D88C(const struct Actor *h, struct VecFx32 *v);
void func_02163E58(void *h, Vec021A56C0 *v, int *lim);
extern u32 func_021A39AC(u32, u32);
extern void func_021A5378(u32 *p, int on);
u32 func_021A5630(u32 a);
int func_021A569C(u8 *a, void *b, int c, int *d);
u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3);
int func_021A56F4(u32 a);
extern const u16 d_021D8A24[4];


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A5630(u32 a)
{
    u32 v;
    u16 t[4];
    u16 i;
    u32 x;
    u16 *p = t;
    t[0] = d_021D8A24[0];
    t[1] = d_021D8A24[1];
    t[2] = d_021D8A24[2];
    t[3] = d_021D8A24[3];
    x = func_021A3920((u8 *)(*(u32 *)&((struct Obj09571 *)a)->fC));
    i = 0;
    do {
        if (func_021A5788(a, x, &v) == 1) {
            if (func_021A55DC(func_021AB0F0(v)) == 0) {
                if (func_021AB11C(v) == 0) {
                    return x;
                }
            }
        }
        i = i + 1;
        x = p[x];
    } while (i < 4);
    return 9;
}


int func_021A569C(u8 *a, void *b, int c, int *d)
{
    int r = func_021A5264(a, b, c, d);

    if (func_021A55DC(func_021AB0F0(*d)) == 1)
        r |= 0x100;
    return r;
}


u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj12739 *)p)->fC);
    Vec021A56C0 v;
    int lim;

    func_0216D88C(h, (struct VecFx32 *)&v);
    func_02163E58(h, &v, &lim);
    if (v.y <= lim)
        return 1;
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A56F4(u32 a)
{
func_021A5378((u32 *)a, 1);
return func_021A39AC(((struct Obj18049 *)((u8 *)(a)))->fC, 7);
}

/*
 * file:     weather_task_p65.c
 * unit:     yes
 * function: func_021A5788, func_021A57C0, func_021A5810
 * address:  0x021A5788
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
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 */
#include "../../matched/include/Obj09571.h"
#include "../../matched/include/Obj00262.h"

struct VecFx32;
struct Actor;
struct BigObj;
struct Ctx;
struct Q;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A5788;

typedef unsigned char u8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef unsigned short u16;

void func_021A3898(unsigned char *p, struct VecFx32 *out);
void func_02164208(int dir, int *p, int amt);
void *func_021A3960(unsigned char *p);
void func_02163E34(void *h, Vec021A5788 *v, int *out);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int  func_02163E58(u8 *a, Vec3 *p, int *out);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162564(char *p, struct Q *q);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626B8(char *a0, int a1);
void func_021A5788(u32 *p, int k, int *out);
int func_021A57C0(u8 *p, int dir);
int func_021A5810(u8 *p, int dir);


void func_021A5788(u32 *p, int k, int *out)
{
    Vec021A5788 v;

    func_021A3898(*(unsigned char * *)&((struct Obj09571 *)p)->fC, (struct VecFx32 *)&v);
    if (k != 9)
        func_02164208(k, (int *)(&v), 0x10000);
    func_02163E34(func_021A3960(*(unsigned char * *)&((struct Obj09571 *)p)->fC), &v, out);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021A57C0(u8 *p, int dir)
{
    u8 *a;
    int y;
    Vec3 pos;
    int lim;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    y = pos.y;
    func_02164208(dir, (int *)(&pos), 0x10000);
    if (func_02163E58(a, &pos, &lim) == 1) {
        if (y < lim) {
            return 1;
        }
        if (y > lim) {
            return 2;
        }
    }
    return 0;
}


int func_021A5810(u8 *p, int dir)
{
    u8 *a;
    int h;
    int i;
    Vec3 pos;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    h = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj00262 *)p)->f10)));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    func_02164208(dir, (int *)(&pos), 0x10000);
    i = func_02162564((char *)h, (struct Q *)(&pos));
    if (i == 0xffff) {
        return 0;
    }
    if (func_021626B8(func_021625CC((char *)h, (u16)i), dir)) {
        return 1;
    }
    return 0;
}

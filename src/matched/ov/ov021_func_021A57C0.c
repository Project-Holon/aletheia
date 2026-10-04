/*
 * function: func_021A57C0
 * address:  0x021A57C0
 * packet:   pkt_ov021_021A57C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char u8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern void *func_021A3960(u8 *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_02164208(int dir, Vec3 *p, int amt);
extern int  func_02163E58(u8 *a, Vec3 *p, int *out);

int func_021A57C0(u8 *p, int dir)
{
    u8 *a;
    int y;
    Vec3 pos;
    int lim;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    y = pos.y;
    func_02164208(dir, &pos, 0x10000);
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

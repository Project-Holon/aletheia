/*
 * function: func_021A56C0
 * address:  0x021A56C0
 * packet:   pkt_ov021_021A56C0
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
 *   func_02163E58  0x02163E58  thumb  ov010
 */
#include "../include/Obj12739.h"

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

void *func_021A3960(unsigned char *p);
struct Actor;
struct VecFx32;
void func_0216D88C(const struct Actor *h, struct VecFx32 *v);
void func_02163E58(void *h, Vec021A56C0 *v, int *lim);

int func_021A56C0(u32 *p)
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

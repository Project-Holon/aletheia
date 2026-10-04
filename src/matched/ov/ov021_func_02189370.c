/*
 * function: func_02189370
 * address:  0x02189370
 * packet:   pkt_ov021_02189370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012974  0x02012974  thumb
 *   func_020141E0  0x020141E0  thumb
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 */
#include "../include/Obj05698.h"
#include "../include/Obj19497.h"

typedef struct Vec { int x, y, z; } Vec;

typedef unsigned int   u32;
struct BigObj;
extern u32 func_02012974(const struct BigObj *p);
extern void func_020141E0(void *a, Vec *v);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);

int func_02189370(char *p)
{
    Vec v;
    char *q;
    void *m;
    int r;

    q = p + 0xd4;
    m = (void *)func_02012974(((struct Obj19497 *)p)->f8);
    func_020141E0(q, &v);
    if (func_02159C48((int)m, v.x, v.z) == 1) {
        r = func_02159BD4((int)m, v.x, v.z);
        if (r != 0xFFFF && r != ((struct Obj05698 *)q)->f4)
            return 1;
    }
    return 0;
}

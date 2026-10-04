/*
 * function: func_021DD2A8
 * address: 0x021DD2A8
 * packet: pkt_ov119_021DD2A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02007984 0x02007984 thumb
 *   func_021DD21C 0x021DD21C thumb ov119
 */
#include "../include/Obj13896.h"
extern int func_0201293C(int);
typedef unsigned int   u32;
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern int func_02007984(void *save);
extern int func_021DD21C(char *p);
int func_021DD2A8(char *p)
{
    int a, b, n;
    a = func_0201293C(*(int *)&((struct Obj13896 *)p)->f82C);
    b = func_021DD21C(p);
    n = func_0201AA18(func_02012934(((struct Obj13896 *)p)->f82C));
    n += func_02007984((void *)a);
    if (n == 2 && b >= 1) return 1;
    if (n > 2 && b >= 2) return 1;
    return 0;
}

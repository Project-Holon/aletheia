/*
 * function: func_021E4984
 * address: 0x021E4984
 * packet: pkt_ov119_021E4984
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 */
#include "../include/Obj00001.h"
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
int func_021E4984(int v, int a, int b, char *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        m = func_021D8B0C(a, b);
        *out = 0;
        return (int)func_021D8DD0((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (int)func_021D8DD0((void *)v, ((struct Obj00001 *)p)->f630, a + b * 2, p);
    }
    return 0;
}

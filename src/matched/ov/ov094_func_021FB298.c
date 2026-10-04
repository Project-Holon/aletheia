/*
 * function: func_021FB298
 * address:  0x021FB298
 * packet:   pkt_ov094_021FB298
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: runs func_021F7F04 on each id listed by func_021FCA04.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FCA04 0x021FCA04 thumb ov094
 *   func_021F7F04 0x021F7F04 thumb ov094
 */
#include "../include/Obj00177.h"
extern int func_0201134C(void *);
extern int func_021FCA04(char *, int, int *);
extern void func_021F7F04(int);

int func_021FB298(void *a, char *s)
{
    int ids[8];
    int n;
    int i;

    n = func_021FCA04(s, func_0201134C(a), ids);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021F7F04(ids[i]);
    }
    return ((struct Obj00177 *)s)->f23C;
}

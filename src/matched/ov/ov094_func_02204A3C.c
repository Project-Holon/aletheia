/*
 * function: func_02204A3C
 * address:  0x02204A3C
 * packet:   pkt_ov094_02204A3C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022023D0  0x022023D0  thumb  ov094
 *   func_02021ED8  0x02021ED8  thumb
 *   func_0220687C  0x0220687C  thumb  ov094
 */
#include "../include/Obj21770.h"
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
typedef unsigned int   u32;
extern u32 func_02021ED8(const char *ptr);
extern int func_0204E804(void);
extern void func_022023D0(char *p);
extern void func_0220687C(char *p, void *q);

void func_02204A3C(void *a, char **s)
{
    if (func_02021ED8(((struct Obj21770 *)(*s))->f64) != 0)
        return;
    if (func_0204E804() != 0)
        return;
    if (((Bits *)(*s + 0x68))->mode == 1)
        func_022023D0(*s);
    func_0220687C(*s, a);
}

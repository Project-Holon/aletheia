/*
 * function: func_021BD3FC
 * address: 0x021BD3FC
 * packet: pkt_ov209_021BD3FC
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD43E..021BD440 is two zero alignment bytes before matched D440.
 * lever: first types search hoisted the initialized full-word ps load before entry arithmetic.
 * checks: 1 own C4E4, C6C4, 45770, 45334 bodies prove 1/2/1/1 arity; 2 ov0679344 and ov208C0740 confirm full-word handles; 3 carried two compiles exhausted; 4 carried two order/extraction probes exhausted; 5 fresh idioms/neighbours read, no stack object. Wave32 I4 pointer ps unchanged5; types search9 candidates exact after ps hoist, all inputs and call/store order preserved.
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj08409.h"
struct PrintSys;
struct Descriptor;
extern unsigned func_0201C4E4(struct PrintSys *);
typedef unsigned int   u32;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
struct Context { char pad[72]; int ps; };
void func_021BD3FC(const struct Context *p)
{
    int ps;
    long i;
    char *entry;
    func_0201C4E4((struct PrintSys *)p->ps);
    for (i = 0; i < 3u; i++) {
        ps = p->ps;
        entry = (char *)p + i * 8;
        if (((struct Obj08409 *)entry)->f24) {
            if (func_0201C6C4((struct PrintSys *)ps, func_02045770(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20)) == 0) {
                func_02045334(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20);
                ((struct Obj08409 *)entry)->f24 = 0;
            }
        }
    }
}

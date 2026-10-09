/*
 * file:     net_state_p37.c
 * unit:     yes
 * function: func_0203D10C, func_0203D12C
 * address:  0x0203D10C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02037A44  0x02037A44  arm
 */
#include "../../matched/include/Obj15980.h"

extern int func_0203CD98(void);
extern void func_02037A44(int a);
int func_0203D10C(int a0);
void func_0203D12C(int a);


int func_0203D10C(int a0){ int t0 = func_0203D788(); int t1 = func_0203BA98((int)((struct Obj15980 *)((char *)(t0)))->f56, (int)a0, (int)0); return t1; }


/*
 * EXACT*, not EXACT: the inferred extent runs on to 0x0203D17C because the
 * four eight-byte ARM long-branch veneers at 0x0203D14C, 0x0203D158,
 * 0x0203D164 and 0x0203D170 save no `lr` and so carry no label.  It is not a
 * byte difference.  They want seeding into layout/function_starts.txt, which
 * is the integrator's file.
 *
 * Guarded forwarding call: the hook at 0x0203CD98 answers whether the
 * connection is up, and only then is the argument handed to 0x02037A44.  The
 * `bl` at the top passes r0 through untouched, so the callee is declared
 * `void` while this one takes the value it later forwards.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D12C.c \
 *       --func func_0203D12C --addr 0x0203D12C --cc 1.1p1 --arm
 */
void func_0203D12C(int a)
{
    if (func_0203CD98() == 0)
        return;

    func_02037A44(a);
}

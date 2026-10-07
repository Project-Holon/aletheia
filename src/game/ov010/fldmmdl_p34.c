/*
 * file:     fldmmdl_p34.c
 * unit:     yes
 * function: func_0216E174, func_0216E180, func_0216E190, func_0216E1A4, func_0216E1C4
 * address:  0x0216E174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D568 0x0216D568 thumb ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */
#include "../../matched/include/Obj09167.h"
#include "../../matched/include/Obj09168.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern char *func_0216D570(char *p, u32 v);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0216D568(void *p, u32 v);
extern u16 func_0216D588(void *p);
extern u16 func_0216D598(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D55C(int a0, int a1);
void func_0216E174(void *a0);
void func_0216E180(void *a0);
void func_0216E190(void *a);
int func_0216E1A4(int a0, int a1);
int func_0216E1C4(int a0, int a1);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E174.c \
 *       --func func_0216E174 --addr 0x0216E174 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216E174(void *a0)
{

    func_0216D570(a0, 442368);
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E180.c \
 *       --func func_0216E180 --addr 0x0216E180 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216E180(void *a0)
{

    func_02082BCC(a0, 0, 256);
}

void func_0216E190(void *a) { func_0216D568(a, 0x20); func_0216E174(a); }


int func_0216E1A4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1AE:
((struct Obj09167 *)((char *)t4))->f0 = a0;
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1B6:
((struct Obj09167 *)t4)->f2 = a0;
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1BE:
((struct Obj09167 *)t4)->f4 = a0;
    return a0;}


int func_0216E1C4(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 1;
t5 = a0 + 0;
t6 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216E1D2:
    if (a0 == 0) goto loc_0216E1FE;
loc_0216E1D6:
a0 = t5 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1DC:
a1 = ((struct Obj09168 *)((char *)t4))->f0;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1E2:
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1E8:
a1 = ((struct Obj09168 *)t4)->f2;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1EE:
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1F4:
a1 = ((struct Obj09168 *)t4)->f4;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1FA:
a0 = t6 + 0;
    return a0;
loc_0216E1FE:
a0 = 0;
    return a0;}

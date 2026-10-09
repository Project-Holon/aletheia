/*
 * file:     net_state_p38.c
 * unit:     yes
 * function: func_0203D17C, func_0203D1A4, func_0203D1B4, func_0203D1C0
 * address:  0x0203D17C
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
 *   func_0203D788  0x0203D788  arm
 *   func_020395EC  0x020395EC  arm
 *   func_020399EC  0x020399EC  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 */
#include "../../matched/include/Obj15981.h"
#include "../../matched/include/Obj15982.h"

struct Link;
struct Entry;
struct NetEntry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*Fn)(u32);

typedef signed int     s32;

extern void *func_0203D788(void);
extern int func_020395EC(struct Entry *a);
extern int func_020399EC(void);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399B8(u8 *p);
void func_0203D17C(u32 a);
int func_0203D1B4(void);
u32 func_0203D1C0(u32 index);



/*
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/func_0203CF10.c and
 * src/matched/func_0203CF3C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D17C.c \
 *       --func func_0203D17C --addr 0x0203D17C --cc 1.1p1 --arm
 */
void func_0203D17C(u32 a)
{
    u8  *p;
    u32 *vt;
    Fn   f;

    p = func_0203D788();
    vt = *(u32 * *)&((struct Obj15981 *)p)->f340;
    if (vt == 0)
        return;
    f = *(Fn *)&((struct Obj15982 *)vt)->fC4;
    f(a);
}



/*
 * Forward to func_020395EC and mask the result to a byte.  func_020395EC is
 * called from func_0203D578 (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1A4.c \
 *       --func func_0203D1A4 --addr 0x0203D1A4 --cc 1.1p1 --arm
 */
u32 func_0203D1A4(struct Link *p)
{
    return func_020395EC((struct Entry *)p) & 0xff;
}


int func_0203D1B4(void)
{
    return func_020399EC();
}


/*
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with func_0203996C and ask func_020399B8 about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1C0.c \
 *       --func func_0203D1C0 --addr 0x0203D1C0 --cc 1.1p1 --arm
 */
u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}

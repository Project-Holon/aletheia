/*
 * file:     net_state_p06.c
 * unit:     yes
 * function: func_0203660C, func_02036624, func_02036640, func_0203666C, func_02036670, func_020366A8, func_020366C0, func_020366FC, func_02036738
 * address:  0x0203660C
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
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj01465.h"
#include "../../matched/include/Obj15900.h"
#include "../../matched/include/Obj05731.h"
#include "../../matched/include/Obj15901.h"
#include "../../matched/include/Obj15902.h"
#include "../../matched/include/Obj11347.h"
#include "../../matched/include/Obj15903.h"
#include "../../matched/include/Obj11348.h"
#include "../../matched/include/Obj05732.h"

struct Conn;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

int func_020366C0(char *p);
int func_0203660C(int a0, int a1, int a2, int a3);
int func_02036624(void *p, int v);
int func_02036640(char *p);
void func_0203666C(void);
u8 *func_02036670(u32 *p);
u32 func_020366FC(u32 *p);
void func_02036738(char *q, int v);


int func_0203660C(int a0, int a1, int a2, int a3){ int t0 = func_020365E8((int)a0); return (*(int *)&((struct Obj01465 *)((char *)(a0)))->f4 - t0); }



int func_02036624(void *p, int v)
{
    return v % ((struct Obj15900 *)p)->f4;
}



static inline int RingUsed(char *p)
{
    int a = ((struct Obj05731 *)p)->fC;
    if (a > ((struct Obj05731 *)p)->fE)
        return ((struct Obj05731 *)p)->f4 + *(volatile short *)&((struct Obj05731 *)p)->fE - a;
    return *(volatile short *)&((struct Obj05731 *)p)->fE - a;
}



/*
 * Free space of a net_ring_buff.c ring: capacity (+4) minus the used count.
 * The used count is the body of the matched sibling func_020365E8 inlined
 * verbatim (its two volatile re-reads of the +0xE cursor are what keep the
 * per-arm reloads the earlier DIFF note could not reproduce).
 */
int func_02036640(char *p)
{
    return ((struct Obj15901 *)p)->f4 - RingUsed(p);
}


void func_0203666C(void){ }



/*
 * Finds the first of `p->unk1C` records (stride 0x14) whose halfword at +0x0E
 * is zero and returns a pointer to it, or NULL when the count is not positive
 * or no record matches.  The found case is a bare `bxeq lr` with the moving
 * pointer still in r0, which is what makes the return type a pointer rather
 * than a boolean: the function returns the record it found, not 1.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036670.c \
 *       --func func_02036670 --addr 0x02036670 --cc 1.1p1 --arm
 */
u8 *func_02036670(u32 *p)
{
    u8  *q;
    s32  i;
    s32  n;

    q = (u8 *)p[6];
    n = (s32)p[7];
    for (i = 0; i < n; i++) {
        if (((struct Obj15902 *)q)->fE == 0)
            return q;
        q += 0x14;
    }
    return 0;
}



int func_020366A8(struct Conn *p)
{
    return func_020366C0((char *)p) == 0;
}


/*
 * Counts the 20-byte records of the array at p+0x18 whose halfword at +0x0E is
 * non-zero, up to the count in p+0x1C.  60 bytes, no calls, no pool: the loop
 * is rotated and the test is a predicated `addne`.
 *
 * The declaration order is the whole lever.  Declared `e, i, c, n` the four
 * locals land in r1, r2, r3 and ip exactly as the image has them: the cursor
 * first, then the index, then the counter (whose `mov r3, #0` then feeds
 * `mov r2, r3` for the index), and the bound last in ip, so the bound's load
 * is the one that survives to just before the `ble`.  With the bound declared
 * first - how this file previously stood - the bound takes r2, the cursor r3
 * and the counter ends up in r0, which frees the `mov r0, r3` before the
 * return and shortens the body to 56 bytes (DIFF).  A param pointer (`u32 *p`
 * plus `q = (u8 *)p[6]`) does not reach it either: the four locals colour the
 * same way whatever the order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm
 */
int func_020366C0(char *p)
{
    const char *e = *(char * *)&((struct Obj11347 *)p)->f18;
    int         i;
    int         c = 0;
    int         n = ((struct Obj11347 *)p)->f1C;

    for (i = 0; i < n; i++, e += 0x14) {
        if (((struct Obj15903 *)e)->fE != 0)
            c++;
    }
    return c;
}


/*
 * Pops one entry off a singly linked list held at p[0], one link at a time:
 * the successor is p[0]->unk8; when it exists it becomes the new head and its
 * own back pointer at +4 is cleared, otherwise the head and the word after it
 * are both zeroed.  Returns 0 only when the list was already empty.
 *
 * Every arm is conditional-executed, so the function has exactly one `bx lr`
 * per exit and both `strne`/`streq` groups sit on the same `cmp`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366FC.c \
 *       --func func_020366FC --addr 0x020366FC --cc 1.1p1 --arm
 */
u32 func_020366FC(u32 *p)
{
    u32 v;

    v = p[0];
    if (v != 0) {
        v = ((struct Obj11348 *)v)->f8;
        if (v != 0) {
            p[0] = v;
            ((struct Obj11348 *)v)->f4 = 0;
        } else {
            p[0] = 0;
            p[1] = 0;
        }
        return 1;
    }
    return 0;
}


void func_02036738(char *q, int v)
{
    *(char *)*(char * *)&((struct Obj05732 *)q)->f0 = (char)v;
    *(char * *)&((struct Obj05732 *)q)->f0 = *(char * *)&((struct Obj05732 *)q)->f0 + 1;
    ((struct Obj05732 *)q)->f4 = ((struct Obj05732 *)q)->f4 - 1;
}

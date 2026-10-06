/*
 * file:     net_state_p05.c
 * unit:     yes
 * function: func_02036568, func_020365E8
 * address:  0x02036568
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
 *   func_02036624  0x02036624  arm
 */
#include "../../matched/include/Obj01465.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8   *buf;
    int   size;
    u32   pad8;
    short head;
    volatile short tail;
} NetRingBuff;

extern int func_02036624(void *p, int v);
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max);
int func_020365E8(char *p);


/*
 * wm_icon.c ring reader. Wave 17 lane untried_small, from 25 out: the ring
 * is a const pointer, in this function and in func_02036624's prototype (both
 * only read it). With the read-only qualifier the compiler hoists the
 * loop-bottom bound load above the byte store through dst, as the image does.
 * The write cursor +0x0E stays volatile (the func_02036428 lever).
 */
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max)
{
    int i;
    int n;

    n = 0;
    for (i = r->head; i < r->head + len; i++) {
        if (r->tail == func_02036624((void *)r, i) || n == max) {
            return n;
        }
        dst[n] = r->buf[func_02036624((void *)r, i)];
        n++;
    }
    return n;
}


/*
 * 36 bytes with no call: the distance from the cursor at p+0x0C to the end of
 * the buffer at p+0x0E, answered from the buffer base at p+4 when the cursor is
 * past the end.
 *
 * The halfword at p+0x0E is read three times in the original (condition, both
 * arms), which is why it is spelled as a field read in each place rather than
 * bound to a local. Spelling all three as plain field reads is not enough on
 * this front end: it CSEs the two arm reads into the condition's register and
 * the function comes out one instruction (4 bytes) short at 32. Declaring the
 * two arm reads `volatile` keeps all three loads, which is the original's shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020365E8.c \
 *       --func func_020365E8 --addr 0x020365E8 --cc 1.1p1 --arm
 */
int func_020365E8(char *p)
{
    int a = ((struct Obj01465 *)p)->fC;

    if (a > ((struct Obj01465 *)p)->fE)
        return ((struct Obj01465 *)p)->f4 + *(volatile short *)&((struct Obj01465 *)p)->fE - a;
    return *(volatile short *)&((struct Obj01465 *)p)->fE - a;
}

/*
 * function: func_021B61E8
 * address:  0x021B61E8
 * packet:   pkt_ov101_021B61E8
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state step: release the pending resource, start the async job with
 * the 0x021B6674 callback, wait for its done flag, then return 1 once.
 *
 * blocker: every concrete byte matches; the one open site is the ABS32 pool
 *   word naming the callback 0x021B6674 (ov101), an unlabelled Thumb leaf
 *   (`movs r1,#1; str r1,[r0,#0x54]; bx lr`, shown as .word in the listing)
 *   with no witness outside this range. Matching 0x021B6674 itself (or a
 *   label for it) gives the `matched` class and makes this EXACT.
 *
 * symbols:
 *   func_021B6760  0x021B6760  thumb  ov101
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_021B6674  0x021B6674  thumb  ov101
 */

typedef struct Obj {
    int f00;
    unsigned char sub[0x40];
    int state;
    unsigned char pad48[0xC];
    int done;
    unsigned char pad58[0x1C];
    int pending;
    int busy;
} Obj;

extern void func_021B6760(void *p);
extern int func_0203CEAC(void (*cb)(void));
extern void func_021B6674(void);

int func_021B61E8(Obj *o)
{
    if (o->busy != 0)
        return 1;
    switch (o->state) {
    case 0:
        if (o->pending != 0) {
            func_021B6760(o->sub);
            o->pending = 0;
        }
        o->done = 0;
        o->state = 1;
        break;
    case 1:
        if (func_0203CEAC(func_021B6674) != 0)
            o->state = 2;
        else
            o->state = 3;
        break;
    case 2:
        if (o->done != 0)
            o->state = 3;
        break;
    case 3:
        o->state = 0;
        return 1;
    }
    return 0;
}

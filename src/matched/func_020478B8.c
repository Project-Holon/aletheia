/*
 * function: func_020478B8
 * address:  0x020478B8
 * packet:   pkt_020478B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: advance a clamped counter.  a is a table base whose
 * slot [idx] holds an object; the object's word at +4 points at a run state
 * (counter at +0, descriptor pointer at +8) whose descriptor's u16 at +4 is a
 * limit in units of 0x1000.  Adds amount to the counter; if it reaches the
 * limit it rewinds by one 0x1000 and returns 0, if it goes negative it pins to
 * zero and returns 0, otherwise returns 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Run {
    u32 cur;
    u32 pad_04;
    u8 *desc;
};

struct Obj {
    u32 pad_00;
    struct Run *run;
};

int func_020478B8(void *a, int idx, int amount)
{
    struct Obj **tbl = *(struct Obj ***)((char *)a + 8);
    struct Obj *e = tbl[idx];
    struct Run *r;
    int nv;
    u32 lim;

    if (e == 0) {
        return 0;
    }

    r = e->run;
    nv = (int)r->cur + amount;
    r->cur = (u32)nv;

    lim = (u32)*(u16 *)(r->desc + 4) << 12;
    if (nv >= (int)lim) {
        r->cur = lim - 0x1000;
        return 0;
    }
    if (nv < 0) {
        r->cur = 0;
        return 0;
    }
    return 1;
}

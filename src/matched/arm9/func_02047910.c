/*
 * function: func_02047910
 * address:  0x02047910
 * packet:   pkt_02047910
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: the sibling of func_020478B8 with a different clamp
 * policy.  Advance the counter of the run state reached through a's table slot
 * [idx]; if it reaches the descriptor limit it pins the counter to zero and
 * returns 0, if it goes negative it pins it to the limit and returns 0,
 * otherwise returns 1.
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

int func_02047910(void *a, int idx, int amount)
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
        r->cur = 0;
        return 0;
    }
    if (nv < 0) {
        r->cur = lim;
        return 0;
    }
    return 1;
}

/*
 * function: func_02022A88
 * address:  0x02022A88
 * packet:   pkt_02022940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef int s32;

struct AnimStep {
    s32 steps;
    s32 limit;
    s32 counter;
    s32 val;
    s32 target_val;
    s32 step_delta;
    s32 pad18;
    s32 scaled_val;
};

int func_02022A88(struct AnimStep *p)
{
    int ret = 0;

    p->counter++;
    if (p->counter >= p->limit) {
        p->counter = 0;
        if (p->steps - 1 > 0) {
            p->steps--;
            p->val += p->step_delta;
        } else {
            p->val = p->target_val;
            ret = 1;
        }

        p->scaled_val = p->val / 128;
    }

    return ret;
}

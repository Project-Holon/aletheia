/*
 * function: ISS_3DS_SYS_StepMasterVolume
 * address:  0x0202BE24
 * packet:   pkt_0202BE24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

struct Obj0202BE24 {
    u8 pad[8];
    u8 target;
    u8 curr;
    u8 step;
};

void ISS_3DS_SYS_StepMasterVolume(struct Obj0202BE24 *p)
{
    int target = p->target;
    int curr = p->curr;
    int diff;
    int abs_diff;
    int step;

    if (curr == target) {
        return;
    }

    diff = target - curr;
    abs_diff = diff;
    if (diff <= 0) {
        abs_diff = -diff;
    }

    step = p->step;
    if (abs_diff >= step) {
        if (diff < 0) {
            diff = -step;
        } else {
            diff = step;
        }
    }

    p->curr += diff;
}

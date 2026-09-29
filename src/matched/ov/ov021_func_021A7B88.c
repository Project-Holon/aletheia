/*
 * function: func_021A7B88
 * address:  0x021A7B88
 * packet:   pkt_ov021_021A7B88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills the Work step table (bytes 0x2C..) from the mode the Args' f0C
 * object reports.
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb  ov021
 *   func_021A80FC  0x021A80FC  thumb  ov021
 *   func_02162370  0x02162370  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x2C - 0x1B];
    u8 step[9];
} Work;

extern int func_021A8268(Work *w);
extern u8 func_021A80FC(void *p);
extern int func_02162370(void *p);

void func_021A7B88(Work *w)
{
    Args *a;
    void *o;

    a = w->f00;
    o = a->f0C;
    if (func_021A8268(w) != 0) {
        switch (func_021A80FC(o)) {
        case 0:
        case 1:
        default:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 5;
            w->step[3] = 2;
            w->step[4] = 3;
            w->step[5] = 4;
            w->step[6] = 6;
            w->step[7] = 7;
            w->step[8] = 8;
            return;
        case 2:
        case 3:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 2;
            w->step[3] = 3;
            w->step[4] = 4;
            w->step[5] = 5;
            w->step[6] = 6;
            w->step[7] = 7;
            w->step[8] = 8;
            return;
        }
    } else if (func_02162370(a->f14) != 0) {
        w->step[0] = 0;
        w->step[1] = 1;
        w->step[2] = 4;
        w->step[3] = 5;
        w->step[4] = 8;
        return;
    } else {
        switch (func_021A80FC(o)) {
        case 0:
        case 1:
        default:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 5;
            w->step[3] = 4;
            w->step[4] = 8;
            return;
        case 2:
        case 3:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 4;
            w->step[3] = 5;
            w->step[4] = 8;
            return;
        }
    }
}

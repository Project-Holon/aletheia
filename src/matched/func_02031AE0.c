/*
 * function: func_02031AE0
 * address:  0x02031AE0
 * packet:   pkt_020319C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dispatch one step of the object's state machine: if the manager global's
 * front object is unarmed the call reports 4 immediately; otherwise the
 * object is either re-armed (its two queue cursors agree) or advanced, and
 * the call's status is dispatched through the dense switch that runs from
 * case 0 to case 4.  The armed transition stamps the progress byte at +0x1c.
 *
 * Two spellings were load-bearing in reaching EXACT, both worth keeping:
 *   - if/else polarity: the unequal arm is written first so it becomes the
 *     fall-through arm and the equal arm goes out of line at +0x40;
 *   - the case order 1, 2, 3, 0, 4: mwcc lays the arm bodies out in source
 *     order and the original's case-0 body sits after case 3's, at +0x90.
 *
 * symbols:
 *   unk_02146994   0x02146994  data
 *   func_02031FE0  0x02031FE0  arm
 *   func_02032688  0x02032688  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031AE0.c \
 *       --func func_02031AE0 --addr 0x02031AE0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct State {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
};

extern u32  unk_02146994[];
extern u32  func_02031FE0(struct State *o, u32 a1, u32 a2, u32 a3);
extern u32  func_02032688(struct State *o, u32 a1, u32 a2);

int func_02031AE0(struct State *o, u32 a1)
{
    u32 r;

    if (*(u32 *)unk_02146994[0] == 0)
        return 4;

    if (o->f00 != o->f04)
        r = func_02031FE0(o, a1, 0, 0);
    else
        r = func_02032688(o, 0, 0);

    switch (r) {
    case 1:
        o->f1c = 1;
        return 1;
    case 2:
        o->f1c = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}

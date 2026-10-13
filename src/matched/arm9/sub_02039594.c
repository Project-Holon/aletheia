/*
 * function: sub_02039594
 * address:  0x02039594
 * packet:   pkt_020393A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   unk_021469D0   0x021469D0  data
 *
 * May the caller proceed?  With no link state, or with the +0x64 byte of the
 * session record set, the answer is an unconditional yes; in the two session
 * states 0 and 5 it is whatever the +0x1eb byte of the link state says; any
 * other state is a yes.
 *
 * The `state == 0 || state == 5` pair is one `cmp` / `cmpne` chain feeding a
 * single `eq` block, so it has to be written as one disjunction: as two
 * `if`s the shared block is duplicated.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039594.c \n *       --func sub_02039594 --addr 0x02039594 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct LinkState {
    u8 pad000[0x1eb];
    u8 unk_1eb;
};

struct Session {
    u8 pad00[0x64];
    u8 unk_64;
    u8 state;
};

extern struct LinkState *unk_021469D0;
extern void *GFL_NET_GetInitParam(void);

int sub_02039594(void)
{
    struct Session *s;

    if (unk_021469D0 == 0) {
        goto yes;
    }

    s = GFL_NET_GetInitParam();
    if (s->unk_64 != 0) {
        goto yes;
    }
    if (s->state == 0 || s->state == 5) {
        return unk_021469D0->unk_1eb;
    }
yes:
    return 1;
}

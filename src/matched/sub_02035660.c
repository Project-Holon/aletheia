/*
 * function: sub_02035660
 * address:  0x02035660
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469BC     0x021469BC  data
 *   sub_020355F8   0x020355F8  arm
 *   sub_02036390   0x02036390  arm
 *   sub_02035E54   0x02035E54  arm
 *
 * The one labelled function of the 0x021469BC accessor block (the other
 * eight are in src/matched/unit_020355C4.c): write the u8 at +0x3d of the
 * singleton, then run the two follow-up passes at 0x02036390 and
 * 0x02035E54 over it.
 *
 * Previously parked at MATCH: 0x02036390 and 0x02035E54 are called from
 * nowhere else in the image, so neither PC24 site had an outside witness of
 * any class and --suggest-split could not help.  Both now close on the
 * `matched` class (src/matched/sub_02036390.c and src/matched/sub_02035E54.c);
 * nothing in this file had to change.
 *
 * The global is re-read between the three calls: all three callees are
 * externs that may store to it, so the load cannot be hoisted, and
 * holding &g_021469BC in r4 across the calls is what that costs.
 * sub_020355F8 ignores its first argument (see the unit file); the call
 * still passes the singleton.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035660.c \
 *       --func sub_02035660 --addr 0x02035660 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Sys {
    u8 pad_00[0x3c];
    u8 unk_3c;
    u8 unk_3d;
    u8 unk_3e;
};

extern struct Sys *g_021469BC;

extern void sub_020355F8(struct Sys *unused, u8 v);
extern void sub_02036390(struct Sys *p);
extern void sub_02035E54(struct Sys *p);

void sub_02035660(u8 v)
{
    sub_020355F8(g_021469BC, v);
    sub_02036390(g_021469BC);
    sub_02035E54(g_021469BC);
}

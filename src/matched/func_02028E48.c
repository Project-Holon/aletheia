/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * function: func_02028E48
 * address:  0x02028E48
 * packet:   pkt_02028DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH on one data address: all 56 concrete bytes are right and
 * func_02028D8C and func_02028FD0 both resolve, but the permission table at
 * 0x0209FD90 appears in exactly one literal pool image-wide, this function's
 * own at 0x02028E7C, so the `literal` class has no outside site.  The word at
 * 0x0209FD90 is zero, so nothing distinguishes the table's start from the run
 * of zeros before it either.  Closing this file would close
 * src/pending/func_02028E0C.c and src/pending/func_020289F8.c behind it.
 *
 * field_sound_system.c: decide whether a new command of class `kind` may be
 * accepted.  Two states are consulted in order, the class of the command the
 * ring is currently pointing at (func_02028D8C) and the class latched at
 * +0x1C; the first non-zero one indexes the 8-wide permission table at
 * 0x0209FD90 by (state, kind).  With neither set the decision falls through
 * to func_02028FD0.
 *
 * The table base is loaded from the pool separately in each arm: the two arms
 * are siblings, not a dominator and a dominated block, and mwccarm does not
 * share an address constant across them.
 *
 * symbols:
 *   func_02028D8C  0x02028D8C  thumb
 *   func_02028FD0  0x02028FD0  thumb
 *   g_0209FD90     0x0209FD90  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/func_02028E48.c \
 *       --addr 0x02028E48 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys {
    u8  pad_00[0x1c];
    u32 unk1C;      /* 0x1c */
};

extern u8 g_0209FD90[][8];

extern struct Cmd *func_02028D8C(struct Sys *s);
extern u32 func_02028FD0(struct Sys *s, u32 kind);

u32 func_02028E48(struct Sys *s, u32 kind)
{
    u32 state;

    state = func_02028D8C(s)->unk00;
    if (state != 0) {
        return g_0209FD90[state][kind];
    }
    state = s->unk1C;
    if (state != 0) {
        return g_0209FD90[state][kind];
    }
    return func_02028FD0(s, kind);
}

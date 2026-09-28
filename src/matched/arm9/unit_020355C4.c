/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_020355C4, sub_020355D8, sub_020355EC, sub_020355F8,
 *           sub_0203560C, sub_02035614, sub_02035630, sub_02035648
 * address:  0x020355C4
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
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   sub_020355C4  read the u8 at +0x3c of the singleton.
 *   sub_020355D8  write it.
 *   sub_020355EC  clear the u8 at +0x3e of a caller-supplied instance.
 *   sub_020355F8  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with sub_0203560C but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   sub_0203560C  read the u8 at +0x3d of a caller-supplied instance.
 *   sub_02035614  global wrapper over sub_020355F8.
 *   sub_02035630  global wrapper over sub_0203560C.
 *   sub_02035648  global wrapper over sub_020355EC.
 *
 * The range deliberately stops before sub_02035660, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/sub_02035660.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */

typedef unsigned char u8;

struct Sys {
    u8 pad_00[0x3c];
    u8 unk_3c;
    u8 unk_3d;
    u8 unk_3e;
};

extern struct Sys *g_021469BC;

u8 sub_020355C4(void)
{
    return g_021469BC->unk_3c;
}

void sub_020355D8(u8 v)
{
    g_021469BC->unk_3c = v;
}

void sub_020355EC(struct Sys *p)
{
    p->unk_3e = 0;
}

void sub_020355F8(struct Sys *unused, u8 v)
{
    g_021469BC->unk_3d = v;
}

u8 sub_0203560C(struct Sys *p)
{
    return p->unk_3d;
}

void sub_02035614(u8 v)
{
    sub_020355F8(g_021469BC, v);
}

u8 sub_02035630(void)
{
    return sub_0203560C(g_021469BC);
}

void sub_02035648(void)
{
    sub_020355EC(g_021469BC);
}

/*
 * function: GFL_NET_GetRunState
 * address:  0x0203CD98
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Guarded call through a function-pointer table: fetch the singleton via
 * GFL_NET_GetSession, bail to 0 if it is null, then chase the pointer at +0x340
 * to a table and call its +0x6c entry through a register (no relocation
 * site there, `blx r0`).  GFL_NET_GetSession has many outside callers, so its
 * own call closes on the `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetRunState.c \
 *       --func GFL_NET_GetRunState --addr 0x0203CD98 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef int (*Fn)(void);

struct Table {
    unsigned char pad_00[0x6c];
    Fn            unk_6c;
};

struct Singleton {
    unsigned char  pad_00[0x340];
    struct Table  *unk_340;
};

extern void *GFL_NET_GetSession(void);

int GFL_NET_GetRunState(void)
{
    struct Singleton *s = GFL_NET_GetSession();

    if (s == 0) {
        return 0;
    }

    return s->unk_340->unk_6c();
}

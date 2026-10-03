/*
 * function: func_0203CD98
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
 *   func_0203D788  0x0203D788  arm
 *
 * Guarded call through a function-pointer table: fetch the singleton via
 * func_0203D788, bail to 0 if it is null, then chase the pointer at +0x340
 * to a table and call its +0x6c entry through a register (no relocation
 * site there, `blx r0`).  func_0203D788 has many outside callers, so its
 * own call closes on the `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CD98.c \
 *       --func func_0203CD98 --addr 0x0203CD98 --cc 1.1p1 --arm
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

extern void *func_0203D788(void);

int func_0203CD98(void)
{
    struct Singleton *s = func_0203D788();

    if (s == 0) {
        return 0;
    }

    return s->unk_340->unk_6c();
}

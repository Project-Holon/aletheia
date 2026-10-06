/*
 * unit:     no
 * function: func_0203D210
 * address:  0x0203D210
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469E0     0x021469E0  data
 *   func_0203D788  0x0203D788  arm
 *
 * TU: net.c.
 *
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * g_021469E0.unk_08 straight out of the singleton (the same two
 * instructions func_0203D788 is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D210.c \
 *       --func func_0203D210 --addr 0x0203D210 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct NetVtbl {
    u8 pad_00[0x6c];
    u32 (*unk_6c)(void);
};

struct NetSys {
    u8              pad_000[0x340];
    struct NetVtbl *vtbl;
};

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

extern struct Singleton g_021469E0;
extern struct NetSys   *func_0203D788(void);

u32 func_0203D210(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 1;
    }
    return func_0203D788()->vtbl->unk_6c() == 0;
}

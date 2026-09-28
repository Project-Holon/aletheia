/*
 * function: sub_0204A600
 * address:  0x0204A600
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204BAEC  0x0204BAEC  arm
 *   func_0204BB54  0x0204BB54  arm
 *   func_0204BB8C  0x0204BB8C  arm
 *   func_02066998  0x02066998  arm
 *   g_02146A74     0x02146A74  data
 *
 * Cell-actor manager main tick: updates latch and displays, iterates banks,
 * updates render subsystem if active, and resets latch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204A600.c \
 *       --func sub_0204A600 --addr 0x0204A600 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_000[0xec];
    u32 unk_0ec;
};

extern struct Sys *g_02146A74;

extern void func_0204BAEC(u32 v);
extern void func_0204BB54(void);
extern void func_0204BB8C(void);
extern void func_02066998(void);

void sub_0204A600(void)
{
    if (g_02146A74 == 0) {
        return;
    }

    func_0204BAEC(0);
    func_0204BB54();
    func_0204BB8C();

    if (g_02146A74->unk_0ec != 0) {
        func_02066998();
    }

    func_0204BAEC(1);
}

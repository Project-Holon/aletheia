/*
 * function: func_0203A5E4
 * address:  0x0203A5E4
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D8     0x021469D8  data
 *   func_02082BCC  0x02082BCC  arm
 *
 * Clears the 16-byte slot whose +0xC key matches, over the same four slots
 * func_0203A574 writes.  func_02082BCC is the MSL memset helper; the clear is
 * that unit's only non-trivial statement and the loop's miss path is the only
 * other exit.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A5E4.c \
 *       --func func_0203A5E4 --addr 0x0203A5E4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Entry {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

extern struct Entry *g_021469D8;
extern void func_02082BCC(int dst, int value, int size);

void func_0203A5E4(u32 key)
{
    struct Entry *e = g_021469D8;
    int i;

    if (e == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (e[i].d == key) {
            func_02082BCC((int)&e[i], 0, 0x10);
            return;
        }
    }
}

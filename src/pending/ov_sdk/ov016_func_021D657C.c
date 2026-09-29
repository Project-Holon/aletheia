/*
 * function: func_021D657C
 * address:  0x021D657C
 * packet:   pkt_ov016_021D657C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes: DIFF, whole-function register allocation shift. Mask derives as (x ^ 0x2FFF) & 0x2FFF (image uses r1 lsr #12 of 0x02FFFFA8); target keeps the fold pointer in r4, bit in ip, i in r3, hoists 0x28 in r5; this source puts the fold pointer in lr and i in r2. Structure (trg/release/repeat updates, count loop 40/47) matches.
 *
 * sdk:      readKey (libdwcutil.TWL.HYB.a input.o)
 *
 * symbols:
 *   g_021DE688     0x021DE688 data
 *   g_021DE690     0x021DE690 data
 */

struct keystate {
    char pad0[0x30];
    unsigned short cont;
    unsigned short trg;
    unsigned short repeat;
    unsigned short release;
};

struct keyfold {
    int f0;
    struct keystate *ks;
};

extern struct keyfold g_021DE688;
extern unsigned char g_021DE690[14];

void func_021D657C(void)
{
    unsigned short *input;
    int i;
    unsigned short bit;

    input = (unsigned short *)0x04000130;
    bit = ((*input | *(unsigned short *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF;
    bit = bit & ~((bit & 0x40) << 1) & ~((bit & 0x20) >> 1);
    g_021DE688.ks->trg = (g_021DE688.ks->cont ^ bit) & bit;
    g_021DE688.ks->release = (g_021DE688.ks->cont ^ bit) & g_021DE688.ks->cont;
    g_021DE688.ks->cont = bit;
    g_021DE688.ks->repeat = g_021DE688.ks->trg;
    for (i = 0; i < 14; i++) {
        if (bit & (unsigned short)(1 << i)) {
            g_021DE690[i]++;
            if (g_021DE690[i] == 40) {
                g_021DE688.ks->repeat |= (unsigned short)(1 << i);
            } else if (g_021DE690[i] == 47) {
                g_021DE690[i] = 40;
                g_021DE688.ks->repeat |= (unsigned short)(1 << i);
            }
        } else {
            g_021DE690[i] = 0;
        }
    }
}

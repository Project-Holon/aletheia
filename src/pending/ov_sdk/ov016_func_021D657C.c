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
 * notes: SIZE-EXACT (272 B) with the per-bit test inverted so the zero-store is
 * the THEN arm -- mwcc then predicates the store (strbeq) where the if/else
 * spelling branches and costs 8 bytes.  Ours 272 B, 2/2 relocs resolved.
 * Residue: 71 bytes, a register permutation only, instruction for instruction
 * identical -- image keeps `bit` in r1 and the loaded ks pointer in r0
 * (`+0028 mov r1, r0` / `+003C ldr r0, [r4, #4]`), ours keeps bit in r0
 * (`+0028 mov r0, r0`) and the ks pointer in r2 (`+003C ldr r2, [r4, #4]`),
 * with the rest rotated the same way (r6/r7 loop temps vs r5/r6).
 *   * +0028 mov r1, r0     | mov r0, r0
 *   * +003C ldr r0, [r4, #4] | ldr r2, [r4, #4]
 * A local `struct keystate *ks = g_021DE688.ks` hoisted to the top re-allocates
 * the whole body (252 B, 182 diffs), so the shape above is kept.
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
        if (!(bit & (unsigned short)(1 << i))) {
            g_021DE690[i] = 0;
        } else {
            g_021DE690[i]++;
            if (g_021DE690[i] == 40) {
                g_021DE688.ks->repeat |= (unsigned short)(1 << i);
            } else if (g_021DE690[i] == 47) {
                g_021DE690[i] = 40;
                g_021DE688.ks->repeat |= (unsigned short)(1 << i);
            }
        }
    }
}

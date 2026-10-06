/*
 * function: func_02015F50
 * address:  0x02015F50
 * packet:   pkt_02015F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb function in the ARM9 module (mcss.c). Starts the
 * +0x134 fade: sets bit 12 of the +0x140 flag word, stores the current
 * and target bytes (+0x134, +0x135), the fifth argument at +0x13C, clears
 * +0x136, splits the signed step into +0x137 and the s32 step at +0x138
 * (1 - step when negative), and negates the step when the current value
 * is above the target (`cmp r1, r2 / bls`, so both are unsigned bytes).
 *
 * The step is stored as a field in each arm and the negation re-reads the
 * field (the original reloads +0x138 with a fresh `0x4e << 2` base).
 * Written through raw char offsets with the step in a local, mwcc forwards
 * the stored value into the `muls` and colours the 0x140 base into r5;
 * the struct spelling below is byte-exact. `* 0xFFFFFFFF` rather than
 * `-x` is what emits the `mvns`/`muls` pair.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;
typedef signed int    s32;

struct McssFade {
    u8  pad[0x134];
    s8  f134;       /* +0x134  current value */
    s8  f135;       /* +0x135  target value  */
    u8  f136;
    u8  f137;
    s32 f138;       /* +0x138  step          */
    u32 f13c;
    u32 f140;       /* +0x140  flag word     */
};

void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e)
{
    w->f140 |= 0x1000;
    w->f134 = cur;
    w->f135 = target;
    w->f13c = e;
    w->f136 = 0;
    if (step < 0) {
        w->f137 = 0;
        w->f138 = -(step - 1);
    } else {
        w->f137 = step;
        w->f138 = 1;
    }
    if (cur > target) {
        w->f138 *= 0xFFFFFFFF;
    }
}

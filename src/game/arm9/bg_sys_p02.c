/*
 * file:     bg_sys_p02.c
 * function: func_0203F0A8
 * address:  0x0203F0A8
 * packet:   pkt_0203F0A8
 * region:   arm9
 * compiler: 1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F8    0x021469F8  data
 *   func_0203F034 0x0203F034  arm
 *
 * MT19937 genrand_int32 with the state regeneration inlined (reference
 * implementation, N = 624, M = 397); func_0203F034 is init_genrand.  The
 * state block (mt[624], mti, mag01[2]) is one heap object behind
 * g_021469F8, reloaded every iteration because the mt[kk] store may alias
 * the pointer.  docs/notes/func_0203F0A8.c.txt has the full decode.
 *
 * FRONT END (wave 18, lane ties_a): this exact C was DIFF 340/340, 16 bytes
 * out under dsi/1.1p1 for eight waves.  The residue was one addressing
 * mode: the image loads mt[kk] with the scaled-register form
 * `ldr ip, [r0, r1, lsl #2]` in both regeneration loops, where 1.1p1 folds
 * it onto the &mt[kk] base as `[r3]` and reorders the two loads.  The
 * permuter was flat under it (hill 800 exhausted, anneal 3000) and no
 * spelling moved it (about forty recorded in the note), which is the
 * front-end signature.  Under dsi/1.2 (and 1.2p1, 1.2p2, 1.3) the same C
 * is 340 bytes, 0 mismatches; 1.1 is 16 out, ../2.0/sp2 352 bytes.  The
 * neighbours func_0203F034, func_0203F1FC and func_0203F258 are 1.1p1.
 */
typedef unsigned int u32;
struct MtState {
    u32 mt[624];
    int mti;
    u32 mag01[2];
};

extern struct MtState *g_021469F8;

extern void func_0203F034(u32 seed);

u32 func_0203F0A8(void)
{
    u32 y;

    if (g_021469F8->mti >= 624) {
        int kk;

        if (g_021469F8->mti == 625) {
            func_0203F034(5489);
        }

        for (kk = 0; kk < 227; kk++) {
            y = (g_021469F8->mt[kk] & 0x80000000)
                | (g_021469F8->mt[kk + 1] & 0x7fffffff);
            g_021469F8->mt[kk] = g_021469F8->mt[kk + 397] ^ (y >> 1)
                ^ g_021469F8->mag01[y & 1];
        }

        for (; kk < 623; kk++) {
            y = (g_021469F8->mt[kk] & 0x80000000)
                | (g_021469F8->mt[kk + 1] & 0x7fffffff);
            g_021469F8->mt[kk] = g_021469F8->mt[kk - 227] ^ (y >> 1)
                ^ g_021469F8->mag01[y & 1];
        }

        y = (g_021469F8->mt[623] & 0x80000000)
            | (g_021469F8->mt[0] & 0x7fffffff);
        g_021469F8->mt[623] = g_021469F8->mt[396] ^ (y >> 1)
            ^ g_021469F8->mag01[y & 1];

        g_021469F8->mti = 0;
    }

    y = g_021469F8->mt[g_021469F8->mti++];

    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);

    return y;
}


/*
 * unit:     yes
 * address:  0x02019A50
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_CRYPTO_XorBlock, POKE_CRYPTO_NextRandom, POKE_CRYPTO_Checksum
 *
 * The three primitives the whole save record in this region is protected
 * with.  POKE_CRYPTO_NextRandom is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, POKE_CRYPTO_XorBlock XOR masks a byte range with that stream halfword by
 * halfword, and POKE_CRYPTO_Checksum is the plain halfword sum used as the checksum.
 *
 * POKE_CRYPTO_XorBlock opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets POKE_TOOL_DecodeBoxBlock mask the
 * same area twice with the same seed to undo itself.
 *
 * POKE_CRYPTO_NextRandom carries no label in the generated listing.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 POKE_CRYPTO_NextRandom(u32 *s);

void POKE_CRYPTO_XorBlock(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= POKE_CRYPTO_NextRandom(s);
            i++;
        } while (i < n);
    }
}

u16 POKE_CRYPTO_NextRandom(u32 *s)
{
    *s = *s * 0x41C64E6D + 0x6073;
    return (u16)(*s >> 16);
}

u16 POKE_CRYPTO_Checksum(const u16 *p, u32 size)
{
    u16 sum = 0;
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        do {
            sum = (u16)(sum + p[i]);
            i++;
        } while (i < n);
    }
    return sum;
}

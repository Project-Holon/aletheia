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
 * function: func_02019A50, func_02019A7C, func_02019A9C
 *
 * The three primitives the whole save record in this region is protected
 * with.  func_02019A7C is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, func_02019A50 XOR masks a byte range with that stream halfword by
 * halfword, and func_02019A9C is the plain halfword sum used as the checksum.
 *
 * func_02019A50 opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets POKE_TOOL_DecodeBoxBlock mask the
 * same area twice with the same seed to undo itself.
 *
 * func_02019A7C carries no label in the generated listing.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_02019A7C(u32 *s);

void func_02019A50(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= func_02019A7C(s);
            i++;
        } while (i < n);
    }
}

u16 func_02019A7C(u32 *s)
{
    *s = *s * 0x41C64E6D + 0x6073;
    return (u16)(*s >> 16);
}

u16 func_02019A9C(const u16 *p, u32 size)
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

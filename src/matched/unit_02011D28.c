/*
 * unit:     yes
 * address:  0x02011D28
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02011D28, func_02011D34
 *
 * symbols:
 *   func_0203F0A8  0x0203F0A8  arm
 *
 * func_02011D28 calls its argument, if not null, purely for effect: the
 * call falls straight through into `mvns r0, r4` with no branch around it,
 * so the return value is always the bitwise complement of the function
 * pointer itself, never whatever the call returned.
 *
 * func_02011D34 calls func_0203F0A8 twice and returns nothing, a debug
 * marker pair (begin/end) around nothing in between.
 *
 * func_02011D40 and func_02011D7C, on either side of the function between
 * this pair, were a documented register-swap near miss on their single
 * `struct.unk04 += 1`; now EXACT (src/matched/func_02011D40.c and
 * src/matched/func_02011D7C.c). The fix was declaring the global as a
 * real struct and using field syntax (`g_02146248.unk04 += 1`) instead
 * of raw pointer-plus-offset arithmetic; not merged into this unit
 * because func_02011D60 between them stays out of the manifest (see
 * below).
 *
 * The function between them, func_02011D60, reproduces every byte the
 * comparison covers, but is left out of the manifest: the listing's extent
 * runs two bytes long across the `00 00` alignment pad in front of
 * func_02011D7C, an `EXACT*` this territory's policy does not accept
 * because the follower carries a real label rather than being the
 * unlabelled-follower case `EXACT*` is meant for.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011D28.c \
 *       --addr 0x02011D28 --thumb
 */

typedef unsigned int u32;

extern u32 func_0203F0A8(void);

u32 func_02011D28(u32 (*fn)(void))
{
    if (fn != 0) {
        fn();
    }
    return ~(u32)fn;
}

void func_02011D34(void)
{
    func_0203F0A8();
    func_0203F0A8();
}

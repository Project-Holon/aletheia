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
 * function: GAMESYSTEM_CallIfSet, GAMESYSTEM_ReadTimerTwice
 *
 * symbols:
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *
 * GAMESYSTEM_CallIfSet calls its argument, if not null, purely for effect: the
 * call falls straight through into `mvns r0, r4` with no branch around it,
 * so the return value is always the bitwise complement of the function
 * pointer itself, never whatever the call returned.
 *
 * GAMESYSTEM_ReadTimerTwice calls GF_STANDARD_Rand twice and returns nothing, a debug
 * marker pair (begin/end) around nothing in between.
 *
 * GAMESYSTEM_LeakHeapPenalty and GAMESYSTEM_LeakHeapPenaltyRepeat, on either side of the function between
 * this pair, were a documented register-swap near miss on their single
 * `struct.unk04 += 1`; now EXACT (src/matched/GAMESYSTEM_LeakHeapPenalty.c and
 * src/matched/GAMESYSTEM_LeakHeapPenaltyRepeat.c). The fix was declaring the global as a
 * real struct and using field syntax (`_GameSystemGlobal.unk04 += 1`) instead
 * of raw pointer-plus-offset arithmetic; not merged into this unit
 * because GAMESYSTEM_ProbeHeapCreate between them stays out of the manifest (see
 * below).
 *
 * The function between them, GAMESYSTEM_ProbeHeapCreate, reproduces every byte the
 * comparison covers, but is left out of the manifest: the listing's extent
 * runs two bytes long across the `00 00` alignment pad in front of
 * GAMESYSTEM_LeakHeapPenaltyRepeat, an `EXACT*` this territory's policy does not accept
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

extern u32 GF_STANDARD_Rand(void);

u32 GAMESYSTEM_CallIfSet(u32 (*fn)(void))
{
    if (fn != 0) {
        fn();
    }
    return ~(u32)fn;
}

void GAMESYSTEM_ReadTimerTwice(void)
{
    GF_STANDARD_Rand();
    GF_STANDARD_Rand();
}

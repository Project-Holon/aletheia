/*
 * unit:     no
 * function: ISS_SWITCH_SET_Free
 * address:  0x0202C3A0
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * A pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) into the ARM SDK
 * function ENV_SetResourceSet, the same target as
 * src/matched/sub_0202C5AC.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SET_Free.c \
 *       --func ISS_SWITCH_SET_Free --addr 0x0202C3A0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 func_020307B0(void *p);

u32 ISS_SWITCH_SET_Free(void *p)
{
    return func_020307B0(p);
}

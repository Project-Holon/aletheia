/*
 * function: func_020111E8
 * address:  0x020111E8
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four bytes, `movs r0, #0x15; bx lr`: a constant getter, isolated between
 * two large unmatched functions, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020111E8.c \
 *       --func func_020111E8 --addr 0x020111E8 --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_020111E8(void)
{
    return 0x15;
}

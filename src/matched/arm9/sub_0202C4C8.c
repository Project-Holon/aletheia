/*
 * unit:     no
 * function: ISS_SWITCH_SET_ReadBgmNo
 * address:  0x0202C4C8
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf sitting in the four bytes between sub_0202C4A4's last
 * instruction and ISS_SWITCH_SET_GetZoneCount's first
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): no
 * register-saving prologue, so disasm.py's sweep never marks it. It is a
 * plain read of the object's first word, reached only through
 * sub_0202C340's pool-word-and-bx tail call
 * (src/matched/unit_0202C318.c, parked at MATCH because this address is
 * its only caller anywhere in the image).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C4C8.c \
 *       --func ISS_SWITCH_SET_ReadBgmNo --addr 0x0202C4C8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

u32 ISS_SWITCH_SET_ReadBgmNo(u32 *p)
{
    return *p;
}

/*
 * unit:     yes
 * function: ISS_SYS_OnZoneChangeRoad
 * address:  0x0202B7B8
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An empty function: `bx lr` and nothing else. Matched as a one-function
 * unit rather than with `one`, because disasm.py's 4-byte extent for this
 * address includes the linker's inter-section padding after the 2-byte
 * body, and `tu` lays the compiled object out on its own footprint instead
 * of against that extent (see src/matched/sub_0202AB64.c for the same
 * situation with a longer body).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/ISS_SYS_OnZoneChangeRoad.c \
 *       --addr 0x0202B7B8 --thumb
 */

void ISS_SYS_OnZoneChangeRoad(void)
{
}

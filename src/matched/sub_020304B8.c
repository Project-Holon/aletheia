/*
 * unit:     no
 * address:  0x020304B8
 * packet:   pkt_0202FB34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020304B8
 *
 * A halfword accessor at a negative offset from its argument: the pointer
 * is to a member partway into a larger object, and this reads a sibling
 * field 0x1c bytes before it. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020304B8.c \
 *       --func sub_020304B8 --addr 0x020304B8 --cc 1.1p1
 */

typedef unsigned short u16;

u16 sub_020304B8(void *p)
{
    return *(u16 *)((char *)p - 0x1c);
}

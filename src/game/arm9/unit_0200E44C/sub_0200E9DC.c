/*
 * function: sub_0200E9DC
 * address:  0x0200E9DC
 * packet:   pkt_0200E994
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A four-byte constant getter with no register-saving prologue; it was
 * hiding as the unlabelled follower behind sub_0200E994's EXACT* extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Its own
 * follower, sub_0200E9E0, already carries a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E9DC.c \
 *       --func sub_0200E9DC --addr 0x0200E9DC --cc 1.1p1
 */

unsigned int sub_0200E9DC(void)
{
    return 0x9c;
}

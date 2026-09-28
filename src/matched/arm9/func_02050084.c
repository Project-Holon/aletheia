/*
 * function: func_02050084
 * address:  0x02050084
 * packet:   pkt_0204FE94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Four-byte empty leaf: `bx lr`, no prologue.  The billboard-actor family's
 * no-op hook, called in the same slot as the other per-entry callbacks.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050084.c \
 *       --func func_02050084 --addr 0x02050084 --cc 1.1p1 --arm
 */

void func_02050084(void)
{
}

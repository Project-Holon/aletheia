/*
 * function: func_020365E8
 * address:  0x020365E8
 * packet:   pkt_02036568
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 36 bytes with no call: the distance from the cursor at p+0x0C to the end of
 * the buffer at p+0x0E, answered from the buffer base at p+4 when the cursor is
 * past the end.  The halfword at p+0x0E is read three times in the original
 * (condition, both arms), which is why it is spelled as a field read in each
 * place rather than bound to a local: with a local the compiler drops the
 * `ldrshgt` and the whole function is one instruction shorter.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020365E8.c \
 *       --func func_020365E8 --addr 0x020365E8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

int func_020365E8(char *p)
{
    int a = *(short *)(p + 0x0C);

    if (a > *(short *)(p + 0x0E))
        return *(u32 *)(p + 4) + *(short *)(p + 0x0E) - a;
    return *(short *)(p + 0x0E) - a;
}

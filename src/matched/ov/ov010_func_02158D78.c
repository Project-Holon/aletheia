/*
 * function: func_02158D78
 * address: 0x02158D78
 * packet: pkt_ov010_02158D78
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * The null pointer local is the branch condition, not parameter b.
 * Lever: a-null-pointer-local-tested-reuses-the-movs-flags.md.
 * Extent follower 0x02158D90 already has its own matched shard.
 * symbols:
 *   func_0204A1BC 0x0204A1BC arm
 */
extern int func_0204A1BC(int, int, int, int);
void *func_02158D78(int a, int b) {
    void *result = 0;
    if (result == 0) result = (void *)func_0204A1BC(0x39, a, (int)result, b);
    return result;
}

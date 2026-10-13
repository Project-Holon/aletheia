/*
 * function: SCRIPT_SYS_LoadScriptFile
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
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 */
extern int ARC_UTIL_LoadMember(int, int, int, int);
void *SCRIPT_SYS_LoadScriptFile(int a, int b) {
    void *result = 0;
    if (result == 0) result = (void *)ARC_UTIL_LoadMember(0x39, a, (int)result, b);
    return result;
}

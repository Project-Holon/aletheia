/*
 * function: func_021D7EF0
 * address: 0x021D7EF0
 * packet: pkt_ov093_021D7EF0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: nonzero/non-3 conjunction puts return 1 before the return 0 arm.
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * semantics: original compares full-word r0 with 0 and 3; no arithmetic,
 * domain bounds, narrowed input, uninitialized values or side effects.
 */
typedef unsigned int u32;
u32 func_021D7EF0(u32 mode)
{
    if (mode != 0 && mode != 3) return 1;
    return 0;
}

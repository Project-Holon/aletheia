/*
 * function: BTL_SLOT_GetRotateDstIndex
 * address: 0x021B9AC8
 * packet: pkt_ov093_021B9AC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
int BTL_SLOT_GetRotateDstIndex(int a) {
    switch (a) { case 2: return 2; case 3: return 1; default: return 0; }
}

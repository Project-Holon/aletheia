/*
 * function: WIFICLUB_IsActivePhase
 * address:  0x021BDD98
 * packet:   pkt_ov099_021BDD98
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Range test: 3 < x < 15 (signed).
 *
 * symbols:
 */
int WIFICLUB_IsActivePhase(int x) {
    if (x < 15 && x > 3) return 1;
    return 0;
}

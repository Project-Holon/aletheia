/*
 * function: BR_CODEIN_GetMenuCallbacks
 * address: 0x021E300C
 * packet: pkt_ov183_021E300C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of handed 021E2910; separately owned 021E301C follows.
 * symbols:
 *   d_021E3910 0x021E3910 data a4
 */
typedef unsigned int u32;
typedef struct { u32 a,b; } Pair;
typedef struct { u32 f0,f4; Pair callbacks; } Table;
extern const Table d_021E3910;
void BR_CODEIN_GetMenuCallbacks(Pair *out) {
    *out=d_021E3910.callbacks;
}

/*
 * function: func_021B94D8
 * address:  0x021B94D8
 * packet:   pkt_021B94D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * near miss: compiles 54 vs 56.  The original re-reads the u16 count at
 * sr+2 on every loop test (ldrh r6,[r3,#2] before adds/cmp); 1.1p1 CSEs the
 * typed ldrh into a bound register.  Forcing the reload with volatile costs
 * four extra bytes (60).  Byte-correct apart from that one ldrh.
 *
 * symbols:
 *   func_021B94C0  0x021B94C0  thumb
 * Addresses are Black-image addresses.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
int func_021B94C0(u16 *p, u16 v);
/*
 * symbols:
 *   func_021B94C0  0x021B94C0  thumb  ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
int func_021B94C0(u16 *p, u16 v);
int func_021B94D8(u16 *r, u8 *tbl, u8 *sr)
{
    int i, found = 0;
    if (*(u16 *)(sr + 2) > 0) {
        u8 *base = *(u8 **)(sr + 0x14);
        for (i = 0; i < *(u16 *)(sr + 2); i++) {
            if (tbl == base + i * 0x48)
                found = i;
        }
    }
    return func_021B94C0(r, (u16)found);
}


/*
 * function: func_021F9A1C
 * address:  0x021F9A1C
 * packet:   pkt_021F9A1C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   tbl_02203370   0x02203370  data  a1
 *   tbl_022033C8   0x022033C8  data  a1
 *   tbl_022032DE   0x022032DE  data  a1
 *   tbl_02203270   0x02203270  data  a1
 *   tbl_022032FE   0x022032FE  data  a1
 *   tbl_02203284   0x02203284  data  a1
 *
 * Touch hit test against the rectangle table of screen mode `mode`
 * (0..7; modes 0/2 and 5/7 share a table). Any other mode falls off the
 * end and hands back the first argument still in r0.
 */

typedef unsigned char u8;

extern u8 tbl_02203370[];
extern u8 tbl_022033C8[];
extern u8 tbl_022032DE[];
extern u8 tbl_02203270[];
extern u8 tbl_022032FE[];
extern u8 tbl_02203284[];

extern int func_02035C08(const void *p);

int func_021F9A1C(void *p, int mode)
{
    switch (mode) {
    case 4:
        return func_02035C08(tbl_02203370);
    case 6:
        return func_02035C08(tbl_022033C8);
    case 0:
    case 2:
        return func_02035C08(tbl_022032DE);
    case 1:
        return func_02035C08(tbl_02203270);
    case 3:
        return func_02035C08(tbl_022032FE);
    case 5:
    case 7:
        return func_02035C08(tbl_02203284);
    }
}

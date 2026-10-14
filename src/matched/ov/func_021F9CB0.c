/*
 * function: WORLDTRADE_INPUT_ClampPageChoice
 * address:  0x021F9CB0
 * packet:   pkt_021F9CB0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   tbl_022033FC   0x022033FC  data  a4
 *
 * Validate a touched entry index: 3 maps to -2; for layouts 0..8 (+0x38)
 * an index at or past the layout's entry count (first word of its 8-byte
 * row) maps to -1; anything else is returned unchanged.
 */

typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    int count;
    int f4;
} Layout;

typedef struct {
    u8 pad0[0x38];
    s16 layout;
} Obj;

extern const Layout tbl_022033FC[];

int WORLDTRADE_INPUT_ClampPageChoice(Obj *p, int v)
{
    if (v != 3) {
        if (p->layout <= 8) {
            if (v >= tbl_022033FC[p->layout].count) {
                v = -1;
            }
            return v;
        }
        return v;
    }
    return -2;
}

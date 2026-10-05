/*
 * function: func_02185934
 * address:  0x02185934
 * packet:   pkt_ov219_02185934
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note (2026-10-05, wD9r lane81): closed by writing the multiply in each mode arm with a literal
 *   factor before the stick word (`0x55 * W(0xC330)`), not a shared goto block with m. Cross-jumping
 *   rebuilds the shared mul tail; the literal-first operand order gives the image colouring.
 *
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int func_02185934(u8 *p, u32 a, u32 b)
{
    int d0, d1;
    int res = 0;
    int x = (short)W(0xC2F4);
    int y = (short)W(0xC2F8);

    if ((a & 1) || (W(0xC320) & 1)) {
        if (H(0xC31C) == 1) {
            if (H(0xC30C) == 0)
                H(0xC30C) = 1;
            else
                H(0xC30C) = 0;
        }
        return 1;
    }
    if (H(0xC30C) == 0) {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0x55 * W(0xC330));
            d1 = (u16)(0x55 * W(0xC334));
        } else {
            d0 = 0x200;
            d1 = 0x200;
        }
    } else {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0xa * W(0xC330));
            d1 = (u16)(0xa * W(0xC334));
        } else {
            d0 = 0x20;
            d1 = 0x20;
        }
    }
    if ((b & 0x20) || (W(0xC320) & 0x20)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) += d0;
        } else if (y < -10208) {
            W(0xC2F8) += d0;
        }
        res = 1;
    }
    if ((b & 0x10) || (W(0xC320) & 0x10)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) -= d0;
        } else if (y > -13184) {
            W(0xC2F8) -= d0;
        }
        res = 1;
    }
    if ((b & 0x40) || (W(0xC320) & 0x40)) {
        if (H(0xC31C) == 1) {
            if (x + d1 < 0x3E00)
                W(0xC2F4) += d1;
            else
                W(0xC2F4) = 0x3E00;
        } else if (x < 0x2020) {
            W(0xC2F4) += d1;
        }
        res = 1;
    }
    if ((b & 0x80) || (W(0xC320) & 0x80)) {
        if (H(0xC31C) == 1) {
            if (x - d1 > -15872)
                W(0xC2F4) -= d1;
            else
                W(0xC2F4) = -15872;
        } else if (x > 0x1300) {
            W(0xC2F4) -= d1;
        }
        res = 1;
    }
    return res;
}

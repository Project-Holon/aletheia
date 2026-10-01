/*
 * function: func_021B8690
 * address: 0x021B8690
 * packet: pkt_ov106_021B8690
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Evidence: original signed halfword loads and stores fix scroll widths.
 * ARM9 sub_02040618's legacy fourth input is forwarded only to
 * sub_02042360, whose complete three-input body does not read it;
 * this caller supplies only three inputs, so the unused fourth is omitted.
 *
 * symbols:
 *   func_021B8648 0x021B8648 thumb ov106
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021B8648(u8 *);
extern void func_02040618(u32, u32, u32);
#define H(o) (*(s16 *)(p + (o)))
#define W(o) (*(u32 *)(p + (o)))
void func_021B8690(void *unused, u8 *p)
{
    s16 step, x, y;
    if (W(0x590)) {
        func_021B8648(p);
        W(0x590) = 0;
        W(0x598) = 1;
    }
    if (W(0x598)) {
        step = H(0x556) % 24;
        if (step == 0) {
            x = H(0x564) + step;
            y = H(0x566) + step;
            H(0x560) = H(0x55e);
            H(0x562) = 1;
        } else {
            if ((H(0x55e) >= 0 && H(0x560) >= 0) ||
                (H(0x55e) < 0 && H(0x560) < 0) || H(0x562) != 0) {
                H(0x562) = 0;
                if (H(0x55e) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            } else {
                if (H(0x560) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            }
        }
        func_02040618(p[0x548], 3, x);
        func_02040618(p[0x549], 3, x);
        func_02040618(p[0x54a], 3, y);
        func_02040618(p[0x54b], 3, y);
        W(0x598) = 0;
    }
}

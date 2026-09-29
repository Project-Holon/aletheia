/*
 * function: func_021D2040
 * address:  0x021D2040
 * packet:   pkt_ov021_021D2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern void func_0204B454(u32 a, Pt *p, u32 b);
extern void func_0204B404(u32 a, Pt *p, u32 b);

int func_021D2040(u8 *w)
{
    Pt pt;

    if (w[0x4c] == 0) {
        *(s8 *)(w + 0x4d) = -4;
    }
    if (*(s8 *)(w + 0x4d) == -4) {
        *(s8 *)(w + 0x4d) = 3;
        w[0x4c] = w[0x4c] + 1;
        if (w[0x4c] == 3) {
            return 0;
        }
    }
    func_0204B454(*(u32 *)(w + 0x3c), &pt, 0);
    pt.y = pt.y - *(s8 *)(w + 0x4d);
    func_0204B404(*(u32 *)(w + 0x3c), &pt, 0);
    *(s8 *)(w + 0x4d) = *(s8 *)(w + 0x4d) - 1;
    return 1;
}

/*
 * function: func_021BE010
 * address:  0x021BE010
 * packet:   pkt_ov210_021BE010
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-04: EXACT*. Levers: func_021BEDE0 takes (p, byte) with r0 untouched;
 * counters written as `(*(u8 *)(p + K))--` / `++` (no CSE with the compare
 * load); one `return 0x19` at the end shared by the switch and the else path.
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   func_021BEDE0  0x021BEDE0  thumb ov210
 *   func_021BF728  0x021BF728  thumb ov210
 *   func_021BFF30  0x021BFF30  thumb ov210
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  func_020355C4(void);
extern int  func_021BEDE0(void *, int);
extern void func_021BF728(void *, int);
extern void func_021BFF30(void *, int, int);

int func_021BE010(u8 *p)
{
    if (*(u8 *)(p + 0x2C0) == 0) {
        switch (*(u8 *)(p + 0x2C2)) {
        case 0:
        case 2:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 1);
                *(u8 *)(p + 0x2C3) = 4;
                (*(u8 *)(p + 0x2C2))++;
            } else {
                (*(u8 *)(p + 0x2C3))--;
            }
            break;
        case 1:
        case 3:
            if (*(u8 *)(p + 0x2C3) == 0) {
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 2);
                *(u8 *)(p + 0x2C3) = 4;
                (*(u8 *)(p + 0x2C2))++;
            } else {
                (*(u8 *)(p + 0x2C3))--;
            }
            break;
        case 4:
            if (func_020355C4() == 1)
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 1);
            else
                func_021BFF30(p, *(u8 *)(p + 0x2C1), 3);
            return *(u32 *)(p + 0x1C);
        }
    } else if (func_021BEDE0(p, *(u8 *)(p + 0x2C1)) == 0) {
        if (*(u32 *)(p + 0x1E0) != 0)
            func_021BF728(p, 0);
        return *(u32 *)(p + 0x1C);
    }
    return 0x19;
}

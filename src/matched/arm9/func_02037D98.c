/*
 * function: func_02037D98
 * address:  0x02037D98
 * packet:   pkt_02037D98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   lbl_020A7A20    0x020A7A20  data
 *   lbl_021469D0    0x021469D0  data
 *   func_02038AE0   0x02038AE0  arm
 *   func_0203D6BC   0x0203D6BC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S02037D98 {
    u32 f0;
    u8 pad04[0x1b0 - 4];
    int f1B0;
    u8 pad1B4[0x1d5 - 0x1b4];
    u8 f1D5;
};

extern u8 lbl_020A7A20[];
extern struct S02037D98 *lbl_021469D0;
extern int func_02038AE0(u32 a, u32 b, u32 c, u32 d);
extern int func_0203D6BC(void);

int func_02037D98(int a)
{
    int r = 0;
    if (lbl_020A7A20[1] != 4)
        return r;
    if (a != 0) {
        struct S02037D98 *p = lbl_021469D0;
        if (p->f1B0 > 0)
            return r;
        if (func_02038AE0(p->f0, (u32)p + 0xcc, func_0203D6BC(), p->f1D5) != 0) {
            struct S02037D98 *q = lbl_021469D0;
            q->f1D5++;
        }
        lbl_020A7A20[1] = 0;
        r = 1;
    } else {
        struct S02037D98 *p = lbl_021469D0;
        if (func_02038AE0(p->f0, (u32)p + 0xcc, func_0203D6BC(), p->f1D5) != 0) {
            struct S02037D98 *q = lbl_021469D0;
            q->f1D5++;
            lbl_020A7A20[1] = 0;
            r = 1;
        }
    }
    return r;
}

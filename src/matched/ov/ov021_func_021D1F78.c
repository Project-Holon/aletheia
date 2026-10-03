/*
 * function: func_021D1F78
 * address:  0x021D1F78
 * packet:   pkt_ov021_021D1F78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_020185F0  0x020185F0  thumb
 *   func_0202D7C8  0x0202D7C8  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_0202D934  0x0202D934  thumb
 *   func_0202D8D0  0x0202D8D0  thumb
 *   func_0202D9A4  0x0202D9A4  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   d_021DD60C     0x021DD60C  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h[4];
} Tbl;

extern Tbl d_021DD60C;

extern u32 func_0204B100(u32 a, u32 b, u32 c);
extern u32 func_020185F0(u32 a);
extern u32 func_0202D7C8(u32 a);
extern u32 func_02017DBC(u32 a);
extern u32 func_0202D934(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0202D8D0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key);
extern void func_02017DE4(u32 a, u32 b);
extern void func_02049238(u32 a);
extern u32 func_0204B294(u32 a, u32 b, u32 c, u32 d, Tbl *e, u32 f, u32 g);

void func_021D1F78(u32 *w)
{
    u32 r4, r7, t;
    Tbl buf;

    w[0x38 / 4] = func_0204B100(1, 0, 0x15);
    r4 = func_020185F0(w[0x14 / 4]);
    r7 = func_0202D7C8(0x15);
    t = func_02017DBC(r4);
    w[0x40 / 4] = func_0202D934(r7, r4, 0, 0, 0x15);
    w[0x44 / 4] = func_0202D8D0(r7, r4, 0, 0, 0x60, 0x15);
    w[0x48 / 4] = func_0202D9A4(r4, 0, 1, 0, 0x15);
    func_02017DE4(r4, t);
    func_02049238(r7);
    buf = d_021DD60C;
    w[0x3c / 4] = func_0204B294(w[0x38 / 4], w[0x40 / 4], w[0x44 / 4], w[0x48 / 4], &buf, 0, 0x15);
}

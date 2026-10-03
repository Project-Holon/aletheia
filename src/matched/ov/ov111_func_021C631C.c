/*
 * function: func_021C631C
 * address:  0x021C631C
 * packet:   pkt_ov111_021C631C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021C876C     0x021C876C  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
} Work;

struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern const u8 d_021C876C[];

void func_021C631C(Work *p, void **bg)
{
    int i;

    if (p->f3034 != 0) {
        func_02045374(bg[6]);
        func_02045334(bg[6]);
    } else {
        for (i = 0; i <= 5; i++) {
            if (d_021C876C[i] != 0) {
                func_02045374(bg[i]);
                func_02045334(bg[i]);
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(4);
}

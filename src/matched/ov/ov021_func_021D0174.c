/*
 * function: func_021D0174
 * address:  0x021D0174
 * packet:   pkt_ov021_021D0174
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   data_021DB8C4  0x021DB8C4  data  a2
 *   data_021DB8CC  0x021DB8CC  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021ABE24(u32 a);
extern u32 func_02046E24(u32 a, u32 b);
extern void func_02046FF8(void);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern const u16 data_021DB8CC[];
extern const u16 data_021DB8C4[];

typedef struct B {
    u32 f0;
    u32 f4[4 + 4];
    u32 f24[4];
    u32 f34[8];
} B;

void func_021D0174(B *p, int i)
{
    u32 x;
    const u16 *s;
    const u16 *t;
    int j;

    x = func_021ABE24(p->f0);
    s = data_021DB8CC;
    if (p->f4[i] == 0) {
        p->f4[i] = func_02046E24(x, s[i]);
        func_02046FF8();
        p->f34[i] = func_02047400(p->f4[i], 0, p->f4[i]);
    }
    t = data_021DB8C4;
    for (j = 0; j < 4; j++, t++) {
        if (p->f24[j] == 0) {
            p->f24[j] = func_02046E24(x, *t);
        }
    }
}

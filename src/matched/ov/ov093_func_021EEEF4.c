/*
 * function: func_021EEEF4
 * address:  0x021EEEF4
 * packet:   pkt_ov093_021EEEF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F39D8  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   func_021EF1CC  0x021EF1CC  thumb  ov093
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 pad;
    u32 pad2;
} E;

typedef struct {
    void (*fn)(u32, u32, u32);
    u32 pad;
} F;

extern E d_021F39D8[];
extern F d_021F39DC[];
extern void func_021EF1CC(u32 a, u32 b, u32 c);

void func_021EEEF4(u32 a, u16 b, u32 c)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (b == d_021F39D8[i].id) {
            d_021F39DC[i].fn(a, b, c);
            return;
        }
    }
    func_021EF1CC(a, b, c);
}

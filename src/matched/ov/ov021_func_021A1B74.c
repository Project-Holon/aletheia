/*
 * function: func_021A1B74
 * address:  0x021A1B74
 * packet:   pkt_ov021_021A1B74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A20C8  0x021A20C8  thumb  ov021
 *   func_021A1C04  0x021A1C04  thumb  ov021
 *   func_021A1BF8  0x021A1BF8  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u32 d_021D886C[];
extern const u32 d_021D8868[];
struct O;
extern void func_021A20C8(struct O *p);
extern void func_021A1C04(u8 *p);
extern void func_021A1BF8(void *p, u32 v);
extern void func_021A1FEC(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);

void func_021A1B74(u8 *p, int a, int f)
{
    int i;
    u32 t;

    if (a == *(u16 *)(p + 0xc) && a != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        func_021A20C8((struct O *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    func_021A1C04(p);
    *(u16 *)(p + 0xa) = 0;
    func_021A1BF8(p, d_021D886C[a * 2]);
    t = d_021D8868[a * 2];
    func_021A1FEC((struct O *)(*(u32 *)(p + 0x20)), t, 0, 0, 1, 1, f);
    *(u16 *)(p + 0xc) = a;
    *(u16 *)(p + 0xe) = 0xFFFF;
}

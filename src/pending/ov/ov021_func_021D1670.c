/*
 * function: func_021D1670
 * address:  0x021D1670
 * packet:   pkt_ov021_021D1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_02012F8C is an unlabelled arm9 leaf (Ilias's, not filed here);
 * its relocation has no outside witness. Verified C for the leaf (EXACT, arm9,
 * thumb, -O4,p; symbols: func_02009448 0x02009448 thumb):
 *   u32 func_02012F8C(u32 *p) { return func_02009448(*p); }
 * Re-run this file once the leaf's shard exists.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F8C  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_0215A5E4(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_02012F8C(u32 a);
extern u32 func_020092EC(void);
extern u32 func_020092D8(u32 a);

int func_021D1670(u32 a, u32 b)
{
    u32 r7;
    u32 r6;
    u16 *r4;
    u32 r5;

    func_0215A5F4(b);
    func_0215A5DC(b);
    r7 = func_0215A5E4(b);
    r6 = func_02159B10(a, b);
    func_02159B10(a, b);
    func_02159B10(a, b);
    r4 = func_02159AE8(a, b);
    r5 = func_02012F8C(r7);
    if (r6 == 0) {
        if (func_020092EC() == 1 && func_020092D8(r5) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
    }
    return 0;
}

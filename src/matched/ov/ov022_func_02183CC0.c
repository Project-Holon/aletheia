/*
 * function: func_02183CC0
 * address:  0x02183CC0
 * packet:   pkt_ov022_02183CC0
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0217410C  0x0217410C  thumb  ov011
 *   func_021840A4  0x021840A4  thumb  ov022
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0203D1C0(u32 index);
extern int func_0217410C(int a, int b);
extern void func_021840A4(u8 *s, int i);

void func_02183CC0(u8 *s)
{
    int i;
    u32 m;
    u32 r;
    u8 t;

    r = s[1];
    if (s[0x10] == 0xff) {
        for (i = 0; i < 5; i++) {
            m = 1 << i;
            if (s[1] & m) {
                if (func_0203D1C0((u8)i) == 0) {
                    r ^= m;
                }
            }
        }
        if (r != s[1]) {
            t = r;
            for (i = 0; i < 5; i++) {
                m = 1 << i;
                if (s[1] & m) {
                    if (!(r & m)) {
                        if (func_0217410C(t, i & 0xff) == 1) {
                            func_021840A4(s, (u8)i);
                            s[1] = s[1] ^ (u8)m;
                        }
                    }
                }
            }
        }
    }
}

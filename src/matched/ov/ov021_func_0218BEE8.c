/*
 * function: func_0218BEE8
 * address:  0x0218BEE8
 * packet:   pkt_ov021_0218BEE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_0218B924  0x0218B924  thumb  ov021
 *   func_0218BC00  0x0218BC00  thumb  ov021
 *   func_0218BC10  0x0218BC10  thumb  ov021
 *   func_0218BC8C  0x0218BC8C  thumb  ov021
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data  ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_02046C94(void);
extern void func_02046CE0(void *dst, void *src);
extern void *func_0218B924(u8 *s, int x);
extern u8 *func_0218BC00(void *p, int x);
extern u8 *func_0218BC10(u8 *p, int i);
extern int func_0218BC8C(u8 *p);
extern u8 *func_0218BCAC(void *p);
extern char d_021DD9CC[];

void func_0218BEE8(u8 *s, void **out, int x)
{
    u8 *t;
    int cnt;
    int i;

    out[0] = func_0218B924(s, x);
    out[1] = func_02030734(*(u16 *)s, func_02046C94(), 1, d_021DD9CC, 0x4d0);
    func_02046CE0(out[1], func_0218BC00(*(void **)(s + 0x18), x));
    t = func_0218BCAC(out[0]);
    cnt = func_0218BC8C(t);
    for (i = 0; i < 4; i++) {
        if (i < cnt) {
            out[2 + i] = func_02030734(*(u16 *)s, func_02046C94(), 1, d_021DD9CC, 0x4db);
            func_02046CE0(out[2 + i], func_0218BC10(t, i));
        } else {
            out[2 + i] = 0;
        }
    }
}

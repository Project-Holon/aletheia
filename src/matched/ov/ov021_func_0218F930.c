/*
 * function: func_0218F930
 * address:  0x0218F930
 * packet:   pkt_ov021_0218F930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F780  0x0218F780  thumb  ov021
 *   func_0218FC80  0x0218FC80  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[3]; } B12;
typedef struct { u32 w[6]; } B24;

extern void func_0218E13C(u8 *p, u32 v);
extern void func_0218F780(u8 *p, u8 *q);
extern void func_0218FC80(void);

void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v)
{
    u8 *q;
    B24 loc;
    if (p) {
        q = p + 0xf0;
        func_0218E13C(p, 2);
        func_0218F780(p, q + 0x34);
        *(B12 *)(q + 0x64) = *(B12 *)a;
        *(B12 *)(q + 0x70) = *(B12 *)b;
        *(u16 *)(q + 0x96) = 0;
        *(u16 *)(q + 0x94) = v;
        loc.w[5] = c[5];
        loc.w[1] = 0;
        loc.w[4] = c[4];
        loc.w[2] = 0;
        loc.w[3] = 0;
        loc.w[0] = c[0];
        *(B24 *)(q + 0xa0) = loc;
        *(void **)(p + 0x1ac) = (void *)func_0218FC80;
        *(u32 *)(q + 0xb8) = 0;
        *(u32 *)(q + 0x9c) = 1;
    }
}

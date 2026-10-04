/*
 * function: func_0218FA40
 * address:  0x0218FA40
 * packet:   pkt_ov021_0218FA40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of func_0218F9C4/func_0218F930: arms the +0xf0 motion block with
 * func_0218FB1C as the per-frame callback, seeded from func_0218E260's record.
 * The two +0x70 copies are tail-merged by the compiler (a shared source
 * pointer variable compiles the same).
 *
 * symbols:
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F780  0x0218F780  thumb  ov021
 *   func_0218E260  0x0218E260  thumb  ov021
 *   func_0218FB1C  0x0218FB1C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 w[3]; } B12;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u16 pad0c[3];
    u16 h12;
    u32 pad14[2];
    u32 flag;
    B12 v;
} Rec;

extern void func_0218E13C(u8 *p, u32 v);
extern void func_0218F780(u8 *p, u8 *q);
extern void func_0218E260(void *p, void *r);
extern void func_0218FB1C(u8 *p);

void func_0218FA40(u8 *p, u16 v)
{
    u8 *q;
    Rec loc;

    if (p) {
        q = p + 0xf0;
        if (*(u32 *)(q + 0x98) != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            func_0218E260(p, &loc);
            *(u16 *)(q + 0x88) = loc.b;
            *(u16 *)(q + 0x8a) = loc.c;
            *(u32 *)(q + 0x8c) = loc.a << 12;
            *(u16 *)(q + 0x90) = loc.h12;
            if (loc.flag != 0) {
                *(B12 *)(q + 0x7c) = loc.v;
                *(B12 *)(q + 0x70) = **(B12 **)(p + 0x18);
            } else {
                *(u32 *)(q + 0x7c) = 0;
                *(u32 *)(q + 0x80) = 0;
                *(u32 *)(q + 0x84) = 0;
                *(B12 *)(q + 0x70) = loc.v;
            }
            *(u16 *)(q + 0x96) = 0;
            *(u16 *)(q + 0x94) = v;
            *(u32 *)(q + 0xa0) = 1;
            *(u32 *)(q + 0xa4) = 1;
            *(u32 *)(q + 0xa8) = 1;
            *(u32 *)(q + 0xac) = 1;
            *(u32 *)(q + 0xb0) = 1;
            *(u32 *)(q + 0xb4) = 1;
            *(void **)(p + 0x1ac) = (void *)func_0218FB1C;
            *(u32 *)(q + 0xb8) = 0;
            *(u32 *)(q + 0x9c) = 1;
        }
    }
}

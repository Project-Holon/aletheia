/*
 * function: func_021BE010
 * address: 0x021BE010
 * packet: pkt_ov209_021BE010
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C940C 0x021C940C thumb ov212
 *   func_0204BA20 0x0204BA20 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021BD908 0x021BD908 thumb ov209
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   d_021BE9A4 0x021BE9A4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R { u16 f0; u16 f2; u32 f4; u32 f8; u32 fC; u32 f10; u16 f14; u16 f16; };
extern const struct R d_021BE9A4;
extern u32 func_021C940C(u32, const void *, u16);
struct Actor;
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021BD908(char *, u32, u32);
extern void func_021BD8D8(char *, u32, u32);
void func_021BE010(char *p) {
    struct R a;
    struct R b;
    u32 *pb;
    u32 i;
    u32 j;
    u32 k;
    a = d_021BE9A4;
    b = d_021BE9A4;
    b.fC = *(u32 *)(p + 0xBF4);
    b.f10 = *(u32 *)(p + 0xC0C);
    for (i = 0; i < 16; i++) {
        b.f2 = i * 0x18 + 8;
        b.f8 = *(u32 *)(p + i * 4 + 0xB64);
        *(u32 *)(p + i * 4 + 0xA9C) = func_021C940C(*(u32 *)(p + 0xA70), &b, 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + i * 4 + 0xA9C)), 0);
    }
    b = a;
    b.fC = *(u32 *)(p + 0xBF8);
    b.f10 = *(u32 *)(p + 0xC10);
    for (j = 0; j < 16; j++) {
        b.f2 = j * 0x18 + 0x20;
        b.f8 = *(u32 *)(p + j * 4 + 0xBA4);
        b.f16 = 1;
        *(u32 *)(p + j * 4 + 0xADC) = func_021C940C(*(u32 *)(p + 0xA70), &b, 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + j * 4 + 0xADC)), 0);
        func_021BD908(p, j + 0x1a, 1);
        pb = (u32 *)(p + 0xA70);
        *(u32 *)(p + j * 4 + 0xB1C) = func_021C940C(*pb, &b, 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 2);
    }
    for (k = 0; k < 16; k++) func_021BD8D8(p, k + 0xa, 0);
    for (i = 0; i < 16; i++) {
        func_021BD8D8(p, i + 0x1a, 0);
        func_021BD8D8(p, i + 0x2a, 0);
    }
}

/*
 * function: func_021C278C
 * address:  0x021C278C
 * packet:   pkt_ov217_021C278C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C28EC  0x021C28EC  thumb  ov217
 *   func_021C28DC  0x021C28DC  thumb  ov217
 *   func_021C28CC  0x021C28CC  thumb  ov217
 *   func_021C28BC  0x021C28BC  thumb  ov217
 *   func_021C28A4  0x021C28A4  thumb  ov217
 *   func_021C2894  0x021C2894  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0204B404(void *h, u16 *pos, u32 v);
extern void func_0204B878(void *h, u32 v);
extern void func_0204B8C4(void *h, u32 v);
extern void func_0204B974(void *h);
extern void func_0204B3DC(void *h, u32 v);
extern void func_021C28EC(void *p, u16 *a, u16 *b);
extern void func_021C28DC(void *p, u16 *a, u16 *b);
extern void func_021C28CC(void *p, u16 *a, u16 *b);
extern u32 func_021C28BC(void *p);
extern u32 func_021C28A4(void *p);
extern u32 func_021C2894(void *p);

void func_021C278C(u8 *p)
{
    u32 z = 0;
    void *h = *(void **)(p + 0x10);
    u8 *q = p + 0x20;
    u16 pos[2];

    pos[0] = *(u32 *)(p + 4);
    pos[1] = *(u32 *)(p + 8);

    func_0204B404(h, pos, *(u16 *)(q + 0xc));
    func_0204B878(h, *(u16 *)(q + 0x10));

    func_0204B8C4(h, 0);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = *(void **)(p + 0x14);
    func_021C28EC(p, pos, pos + 1);
    func_0204B404(h, pos, *(u16 *)(q + 0xc));
    func_0204B878(h, *(u16 *)(q + 0xe));
    func_0204B8C4(h, func_021C28BC(p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = *(void **)(p + 0x18);
    func_021C28DC(p, pos, pos + 1);
    func_0204B404(h, pos, *(u16 *)(q + 0xc));
    func_0204B878(h, *(u16 *)(q + 0xe));
    func_0204B8C4(h, func_021C28A4(p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = *(void **)(p + 0x1c);
    func_021C28CC(p, pos, pos + 1);
    func_0204B404(h, pos, *(u16 *)(q + 0xc));
    func_0204B878(h, *(u16 *)(q + 0xe));
    func_0204B8C4(h, func_021C2894(p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, z);
}

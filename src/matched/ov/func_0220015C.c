/*
 * function: func_0220015C
 * address:  0x0220015C
 * packet:   pkt_0220015C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *
 * Straight-line six-argument window setup over a 0x60x0x48 handle: the
 * handle open, three B40/B68 window calls, two F5BC text calls and two
 * 498F4 draws, ending with the 49238 release.  No parameters.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020498F4(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02049238(void *h);

void func_0220015C(void)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 3, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xd, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x20, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
}

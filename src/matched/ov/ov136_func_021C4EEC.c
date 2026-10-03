/*
 * function: func_021C4EEC
 * address: 0x021C4EEC
 * packet: pkt_ov136_021C4EEC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): byte-correct; only the ABS32 word for func_021C4534 (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216B4 0x020216B4 thumb
 *   func_02021640 0x02021640 thumb
 *   func_0201F548 0x0201F548 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02049238 0x02049238 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
 *   func_021C4534 0x021C4534 thumb ov136
 *   func_021C4528 0x021C4528 thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(int, int);
extern void func_0201F5BC(u32, u32, u32, u32, u32);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u32);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_02021518(u32 heap);
extern void func_0202155C(u32 h, u32 a, u32 b, u32 heap);
extern void func_020216B4(u32 a, void *h, u32 b, u32 heap, u32 c, u32 d, u32 e);
extern void func_02021640(u32 a, u32 b, u32 c, u32 heap, u32 d, u32 e, u32 f);
extern u32 func_0201F548(u32 a);
extern void func_0201DD68(void);
extern void func_02049238(void *h);
extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(u32 layer);
extern void func_020434DC(u32, u32);
extern int func_021C4534(void);
extern int func_021C4528(void);

void func_021C4EEC(u8 *p)
{
    u32 k = (*(u8 **)(p + 0x1C))[0xB];
    void *h = func_020490F4(0x9B, (u16)*(u32 *)p);
    u32 sz;
    u32 pal;
    u32 chr;

    func_0201F5BC(0, 1, 4, 0, (u16)*(u32 *)p);
    func_0201F5BC(0, 0xD, 6, 0, (u16)*(u32 *)p);
    pal = k + 0xC;
    func_02049658(h, pal, 3, 0, 0, 1, (u16)*(u32 *)p);
    func_02049658(h, pal, 4, 0, 0, 1, (u16)*(u32 *)p);
    chr = k + 0x18;
    sz = 0x800;
    func_020498F4(h, chr, 3, 0, sz, 1, (u16)*(u32 *)p);
    func_020498F4(h, chr, 4, 0, sz, 1, (u16)*(u32 *)p);
    func_02049B68(h, k, 4, 0, 0, (u16)*(u32 *)p);
    func_02049B40(0x17, 5, 0, 0xA0, 0x20, (u16)*(u32 *)p);
    *(u32 *)(p + 0x38) = func_02021518(*(u32 *)p);
    func_0202155C(*(u32 *)(p + 0x38), 0, 0xE0, (u16)*(u32 *)p);
    func_020216B4(*(u32 *)(p + 0x38), h, k, (u16)*(u32 *)p, 0, 0x60, 0);
    func_02021640(*(u32 *)(p + 0x38), 0x17, 7, (u16)*(u32 *)p, 0, 0x20, 0x30);
    func_02021640(*(u32 *)(p + 0x38), 0x17, 5, (u16)*(u32 *)p, 0, 0x20, 0x50);
    func_02021640(*(u32 *)(p + 0x38), 5, func_0201F548(0), (u16)*(u32 *)p, 0, 0x20, 0x40);
    func_02021640(*(u32 *)(p + 0x38), 5, func_0201F548(1), (u16)*(u32 *)p, 0, 0x20, 0x60);
    func_0201DD68();
    func_02049238(h);
    func_02041300(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    func_02041B6C(4);
    func_020434DC(1, 1);
    func_020434DC(2, 1);
    func_020434DC(8, 1);
    if (p[0xB] != 0) {
        h = func_020490F4(0x9B, (u16)*(u32 *)p);
        func_020498F4(h, 0x24, 2, 0, sz, 1, (u16)*(u32 *)p);
        func_02049238(h);
        *(void **)(p + 0x3C) = (void *)func_021C4534;
        *(void **)(p + 0x40) = (void *)func_021C4528;
        func_020434DC(4, 1);
    }
}

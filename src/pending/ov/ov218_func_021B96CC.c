/*
 * function: func_021B96CC
 * address:  0x021B96CC
 * packet:   pkt_ov218_021B96CC
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wD2 lane07): first draft, DIFF, 342 vs 340 bytes; every instruction matches except one register swap:
 *   original holds a = 0x81 - i in r5 and buf in r6, compiler gives a r6 and buf r5 (all uses follow). Semantics: 0x82 slots, 8 bytes of 0xff
 *   at buf + col + row*32 + 0x20 where col = (u8)((u8)((3 - a % 4) * 2) * 4), row = (u8)(a / 4). Lever notes: declare w2/w1 and o2/o1 in
 *   that order (slots), `col` as its own statement before `off`, add 0x20 to the row part before adding col. Tried with no effect on the swap:
 *   decl order of a/buf/i, buf block-local, buf stored via q pointer or buf[off + k], a replaced by the expression (the sub then sinks into the if).
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049DF4(void *, int, int, void **, u16);
extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern void func_020307B0(void *);
extern void func_02049238(void *);
void func_021B96CC(u8 *p, u16 heap)
{
    void *h;
    void *w2;
    void *w1;
    u8 *o2;
    u8 *o1;
    int a;
    int i;
    h = func_020490F4(0xc1, heap);
    func_02049B68(h, 1, 0, 0, 0xe0, heap);
    func_02049B68(h, 1, 4, 0, 0xe0, heap);
    func_02049658(h, 0xc, 4, 0, 0x200, 0, heap);
    func_020498F4(h, 6, 7, 0, 0, 0, heap);
    func_020498F4(h, 0xd, 4, 0, 0, 0, heap);
    w1 = func_02049DF4(h, 0, 0, (void **)&o1, heap);
    func_020498F4(h, 5, 3, 0, 0, 0, heap);
    w2 = func_02049DF4(h, 0, 0, (void **)&o2, heap);
    func_02049658(h, 2, 2, 0, 0, 0, heap);
    func_02049658(h, 2, 6, 0, 0, 0, heap);
    for (i = 0; i < 0x82; i++) {
        a = 0x81 - i;
        u8 *buf = *(u8 **)(((i < 0x32) ? o1 : o2) + 0x14);
        if (*(u32 *)(p + 0x34 + i * 4) == 0) {
            u32 col = (u8)((u8)((3 - a % 4) * 2) * 4);
            u32 off = col + (((u8)(a / 4) << 5) + 0x20);
            buf[off] = 0xff;
            buf[off + 1] = 0xff;
            buf[off + 2] = 0xff;
            buf[off + 3] = 0xff;
            buf[off + 4] = 0xff;
            buf[off + 5] = 0xff;
            buf[off + 6] = 0xff;
            buf[off + 7] = 0xff;
        }
    }
    func_02040B1C(7, *(void **)(o1 + 0x14), *(u32 *)(o1 + 0x10), 0);
    func_020307B0(w1);
    func_02040B1C(3, *(void **)(o2 + 0x14), *(u32 *)(o2 + 0x10), 0);
    func_020307B0(w2);
    func_02049238(h);
}

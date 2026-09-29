/*
 * function: func_021BB380
 * address:  0x021BB380
 * packet:   pkt_ov088_021BB380
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 *
 * symbols:
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   d_021BD5EC     0x021BD5EC  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u16 f0;
    u16 f2;
};

extern const struct Ent d_021BD5EC[];

extern void *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(void *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(void *mgr, u32 idx, void *a);

void func_021BB380(char *p)
{
    u32 i;

    *(void **)(p + 0x118) = func_0202C9B4(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        func_0202CA3C(*(void **)(p + 0x118), i, 1, 0x1a, d_021BD5EC[i].f2);
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0x80));
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0x88));
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0x90));
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0x98));
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0xa0));
    func_0202CEBC(*(void **)(p + 0x118), 0, *(void **)(p + 0xa8));
    func_0202CEBC(*(void **)(p + 0x118), 1, *(void **)(p + 0xb0));
    func_0202CEBC(*(void **)(p + 0x118), 2, *(void **)(p + 0xb8));
    func_0202CEBC(*(void **)(p + 0x118), 3, *(void **)(p + 0xc0));
    func_0202CEBC(*(void **)(p + 0x118), 4, *(void **)(p + 0xc8));
    func_0202CEBC(*(void **)(p + 0x118), 5, *(void **)(p + 0xd0));
    func_0202CEBC(*(void **)(p + 0x118), 6, *(void **)(p + 0xd8));
    func_0202CEBC(*(void **)(p + 0x118), 7, *(void **)(p + 0xe0));
}

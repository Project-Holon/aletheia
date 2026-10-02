/*
 * function: func_02200B34
 * address:  0x02200B34
 * packet:   pkt_02200B34
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
 *   func_02049658  0x02049658  arm
 *   func_020499D4  0x020499D4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_020499D4(void *h, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_0204B3DC(u32 v, int k);

void func_02200B34(u8 *p)
{
    void *h;

    if (*(u32 *)(p + 0x12e0) == 1 && *(u32 *)(p + 0x12e4) == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049B68(h, 5, 4, 0, 0x20, 0x48);
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020499D4(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        func_02049238(h);
    }
    func_0204B3DC(*(u32 *)(p + 0xd38), 1);
}

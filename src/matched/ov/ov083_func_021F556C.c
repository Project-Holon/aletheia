/*
 * function: func_021F556C
 * address:  0x021F556C
 * packet:   pkt_ov083_021F556C
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F184  0x0201F184  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190844  0x02190844  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Slot;
struct WordSet;
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190844(struct Slot **p, int x, int y, u32 z);

void func_021F556C(char *p, u32 a1, u32 a2, int a3, u8 a4)
{
    func_0201F184((struct WordSet *)(*(u32 *)(p + 0x2C)), 0, a2);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x2C)), 1, a3 / 60, 2, 1, 1);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x2C)), 2, a3 % 60, 2, 2, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x2C)), (void *)(*(u32 *)(p + 0x38)), (void *)a1);
    func_02190844((struct Slot **)(*(u32 *)(p + 0x18)), 8, (u16)(a4 << 4), *(u32 *)(p + 0x38));
}

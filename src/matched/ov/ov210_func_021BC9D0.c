/*
 * function: func_021BC9D0
 * address:  0x021BC9D0
 * packet:   pkt_021BC9D0
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_02049238 0x02049238 arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CodeIn;
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void func_02049238(void *);

void func_021BC9D0(int p)
{
    void *h = func_020490F4(0x9f, 0x807b);

    *(int *)(p + 0x2b4) = (int)func_0202E940(0x30, 0x10, 1, 0x7b);
    func_0202E9AC((struct CodeIn *)(*(int *)(p + 0x2b4)), h, 0x49, 0x20, 0x30);
    func_02049238(h);
}

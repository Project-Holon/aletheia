/*
 * function: ov208_func_021C0090
 * address:  0x021C0090
 * packet:   pkt_ov208_021C0090
 * region:   ov208
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
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);

void ov208_func_021C0090(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x55, *heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, *heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, *heap);
    func_02049658(h, 5, 2, 0, 0x4000, 0, *heap);
    func_02049658(h, 7, 3, 0, 0xc000, 0, *heap);
    func_020498F4(h, 0x11, 2, 0, 0x800, 0, *heap);
    func_020498F4(h, 0x10, 3, 0, 0x800, 0, *heap);
    func_02049238(h);
}

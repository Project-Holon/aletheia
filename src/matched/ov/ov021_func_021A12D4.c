/*
 * function: func_021A12D4
 * address:  0x021A12D4
 * packet:   pkt_ov021_021A12D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *
 * Lever: func_020490F4 takes (id, heap); passing x as its second argument
 * is what gives x its register before the constant's.
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void func_02049990(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 heap);
extern void func_02049238(void *h);
typedef unsigned char  u8;
struct St021D3244;
extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32 a, int b, int c, int d, int e, int f);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);

void func_021A12D4(u32 *p, u32 x)
{
    void *h = func_020490F4(0x47, x);
    func_02049BDC(h, 0, 0, 0x140, 0x140, 0x20, x);
    func_02049658(h, 3, 1, 0x64, 0, 0, x);
    func_02049990(h, 0xf, 1, 0, 0x64, 0, 0, x);
    func_02049238(h);
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, -6);
    func_021D3244((struct St021D3244 *)func_02188E30((u8 *)p[5]), 1, 1);
}

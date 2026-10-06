/*
 * function: func_021B7C68
 * address: 0x021B7C68
 * packet: pkt_ov103_021B7C68
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_021B7D58 0x021B7D58 thumb ov103
 *   func_021B7DFC 0x021B7DFC thumb ov103
 *   d_021B9228 0x021B9228 data a4
 *   d_021B9234 0x021B9234 data a4
 *   d_021B9240 0x021B9240 data a4
 *   d_021B9218 0x021B9218 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_02046440(int, int, int, int, int, int, void *);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void *func_020490F4(unsigned int id, int heap);
extern void func_02049238(void *);
extern void func_021B7D58(void);
extern void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4);
extern u8 d_021B9228[];
extern u8 d_021B9234[];
extern u8 d_021B9240[];
extern u8 d_021B9218[];

void func_021B7C68(u8 *p, int heap)
{
    void *arc;
    func_02046440(0, 1, 0, 1, 0, heap, (void *)func_021B7D58);
    *(int *)p = func_02048A24(2, 6 << 14, 0xFFFE8000, 0xFFFE0000, 1 << 17, 1 << 12, 250 << 14, 0,
                              d_021B9228, d_021B9234, d_021B9240, heap);
    arc = func_020490F4(0x5e, heap);
    func_021B7DFC(p + 4, (int)arc, (const u16 *)d_021B9218, 1, heap);
    func_021B7DFC(p + 0x64, (int)arc, (const u16 *)d_021B9218, 2, heap);
    func_02049238(arc);
}

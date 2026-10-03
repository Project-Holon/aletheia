/*
 * function: func_021F0760
 * address:  0x021F0760
 * packet:   pkt_ov033_021F0760
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);

void func_021F0760(char *p)
{
    unsigned h = *(unsigned short *)(p + 2);
    void *a = func_020490F4(0xC3, h);
    unsigned b;
    func_02049BDC(a, 0, 4, 0, 0, 0x40, h);
    b = func_02049740(a, 2, 7, 0, 0, h);
    func_02049990(a, 7, 7, 0, (unsigned short)b, 0, 0, h);
    func_02049238(a);
    func_020413B0(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    *(unsigned *)(p + 0x10) = b;
}

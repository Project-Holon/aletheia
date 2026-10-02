/*
 * function: func_021F2234
 * address:  0x021F2234
 * packet:   pkt_ov032_021F2234
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2234 0x021F2234 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F36A0 0x021F36A0 data ov032 a1
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188E30 0x02188E30 thumb ov021
 *   func_020490F4 0x020490F4 arm
 *   func_021F27D4 0x021F27D4 thumb ov032
 *   func_021F2908 0x021F2908 thumb ov032
 *   func_021F2A8C 0x021F2A8C thumb ov032
 *   func_021F2C1C 0x021F2C1C thumb ov032
 *   func_021F2D20 0x021F2D20 thumb ov032
 *   func_021F2F44 0x021F2F44 thumb ov032
 *   func_021F3058 0x021F3058 thumb ov032
 *   func_021EFEC0 0x021EFEC0 thumb ov032
 *   func_021F0208 0x021F0208 thumb ov032
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char d_021F36A0[];
extern void *func_02030734(u32 heap, u32 size, u32 flag, const char *file, u32 line);
extern u32 func_020120F4(u32 a);
extern u32 func_0201210C(u32 a);
extern u32 func_02188E30(u32 a);
extern u32 func_020490F4(u32 a, u32 b);
extern void func_021F27D4(char *p);
extern void func_021F2908(char *p);
extern void func_021F2A8C(char *p, u32 a);
extern void func_021F2C1C(char *p);
extern void func_021F2D20(char *p, u32 a);
extern void func_021F2F44(char *p, u32 a);
extern void func_021F3058(char *p);
extern void func_021EFEC0(char *p);
extern void func_021F0208(char *p, int flag);

char *func_021F2234(u32 a0, u32 a1)
{
    char *p;
    u32 v;

    p = func_02030734(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    *(u32 *)(p + 0x0) = a0;
    *(u32 *)(p + 0x4) = func_020120F4(a0);
    *(u32 *)(p + 0x8) = v = func_0201210C(a0);
    *(u32 *)(p + 0x10) = func_02188E30(v);
    *(u32 *)(p + 0xc) = a1;
    *(u16 *)(p + 0x98) = 0x70;
    *(u16 *)(p + 0x94) = 0x15;
    *(u16 *)(p + 0x96) = 0x8070;
    *(u32 *)(p + 0x9c) = func_020490F4(0xad, *(u16 *)(p + 0x98));
    func_021F27D4(p);
    func_021F2908(p);
    func_021F2A8C(p, *(u32 *)(p + 0x9c));
    func_021F2C1C(p);
    func_021F2D20(p, *(u32 *)(p + 0x9c));
    func_021F2F44(p, *(u32 *)(p + 0x9c));
    func_021F3058(p);
    *(u8 *)(p + 0x7a) = 1;
    func_021EFEC0(p);
    *(u8 *)(p + 0x7a) = 0;
    *(u32 *)(p + 0x60) = 0;
    func_021F0208(p, 1);
    return p;
}

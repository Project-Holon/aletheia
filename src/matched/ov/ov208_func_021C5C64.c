/*
 * function: ov208_func_021C5C64
 * address:  0x021C5C64
 * packet:   pkt_ov208_021C5C64
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C51A0  0x021C51A0  thumb
 *   func_021C51C8  0x021C51C8  thumb
 *   ov208_func_021C569C  0x021C569C  thumb
 *   func_021C4EAC  0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C51A0(u8 *mdl, u32 sys);
extern void func_021C51C8(u32 turn, int side, u8 *p);
extern void ov208_func_021C569C(void *a0, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void func_021C4EAC(void *a0, u8 *p, int key);
extern void ov208_func_021C6A10(void *a0, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ov208_func_021C5C64(void *a0, u8 *p, int key)
{
    int a;
    int b;

    func_021C51A0(p + 0x94, W(8));
    func_021C51A0(p + 0xd8, W(8));
    a = W(0x124) != 0 ? 2 : 4;
    b = W(0x124) != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, H(0x550));
    if (a != 4)
        func_021C51C8(W(0x98), 2, p);
    if (b != 4)
        func_021C51C8(W(0xdc), 3, p);
    func_021C4EAC(a0, p, key);
    ov208_func_021C6A10(a0, p, key);
}

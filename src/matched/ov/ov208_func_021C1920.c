/*
 * function: func_021C1920
 * address:  0x021C1920
 * packet:   pkt_ov208_021C1920
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_021BDBAC  0x021BDBAC  thumb  ov208
 *   func_021C0D3C  0x021C0D3C  thumb  ov208
 *   func_021C0D5C  0x021C0D5C  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C1D30  0x021C1D30  thumb  ov208
 *   func_021C2238  0x021C2238  thumb  ov208
 *   func_021BC3BC  0x021BC3BC  thumb  ov208
 *   func_021BDAAC  0x021BDAAC  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021BDC14  0x021BDC14  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021BC3B4(int key);
extern void func_021BDBAC(void *s, u32 on);
extern void func_021C0D3C(u16 *heap, u8 *p, int key);
extern u8   func_021C0D5C(u16 *heap, u8 *p, int key, u8 x, u8 y);
extern void func_0204B3DC(u32 obj, int on);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void func_021C2238(u16 *heap, u8 *p, int key);
extern u16  func_021BC3BC(char *p);
extern void func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void func_021BDBA0(void *s);
extern void func_021BDC48(void *s, u32 on);
extern int  func_021BC3A4(int key);
extern int func_02012BF8(int a0, int a1);
extern void func_021BDC14(char *p, int b);

#define W(o) (*(u32 *)(p + (o)))

void func_021C1920(u16 *heap, u8 *p, int key, int mode)
{
    void *s;
    u32 wide;

    s = func_021BC3B4(key);
    switch (W(0x6c)) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            W(0x84) = 1;
        } else if (mode == 4) {
            W(0x84) = 1;
        }
        break;
    case 1:
        if (mode == 2)
            func_021BDBAC(s, 0);
        break;
    case 2:
        if (mode == 5) {
            W(0x70) = 1;
            W(0x74) = 1;
            if (W(0x90) == 1) {
                if (W(0x7c) == 0) {
                    func_021C0D3C(heap, p, key);
                } else {
                    p[0x79] = func_021C0D5C(heap, p, key, p[0x80], p[0x81]);
                    if (p[0x79] != 0xff)
                        func_0204B3DC(W(0xd0), 1);
                }
                func_021C1D30(heap, p, key);
                func_021C2238(heap, p, key);
            }
            func_021BDAAC(s, 1, 1, func_021BC3BC((char *)key) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (W(0x42c) != 0) {
                W(0x430) = 1;
                if (W(0x434) != 0) {
                    W(0x42c) = 0;
                    func_021BDBA0(s);
                }
            }
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48(s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            W(0x84) = 1;
        }
        break;
    case 6:
        if (mode == 7)
            func_021BDBAC(s, 0);
        break;
    case 7:
        if (mode == 0) {
            W(0x70) = 3;
            W(0x74) = 3;
            func_0204B3DC(W(0xcc), 0);
            func_0204B3DC(W(0xd0), 0);
            wide = func_021BC3BC((char *)key) > 1 ? 1 : 0;
            func_021BDAAC(s, 0, 1, wide);
            func_021BDC14(s, func_02012BF8(func_021BC3A4(key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            func_021BDBA0(s);
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48(s, 1);
        }
        break;
    }
    W(0x6c) = mode;
}

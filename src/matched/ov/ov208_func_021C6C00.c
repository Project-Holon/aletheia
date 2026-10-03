/*
 * function: ov208_func_021C6C00
 * address:  0x021C6C00
 * packet:   pkt_ov208_021C6C00
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035D20  0x02035D20  arm
 *   func_021BDC48  0x021BDC48  thumb
 *   func_0204B404  0x0204B404  arm
 *   ov208_func_021C6DD8  0x021C6DD8  thumb
 *   ov208_func_021C6E60  0x021C6E60  thumb
 *   ov208_func_021C5C64  0x021C5C64  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_021BC3B4(int key);
extern u32  func_02035CB8(u32 *x, u32 *y);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021BDC48(void *scene, u32 on);
extern void func_0204B404(u32 obj, s16 *pos, int flag);
extern u16  ov208_func_021C6DD8(u16 n, u8 x);
extern u16  ov208_func_021C6E60(void *a0, u8 *p, int key, u16 skip, u16 want);
extern void ov208_func_021C5C64(void *a0, u8 *p, int key);
extern void func_020061E4(u32 a);
extern void func_020355D8(u8 v);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

u32 ov208_func_021C6C00(void *a0, u8 *p, int key)
{
    u32 x;
    u32 y;
    s16 pos[2];
    void *scene;
    int moved;
    u16 old;

    scene = func_021BC3B4(key);
    moved = 0;
    if (W(0x69c) != 0) {
        if (func_02035CB8(&x, &y) == 0) {
            W(0x69c) = 0;
            func_021BDC48(scene, 1);
        }
    } else if (H(0x548) >= 3) {
        if (func_02035D20(&x, &y) != 0 && x >= 0x90 && x <= 0xe7 && y >= 0x28 && y <= 0x3f) {
            W(0x69c) = 1;
            func_021BDC48(scene, 0);
            moved = 1;
        }
    }
    if (W(0x69c) != 0) {
        old = H(0x550);
        x = x > 0xdc ? 0xdc : (x < 0x9c ? 0x9c : x);
        pos[0] = x;
        pos[1] = 0x30;
        func_0204B404(W(0x5e8), pos, 0);
        H(0x550) = ov208_func_021C6E60(a0, p, key, H(0x54e),
                                       ov208_func_021C6DD8(H(0x548) - 1, x));
        if (old != H(0x550)) {
            ov208_func_021C5C64(a0, p, key);
            moved = 1;
        }
    }
    if (moved)
        func_020061E4(0x645);
    if (W(0x69c) != 0)
        func_020355D8(1);
    return W(0x69c);
}

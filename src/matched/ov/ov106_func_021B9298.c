/*
 * function: func_021B9298
 * address: 0x021B9298
 * packet: pkt_ov106_021B9298
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);
void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h) {
    u8 *dst = func_020437D4(a);
    u8 *src = func_020437D4(b);
    func_02082A90(dst + (x + w * y) * 32, src + (sx + w * sy) * 32, w * h * 32);
}

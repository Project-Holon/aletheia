/*
 * function: func_021B9F34
 * address: 0x021B9F34
 * packet: pkt_ov110_021B9F34
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0204ABF0(int, int, int, int, u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021B9F34(u8 *p, int archive) {
    u8 *q = *(u8 **)p;
    int i;
    for (i=0; i<2; ++i) {
        u8 *r = q+i*12;
        *(int *)(r+0x24) = func_0204ABF0(archive, 7, i, 0, 42);
        *(int *)(r+0x28) = func_0204A6C8((void *)archive, 19, 0, i, 42);
        *(int *)(r+0x2C) = func_0204AF28((void *)archive, 36, 42, 42);
        *(int *)(r+0x3C) = func_0204ABF0(archive, 1, i, 224, 42);
        *(int *)(r+0x40) = func_0204A6C8((void *)archive, 46, 0, i, 42);
        *(int *)(r+0x44) = func_0204AF28((void *)archive, 34, 40, 42);
    }
}

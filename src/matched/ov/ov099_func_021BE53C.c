/*
 * function: func_021BE53C
 * address:  0x021BE53C
 * packet:   pkt_ov099_021BE53C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_021BE2DC  0x021BE2DC  thumb  ov099
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_021BE2DC(char *p, int a, int b);
typedef unsigned short u16;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);

void func_021BE53C(char *p, int v)
{
    u32 k = 0xF;
    func_020434DC(0xF, 1);
    func_02043598(0xD, 1);
    func_021BE2DC(p + 0x898, v, 0x21);
    func_02049B40(0x17, 5, 0, k << 5, 0x20, 0x21);
    *(void **)(p + 0x1330) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1334) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1338) = func_0201F5DC((void *)1, 0xE, 0, 0x21);
}

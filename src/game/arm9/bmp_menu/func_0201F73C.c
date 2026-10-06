/*
 * function: func_0201F73C
 * address:  0x0201F73C
 * packet:   pkt_0201F73C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     blocked on func_0201F628 (label class): its only image-wide
 *   caller is the +0040 site inside this same function, so no witness
 *   exists outside the range under test. --suggest-split confirms no
 *   partition frees it (best partition: 0 pieces, function left out).
 * symbols:
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_0201F628 0x0201F628 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_02041B6C 0x02041B6C arm
 */

typedef unsigned int u32;

extern void *func_02045730(void *a0);
typedef unsigned char  u8;
struct Descriptor;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void  func_0201F628(void *ctx, u32 v10, u32 v14, u32 v18, u32 v0, int a3, int a2);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);

void func_0201F73C(void *a0, int a1, int a2, int a3)
{
    void *ctx = func_02045730(a0);
    u32 v10 = func_02045758(a0);
    u32 v14 = func_02045760(a0);
    u32 v18 = func_02045748(a0);
    u32 v0  = func_02045750(a0);

    func_0201F628(ctx, v10, v14, v18, v0, a3, a2);

    if (a1 == 0) {
        func_020409B4((u32)ctx);
    } else if (a1 == 1) {
        func_02041B6C((u32)ctx);
    }
}

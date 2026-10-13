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
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   func_0201F628 0x0201F628 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_02041B6C 0x02041B6C arm
 */

typedef unsigned int u32;

extern void *BMP_WIN_GetBgLayer(void *a0);
typedef unsigned char  u8;
struct Descriptor;
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);
extern void  func_0201F628(void *ctx, u32 v10, u32 v14, u32 v18, u32 v0, int a3, int a2);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);

void func_0201F73C(void *a0, int a1, int a2, int a3)
{
    void *ctx = BMP_WIN_GetBgLayer(a0);
    u32 v10 = BMP_WIN_GetPosX(a0);
    u32 v14 = BMP_WIN_GetPosY(a0);
    u32 v18 = BMP_WIN_GetDispWidth(a0);
    u32 v0  = BMP_WIN_GetDispHeight(a0);

    func_0201F628(ctx, v10, v14, v18, v0, a3, a2);

    if (a1 == 0) {
        func_020409B4((u32)ctx);
    } else if (a1 == 1) {
        func_02041B6C((u32)ctx);
    }
}

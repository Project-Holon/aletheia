/*
 * function: ov208_func_021C4D68
 * address:  0x021C4D68
 * packet:   pkt_ov208_021C4D68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 3 bytes out: the second print passes y = 0x11 as `movs r3,#0x11; lsls; asrs`
 * (a runtime s16 conversion of a constant); every spelling folds the conversion.
 *
 * symbols:
 *   func_02045770        0x02045770  arm
 *   func_020437DC        0x020437DC  arm
 *   ov208_func_021C47C4  0x021C47C4  thumb
 *   func_0201D304        0x0201D304  thumb
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   ov208_func_021C4B60  0x021C4B60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208Menu {
    u32 f0;
    u32 font;
};

extern u32  func_02045770(u32 win);
extern u16  func_020437DC(u32 bmp);
extern void ov208_func_021C47C4(u16 *heap, struct Ov208Menu *p, int key, u32 *outStr, u32 *outB,
                                int *outC, int *outD, u16 idx);
extern u32  func_0201D304(u32 str, u32 font, u32 b);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);
extern void func_02045808(u32 str);
extern void ov208_func_021C4B60(u16 *heap, struct Ov208Menu *p, int key, int i);

void ov208_func_021C4D68(u16 *heap, struct Ov208Menu *p, int key, int i, u32 print, u32 win,
                         u32 *active, u16 idx)
{
    u32 bmp;
    u16 width;
    u32 strA;
    u32 strB;
    int freeA;
    int freeB;
    int y;
    u16 w;

    bmp = func_02045770(win);
    width = func_020437DC(bmp);
    ov208_func_021C47C4(heap, p, key, &strA, &strB, &freeA, &freeB, idx);
    y = 1;
    if (strB == 0)
        y = 9;
    w = func_0201D304(strA, p->font, 0);
    func_0201C724(print, bmp, (u16)((width - w) / 2), y, strA, p->font, 0x3c40);
    if (strB != 0) {
        w = func_0201D304(strB, p->font, 0);
        func_0201C724(print, bmp, (u16)((width - w) / 2), y + 16, strB, p->font, 0x3c40);
    }
    if (strA != 0 && freeA != 0)
        func_02045808(strA);
    if (strB != 0 && freeB != 0)
        func_02045808(strB);
    *active = 1;
    ov208_func_021C4B60(heap, p, key, i);
}

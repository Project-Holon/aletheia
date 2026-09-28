/*
 * function: func_021EBA30
 * address:  0x021EBA30
 * packet:   pkt_ov170_021EBA30
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *
 * Clears a message window to colour 15 and draws its frame.
 */

typedef unsigned int u32;

extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, u32 color);
extern void func_0201F73C(void *win, u32 a, u32 b, u32 c);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EBA30(unsigned char *p, void *win)
{
    func_02043B5C(func_02045770(win), 0xF);
    func_0201F73C(win, 2, (unsigned short)*(int *)(WORK(p) + 0x178), 10);
}

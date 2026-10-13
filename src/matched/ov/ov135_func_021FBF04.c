/*
 * function: func_021FBF04
 * address:  0x021FBF04
 * packet:   pkt_021FBF04
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02202A50  0x02202A50  thumb
 *   func_02202B20  0x02202B20  thumb
 *   func_02045334  0x02045334  arm
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WinMgr;
struct CharBuf;
struct Descriptor;
struct Obj;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02202A50(void *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
extern void func_02202B20(struct Obj *p, int arg1, void *arg2, int arg3, int arg4);
extern void func_02045334(struct Descriptor *d);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);

void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages)
{
    func_02043B5C(func_02045770(win), 8);
    func_02202A50(ctx, page + 1, 2, 1, win, 0, 0);
    func_02202B20(ctx, 0, win, 0x10, 0);
    func_02202A50(ctx, pages, 2, 0, win, 0x18, 0);
    func_02045334(win);
    BGWINFRM_PutBmpWin(mgr, 0, win);
}

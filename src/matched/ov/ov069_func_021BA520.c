/*
 * function: func_021BA520
 * address:  0x021BA520
 * packet:   pkt_021BA520
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BGWINFRM_ShowFrame  0x0202CC58  thumb
 */
#include "../include/Obj07687.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct WinMgr;
typedef signed short   s16;
typedef unsigned short u16;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);

void func_021BA520(u8 *a0, int a1, void *a2, int a3)
{
    func_02043B5C(func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 4);
    if (a3 == 0)
        func_0201C7D0((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      ((struct Obj07687 *)a0)->fC, 0x3584);
    else
        func_0201C7D0((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      ((struct Obj07687 *)a0)->fC, 0x2D44);
    func_02045334(*(void **)(a0 + 0x10 + a1 * 4));
    BGWINFRM_PutBmpWin(*(struct WinMgr * *)&((struct Obj07687 *)a0)->f4, a1, *(void **)(a0 + 0x10 + a1 * 4));
    BGWINFRM_ShowFrame(*(struct WinMgr * *)&((struct Obj07687 *)a0)->f4, a1);
}

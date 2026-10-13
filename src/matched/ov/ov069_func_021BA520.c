/*
 * function: BSUBWAY_RECORD_LIST_DrawRowName
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
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
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
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);

void BSUBWAY_RECORD_LIST_DrawRowName(u8 *a0, int a1, void *a2, int a3)
{
    BMP_Clear(func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 4);
    if (a3 == 0)
        PRINTSYS_PrintColor((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      ((struct Obj07687 *)a0)->fC, 0x3584);
    else
        PRINTSYS_PrintColor((void *)func_02045770(*(void **)(a0 + 0x10 + a1 * 4)), 0, 0, a2,
                      ((struct Obj07687 *)a0)->fC, 0x2D44);
    BMP_WIN_TransferChars(*(void **)(a0 + 0x10 + a1 * 4));
    BGWINFRM_PutBmpWin(*(struct WinMgr * *)&((struct Obj07687 *)a0)->f4, a1, *(void **)(a0 + 0x10 + a1 * 4));
    BGWINFRM_ShowFrame(*(struct WinMgr * *)&((struct Obj07687 *)a0)->f4, a1);
}

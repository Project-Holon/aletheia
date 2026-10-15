/*
 * function: SHINKA_DEMO_ClearText
 * address:  0x0220549C
 * packet:   pkt_0220549C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01429.h"

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(int, int);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
typedef unsigned char  u8;
struct Cfg;
struct Rec3;
struct U16Vec;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);

void SHINKA_DEMO_ClearText(char *a, int b)
{
    int p;

    BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01429 *)a)->f6C), b);
    p = ((struct Obj01429 *)a)->f6C;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    if (((struct Obj01429 *)a)->f64 != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj01429 *)a)->f64));
    if (((struct Obj01429 *)a)->f80 != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Obj01429 *)a)->f80));
    ((struct Obj01429 *)a)->f64 = 0;
    ((struct Obj01429 *)a)->f80 = 0;
}

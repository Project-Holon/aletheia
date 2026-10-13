/*
 * function: func_0220549C
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
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01429.h"

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(int, int);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
typedef unsigned char  u8;
struct Cfg;
struct Rec3;
struct U16Vec;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);

void func_0220549C(char *a, int b)
{
    int p;

    BMP_Clear((int)func_02045770((struct Descriptor *)((struct Obj01429 *)a)->f6C), b);
    p = ((struct Obj01429 *)a)->f6C;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    if (((struct Obj01429 *)a)->f64 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01429 *)a)->f64));
    if (((struct Obj01429 *)a)->f80 != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Obj01429 *)a)->f80));
    ((struct Obj01429 *)a)->f64 = 0;
    ((struct Obj01429 *)a)->f80 = 0;
}

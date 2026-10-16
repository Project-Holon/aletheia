/*
 * function: ZUKAN_INFO_FlushMainWindow
 * address:  0x021BB0FC
 * packet:   pkt_ov206_021BB0FC
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj10886.h"

struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void ZUKAN_INFO_FlushMainWindow(void *obj)
{
    int p;

    if (((struct Obj10886 *)obj)->f8 != 0) {
        p = ((struct Obj10886 *)obj)->f8C;
        BMP_WIN_TransferChars((struct Descriptor *)p);
        BMP_WIN_MakeScreen((struct Cfg *)p);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
        return;
    }
    p = ((struct Obj10886 *)obj)->f90;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
}


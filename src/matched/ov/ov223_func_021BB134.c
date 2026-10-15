/*
 * function: PSEL_UpdateB134
 * address: 0x021BB134
 * packet: pkt_ov223_021BB134
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing B18A halfword is zero alignment padding.
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
#include "../include/Obj00084.h"
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Rec3;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern void STRBUF_Delete(struct U16Vec *);
void PSEL_UpdateB134(char *p)
{
    struct Descriptor *d;
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00084 *)p)->f23C), 0);
    d = *(struct Descriptor * *)&((struct Obj00084 *)p)->f23C;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen((struct Cfg *)d);
    func_02041B6C(BMP_WIN_GetBgLayer(d));
    if (*(struct Rec3 * *)&((struct Obj00084 *)p)->f250)
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj00084 *)p)->f250);
    *(int *)&((struct Obj00084 *)p)->f250 = 0;
    if (*(struct U16Vec * *)&((struct Obj00084 *)p)->f258)
        STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00084 *)p)->f258);
    *(int *)&((struct Obj00084 *)p)->f258 = 0;
}

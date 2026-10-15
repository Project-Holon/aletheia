/*
 * function: STA_ACTING_ClearText
 * address: 0x021F94B0
 * packet: pkt_ov132_021F94B0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj03817.h"
typedef unsigned char u8;
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void STA_ACTING_ClearText(u8 *p)
{
    if (((struct Obj03817 *)p)->fD8) {
        PRINTSYS_PrintStreamDelete(((struct Obj03817 *)p)->fD8);
        ((struct Obj03817 *)p)->fD8 = 0;
    }
    if (((struct Obj03817 *)p)->fE0) {
        STRBUF_Delete(((struct Obj03817 *)p)->fE0);
        ((struct Obj03817 *)p)->fE0 = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03817 *)p)->fD0), 0);
    BMP_WIN_TransferChars(((struct Obj03817 *)p)->fD0);
}

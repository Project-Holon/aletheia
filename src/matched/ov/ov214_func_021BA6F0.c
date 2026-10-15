/*
 * function: BTL_REC_SEL_ResetTimer
 * address: 0x021BA6F0
 * packet: pkt_ov214_021BA6F0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA792 alignment padding (two zero bytes).
 * note: BAD08 accepts the visible obj/p inputs although its stub ignores them.
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   BTL_REC_SEL_ClearLayer 0x021BAD08 thumb ov214
 */
#include "../include/Obj00202.h"
typedef unsigned char u8;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void BTL_REC_SEL_ClearLayer(void*,char*);
void BTL_REC_SEL_ResetTimer(void*obj,char*p)
{
    void*h;
    *(int *)&((struct Obj00202 *)p)->fAC=0;
    *(int *)&((struct Obj00202 *)p)->fB0=0;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00202 *)p)->f14));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj00202 *)p)->f94),0);
    h=*(void* *)&((struct Obj00202 *)p)->f94;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(BMP_WIN_GetBgLayer(h));
    ((struct Obj00202 *)p)->fA4=1;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00202 *)p)->f18));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj00202 *)p)->f98),0);
    h=*(void* *)&((struct Obj00202 *)p)->f98;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(BMP_WIN_GetBgLayer(h));
    ((struct Obj00202 *)p)->fA8=1;
    if(((struct Obj00202 *)p)->f3C)BTL_REC_SEL_ClearLayer(obj,p);
    ((struct Obj00202 *)p)->fBC=0;
    ((struct Obj00202 *)p)->fC0=0;
}

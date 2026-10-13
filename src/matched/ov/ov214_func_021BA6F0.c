/*
 * function: func_021BA6F0
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
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BAD08 0x021BAD08 thumb ov214
 */
#include "../include/Obj00202.h"
typedef unsigned char u8;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void func_021BAD08(void*,char*);
void func_021BA6F0(void*obj,char*p)
{
    void*h;
    *(int *)&((struct Obj00202 *)p)->fAC=0;
    *(int *)&((struct Obj00202 *)p)->fB0=0;
    func_0201C6EC((struct PrintSys *)(((struct Obj00202 *)p)->f14));
    BMP_Clear(func_02045770(*(void* *)&((struct Obj00202 *)p)->f94),0);
    h=*(void* *)&((struct Obj00202 *)p)->f94;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(func_02045730(h));
    ((struct Obj00202 *)p)->fA4=1;
    func_0201C6EC((struct PrintSys *)(((struct Obj00202 *)p)->f18));
    BMP_Clear(func_02045770(*(void* *)&((struct Obj00202 *)p)->f98),0);
    h=*(void* *)&((struct Obj00202 *)p)->f98;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(func_02045730(h));
    ((struct Obj00202 *)p)->fA8=1;
    if(((struct Obj00202 *)p)->f3C)func_021BAD08(obj,p);
    ((struct Obj00202 *)p)->fBC=0;
    ((struct Obj00202 *)p)->fC0=0;
}

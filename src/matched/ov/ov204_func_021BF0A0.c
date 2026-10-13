/*
 * function: func_021BF0A0
 * address: 0x021BF0A0
 * packet: pkt_ov204_021BF0A0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   site 0x021C0AE4 data a1
 *   func_02030734 0x02030734 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 *   TIME_ICON_Alloc 0x0202EF60 thumb
 */
#include "../include/Obj01008.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern const char site[];
extern void *func_02030734(u32,u32,int,const char *,u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void *func_02028590(u32,u32,u32,u32);
extern struct Obj *TIME_ICON_Alloc(u32 heap);
char *func_021BF0A0(u16 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    ((struct Obj01008 *)p)->f0=heap;
    ((struct Obj01008 *)p)->f8=func_0201EC64(heap);
    ((struct Obj01008 *)p)->f4=(void *)PRINTSYS_QUE_Create((void *)heap);
    ((struct Obj01008 *)p)->f18=TCBL_Create(((struct Obj01008 *)p)->f0,((struct Obj01008 *)p)->f0,2,0);
    func_02049B40(23,5,0,320,32,heap);
    func_0201F5BC(1,7,9,0,heap);
    func_0201F5BC(1,16,8,1,heap);
    ((struct Obj01008 *)p)->f10=GF_FONT_Create(23,0,1,0,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f3C=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f40=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f38=(void *)BMP_WIN_Create(1,22,13,9,4,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01008 *)p)->f38),0);
    obj=((struct Obj01008 *)p)->f38;
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_02041B6C(BMP_WIN_GetBgLayer(obj));
    ((struct Obj01008 *)p)->f1C=(void *)BMP_WIN_Create(1,1,19,30,4,10,1);
    ((struct Obj01008 *)p)->f20=func_02028590(15,1,1,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f44=TIME_ICON_Alloc(((struct Obj01008 *)p)->f0);
    return p;
}

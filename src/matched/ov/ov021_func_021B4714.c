/*
 * function: SCRCMD_PROC_FLD_ShowItemMessage
 * address:  0x021B4714
 * packet:   pkt_ov021_021B4714
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201EF6C  0x0201EF6C  thumb
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   SCRCMD_PROC_FLD_ReturnZero  0x021B4710  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01503.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef signed short   s16;
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern signed char func_02012FFC(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int SCRCMD_PROC_FLD_ReturnZero();

void SCRCMD_PROC_FLD_ShowItemMessage(u8 *p, u32 sel, u32 c, u32 d)
{
    u32 flag;
    u32 v;
    u32 h;

    if (sel == 9 && d != 0)
        flag = 1;
    else
        flag = 0;
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01503 *)p)->f17C)), 0xf);
    func_0201F73C((void *)(((struct Obj01503 *)p)->f17C), 0, 0xe4, 9);
    func_0201EF6C((struct WordSet *)(((struct Obj01503 *)p)->f190), 0, c, flag, 0);
    func_0201F14C((struct WordSet *)(((struct Obj01503 *)p)->f190), 1, func_02020FE4((void *)c, 5, ((struct Obj01503 *)p)->f4));
    v = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01503 *)p)->f188), sel);
    func_0201F250((struct WordSet *)(((struct Obj01503 *)p)->f190), (void *)(((struct Obj01503 *)p)->f198), (void *)v);
    STRBUF_Delete((struct U16Vec *)v);
    ((struct Obj01503 *)p)->f1B8 = (u32)PRINTSYS_PrintStreamCallBack(((struct Obj01503 *)p)->f17C, 0, 0, ((struct Obj01503 *)p)->f198,
                                        ((struct Obj01503 *)p)->f8, func_02012FFC(),
                                        ((struct Obj01503 *)p)->f1B4, 0, ((struct Obj01503 *)p)->f4, 0xffff,
                                        (u32)SCRCMD_PROC_FLD_ReturnZero);
    h = ((struct Obj01503 *)p)->f17C;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
}

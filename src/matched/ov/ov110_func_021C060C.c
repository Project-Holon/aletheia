/*
 * function: func_021C060C
 * address: 0x021C060C
 * packet: pkt_ov110_021C060C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Own callee bodies fix arity and full word payloads; caller0490 loads heap
 *   with ldrh. The original narrows only 49990's fifth argument to u16.
 * No local arrays; p+14/+16/+18/+1a halfwords initialized before queued
 *   two-byte reads. Callback/context pointers retain their full32 bits.
 * First one EXACT476; final text freshly verified after literal move.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02466.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern int func_02061CA4(void *,u32,u32,int);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021C060C(u8 *p,u16 heap,u32 font,void *print,void *bank)
{
    void *h;
    void *str;
    h=func_020490F4((unsigned int)43,heap);
    func_02049B68((void *)((u32)h),0,0,0,288,heap);
    func_02049B68((void *)((u32)h),0,4,0,256,heap);
    func_02049B40(23,5,0,288,32,heap);
    ((struct Obj02466 *)p)->f14=0x7fff;
    func_02061CA4((void *)15,316,(u32)(p+0x14),2);
    ((struct Obj02466 *)p)->f16=0x7fff;
    func_02061CA4((void *)15,314,(u32)(p+0x16),2);
    func_02049658((void *)((u32)h),10,4,0,0,0,heap);
    func_020498F4((void *)((u32)h),21,4,0,0,0,heap);
    ((struct Obj02466 *)p)->f0=func_02049740((void *)((u32)h),10,3,0,0,heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)((u32)h),22,3,0,(u16)(((struct Obj02466 *)p)->f0),0,0,heap);
    func_02049658((void *)((u32)h),11,2,0,0,0,heap);
    ((struct Obj02466 *)p)->f4=ARC_UTIL_LoadPaletteDataFromHandle(h,23,0,(void **)(p+8),heap);
    ARC_UTIL_UploadPaletteFromHandle((void *)((u32)h),4,4,128,256,32,heap);
    ((struct Obj02466 *)p)->f18=0x294b;
    func_02061CA4((void *)31,284,(u32)(p+0x18),2);
    ((struct Obj02466 *)p)->f1A=0x5694;
    func_02061CA4((void *)31,286,(u32)(p+0x1a),2);
    func_02049658((void *)((u32)h),18,5,0,0,0,heap);
    func_020498F4((void *)((u32)h),24,5,0,0,0,heap);
    func_020413B0(5,0,0,32,32,8);
    *(u32 *)&((struct Obj02466 *)p)->f24=BMP_WIN_Create(5,3,5,26,7,8,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02466 *)p)->f24),7);
    str=func_02045EC0(bank,21);
    PRINTSYS_PrintQueColor(print,(u32)BMP_WIN_GetBmp(((struct Obj02466 *)p)->f24),2,4,(u32)str,font,0x39e7);
    ((struct Obj02466 *)p)->f28=1;
    STRBUF_Delete(str);
    ARC_TOOL_DeleteHandle(h);
}

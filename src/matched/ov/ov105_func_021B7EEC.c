/*
 * function: func_021B7EEC
 * address: 0x021B7EEC
 * packet: pkt_ov105_021B7EEC
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_021B7CAC 0x021B7CAC thumb ov105
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF6C 0x0201EF6C thumb
 */
#include "../include/Obj05278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CA0(void *);
extern int func_021B7CA4(void *);
extern int func_021B7CA8(void *);
extern int func_021B7CAC(void *p);
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct MsgBank;
struct PrintSys;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void func_021B7EEC(u8 *p, void *a, u8 b, u16 c, u16 d)
{
 void *msg; int bank; void *text; int font; int tag;
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj05278 *)p)->f0),((struct Obj05278 *)p)->f10);
 msg=(void *)func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201EFA4(msg,d,c,3,0,1);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05278 *)p)->fC,text); STRBUF_Delete(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 PRINTSYS_PrintQue((struct PrintSys *)font,(u32)BMP_WIN_GetBmp(((struct Obj05278 *)p)->f4),0,0,((struct Obj05278 *)p)->fC,tag);
 p[8]=1;
}

/*
 * function: func_021B8030
 * address: 0x021B8030
 * packet: pkt_ov104_021B8030
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7DE0 0x021B7DE0 thumb ov104
 *   func_021B7DE4 0x021B7DE4 thumb ov104
 *   func_021B7DE8 0x021B7DE8 thumb ov104
 *   func_021B7DEC 0x021B7DEC thumb ov104
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj05274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B7DE0(void *);
extern int func_021B7DE4(void *);
extern int func_021B7DE8(void *);
extern int func_021B7DEC(void *);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct PrintSys;
struct WordSet;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021B8030(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6) { int set; int bank; void *text; int font; int tag; BMP_Clear(func_02045770(((struct Obj05274 *)p)->f0),((struct Obj05274 *)p)->f10); set=func_021B7DEC(a); bank=func_021B7DE8(a); func_0201F02C((struct WordSet *)set,0,c+0xc); text=func_02045EC0((struct MsgBank *)bank,b); func_0201F250((struct WordSet *)set,((struct Obj05274 *)p)->fC,text); STRBUF_Delete(text); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05274 *)p)->f4),x,y,((struct Obj05274 *)p)->fC,tag); p[8]=1; }

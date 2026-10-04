/*
 * function: func_021B7DE4
 * address: 0x021B7DE4
 * packet: pkt_ov105_021B7DE4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
#include "../include/Obj05277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CA0(void *);
extern int func_021B7CA4(void *);
extern int func_021B7CA8(void *);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
struct PrintSys;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y) {
 int bank; int font; int tag;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj05277 *)p)->f0),((struct Obj05277 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj05277 *)p)->fC);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05277 *)p)->f4),(s16)x,y,((struct Obj05277 *)p)->fC,tag); p[8]=1;
}

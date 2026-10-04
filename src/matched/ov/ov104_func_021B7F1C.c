/*
 * function: func_021B7F1C
 * address: 0x021B7F1C
 * packet: pkt_ov104_021B7F1C
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
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
#include "../include/Obj05273.h"
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
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct MsgBank;
struct PrintSys;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_021B7F1C(u8 *p,void *a,int b,int x,s16 y) { int bank; int font; int tag; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(((struct Obj05273 *)p)->f0),((struct Obj05273 *)p)->f10); func_02045CAC((struct MsgBank *)bank,b,((struct Obj05273 *)p)->fC); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05273 *)p)->f4),(s16)x,y,((struct Obj05273 *)p)->fC,tag); p[8]=1; }

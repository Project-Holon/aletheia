/*
 * function: func_021EF444
 * address: 0x021EF444
 * packet: pkt_ov107_021EF444
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: MMIO palette halfword stores at 021EF56E and 021EF572.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021F1B04 0x021F1B04 thumb ov107
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021F6EA0 0x021F6EA0 data a4
 */
#include "../include/Obj00057.h"
#include "../include/G_Counter.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;struct MsgBank;struct Rec;struct U16Vec;struct CharBuf;struct Cfg;
extern struct Counter d_021F6EA0;
extern void func_02040588(u32 which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u32,u8,u8,u8,u8,u8),func_020409B4(u32),ARC_TOOL_DeleteHandle(void *);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern unsigned int func_021F1B04(unsigned char *p);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *),BMP_WIN_MakeScreen(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
void func_021EF444(u8 *p) {
 u32 bg,window;
 void *archive,*text;
 struct MsgBank *bank;
 if(!p[0x28]) {*(u32 *)(((u8 *)&d_021F6EA0)+4)=1;bg=4;}
 else {*(u32 *)(((u8 *)&d_021F6EA0)+4)=0;bg=2;}
 func_02040588(bg,0);
 archive=func_020490F4(22,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,4,224,32,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,224,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),1,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020498F4((void *)((u32)archive),2,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020413B0(bg,0,0,32,24,7);func_020409B4(bg);ARC_TOOL_DeleteHandle(archive);
 window=BMP_WIN_Create(bg,1,4,30,8,7,1);
 bank=func_02045B38(0,2,0x52,((struct Obj00057 *)p)->f0);
 text=func_02045EC0(bank,1);
 BMP_Clear(func_02045770((struct Descriptor *)window),7);
 PRINTSYS_PrintColor(func_02045770((struct Descriptor *)window),0,0,text,(void *)func_021F1B04(*(u8 * *)&((struct Obj00057 *)p)->f68),0x1167);
 BMP_WIN_TransferChars((struct Descriptor *)window);BMP_WIN_MakeScreen((struct Cfg *)window);
 func_020409B4(func_02045730((struct Descriptor *)window));
 STRBUF_Delete((struct U16Vec *)text);MSGDATA_Delete((struct Rec *)bank);func_020452E8((struct Descriptor *)window);
 *(volatile u16 *)0x05000000=0x7eea;*(volatile u16 *)0x05000400=0x7eea;
}

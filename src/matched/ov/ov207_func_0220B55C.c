/*
 * function: ZUKAN_NICKNAME_Create
 * address: 0x0220B55C
 * packet: pkt_ov207_0220B55C
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0201CCE4 is a void forwarder in its matched source; caller stores live r0, so declare its observed word return.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   func_02049B40 0x02049B40 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_020355C4 0x020355C4 arm
 *   ZUKAN_NICKNAME_InitKeyboard 0x0220B954 thumb ov207
 *   ZUKAN_NICKNAME_TransferPalette 0x0220B944 thumb ov207
 *   func_020056A0 0x020056A0 thumb
 */
#include "../include/Obj00174.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Tcbl;
extern char file_0220BC38[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern void WORDSET_SetSlotMonName(struct WordSet *,u32,void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void *BMP_MENUWORK_LoadFrameGfx(void *,u32,u32,u32);
extern u8 func_020355C4(void);
extern void ZUKAN_NICKNAME_InitKeyboard(u32 *);
extern void ZUKAN_NICKNAME_TransferPalette(void *a, u32 *p);
extern void *func_020056A0(u32,u32,u32);
char *ZUKAN_NICKNAME_Create(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h)
{
    char *p;
    struct WordSet *ws;
    struct MsgBank *bank;
    void *str;
    u8 enabled;
    p=func_02030734(heap,0x5c,0,file_0220BC38,220);
    MI_CpuFill8(p,0,0x5c);
    ((struct Obj00174 *)p)->f0=heap;
    *(u32 *)&((struct Obj00174 *)p)->f4=a;
    ((struct Obj00174 *)p)->f8=b;
    ((struct Obj00174 *)p)->fC=c;
    ((struct Obj00174 *)p)->f10=d;
    ((struct Obj00174 *)p)->f14=e;
    ((struct Obj00174 *)p)->f18=f;
    ((struct Obj00174 *)p)->f1C=g;
    ((struct Obj00174 *)p)->f20=h;
    ((struct Obj00174 *)p)->f3C=0;
    ((struct Obj00174 *)p)->f40=2;
    ((struct Obj00174 *)p)->f44=0;
    func_02049B40(0x17,5,0,0x120,32,((struct Obj00174 *)p)->f0);
    ws=WORDSET_CreateDefault(((struct Obj00174 *)p)->f0);
    WORDSET_SetSlotMonName(ws,0,((struct Obj00174 *)p)->f4);
    bank=func_02045B38(0,2,0xea,((struct Obj00174 *)p)->f0);
    str=func_02045EC0(bank,0xaf);
    *(struct U16Vec * *)&((struct Obj00174 *)p)->f2C=STRBUF_Create(64,((struct Obj00174 *)p)->f0);
    WORDSET_CopyTaggedText(ws,((struct Obj00174 *)p)->f2C,str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct Rec *)bank);
    WORDSET_DeleteStrbufED04(ws);
    *(u32 *)&((struct Obj00174 *)p)->f38=BMP_WIN_Create(3,0,0,1,1,9,0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38),0);
    BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38);
    func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38));
    *(struct Tcbl * *)&((struct Obj00174 *)p)->f34=TCBL_Create(((struct Obj00174 *)p)->f0,((struct Obj00174 *)p)->f0,1,0);
    *(u32 *)&((struct Obj00174 *)p)->f24=BMP_WIN_Create(3,1,19,30,4,9,1);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00174 *)p)->f24),15);
    GF_FONT_SetTextColor(1,2,15);
    ((struct Obj00174 *)p)->f28=PRINTSYS_PrintStream(*(u32 *)&((struct Obj00174 *)p)->f24,0,0,*(u32 *)&((struct Obj00174 *)p)->f2C,((struct Obj00174 *)p)->f18,MSG_SPEED_GetWait(),*(u32 *)&((struct Obj00174 *)p)->f34,2,((struct Obj00174 *)p)->f0,15);
    ((struct Obj00174 *)p)->f30=BMP_MENUWORK_LoadFrameGfx((void *)3,8,0,((struct Obj00174 *)p)->f0);
    enabled=1;
    if(func_020355C4()!=0) enabled=0;
    ((struct Obj00174 *)p)->f50=enabled;
    ZUKAN_NICKNAME_InitKeyboard((u32 *)p);
    ((struct Obj00174 *)p)->f48=func_020056A0((u32)ZUKAN_NICKNAME_TransferPalette,(u32)p,1);
    return p;
}

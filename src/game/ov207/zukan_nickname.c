/*
 * file:     zukan_nickname.c
 * unit:     yes
 * function: func_0220B55C, func_0220B6E4, func_0220B72C, func_0220B908, func_0220B940, func_0220B944, func_0220B954, func_0220B9B0
 * address:  0x0220B55C
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020355C4 0x020355C4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   TCBL_Main 0x020310C4 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_0220B9E0 0x0220B9E0 thumb ov207
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   func_02202058 0x02202058 thumb ov094
 *   func_022021F4 0x022021F4 thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02034A5C 0x02034A5C arm
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 */
#include "../../matched/include/Obj00174.h"
#include "../../matched/include/Obj00181.h"
#include "../../matched/include/Obj06677.h"
#include "../../matched/include/Obj25413.h"
#include "../../matched/include/Obj01975.h"

struct WordSet;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Tcbl;
struct Rec;
struct Node;
struct Rec3;
struct S02031140;
struct Cfg;
struct S02021D50;
struct Obj02021EE4;
struct PalAnmSlot;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct Obj Obj;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201EE84(struct WordSet *,u32,void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern u8 func_020355C4(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void TCBL_Main(struct Tcbl *);
extern u32 func_0201CE30(void *);
extern u32 func_0203630C(void);
extern void func_020355D8(u8);
extern int TOUCHPANEL_GetCont(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0201CE38(void *);
extern void func_020061E4(u32);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201F164(struct WordSet *,u32,u32,u32);
extern void func_0220B9E0(int *);
extern void func_0201F73C(void *,int,unsigned short,int);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern int func_02034AC4(int);
extern void *PALANM_Create(unsigned);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern struct Obj *func_02202058(int a, int b, int c, int d, int e, u16 k);
extern void func_022021F4(Obj *);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);
extern void PALANM_Delete(struct PalAnmSlot *);
extern void func_02034A5C(int);
char *func_0220B55C(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h);
void func_0220B6E4(unsigned *p);
int func_0220B72C(char *p);
void func_0220B908(char *p);
int func_0220B940(char *p);
void func_0220B944(void *a, u32 *p);
void func_0220B954(unsigned *p);
void func_0220B9B0(char *p);
extern char file_0220BC38[];
extern char overlay94[];

/*
 * ABI: 0201CCE4 is a void forwarder in its matched source; caller stores live r0, so declare its observed word return.
 */
char *func_0220B55C(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h)
{
    char *p;
    struct WordSet *ws;
    struct MsgBank *bank;
    void *str;
    u8 enabled;
    p=func_02030734(heap,0x5c,0,file_0220BC38,220);
    func_02082BCC(p,0,0x5c);
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
    ws=func_0201EC64(((struct Obj00174 *)p)->f0);
    func_0201EE84(ws,0,((struct Obj00174 *)p)->f4);
    bank=func_02045B38(0,2,0xea,((struct Obj00174 *)p)->f0);
    str=func_02045EC0(bank,0xaf);
    *(struct U16Vec * *)&((struct Obj00174 *)p)->f2C=STRBUF_Create(64,((struct Obj00174 *)p)->f0);
    func_0201F250(ws,((struct Obj00174 *)p)->f2C,str);
    STRBUF_Delete(str);
    MSGDATA_Delete((struct Rec *)bank);
    func_0201ED04(ws);
    *(u32 *)&((struct Obj00174 *)p)->f38=BMP_WIN_Create(3,0,0,1,1,9,0);
    BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38),0);
    BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38);
    func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38));
    *(struct Tcbl * *)&((struct Obj00174 *)p)->f34=TCBL_Create(((struct Obj00174 *)p)->f0,((struct Obj00174 *)p)->f0,1,0);
    *(u32 *)&((struct Obj00174 *)p)->f24=BMP_WIN_Create(3,1,19,30,4,9,1);
    BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj00174 *)p)->f24),15);
    GF_FONT_SetTextColor(1,2,15);
    ((struct Obj00174 *)p)->f28=PRINTSYS_PrintStream(*(u32 *)&((struct Obj00174 *)p)->f24,0,0,*(u32 *)&((struct Obj00174 *)p)->f2C,((struct Obj00174 *)p)->f18,func_02012FFC(),*(u32 *)&((struct Obj00174 *)p)->f34,2,((struct Obj00174 *)p)->f0,15);
    ((struct Obj00174 *)p)->f30=func_0201F5DC((void *)3,8,0,((struct Obj00174 *)p)->f0);
    enabled=1;
    if(func_020355C4()!=0) enabled=0;
    ((struct Obj00174 *)p)->f50=enabled;
    func_0220B954((u32 *)p);
    ((struct Obj00174 *)p)->f48=func_020056A0((u32)func_0220B944,(u32)p,1);
    return p;
}

/*
 * tail: two zero alignment bytes at 0x0220B72A before 0x0220B72C.
 */
void func_0220B6E4(unsigned *p)
{
    func_0220B9B0((char *)p);
    func_02030EAC((void *)p[18]);
    func_0201CE48((void *)p[10]);
    func_0203FB44((int)3, (u16)p[12], (u16)(p[12] >> 16));
    func_020452E8((void *)p[9]);
    STRBUF_Delete((void *)p[11]);
    TCBL_Destroy((void *)p[13]);
    func_020452E8((void *)p[14]);
    func_020307B0(p);
}

/*
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 */
int func_0220B72C(char *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(((struct Obj00181 *)p)->f3C) {
    case 0: break;
    case 1:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=func_0201CE30(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=2;((struct Obj00181 *)p)->f4C=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(func_0203630C()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) func_0201CE5C(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(func_020362DC()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {func_0201CE38(((struct Obj00181 *)p)->f28);func_020061E4(0x547);}
            break;
        }
        break;
    case 2:
        if(((struct Obj00181 *)p)->f40==2) break;
        if(((struct Obj00181 *)p)->f40==0) {
            if(*(u32 *)&((struct Obj00181 *)p)->f8==0) {((struct Obj00181 *)p)->f3C=5;break;}
            BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj00181 *)p)->f24),15);
            func_0201CE48(((struct Obj00181 *)p)->f28);
            STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00181 *)p)->f2C);
            ws=func_0201EC64(((struct Obj00181 *)p)->f0);
            func_0201EEF4(ws,0,((struct Obj00181 *)p)->f4);
            func_0201F164(ws,1,((struct Obj00181 *)p)->fC,((struct Obj00181 *)p)->f10);
            *(struct U16Vec * *)&((struct Obj00181 *)p)->f2C=STRBUF_Create(64,((struct Obj00181 *)p)->f0);
            func_0201F250(ws,((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f8);
            func_0201ED04(ws);
            *(u32 *)&((struct Obj00181 *)p)->f28=PRINTSYS_PrintStream(*(u32 *)&((struct Obj00181 *)p)->f24,0,0,*(u32 *)&((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f18,func_02012FFC(),*(u32 *)&((struct Obj00181 *)p)->f34,2,((struct Obj00181 *)p)->f0,15);
            ((struct Obj00181 *)p)->f3C=3;
        } else ((struct Obj00181 *)p)->f3C=5;
        break;
    case 3:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=func_0201CE30(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(func_0203630C()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) func_0201CE5C(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(func_020362DC()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {func_0201CE38(((struct Obj00181 *)p)->f28);func_020061E4(0x547);}
            break;
        }
        break;
    case 4:
        ++((struct Obj00181 *)p)->f44;
        if(((struct Obj00181 *)p)->f44==60) ((struct Obj00181 *)p)->f3C=5;
        break;
    case 5: done=1; break;
    }
    func_0220B9E0((int *)p);
    return done;
}

void func_0220B908(char *p){if(!((struct Obj06677 *)p)->f3C){struct Descriptor *d;unsigned flag=1;func_0201F73C(((struct Obj06677 *)p)->f24,1,((struct Obj06677 *)p)->f30,8);d=*(struct Descriptor * *)&((struct Obj06677 *)p)->f24;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(func_02045730(d));((struct Obj06677 *)p)->f3C=flag;}}

/*
 * Extra: ARM9-free blocker getter for assigned 0220B0A4; ownership and SDK checks clear.
 */
int func_0220B940(char *p)
{
    return ((struct Obj25413 *)p)->f40;
}

void func_0220B944(void *a, u32 *p){if(p[22])PALANM_TransferPalettes((void*)p[22]);}

void func_0220B954(unsigned *p)
{
    func_02034AC4((int)overlay94);
    p[22]=(unsigned)PALANM_Create(((struct Obj00174 *)p)->f0);
    PALANM_SetAutoTransfer((void *)p[22],1);
    PALANM_AllocSlotBuffers((void *)p[22],1,480,((struct Obj00174 *)p)->f0);
    PALANM_AllocSlotBuffers((void *)p[22],3,480,((struct Obj00174 *)p)->f0);
    p[21]=(unsigned)func_02202058((int)((void *)p[8]),0,(int)((void *)p[22]),(int)((void *)p[6]),(int)(p+20),((struct Obj00174 *)p)->f0);
    p[19]=0;
}

/*
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 */
void func_0220B9B0(char *p){func_022021F4(*(Obj * *)&((struct Obj01975 *)p)->f54);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,3);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58);*(unsigned *)&((struct Obj01975 *)p)->f58=0;func_02034A5C((int)overlay94);}

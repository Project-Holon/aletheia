/*
 * file:     zukan_nickname.c
 * unit:     yes
 * function: ZUKAN_NICKNAME_Create, ZUKAN_NICKNAME_Delete, ZUKAN_NICKNAME_Main, ZUKAN_NICKNAME_SetupScreen, ZUKAN_NICKNAME_GetResult, ZUKAN_NICKNAME_TransferPalette, ZUKAN_NICKNAME_InitKeyboard, ZUKAN_NICKNAME_DeleteKeyboard, ZUKAN_NICKNAME_UpdateInfoWindow
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
 *   MI_CpuFill8 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   func_02049B40 0x02049B40 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
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
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020355C4 0x020355C4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   overlay94 0x0000005E data
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   BTLV_INPUT_Delete 0x022021F4 thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02034A5C 0x02034A5C arm
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb
 *   BTLV_INPUT_UpdateInfoWindow  0x02202228  thumb
 *   d_0220BBEC     0x0220BBEC  data  ov207
 *   d_0220BBF8     0x0220BBF8  data  ov207
 */
#include "../../matched/include/Obj00174.h"
#include "../../matched/include/Obj00181.h"
#include "../../matched/include/Obj06677.h"
#include "../../matched/include/Obj25413.h"
#include "../../matched/include/Obj01975.h"
#include "../../matched/include/Obj00181.h"

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

typedef struct {
    int v0;
    int v1;
    int v2;
} S3;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern void func_0201EE84(struct WordSet *,u32,void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
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
extern void *func_0201F5DC(void *,u32,u32,u32);
extern u8 func_020355C4(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void TCBL_Main(struct Tcbl *);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern u32 KEY_GetCont(void);
extern void func_020355D8(int a);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201F164(struct WordSet *,u32,u32,u32);
extern void func_0201F73C(void *,int,unsigned short,int);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern int func_02034AC4(int);
extern void *PALANM_Create(unsigned);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern struct Obj *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k);
extern void BTLV_INPUT_Delete(Obj *);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);
extern void PALANM_Delete(struct PalAnmSlot *);
extern void func_02034A5C(int);
extern void BTLV_INPUT_ChangeScreen(int *p, int n, S3 *s);
extern int  BTLV_INPUT_ProcessTouchInput(int *p, void *a, void *b);
extern void BTLV_INPUT_UpdateInfoWindow(int *p);
char *ZUKAN_NICKNAME_Create(u16 heap,u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h);
void ZUKAN_NICKNAME_Delete(unsigned *p);
int ZUKAN_NICKNAME_Main(char *p);
void ZUKAN_NICKNAME_SetupScreen(char *p);
int ZUKAN_NICKNAME_GetResult(char *p);
void ZUKAN_NICKNAME_TransferPalette(void *a, u32 *p);
void ZUKAN_NICKNAME_InitKeyboard(unsigned *p);
void ZUKAN_NICKNAME_DeleteKeyboard(char *p);
void ZUKAN_NICKNAME_UpdateInfoWindow(int *a);
extern char file_0220BC38[];
extern char overlay94[];
extern char d_0220BBEC[];
extern char d_0220BBF8[];


/*
 * ABI: 0201CCE4 is a void forwarder in its matched source; caller stores live r0, so declare its observed word return.
 */
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
    ws=GF_FONT_Create_EC64(((struct Obj00174 *)p)->f0);
    func_0201EE84(ws,0,((struct Obj00174 *)p)->f4);
    bank=func_02045B38(0,2,0xea,((struct Obj00174 *)p)->f0);
    str=func_02045EC0(bank,0xaf);
    *(struct U16Vec * *)&((struct Obj00174 *)p)->f2C=STRBUF_Create(64,((struct Obj00174 *)p)->f0);
    func_0201F250(ws,((struct Obj00174 *)p)->f2C,str);
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
    ((struct Obj00174 *)p)->f30=func_0201F5DC((void *)3,8,0,((struct Obj00174 *)p)->f0);
    enabled=1;
    if(func_020355C4()!=0) enabled=0;
    ((struct Obj00174 *)p)->f50=enabled;
    ZUKAN_NICKNAME_InitKeyboard((u32 *)p);
    ((struct Obj00174 *)p)->f48=func_020056A0((u32)ZUKAN_NICKNAME_TransferPalette,(u32)p,1);
    return p;
}


/*
 * tail: two zero alignment bytes at 0x0220B72A before 0x0220B72C.
 */
void ZUKAN_NICKNAME_Delete(unsigned *p)
{
    ZUKAN_NICKNAME_DeleteKeyboard((char *)p);
    func_02030EAC((void *)p[18]);
    PRINTSYS_PrintStreamDelete((void *)p[10]);
    BG_SYS_DeleteHalf((int)3, (u16)p[12], (u16)(p[12] >> 16));
    BMP_WIN_Delete((void *)p[9]);
    STRBUF_Delete((void *)p[11]);
    TCBL_Destroy((void *)p[13]);
    BMP_WIN_Delete((void *)p[14]);
    func_020307B0(p);
}


/*
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 */
int ZUKAN_NICKNAME_Main(char *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(((struct Obj00181 *)p)->f3C) {
    case 0: break;
    case 1:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=PRINTSYS_PrintStreamGetState(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=2;((struct Obj00181 *)p)->f4C=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(((struct Obj00181 *)p)->f28);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 2:
        if(((struct Obj00181 *)p)->f40==2) break;
        if(((struct Obj00181 *)p)->f40==0) {
            if(*(u32 *)&((struct Obj00181 *)p)->f8==0) {((struct Obj00181 *)p)->f3C=5;break;}
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00181 *)p)->f24),15);
            PRINTSYS_PrintStreamDelete(((struct Obj00181 *)p)->f28);
            STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00181 *)p)->f2C);
            ws=GF_FONT_Create_EC64(((struct Obj00181 *)p)->f0);
            func_0201EEF4(ws,0,((struct Obj00181 *)p)->f4);
            func_0201F164(ws,1,((struct Obj00181 *)p)->fC,((struct Obj00181 *)p)->f10);
            *(struct U16Vec * *)&((struct Obj00181 *)p)->f2C=STRBUF_Create(64,((struct Obj00181 *)p)->f0);
            func_0201F250(ws,((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f8);
            WORDSET_DeleteStrbufED04(ws);
            *(u32 *)&((struct Obj00181 *)p)->f28=PRINTSYS_PrintStream(*(u32 *)&((struct Obj00181 *)p)->f24,0,0,*(u32 *)&((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f18,MSG_SPEED_GetWait(),*(u32 *)&((struct Obj00181 *)p)->f34,2,((struct Obj00181 *)p)->f0,15);
            ((struct Obj00181 *)p)->f3C=3;
        } else ((struct Obj00181 *)p)->f3C=5;
        break;
    case 3:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=PRINTSYS_PrintStreamGetState(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(((struct Obj00181 *)p)->f28);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 4:
        ++((struct Obj00181 *)p)->f44;
        if(((struct Obj00181 *)p)->f44==60) ((struct Obj00181 *)p)->f3C=5;
        break;
    case 5: done=1; break;
    }
    ZUKAN_NICKNAME_UpdateInfoWindow((int *)p);
    return done;
}


void ZUKAN_NICKNAME_SetupScreen(char *p){if(!((struct Obj06677 *)p)->f3C){struct Descriptor *d;unsigned flag=1;func_0201F73C(((struct Obj06677 *)p)->f24,1,((struct Obj06677 *)p)->f30,8);d=*(struct Descriptor * *)&((struct Obj06677 *)p)->f24;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));((struct Obj06677 *)p)->f3C=flag;}}


/*
 * Extra: ARM9-free blocker getter for assigned 0220B0A4; ownership and SDK checks clear.
 */
int ZUKAN_NICKNAME_GetResult(char *p)
{
    return ((struct Obj25413 *)p)->f40;
}


void ZUKAN_NICKNAME_TransferPalette(void *a, u32 *p){if(p[22])PALANM_TransferPalettes((void*)p[22]);}


void ZUKAN_NICKNAME_InitKeyboard(unsigned *p)
{
    func_02034AC4((int)overlay94);
    p[22]=(unsigned)PALANM_Create(((struct Obj00174 *)p)->f0);
    PALANM_SetAutoTransfer((void *)p[22],1);
    PALANM_AllocSlotBuffers((void *)p[22],1,480,((struct Obj00174 *)p)->f0);
    PALANM_AllocSlotBuffers((void *)p[22],3,480,((struct Obj00174 *)p)->f0);
    p[21]=(unsigned)BTLV_INPUT_CreateDefault((int)((void *)p[8]),0,(int)((void *)p[22]),(int)((void *)p[6]),(int)(p+20),((struct Obj00174 *)p)->f0);
    p[19]=0;
}


/*
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 */
void ZUKAN_NICKNAME_DeleteKeyboard(char *p){BTLV_INPUT_Delete(*(Obj * *)&((struct Obj01975 *)p)->f54);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58,3);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj01975 *)p)->f58);*(unsigned *)&((struct Obj01975 *)p)->f58=0;func_02034A5C((int)overlay94);}


void ZUKAN_NICKNAME_UpdateInfoWindow(int *a)
{
    S3 s;

    switch (a[19]) {
    case 0:
    case 3:
        break;
    case 1:
        ((u8 *)a)[0x50] = (func_020355C4() == 0) ? 1 : 0;
        {
            int r5 = (int)func_02045B38(0, 2, 0xe9, ((struct Obj00181 *)a)->f0);
            s.v0 = (int)func_02045EC0((struct MsgBank *)r5, 0);
            s.v1 = (int)func_02045EC0((struct MsgBank *)r5, 1);
            s.v2 = 1;
            BTLV_INPUT_ChangeScreen((int *)a[21], 4, &s);
            STRBUF_Delete((struct U16Vec *)s.v0);
            STRBUF_Delete((struct U16Vec *)s.v1);
            MSGDATA_Delete((struct Rec *)r5);
            a[19] = 2;
        }
        break;
    case 2:
        {
            int r5 = BTLV_INPUT_ProcessTouchInput((int *)a[21], d_0220BBEC, d_0220BBF8);
            if (r5 == -1)
                break;
            BTLV_INPUT_ChangeScreen((int *)a[21], 0, 0);
            a[19] = 3;
            if (r5 == 0)
                a[16] = 1;
            else
                a[16] = 0;
            func_020355D8(((u8 *)a)[0x50] ? 0 : 1);
        }
        break;
    }
    BTLV_INPUT_UpdateInfoWindow((int *)a[21]);
}

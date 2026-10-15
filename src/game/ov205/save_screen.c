/*
 * file:     save_screen.c
 * unit:     yes
 * function: func_021B95A0, func_021B95F4, func_021B9864, func_021B9874, func_021B9928, func_021B9970, func_021B99D8, func_021B99E4, func_021B9A68, func_021B9A94, func_021B9AD8, func_021B9B04, func_021B9B20, func_021B9B78, func_021B9BAC, func_021B9BE4, func_021B9D48, func_021B9D58, func_021B9DAC, SAVE_SCREEN_PrintText
 * address:  0x021B95A0
 * region:   ov205
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 *   init 0x021B9E50 data a2
 *   KEY_GetTrg 0x020362DC arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02028484 0x02028484 thumb
 *   TCBL_Main 0x020310C4 arm
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020403F4 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040EBC 0x02040EBC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   RTC_GetDate 0x02088864 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   MISC_SAVEDATA_SnapshotParty 0x0200EA3C thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_02008654 0x02008654 thumb
 *   func_02008D1C 0x02008D1C thumb
 *   func_02008DAC 0x02008DAC thumb
 *   func_02008DFC 0x02008DFC thumb
 *   FIELD_CLOCK_SaveTimestamp 0x02169120 thumb ov010
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   MISC_SAVEDATA_AppendPartyRecord 0x0200EBD0 thumb
 *   GAME_DATA_PartSaveStart 0x02012E4C thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   d_021B9EFC 0x021B9EFC data a4
 *   d_021B9ECC 0x021B9ECC data a4
 *   d_021B9EDC 0x021B9EDC data a4
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj04611.h"
#include "../../matched/include/Obj00419.h"
#include "../../matched/include/Obj25393.h"
#include "../../matched/include/Obj03359.h"
#include "../../matched/include/Obj01777.h"
#include "../../matched/include/Obj14630.h"
#include "../../matched/include/Obj14631.h"
#include "../../matched/include/Obj14632.h"
#include "../../matched/include/Obj14633.h"
#include "../../matched/include/Obj08386.h"
#include "../../matched/include/Obj10884.h"
#include "../../matched/include/Obj10885.h"
#include "../../matched/include/Obj14634.h"
#include "../../matched/include/Obj01293.h"

struct Obj0203159C;
struct Big;
struct Ctx;
struct Sub020071E4Ctrl;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Blk;
struct S020315D4;
struct GfFont;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Rec;
struct S02031140;
struct BgTemplate;
struct DispVram;
struct DispConfig;
struct BigObj;
struct Date;
struct PlayTime;
struct Sub02008C20Obj;
struct RTCDate;
struct Ctrl;
struct Obj;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {u16 value;} Init;

typedef signed int     s32;

typedef enum { ST0=0,ST13=13 } State;

typedef signed short   s16;

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(unsigned,void *,unsigned);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern u32 KEY_GetTrg(void);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_0207E468(void *,u32,u32);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int GAME_DATA_SaveStart(int);
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);
extern int GAME_DATA_SaveMain(u8 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void TCBL_Main(struct Tcbl *p);
extern void TIME_ICON_Update(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_0204363C(u32);
extern void func_0208068C(u32);
extern void MIi_CpuClearFast(u32,u32,u32);
extern void func_02080B98(void);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern struct Tcbl *TCBL_Create(u32,u16,u32,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_0201F7A8(void *,unsigned);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void func_020403F4(unsigned);
extern u32 GF_FONT_Delete(void *ptr);
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040EBC(unsigned,unsigned);
extern void BMP_WIN_Init(u16);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *,unsigned,unsigned,void *,void *,unsigned,void *,unsigned,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void RTC_GetDate(void *);
extern void *GAME_DATA_GetMyParty(const struct BigObj *);
extern void *GAME_DATA_GetSaveBlock42(void **);
extern void MISC_SAVEDATA_SnapshotParty(struct Rec *,void *,struct Date *,u32);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern int GAME_DATA_GetPlayTime(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u8 func_02008654(const struct PlayTime *p);
extern u32 func_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
extern u32 func_02008DAC(struct Sub02008C20Obj *,int,u32);
extern u32 func_02008DFC(struct Sub02008C20Obj *,int);
extern void FIELD_CLOCK_SaveTimestamp(void *);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern void MISC_SAVEDATA_AppendPartyRecord(struct Obj *obj, void *a1, void *date, u32 heap);
extern void GAME_DATA_PartSaveStart(u8 *p, u32 a);
extern int GAME_DATA_PartSaveMain(char *,int);
extern void func_020072A4(struct Sub020072A4Ctrl *,u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void func_02041B6C(u32);
int func_021B95A0(void *owner,int unused,void **args);
int func_021B95F4(void *unused,State *state,const char *context,char *p);
int func_021B9864(void *p);
void func_021B9874(char *p, const char *a1);
void func_021B9928(char *p);
void func_021B9970(u16 heap);
void func_021B99D8(void);
void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind);
void func_021B9A68(char *p);
void func_021B9A94(char *p);
void func_021B9AD8(char *p);
void func_021B9B04(char *p);
void func_021B9B20(char *p);
void func_021B9B78(char *p);
int func_021B9BAC(struct Obj0203159C *obj,u32 unused,char *ctx);
int func_021B9BE4(void *input,u32 *state,u32 unused,char *p);
int func_021B9D48(void *p);
void func_021B9D58(u16 heap);
void func_021B9DAC(void);
void SAVE_SCREEN_PrintText(char *p,u32 index,s16 x,s16 y);
extern const Init init;
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
extern const unsigned d_021B9EFC[],d_021B9ECC[],d_021B9EDC[];


int func_021B95A0(void *owner,int unused,void **args)
{
    void *context;
    char *p;
    context=*args;
    GFL_HEAP_CreateChildHeap(1,84,1<<18);
    p=PROCSYS_AllocProcWork(owner,76,84);
    func_02082A7C(0,p,76);
    ((struct Obj04611 *)p)->f0=84;
    ((struct Obj04611 *)p)->f2=36;
    ((struct Obj04611 *)p)->f4=ICA_ANIME_GetField1C(context);
    ((struct Obj04611 *)p)->f8=func_02012944(((struct Obj04611 *)p)->f4);
    if(func_020071F0(GAME_DATA_GetSaveControl(((struct Obj04611 *)p)->f4))!=0)
        ((struct Obj04611 *)p)->f40=1;
    return 1;
}


int func_021B95F4(void *unused,State *state,const char *context,char *p)
{
    Init local;
    void *obj;
    enum { M3=3,M12=12 } mode;
    local=init;
    KEY_GetTrg();
    switch(*state){
    case 0:func_021B9874(p,context);(*state)++;break;
    case 1:
    {
        enum { Z0,Z1 } zero;
        zero=0;
        *(u16 *)0x04000050=zero;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&0xffffe0ff)|256;
        if(GPOWER_GetSpecialPowerId()==21)mode=3;
        else {func_0207E468(&local,zero,2);mode=12;}
        FADE_Start(mode,16,zero,zero);(*state)++;break;
    }
    case 2:if(!FADE_IsActive())*state=3;break;
    case 3:
        if(((struct Obj00419 *)p)->f40!=0){ (*state)++; break; }
        {
            GFL_USE_PlaySeDefaultVolume(0x54c);func_021B99E4(p,3,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=4;*state=13;GAME_DATA_SaveStart(*(int *)&((struct Obj00419 *)p)->f4);
        }
        break;
    case 4:
        if(((struct Obj00419 *)p)->f40==0){
            if(((struct Obj25393 *)context)->f4==0){func_021B9A68(p);func_021B9A94(p);}
            else {func_021B9B04(p);func_021B9AD8(p);func_021B9B20(p);}
        }
        ((struct Obj00419 *)p)->f30=TIME_ICON_CreateNode(*(u32 *)&((struct Obj00419 *)p)->f24,((struct Obj00419 *)p)->f1C,15,16,((struct Obj00419 *)p)->f0);
        (*state)++;break;
    case 5:
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f38!=0){
            func_021B9B78(p);
            if(((struct Obj00419 *)p)->f3C!=0)(*state)++;
        }else (*state)++;
        break;
    case 6:
        if(((struct Obj00419 *)p)->f40==0){
            switch(GAME_DATA_SaveMain(((struct Obj00419 *)p)->f4)){
            case 0:case 1:break;
            case 2:((struct Obj00419 *)p)->f34=1;(*state)++;break;
            case 3:((struct Obj00419 *)p)->f34=0;(*state)++;break;
            }
        }else (*state)++;
        break;
    case 7:
        TIME_ICON_Delete(((struct Obj00419 *)p)->f30);
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f34!=0){
            func_021B99E4(p,4,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;GFL_USE_PlaySeDefaultVolume(0x558);
        }else{
            func_021B99E4(p,5,0,0);
            obj=((struct Obj00419 *)p)->f1C;BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;
        }
        break;
    case 8:
        if(((struct Obj00419 *)p)->f48>120)(*state)++;
        (((struct Obj00419 *)p)->f48)++;break;
    case 9:
        if(GPOWER_GetSpecialPowerId()==21){ FADE_Start(3,0,16,0); }
        else { FADE_Start(12,0,16,0); }
        (*state)++;break;
    case 10:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(((struct Obj00419 *)p)->f1C),15);(*state)++;}
        break;
    case 11:func_021B9928(p);(*state)++;break;
    case 12:return 1;
    case 13:
        if(func_02028484((struct Blk *)(p+40),((struct Obj00419 *)p)->f20))*state=((struct Obj00419 *)p)->f44;
        break;
    }
    if(((struct Obj00419 *)p)->f24)TCBL_Main(((struct Obj00419 *)p)->f24);
    if(((struct Obj00419 *)p)->f30)TIME_ICON_Update(((struct Obj00419 *)p)->f30);
    return 0;
}



int func_021B9864(void *p)
{
    func_020315D4(p);
    func_020306F0(0x54);
    return 1;
}


void func_021B9874(char *p, const char *a1) { func_0204363C(1);func_0208068C(511);MIi_CpuClearFast(0,0x6800000,0xa4000);func_02080B98();func_021B9970(*(u16 *)p);*(struct GfFont **)(p+0x10)=GF_FONT_Create(23,0,0,0,*(u16 *)p);func_02049B40(23,5,0,416,32,*(u16 *)p);*(struct MsgBank **)(p+0x14)=func_02045B38(0,2,*(u16 *)(p+2),*(u16 *)p);*(struct WordSet **)(p+0x18)=GF_FONT_Create_EC64(*(u16 *)p);func_0201F5BC(0,1,12,0,*(u16 *)p);*(u32 *)(p+0x1c)=BMP_WIN_Create(0,2,18,27,4,13,1);*(struct Tcbl **)(p+0x24)=TCBL_Create(*(u16 *)p,*(u16 *)p,10,32);*(struct U16Vec **)(p+12)=STRBUF_Create(1024,*(u16 *)p); }


void func_021B9928(char *p)
{
    TCBL_DeleteAllTasks(((struct Obj03359 *)p)->f24);
    TCBL_Destroy(((struct Obj03359 *)p)->f24);
    ((struct Obj03359 *)p)->f24=0;
    func_0201F7A8(((struct Obj03359 *)p)->f1C,0);
    BMP_WIN_Delete(((struct Obj03359 *)p)->f1C);
    STRBUF_Delete(((struct Obj03359 *)p)->fC);
    WORDSET_DeleteStrbufED04(((struct Obj03359 *)p)->f18);
    MSGDATA_Delete(((struct Obj03359 *)p)->f14);
    func_020403F4(0);
    GF_FONT_Delete(((struct Obj03359 *)p)->f10);
    func_021B99D8();
}


void func_021B9970(u16 heap)
{
    unsigned zero;
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9E90);
    func_0203FC28((void *)d_021B9E60);
    zero=0;
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9E70,0);
    func_02049B40(23,7,0,416,32,heap);
    if(GPOWER_GetSpecialPowerId()==20) func_02040EBC(zero,65535);
    else func_02040EBC(zero,zero);
    BMP_WIN_Init(heap);
}


void func_021B99D8(void) { BMP_WIN_Exit();BG_SYS_Delete(); }


void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind)
{
    void *buffer;
    buffer=STRBUF_Create(1024,((struct Obj01777 *)p)->f0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01777 *)p)->f1C),15);
    func_02045CAC(((struct Obj01777 *)p)->f14,entry,buffer);
    func_0201F02C(((struct Obj01777 *)p)->f18,0,((struct Obj01777 *)p)->f8);
    func_0201F250(((struct Obj01777 *)p)->f18,((struct Obj01777 *)p)->fC,buffer);
    ((struct Obj01777 *)p)->f20=PRINTSYS_PrintStream(((struct Obj01777 *)p)->f1C,index,kind,((struct Obj01777 *)p)->fC,((struct Obj01777 *)p)->f10,MSG_SPEED_GetWait(),((struct Obj01777 *)p)->f24,0,((struct Obj01777 *)p)->f0,3855);
    STRBUF_Delete(buffer);
    func_0201F73C(((struct Obj01777 *)p)->f1C,2,1,12);
}


void func_021B9A68(char *p) { u32 date[4];void *party,*rec;RTC_GetDate(date);party=GAME_DATA_GetMyParty(*(struct BigObj * *)&((struct Obj14630 *)p)->f4);rec=GAME_DATA_GetSaveBlock42(*(void ** *)&((struct Obj14630 *)p)->f4);MISC_SAVEDATA_SnapshotParty(rec,party,(struct Date *)date,4); }


void func_021B9A94(char *p)
{
    void *counter,*date;
    unsigned year,month,day;
    counter=GAME_DATA_GetTrainerRecord(((struct Obj14631 *)p)->f4);
    date=(void *)GAME_DATA_GetPlayTime((int)(((struct Obj14631 *)p)->f4));
    year=func_0200864C(date);
    month=func_02008650(date);
    day=func_02008654(date);
    func_02008D1C(counter,2,day+(year*10000+month*100));
}


void func_021B9AD8(char *p) { void *save,*obj;save=GAME_DATA_GetSaveControl(*(struct Big * *)&((struct Obj14632 *)p)->f4);obj=GAME_DATA_GetTrainerRecord(*(int * *)&((struct Obj14632 *)p)->f4);if(func_020071F0(save)==0)func_02008DAC(obj,71,1); }


void func_021B9B04(char *p) { if(func_02008DFC(GAME_DATA_GetTrainerRecord(*(int * *)&((struct Obj14633 *)p)->f4),71)==0)FIELD_CLOCK_SaveTimestamp(*(char * *)&((struct Obj14633 *)p)->f4); }


void func_021B9B20(char *p)
{
    unsigned date[4];
    void *save,*object,*record;
    RTC_GetDate((struct RTCDate *)date);
    object=GAME_DATA_GetMyParty(((struct Obj08386 *)p)->f4);
    save=GAME_DATA_GetSaveControl(((struct Obj08386 *)p)->f4);
    SAVE_CONTROL_LoadExtraSave(save,8,4);
    record=func_020073D8(save,8,0);
    if(func_020071F0(save)==0) {
        MISC_SAVEDATA_AppendPartyRecord(record,object,date,4);
        GAME_DATA_PartSaveStart(((struct Obj08386 *)p)->f4,8);
        ((struct Obj08386 *)p)->f38=1;
    }
}


void func_021B9B78(char *p) { void *save; u32 n;save=GAME_DATA_GetSaveControl(*(struct Big * *)&((struct Obj10884 *)p)->f4);if(func_020071F0(save)==0) { n=GAME_DATA_PartSaveMain(*(char * *)&((struct Obj10884 *)p)->f4,8);if(n-2<=1) { func_020072A4(save,8);((struct Obj10884 *)p)->f3C=1; } } }


int func_021B9BAC(struct Obj0203159C *obj,u32 unused,char *ctx) { char *p;GFL_HEAP_CreateChildHeap(1,84,0x40000);p=PROCSYS_AllocProcWork(obj,28,84);func_02082A7C(0,p,28);((struct Obj10885 *)p)->f0=84;((struct Obj10885 *)p)->f4=((struct Obj14634 *)ctx)->f4;((struct Obj10885 *)p)->f8=((struct Obj14634 *)ctx)->f8;return 1; }


int func_021B9BE4(void *input,u32 *state,u32 unused,char *p)
{
    u32 keys;
    void *obj;
    keys=KEY_GetTrg();
    switch(*state){
    case 0:
        func_0208068C(511);MIi_CpuClearFast(0,0x6800000,0xa4000);func_02080B98();
        func_021B9D58(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f18=GF_FONT_Create(23,0,0,0,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->fC=func_02045B38(0,2,37,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f10=GF_FONT_Create_EC64(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f14=(void *)BMP_WIN_Create(0,2,7,27,15,13,1);
        if(((struct Obj01293 *)p)->f4==0)SAVE_SCREEN_PrintText(p,3,6,0);
        else SAVE_SCREEN_PrintText(p,2,6,0);
        obj=((struct Obj01293 *)p)->f14;
        BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4(BMP_WIN_GetBgLayer(obj));
        GFL_NET_RestartWithDefaultTimeout(1,((struct Obj01293 *)p)->f0);BG_SYS_SetMainPlaneVisible(16,1);
        (*state)++;break;
    case 1:
        FADE_Start(3,16,0,0);*(u16 *)0x04000050=0;
        (*state)++;break;
    case 2:
        if(!FADE_IsActive())(*state)++;
        break;
    case 3:
        if((keys&1)||(keys&2)){FADE_Start(3,0,16,0);(*state)++;}
        break;
    case 4:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(((struct Obj01293 *)p)->f14),0);(*state)++;}
        break;
    case 5:
        func_0201F7A8(((struct Obj01293 *)p)->f14,0);BMP_WIN_Delete(((struct Obj01293 *)p)->f14);
        WORDSET_DeleteStrbufED04(((struct Obj01293 *)p)->f10);MSGDATA_Delete(((struct Obj01293 *)p)->fC);
        func_020403F4(0);GF_FONT_Delete(((struct Obj01293 *)p)->f18);func_021B9DAC();return 1;
    }
    return 0;
}



int func_021B9D48(void *p)
{
    func_020315D4(p);
    func_020306F0(0x54);
    return 1;
}


void func_021B9D58(u16 heap)
{
    BG_SYS_Create(heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9EFC);
    func_0203FC28((void *)d_021B9ECC);
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)d_021B9EDC,0);
    func_02049B40(23,7,0,416,32,heap);
    func_02040EBC(0,0);
    BMP_WIN_Init(heap);
}


void func_021B9DAC(void) { BMP_WIN_Exit();BG_SYS_Delete(); }

void SAVE_SCREEN_PrintText(char *p,u32 index,s16 x,s16 y)
{
    struct U16Vec *a,*b;
    a=STRBUF_Create(0x400,*(u16 *)p);
    b=STRBUF_Create(0x400,*(u16 *)p);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),15);
    MSGDATA_ReadString(*(struct MsgBank **)(p+12),index,a);
    func_0201F02C(*(struct WordSet **)(p+16),1,*(void **)(p+8));
    func_0201F250(*(struct WordSet **)(p+16),b,a);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),x,y,b,*(void **)(p+24));
    STRBUF_Delete(a);
    STRBUF_Delete(b);
    BMP_WIN_TransferChars(*(struct Descriptor **)(p+20));
    func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor **)(p+20)));
}

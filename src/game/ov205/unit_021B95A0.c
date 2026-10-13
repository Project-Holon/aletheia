/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B95F4, func_021B9864, func_021B9874, func_021B9928, func_021B9970, func_021B99D8, func_021B99E4, func_021B9A68, func_021B9A94, func_021B9AD8, func_021B9B04, func_021B9B20, func_021B9B78, func_021B9BAC, func_021B9BE4, func_021B9D48, func_021B9D58, func_021B9DAC
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
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 *   init 0x021B9E50 data a2
 *   func_020362DC 0x020362DC arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02012DAC 0x02012DAC thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   func_02031140 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02045088 0x02045088 arm
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02088864 0x02088864 arm
 *   func_02012934 0x02012934 thumb
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   func_0200EA3C 0x0200EA3C thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_02008654 0x02008654 thumb
 *   func_02008D1C 0x02008D1C thumb
 *   func_02008DAC 0x02008DAC thumb
 *   func_02008DFC 0x02008DFC thumb
 *   func_02169120 0x02169120 thumb ov010
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200EBD0 0x0200EBD0 thumb
 *   func_02012E4C 0x02012E4C thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 *   func_021B9DB8 0x021B9DB8 thumb ov205
 *   func_0203D34C 0x0203D34C arm
 *   func_020434DC 0x020434DC arm
 *   d_021B9EFC 0x021B9EFC data a4
 *   d_021B9ECC 0x021B9ECC data a4
 *   d_021B9EDC 0x021B9EDC data a4
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

extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(unsigned,void *,unsigned);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern u32 func_020362DC(void);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_0207E468(void *,u32,u32);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_020061E4(u32);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int func_02012DAC(int);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern int func_02012DD0(u8 *p);
extern void func_0202F038(u8 *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
extern void TIME_ICON_Update(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_0204363C(u32);
extern void func_0208068C(u32);
extern void func_02082AC0(u32,u32,u32);
extern void func_02080B98(void);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern struct Tcbl *func_0203101C(u32,u16,u32,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *,unsigned);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_020403F4(unsigned);
extern u32 func_0201D83C(void *ptr);
extern void func_0203F8F4(u16);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040EBC(unsigned,unsigned);
extern void func_02045088(u16);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,unsigned,unsigned,void *,void *,unsigned,void *,unsigned,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_02088864(void *);
extern void *func_02012934(const struct BigObj *);
extern void *GAME_DATA_GetSaveBlock42(void **);
extern void func_0200EA3C(struct Rec *,void *,struct Date *,u32);
extern void *func_02012F2C(int *p);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u8 func_02008654(const struct PlayTime *p);
extern u32 func_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
extern u32 func_02008DAC(struct Sub02008C20Obj *,int,u32);
extern u32 func_02008DFC(struct Sub02008C20Obj *,int);
extern void func_02169120(void *);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern void func_0200EBD0(struct Obj *obj, void *a1, void *date, u32 heap);
extern void func_02012E4C(u8 *p, u32 a);
extern int func_02012E7C(char *,int);
extern void func_020072A4(struct Sub020072A4Ctrl *,u32);
extern void func_021B9DB8(char *p, u32 index, s16 x, s16 y);
extern void func_0203D34C(u32,u32);
extern void func_020434DC(u32 mask, u32 enable);
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
extern const Init init;
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
extern const unsigned d_021B9EFC[],d_021B9ECC[],d_021B9EDC[];

int func_021B95A0(void *owner,int unused,void **args)
{
    void *context;
    char *p;
    context=*args;
    func_0203064C(1,84,1<<18);
    p=func_0203159C(owner,76,84);
    func_02082A7C(0,p,76);
    ((struct Obj04611 *)p)->f0=84;
    ((struct Obj04611 *)p)->f2=36;
    ((struct Obj04611 *)p)->f4=func_020120F4(context);
    ((struct Obj04611 *)p)->f8=func_02012944(((struct Obj04611 *)p)->f4);
    if(func_020071F0(func_02012EBC(((struct Obj04611 *)p)->f4))!=0)
        ((struct Obj04611 *)p)->f40=1;
    return 1;
}

int func_021B95F4(void *unused,State *state,const char *context,char *p)
{
    Init local;
    void *obj;
    enum { M3=3,M12=12 } mode;
    local=init;
    func_020362DC();
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
        func_0204E720(mode,16,zero,zero);(*state)++;break;
    }
    case 2:if(!func_0204E804())*state=3;break;
    case 3:
        if(((struct Obj00419 *)p)->f40!=0){ (*state)++; break; }
        {
            func_020061E4(0x54c);func_021B99E4(p,3,0,0);
            obj=((struct Obj00419 *)p)->f1C;func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            ((struct Obj00419 *)p)->f44=4;*state=13;func_02012DAC(*(int *)&((struct Obj00419 *)p)->f4);
        }
        break;
    case 4:
        if(((struct Obj00419 *)p)->f40==0){
            if(((struct Obj25393 *)context)->f4==0){func_021B9A68(p);func_021B9A94(p);}
            else {func_021B9B04(p);func_021B9AD8(p);func_021B9B20(p);}
        }
        ((struct Obj00419 *)p)->f30=func_0202EE8C(*(u32 *)&((struct Obj00419 *)p)->f24,((struct Obj00419 *)p)->f1C,15,16,((struct Obj00419 *)p)->f0);
        (*state)++;break;
    case 5:
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f38!=0){
            func_021B9B78(p);
            if(((struct Obj00419 *)p)->f3C!=0)(*state)++;
        }else (*state)++;
        break;
    case 6:
        if(((struct Obj00419 *)p)->f40==0){
            switch(func_02012DD0(((struct Obj00419 *)p)->f4)){
            case 0:case 1:break;
            case 2:((struct Obj00419 *)p)->f34=1;(*state)++;break;
            case 3:((struct Obj00419 *)p)->f34=0;(*state)++;break;
            }
        }else (*state)++;
        break;
    case 7:
        func_0202F038(((struct Obj00419 *)p)->f30);
        if(((struct Obj00419 *)p)->f40==0 && ((struct Obj00419 *)p)->f34!=0){
            func_021B99E4(p,4,0,0);
            obj=((struct Obj00419 *)p)->f1C;func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;func_020061E4(0x558);
        }else{
            func_021B99E4(p,5,0,0);
            obj=((struct Obj00419 *)p)->f1C;func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            ((struct Obj00419 *)p)->f44=8;*state=13;
        }
        break;
    case 8:
        if(((struct Obj00419 *)p)->f48>120)(*state)++;
        (((struct Obj00419 *)p)->f48)++;break;
    case 9:
        if(GPOWER_GetSpecialPowerId()==21){ func_0204E720(3,0,16,0); }
        else { func_0204E720(12,0,16,0); }
        (*state)++;break;
    case 10:
        if(!func_0204E804()){func_02043B5C(func_02045770(((struct Obj00419 *)p)->f1C),15);(*state)++;}
        break;
    case 11:func_021B9928(p);(*state)++;break;
    case 12:return 1;
    case 13:
        if(func_02028484((struct Blk *)(p+40),((struct Obj00419 *)p)->f20))*state=((struct Obj00419 *)p)->f44;
        break;
    }
    if(((struct Obj00419 *)p)->f24)func_020310C4(((struct Obj00419 *)p)->f24);
    if(((struct Obj00419 *)p)->f30)TIME_ICON_Update(((struct Obj00419 *)p)->f30);
    return 0;
}


int func_021B9864(void *p)
{
    func_020315D4(p);
    func_020306F0(0x54);
    return 1;
}

void func_021B9874(char *p, const char *a1) { func_0204363C(1);func_0208068C(511);func_02082AC0(0,0x6800000,0xa4000);func_02080B98();func_021B9970(*(u16 *)p);*(struct GfFont **)(p+0x10)=func_0201D7EC(23,0,0,0,*(u16 *)p);func_02049B40(23,5,0,416,32,*(u16 *)p);*(struct MsgBank **)(p+0x14)=func_02045B38(0,2,*(u16 *)(p+2),*(u16 *)p);*(struct WordSet **)(p+0x18)=func_0201EC64(*(u16 *)p);func_0201F5BC(0,1,12,0,*(u16 *)p);*(u32 *)(p+0x1c)=func_020450F0(0,2,18,27,4,13,1);*(struct Tcbl **)(p+0x24)=func_0203101C(*(u16 *)p,*(u16 *)p,10,32);*(struct U16Vec **)(p+12)=func_020457B0(1024,*(u16 *)p); }

void func_021B9928(char *p)
{
    TCBL_DeleteAllTasks(((struct Obj03359 *)p)->f24);
    func_02031140(((struct Obj03359 *)p)->f24);
    ((struct Obj03359 *)p)->f24=0;
    func_0201F7A8(((struct Obj03359 *)p)->f1C,0);
    func_020452E8(((struct Obj03359 *)p)->f1C);
    func_02045808(((struct Obj03359 *)p)->fC);
    func_0201ED04(((struct Obj03359 *)p)->f18);
    func_02045C04(((struct Obj03359 *)p)->f14);
    func_020403F4(0);
    func_0201D83C(((struct Obj03359 *)p)->f10);
    func_021B99D8();
}

void func_021B9970(u16 heap)
{
    unsigned zero;
    func_0203F8F4(heap);
    func_020433E0((const struct DispVram *)d_021B9E90);
    func_0203FC28((void *)d_021B9E60);
    zero=0;
    func_0203FCA0(0,(const struct BgTemplate *)d_021B9E70,0);
    func_02049B40(23,7,0,416,32,heap);
    if(GPOWER_GetSpecialPowerId()==20) func_02040EBC(zero,65535);
    else func_02040EBC(zero,zero);
    func_02045088(heap);
}

void func_021B99D8(void) { func_020450C8();func_0203F9B4(); }

void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind)
{
    void *buffer;
    buffer=func_020457B0(1024,((struct Obj01777 *)p)->f0);
    func_02043B5C(func_02045770(((struct Obj01777 *)p)->f1C),15);
    func_02045CAC(((struct Obj01777 *)p)->f14,entry,buffer);
    func_0201F02C(((struct Obj01777 *)p)->f18,0,((struct Obj01777 *)p)->f8);
    func_0201F250(((struct Obj01777 *)p)->f18,((struct Obj01777 *)p)->fC,buffer);
    ((struct Obj01777 *)p)->f20=func_0201CCE4(((struct Obj01777 *)p)->f1C,index,kind,((struct Obj01777 *)p)->fC,((struct Obj01777 *)p)->f10,func_02012FFC(),((struct Obj01777 *)p)->f24,0,((struct Obj01777 *)p)->f0,3855);
    func_02045808(buffer);
    func_0201F73C(((struct Obj01777 *)p)->f1C,2,1,12);
}

void func_021B9A68(char *p) { u32 date[4];void *party,*rec;func_02088864(date);party=func_02012934(*(struct BigObj * *)&((struct Obj14630 *)p)->f4);rec=GAME_DATA_GetSaveBlock42(*(void ** *)&((struct Obj14630 *)p)->f4);func_0200EA3C(rec,party,(struct Date *)date,4); }

void func_021B9A94(char *p)
{
    void *counter,*date;
    unsigned year,month,day;
    counter=func_02012F2C(((struct Obj14631 *)p)->f4);
    date=(void *)func_02012FCC((int)(((struct Obj14631 *)p)->f4));
    year=func_0200864C(date);
    month=func_02008650(date);
    day=func_02008654(date);
    func_02008D1C(counter,2,day+(year*10000+month*100));
}

void func_021B9AD8(char *p) { void *save,*obj;save=func_02012EBC(*(struct Big * *)&((struct Obj14632 *)p)->f4);obj=func_02012F2C(*(int * *)&((struct Obj14632 *)p)->f4);if(func_020071F0(save)==0)func_02008DAC(obj,71,1); }

void func_021B9B04(char *p) { if(func_02008DFC(func_02012F2C(*(int * *)&((struct Obj14633 *)p)->f4),71)==0)func_02169120(*(char * *)&((struct Obj14633 *)p)->f4); }

void func_021B9B20(char *p)
{
    unsigned date[4];
    void *save,*object,*record;
    func_02088864((struct RTCDate *)date);
    object=func_02012934(((struct Obj08386 *)p)->f4);
    save=func_02012EBC(((struct Obj08386 *)p)->f4);
    SAVE_CONTROL_LoadExtraSave(save,8,4);
    record=func_020073D8(save,8,0);
    if(func_020071F0(save)==0) {
        func_0200EBD0(record,object,date,4);
        func_02012E4C(((struct Obj08386 *)p)->f4,8);
        ((struct Obj08386 *)p)->f38=1;
    }
}

void func_021B9B78(char *p) { void *save; u32 n;save=func_02012EBC(*(struct Big * *)&((struct Obj10884 *)p)->f4);if(func_020071F0(save)==0) { n=func_02012E7C(*(char * *)&((struct Obj10884 *)p)->f4,8);if(n-2<=1) { func_020072A4(save,8);((struct Obj10884 *)p)->f3C=1; } } }

int func_021B9BAC(struct Obj0203159C *obj,u32 unused,char *ctx) { char *p;func_0203064C(1,84,0x40000);p=func_0203159C(obj,28,84);func_02082A7C(0,p,28);((struct Obj10885 *)p)->f0=84;((struct Obj10885 *)p)->f4=((struct Obj14634 *)ctx)->f4;((struct Obj10885 *)p)->f8=((struct Obj14634 *)ctx)->f8;return 1; }

int func_021B9BE4(void *input,u32 *state,u32 unused,char *p)
{
    u32 keys;
    void *obj;
    keys=func_020362DC();
    switch(*state){
    case 0:
        func_0208068C(511);func_02082AC0(0,0x6800000,0xa4000);func_02080B98();
        func_021B9D58(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f18=func_0201D7EC(23,0,0,0,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->fC=func_02045B38(0,2,37,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f10=func_0201EC64(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f14=(void *)func_020450F0(0,2,7,27,15,13,1);
        if(((struct Obj01293 *)p)->f4==0)func_021B9DB8(p,3,6,0);
        else func_021B9DB8(p,2,6,0);
        obj=((struct Obj01293 *)p)->f14;
        func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
        func_0203D34C(1,((struct Obj01293 *)p)->f0);func_020434DC(16,1);
        (*state)++;break;
    case 1:
        func_0204E720(3,16,0,0);*(u16 *)0x04000050=0;
        (*state)++;break;
    case 2:
        if(!func_0204E804())(*state)++;
        break;
    case 3:
        if((keys&1)||(keys&2)){func_0204E720(3,0,16,0);(*state)++;}
        break;
    case 4:
        if(!func_0204E804()){func_02043B5C(func_02045770(((struct Obj01293 *)p)->f14),0);(*state)++;}
        break;
    case 5:
        func_0201F7A8(((struct Obj01293 *)p)->f14,0);func_020452E8(((struct Obj01293 *)p)->f14);
        func_0201ED04(((struct Obj01293 *)p)->f10);func_02045C04(((struct Obj01293 *)p)->fC);
        func_020403F4(0);func_0201D83C(((struct Obj01293 *)p)->f18);func_021B9DAC();return 1;
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
    func_0203F8F4(heap);
    func_020433E0((const struct DispVram *)d_021B9EFC);
    func_0203FC28((void *)d_021B9ECC);
    func_0203FCA0(0,(const struct BgTemplate *)d_021B9EDC,0);
    func_02049B40(23,7,0,416,32,heap);
    func_02040EBC(0,0);
    func_02045088(heap);
}

void func_021B9DAC(void) { func_020450C8();func_0203F9B4(); }

/*
 * function: func_021D9090
 * address: 0x021D9090
 * packet: pkt_ov175_021D9090
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Lever: byte range test uses (u8)(value + 255), preserving adds #255.
 * Extent: final 021D9342..021D9344 is zero alignment padding.
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021D97E4 0x021D97E4 thumb ov175
 *   func_021DD020 0x021DD020 thumb ov175
 *   func_021DC8B4 0x021DC8B4 thumb ov175
 *   func_021DC908 0x021DC908 thumb ov175
 *   func_02167ED8 0x02167ED8 arm ov009
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   RTC_ConvertDateTimeToSecond 0x02089004 arm
 *   RTC_ConvertSecondToDateTime 0x020891E0 arm
 *   RTC_ConvertDateToDay 0x02088F58 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0200FA84 0x0200FA84 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
#include "../include/Obj00728.h"
#include "../include/Obj08277.h"
typedef unsigned long u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef long long s64;
struct RTCDate { u32 year,month,day,week; };
struct RTCTime { u32 hour,minute,second; };
struct Request { u8 a,b,c,d; u32 id; };
struct Obj;
struct Reg2;
extern void func_021E8738(int *p, int a, int b, int c);
struct Big;
extern void func_021E8AB4(u32,u32);
extern void func_021E8AB8(u32);
extern void func_021E8AA8(int a);
extern int func_021E8844(const int *p);
extern void func_021D97E4(char *,u32);
extern u32 func_021DD020(char *);
extern void func_021DC8B4(char *,void *,unsigned);
extern int func_021DC908(char *);
extern int GFL_NET_GetRunState(void);
extern int func_02167ED8(void *date, void *time);
extern void func_0200FA84(void);
typedef signed int     s32;
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern void RTC_ConvertSecondToDateTime(struct RTCDate *,struct RTCTime *,s64);
extern s32 RTC_ConvertDateToDay(struct RTCDate *date);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern unsigned int BATTLE_BOX_IsLocked(struct Obj *,unsigned int);
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern void REGULATION_Card_SetValue(struct Reg2 *,unsigned int,int);
extern int GAME_DATA_SaveStart(int),GAME_DATA_SaveMain(u8 *);
extern void MI_CpuFill8(void *,int,unsigned);
void func_021D9090(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00728 *)p)->f104;
    struct RTCDate startDate;
    struct RTCDate endDate;
    struct RTCDate nowDate;
    struct RTCTime nowTime;
    struct Request req;
    struct Reg2 *reg;
    struct Obj *box;
    int got;
    int startDay,endDay,nowDay,v;
    switch(*state) {
    case 0:*state=1;break;
    case 1:reg=*(struct Reg2 * *)&((struct Obj00728 *)p)->f108;
        if(!GFL_NET_GetRunState())func_0200FA84();
        got=func_02167ED8((int *)&nowDate,(int *)&nowTime);
        if(got)RTC_ConvertSecondToDateTime(&nowDate,&nowTime,RTC_ConvertDateTimeToSecond(&nowDate,&nowTime));
        startDate.year=REGULATION_Card_GetValue(reg,4);
        startDate.month=REGULATION_Card_GetValue(reg,5);
        startDate.day=REGULATION_Card_GetValue(reg,6);startDate.week=0;
        endDate.year=REGULATION_Card_GetValue(reg,7);
        endDate.month=REGULATION_Card_GetValue(reg,8);
        endDate.day=REGULATION_Card_GetValue(reg,9);endDate.week=0;
        startDay=RTC_ConvertDateToDay(&startDate);
        endDay=RTC_ConvertDateToDay(&endDate);
        nowDay=RTC_ConvertDateToDay(&nowDate);
        if(got && nowDay<startDay) {((struct Obj00728 *)p)->f40=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {((struct Obj00728 *)p)->f40=0;*state=13;}
        else {((struct Obj00728 *)p)->f40=1;*state=3;}
        break;
    case 2:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,96,1);
        *state=14;func_021E8AB4(sys,13);break;
    case 3:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,80,1);
        *state=14;func_021E8AB4(sys,4);break;
    case 4:if((u8)((*(u8 **)(q+48))[5]+255)<=1) *state=5;
        else *state=13;break;
    case 5:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,40,2);
        *state=14;func_021E8AB4(sys,6);break;
    case 6:box=BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj08277 *)q)->f8));
        ((struct Obj00728 *)p)->f26C=BATTLE_BOX_IsLocked(box,1);
        BATTLE_BOX_ClearLockFlags(box,1);
        REGULATION_Card_SetValue(*(struct Reg2 * *)&((struct Obj00728 *)p)->f108,10,3);
        GAME_DATA_SaveStart(**(int * *)&((struct Obj08277 *)q)->f8);*state=7;break;
    case 7:if(GAME_DATA_SaveMain(**(void ** *)&((struct Obj08277 *)q)->f8)==2) *state=8;break;
    case 8:BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj08277 *)q)->f8));
        if(((struct Obj00728 *)p)->f26C!=0) *state=9;else *state=10;break;
    case 9:func_021D97E4(p,1);
        func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,81,1);
        *state=14;func_021E8AB4(sys,10);break;
    case 10:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,70,2);
        *state=14;func_021E8AB4(sys,11);break;
    case 11:MI_CpuFill8(&req,0,8);req.b=3;
        req.id=func_021DD020(*(char * *)&((struct Obj00728 *)p)->f34);
        (*(u8 **)(*(char * *)&((struct Obj00728 *)p)->f104+48))[5]=3;
        func_021DC8B4(*(char * *)&((struct Obj00728 *)p)->f34,&req,87);*state=12;break;
    case 12:v=func_021DC908(*(char * *)&((struct Obj00728 *)p)->f34);
        if(v==1) *state=13;
        else if(v==3) {((struct Obj00728 *)p)->f40=3;*state=13;}
        break;
    case 13:func_021E8AA8(sys);break;
    case 14:if(func_021E8844((const int *)(((struct Obj00728 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}

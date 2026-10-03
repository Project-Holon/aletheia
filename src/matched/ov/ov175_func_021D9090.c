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
 *   func_0203CD98 0x0203CD98 arm
 *   func_02089004 0x02089004 arm
 *   func_020891E0 0x020891E0 arm
 *   func_02088F58 0x02088F58 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200FA84 0x0200FA84 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBFC 0x0200BBFC thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 */
typedef unsigned long u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef long long s64;
struct RTCDate { u32 year,month,day,week; };
struct RTCTime { u32 hour,minute,second; };
struct Request { u8 a,b,c,d; u32 id; };
struct Obj;
struct Reg2;
extern void func_021E8738(u32,u32,u32,u32);
extern void func_021E8AB4(u32,u32),func_021E8AB8(u32),func_021E8AA8(u32);
extern int func_021E8844(u32);
extern void func_021D97E4(char *,u32);
extern u32 func_021DD020(char *);
extern void func_021DC8B4(char *,void *,unsigned);
extern int func_021DC908(char *);
extern int func_0203CD98(void),func_02167ED8(int *,int *);
extern void func_0200FA84(void);
extern s64 func_02089004(const struct RTCDate *,const struct RTCTime *);
extern void func_020891E0(struct RTCDate *,struct RTCTime *,s64);
extern int func_02088F58(const struct RTCDate *);
extern u32 func_0200B078(struct Reg2 *,u32);
extern void *func_02012EBC(void *),*func_0200BAC8(void *);
extern unsigned int func_0200BBFC(struct Obj *,unsigned int);
extern void func_0200BBD8(struct Obj *,u16),func_0200B110(struct Reg2 *,unsigned int,int);
extern int func_02012DAC(int),func_02012DD0(void *);
extern void func_02082BCC(void *,int,unsigned);
void func_021D9090(u32 sys,int *state,char *p)
{
    char *q=*(char **)(p+260);
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
    case 1:reg=*(struct Reg2 **)(p+264);
        if(!func_0203CD98())func_0200FA84();
        got=func_02167ED8((int *)&nowDate,(int *)&nowTime);
        if(got)func_020891E0(&nowDate,&nowTime,func_02089004(&nowDate,&nowTime));
        startDate.year=func_0200B078(reg,4);
        startDate.month=func_0200B078(reg,5);
        startDate.day=func_0200B078(reg,6);startDate.week=0;
        endDate.year=func_0200B078(reg,7);
        endDate.month=func_0200B078(reg,8);
        endDate.day=func_0200B078(reg,9);endDate.week=0;
        startDay=func_02088F58(&startDate);
        endDay=func_02088F58(&endDate);
        nowDay=func_02088F58(&nowDate);
        if(got && nowDay<startDay) {*(u32 *)(p+64)=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {*(u32 *)(p+64)=0;*state=13;}
        else {*(u32 *)(p+64)=1;*state=3;}
        break;
    case 2:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),96,1);
        *state=14;func_021E8AB4(sys,13);break;
    case 3:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),80,1);
        *state=14;func_021E8AB4(sys,4);break;
    case 4:if((u8)((*(u8 **)(q+48))[5]+255)<=1) *state=5;
        else *state=13;break;
    case 5:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),40,2);
        *state=14;func_021E8AB4(sys,6);break;
    case 6:box=func_0200BAC8(func_02012EBC(**(void ***)(q+8)));
        *(u32 *)(p+620)=func_0200BBFC(box,1);
        func_0200BBD8(box,1);
        func_0200B110(*(struct Reg2 **)(p+264),10,3);
        func_02012DAC(**(int **)(q+8));*state=7;break;
    case 7:if(func_02012DD0(**(void ***)(q+8))==2) *state=8;break;
    case 8:func_0200BAC8(func_02012EBC(**(void ***)(q+8)));
        if(*(u32 *)(p+620)!=0) *state=9;else *state=10;break;
    case 9:func_021D97E4(p,1);
        func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),81,1);
        *state=14;func_021E8AB4(sys,10);break;
    case 10:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),70,2);
        *state=14;func_021E8AB4(sys,11);break;
    case 11:func_02082BCC(&req,0,8);req.b=3;
        req.id=func_021DD020(*(char **)(p+52));
        (*(u8 **)(*(char **)(p+260)+48))[5]=3;
        func_021DC8B4(*(char **)(p+52),&req,87);*state=12;break;
    case 12:v=func_021DC908(*(char **)(p+52));
        if(v==1) *state=13;
        else if(v==3) {*(u32 *)(p+64)=3;*state=13;}
        break;
    case 13:func_021E8AA8(sys);break;
    case 14:if(func_021E8844(*(u32 *)(p+44)))func_021E8AB8(sys);break;
    }
}

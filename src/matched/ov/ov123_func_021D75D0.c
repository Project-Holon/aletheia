/*
 * function: func_021D75D0
 * address: 0x021D75D0
 * packet: pkt_ov123_021D75D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D758C 0x021D758C thumb ov123
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02030734 0x02030734 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02009108 0x02009108 thumb
 *   d_021DAB78 0x021DAB78 data ov123 a1
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb  arm9
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */
#include "../include/Obj03793.h"
#include "../include/Obj22959.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Big;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_021D5BA0(char *p);
typedef unsigned int   u32;
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int SAVE_CONTROL_LoadExtraSaveWithBuffer(int,int,u16,int,int);
extern void MI_CpuCopy8(const void *,void *,int);
extern void func_0200E8E0(void *obj, u32 value);
extern void GAME_DATA_PartSaveStart(u8 *,u32);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6FF0(char *p);
extern void func_021D76B8(char *p);
extern void func_021D758C(u8 *a);
extern const char d_021DAB78[];
void func_021D75D0(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj03793 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj03793 *)a)->f8));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=((struct Obj22959 *)p)->f2600) {
        ((struct Obj03793 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x345);
        return;
    }
    ((struct Obj03793 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj03793 *)a)->f0,0x3000,0,d_021DAB78,0x34a);
    ((struct Obj03793 *)a)->f40=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,4,((struct Obj03793 *)a)->f0,x,0x3000);
    MI_CpuCopy8(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    GAME_DATA_PartSaveStart((u8 *)((struct Obj03793 *)a)->f2C,4);
    func_021D6EE0((u8 *)a,(int)func_021D758C,0x355);
}

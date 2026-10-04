/*
 * function: func_021B9BE4
 * address: 0x021B9BE4
 * packet: pkt_ov205_021B9BE4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   func_021B9D58 0x021B9D58 thumb ov205
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_021B9DB8 0x021B9DB8 thumb ov205
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020434DC 0x020434DC arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B9DAC 0x021B9DAC thumb ov205
 */
#include "../include/Obj01293.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_020362DC(void *);
extern void func_0208068C(u32);
extern void func_02082AC0(u32,u32,u32);
extern void func_02080B98(void);
extern void func_021B9D58(u16);
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct WordSet;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021B9DB8(char *,u32,u32,u32);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0203D34C(u32,u32);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F7A8(void *,u32);
extern void func_020452E8(struct Descriptor *d);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_020403F4(u32);
extern void func_0201D83C(void *);
extern void func_021B9DAC(void);
int func_021B9BE4(void *input,u32 *state,u32 unused,char *p)
{
    u32 keys;
    void *obj;
    keys=func_020362DC(input);
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

/*
 * function: func_021F0754
 * address: 0x021F0754
 * packet: pkt_ov107_021F0754
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02087D28 0x02087D28 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_021F5904 0x021F5904 arm ov107
 *   func_02034714 0x02034714 arm
 *   func_021F5B4C 0x021F5B4C arm ov107
 *   func_021F1B3C 0x021F1B3C arm ov107
 *   func_021F0D1C 0x021F0D1C thumb ov107
 *   func_021F0B2C 0x021F0B2C thumb ov107
 *   d_021F6EB4 0x021F6EB4 data a4
 *   d_021F6E1C 0x021F6E1C data a4
 *   d_021F6EAC 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 f00,f01,f02,f03;u16 f04[10];u16 f18,f1A;u16 f1C[26];u16 f50,f52;u8 f54;} User;
typedef struct {u8 f00:4;u8 f00hi:4;u8 f01;u16 f02[10];} MBUser;
typedef struct {u32 words[5];} Zero;
struct OSOwnerInfoEx;
extern void func_02087D28(struct OSOwnerInfoEx *info);extern void func_02082D44(const void *,void *,u32);extern void *func_0203D7C8(u32,u32,const char *,u16);extern int func_021F5904(void *,MBUser *,int,int,u16);extern void func_02034714(void *,int,void *);extern int func_021F5B4C(u16,u16);extern void func_021F1B3C(void (*)(u16,u32,void *));extern void func_021F0D1C(u16);extern void func_021F0B2C(u16,u32,void *);
extern Zero d_021F6EB4;extern struct Masks d_021F6EAC;extern u8 d_021F6E1C[],d_021F6E24[];
void func_021F0754(int a,int b){User user;MBUser mb;u8 buffer[20];Zero *zero;
func_02087D28((struct OSOwnerInfoEx *)(&user));mb.f00=user.f01;mb.f01=user.f1A;func_02082D44(user.f04,mb.f02,user.f1A*2);mb.f00hi=0;
zero=(Zero *)buffer;zero->words[0]=0;zero->words[1]=0;zero->words[2]=0;zero->words[3]=0;zero->words[4]=0;d_021F6EB4=*zero;
d_021F6EAC.f04=func_0203D7C8(93,45312,(const char *)d_021F6E1C,158);
if(func_021F5904(d_021F6EAC.f04,&mb,a,b,1))func_02034714(d_021F6E24,0,d_021F6E24);
func_021F5B4C(256,1);func_021F1B3C(func_021F0B2C);func_021F0D1C(1);}

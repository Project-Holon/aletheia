/*
 * function: func_0220B55C
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
 *   func_02082BCC 0x02082BCC arm
 *   file_0220BC38 0x0220BC38 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0220B954 0x0220B954 thumb ov207
 *   func_0220B944 0x0220B944 thumb ov207
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
extern void func_02082BCC(void *,int,int);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201EE84(struct WordSet *,u32,void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_02045808(struct U16Vec *);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_0201ED04(struct WordSet *);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern struct Tcbl *func_0203101C(u32,u16,u32,u32);
extern void func_0201DD78(u32,u32,u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern u8 func_020355C4(void);
extern void func_0220B954(u32 *);
extern void func_0220B944(void *a, u32 *p);
extern void *func_020056A0(u32,u32,u32);
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
    *(struct U16Vec * *)&((struct Obj00174 *)p)->f2C=func_020457B0(64,((struct Obj00174 *)p)->f0);
    func_0201F250(ws,((struct Obj00174 *)p)->f2C,str);
    func_02045808(str);
    func_02045C04((struct Rec *)bank);
    func_0201ED04(ws);
    *(u32 *)&((struct Obj00174 *)p)->f38=func_020450F0(3,0,0,1,1,9,0);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38),0);
    func_02045334(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38);
    func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj00174 *)p)->f38));
    *(struct Tcbl * *)&((struct Obj00174 *)p)->f34=func_0203101C(((struct Obj00174 *)p)->f0,((struct Obj00174 *)p)->f0,1,0);
    *(u32 *)&((struct Obj00174 *)p)->f24=func_020450F0(3,1,19,30,4,9,1);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00174 *)p)->f24),15);
    func_0201DD78(1,2,15);
    ((struct Obj00174 *)p)->f28=func_0201CCE4(*(u32 *)&((struct Obj00174 *)p)->f24,0,0,*(u32 *)&((struct Obj00174 *)p)->f2C,((struct Obj00174 *)p)->f18,func_02012FFC(),*(u32 *)&((struct Obj00174 *)p)->f34,2,((struct Obj00174 *)p)->f0,15);
    ((struct Obj00174 *)p)->f30=func_0201F5DC((void *)3,8,0,((struct Obj00174 *)p)->f0);
    enabled=1;
    if(func_020355C4()!=0) enabled=0;
    ((struct Obj00174 *)p)->f50=enabled;
    func_0220B954((u32 *)p);
    ((struct Obj00174 *)p)->f48=func_020056A0((u32)func_0220B944,(u32)p,1);
    return p;
}

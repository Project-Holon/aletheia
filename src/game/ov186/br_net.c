/*
 * file:     br_net.c
 * unit:     yes
 * function: func_021FEEF4, func_021FF004, func_021FF01C, func_021FF028, func_021FF02C, func_021FF038, func_021FF074, func_021FF0A0, func_021FF248, func_021FF334, func_021FF408, func_021FF4E4, func_021FF52C, func_021FF54C, func_021FF648, func_021FF660, func_021FF67C, func_021FF698, func_021FF6B4, func_021FF6DC, func_021FF704, func_021FF72C, func_021FF88C, func_021FF8D4, func_021FF8E0, func_021FF8E4, func_021FF900, func_021FF938, func_021FF968, func_021FF99C, func_021FF9D0, func_021FFA14, func_021FFA40, func_021FFA6C, func_021FFA98, func_021FFB14, func_021FFB50, func_021FFB58, func_021FFB68, func_021FFB70, func_021FFB80, func_021FFBD4, func_021FFC6C, func_021FFC9C, func_021FFE34, func_021FFE5C, func_021FFE70, func_021FFE90, func_021FFEA8, func_021FFF1C, func_021FFF28, func_021FFFCC, func_021FFFF8, func_022000D0, func_022000F0, func_0220014C, func_02200188
 * address:  0x021FEEF4
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   sub_02034714 0x02034714 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   sub_0204B294 0x0204B294 arm
 *   sub_0204B570 0x0204B570 arm
 *   sub_0204B5D4 0x0204B5D4 arm
 *   sub_0204B688 0x0204B688 arm
 *   sub_0204B3DC 0x0204B3DC arm
 *   d_02200D88 0x02200D88 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0203F684 0x0203F684 arm
 *   func_0204B5E4 0x0204B5E4 arm
 *   ov125_id 0x0000007D data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021D6660 0x021D6660 thumb ov125
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D59C 0x0200D59C thumb
 *   func_0200D5D0 0x0200D5D0 thumb
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   d_02200D8C 0x02200D8C data a1
 *   func_0200D5C8 0x0200D5C8 thumb
 *   func_021D6770 0x021D6770 thumb ov125
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021D6A34 0x021D6A34 thumb ov125
 *   func_02034714 0x02034714 arm
 *   d_02200D98 0x02200D98 data a1
 *   func_021D7374  0x021D7374  thumb  ov125
 *   func_021D73E0 0x021D73E0 thumb ov125
 *   func_021D74D8  0x021D74D8  thumb  ov125
 *   func_021D7414 0x021D7414 thumb ov125
 *   func_021D72EC 0x021D72EC thumb ov125
 *   func_021D72F8 0x021D72F8 thumb ov125
 *   func_02006210 0x02006210 thumb
 *   func_0200FB4C 0x0200FB4C thumb
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_021D730C  0x021D730C  thumb  ov125
 *   func_021D67C8 0x021D67C8 thumb ov125
 *   func_021D6814 0x021D6814 thumb ov125
 *   func_021D683C 0x021D683C thumb ov125
 *   func_021D69DC 0x021D69DC thumb ov125
 *   func_021D68EC 0x021D68EC thumb ov125
 *   func_021D6968 0x021D6968 thumb ov125
 *   func_021D69B4 0x021D69B4 thumb ov125
 *   func_021D698C 0x021D698C thumb ov125
 *   func_021D6A08 0x021D6A08 thumb ov125
 *   func_02012E40 0x02012E40 thumb
 *   func_021D7124 0x021D7124 thumb ov125
 *   func_0201C440 0x0201C440 thumb
 *   func_02200228 0x02200228 thumb ov186
 *   d_02200D9C 0x02200D9C data a1
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   d_02200DAC 0x02200DAC data
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F898 0x0201F898 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   d_020A7370 0x020A7370 data
 *   d_02200CA8 0x02200CA8 data
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   d_02200CD0 0x02200CD0 data a1
 *   func_0200D064 0x0200D064 thumb
 *   d_02200C94 0x02200C94 data a4
 */
#include "../../matched/include/Obj02527.h"
#include "../../matched/include/Obj24851.h"
#include "../../matched/include/Obj24854.h"
#include "../../matched/include/Obj06636.h"
#include "../../matched/include/Obj05508.h"
#include "../../matched/include/Obj00153.h"
#include "../../matched/include/Obj00595.h"
#include "../../matched/include/Obj06637.h"
#include "../../matched/include/Obj08336.h"
#include "../../matched/include/Obj14477.h"
#include "../../matched/include/Obj24855.h"
#include "../../matched/include/Obj24856.h"
#include "../../matched/include/Obj24858.h"
#include "../../matched/include/Obj24860.h"
#include "../../matched/include/Obj24861.h"
#include "../../matched/include/Obj24862.h"
#include "../../matched/include/Obj24863.h"
#include "../../matched/include/Obj24864.h"
#include "../../matched/include/Obj14481.h"
#include "../../matched/include/Obj24865.h"
#include "../../matched/include/Obj24866.h"
#include "../../matched/include/Obj14482.h"
#include "../../matched/include/Obj08337.h"
#include "../../matched/include/Obj14483.h"
#include "../../matched/include/Obj24867.h"
#include "../../matched/include/Obj24868.h"
#include "../../matched/include/Obj24869.h"
#include "../../matched/include/Obj24870.h"
#include "../../matched/include/Obj24871.h"
#include "../../matched/include/Obj24872.h"
#include "../../matched/include/Obj24873.h"
#include "../../matched/include/Obj14485.h"
#include "../../matched/include/Obj10800.h"
#include "../../matched/include/Obj01967.h"
#include "../../matched/include/Obj06638.h"
#include "../../matched/include/Obj00221.h"
#include "../../matched/include/Obj24875.h"
#include "../../matched/include/Obj02237.h"
#include "../../matched/include/Obj14486.h"
#include "../../matched/include/Obj04590.h"
#include "../../matched/include/Obj24877.h"
#include "../../matched/include/Obj14487.h"
#include "../../matched/include/Obj24878.h"
#include "../../matched/include/Obj06639.h"
#include "../../matched/include/Obj24879.h"

struct Actor;
struct Obj;
struct Big;
struct GdsProfile;
struct Sub0200852CObj;
struct PrintSys;
struct Work;
struct Slot;
struct MsgBank;
struct U16Vec;
struct Blk37;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {int x,y,z;} Triple;

typedef struct {short x,y,z,pad;u32 word8,wordC,mode,word14;} Config_a;

typedef struct {short x,y,z;u8 pad,flag;} Request_021FEEF4;

typedef signed short s16;

typedef unsigned long u32_021FF0A0;

typedef unsigned long u32_021FF248;

typedef signed int     s32;

typedef unsigned long u32_021FF334;

typedef unsigned long u32_021FF408;

typedef struct {u32_021FF408 value;u32_021FF408 unused;void *owner;void *arg;void *context;void (*a)(char *);void (*b)(char *);void (*c)(char *);void (*d)(char *);void (*e)(char *);void (*f)(char *);} Config;

typedef unsigned int   u32_021FF4E4;

typedef unsigned int u32_021FF52C;

typedef struct {int(*fn_021FEEF4)(void*,void*,int);char pad_04[4];int arg_08;} S_b;

typedef struct {int a,b;} W;

typedef unsigned int   u32_021FF54C;

typedef signed char s8;

typedef struct{int words[32];} Block128;

typedef struct{int words[108];} Block432;

typedef struct {
    int (*fn_021FF968)(void *, void *, int);
    char  pad_04[4];
    int   arg_08;
} S;

typedef struct { int x,y; } Pair;

typedef struct Request_021FF968 { unsigned short x, y, id; unsigned char flag, pad; } Request_021FF968;

typedef struct Work { char pad0[0x14]; unsigned char flags[9]; char pad1[7]; unsigned short heap; unsigned short pad2; char *owner; char pad3[0x10]; void *resource; char *slots[9]; char pad4[0xc]; int state; } Work;

typedef struct { const void *str; u32 param; } Slot;

typedef struct { u32 v[10]; } Config_c;

extern void * func_02082BCC(void *,u32,u32);
extern int func_021FC124(char *,int,Triple *);
extern void sub_02034714(const char *,u32,const char *);
extern struct Obj *sub_0204B294(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void sub_0204B570(struct Actor *,u32);
extern void sub_0204B5D4(struct Actor *,u32,u32);
extern void sub_0204B688(struct Actor *,u32);
extern void sub_0204B3DC(struct Obj *,u32);
extern void func_0204B3B4(struct Obj *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void func_0204B5D4(struct Actor*,u32,u32);
extern s16 func_0204B4EC(struct Actor *actor, u32_021FF0A0 space, u32_021FF0A0 axis);
extern s16 func_0203F684(u16);
extern u32_021FF334 func_0204B5E4(const struct Actor *actor, u32_021FF334 which);
extern int func_02034AC4(int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
extern u8 *func_02012944(void *p);
extern u32_021FF408 func_0200853C(const struct Sub0200852CObj *obj);
extern int func_021D6660(char *p, char *a);
extern void *func_02012EBC(struct Big *p);
extern struct GdsProfile *func_0200D59C(u32_021FF408 heap);
extern void func_0200D5D0(struct GdsProfile *p, void *sys);
extern void func_02156DE0(int a, int b);
extern void func_0200D5C8(struct GdsProfile *p);
extern void func_021D6770(char *p);
extern u32_021FF4E4 func_020307B0(void *p);
extern void func_02034A5C(int);
extern int func_021D6A34(char*);
extern void func_02034714(const char *expr, u32_021FF54C line, const char *file);
extern int func_021D7374(char *a, void **out, int max);
extern unsigned long long func_021D73E0(char *a0);
extern int func_021D74D8(void *unused, char **out);
extern int func_021D7414(char *unused, char *dst, int n);
extern int func_021D72EC(char *,int **);
extern void func_021D72F8(char *);
extern void func_02006210(void);
extern void func_0200FB4C(unsigned int x);
extern int func_02157170(int, int);
extern void func_0200F7DC(void);
extern int func_021D730C(char *p);
extern int func_021D67C8(char*,const Block128*,const Block432*);
extern int func_021D6814(char *,int);
extern int func_021D683C(char *,void *);
extern int func_021D69DC(char *,int,int);
extern int func_021D68EC(char *, int, unsigned, int, unsigned char);
extern int func_021D6968(char *);
extern int func_021D69B4(char *);
extern int func_021D698C(char *);
extern int func_021D6A08(char *p, int a, int b);
extern u8 func_02012E40(const u8 *o);
extern void func_021D7124(char *, int, int, int);
extern u32 func_0201C440(void *p);
extern int func_02200228(unsigned short, unsigned *);
extern void func_0201C4C0(struct PrintSys *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(char *,u32,const Pair *);
extern void func_021FCD0C(char *);
extern int func_021FCDA8(char *),func_021FD938(char *),func_021FE7B0(int *);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FC830(void *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void *func_021FB378(void *, int, int, int, int, int, int, int, void *, unsigned short);
extern void func_021FB494(char *p);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *, void *, void *, void *, unsigned short);
extern void func_021FC734(u8 *p);
extern void func_020409B4(u32 index);
extern void func_021FBDA4(int,unsigned);
extern Slot *func_0201F81C(u32,u32);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FC8C8(Config_c *,u32);
extern void func_021FCC80(char *);
extern u32 func_0201F868(void *p);
extern int func_02035C08(const void *);
extern void func_020061E4(u32 a);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
void func_021FEEF4(char *p,u32 owner,char *resources,const Config_a *config,u16 heap);
void func_021FF004(u8 *p);
void func_021FF01C(u8 *p);
int func_021FF028(u32 *p);
void func_021FF02C(u8 *p,u32 v);
void func_021FF038(u8*p,u32 mode);
void func_021FF074(u8*p);
void func_021FF0A0(char *p);
void func_021FF248(char *p);
void func_021FF334(char *p);
char *func_021FF408(void *owner,void *arg,u32_021FF408 heap);
void func_021FF4E4(char *p);
void func_021FF52C(char*p);
void func_021FF54C(char *p,int kind,const int *values);
int func_021FF648(char *p);
int func_021FF660(char *p, int a1, int a2, int *out);
u32 func_021FF67C(u8*p,unsigned long long*out);
int func_021FF698(char *p, int a1, int *out);
int func_021FF6B4(char*p,void*buffer,int count,int*out);
int func_021FF6DC(char*p,void*buffer,int count,int*out);
int func_021FF704(char*p,void*buffer,int count,int*out);
int func_021FF72C(char *p,int *out);
int func_021FF88C(char *p);
int func_021FF8D4(char *p);
void func_021FF8E0(void);
void func_021FF8E4(void *p, int a1, int a2);
void func_021FF900(char*p,int unused,char*q);
void func_021FF938(char *p,int unused,char *q);
void func_021FF968(char *p,int unused,char *q);
void func_021FF99C(char *p,int unused,char *q);
void func_021FF9D0(char *p, int unused, char *q);
void func_021FFA14(char *p,int unused,char *q);
void func_021FFA40(char *p,int unused,char *q);
void func_021FFA6C(char *p,int unused,char *q);
void func_021FFA98(char *p, int unused, char *q);
void func_021FFACC(char *p);
void func_021FFAD8(char *p);
void func_021FFAE4(char *p);
void func_021FFAF0(char *p);
void func_021FFAFC(char *p);
void func_021FFB08(char *p);
char *func_021FFB14(void *p,int f,unsigned heap);
void func_021FFB50(void *p);
void func_021FFB58(S *p);
void func_021FFB68(char *p, int v);
int func_021FFB70(int *p,int value);
int func_021FFB80(char *p, int b, int kind, int d);
char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
void func_021FFC6C(char *p);
int func_021FFC9C(char *p);
unsigned func_021FFE34(char *p);
void func_021FFE5C(char *p);
void func_021FFE70(char *p);
int func_021FFE90(int *p, unsigned short *out);
void func_021FFEA8(char *p);
void func_021FFF1C(char *p);
void func_021FFF28(Work *p);
void func_021FFFCC(u8 *p);
void func_021FFFF8(char *p);
void func_022000D0(u8 *p);
int func_022000F0(char *p);
int func_0220014C(void *p,u32 n,const u16 *ids);
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap);
extern const char d_02200D88[];
extern const char d_02200D8C[];
extern char ov125_id[];
extern const char d_02200D98[];
extern const char d_02200D9C[];
extern char d_02200DAC[];
extern void *d_020A7370;
extern const Config_c d_02200CA8;
extern const char d_02200CD0[];
extern const u16 d_02200C94[];



static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}



/*
 * ABI: sub_0204B294 returns the allocated object pointer in r0.
 */
void func_021FEEF4(char *p,u32 owner,char *resources,const Config_a *config,u16 heap)
{
    Triple triple;
    Request_021FEEF4 request;
    int index;
    func_02082BCC(p,0,0x4c);
    *(Config_a *)(p+0x34)=*config;
    index=4;
    if(config->mode)index=5;
    if(!func_021FC124(resources,index,&triple))sub_02034714(d_02200D88,0,d_02200D88);
    func_02082BCC(&request,0,sizeof(request));
    request.x=config->x;
    request.y=config->y;
    request.flag=1;
    ((struct Obj02527 *)p)->f8=roundFixed(request.x);
    ((struct Obj02527 *)p)->fC=roundFixed(request.y);
    *(int *)&((struct Obj02527 *)p)->f14=config->z;
    *(u32 *)&((struct Obj02527 *)p)->f4=(u32)sub_0204B294((void *)owner,triple.y,triple.z,triple.x,&request,((struct Obj02527 *)p)->f44,heap);
    sub_0204B570(*(struct Actor * *)&((struct Obj02527 *)p)->f4,2);
    sub_0204B5D4(*(struct Actor * *)&((struct Obj02527 *)p)->f4,((struct Obj02527 *)p)->f14,0);
    sub_0204B688(*(struct Actor * *)&((struct Obj02527 *)p)->f4,0);
    sub_0204B3DC(*(struct Obj * *)&((struct Obj02527 *)p)->f4,0);
    ((struct Obj02527 *)p)->f0=1;
}



void func_021FF004(u8 *p){func_0204B3B4(*(struct Obj * *)&((struct Obj24851 *)p)->f4);func_02082BCC(p,0,76);}



void func_021FF01C(u8 *p){void (*f)(u8 *);f=*(void (**)(u8 *))(p+24);if(f)f(p);}



int func_021FF028(u32 *p){return *p;}



void func_021FF02C(u8 *p,u32 v){func_0204B3DC(*(struct Obj * *)&((struct Obj24854 *)p)->f4,v);}



void func_021FF038(u8*p,u32 mode){switch(mode){case 0:*(void (**)(char*))(p+24)=0;break;case 1:*(void (**)(char*))(p+24)=func_021FF0A0;break;case 2:*(void (**)(char*))(p+24)=func_021FF248;break;case 3:*(void (**)(char*))(p+24)=func_021FF334;break;}((struct Obj06636 *)p)->f1C=0;}



/* Space is explicitly truncated to u16 at the original call. */
void func_021FF074(u8*p){((struct Obj05508 *)p)->f14=410;func_0204B49C(*(struct Actor* *)&((struct Obj05508 *)p)->f4,((struct Obj05508 *)p)->f3C,(u16)(((struct Obj05508 *)p)->f44),0);func_0204B5D4(*(struct Actor* *)&((struct Obj05508 *)p)->f4,((struct Obj05508 *)p)->f14,0);}




void func_021FF0A0(char *p)
{
    int direction;
    s16 x;
    float value;
    ((struct Obj00153 *)p)->f28=(((struct Obj00153 *)p)->f28+1)%2;
    if(((struct Obj00153 *)p)->f28!=0)return;
    switch(((struct Obj00153 *)p)->f1C){
    case 0:
        func_0204B3DC(((struct Obj00153 *)p)->f4,1);
        ((struct Obj00153 *)p)->f24=0;
        ((struct Obj00153 *)p)->f14=((struct Obj00153 *)p)->f38;
        ((struct Obj00153 *)p)->f1C=1;
        break;
    case 1:
        if(((struct Obj00153 *)p)->f24==3){
            ((struct Obj00153 *)p)->f1C=2;
            if(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)>0)
                value=0.5f+(float)(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)<<12);
            else
                value=(float)(func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0)<<12)-0.5f;
            ((struct Obj00153 *)p)->f10=(int)value;
            ((struct Obj00153 *)p)->f24=0;
        }else (((struct Obj00153 *)p)->f24)++;
        break;
    case 2:
        direction=-1;
        if(((struct Obj00153 *)p)->f48!=0)direction=1;
        direction=(signed char)direction;
        if(((struct Obj00153 *)p)->f24==4){
            ((struct Obj00153 *)p)->f1C=3;
            ((struct Obj00153 *)p)->f24=0;
        }else{
            ((struct Obj00153 *)p)->f10+=-direction*func_0203F684(((struct Obj00153 *)p)->f20*65535/360);
            ((struct Obj00153 *)p)->f20+=32;
            ((struct Obj00153 *)p)->f20%=360;
            func_0204B49C(((struct Obj00153 *)p)->f4,((struct Obj00153 *)p)->f10>>12,(u16)(((struct Obj00153 *)p)->f44),0);
            (((struct Obj00153 *)p)->f24)++;
        }
        break;
    case 3:
        x=func_0204B4EC(((struct Obj00153 *)p)->f4,(u16)(((struct Obj00153 *)p)->f44),0);
        if(((struct Obj00153 *)p)->f24==0){
            ((struct Obj00153 *)p)->f2C=((struct Obj00153 *)p)->f3C-x;
            ((struct Obj00153 *)p)->f2C/=((struct Obj00153 *)p)->f3A;
            (((struct Obj00153 *)p)->f24)++;
        }else if(((struct Obj00153 *)p)->f24==((struct Obj00153 *)p)->f3A+1){
            x=((struct Obj00153 *)p)->f3C;
            ((struct Obj00153 *)p)->f1C=4;
        }else{
            x+=(s16)((struct Obj00153 *)p)->f2C;
            (((struct Obj00153 *)p)->f24)++;
        }
        func_0204B49C(((struct Obj00153 *)p)->f4,x,(u16)(((struct Obj00153 *)p)->f44),0);
        break;
    case 4:func_021FF038((u8 *)p,2);break;
    }
    if(((struct Obj00153 *)p)->f1C==3){
        if(((struct Obj00153 *)p)->f14>410){
            ((struct Obj00153 *)p)->f14-=410;
            func_0204B5D4(((struct Obj00153 *)p)->f4,((struct Obj00153 *)p)->f14,0);
        }
    }
}




/*
 * Lever: int direction with explicit signed-char cast at use retains the original lsls/asrs byte truncation; a signed-char local folds it away and compiles 232/236 bytes.
 * Width: original caller truncates space and sine arguments to u16; full callee signatures otherwise copied.
 */
void func_021FF248(char *p)
{
    int direction;
    int position;
    float value;
    ((struct Obj00595 *)p)->f28=(((struct Obj00595 *)p)->f28+1)%2;
    if(((struct Obj00595 *)p)->f28!=0)return;
    switch(((struct Obj00595 *)p)->f1C){
    case 0:
        func_0204B3DC(((struct Obj00595 *)p)->f4,1);
        func_0204B49C(((struct Obj00595 *)p)->f4,((struct Obj00595 *)p)->f3C,(u16)(((struct Obj00595 *)p)->f44),0);
        if(((struct Obj00595 *)p)->f3C>0)value=0.5f+(float)(((struct Obj00595 *)p)->f3C<<12);
        else value=(float)(((struct Obj00595 *)p)->f3C<<12)-0.5f;
        ((struct Obj00595 *)p)->f10=(int)value;
        ((struct Obj00595 *)p)->f20=((struct Obj00595 *)p)->f40;
        ((struct Obj00595 *)p)->f1C=1;
        break;
    case 1:
        direction=-1;
        if(((struct Obj00595 *)p)->f48!=0)direction=1;
        position=((struct Obj00595 *)p)->f10+-(signed char)direction*(func_0203F684((u16)(((struct Obj00595 *)p)->f20*65535/360))*3);
        ((struct Obj00595 *)p)->f20+=((struct Obj00595 *)p)->f42;
        ((struct Obj00595 *)p)->f20%=360;
        func_0204B49C(((struct Obj00595 *)p)->f4,position>>12,(u16)(((struct Obj00595 *)p)->f44),0);
        break;
    }
    if(((struct Obj00595 *)p)->f14>410){
        ((struct Obj00595 *)p)->f14-=410;
        func_0204B5D4(((struct Obj00595 *)p)->f4,((struct Obj00595 *)p)->f14,0);
    }
}




/*
 * Verified blocker C: one --arm without region, fixed compiler/flags/lang, EXACT 16 (scratch b5e4.c and b5e4-verify.log).
 * typedef unsigned long u32;
 * typedef struct { char pad[0x14]; u32 a; u32 b; } Actor;
 * u32 func_0204B5E4(const Actor *p,u32 which)
 * { if(which==0)return p->a; else return p->b; }
 * Width: space argument truncated by original caller to u16 despite callee u32.
 */
void func_021FF334(char *p)
{
    s16 x;
    u32_021FF334 y;
    *(int *)(p+0x28)=(*(int *)(p+0x28)+1)%2;
    if(*(int *)(p+0x28)!=0)return;
    switch(*(int *)(p+0x1C)){
    case 0:
        func_0204B3DC(*(void **)(p+4),1);
        *(int *)(p+0x24)=0;
        *(int *)(p+0x1C)=1;
        break;
    case 1:
        x=func_0204B4EC(*(void **)(p+4),(u16)(*(u32_021FF334 *)(p+0x44)),0);
        y=func_0204B5E4(*(void **)(p+4),0);
        if(*(int *)(p+0x24)==0){
            *(int *)(p+0x2C)=*(s16 *)(p+0x34)-x;
            *(int *)(p+0x2C)/=*(s16 *)(p+0x3A);
            (*(int *)(p+0x24))++;
            *(int *)(p+0x30)=*(s16 *)(p+0x38)-y;
            *(int *)(p+0x30)/=*(s16 *)(p+0x3A);
        }else if(*(int *)(p+0x24)==*(s16 *)(p+0x3A)+1){
            x=*(s16 *)(p+0x34);
            y=*(s16 *)(p+0x38);
            *(int *)(p+0x1C)=2;
        }else{
            x+=(s16)*(int *)(p+0x2C);
            y+=*(int *)(p+0x30);
            (*(int *)(p+0x24))++;
        }
        func_0204B49C(*(void **)(p+4),x,(u16)(*(u32_021FF334 *)(p+0x44)),0);
        func_0204B5D4(*(void **)(p+4),y,0);
        break;
    case 2:func_021FF038((u8 *)p,0);break;
    }
}




/*
 * Layout: original fills 0x2c bytes of local config and allocates 0x5e4-byte context. Callback table occupies its final seven words.
 */
char *func_021FF408(void *owner,void *arg,u32_021FF408 heap)
{
    char *p;
    Config cfg;
    func_02034AC4((int)ov125_id);
    p=func_02030734(heap,0x5E4,0,d_02200D8C,0x97);
    func_02082BCC(p,0,0x5E4);
    ((struct Obj06637 *)p)->f5E0=owner;
    func_02082BCC(&cfg,0,0x2C);
    cfg.owner=owner;
    cfg.value=func_0200853C((const struct Sub0200852CObj *)func_02012944(owner));
    cfg.arg=arg;
    cfg.context=p;
    cfg.a=func_021FFACC;cfg.b=func_021FFAD8;cfg.c=func_021FFAE4;
    cfg.d=func_021FFAF0;cfg.e=func_021FFAFC;cfg.f=func_021FFB08;
    func_021D6660(p,(char *)(&cfg));
    ((struct Obj06637 *)p)->f5A4=1;
    func_02012EBC(owner);
    ((struct Obj06637 *)p)->f5A8=func_0200D59C(heap);
    func_0200D5D0(((struct Obj06637 *)p)->f5A8,owner);
    ((struct Obj06637 *)p)->f5AC=func_021FFB14(p,(int)((void *)func_021FF8E0),heap);
    func_02156DE0((int)((void *)func_021FFB80),(int)p);
    return p;
}




void func_021FF4E4(char *p)
{
    func_02156DE0(0, 0);
    func_021FFB50(((struct Obj08336 *)p)->f5AC);
    func_0200D5C8(((struct Obj08336 *)p)->f5A8);
    if (((struct Obj08336 *)p)->f5A4) {
        func_021D6770(p);
        ((struct Obj08336 *)p)->f5A4 = 0;
    }
    func_020307B0(p);
    func_02034A5C((int)ov125_id);
}




void func_021FF52C(char*p){if(((struct Obj14477 *)p)->f5A4){func_021FFB58((S *)(*(S_b* *)&((struct Obj14477 *)p)->f5AC));func_021D6A34(p);}}




/*
 * Extent: 252 bytes; the listing extent of 276 includes the separately filed func_021FF648 at +0xFC.
 * recoup 2026-10-05: the 8-byte payload copy as one struct assignment (W = two ints) gives the original r2/r1 load colours; two int stores gave r1/r1 (2 bytes off). Struct copy is a plausible human form. EXACT* only because of the 276 vs 252 listing extent.
 */
void func_021FF54C(char *p,int kind,const int *values)
{
    if(kind>=9)func_02034714(d_02200D98,0,d_02200D98);
    if(values){
        *(W *)(p+0x5B0)=*(const W *)values;
    }
    func_02082BCC(p+0x5B8,0,0x24);
    switch(kind){
    case 0:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF900);break;
    case 1:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF938);break;
    case 2:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF968);break;
    case 3:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF99C);break;
    case 4:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF9D0);break;
    case 5:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA14);break;
    case 6:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA40);break;
    case 7:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA6C);break;
    case 8:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA98);break;
    default:func_02034714(d_02200D98,0,d_02200D98);break;
    }
}




int func_021FF648(char *p)
{
    return func_021FFB70(*(int * *)&((struct Obj24855 *)p)->f5AC,(int)func_021FF8E0);
}





int func_021FF660(char *p, int a1, int a2, int *out)
{
    int v = ((struct Obj24856 *)p)->f5BC;

    if (v != 0)
        *out = func_021D7374((char *)p, (void **)a1, a2);
    return v;
}




u32 func_021FF67C(u8*p,unsigned long long*out){u32 present;present=((struct Obj24858 *)p)->f5C0;if(present)*out=func_021D73E0((char *)p);return present;}





/*
 * Earlier blocker (closed): 5 bytes, a pure r4/r5 swap.  The original keeps the out pointer
 * in r4 and the field value in r5; every spelling tried (named pointer copy,
 * reversed declarations, int index, inline re-read) makes this compiler put
 * the field value in r4 and the pointer in r5, because the loaded value is
 *   the first live temporary while the pointer (arg r2) is spilled to the
 *   highest callee-saved register.  `cmp`-style naming does not move it.
 *   Re-verified (DIFF fixer): declaration order v-then-o, assignment o-then-v,
 *   and dropping the `o` alias to store through `out` directly all still swap
 *   r4/r5 the same way.
 *
 * 2026-10-05: tried a local k=0x5c4 reused as the call argument, pointer-typed value, u32 types, struct field access, early return for v==0, static inline getter, out alias inside the if. All still give out in r5 and value in r4 (original: out r4, value r5). Residue unchanged: 5 bytes, pure r4/r5 swap.
 *
 * 2026-10-05 (D9-14): closed. The swap was a wrong callee arity: func_021D74D8
 *   (matched in ov125) takes two arguments; the 0x5c4 in r2 at the call is only the
 *   leftover offset register. Two-argument call, no alias local: EXACT.
 */
int func_021FF698(char *p, int a1, int *out)
{
    int v = *(int *)(p + 0x5c4);

    if (v != 0)
        *out = func_021D74D8(p, (char **)a1);
    return v;
}




int func_021FF6B4(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24860 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}




int func_021FF6DC(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24861 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}




int func_021FF704(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24862 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}




/*
 * note: pass 4 2026-10-06 P4L01: EXACT (also with --lang c). Case 1 works on a block local copy of the
 *   result (`int r=result; ... r=1; ... result=r;`). The final `result=r` is a register copy that the
 *   allocator coalesces away, so the block after case 1's if is empty only after allocation; it is then
 *   merged into case 1's copy block, which gives that block a new (front of list) edge to the release
 *   join. The cross-jump keeps the first predecessor in the join's list, so case 1's `movs r5,#1` keeps
 *   and case 0's after-store copy and 22002's copy become hops onto it (the image's forward hop at +002E).
 *   Earlier forms (2 B off) kept case 0's copy, the earliest original edge.
 */
int func_021FF72C(char *p,int *out)
{
    const int *event;
    int result;
    if(func_021D72EC(p,(int **)&event)){
        result=1;
        if(event[1]==0){
            if(event[3]){
                if(out)*out=event[3]+283;
                result=1;
            }
        }else if(event[1]==1){
            int r=result;
            if(event[3]==7){
                if(out)*out=event[3]+298;
                r=1;
            }
            result=r;
        }else if(event[1]==2){
            switch(event[2]){
            case 21000:
                if(event[3]){if(out)*out=event[3]+230;result=2;}
                break;
            case 21001:
                if(event[3]){if(out)*out=event[3]+237;result=2;}
                break;
            case 22000:
                if(event[3]){
                    switch(event[3]){
                    case 150:func_02006210();func_0200FB4C(65);result=3;break;
                    case 151:func_02006210();func_0200FB4C(66);result=3;break;
                    case 152:func_02006210();func_0200FB4C(68);result=3;break;
                    case 153:func_02006210();func_0200FB4C(67);result=3;break;
                    default:if(out)*out=event[3]+261;result=2;break;
                    }
                }
                break;
            case 22001:
                if(event[3]){if(out)*out=event[3]+269;result=2;}
                break;
            case 22002:
                if(event[3]){if(out)*out=event[3]+274;result=1;}
                break;
            case 22003:result=0;break;
            }
        }
        func_021D72F8(p);
        if(result==3)*(int *)(p+0x5DC)=1;
        return result;
    }
    return 0;
}




int func_021FF88C(char *p)
{
    if (!p) return 0;
    switch (func_02157170(1, 0)) {
    case 1: func_02006210(); return 1;
    case 2: func_02006210(); ((struct Obj24863 *)p)->f5DC = 1; return 2;
    case 3: func_02006210(); func_0200F7DC(); break;
    }
    return 0;
}





int func_021FF8D4(char *p)
{
    return ((struct Obj24864 *)p)->f5DC;
}




void func_021FF8E0(void)
{
}





/*
 * 0x021FF8E0 is an unlabelled two-byte `bx lr` leaf reached through the pool
 * word 0x021FF8E1 (thumb bit set); now matched as src/matched/func_021FF8E0.c.
 */
void func_021FF8E4(void *p, int a1, int a2)
{
    if (func_021D730C((char *)a2) != 0)
        func_021FFB68(p, (int)((void *)func_021FF8E0));
}




void func_021FF900(char*p,int unused,char*q){if(!func_021D67C8(q,*(const Block128* *)&((struct Obj14481 *)q)->f5A8,*(const Block432* *)&((struct Obj14481 *)q)->f5B0))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FF938(char *p,int unused,char *q) {if(!func_021D6814(q,((struct Obj24865 *)q)->f5B0))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FF968(char *p,int unused,char *q) {if(!func_021D683C(q,((struct Obj24866 *)q)->f5A8))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FF99C(char *p,int unused,char *q) {if(!func_021D69DC(q,((struct Obj14482 *)q)->f5B0,((struct Obj14482 *)q)->f5B4))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FF9D0(char *p, int unused, char *q)
{
    if (!func_021D68EC(q, ((struct Obj08337 *)q)->f5B0, ((struct Obj08337 *)q)->f5B4, ((struct Obj08337 *)q)->f5B2, ((struct Obj08337 *)q)->f5B3))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}




void func_021FFA14(char *p,int unused,char *q) {if(!func_021D6968(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FFA40(char *p,int unused,char *q) {if(!func_021D69B4(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FFA6C(char *p,int unused,char *q) {if(!func_021D698C(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}




void func_021FFA98(char *p, int unused, char *q)
{
    if (!func_021D6A08(q, ((struct Obj14483 *)q)->f5B0, ((struct Obj14483 *)q)->f5B4))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}




void func_021FFACC(char *p) { ((struct Obj24867 *)p)->f5B8 = 1; }




void func_021FFAD8(char *p) { ((struct Obj24868 *)p)->f5BC = 1; }




void func_021FFAE4(char *p) { ((struct Obj24869 *)p)->f5C0 = 1; }




void func_021FFAF0(char *p) { ((struct Obj24870 *)p)->f5C8 = 1; }




void func_021FFAFC(char *p) { ((struct Obj24871 *)p)->f5C4 = 1; }




void func_021FFB08(char *p) { ((struct Obj24872 *)p)->f5D8 = 1; }




char *func_021FFB14(void *p,int f,unsigned heap) {char *q=func_02030734(heap,16,0,d_02200D8C,0x44f);func_02082BCC(q,0,16);((struct Obj24873 *)q)->f8=p;func_021FFB68(q,f);return q;}




void func_021FFB50(void *p) {func_020307B0(p);}





void func_021FFB58(S *p)
{
    if (p->fn_021FF968 != 0)
        p->fn_021FF968(p, (char *)p + 4, p->arg_08);
}





void func_021FFB68(char *p, int v)
{
    ((struct Obj14485 *)p)->f0 = v;
    ((struct Obj14485 *)p)->f4 = 0;
}




int func_021FFB70(int *p,int value)
{
    if(*p==value) return 1;
    return 0;
}




int func_021FFB80(char *p, int b, int kind, int d)
{
    if (func_02012E40(((struct Obj10800 *)p)->f5E0)) return 1;
    func_021D7124(p, b, kind, d);
    if (kind == 3 || kind == 6) {
        if (((struct Obj10800 *)p)->f5A4) {
            func_021D6770(p);
            ((struct Obj10800 *)p)->f5A4 = 0;
        }
        func_02156DE0(0, 0);
    }
    return 0;
}




char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap)
{
    char *p;
    int i = 0;
    p = func_02030734(heap, 0x90, 0, d_02200D9C, 0x11a);
    func_02082BCC(p, 0, 0x90);
    ((struct Obj01967 *)p)->f24 = heap;
    ((struct Obj01967 *)p)->f7C = owner;
    ((struct Obj01967 *)p)->f28 = table;
    ((struct Obj01967 *)p)->f30 = c;
    ((struct Obj01967 *)p)->f34 = a;
    ((struct Obj01967 *)p)->f38 = b;
    ((struct Obj01967 *)p)->f3C = (void *)func_0201C440((void *)(((struct Obj01967 *)p)->f24));
    *(int *)&((struct Obj01967 *)p)->f80 = func_02200228((heap & 0x7fff) | 0x8000, (unsigned *)(p + 0x84));
    ((struct Obj01967 *)p)->f74 = d;
    ((struct Obj01967 *)p)->f78 = e;
    for (; i < 9; i++) *(unsigned char *)(p + i + 0x14) = func_0220014C(((struct Obj01967 *)p)->f7C, i, (const u16 *)(((struct Obj01967 *)p)->f80));
    return p;
}




void func_021FFC6C(char *p) {if(((struct Obj06638 *)p)->f88){func_020307B0(((struct Obj06638 *)p)->f88);((struct Obj06638 *)p)->f88=0;}func_020307B0(((struct Obj06638 *)p)->f80);func_0201C4C0(*(struct PrintSys * *)&((struct Obj06638 *)p)->f3C);func_020307B0(p);}




int func_021FFC9C(char *p)
{
    if (((struct Obj00221 *)p)->f6C) {
        switch (((struct Obj00221 *)p)->f0) {
        case 0: (((struct Obj00221 *)p)->f0)++; break;
        case 1: ((struct Obj00221 *)p)->f0=2; break;
        case 2: {
            int x,y,held;
            Pair pair;
            ((struct Obj00221 *)p)->fC=func_022000F0(p);
            held=func_02035D20((u32 *)(&x),(u32 *)(&y));
            if (func_021FB4B4((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=1;
            } else if (((struct Obj00221 *)p)->fC!=9) {
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=3;
            }
            break;
        }
        case 3: {
            int x,y,held;
            Pair pair;
            func_021FCD0C(*(char * *)&((struct Obj00221 *)p)->f68);
            ((struct Obj00221 *)p)->f10=func_021FCDA8(*(char * *)&((struct Obj00221 *)p)->f68);
            held=func_02035D20((u32 *)(&x),(u32 *)(&y));
            if (func_021FB4B4((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=2;
            } else if (((struct Obj00221 *)p)->f10!=-1) {
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=2;
            }
            break;
        }
        case 4:
            if (func_021FD938(*(char * *)&((struct Obj00221 *)p)->f78)) {
                func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,1);
                (((struct Obj00221 *)p)->f0)++;
            }
            break;
        case 5:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) (((struct Obj00221 *)p)->f0)++;
            break;
        case 6:
            if (((struct Obj00221 *)p)->f4==3) {
                func_021FFFCC((u8 *)p);
                if (((struct Obj00221 *)p)->f88) func_02034714(d_02200DAC,0,d_02200DAC);
                *(u16 * *)&((struct Obj00221 *)p)->f88=func_02200188(((struct Obj00221 *)p)->f7C,*(u32 *)&((struct Obj00221 *)p)->fC,*(u16 * *)&((struct Obj00221 *)p)->f80,(u32 *)(p+0x8c),((struct Obj00221 *)p)->f24);
                func_021FFFF8(p);
            } else {
                func_022000D0((u8 *)p);
                if (((struct Obj00221 *)p)->f88) {
                    func_020307B0(((struct Obj00221 *)p)->f88);
                    ((struct Obj00221 *)p)->f88=0;
                }
                func_021FFF28((Work *)((struct Work *)p));
            }
            func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,0);
            (((struct Obj00221 *)p)->f0)++;
            break;
        case 7:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) ((struct Obj00221 *)p)->f0=*(u32 *)&((struct Obj00221 *)p)->f4;
            break;
        case 8: (((struct Obj00221 *)p)->f0)++; break;
        case 9: (((struct Obj00221 *)p)->f0)++; break;
        case 10: ((struct Obj00221 *)p)->f20=1; break;
        }
    }
    return func_021FFE34(p);
}




unsigned func_021FFE34(char *p) {unsigned r=1;int i;for(i=0;i<9;i++){void *v=*(void **)((unsigned)p+i*4+64);if(v)r &= func_021FC830(v);}return r & func_0201C4E4(*(struct PrintSys * *)&((struct Obj24875 *)p)->f3C);}





void func_021FFE5C(char *p)
{
    func_021FFEA8(p);
    func_021FFF28((Work *)((struct Work *)p));
    ((struct Obj02237 *)p)->f6C = 1;
}




void func_021FFE70(char *p) {((struct Obj14486 *)p)->f6C=0;if(((struct Obj14486 *)p)->f70==1)func_022000D0((u8 *)p);else func_021FFFCC((u8 *)p);func_021FFF1C(p);}




/*
 * Unlabelled ov186 leaf: if the +0x20 field is zero return 0; otherwise, when
 * the +0x08 field is 2, publish the +0x10 halfword through the out pointer and
 * return the +0x08 field.  Matched to supply the `matched` witness for the
 * pending ov185 caller func_021F86A4.
 */
int func_021FFE90(int *p, unsigned short *out)
{
    if (p[8] != 0) {
        if (p[2] == 2)
            *out = (unsigned short)p[4];
        return p[2];
    }
    return 0;
}




void func_021FFEA8(char *p)
{
    Request_021FF968 req;
    int info[3];
    int a = func_021FC20C(*(char * *)&((struct Obj04590 *)p)->f28);
    int b = func_021FC214(*(char * *)&((struct Obj04590 *)p)->f28);
    func_02082BCC(&req, 0, 8);
    req.x = 0x50; req.y = 0xa8; req.id = 0; req.flag = 1;
    if (!func_021FC124((char *)(((struct Obj04590 *)p)->f28), 6, (Triple *)info))
        func_02034714(d_02200DAC, 0, d_02200DAC);
    ((struct Obj04590 *)p)->f2C = func_021FB378(&req, 4, 0x60, 1, ((struct Obj04590 *)p)->f34, ((struct Obj04590 *)p)->f38, a, b, info, ((struct Obj04590 *)p)->f24);
}



void func_021FFF1C(char *p) {func_021FB494(((struct Obj24877 *)p)->f2C);}



void func_021FFF28(Work *p)
{
    int a, b, i;
    unsigned color;
    unsigned char x, y;
    p->state = 0;
    func_021FB964((void *)((int)p->owner), 20, p->heap);
    a = func_021FC20C(p->owner);
    b = func_021FC214(p->owner);
    for (i = 0; i < 9; i++) {
        x = (i % 5) * 6 + 2;
        y = 6;
        if (i < 5) y = 0;
        p->slots[i] = func_021FC6A4(4, (unsigned char)x, (unsigned char)(y + 4), (unsigned)4, 2, 14, p->resource, p->heap);
        color = 0x3da0;
        if (!p->flags[i]) color = 0x2da0;
        func_021FC868((u8 *)p->slots[i], (int)0, (int)0, (int)1);
        func_021FC754(p->slots[i], (void *)b, (void *)(i + 0x3a), (void *)a, color);
    }
}



void func_021FFFCC(u8 *p) { int i; for(i=0;i<9;i++) { u8 *q=p+(u32)i*4; func_021FC734(((struct Obj14487 *)q)->f40); *(u32 *)&((struct Obj14487 *)q)->f40=0; } func_020409B4(4); func_021FBDA4(((struct Obj24878 *)p)->f28,20); }



/*
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing Ilias-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only func_02045C44, omitting func_02045CAC.
 *   Verified C follows, using that unit's declarations:
 *   void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *     u32 size; struct MsgEntry *e;
 *     if (index >= bank->file->count) { func_0204581C(dest); return; }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *       u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *       func_0204960C(bank->stream, pos + (index * 8 + 4));
 *       func_020495F4(bank->stream, 8, &bank->cache); e = &bank->cache;
 *     } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *     if (bank->resident == 0) {
 *       void *buf; size = e->len * 2;
 *       buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                         size, 0, g_020A7E8C, 0xd6);
 *       if (buf != 0) {
 *         func_0204960C(bank->stream, e->off + (bank->origin
 *                       + bank->file->langOff[bank->langIndex]));
 *         func_020495F4(bank->stream, size, buf);
 *         func_02045A00(dest, buf, e->len); func_020307B0(buf);
 *       }
 *     } else { func_02045A00(dest, (u8 *)bank->base + e->off, e->len); }
 *     func_02045E04(dest, index);
 *   }
 */
void func_021FFFF8(char *p)
{
    Config_c cfg;
    void *str;
    u32 i;
    *(u32 *)(p+0x70)=1;
    func_021FB964((void *)(*(int *)(p+0x28)),21,*(u16 *)(p+0x24));
    if (*(void **)(p+0x64)) func_02034714(d_02200DAC,0,d_02200DAC);
    if (*(void **)(p+0x68)) func_02034714(d_02200DAC,0,d_02200DAC);
    *(Slot **)(p+0x64)=func_0201F81C(*(u32 *)(p+0x8c),*(u16 *)(p+0x24));
    str=func_020457B0(11,*(u16 *)(p+0x24));
    for(i=0;i<*(u32 *)(p+0x8c);i++) {
        func_02045CAC(d_020A7370,(*(u16 **)(p+0x88))[i],str);
        func_0201F898((struct Slot *)(*(Slot **)(p+0x64)+i),(u32)str,(*(u16 **)(p+0x88))[i],*(u16 *)(p+0x24));
    }
    func_02045808(str);
    cfg=d_02200CA8;
    cfg.v[0]=*(u32 *)(p+0x64);
    cfg.v[1]=*(u32 *)(p+0x8c);
    cfg.v[5]=*(u32 *)(p+0x28);
    cfg.v[6]=*(u32 *)(p+0x34);
    cfg.v[7]=*(u32 *)(p+0x74);
    cfg.v[8]=*(u32 *)(p+0x78);
    *(void **)(p+0x68)=func_021FC8C8(&cfg,*(u16 *)(p+0x24));
}



void func_022000D0(u8 *p) { func_021FCC80(*(char * *)&((struct Obj06639 *)p)->f68); *(u32 *)&((struct Obj06639 *)p)->f68=0; func_0201F868(((struct Obj06639 *)p)->f64); *(u32 *)&((struct Obj06639 *)p)->f64=0; func_021FBDA4(((struct Obj06639 *)p)->f28,21); }



int func_022000F0(char *p)
{
    int x, y, args[2];
    int index = func_02035C08(d_02200CD0);
    if (index != -1) {
        if (*(unsigned char *)(p + index + 0x14)) {
            func_02035D20((unsigned int *)(&x), (unsigned int *)(&y));
            args[0] = x;
            args[1] = y;
            func_021FD860((char *)(((struct Obj24879 *)p)->f78), 1, (const Pair *)args);
            func_020061E4(0x703);
            return index;
        }
        func_020061E4(0x704);
    }
    return 9;
}



/*
 * lever: unsigned table indices preserve load scheduling; raw address casts differ by 12 bytes.
 */
int func_0220014C(void *p,u32 n,const u16 *ids) { u32 i; u32 end; int found; end=d_02200C94[n+1];found=0;for(i=d_02200C94[n];i<end;i++) { if(func_0200D064(p,*(const u16 *)((u32)ids+i*2)))found=1; }return found; }



/*
 * lever: loop-2 store written as two statements (dst[filled] = ...; filled++;) with braced
 *   loop and if bodies; the one-line dst[filled++] form left a 3-register rotation (18 B).
 */
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap)
{
    u32 end, start;
    u16 *dst;
    int filled;
    int count, bytes;
    end = d_02200C94[index + 1];
    count = 0;
    start = d_02200C94[index];
    for (filled = start; filled < end; filled++) {
        if (func_0200D064(p, table[filled])) {
            count++;
        }
    }
    bytes = count * 2;
    dst = func_02030734(heap, bytes, 0, d_02200D9C, 0x3c3);
    filled = 0;
    func_02082BCC(dst, 0, bytes);
    for (; start < end; start++) {
        if (func_0200D064(p, table[start])) {
            dst[filled] = table[start];
            filled++;
        }
    }
    if (out) *out = filled;
    return dst;
}

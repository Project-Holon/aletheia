/*
 * file:     br_net_p02.c
 * unit:     yes
 * function: func_021FF0A0, func_021FF248, func_021FF334, func_021FF408, func_021FF4E4, func_021FF52C, func_021FF54C
 * address:  0x021FF0A0
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
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_0203F684 0x0203F684 arm
 *   func_021FF038 0x021FF038 thumb ov186
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0204B5E4 0x0204B5E4 arm
 *   ov125_id 0x0000007D data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021D6660 0x021D6660 thumb ov125
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D59C 0x0200D59C thumb
 *   func_0200D5D0 0x0200D5D0 thumb
 *   func_021FFB14 0x021FFB14 thumb ov186
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021FFACC 0x021FFACC thumb ov186
 *   func_021FFAD8 0x021FFAD8 thumb ov186
 *   func_021FFAE4 0x021FFAE4 thumb ov186
 *   func_021FFAF0 0x021FFAF0 thumb ov186
 *   func_021FFAFC 0x021FFAFC thumb ov186
 *   func_021FFB08 0x021FFB08 thumb ov186
 *   func_021FF8E0 0x021FF8E0 thumb ov186
 *   func_021FFB80 0x021FFB80 thumb ov186
 *   d_02200D8C 0x02200D8C data a1
 *   func_021FFB50 0x021FFB50 thumb ov186
 *   func_0200D5C8 0x0200D5C8 thumb
 *   func_021D6770 0x021D6770 thumb ov125
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021FFB58 0x021FFB58 thumb ov186
 *   func_021D6A34 0x021D6A34 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 *   func_021FF900 0x021FF900 thumb ov186
 *   func_021FF938 0x021FF938 thumb ov186
 *   func_021FF968 0x021FF968 thumb ov186
 *   func_021FF99C 0x021FF99C thumb ov186
 *   func_021FF9D0 0x021FF9D0 thumb ov186
 *   func_021FFA14 0x021FFA14 thumb ov186
 *   func_021FFA40 0x021FFA40 thumb ov186
 *   func_021FFA6C 0x021FFA6C thumb ov186
 *   func_021FFA98 0x021FFA98 thumb ov186
 */
#include "../../matched/include/Obj00153.h"
#include "../../matched/include/Obj00595.h"
#include "../../matched/include/Obj06637.h"
#include "../../matched/include/Obj08336.h"
#include "../../matched/include/Obj14477.h"

struct Actor;
struct Obj;
struct Big;
struct GdsProfile;
struct Sub0200852CObj;
typedef unsigned short u16;

typedef signed short s16;

typedef unsigned long u32_021FF0A0;

typedef unsigned char  u8;

typedef unsigned long u32_021FF248;

typedef signed int     s32;

typedef unsigned long u32_021FF334;

typedef unsigned long u32_021FF408;

typedef struct {u32_021FF408 value;u32_021FF408 unused;void *owner;void *arg;void *context;void (*a)(char *);void (*b)(char *);void (*c)(char *);void (*d)(char *);void (*e)(char *);void (*f)(char *);} Config;

typedef unsigned int   u32_021FF4E4;

typedef unsigned int u32_021FF52C;

typedef struct {int(*fn)(void*,void*,int);char pad_04[4];int arg_08;} S;

typedef struct {int a,b;} W;

typedef unsigned int   u32_021FF54C;

extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern s16 func_0204B4EC(struct Actor *actor, u32_021FF0A0 space, u32_021FF0A0 axis);
extern void func_0204B49C(struct Actor *actor, s16 value, u32_021FF0A0 space, u32_021FF0A0 axis);
extern void func_0204B5D4(struct Actor *actor, u32_021FF0A0 value, u32_021FF0A0 which);
extern s16 func_0203F684(u16);
extern void func_021FF038(u8 *p, u32_021FF0A0 mode);
extern u32_021FF334 func_0204B5E4(const struct Actor *actor, u32_021FF334 which);
extern int func_02034AC4(int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
extern void func_02082BCC(void *,u32_021FF408,u32_021FF408);
extern u8 *func_02012944(void *p);
extern u32_021FF408 func_0200853C(const struct Sub0200852CObj *obj);
extern int func_021D6660(char *p, char *a);
extern void *func_02012EBC(struct Big *p);
extern struct GdsProfile *func_0200D59C(u32_021FF408 heap);
extern void func_0200D5D0(struct GdsProfile *p, void *sys);
extern char *func_021FFB14(void *p, int f, unsigned heap);
extern void func_02156DE0(int a, int b);
extern void func_021FFACC(char *),func_021FFAD8(char *),func_021FFAE4(char *),func_021FFAF0(char *),func_021FFAFC(char *),func_021FFB08(char *);
extern void func_021FF8E0(void);
extern int func_021FFB80(char *,int,int,int);
extern void func_021FFB50(void *);
extern void func_0200D5C8(struct GdsProfile *p);
extern void func_021D6770(char *p);
extern u32_021FF4E4 func_020307B0(void *p);
extern void func_02034A5C(int);
extern void func_021FFB58(S*);
extern int func_021D6A34(char*);
extern void func_02034714(const char *expr, u32_021FF54C line, const char *file);
extern void func_021FFB68(char *,int);
extern void func_021FF900(char *,int,char *);
extern void func_021FF938(char *,int,char *);
extern void func_021FF968(char *,int,char *);
extern void func_021FF99C(char *,int,char *);
extern void func_021FF9D0(char *,int,char *);
extern void func_021FFA14(char *,int,char *);
extern void func_021FFA40(char *,int,char *);
extern void func_021FFA6C(char *,int,char *);
extern void func_021FFA98(char *,int,char *);
void func_021FF0A0(char *p);
void func_021FF248(char *p);
void func_021FF334(char *p);
char *func_021FF408(void *owner,void *arg,u32_021FF408 heap);
void func_021FF4E4(char *p);
void func_021FF52C(char*p);
void func_021FF54C(char *p,int kind,const int *values);
extern const char d_02200D8C[];
extern char ov125_id[];
extern const char d_02200D98[];

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

void func_021FF52C(char*p){if(((struct Obj14477 *)p)->f5A4){func_021FFB58(*(S* *)&((struct Obj14477 *)p)->f5AC);func_021D6A34(p);}}

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

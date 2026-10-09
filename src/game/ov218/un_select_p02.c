/*
 * file:     un_select_p02.c
 * unit:     yes
 * function: func_021B9C74, func_021B9C80, func_021B9C84, func_021B9C88, func_021B9C8C, func_021B9CDC, func_021B9D10, func_021B9D48, func_021B9E28, func_021B9E48, func_021B9F98, func_021B9FD4, func_021B9FD8, func_021BA0B0, func_021BA138, func_021BA1A0, func_021BA1C0, func_021BA208, func_021BA21C, func_021BA290, func_021BA2EC, func_021BA328, func_021BA4B4, func_021BA4D4, func_021BA4FC, func_021BA554, func_021BA61C, func_021BA680, func_021BA6BC, func_021BA6E8, func_021BA720, func_021BA75C, func_021BA780, func_021BA7A4
 * address:  0x021B9C74
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_021B9AE4 0x021B9AE4 thumb ov218
 *   func_021B8AB8 0x021B8AB8 thumb ov067
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_021B796C 0x021B796C thumb ov067
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207D534 0x0207D534 arm
 *   func_021BA848 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   func_021B6100 0x021B6100 thumb ov067
 *   func_021B96CC 0x021B96CC thumb ov218
 *   func_021B9964 0x021B9964 thumb ov218
 *   func_021BA960 0x021BA960 thumb ov218
 *   func_021B9820 0x021B9820 thumb ov218
 *   func_02027F60 0x02027F60 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02005624 0x02005624 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_020362DC 0x020362DC arm
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9890 0x021B9890 thumb ov218
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00 0x021B9C00 thumb ov218
 *   func_021B9898 0x021B9898 thumb ov218
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_021B991C 0x021B991C thumb ov218
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9914 0x021B9914 thumb ov218
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_021BABC8 0x021BABC8 data ov218 a4
 *   d_021BAB68 0x021BAB68 data a4
 *   d_021BAB98 0x021BAB98 data ov218 a4
 *   d_021BABB0 0x021BABB0 data ov218 a4
 *   d_021BAB80 0x021BAB80 data ov218 a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 *   ov067_id 0x43 data
 */
#include "../../matched/include/Obj26040.h"
#include "../../matched/include/Obj26041.h"
#include "../../matched/include/Obj26042.h"
#include "../../matched/include/Obj26043.h"
#include "../../matched/include/Obj03959.h"
#include "../../matched/include/Obj02556.h"
#include "../../matched/include/G_Template.h"
#include "../../matched/include/Obj14772.h"
#include "../../matched/include/Obj00243.h"
#include "../../matched/include/Obj02931.h"
#include "../../matched/include/Obj04644.h"
#include "../../matched/include/Obj26046.h"
#include "../../matched/include/Obj26047.h"
#include "../../matched/include/Obj26048.h"
#include "../../matched/include/Obj01983.h"
#include "../../matched/include/G_Config.h"
#include "../../matched/include/Obj08448.h"
#include "../../matched/include/Obj14773.h"

struct S;
struct Tmpl;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Obj0203159C;
struct R;
struct TaskMenu;
struct WordSet;
struct Obj;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct Template Template;

typedef signed int     s32;

typedef struct Config Config;

typedef struct Pair_021BA290 {short x,y;} Pair_021BA290;

struct Row0 {char pad[0x294];void *item;};

struct Row1 {char pad[0x2b0];void *item;};

typedef struct Pair_021BA61C { short x, y; } Pair_021BA61C;

typedef struct Row { char pad[0x244]; void *item; char gap[0x94]; unsigned id; } Row;

typedef struct PtS{s16 x,y;} PtS;

typedef enum { FogMode0 = 0 } FogMode;

typedef enum { FogSlope0 = 0 } FogSlope;

extern void func_0201F7A8(void *,u32);
extern u32 func_021B9398(char *p, int index);
extern unsigned func_021B9394(char *p);
extern void func_021B9AE4(u8 *p, u32 a, u32 b, void *c, u32 d);
extern int func_021B8AB8(u8 *);
extern int func_021B93A4(char *);
extern int func_021B93B0(char *);
extern struct S *func_021B7754(struct Tmpl *tmpl, u32 heap);
extern void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *);
extern void func_021B796C(struct S *);
extern int func_02034AC4(int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern char *func_021BA848(unsigned swap, unsigned heap);
extern void *func_021B6100(u32,void *,u8,u16,void *);
extern void func_021B96CC(u8 *p, u16 heap);
extern void *func_021B9964(u16);
extern u32 func_021BA960(char *p);
extern void *func_021B9820(int,int);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void func_0203D34C(u32,u32);
extern u32 func_020362DC(void);
extern int func_021B7AB0(struct S *p);
extern void func_021B9280(u8 *p, int a, u32 b);
extern void func_020061E4(u32);
extern void func_021B61F8(unsigned char *,int);
extern void func_021B9890(void *);
extern int func_021B6448(unsigned char *);
extern unsigned func_021B61FC(const unsigned char *p);
extern void func_021B6200(u8 *a);
extern int func_021B9924(void);
extern void func_021B9B78(char *p, u32 id);
extern int func_021B9C00(char *p);
extern struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
extern int func_0204E804(void);
extern int func_02024004(int a);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_021B991C(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
extern void func_021B9944(void);
extern void func_021B9914(struct TaskMenu *p);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u32 space);
extern void func_0204B404(struct Obj *p, const struct PtS *delta, u32 which);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(int, FogMode, FogSlope, int);
extern void func_0207DD24(unsigned short, int, int, int, int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
void func_021B9C74(u8 *p);
void *func_021B9C80(u8 *p);
void *func_021B9C84(u8 *p);
u32 func_021B9C88(char *p);
void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void func_021B9CDC(u8 *p);
void func_021B9D10(u8 *p,int delta);
void func_021B9D48(char *p);
void func_021B9E28(char *p);
char *func_021B9E48(void *owner,char *input);
void func_021B9F98(u8 *p, int mode);
int func_021B9FD4(void);
int func_021B9FD8(unsigned char *task,char *p);
int func_021BA0AC(void);
u32 func_021BA0B0(u8 *a, u8 *b);
int func_021BA138(unsigned char *task, char *ctx);
int func_021BA1A0(void);
int func_021BA1C0(unsigned char *task, char *ctx);
int func_021BA208(void *unused, char *p);
int func_021BA21C(unsigned char *task, char *ctx);
void func_021BA238(void);
void func_021BA290(char *ctx);
void func_021BA2EC(char *p);
void func_021BA328(char *p);
void func_021BA4B4(char *p);
struct Obj *func_021BA4D4(u32 owner,char *p);
void func_021BA4FC(char *ctx);
void func_021BA554(const char *p,int delta);
void func_021BA61C(char *ctx);
void func_021BA680(char *p,int v);
void func_021BA6BC(char *p,int y);
void func_021BA6E8(u32 p, int sel, u32 y);
int func_021BA720(u32 base,u32 i,u32 space,int y);
int func_021BA75C(char *p, int v);
unsigned int func_021BA780(int v);
void func_021BA7A4(void);
extern struct Template d_021BB060;
extern struct Template template_021BB060;
extern int tbl_021BAC80[];
extern char ov067_id[];
extern char d_021BAB20[];
extern struct Config d_021BAB68;
extern const Config d_021BABC8, d_021BAB98, d_021BABB0, d_021BAB80;
extern const unsigned short d_021BAED8[];




void func_021B9C74(u8 *p)
{
    func_0201F7A8(((struct Obj26040 *)p)->f24,1);
}




void *func_021B9C80(u8 *p)
{
    return ((struct Obj26041 *)p)->fC;
}




void *func_021B9C84(u8 *p)
{
    return ((struct Obj26042 *)p)->f10;
}





/*
 * Unlabelled leaf in ov218, printed as a .word run right before the next
 * function at 0x021B9C8C; four-byte word getter.  Blocker target of
 * func_021BA0B0 (pkt_021BA0B0), whose ov218 hint then covers it.
 */
u32 func_021B9C88(char *p)
{
    return ((struct Obj26043 *)p)->f8;
}




void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    func_021BA4FC((char *)p);
    func_021B9398((char *)(*(u8 **)(p + 0x2C)), a);
    t = func_021B9394((char *)(*(u8 **)(p + 0x2C)));
    func_021B9AE4(*(u8 **)(p + 0x28), b, t, func_021B9C80(*(u8 **)(p + 0x28)), a);
    if (func_021BA75C((char *)p, a)) {
        func_021BA6E8((u32)p, d, (u32)(c + 0x14));
    }
}




void func_021B9CDC(u8 *p)
{
    int selected;
    s16 y;
    y=func_021B8AB8(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=func_021B93A4(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)func_021B93B0(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}




void func_021B9D10(u8 *p,int delta)
{
    int selected;
    s16 y;
    func_021BA554((const char *)p,(int)(0u-(u32)delta));
    y=func_021B8AB8(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=func_021B93A4(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)func_021B93B0(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}




void func_021B9D48(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=**(u8 * *)&((struct Obj02556 *)p)->f20;
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    ((struct Obj02556 *)p)->f2C=func_021B7754((struct Tmpl *)(&template_021BB060),((struct Obj02556 *)p)->f0);
    archive=func_020490F4(193,((struct Obj02556 *)p)->f0);
    func_021B7A10(((struct Obj02556 *)p)->f2C,(u32)archive,3,0,0);
    func_021B7A10(((struct Obj02556 *)p)->f2C,(u32)archive,4,0,1);
    func_021B7A4C(((struct Obj02556 *)p)->f2C,archive,1,2,3);
    func_02049238(archive);
    bank=func_02045B38(0,2,229,((struct Obj02556 *)p)->f0);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(*(u32 *)(p+0x34+offset)==1)disabled=0;
        func_021B79E4(((struct Obj02556 *)p)->f2C,disabled,i);
        if(disabled==0)
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,238);
    }
    func_02045C04(bank);
}




void func_021B9E28(char *p){int i;for(i=0;i<130;i++)func_02045808(*(struct U16Vec **)(((struct Obj14772 *)p)->f28+i*4+0x2c));func_021B796C(*(struct S * *)&((struct Obj14772 *)p)->f2C);}




char *func_021B9E48(void *owner,char *input)
{
    char *p;
    int i,value;
    u32 a,b;
    func_02034AC4((int)ov067_id);
    func_0203064C(1,122,0x30000);
    p=func_0203159C(owner,0x330,122);
    func_02082BCC(p,0,0x330);
    ((struct Obj00243 *)p)->f0=122;
    *(char * *)&((struct Obj00243 *)p)->f20=input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))*(u32 *)(p+0x34+i*4)=1;
        else *(u32 *)(p+0x34+i*4)=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=func_021BA780(value);
        else value=65535;
        *(int *)(p+0x2dc+i*4)=value;
    }
    func_0207D534((u16 *)0x0400006c,-16);
    func_0207D534((u16 *)0x0400106c,-16);
    ((struct Obj00243 *)p)->f4=func_021BA848(0,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f24=func_021B6100(((struct Obj00243 *)p)->f0,d_021BAB20,3,0,p);
    func_021B96CC((u8 *)p,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f28=func_021B9964(((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f8=func_021B9820(func_021BA960(((struct Obj00243 *)p)->f4),((struct Obj00243 *)p)->f0);
    a=(u32)func_021B9C80(((struct Obj00243 *)p)->f28);
    b=(u32)func_021B9C84(((struct Obj00243 *)p)->f28);
    ((struct Obj00243 *)p)->f18=func_02027F60(1,11,a,b,((struct Obj00243 *)p)->f0);
    func_021BA290(p);
    func_021B9D48(p);
    func_021BA328(p);
    func_021BA61C(p);
    func_0207D63C((u32 *)0x04001050,4,8,6,10);
    ((struct Obj00243 *)p)->f23C=func_02005624((u32)func_021BA238,(u32)p,0);
    func_0203D34C(1,((struct Obj00243 *)p)->f0);
    return p;
}




void func_021B9F98(u8 *p, int mode)
{
    switch (mode) {
    case 0: {
        int idx = *(int *)(p + 0x30);
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0x83 - idx;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = tbl_021BAC80[idx];
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 1;
        break;
    }
    case 1:
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = 0;
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 0;
        break;
    }
}




int func_021B9FD4(void) { return 1; }




int func_021B9FD8(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct Obj02931 *)p)->f32C=0;
    if(func_020362DC()&0x200)active=1;
    else if(func_020362DC()&0x100)active=1;
    if(active) ((struct Obj02931 *)p)->f32C=1;
    if((u32)func_021B7AB0(((struct Obj02931 *)p)->f2C)<4){
        selected=func_021B93A4(*(char * *)&((struct Obj02931 *)p)->f2C);
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            ((struct Obj02931 *)p)->f30=selected;
            func_021B9280(((struct Obj02931 *)p)->f2C,(unsigned short)func_021B93B0(*(char * *)&((struct Obj02931 *)p)->f2C),3);
            func_020061E4(1356);
            func_021B61F8(task,**(unsigned char * *)&((struct Obj02931 *)p)->f20==131-selected ? 2 : 1);
            return 1;
        }
    }
    func_021B9890(((struct Obj02931 *)p)->f8);
    switch(func_021B6448(*(unsigned char * *)&((struct Obj02931 *)p)->f8)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        func_021B9F98((u8 *)p,1);
        func_021B61F8(task,65534);
        return 1;
    }
    return 0;
}




int func_021BA0AC(void) { return 1; }




u32 func_021BA0B0(u8 *a, u8 *b)
{
    switch (func_021B61FC(a)) {
    case 0:
        func_021B9924();
    tail:
        func_021B6200(a);
        break;
    case 1:
        if (func_0204E804() == 1) break;
        if (func_02024004(1) == 0) break;
        func_0201F048((struct WordSet *)(*(u32 *)(*(u8 **)(b + 0x28) + 0x14)), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78((char *)(*(u8 **)(b + 0x28)), 0xEA);
        goto tail;
    case 2:
        if (func_021B9C00((char *)(*(u8 **)(b + 0x28))) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = (u32)func_021B9898((void *)(*(u32 *)(b + 0x18)), (struct MsgBank *)func_021B9C88((char *)(*(u8 **)(b + 0x28))), *(u16 *)b);
        return 1;
    }
    return 0;
}




int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (func_020279E8(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (func_02027A04(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((u8 *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}




int func_021BA1A0(void){if(func_0204E804()==1 || func_02024004(1)==0)return 0;return 1;}




int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (func_021B61FC(task)) {
    case 0:
        func_021B9924();
advance:
        func_021B6200(task);
        break;
    case 1:
        if (func_0204E804() == 1)
            break;
        if (func_02024004(1) == 0)
            break;
        func_021B9B78(((struct Obj26046 *)ctx)->f28, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}





int func_021BA208(void *unused, char *p)
{
    return func_021B9C00((char *)(((struct Obj26047 *)p)->f28)) != 0;
}




int func_021BA21C(unsigned char *task, char *ctx)
{
    func_021B9944();
    func_021B9C74(((struct Obj26048 *)ctx)->f28);
    func_021B61F8(task, 0);
    return 1;
}




void func_021BA238(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}




void func_021BA290(char *ctx)
{
    unsigned short heap = ((struct Obj00243 *)ctx)->f0;
    void *archive;
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = -1;
    archive = func_020490F4(193, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = func_0204A6C8((void *)((unsigned)archive), 10, 0, 2, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = func_0204ABF0((void *)archive, 11, 2, 96, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = func_0204AF28((void *)((unsigned)archive), 9, 8, heap);
    func_02049238(archive);
}




void func_021BA2EC(char *p){if(((struct Obj01983 *)p)->f2D0!=-1)func_0204A8D4(((struct Obj01983 *)p)->f2D0);if(((struct Obj01983 *)p)->f2D4!=-1)func_0204ADA4(((struct Obj01983 *)p)->f2D4);if(((struct Obj01983 *)p)->f2D8!=-1)func_0204AFD8(((struct Obj01983 *)p)->f2D8);}




void func_021BA328(char *p)
{
    Config a,b,c,d,e;
    void *manager,*item;
    int i,j;
    manager=(void *)func_021BA960(((struct Obj00243 *)p)->f4);
    for(j=0;j<36;j++)*(u32 *)(p+0x240+j*4)=0;
    a=d_021BABC8;
    a.c=((struct Obj00243 *)p)->f2D0;a.d=((struct Obj00243 *)p)->f2D4;a.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f240=func_021BA4D4((u32)manager,(char *)(&a));
    b=d_021BAB68;
    b.c=((struct Obj00243 *)p)->f2D0;b.d=((struct Obj00243 *)p)->f2D4;b.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<20;i++)*(void **)(p+0x244+i*4)=func_021BA4D4((u32)manager,(char *)(&b));
    c=d_021BAB98;
    c.c=((struct Obj00243 *)p)->f2D0;c.d=((struct Obj00243 *)p)->f2D4;c.e=((struct Obj00243 *)p)->f2D8;
    for(j=0;j<7;j++) {
        item=func_021BA4D4((u32)manager,(char *)(&c));
        func_0204B3DC(item,0);
        *(void **)(p+0x294+j*4)=item;
    }
    d=d_021BABB0;
    d.c=((struct Obj00243 *)p)->f2D0;d.d=((struct Obj00243 *)p)->f2D4;d.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<7;i++) {
        item=func_021BA4D4((u32)manager,(char *)(&d));
        func_0204B688(item,1);
        func_0204B3DC(item,0);
        *(void **)(p+0x2b0+i*4)=item;
    }
    e=d_021BAB80;
    e.c=((struct Obj00243 *)p)->f2D0;e.d=((struct Obj00243 *)p)->f2D4;e.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f2CC=func_021BA4D4((u32)manager,(char *)(&e));
}





void func_021BA4B4(char *p)
{
    int i;
    for (i = 0; i < 0x24; i++)
    {
        void *q = *(void **)(p + 0x240 + i * 4);
        if (q != 0)
        {
            func_0204B3B4(q);
        }
    }
}




struct Obj *func_021BA4D4(u32 owner,char *p){struct Obj *r;r=(struct Obj *)func_0204B294(owner,((struct Obj08448 *)p)->f8,((struct Obj08448 *)p)->fC,((struct Obj08448 *)p)->f10,(u32)p,((struct Obj08448 *)p)->f16,122);func_0204B92C(r,1);return r;}




void func_021BA4FC(char *ctx)
{
    int i;
    void *item;
    if (((struct Obj14773 *)ctx)->f32C != 0) {
        ((struct Obj14773 *)ctx)->f32C = 0;
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x294 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x2b0 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
    }
}




static inline void scroll(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    void *item;
    long i;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(func_0204B3F4(item)){
            func_0204B454(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            func_0204B404(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)func_0204B3DC(item,0);
            }else{
                if(value<=-28 || value>=212)func_0204B3DC(item,0);
            }
        }
    }
}




static inline void scrollSecond(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    long i;
    void *item;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(func_0204B3F4(item)){
            func_0204B454(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            func_0204B404(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)func_0204B3DC(item,0);
            }else{
                if(value<=-28 || value>=212)func_0204B3DC(item,0);
            }
        }
    }
}




/*
 * checks: 1 actor accessor/unit bodies fix return and three-argument position calls; 2 ov218 A61C confirms Pair_021BA290 ABI, no two-loop twin; 3 long index and const p each unchanged; 4 inline short-parameter helper reproduces both raw-parameter recasts, shared Pair_021BA290 fixes frame; 5 full idiom listing and A61C/other ov218 callers reread.
 * Two manual scheduling variants used; once-only permuter 300/jobs1/types unchanged, emitted baseline agrees at DIFF 200/200 with 9 concrete bytes.
 * single-lever: separate inline helpers use item-before-index in the first loop and index-before-item in the second; shared helper order swaps one loop's r4/r5 pair (9 bytes out).
 */
void func_021BA554(const char *p,int delta)
{
    Pair_021BA290 pos;
    scroll(p,delta,0,&pos);
    scrollSecond(p,delta,1,&pos);
}



/*
 * single-lever: row base retains ctx+i*4; fields at 244/2DC reproduce rematerialized id offset instead of hoisting a second array base.
 */
void func_021BA61C(char *ctx)
{
    int i;
    void *item;
    Pair_021BA61C pos;
    Row *row;
    for (i = 0; i < 20; i++) {
        row = (Row *)(ctx + i * 4);
        item = row->item;
        if (row->id == 65535) {
            func_0204B3DC(item, 0);
        } else {
            func_0204B454(item, (struct PtS *)&pos, 65535);
            pos.y = row->id * 2 + 92;
            func_0204B404(item, (const struct PtS *)(&pos), 65535);
        }
    }
}




/*
 * extent: 2 zero alignment bytes at 021BA6BA.
 */
void func_021BA680(char *p,int v){PtS pos;s16 y;void *o;o=((struct Obj03959 *)p)->f2CC;y=(s16)v;if(y<16)y=16;else if(y>152)y=152;func_0204B454(o,&pos,0);pos.y=y;func_0204B404(o,&pos,0);}





void func_021BA6BC(char *p,int y){PtS pos;void *o=((struct Obj03959 *)p)->f240;func_0204B454(o,&pos,65535);pos.y=y;func_0204B404(o,&pos,65535);}





void func_021BA6E8(u32 p, int sel, u32 y)
{
    u32 base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = p + 0x294;
        n = 7;
    } else {
        space = 1;
        base = p + 0x2B0;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}




int func_021BA720(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(func_0204B3F4(o)==0){func_0204B3DC(o,1);r=1;func_0204B454(o,&pos,space);pos.y=y;func_0204B404(o,&pos,space);}return r;}




int func_021BA75C(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == *(int *)(p + 0x2dc + i * 4))
        {
            return 1;
        }
    }
    return 0;
}





unsigned int func_021BA780(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}




void func_021BA7A4(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        func_02046A94((unsigned char)i, &d_021BAED8[i * 4]);
    func_02046BE0(0, 0);
}

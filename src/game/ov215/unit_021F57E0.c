/*
 * file:     unit_021F57E0.c
 * unit:     yes
 * function: func_021F57E0, func_021F584C, func_021F5884, func_021F5C08, func_021F5C20, func_021F5CFC, func_021F5D4C, func_021F5DA8, func_021F5DAC, func_021F5E38, func_021F5E68, func_021F5E90, func_021F5EB8, func_021F5EC8, func_021F5ECC, func_021F5F74, func_021F5F84, func_021F5FB0, func_021F5FDC, func_021F5FEC, func_021F6000, func_021F602C
 * address:  0x021F57E0
 * region:   ov215
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
 *   func_02082BCC 0x02082BCC arm
 *   func_0204E720 0x0204E720 arm
 *   PROCSYS_Create 0x02031324 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020362DC 0x020362DC arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021F6A3C 0x021F6A3C thumb ov215
 *   func_021F6A44 0x021F6A44 thumb ov215
 *   func_020127A4 0x020127A4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   POKE_TOOL_HatchEgg 0x02017B24 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_021F6A48 0x021F6A48 thumb ov215
 *   func_021F6A84 0x021F6A84 thumb ov215
 *   func_021F6A98 0x021F6A98 thumb ov215
 *   func_021F6AA4 0x021F6AA4 thumb ov215
 *   func_021F6164 0x021F6164 thumb ov215
 *   func_021F6194 0x021F6194 thumb ov215
 *   func_021F6228 0x021F6228 thumb ov215
 *   func_021F62FC 0x021F62FC thumb ov215
 *   func_021F6324 0x021F6324 thumb ov215
 *   func_020355D8 0x020355D8 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0216C028 0x0216C028 thumb ov010
 *   PROCSYS_Push 0x02031348 arm
 *   d_021F5580 0x021F5580 data ov194 a4
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_020457B0 0x020457B0 arm
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_02017E40 0x02017E40 thumb
 *   func_02045808 0x02045808 arm
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_021F604C 0x021F604C thumb ov215
 *   func_021F6158 0x021F6158 thumb ov215
 *   func_021F62CC 0x021F62CC thumb ov215
 *   func_021F67E0 0x021F67E0 thumb ov215
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021F64D0 0x021F64D0 thumb ov215
 *   func_021F64E4 0x021F64E4 thumb ov215
 *   func_021F6A24 0x021F6A24 thumb ov215
 *   func_021F64F0 0x021F64F0 thumb ov215
 *   func_02040588 0x02040588 arm
 *   func_021F63CC 0x021F63CC thumb ov215
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6060 0x021F6060 thumb ov215
 *   func_021F6280 0x021F6280 thumb ov215
 *   func_0204047C 0x0204047C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_021F6720 0x021F6720 thumb ov215
 *   func_021F67B0 0x021F67B0 thumb ov215
 *   func_021F62C8 0x021F62C8 thumb ov215
 *   func_021F6114 0x021F6114 thumb ov215
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021F6474 0x021F6474 thumb ov215
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021F64FC 0x021F64FC thumb ov215
 *   table 0x021F7124 data ov215
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   func_0204B98C 0x0204B98C arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   func_02005F38  0x02005F38  thumb
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   abs_id_C2 0xC2 data
 */
#include "../../matched/include/Obj03371.h"
#include "../../matched/include/Obj14704.h"
#include "../../matched/include/Obj00186.h"
#include "../../matched/include/Obj14705.h"
#include "../../matched/include/Obj03372.h"
#include "../../matched/include/Obj25737.h"
#include "../../matched/include/Obj05549.h"
#include "../../matched/include/Obj08424.h"
#include "../../matched/include/Obj10938.h"
#include "../../matched/include/Obj25739.h"
#include "../../matched/include/Obj04634.h"
#include "../../matched/include/Obj25740.h"
#include "../../matched/include/Obj25741.h"
#include "../../matched/include/Obj25742.h"
#include "../../matched/include/Obj14707.h"
#include "../../matched/include/Obj25743.h"
#include "../../matched/include/Obj14708.h"
#include "../../matched/include/Obj25744.h"
#include "../../matched/include/Obj25745.h"
#include "../../matched/include/Obj25746.h"

struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct S021F5E68;
struct SaveBlock;
struct Rec44;
struct Blk37;
struct Big;
struct U16Vec;
struct Sub02008C20Obj;
struct PrintSys;
struct Context;
struct GfFont;
struct Node;
struct Obj;
struct Actor;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Context {
    unsigned short heap;
    unsigned short pad2;
    unsigned int owner;
    char pad8[36];
    unsigned int resource1, resource2, resource3;
    unsigned int objects[6];
    char tail[60];
};

struct S021F5E68
{
    char pad[0x38];
    void *slots[6];
};

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void func_0204E720(u32,int,int,int);
extern void *PROCSYS_Create(int a0);
extern void func_0203D34C(u32,u32);
extern void func_0203133C(struct S020314B8 *),func_020315D4(struct S020315D4 *),func_020306F0(u32);
extern u32 func_020362DC(void),PROCSYS_Main(void *);
extern int func_0204E804(void);
extern void func_021F6A3C(char *);
extern int func_021F6A44(char *);
extern void *func_020127A4(struct SaveBlock *);
extern u8 *func_02012944(void *);
extern u16 func_02012AC8(const struct Rec44 *);
extern u32 func_02013E4C(u32);
extern void POKE_TOOL_HatchEgg(void *,u32,u32,u32);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *,void *),func_0200CDE0(struct Blk37 *,void *);
extern void func_021F6A48(char *p, int a);
extern int func_021F6A84(char *),func_021F6AA4(char *);
extern void func_021F6194(char *,char *,u32);
extern int func_021F6228(void *,char *),func_021F601C(void *,char *),func_021F62FC(int,char *),func_021F6324(int,char *);
extern void func_021F602C(void *,char *),func_020355D8(u8);
extern void *func_02012EBC(struct Big *),*func_0200C0F0(void *);
extern int *func_0216C028(u16,int,int,int,int);
extern void PROCSYS_Push(void *,u32,u32,u32);
extern int func_0216C0E4(int *);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0216C0D4(int *,int),func_02017E40(void *,u32,u32),func_02045808(struct U16Vec *);
extern void *func_02012F2C(int *);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern int func_0216C0C0(int a0);
extern void func_021F604C(u32 *,u32 *),func_021F5ECC(u8 *,u8 *),func_021F6158(void *,char *),func_021F62CC(void *,char *);
extern void func_021F67E0(char *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_021F64D0(char *),func_021F64E4(char *),func_021F6A24(char *),func_021F64F0(char *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern char *func_021F63CC(u32,u16);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern void *func_020056A0(u32,u32,u32);
extern void func_021F6060(int,char *);
extern void func_021F6280(int,u8 *);
extern void func_0204047C(int,u16);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern void func_02040EBC(u32,u32);
extern char *func_021F6720(u32,void *);
extern void func_021F67B0(char *p);
extern void func_021F62C8(int a0, char *a1);
extern void func_021F6114(void *unused, char *p);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021F6474(char *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049658(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_020498F4(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049238(void *);
extern void func_020409B4(u32 index);
extern int func_0204AC18(void *, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short, unsigned short);
extern int func_0204A6C8(void *, unsigned int, unsigned int, unsigned int, unsigned short);
extern int func_0204AF28(void *, unsigned int, unsigned int, unsigned int);
extern int func_021F64FC(char *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern u32 func_0204B98C(struct Actor *a);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int  GFL_USE_IsBgmFading(void);
extern int GFL_USE_PushBgm(void);
extern int  func_02005F38(void);
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned, unsigned);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
int func_021F57E0(void *a,int unused,u32 c);
int func_021F584C(struct S020315D4 *task,int unused,u32 a,char *p);
int func_021F5884(u32 unused0,u32 unused1,u32 *a,u32 *p);
void func_021F5C08(void *unused, char *p);
void func_021F5C20(int a,char *p);
void func_021F5CFC(u32 a,char *p);
void func_021F5D4C(int unused, char *p);
void func_021F5DA8(int a0, char *a1);
void func_021F5DAC(int unused, struct Context *p);
void func_021F5E38(void *unused, char *p);
void func_021F5E68(int unused, struct S021F5E68 *p);
int func_021F5E90(int unused, struct S021F5E68 *p);
int func_021F5EB8(int a, char *b);
void func_021F5EC8(u32 a, char *p);
void func_021F5ECC(u8 *p, u8 *q);
int func_021F5F74(void *unused,char *p);
void func_021F5F84(void *unused, char *p);
int func_021F5FA0(void *unused, char *p);
void func_021F5FB0(void *unused, char *p);
int func_021F5FCC(void *unused, char *p);
void func_021F5FDC(void *a0, void *a1);
void func_021F5FEC(void *a0, void *a1);
void func_021F6000(void *unused, char *p);
int func_021F601C(void *unused, char *p);
void func_021F602C(void *unused, char *p);
int func_021F603C(void *unused, char *p);
extern char d_021F5580,abs_id_C2;
extern const unsigned int table[][2];


/*
 * Legacy void allocator/31324 returns consumed; preserve visible heap input.
 */
int func_021F57E0(void *a,int unused,u32 c)
{
    char *p;
    func_0203064C(1,143,5<<16);
    p=func_0203159C(a,140,143);
    func_02082BCC(p,0,140);
    ((struct Obj03371 *)p)->f0=143;
    ((struct Obj03371 *)p)->f10=0;
    p[20]=5;
    ((struct Obj03371 *)p)->f18=0;
    ((struct Obj03371 *)p)->f1C=0;
    ((struct Obj03371 *)p)->f20=0;
    func_021F5C20(c,p);
    func_021F5EB8(c,p);
    func_0204E720(3,16,16,0);
    ((struct Obj03371 *)p)->f88=(unsigned int)PROCSYS_Create(((struct Obj03371 *)p)->f0);
    func_0203D34C(0,((struct Obj03371 *)p)->f0);
    return 1;
}


int func_021F584C(struct S020315D4 *task,int unused,u32 a,char *p) { func_0203133C(*(struct S020314B8 * *)&((struct Obj14704 *)p)->f88);func_021F5EC8(a,p);if(((struct Obj14704 *)p)->f10!=17)func_021F5CFC(a,p);func_020315D4(task);func_020306F0(143);return 1; }


/*
 * prototypes: owning ARM9 units and ov215 sources; live r3 from C028 is
 * forwarded by 31348 into the four-argument 314F4 body.
 * lever: pooled overlay ID abs_id_C2 and branch-local else return preserve
 * case15 tail layout; direct 194 and early return produced DIFF97/896.
 * data: overlay ID 194 supplied to 31348 identifies ov194's process table
 * at 021F5580; own ov194 listing has three callback words there.
 */
int func_021F5884(u32 unused0,u32 unused1,u32 *a,u32 *p)
{
    u32 active;
    struct Rec44 *save;
    u8 *trainer;
    struct Blk37 *dex;
    void *block;
    int *child;
    struct U16Vec *vec;
    func_020362DC();
    active=PROCSYS_Main((void *)p[34]);
    if(active==1)return 0;
    switch(p[4]) {
    case 0:
        if(((struct Obj00186 *)p)->f14==0){p[4]=1;func_0204E720(3,16,0,-16);}
        else (((struct Obj00186 *)p)->f14)--;
        break;
    case 1:if(!func_0204E804()){p[4]=2;func_021F5E68((int)a,(struct S021F5E68 *)p);}break;
    case 2:if(!func_021F5F74(a,(char *)p)&&func_021F5E90((int)a,(struct S021F5E68 *)p)){p[4]=3;func_021F5F84(a,(char *)p);}break;
    case 3:if(!func_021F5FA0(a,(char *)p)){p[4]=4;func_021F5FB0(a,(char *)p);}break;
    case 4:if(func_021F5FCC(a,(char *)p)){p[4]=5;func_021F6A3C((char *)p[32]);}break;
    case 5:if(func_021F6A44((char *)p[32])){p[4]=6;func_021F5FDC(a,p);}break;
    case 6:
        p[4]=7;
        save=func_020127A4((struct SaveBlock *)a[0]);trainer=func_02012944((void *)a[0]);
        POKE_TOOL_HatchEgg((void *)a[1],(u32)trainer,func_02013E4C(func_02012AC8(save)),((struct Obj00186 *)p)->f0);
        dex=func_0200CA1C((void *)a[0]);func_0200CFA0(dex,(void *)a[1]);func_0200CDE0(dex,(void *)a[1]);
        func_021F6A48((char *)p[32],(int)((void *)a[1]));break;
    case 7:if(func_021F6A84((char *)p[32])){p[4]=8;func_021F6A98((char *)p[32]);}break;
    case 8:if(func_021F6AA4((char *)p[32])){p[4]=9;func_021F6164(a,(char *)p);func_021F6000(a,(char *)p);}break;
    case 9:p[27]=1;p[4]=10;break;
    case 10:func_021F6194((char *)a,(char *)p,1);p[4]=11;break;
    case 11:if(func_021F6228(a,(char *)p)&&!func_021F601C(a,(char *)p)){p[4]=12;func_021F6194((char *)a,(char *)p,2);}break;
    case 12:if(func_021F6228(a,(char *)p)){p[4]=13;func_021F62FC((int)a,(char *)p);}break;
    case 13:
        active=func_021F6324((int)a,(char *)p);
        if(active==0){p[4]=18;func_0204E720(3,0,16,2);func_021F602C(a,(char *)p);func_020355D8(0);}
        else if(active==1){p[4]=14;func_0204E720(3,0,16,0);func_020355D8(0);}break;
    case 14:
        if(!func_0204E804()){
            block=func_0200C0F0(func_02012EBC((struct Big *)a[0]));
            func_021F5CFC((u32)a,(char *)p);p[4]=15;
            child=func_0216C028(((struct Obj00186 *)p)->f0,(int)a[1],10,0,(int)block);p[33]=(u32)child;
            PROCSYS_Push((void *)p[34],(u32)&abs_id_C2,(u32)&d_021F5580,(u32)child);
        }break;
    case 15:
        if(active!=1){
        if(!func_0216C0E4((int *)p[33])){
            vec=func_020457B0(32,((struct Obj00186 *)p)->f0);func_0216C0D4((int *)p[33],(int)vec);
            func_02017E40((void *)a[1],115,(u32)vec);func_02045808(vec);
            func_02008DF0(func_02012F2C((int *)a[0]),30);
        }
        func_0216C0C0((int)((int *)p[33]));p[4]=16;func_021F602C(a,(char *)p);
        }else{return 0;}break;
    case 16:if(!func_021F603C(a,(char *)p)){p[4]=17;func_021F604C(a,p);return 1;}break;
    case 17:break;
    case 18:if(!func_021F603C(a,(char *)p)){p[4]=19;func_021F604C(a,p);}break;
    case 19:if(!func_0204E804()){p[4]=20;return 1;}break;
    }
    func_021F5ECC((u8 *)a,(u8 *)p);
    if(p[4]!=15&&p[4]!=16&&p[4]!=17&&p[4]!=20){
        func_021F6158(a,(char *)p);func_021F62CC(a,(char *)p);func_021F67E0((char *)p[32]);
        func_0201C4E4((struct PrintSys *)p[3]);func_021F64D0((char *)p[1]);func_021F64E4((char *)p[1]);
        func_021F6A24((char *)p[32]);func_021F64F0((char *)p[1]);
    }
    return 0;
}


void func_021F5C08(void *unused, char *p)
{
    if (((struct Obj14705 *)p)->f6C) {
        func_02040588(1, 1);
        ((struct Obj14705 *)p)->f6C = 0;
    }
}


void func_021F5C20(int a,char *p)
{
    u8 i;
    for (i=0;i<=7;i++) func_02040588(i,0);
    ((struct Obj03372 *)p)->f4=func_021F63CC(1,((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->f8=func_0201D7EC(23,0,0,0,((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->fC=func_0201C440((void *)(u32)((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->f28=func_020056A0((u32)func_021F5C08,(u32)p,1);
    func_021F5D4C(a,p);
    func_021F5DAC(a,(struct Context *)p);
    func_021F6060(a,p);
    func_021F6280(a,(u8 *)p);
    func_0204047C(0,2);
    func_0204047C(2,1);
    func_0204047C(1,0);
    func_0204047C(4,0);
    func_02040588(0,1);
    func_02040588(2,1);
    func_02040588(4,1);
    func_0207D63C((u32 *)0x04000050,1,47,0,0);
    func_02040EBC(0,0x4210);
    func_02040EBC(4,0);
    *(char * *)&((struct Obj03372 *)p)->f80=func_021F6720(((struct Obj03372 *)p)->f0,((struct Obj25737 *)((u32)a))->f4);
}


void func_021F5CFC(u32 a,char *p)
{
    func_021F67B0((char *)(((struct Obj05549 *)p)->f80));
    func_021F62C8(a,p);
    func_021F6114((void *)a,p);
    func_021F5E38((void *)a,p);
    func_021F5DA8(a,p);
    func_02030EAC((struct Node *)(((struct Obj05549 *)p)->f28));
    func_0201C6EC((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    func_0201C4C0((struct PrintSys *)(((struct Obj05549 *)p)->fC));
    func_0201D83C((void *)(((struct Obj05549 *)p)->f8));
    func_021F6474((char *)(((struct Obj05549 *)p)->f4));
}



void func_021F5D4C(int unused, char *p)
{
    void *h = func_020490F4(189, ((struct Obj08424 *)p)->f0);
    func_02049B68(h, 3, 0, 0, 32, ((struct Obj08424 *)p)->f0);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct Obj08424 *)p)->f0);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct Obj08424 *)p)->f0);
    func_02049238(h);
    func_020409B4(2);
}


void func_021F5DA8(int a0, char *a1)
{

}


/*
 * lever: first types search split the full-word per-element pointer assignment and named the table address and resource result; declarations ported to block tops with initializer timing preserved.
 * checks: 1 own callee bodies prove 2/7/5/4/1/1/7/2 arities and visible full-word B294 return; 2 no ov214/215/216 constructor twin, own request builder read; 3 carried const/struct compiles remain exhausted2/2; 4 enum-zero, hoisted-zero, per-element pointer and byte-colour idioms read, manual order2/2 unchanged; 5 fresh full idiom inventory and own neighbours read. First types search stopped at200 with MATCH140; clean independent one EXACT140, all9 sites resolved. No manual scheduling variant added.
 * Return ABI: B294 original0204B314 calls CFDC then0204B318/31C returns without overwriting r0; CFDC0204D040 restores full object pointer. Caller021F5E20 stores this r0 and forwards it to B92C. Own B294 void declaration is superseded here by consumed return evidence.
 * Forwarding: 64FC adds4 to r0 and tails through6504 to662C;662C is ldr r0,[r0]; bx lr. All one full-word input/output.
 */
void func_021F5DAC(int unused, struct Context *p)
{
    unsigned char i;
    void *h = func_020490F4(189, p->heap);
    char *tmp1;
    unsigned int tmp2;
    int tmp;
    p->resource2 = func_0204AC18(h, 3, 0, 0, 0, 1, p->heap);
    tmp = func_0204A6C8(h, 2, 0, 0, p->heap);
    if (unused) {
    }
    p->resource1 = tmp;
    p->resource3 = func_0204AF28(h, 1, 0, p->heap);
    func_02049238(h);
    for (i = 0; i < 6; i++) {
        struct Context *out;
        unsigned int o;
        tmp1 = (char *)p;
        tmp1 = tmp1 + (i * 4);
        out = (struct Context *)tmp1;
        tmp2 = (unsigned int)table[i];
        o = (unsigned int)func_0204B294((void *)func_021F64FC((char *)p->owner), p->resource1, p->resource2, p->resource3, (const void *)tmp2, 0, p->heap);
        out->objects[0] = o;
        func_0204B92C((struct Obj *)o, 0);
    }
}


void func_021F5E38(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 6; i++) func_0204B3B4(*(void **)(p + i * 4 + 0x38));
    func_0204AFD8(((struct Obj10938 *)p)->f34);
    func_0204A8D4(((struct Obj10938 *)p)->f2C);
    func_0204ADA4(((struct Obj10938 *)p)->f30);
}



void func_021F5E68(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        CLACT_SetActorAnimIndex((int)p->slots[i], 0);
        func_0204B92C(p->slots[i], 1);
    }
}



int func_021F5E90(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    int r = 1;
    for (i = 0; i < 6; i++)
    {
        if (func_0204B98C(p->slots[i]) != 0)
        {
            r = 0;
            break;
        }
    }
    return r;
}



int func_021F5EB8(int a, char *b)
{
    GFL_USE_FadeOutBgm(0x1e);
    ((struct Obj25739 *)b)->f18 = 1;
    return 1;
}


void func_021F5EC8(u32 a, char *p)
{

}



void func_021F5ECC(u8 *p, u8 *q)
{
    switch (((struct Obj04634 *)q)->f18) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            ((struct Obj04634 *)q)->f18 = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3F3, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 4;
        break;
    case 4:
        break;
    case 5:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(q + 0x24), 0) != 0)
            ((struct Obj04634 *)q)->f18 = 6;
        break;
    case 6:
        if (func_02005F38() == 0) {
            func_021F5FEC(p, q);
            ((struct Obj04634 *)q)->f18 = 4;
        }
        break;
    case 7:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Obj04634 *)q)->f18 = 0;
        }
        break;
    }
}


/*
 * leaf: sole blocker set of concrete MATCH900 ov215021F5884; parent claim.
 * extent: 14-byte predicate then two zero alignment bytes at 021F5F82.
 */
int func_021F5F74(void *unused,char *p)
{
    if(((struct Obj25740 *)p)->f18==1)return 1;
    return 0;
}


void func_021F5F84(void *unused, char *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
    ((struct Obj25741 *)p)->f18 = 2;
}



int func_021F5FA0(void *unused, char *p)
{
    if (((struct Obj25742 *)p)->f18 == 2) return 1;
    return 0;
}


void func_021F5FB0(void *unused, char *p)
{
    ((struct Obj14707 *)p)->f24 = 0;
    GFL_USE_StepBgmLoad((u8 *)0x3f3, (u32 *)(p + 0x24), 1);
    ((struct Obj14707 *)p)->f18 = 3;
}



int func_021F5FCC(void *unused, char *p)
{
    if (((struct Obj25743 *)p)->f18 == 4) return 1;
    return 0;
}



void func_021F5FDC(void *a0, void *a1)
{
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
}



void func_021F5FEC(void *a0, void *a1)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(6);
}


void func_021F6000(void *unused, char *p)
{
    ((struct Obj14708 *)p)->f24 = 0;
    GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(p + 0x24), 1);
    ((struct Obj14708 *)p)->f18 = 5;
}



int func_021F601C(void *unused, char *p)
{
    int state = ((struct Obj25744 *)p)->f18;
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}


void func_021F602C(void *unused, char *p)
{
    GFL_USE_FadeOutBgm(0x3c);
    ((struct Obj25745 *)p)->f18 = 7;
}



int func_021F603C(void *unused, char *p)
{
    if (((struct Obj25746 *)p)->f18 == 7) return 1;
    return 0;
}

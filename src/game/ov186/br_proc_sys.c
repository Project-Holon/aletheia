/*
 * file:     br_proc_sys.c
 * unit:     yes
 * function: func_021F90C0, func_021F9244, func_021F92F4, func_021F9390, func_021F93D4, func_021F94D0, func_021F94E4, func_021F961C, func_021F962C, func_021F9668, func_021F966C, func_021F96A8, func_021F96AC,func_021F9728, func_021F972C, func_021F9750, func_021F9754, func_021F9774, func_021F97A0, func_021F97EC, func_021F9810, func_021F9868, func_021F98A8, func_021F98CC, func_021F98D0, func_021F98F4, func_021F98F8, func_021F99CC, func_021F9A6C, func_021F9A80, func_021F9B98, func_021F9B9C, func_021F9BA0, func_021F9BF4, func_021F9C50, func_021F9C6C, func_021F9C84, func_021F9CA4
 * address:  0x021F90C0
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
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC3BC 0x021FC3BC thumb ov186
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C3E0 0x0200C3E0 thumb
 *   func_021FB884 0x021FB884 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FE6C0 0x021FE6C0 thumb ov186
 *   func_021FE7B4 0x021FE7B4 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_021FE7F8 0x021FE7F8 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FED50 0x021FED50 thumb ov186
 *   func_021FF408 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 *   func_021FF8D4 0x021FF8D4 thumb ov186
 *   func_021FF4E4 0x021FF4E4 thumb ov186
 *   func_02034A5C 0x02034A5C arm
 *   func_021FEDC4 0x021FEDC4 thumb ov186
 *   func_021FE734 0x021FE734 thumb ov186
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_0200C3EC 0x0200C3EC thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FB92C 0x021FB92C thumb ov186
 *   func_021FC474 0x021FC474 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021FE768 0x021FE768 thumb ov186
 *   func_021FEE00 0x021FEE00 thumb ov186
 *   func_021FC4C8 0x021FC4C8 thumb ov186
 *   func_021FF52C 0x021FF52C thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 *   func_02012EBC 0x02012EBC thumb
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   func_020071CC   0x020071CC  thumb
 *   func_0200E9F4   0x0200E9F4  thumb
 *   func_0200EA04   0x0200EA04  thumb
 *   func_02045808 0x02045808 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A630 0x0200A630 thumb
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02200D04 0x02200D04 data a1
 *   func_0203133C  0x0203133C  arm
 *   func_020307B0  0x020307B0  arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_02200D14 0x02200D14 data a1
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj00387.h"
#include "../../matched/include/Obj24764.h"
#include "../../matched/include/Obj24765.h"
#include "../../matched/include/Obj24766.h"
#include "../../matched/include/Obj24768.h"
#include "../../matched/include/Obj24769.h"
#include "../../matched/include/Obj24770.h"
#include "../../matched/include/Obj24772.h"
#include "../../matched/include/Obj24773.h"
#include "../../matched/include/Obj24774.h"
#include "../../matched/include/Obj24775.h"
#include "../../matched/include/Obj24776.h"
#include "../../matched/include/Obj24777.h"
#include "../../matched/include/Obj24779.h"
#include "../../matched/include/Obj24780.h"
#include "../../matched/include/Obj24781.h"
#include "../../matched/include/Obj24782.h"
#include "../../matched/include/Obj24783.h"
#include "../../matched/include/Obj24785.h"
#include "../../matched/include/Obj24786.h"
#include "../../matched/include/Obj24787.h"
#include "../../matched/include/Obj24788.h"
#include "../../matched/include/Obj05492.h"
#include "../../matched/include/Obj05493.h"
#include "../../matched/include/Obj05494.h"
#include "../../matched/include/Obj05495.h"
#include "../../matched/include/Obj06625.h"
#include "../../matched/include/Obj06626.h"
#include "../../matched/include/Obj24789.h"
#include "../../matched/include/Obj24790.h"
#include "../../matched/include/Obj05496.h"
#include "../../matched/include/Obj05497.h"
#include "../../matched/include/Obj24791.h"
#include "../../matched/include/Obj24792.h"
#include "../../matched/include/Obj14449.h"
#include "../../matched/include/Obj24794.h"
#include "../../matched/include/Obj24795.h"
#include "../../matched/include/Obj24796.h"
#include "../../matched/include/Obj10774.h"
#include "../../matched/include/Obj01569.h"
#include "../../matched/include/Obj24810.h"
#include "../../matched/include/Obj05498.h"
#include "../../matched/include/Obj24811.h"
#include "../../matched/include/Obj08325.h"
#include "../../matched/include/Obj24813.h"

struct Obj0203159C;
struct SoundSys;
struct BigObj;
struct Blk34;
struct S020315D4;
struct Big;
struct GdsProfile;
struct ObjC4;
struct Sub020071CCCtrl;
struct Pair;
struct PrintSys;
struct Bits;
struct RecGet;
struct U16Vec;
struct S020314B8;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct {int x[3];} S;

typedef signed short s16;

typedef struct { struct { u16 id; u16 x; } e[6]; int n; } Stk_021F94D0;

typedef struct { u8 pad[0x24]; Stk_021F94D0 *s; } Obj_021F94D0;

typedef struct Inner {
    int f0;
    int f4;
} Inner;

typedef struct Mid {
    int pad0;
    int pad4;
    int f8;
    Inner *p0c;
} Mid;

typedef struct Top {
    int w0;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    Mid *f18;
    int w7;
    int w8;
    int w9;
    int f28;
    int f2c;
} Top;

typedef struct { int w0, w4, w8, wc, w10, w14, w18; } A_021F98A8;

typedef struct { int w0, w4, w8, wc, w10, w14; struct { int pad[3]; struct { int pad; int v; } *q; } *w18; } B_021F98A8;

typedef struct { int w0, w4, w8, wc, w10, w14, w18; } A_021F98D0;

typedef struct { int w0, w4, w8, wc, w10, w14; struct { int pad[3]; struct { int pad; int v; } *q; } *w18; } B_021F98D0;

typedef unsigned long long u64;

typedef struct Fields {u32 words[4];void *handles[4];u32 flags[4];u64 values[4];u32 state,ready;} Fields;

typedef struct {
    unsigned object;
    void *base;
    unsigned short count, pad;
    unsigned arg;
    unsigned short heap, pad2;
    unsigned words[21];
    unsigned *list;
    unsigned loaded;
} Context;

typedef unsigned u32_021F9A80;

struct Ops {u32_021F9A80 id,size,fn;void (*init)(void *,u32_021F9A80,void *,int);void (*update)(void *,u32_021F9A80);};

struct Slot {u32_021F9A80 active;void *work;const struct Ops *ops;int arg;};

typedef unsigned int u32_021F9B9C;

typedef struct { u32_021F9B9C words[4]; } Info_021F9BA0;

typedef struct { unsigned words[4]; } Info_021F9BF4;

typedef struct {
    char  pad_00[0x4c];
    char  unk_4c[0x18];
    int   unk_64;
    void *unk_68;
} S_021F9A80;

typedef struct {
    char pad_00[0x64];
    int  unk_64;
} S_021F9C6C;

extern void func_0203064C(u32,u32,u32),func_02082BCC(void *,int,unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_021FC3BC(unsigned mode, int setting, unsigned heap);
extern void *func_02012F08(int *);
extern void *func_021FB884(unsigned,unsigned,unsigned);
extern u8 func_0200C3E0(struct Blk34 *p);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern int *func_021FE6C0(unsigned);
extern void func_021FE7B4(char *),func_021FE7F4(int *,int),func_021FE7F8(char *,int);
extern int func_021FC224(char *);
extern u32 func_021FC4DC(u8 *p);
extern char *func_021FED50(int,int,char *,unsigned);
extern char *func_021FF408(void *owner, void *arg, u32 heap);
extern int func_02034AC4(int),func_0203CD98(void);
extern void func_0203D34C(u32,u32);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern void func_021FE840(int,int,int);
extern int func_021FF8D4(char *);
extern void func_021FF4E4(char *p);
extern void func_02034A5C(int);
extern void func_021FEDC4(char *p, char *ctx);
extern void func_021FE734(char *p);
extern int func_021FC238(char *p);
extern void func_0200C3EC(struct Blk34 *p, u32 v);
extern void func_021FBDA4(int,unsigned);
extern void func_021FB92C(char *p);
extern void func_021FC474(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021FE768(S *);
extern void func_021FEE00(char *p);
extern void func_021FC4C8(char *);
extern void func_021FF52C(char *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02012EBC(struct Big *p);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);
extern void GDS_PROFILE_Init(struct GdsProfile *p, void *sys);
extern void *func_020071CC(struct Sub020071CCCtrl *, unsigned int);
extern void *func_0200E9F4(void *p);
extern int func_0200EA04(int);
extern u8 *BATTLE_REC_GetHeader(void);
extern void *func_0200A5F8(void *);
extern void func_02045808(struct U16Vec *vec);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern u32 func_0200D6EC(struct RecGet *p);
extern u32 func_0200A630(struct Bits *p);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *PROCSYS_Create(int a0);
extern void func_0203133C(struct S020314B8 *);
extern u32 func_020307B0(void *p);
extern void PROCSYS_Push(u32_021F9A80,u32_021F9A80,u32_021F9A80,void *);
extern u32_021F9A80 PROCSYS_Main(void *);
extern void func_02082D44(void *, void *, int);
int func_021F90C0(void *obj,int unused,char *q);
int func_021F9244(int sys,int unused,int unused2,int *p);
int func_021F92F4(int sys,int *state,int unused,int *p);
void func_021F9390(int *out,int *source,int unused,int type);
void func_021F93D0(void);
void func_021F93D4(int *out,int *source,int *ctx,int type);
void func_021F94D0(Obj_021F94D0 *o);
void func_021F94E4(int *out,int *source,const char *ctx,int type);
void func_021F961C(u32 *a, u32 *b);
void func_021F962C(char *r5, int *r4);
void func_021F9668(void);
void func_021F966C(char *r5, int *r4);
void func_021F96A8(void);
void func_021F96AC(int *out, int *source, const int *ctx, int type);
void func_021F9728(void);
void func_021F972C(char *p,char *q);
void func_021F9750(void);
void func_021F9754(int *out,int *source);
void func_021F9770(void);
void func_021F9774(char *p,char *q);
void func_021F979C(void);
void func_021F97A0(int *out,int *source,int *ctx,int type);
void func_021F97EC(char *p,char *q);
void func_021F9810(int *out,int *source,const char *ctx,int type);
void func_021F9868(Top *p, Top *q);
void func_021F98A8(A_021F98A8 *a, B_021F98A8 *b);
void func_021F98CC(void);
void func_021F98D0(A_021F98D0 *a, B_021F98D0 *b);
void func_021F98F4(void);
void func_021F98F8(char *p, int skip, void *sys, int heap);
Context *func_021F99CC(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap);
void func_021F9A6C(int *p);
void func_021F9A80(char *p);
int func_021F9B98(int *p);
unsigned func_021F9B9C(struct Obj24810 *p);
void func_021F9BA0(unsigned *ctx);
void func_021F9BF4(unsigned *ctx, unsigned index);
void func_021F9C50(S_021F9A80 *p);
void func_021F9C6C(S_021F9C6C *p);
void func_021F9C84(char *p,int a,int b);
void func_021F9CA4(void *p);
extern char ov125_id[];
extern const char d_02200254[];
extern const char d_02200D00[];
extern const char d_02200D04[];
extern const char d_02200D04[],d_02200D14[];








/*
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 */
int func_021F90C0(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    func_0203064C(1,0x5a,0x90000);
    p=func_0203159C(obj,0x1c,0x5a);
    zero=0;
    func_02082BCC(p,0,0x1c);
    *(char * *)&((struct Obj00387 *)p)->f18=q;
    ((struct Obj24765 *)(*(char * *)&((struct Obj24764 *)q)->fC))->fC=zero;
    if(**(int * *)&((struct Obj24766 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC!=2) flag=zero;
    enabled=1;
    ((struct Obj00387 *)p)->f0=func_021FC3BC(flag,1,0x5a);
    mode=func_0200C3E0(func_02012F08(*(int * *)&((struct Obj24769 *)(*(char * *)&((struct Obj24768 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4));
    if(**(int * *)&((struct Obj24770 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) enabled=0;
    ((struct Obj00387 *)p)->f4=func_021FB884(mode,enabled,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),0,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),1,0x5a);
    ((struct Obj00387 *)p)->f8=func_021F99CC(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(((struct Obj24772 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1728),0x5a);
    *(int * *)&((struct Obj00387 *)p)->fC=func_021FE6C0(0x5a);
    func_021FE7B4(*(char * *)&((struct Obj00387 *)p)->fC);
    func_021FE7F4(*(int * *)&((struct Obj00387 *)p)->fC,func_021FC224(*(char * *)&((struct Obj00387 *)p)->f4));
    if(!((struct Obj24773 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4) func_021FE7F8(*(char * *)&((struct Obj00387 *)p)->fC,3);
    *(char * *)&((struct Obj00387 *)p)->f10=func_021FED50(func_021FC4DC((u8 *)(*(int *)&((struct Obj00387 *)p)->f0)),*(int *)&((struct Obj00387 *)p)->fC,*(char * *)&((struct Obj00387 *)p)->f4,0x5a);
    func_021F98F8((char *)(((struct Obj24774 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1748),1,(void *)(((struct Obj24776 *)(*(char * *)&((struct Obj24775 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x5a);
    if(**(int * *)&((struct Obj24777 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        ((struct Obj00387 *)p)->f14=func_021FF408(((struct Obj24780 *)(*(char * *)&((struct Obj24779 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4,(void *)(((struct Obj24782 *)(*(char * *)&((struct Obj24781 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f8),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(func_0203CD98()) func_0203D34C(0,0x5a);
    if(!**(int * *)&((struct Obj24783 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        if(((struct Obj24785 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4!=1) func_02028A58((void *)func_02012A30(((struct Obj24787 *)(*(char * *)&((struct Obj24786 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x40,0);
    } else GFL_USE_CancelChangeAndPlayBgm(0x484,0xffff);
    if(((struct Obj24788 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4==1) {
        func_021FEE9C((char *)(*(int *)&((struct Obj00387 *)p)->f10));func_021FEE4C((char *)(*(int *)&((struct Obj00387 *)p)->f10));
        func_021FE840(*(int *)&((struct Obj00387 *)p)->fC,3,0);
    }
    return 1;
}








int func_021F9244(int sys,int unused,int unused2,int *p)
{
    int *nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) func_02028A58((struct SoundSys *)func_02012A30((const struct BigObj *)nested[1]),0x7f,0);
    if(p[5]) {
        if(func_021FF8D4((char *)p[5])) ((int *)((int *)p[6])[3])[3]=2;
        func_021FF4E4((char *)p[5]); p[5]=0;
    } else func_02034A5C((int)ov125_id);
    func_021FEDC4((char *)p[4],(char *)p[1]);
    func_021FE734((char *)p[3]);
    func_021F9A6C((int *)p[2]);
    nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) {
        int a=(int)func_02012F08((int *)nested[1]);
        int b=func_021FC238((char *)p[1]);
        func_0200C3EC((struct Blk34 *)a,(unsigned char)b);
    }
    func_021FBDA4(p[1],0);
    func_021FBDA4(p[1],1);
    func_021FB92C((char *)p[1]);
    func_021FC474((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    func_020306F0(0x5a);
    return 1;
}








int func_021F92F4(int sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1: func_0204E720(3,16,0,0); *state=2; break;
    case 2: if(!func_0204E804()) *state=3; break;
    case 3:
        func_021FE768((S *)p[3]);
        func_021FEE00((char *)p[4]);
        func_021F9A80((char *)p[2]);
        func_021FC4C8((char *)p[0]);
        if(p[5]) func_021FF52C((char *)p[5]);
        if(func_021F9B98((int *)p[2])) *state=4;
        break;
    case 4: func_0204E720(3,0,16,0); *state=5; break;
    case 5: if(!func_0204E804()) *state=6; break;
    case 6: return 1;
    }
    return 0;
}








/*
 * Extent includes empty follower021F93D0; zeros021F93CE and021F93D2 are alignment.
 */
void func_021F9390(int *out,int *source,int unused,int type)
{
    out[3]=source[1];
    out[2]=source[3];
    out[4]=source[2];
    out[1]=func_021FC4DC((u8 *)source[0]);
    out[5]=source[4];
    if(type==1) out[0]=1;
    else if(((int *)source[6])[1]==0) out[0]=0;
    else out[0]=2;
}








void func_021F93D0(void)
{
}








/*
 * note: 2026-10-05 wave P15 D3. Real extent 252 bytes (pool ends 0x021F94CC); the unlabelled
 *   follower at 0x021F94D0 is a separate function. Written from the listing, EXACT* at the first compile.
 */
void func_021F93D4(int *out,int *source,int *ctx,int type)
{
    out[3]=2;
    out[10]=*(int *)((char *)source[6]+0xc)+0xc;
    out[9]=*(int *)((char *)source[6]+8)+0x17A0;
    if(*(int *)((char *)source[6]+4)==1) {
        switch(**(int **)((char *)source[6]+0xc)) {
        case 0: out[0]=1; break;
        case 1: out[0]=7; break;
        case 2: out[0]=10; break;
        }
    } else {
        switch(type) {
        case 2:
            switch(ctx[2]) {
            case 0: out[0]=1; break;
            case 1: case 2: case 3: out[0]=2; break;
            case 4: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            case 5: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            }
            break;
        case 5: out[0]=7; break;
        case 6: case 7: out[0]=6; break;
        case 12:
            if(ctx[7]==0) out[3]=4;
            out[0]=10;
            break;
        default:
            switch(**(int **)((char *)source[6]+0xc)) {
            case 0: out[0]=0; break;
            case 1: out[0]=5; break;
            case 2: out[0]=10; break;
            }
            break;
        }
    }
    out[6]=source[1];
    out[4]=source[3];
    out[7]=source[2];
    out[5]=func_021FC4DC((u8 *)source[0]);
    out[8]=*(int *)((char *)source[6]+8)+0x1748;
}






void func_021F94D0(Obj_021F94D0 *o) { Stk_021F94D0 *s = o->s; int i = s->n - 1; if (s->e[(u16)i].id == 8) s->n = i; }






/*
 * note: final push 2026-10-05 G1L5. Real extent 312 bytes (pool ends 0x021F961A); the unlabelled
 *   follower at 0x021F961C is a separate function, not filed. Case 7 reads the adjacent words ctx+0x10 and
 *   ctx+0x14 as one u64 and splits it into out[7] and out[8] (low word first); this gives the original load
 *   order (r2 from 0x10, then r3 from 0x14). Two int locals, a Pair copy, const, int *ctx and every per-function
 *   pragma left the loads reversed (2 bytes off). A u32 pair read through a pointer or a struct is 101 bytes off.
 *   The u64 read is a judgement call for the integrator: the two words are plausibly one 64-bit field.
 */
void func_021F94E4(int *out,int *source,const char *ctx,int type)
{
    u32 result;
    void *sys;
    unsigned a,b;
    out[4]=source[1];out[3]=source[3];out[5]=source[2];
    out[6]=func_021FC4DC((u8 *)source[0]);
    out[9]=source[5];
    out[10]=(*(int **)((char *)source[6]+12))[1];
    out[11]=*(int *)((char *)source[6]+8)+0x1720;
    out[13]=0;
    out[14]=*(int *)((char *)source[6]+8)+0x1748;
    out[15]=*(int *)((char *)source[6]+8)+0x17bc;
    switch(type) {
    case 0:case 2:case 3:case 4:case 6:case 8:case 9: goto done;
    default:
        if(type!=-2) return;
        break;
    case 1:
        out[2]=*(int *)(ctx+8);out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=out[2];
        sys=*(void **)(*(char **)((char *)source[6]+12)+4);
        BATTLE_REC_Load(func_02012EBC(sys),0x59,&result,out[2]);
        if(result==1) {if(!out[2]) GDS_PROFILE_Init((struct GdsProfile *)BATTLE_REC_GetWork(),sys);}
        else func_02034714(d_02200D00,0,d_02200D00);
        return;
    case 5:
        out[2]=4;out[12]=*(int *)((char *)source[6]+8);
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=4;
        return;
    case 7:
        out[2]=5;{ unsigned long long v=*(unsigned long long *)(ctx+0x10); out[7]=v; out[8]=v>>32;} out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=5;
        return;
    case 10:
        a=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
        b=*(int *)(ctx+0x20);
        out[2]=a;
        out[12]=*(int *)((char *)source[6]+8);
        a=*(int *)(ctx+0x1c);out[8]=b;out[7]=a;out[13]=1;
        return;
    }
    out[2]=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
    out[12]=*(int *)((char *)source[6]+8);out[13]=1;
done:
    return;
}








void func_021F961C(u32 *a, u32 *b) { if (*a == 1) *(u32 *)b[6] = 1; }






/*
 * Fill the output record from the source object and its nested handle.
 */
void func_021F962C(char *r5, int *r4)
{
    int x;
    x = (int)func_02012EBC((struct Big *)(*(int *)(*(int *)(((struct Obj05493 *)r4)->f18 + 0xC) + 4)));
    ((struct Obj05492 *)r5)->f8 = r4[1];
    ((struct Obj05492 *)r5)->f0 = r4[3];
    ((struct Obj05492 *)r5)->fC = r4[2];
    ((struct Obj05492 *)r5)->f4 = func_021FC4DC((u8 *)r4[0]);
    ((struct Obj05492 *)r5)->f10 = (int)func_020071CC((struct Sub020071CCCtrl *)x, 0x3a);
    ((struct Obj05492 *)r5)->f14 = *(int *)(*(int *)(((struct Obj05493 *)r4)->f18 + 0xC) + 4);
}






void func_021F9668(void) {}





/*
 *   unlabelled Thumb leaves with no branch anywhere outside this range, so
 *   the two calls stay wildcarded.
 *
 * Fill the output record from the source object and its nested handle.
 */
void func_021F966C(char *r5, int *r4)
{
    int x;
    x = (int)func_02012EBC((struct Big *)(*(int *)(*(int *)(((struct Obj05495 *)r4)->f18 + 0xC) + 4)));
    ((struct Obj05494 *)r5)->f8 = r4[1];
    ((struct Obj05494 *)r5)->f4 = r4[3];
    ((struct Obj05494 *)r5)->fC = r4[2];
    ((struct Obj05494 *)r5)->f0 = func_021FC4DC((u8 *)r4[0]);
    ((struct Obj05494 *)r5)->f10 = *(int *)(*(int *)(((struct Obj05495 *)r4)->f18 + 0xC) + 4);
    ((struct Obj05494 *)r5)->f14 = func_0200EA04((int)func_0200E9F4((void *)x));
}





void func_021F96A8(void) {}




/*
 * extent: empty-return follower 0x021F9728; zero halfwords at 0x021F9726
 *   and 0x021F972A are alignment padding.
 * lever: ctx declared `const int *` lets the type-6 arm load ctx[5]/ctx[6]
 *   ahead of the out[0] store (021F96E4..021F96EA); a plain pointer left 13
 *   bytes, block locals for the two loads 74.
 */
void func_021F96AC(int *out, int *source, const int *ctx, int type)
{
    out[7] = *(int *)(source[6] + 8);
    out[10] = *(int *)(source[6] + 8) + 0x17C0;
    if (type == 1) {
        out[0] = ctx[2];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = out[0];
        func_02082BCC((void *)out[10], 0, 4);
    } else if (type == 6) {
        out[0] = 3;
        out[8] = ctx[5];
        out[9] = ctx[6];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = 3;
        func_02082BCC((void *)out[10], 0, 4);
    } else if (type == 2) {
        out[0] = *(int *)(*(int *)(source[6] + 8) + 0x17C4);
        out[1] = 1;
    }
    out[4] = source[1];
    out[2] = source[3];
    out[5] = source[2];
    out[3] = func_021FC4DC((u8 *)source[0]);
    out[6] = source[5];
}




void func_021F9728(void)
{
}




/*
 * extent: empty-return follower 0x021F9750; trailing two-byte padding.
 */
void func_021F972C(char *p,char *q) { ((struct Obj06625 *)p)->f8=((struct Obj06626 *)q)->f4;((struct Obj06625 *)p)->f0=((struct Obj06626 *)q)->fC;((struct Obj06625 *)p)->fC=((struct Obj06626 *)q)->f8;((struct Obj06625 *)p)->f4=func_021FC4DC((u8 *)(((struct Obj06626 *)q)->f0));((struct Obj06625 *)p)->f10=((struct Obj24790 *)(*(char * *)&((struct Obj24789 *)(*(char * *)&((struct Obj06626 *)q)->f18))->fC))->f4; }




void func_021F9750(void) {}





void func_021F9754(int *out,int *source)
{
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[2];
    out[1]=func_021FC4DC((u8 *)source[0]);
}





/*
 * Extent includes empty follower func_021F9770; zeros at 021F976E and 021F9772 are alignment.
 */
void func_021F9770(void)
{
}





void func_021F9774(char *p,char *q) { ((struct Obj05496 *)p)->f8=((struct Obj05497 *)q)->f4;((struct Obj05496 *)p)->f0=((struct Obj05497 *)q)->fC;((struct Obj05496 *)p)->fC=((struct Obj05497 *)q)->f8;((struct Obj05496 *)p)->f4=func_021FC4DC((u8 *)(((struct Obj05497 *)q)->f0));((struct Obj05496 *)p)->f10=((struct Obj05497 *)q)->f14;((struct Obj05496 *)p)->f14=((struct Obj24792 *)(*(char * *)&((struct Obj24791 *)(*(char * *)&((struct Obj05497 *)q)->f18))->fC))->f4; }





/*
 * extent: empty-return follower 0x021F979C; trailing two-byte padding.
 */
void func_021F979C(void) {}





void func_021F97A0(int *out,int *source,int *ctx,int type)
{
    if(type==1) {
        out[0]=ctx[2];
        out[3]=source[1];
        out[1]=source[3];
        out[4]=source[2];
        out[2]=func_021FC4DC((u8 *)source[0]);
        out[5]=(*(int **)((char *)source[6]+0xc))[1];
        out[6]=*(int *)((char *)source[6]+8)+0x1748;
    } else {
        func_02034714(d_02200D00,0,d_02200D00);
    }
}





void func_021F97EC(char *p,char *q) { char *s;if(((struct Obj24794 *)p)->f1C){s=*(char * *)&((struct Obj24795 *)q)->f18;func_021F98F8((char *)(((struct Obj14449 *)s)->f8+0x1748),0,(void *)(((struct Obj24796 *)(*(char * *)&((struct Obj14449 *)s)->fC))->f4),90);} }




/*
 * Lever: compute ctx+0x20 before storing the getter result, then read ctx+0x1c.
 * Direct getter store leaves an 8-byte scheduling/register residue.
 */
void func_021F9810(int *out,int *source,const char *ctx,int type)
{
    unsigned a;
    int b,result;
    if(type!=2) func_02034714(d_02200D00,0,d_02200D00);
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[5];
    out[4]=source[2];
    result=func_021FC4DC((u8 *)source[0]);
    a=((struct Obj10774 *)ctx)->f20;
    out[1]=result;
    b=((struct Obj10774 *)ctx)->f1C;
    out[8]=a;
    out[7]=b;
    out[5]=(*(int **)((char *)source[6]+0xc))[1];
    out[6]=*(int *)((char *)source[6]+8)+0x1748;
    out[9]=((struct Obj10774 *)ctx)->f4;
}




void func_021F9868(Top *p, Top *q)
{
    int buf[1];

    if (p->f28 == 0)
        return;
    func_021F98F8((char *)q->f18->f8 + 0x1748, 0, (void *)q->f18->p0c->f4, 0x5a);
    BATTLE_REC_Load((void *)((int)func_02012EBC((struct Big *)q->f18->p0c->f4)), 0x805a, (u32 *)buf, p->f2c);
}


void func_021F98A8(A_021F98A8 *a, B_021F98A8 *b) { a->wc = b->w4; a->w0 = b->wc; a->w10 = b->w8; a->w8 = b->w0; a->w14 = b->w14; a->w4 = b->w10; a->w18 = b->w18->q->v; }




void func_021F98CC(void) {}


void func_021F98D0(A_021F98D0 *a, B_021F98D0 *b) { a->wc = b->w4; a->w0 = b->wc; a->w10 = b->w8; a->w8 = b->w0; a->w14 = b->w14; a->w4 = b->w10; a->w18 = b->w18->q->v; }




void func_021F98F4(void) {}



/*
 * note: 2026-10-05 recoup. The old draft had the save and tag spill slots swapped
 *   (4 bytes). Declaring the heap parameter of BATTLE_REC_Load as u16 and keeping the
 *   tag as a plain u32 local `(heap & 0x7fff) | 0x8000` (no u16 cast) gives EXACT in
 *   c99 and c. Other forms tried: u16 or int tag, tag inline in the call, tag set
 *   before save, declaration order of tag and save, tag in the loop body, heap
 *   reassigned, u32 heap parameter, all six per-function pragmas: all 4 bytes off.
 */
void func_021F98F8(char *p, int skip, void *sys, int heap)
{
    int enabled=1;
    int i;
    u32 result;
    u32 save;
    void *profile;
    if(skip && *(int *)(p+0x54)) enabled=0;
    if(enabled) {
        u32 tag;
        save=(u32)func_02012EBC(sys);
        if(*(int *)(p+0x54)) {
            for(i=0;i<4;i++) {
                if(((Fields *)p)->handles[i]) {
                    func_02045808(((Fields *)p)->handles[i]);
                    ((Fields *)p)->handles[i]=0;
                }
            }
        }
        func_02082BCC(p,0,0x58);
        tag=(heap&0x7fff)|0x8000;
        for(i=0;i<4;i++) {
            BATTLE_REC_Load((void *)save,tag,&result,i);
            if(result==1) {
                profile=BATTLE_REC_GetWork();
                if(i==0) GDS_PROFILE_Init(profile,sys);
                *(int *)((u32)p+(u32)i*4)=1;
                *(void **)((u32)p+(u32)i*4+0x10)=GDS_PROFILE_CreateNameStr(profile,0x59);
                *(u32 *)((u32)p+(u32)i*4+0x20)=func_0200D6EC(profile);
                *(u64 *)((u32)p+(u32)i*8+0x30)=BATTLE_REC_GetHeaderParam(BATTLE_REC_GetHeader(),4,0);
            }
        }
        *(u32 *)(p+0x50)=func_0200A630(func_0200A5F8(func_02012EBC(sys)));
        *(int *)(p+0x54)=1;
    }
}




Context *func_021F99CC(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap)
{
    Context *ctx;
    unsigned i = 0;
    ctx = func_02030734(heap, 0x70, 0, d_02200D04, 0x77);
    func_02082BCC(ctx, 0, 0x70);
    ctx->heap = heap;
    ctx->count = count;
    ctx->arg = arg;
    ctx->base = base;
    ctx->list = list;
    ctx->object = (unsigned int)PROCSYS_Create(heap);
    func_021F9CA4((char *)ctx + 0x2c);
    func_021F9CA4((char *)ctx + 0x3c);
    func_021F9CA4((char *)ctx + 0x1c);
    if (ctx->list[6]) {
        for (i = 0; i < ctx->list[6]; i++) {
            func_021F9BF4((unsigned int *)ctx, (unsigned short)ctx->list[i]);
        }
        func_02082BCC(ctx->list, 0, 0x1c);
        ctx->loaded = 1;
    } else {
        func_021F9BF4((unsigned int *)ctx, fallback);
    }
    return ctx;
}





void func_021F9A6C(int *p)
{
    func_0203133C((struct S020314B8 *)p[0]);
    func_020307B0(p);
}







/*
 * tail: existing matched accessor followers 021F9B98 and 021F9B9C; lead only.
 */
void func_021F9A80(char *p)
{
 struct Slot *current,*old,*next;
 current=(struct Slot *)(p+0x2c);
 old=(struct Slot *)(p+0x1c);
 next=(struct Slot *)(p+0x3c);
 switch(((struct Obj01569 *)p)->f18){
 case 0:*old=*current;*current=*next;((struct Obj01569 *)p)->f18=1;break;
 case 1:{
  int mode;
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(!current->ops->init)func_02034714(d_02200D14,0,d_02200D14);
  current->work=func_02030734(((struct Obj01569 *)p)->f10,current->ops->size,0,d_02200D04,0xd2);
  func_02082BCC(current->work,0,current->ops->size);
  mode=-2;if(!((struct Obj01569 *)p)->f6C)mode=old->arg;
  current->ops->init(current->work,((struct Obj01569 *)p)->fC,old->work,mode);
  ((struct Obj01569 *)p)->f6C=0;
  if(old->work)func_020307B0(old->work);
  PROCSYS_Push(*(u32_021F9A80 *)&((struct Obj01569 *)p)->f0,current->ops->fn,current->ops->id,current->work);
  ((struct Obj01569 *)p)->f18=2;break;
 }
 case 2:if(!PROCSYS_Main(((struct Obj01569 *)p)->f0))((struct Obj01569 *)p)->f18=3;break;
 case 3:
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(current->ops->update)current->ops->update(current->work,((struct Obj01569 *)p)->fC);
  if(((struct Obj01569 *)p)->f64)((struct Obj01569 *)p)->f18=0;
  else{if(current->work)func_020307B0(current->work);((struct Obj01569 *)p)->f18=4;}
  break;
 case 4:((struct Obj01569 *)p)->f14=1;break;
 }
}







/*
 * Follower021F9B9C has its existing matched source/shard; no unit.
 */
int func_021F9B98(int *p)
{
    return p[5];
}







/*
 * leaf: sole blocker of ov183 021DB2E0; parent cleared ownership.
 */
unsigned func_021F9B9C(struct Obj24810 *p)
{
    return p->f10;
}







void func_021F9BA0(unsigned *ctx)
{
    Info_021F9BA0 info;
    if (ctx[25] != 0) {
        ctx[25]--;
        if (ctx[25] != 0) {
            unsigned idx = (unsigned short)((unsigned *)((char *)ctx + 0x48))[ctx[25]];
            func_021F9C84((char *)(&info), idx, (int)((char *)ctx[1] + idx * 20));
            *(Info_021F9BA0 *)((char *)ctx + 0x3c) = info;
        } else {
            func_021F9CA4((char *)ctx + 0x3c);
        }
    } else {
        func_021F9CA4((char *)ctx + 0x3c);
    }
}







void func_021F9BF4(unsigned *ctx, unsigned index)
{
    Info_021F9BF4 info;
    char *base = (char *)ctx[1];
    char *entry = base + index * 20;
    if (index >= ((struct Obj05498 *)ctx)->f8)
        func_02034714(d_02200D14, 0, d_02200D14);
    func_021F9C84((char *)(&info), index, (int)entry);
    if (ctx[25] >= 6)
        func_02034714(d_02200D14, 0, d_02200D14);
    ((unsigned (*)[6])((char *)ctx + 0x4c))[0][ctx[25]] = index;
    ctx[25]++;
    *(Info_021F9BF4 *)((char *)ctx + 0x3c) = info;
}






void func_021F9C50(S_021F9A80 *p)
{
    func_02082D44(p->unk_4c, p->unk_68, 0x18);
    ((struct Obj24811 *)((char *)p->unk_68))->f18 = p->unk_64;
    func_021F9C6C((S_021F9C6C *)p);
}





void func_021F9C6C(S_021F9C6C *p)
{
    while (p->unk_64 != 0)
        func_021F9BA0((unsigned int *)p);
}




void func_021F9C84(char *p,int a,int b) { int zero=0;func_02082BCC(p,0,16);((struct Obj08325 *)p)->f0=1;((struct Obj08325 *)p)->f4=zero;((struct Obj08325 *)p)->fC=a;((struct Obj08325 *)p)->f8=b; }





void func_021F9CA4(void *p)
{
    func_02082BCC(p, 0, 0x10);
    ((struct Obj24813 *)p)->fC = -1;
}
